/***
Please refer to the course website for the required .txt file (romeoandjuliet.txt) and the official solution, which is quite similar.
***/

#include <iostream> // This directive was provided by the course instructor.
#include <iomanip>
#include <string>
#include <fstream>

void read_and_copy(std::ifstream &input_file, std::ofstream &output_file, std::string &line, int &line_number) {
    while ( std::getline(input_file, line) ) {
        output_file << std::setw(10) << std::left << line_number 
                    << line << std::endl; 
        line_number++;
        //line_number << "\t\t" << line << std::endl; //\t makes it look misaligned
    }
}

int main() {
    
    // 1. Initialize input and output stream objects + try to open them
    std::ifstream input_file {"romeoandjuliet.txt"};
    std::ofstream output_file {"romeoandjuliet_out.txt"};

    if (!input_file) {
        std::cerr << "Error opening the input file" << std::endl;
        return 1;
    }

     if (!output_file) {
        std::cerr << "Error opening the output file" << std::endl;
        return 1;
    }
    
    // 2. Declare and initialize the required variables
    std::string line {};
    int line_number {1}; 
    
    // 3. Read lines of the input file (formatted) and create copy
    read_and_copy(input_file, output_file, line, line_number);
    
    // 4. Close files
    input_file.close();
    output_file.close();
    
    return 0;
}