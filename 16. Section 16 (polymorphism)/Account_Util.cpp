/***
This challenge starts from the official solution to the previous challenge (Section 15). The following files, which are 
required for this challenge (Section 16), were provided by the instructor: Account.h, Account.cpp, Account_Util.h, Account_Util.cpp,
Checking_Account.h, Checking_Account.cpp, Savings_Account.h, Savings_Account.cpp, Trust_Account.h, Trust_Account.cpp, main.cpp. Please
refer to the course website for these files. 

I will only be sharing my modified Account_Util.cpp file and the additional tests I added in my main.cpp file. This is because the 
modifications I made to the other files are very similar to the official changes made by the instructor. Also, regarding my Account_Util.cpp, 
despite my solution being very similar to the official one there are some key differences which is why I've decided to share it. Moreover, the 
two additional files I created for this challenge, which are related to an abstract class which is used as an interface, are also pretty much 
the same as the official solution (it also includes two extra files). 

Everything I described in the previous paragraph is influenced by the fact that some code was already available in the challenge description.
Also, the modifications to make were very clearly described by the instructor.  Therefore, please refer to the course website for the 
official solution. 
***/

// These #include directives are also part of the official solution.
#include <iostream>
#include "Account_Util.h"

// Displays objects pointed to in a vector with pointers to Account objects (dynamic polymorphism) 
void display(const std::vector<Account *> &accounts) {
    std::cout << "\n=== Accounts===========================================" << std::endl;
    // The loop below worked with &acc, which I prefer. 
	// It also worked with const auto acc (like in the official solution).
    for (const auto &acc: accounts) 
        std::cout << (*acc) << std::endl;
}

// The deposit and withdraw functions worked with const auto &acc (acc is a pointer). Please 
// refer to the official solution for an alternative loop and another operator which can be 
// used in this context.

// Deposits a specified amount to each object pointed to in the vector (dynamic polymorphism)
void deposit(std::vector<Account *> &accounts, double amount) {
    std::cout << "\n=== Depositing to Accounts =================================" << std::endl;
    for (const auto &acc: accounts)  {
        if ((*acc).deposit(amount)) 
            std::cout << "Deposited " << amount << " to " << (*acc) << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << (*acc) << std::endl;
    }
}

// Withdraw a specific amount from each object pointed to in the vector (dynamic polymorphism)
void withdraw(std::vector<Account *> &accounts, double amount) {
    std::cout << "\n=== Withdrawing from Accounts ==============================" <<std::endl;
    for (const auto &acc: accounts)  {
        if ((*acc).withdraw(amount)) 
            std::cout << "Withdrew " << amount << " from " << (*acc) << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << (*acc) << std::endl;
    } 
}
