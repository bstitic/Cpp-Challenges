// For this challenge, please check the reference material of Section 12 (reference solution and problem statement)
  
#include <iostream>

using namespace std;

// Function prototypes
// Also, it's best practice not to change pointers, so try to use const whenever possible 
// For example here we can use const to avoid changing the elements or the pointer to the arrays
int* apply_all(const int* const array1_ptr, size_t array1_size, const int* const array2_ptr, size_t array2_size);

// Likewise here
void print(const int* const array_ptr, size_t size);

int main() { //This main was taken from the reference material to test the code - please refer to it 
    
    // constants
    const size_t array1_size {5};
    const size_t array2_size {3};
 
    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};
    
    cout << "Array 1: " ;
    print(array1, array1_size);
    
    cout << "Array 2: " ;
    print(array2, array2_size);
    
    int *results = apply_all(array1, array1_size, array2, array2_size);
    constexpr size_t results_size {array1_size * array2_size};
    
    cout << "Result: " ;
    print(results, results_size);
    
    cout << endl;
    
    //Best practice: release memory on the heap (I added this part) 
    delete [] results; 

    return 0;
}


int* apply_all(const int* const array1_ptr, size_t array1_size, const int* const array2_ptr, size_t array2_size){
    
    int* array_ptr = new int[int(array1_size * array2_size)];
    
    int position {0}; //initialize index for the new array
    
    for(size_t i {0}; i < array2_size; i++){ 
        for(size_t j {0}; j < array1_size; j++){
            array_ptr[position] = array2_ptr[i] * array1_ptr[j];
            position++;
        }
    }
    
    return array_ptr; //Common mistake: make sure not to return a changed pointer variable
    
}

void print(const int* const array_ptr, size_t size){
    cout << "[ ";
    
    for(size_t k {0}; k < size; ++k){
        cout << array_ptr[k] << " " ;
    }
    cout << "]" << endl; 
    
}
