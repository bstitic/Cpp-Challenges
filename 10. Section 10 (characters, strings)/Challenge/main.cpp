#include <iostream>
#include <string>

using namespace std; 

int main() {
    
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
    
    //cout << (alphabet.length() == key.length()) << endl; //it's ok

    string input_user {}; //input from the user
    cout << "Enter your secret message: ";
    getline(cin, input_user);
    string encrypted_message {input_user}; //copy 
    
    cout << "Encrypting message ... " << endl; 
    
    // Watch lecture video (Section 10) for an easier way to do the next part
	// This easier alternative involves using the += operator to add new characters to the 
	// encrypted message and a range based for loop
    for(size_t i {0}; i < input_user.length(); ++i) {
        size_t position {alphabet.find(input_user.at(i))}; //character at index i 
        if (position != string::npos){ //if it's in the alphabet 
            // replace doc/example: https://www.javatpoint.com/cpp-string-replace-function 
            encrypted_message.at(i) = key.at(position); 
        }
    }
     
    cout << "\nEncrypted message: " << encrypted_message << endl;
    
    cout << "\nDecrypting message ... " << endl; 
    
    string decrypted_message {encrypted_message}; 
    
    for(size_t j {0}; j < encrypted_message.length(); ++j) {
        size_t position {key.find(encrypted_message.at(j))}; 
        if (position != string::npos){ //if it's in the key 
            // replace doc/example: https://www.javatpoint.com/cpp-string-replace-function 
            decrypted_message.at(j) = alphabet.at(position); 
        }
    }
    
    cout << "\nDecrypted message: " << decrypted_message << endl;
    
    cout << "\nOriginal message: " << input_user << endl; 
    cout << "\nAlphabet: " << alphabet << endl; 
    cout << "\nKey: " << key << endl;
    
    return 0;
    }