#include <iostream>
#include <vector>

using namespace std; 

int main() {
    
    // 1. Declare 2 empty vectors of integers 
    vector <int> vector1;
    vector <int> vector2;
    
    // 2. Add 10 and 20 to vector 1 dynamically using push_back
    // Display the elements of vector1 using at() as well as its size with size() 
    vector1.push_back(10);
    vector1.push_back(20);
    
    cout << "First element of vector1: " << vector1.at(0) << endl; 
    cout << "Second element of vector1: " << vector1.at(1) << endl; 
    cout << "Size of vector1: " << vector1.size() << endl;

    // 3. Add 100 and 200 to vector 2 dynamically using push_back
    // Display the elements of vector2 using at() as well as its size with size() 
    vector2.push_back(100);
    vector2.push_back(200);
    
    cout << "\nFirst element of vector2: " << vector2.at(0) << endl; 
    cout << "Second element of vector2: " << vector2.at(1) << endl; 
    cout << "Size of vector2: " << vector2.size() << endl;
    
    // 4. Declare an empty 2D vector called vector_2d
    vector <vector<int>> vector_2d; 
    
    // 5. Add vector1 to vector_2d dynamically using push_back
    //    Add vector2 to vector_2d dynamically using push_back
    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);
    
    // 6. Display the elements in vector_2d using the at() method
    cout << "\nElement [0,0] of vector_2d: " << vector_2d.at(0).at(0) << endl;
    cout << "Element [0,1] of vector_2d: " << vector_2d.at(0).at(1) << endl;
    cout << "Element [1,0] of vector_2d: " << vector_2d.at(1).at(0) << endl;
    cout << "Element [1,1] of vector_2d: " << vector_2d.at(1).at(1) << endl;
    
    // 7. Change vector1.at(0) to 1000
    vector1.at(0) = 1000;
    
    // 8. Display the elements in vector_2d again using the at() method
    // (It doesn't change because what happened when we added elements to vector_2d was that copies were added to it)
    cout << "\nElement [0,0] of vector_2d after changing vector1: " << vector_2d.at(0).at(0) << endl;
    cout << "Element [0,1] of vector_2d after changing vector1: " << vector_2d.at(0).at(1) << endl;
    cout << "Element [1,0] of vector_2d after changing vector1: " << vector_2d.at(1).at(0) << endl;
    cout << "Element [1,1] of vector_2d after changing vector1: " << vector_2d.at(1).at(1) << endl;
    
    // 9. Display the elements in vector1
    cout << "\nFirst element of vector1 after changing it: " << vector1.at(0) << endl; 
    cout << "Second element of vector1 after changing it: " << vector1.at(1) << endl; 
    cout << "Size of vector1 after changing it: " << vector1.size() << endl;
    
}