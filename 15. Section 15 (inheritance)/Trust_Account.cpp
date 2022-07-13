/***
Please note that this challenge also requires the files: Account.h, Account.cpp, Savings_Account.h, Savings_Account.cpp, 
Account_Util.h, Account_Util.cpp and main.cpp, which can be found on the course website. Moreover, for this challenge and the 
solution shared here, Account_Util.h, Account_Util.cpp and main.cpp were modified to include the classes: Checking_Account 
and Trust_Account.

Finally, in the case of Account_Util.h and Account_Util.cpp, I did not share my changes because the modifications to make are very easy 
to understand after going through the course files.
***/

#include "Trust_Account.h"

/* 
Ways to improve this constructor (based on the official solution): it is possible to only include the name, balance and int_rate as part of 
the parameter list and then invoke the Savings_Account constructor + initialize withdrawals to 0 directly (please see the official solution). 
For this application, this actually makes more sense. 
*/
Trust_Account::Trust_Account(std::string name, double balance, double int_rate, int withdrawals)
    : Savings_Account {name, balance, int_rate}, withdrawals{withdrawals} {
}

// Please see the official solution for an alternative implementation of this method with constexprs (private).
bool Trust_Account::deposit(double amount) {
    // If the amount is 5000 or more
    if (amount >= 5000){
        amount += 50.00;
    }
    return Savings_Account::deposit(amount);
}

// Please see the alternative solution on the course website with constexprs and the ++ operator.
bool Trust_Account::withdraw(double amount) {
    if ( (withdrawals < 3) && (amount <= (0.2*balance) ) ) {
        withdrawals += 1;
        return Savings_Account::withdraw(amount);
    }
    else {
        return false;
    }
}

// This implementation is very similar (almost identical) to the official solution.
std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%, withdrawals: " << account.withdrawals << " ]";
    return os;
}