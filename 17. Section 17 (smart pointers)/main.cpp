/***
The following code corresponds to my implementation of the three functions that were supposed to be implemented in this challenge. This 
code should be added to the original main.cpp file which is available on the course website. In this original file, it is also possible to 
find the Test class, the function prototypes and the implementation of main(). 

Please see the official challenge solution (available on the course website as well) for slight variations of the functions below. Examples
of these differences include the implementation of fill() using move semantics and a slightly different for loop, a different implementation 
of make() as well as the return type of this function and the use of the -> operator in display(). 
***/

// The following #include directives were provided by the instructor
#include <iostream>
#include <memory>
#include <vector>

//Function implementations
// Function 1: create + return a unique_ptr to the vector of shared pointers to Test objects as explained
// in the challenge description.
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make(){
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> ptr = std::make_unique<std::vector<std::shared_ptr<Test>>>();
    std::cout << "In make(), address of ptr is: " << &ptr << std::endl; //To study the ptr 
    return ptr;
}

void fill(std::vector<std::shared_ptr<Test>> &vec, int num) {
    int val;
    for(int i = 0; i < num; i++){
        std::cout << "Please enter an integer value: ";
        std::cin >> val;
        std::shared_ptr<Test> ptr = std::make_shared<Test>(val);
        vec.push_back(ptr);
    }
}

void display(const std::vector<std::shared_ptr<Test>>&vec){
    int j = 0;
    std::cout << "\n**** About to display available data ****" << std::endl; 
    for(const auto &ptr: vec){ //try const, but can also work with auto (solution is with const)
        std::cout << "Data of test object [" << j << "] : " << (*ptr).get_data() << std::endl;  
        j++;
    }
}