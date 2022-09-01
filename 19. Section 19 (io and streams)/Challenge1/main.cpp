/***
Please see the official solution for the required structs, the variable "tours" (Tours struct) and an alternative solution to this challenge.
The official code is very nicely organized and uses, for example, constants. Also, the loop used in the official solution is especially interesting.
***/

// The following preprocessor directives were provided by the instructor.
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

// Please see the official solution for the required structs (City, Country, Tours)

// Function prototypes
void ruler(void); 
double population_millions(double value);

// Constants
const double MILLIONS = 1000000;

int main()
{
    
	// Please see the official solution for the variable tours (Tours struct)
    
    // 1. Display the ruler
    ruler();
	
	// 2. Headers of the table
    std::cout << std::endl; //endl and \n -> next line, but std::endl flushes the output buffer (\n does not)
    std::cout << std::setw(66) << tours.title << "\n" << std::endl; 
    
    std::cout << std::setw(28) << std::left << "Country" 
              << std::setw(15) << "City"
              << std::setw(35) << std::right << "Population (M)" 
              << std::setw(25) << "Price" 
              <<  std::endl; //City, Population, Price
    
    std::cout << std::setw(103) << std::setfill('-') << "-" << std::endl; 
    std::cout << std::setfill(' '); //reset; std::setfill is persistent
    
	
    // 3. Display data
	int j {0}; // variable for the first city of a country (please see code below)
    for(auto &country : tours.countries) {   // loop through the countries
        j = 0; //city index
        std::cout << std::setw(28) << std::left << country.name;
        
        for(auto &city : country.cities) { // loop through the cities of a country
            if (j > 0)
                std::cout << std::setw(28) << " ";
            
            // next: std::setprecision and std::fixed are persistent, but we'd like a different
            // configuration depending on whether it's cost or population data
            std::cout     << std::setw(15) << std::left << city.name 
                          << std::setw(35) << std::right << std::setprecision(4) << std::fixed << population_millions(city.population)
                          << std::setw(25)  << std::setprecision(2) << std::fixed << city.cost 
                          << std::endl;
            j++; 
        }
        
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
    
    return 0;
}

void ruler(void){
    std::cout << "1234567890123456789012345678901234567890"
              << "12345678901234567890123456789012345678901234567890" 
              << "1234567890123"
              << std::endl;
}

double population_millions(double value){
    return value/MILLIONS;
}