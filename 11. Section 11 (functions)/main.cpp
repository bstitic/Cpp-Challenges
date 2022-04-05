#include <iostream>
#include <vector>
#include <iomanip>
#include <cctype> // for the toupper() function

using namespace std; 

// Function prototypes
char display_menu(); 
void print_numbers(vector<int>);
vector<int> add_numbers(vector<int>);
void mean_of_numbers(vector<int>);
void smallest_number(vector<int>);
void largest_number(vector<int>);

int main() {
    
    char option {};
    vector<int> vec; //vector of integers
    
    do {
        
        option = display_menu(); 
        
        if (option == 'P'){
            print_numbers(vec);
        }
        
        else if (option == 'A'){
            vec = add_numbers(vec);
        }
        
        else if (option == 'M'){
            mean_of_numbers(vec);
        }
        
        else if (option == 'S'){
            smallest_number(vec);
        }
        
        
        else if (option == 'L'){
            largest_number(vec);
        }
        
        else if (option == 'Q'){
            cout << "Goodbye" << endl;
        }
        
        else{
            cout << "Unknown selection, please try again" << endl;
        }
    
    } while( option != 'Q' ); //this is from lecture
    
    return 0;
}

// Function implementations

char display_menu(){
    
    char input_option {};
    
    cout << "\nP - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl; 
    cout << "\nEnter your choice: ";
    
    cin >> input_option;
    
    return toupper(input_option); 
    
}

void print_numbers(vector<int> vec){
    
    if (vec.size() == 0 ){
        cout << "[] - the list is empty" << endl;
    } else{
        cout << "[ ";
        for(auto integer_element : vec){
            cout << integer_element << " ";
        }
        cout << "]" << endl;
    }
    
}

vector<int> add_numbers(vector <int> vec){
    
    //cout << "Pressed A" << endl; // for debugging
    int integer_to_add {}; // for option A
    cout << "Enter an integer to add to the list: ";
    cin >> integer_to_add;
    vec.push_back(integer_to_add);
    cout << integer_to_add << " was added" << endl;
    
    return vec;
    
}

void mean_of_numbers(vector <int> vec){
    
    double mean {}; // for option M
    
    //cout << "Pressed M" << endl;// for debugging
    if (vec.size() == 0 ) {
        cout << "Unable to calculate the mean - no data" << endl; 
    } else{
        mean = 0.0; // reset the mean 
        for (auto integer_element : vec){
            mean += integer_element;
        }
        mean /= vec.size();
        cout << fixed << setprecision(3);
        cout << "The mean is : " << mean << endl; 
    } 

}

void smallest_number(vector<int> vec){
 
    //cout << "Pressed S" << endl; // for debugging
    if (vec.size() == 0){
        cout << "Unable to determine the smallest number - list is empty" << endl;
    }
    else {
        int smallest {vec[0]}; //first element of the list
        for (auto integer_element: vec){
            if (integer_element <= smallest){
                smallest = integer_element; 
            }
        }
        cout << "The smallest number is " << smallest << endl;
    }   
    
}

void largest_number(vector<int> vec){
    
    //cout << "Pressed L" << endl; //for debugging
    if (vec.size() == 0){
        cout << "Unable to determine the largest number - list is empty" << endl;
    }
    else {
        int largest {vec[0]}; //first element of the list
        for (auto integer_element: vec){
            if (integer_element >= largest){
                largest = integer_element; 
            }
        }
        cout << "The largest number is " << largest << endl;
    }   
    
}