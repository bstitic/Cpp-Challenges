/*** 
Please see the official solution for the implementation of a friend function and a more efficient implementation of the 
withdraw method which invokes the Account constructor.

Please note that this challenge also requires the files: Account.h, Account.cpp, Savings_Account.h, Savings_Account.cpp, 
Account_Util.h, Account_Util.cpp and main.cpp, which can be found on the course website. Moreover, for this challenge and the 
solution shared here, Account_Util.h, Account_Util.cpp and main.cpp were modified to include the classes: Checking_Account 
and Trust_Account.

Finally, in the case of Account_Util.h and Account_Util.cpp, I did not share my changes because the modifications to make are very easy 
to understand after going through the course files.
***/

#include "Checking_Account.h"

// Please see Savings_Account.cpp for reference (available on the course website).
Checking_Account::Checking_Account(std::string name, double balance)
    : Account {name, balance}{
}

// Withdraw method: we should consider the $1.50 fee per transaction. 
bool Checking_Account::withdraw(double amount) {
    if (balance - amount - 1.50 >= 0){
            balance -= (amount+1.50);
            return true; 
    } else{
            return false;
    }
}