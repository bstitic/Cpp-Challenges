/***
The following code includes my tests with local objects only. Please refer to the official solution on the course website for the 
tests provided by the instructor (official main.cpp file). The official solution also includes the -> operator and unique pointers.

Moreover, the files required to run this challenge are also available on the course website, specifically: 
Account.h, Account.cpp, Account_Util.h, Account_Util.cpp, Checking_Account.h, Checking_Account.cpp, I_Printable.h, I_Printable.cpp,
Savings_Account.h, Savings_Account.cpp, Trust_Account.h and Trust_Account.cpp. 

Regarding the exception classes that should be implemented for this challenge (IllegalBalanceException and InsufficientFundsException), 
the file IllegalBalanceException.h is provided by the instructor. The changes to make are very straighforward based on the challenge
instructions. Once this class is ready, creating the second class is very simple.
***/

// The following #include directives were provided by the instructor except for the last two.
#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"
#include "IllegalBalanceException.h"
#include "InsufficientFundsException.h"

using namespace std; // This was also provided by the instructor.

int main() {
    
    // Tests with local objects
    
    try {
        //Local objects
        Checking_Account checking_account = Checking_Account{"Cookie", -1000};
        std::cout << "hello!" << std::endl; //this doesn't execute -> this is fine  
        Savings_Account savings_account = Savings_Account{"Muffin", -2000, 5};
        Trust_Account trust_account = Trust_Account{"Vanilla", 1000, 5};
    }
    catch(IllegalBalanceException& ex) { // Can also use const (please see official solution)
        std::cout << ex.what() << std::endl; // Can also use std::cerr (please see official solution)
    }
    
    try{
        Savings_Account savings_account = Savings_Account{"Vanilla", 1000, 5};
        savings_account.withdraw(2000);
    }
    catch(InsufficientFundsException& ex){
        std::cout << ex.what() << std::endl; 
    }
	
    return 0;
}
