/***
Please refer to the course website for the required .txt file (responses.txt) and the official solution.
***/

#include <iostream> // This preprocessor directive was provided by the instructor.
#include <iomanip>
#include <string>
#include <fstream>

//Function to calculate score
int calc_score(const std::string &key, const std::string &answer){
    int matches {0};
    for(size_t i = 0; i < key.length(); i++ ){
        if (key.at(i) == answer.at(i)){
            matches++;
        }
    }
    return matches;
}

//Function to configure headers
void config_headers(const int& student_field, const int& score_field){
    std::cout << std::setw(student_field) << std::left << "Student"
              << std::setw(score_field) << std::right << "Score"
              << std::endl; 
}

//Function to configure dashes
void dashes(const int& total_field){
    std::cout << std::setw(total_field) << std::setfill('-') << "" << std::endl; 
    std::cout << std::setfill(' '); //reset blank space
}

//Function to display average score
void display_avg(const int& student_field, const int& score_field, const double& sum, const int& students){
    std::cout << std::setprecision(1) << std::fixed; 
    std::cout << std::setw(student_field) << std::left << "Average score" 
              << std::setw(score_field) << std::right << sum/students
              << std::endl; 
    std::cout << std::endl;
}

int main() {
    
    // 1. Create ifstream object and try to open the file
    const std::string file_name {"responses.txt"}; //with ../responses.txt it crashes
    std::ifstream in_file;
    in_file.open(file_name);
    
    if(!in_file){
    	std::cerr << "Error opening " << file_name << std::endl;
    	return 1;
    }

    // 2. Obtain correct answer key (as a std::string)
    std::string key {};
    in_file >> key;
    
    // 3. Set up variables for names, answers, running sum and students
    std::string name {};
    std::string answer {};
    double sum {0.0};
    int students {0};
    
    // 4. Set up constants for field widths
    const int student_field {25};
    const int score_field {15};
    const int total_field {40};
    
    // 5. Configure table headers and dashes
    config_headers(student_field, score_field);
    dashes(total_field);
    
    // 6. Display student information (name and score) 
    while (in_file >> name >> answer){
        int score = calc_score(key, answer);
        students++;
        sum += score; 
        std::cout << std::setw(student_field) << std::left << name 
                  << std::setw(score_field) << std::right << score
                  << std::endl;
    }
    
    // 7. Dashes, display average and close file
    dashes(total_field);
    display_avg(student_field, score_field, sum, students);
    in_file.close();
    
    return 0;
}