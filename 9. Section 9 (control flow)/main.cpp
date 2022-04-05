#include <iostream>
#include <vector>
#include <iomanip>

using namespace std; 

int main() {
    
    char option {};
    vector<int> vec; //vector of integers
    int integer_to_add {}; // for option A
    double mean {}; // for option M
    
    do {
        
        cout << "\nP - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "Q - Quit" << endl; 
        cout << "\nEnter your choice: ";
        
        cin >> option; 
        
        if (option == 'P' || option == 'p'){
            //cout << "Pressed P" << endl; // for debugging
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
        
        else if (option == 'A' || option == 'a'){
            //cout << "Pressed A" << endl; // for debugging
            cout << "Enter an integer to add to the list: ";
            cin >> integer_to_add;
            vec.push_back(integer_to_add);
            cout << integer_to_add << " was added" << endl;
        }
        
        else if (option == 'M' || option == 'm'){
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
        
        else if (option == 'S' || option == 's'){
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
        
        
        else if (option == 'L' || option == 'l'){
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
        
        else if (option == 'Q' || option == 'q'){
            cout << "Goodbye" << endl;
        }
        
        else{
            cout << "Unknown selection, please try again" << endl;
        }
    
    } while( (option != 'q') && (option != 'Q')); //this is from lecture
    
    return 0;
}