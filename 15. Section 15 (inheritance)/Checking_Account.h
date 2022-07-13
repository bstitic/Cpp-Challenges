/*** 
Based on the challenge description, a Checking Account has a name, a balance and a fee of $1.50 for each withdrawal transaction. 
Please see the official challenge solution for more on: a friend function (<< operator), another private constexpr which organizes
the code better and additional libraries that can be included. 
   
Please note that this file follows the structure of the files: Account.h and Savings_Account.h, which were provided by the 
course instructor. Similarly, this challenge also requires the files: Account.cpp, Savings_Account.cpp, Account_Util.h, Account_Util.cpp 
and main.cpp, which can be found on the course website. Moreover, for this challenge and the solution shared here, Account_Util.h, 
Account_Util.cpp and main.cpp were modified to include the classes: Checking_Account and Trust_Account. 

Finally, in the case of Account_Util.h and Account_Util.cpp, I did not share my changes because the modifications to make are very easy 
to understand after going through the course files.
***/   

#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_
#include "Account.h"

class Checking_Account: public Account {
private:
    static constexpr const char *def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
public:
    Checking_Account(std::string name = def_name, double balance =def_balance);    
    bool withdraw(double amount);
    // Inherits the Account::deposit method
};

#endif // _CHECKING_ACCOUNT_H_