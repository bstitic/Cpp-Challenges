/*** 
This file includes my solution to the challenge on operator overloading using member methods. The challenge was to do this for a user-defined 
class named "Mystring" which has an attribute that is a pointer to a char[] that holds a c-style string.  

The following was provided by the instructor: no-args constructor, overloaded constructor, copy constructor, move constructor, destructor, 
copy assignment, move assignment, display method, getters, overloaded insertion operator (friend) and overloaded extraction operator (friend). 
This is also clearly indicated in the code of this file using comments.

Please refer to the course material of Section 14 for the reference files and reference solution. The main.cpp and Mystring.h files provided by 
the instructor are also required to run this project and can be found in the material as well. In particular:
1) main.cpp: includes some test cases to run 
2) Mystring.h: includes friends (extraction and insertion operators), private attribute (pointer), public: no-args constructor, overloaded constructor,
   copy constructor, move constructor, destructor, copy assignment, move assignment, display() const method and getters.
   
   NOTE: to the Mystring.h file, it is only required to add the following 11 member function declarations (with the public qualifier):
		Mystring operator-() const;                            
		Mystring operator+(const Mystring &rhs) const;         
		bool operator==(const Mystring &rhs) const;             
		bool operator!=(const Mystring &rhs) const;             
		bool operator<(const Mystring &rhs) const;              
		bool operator>(const Mystring &rhs) const;             
		Mystring &operator+=(const Mystring &rhs);            
		Mystring operator*(int n) const;                               
		Mystring &operator*=(int n);                                     
		Mystring &operator++();                                          
		Mystring operator++(int);                                       

As implied above, I implemented the following 11 operators for the Mystring class: 
1) Unary minus 
2) Binary == 
3) Binary != 
4) Binary > (lexical)
5) Binary < (lexical)
6) Binary concatenation + 
7) Binary concatenation +=
8) Binary * (repetition) 
9) Binary *= (repetition and assignment)
10) Unary pre-increment 
11) Unary post-increment 
***/

#include <iostream>
#include <cstring>
#include "Mystring.h"

 // Constructor (provided by instructor)
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor (provided by instructor)
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }
}

// Copy constructor (provided by instructor)
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[strlen(source.str)+ 1];
        strcpy(str, source.str);
 //       std::cout << "Copy constructor used" << std::endl;

}

// Move constructor (provided by instructor) 
Mystring::Mystring( Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
//        std::cout << "Move constructor used" << std::endl;
}

 // Destructor (provided by instructor)
Mystring::~Mystring() {
    delete [] str;
}

 // Copy assignment (provided by instructor)
Mystring &Mystring::operator=(const Mystring &rhs) {
//    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment (provided by instructor)
Mystring &Mystring::operator=( Mystring &&rhs) {
 //   std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}


// Display method (provided by instructor)
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

 // Getters (provided by instructor)
 int Mystring::get_length() const { return strlen(str); }
 const char *Mystring::get_str() const { return str; }

// Overloaded insertion operator (provided by instructor)
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// Overloaded extraction operator (provided by instructor) 
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}

// Operators (my implementations)
// 1. Unary minus, make it const for good practice
Mystring Mystring::operator-() const{
    char* buffer = new char[std::strlen(str)+1]; //allocate memory on the heap
    std::strcpy(buffer, str); //copy original characters
    
    for(size_t i {0}; i < std::strlen(buffer); i++){
        buffer[i] = std::tolower(buffer[i]);
    }
    Mystring temp {buffer};
    delete [] buffer; //deallocate memory
    return temp; 
}

// 2. Binary comparison ==
bool Mystring::operator==(const Mystring &rhs) const{
    return ( std::strcmp(str, rhs.str) == 0 );
}

// 3. Binary comparison != 
bool Mystring::operator!=(const Mystring &rhs) const{
    return (std::strcmp(str, rhs.str) != 0 );  
}

// 4. Binary comparison < (lexical)
bool Mystring::operator<(const Mystring &rhs) const{    
    return (std::strcmp(str, rhs.str) < 0 ) ; 
} 

// 5. Binary comparison > (lexical)
bool Mystring::operator>(const Mystring &rhs) const{
    return (std::strcmp(str, rhs.str) > 0 ) ; 
}  

// 6. Binary concatenation +
Mystring Mystring::operator+(const Mystring &rhs) const{
   char* buffer = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
   std::strcpy(buffer, str);
   std::strcat(buffer, rhs.str);
   Mystring temp {buffer};
   delete [] buffer;
   return temp; 
}  

// 7. Binary concatenation +=
Mystring& Mystring::operator+=(const Mystring &rhs){
    *this = *this + rhs;
    return *this; 
}

// 8. Binary * (repetition)
Mystring Mystring::operator*(int N) const{
    // Can also be implemented using the + operator    
    char* buff = new char[ ((std::strlen(str))*N) + 1 ];
    std::strcpy(buff, str); //first time 
    for(int i {0}; i<(N-1); i++)  {
        std::strcat(buff, str);
    }
    Mystring temp {buff};
    delete [] buff; 
    return temp; 
}

// 9. Binary *= (repetition and assignment)
Mystring& Mystring::operator*=(int N){
    *this = *this * N; //don't return (*this * N) -> R value reference (ie. &&)
    return *this;  
}

// 10. Unary pre-increment ie. ++x, make all characters uppercase
Mystring& Mystring::operator++()   {  // pre-increment
   for(size_t i {0}; i<std::strlen(str); i++) {
       str[i] = std::toupper(str[i]);
   }
   return *this;
}

// 11. Unary post-increment ie. x++ -> return object by value   
Mystring Mystring::operator++(int) {  
   Mystring temp (*this);           // create copy (with the old *this)
   operator++();                    // call pre-increment 
   return temp;                     // return the old value
}