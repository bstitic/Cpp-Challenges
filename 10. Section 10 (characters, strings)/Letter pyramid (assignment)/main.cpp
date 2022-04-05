#include <iostream>
#include <string>

using namespace std; 

int main() {
    
    string input_user {}; //input from the user
    cout << "Enter your string: ";
    getline(cin, input_user);
    
    string message_to_display_first_part {}; //empty string, concatenate using +
    
    for(size_t j {0}; j < input_user.length(); j++){ //for every line
        
        //1. Blank spaces to center the pyramid
        for(size_t s {0}; s < (input_user.length() - (j+1)) ; s++){
            cout << " "; 
        }
        
        //2. Configure first part of the output string
        message_to_display_first_part += input_user.at(j);
        
        cout << message_to_display_first_part; 
        
        //3. Configure second half of the row
        if(j > 0){
            string message_to_display_second_part {input_user.substr(0, j)}; //initial pos, len
            
            //m>=0 fails with size_t, because size_t is unsigned (goes back to largest number)
            for (size_t m {message_to_display_second_part.length()}; m > 0 ; --m){ 
                cout << message_to_display_second_part.at(m-1);
            }
            
        }
        
        cout << endl;
            
            
    }
     
    return 0;
   
}