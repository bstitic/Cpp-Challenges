/***
Please refer to the course website for the required .txt file (romeoandjuliet.txt) and the official solution.
***/

#include <iostream> // This directive was provided by the instructor.
#include <string>
#include <fstream>

using namespace std;

// Function for looking for the target substring in each word
// Based on the following good reference (please see it):
// https://www.tutorialspoint.com/check-if-a-string-contains-a-sub-string-in-cplusplus
void is_substring(const std::string &text_word, const std::string &substring, int &target_substring_count){
    long long unsigned int index {0};
    int position {0};
    index = text_word.find(substring, position);
    if (index != string::npos)
        target_substring_count++;
}

// Function for displaying results
void display_results(const int& total_words, const std::string& substring, const int& target_substring_count){
    std::cout << total_words << " words were searched..." << std::endl;
    std::cout << "The substring " << substring << " was found " << target_substring_count << " times" 
              << std::endl; 
}

int main() {
    
    // 1. Create ifstream object and try to open the file
    const std::string file_name {"romeoandjuliet.txt"};
    std::ifstream in_file;
    in_file.open(file_name);
    
    if(!in_file){
    	std::cerr << "Error opening " << file_name << std::endl;
    	return 1;
    }
    
    // 2. Set up variables
    int target_substring_count {0}; // Count of target word (substring)
    int total_words {0}; // Total amount of words
    std::string substring {};  // Substring to find (user input)
    std::string text_word {}; //Current word (from text)
    
    // 3. Ask the user for the word to search (case sensitive implementation)
    std::cout << "Enter the substring to search for: ";
    std::cin >> substring; 
    
    // 4. Process the file
    while (in_file >> text_word){
        total_words++; // Increment total amount of words
        is_substring(text_word, substring, target_substring_count);
    }
    
    // 5. Display results
    display_results(total_words, substring, target_substring_count);
    
    // 6. Close file
    in_file.close();
    
    return 0;
}