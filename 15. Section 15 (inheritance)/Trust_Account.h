/*** 
Based on the challenge description, a Trust Account has a name, a balance and an interest rate. The deposit method works like the deposit 
of a Savings_Account object with one exception: if $5000.00 or more dollars are deposited into the Trust Account, there will be a $50.00 bonus. 
Regarding the withdrawal method of the Trust Account, there is a limit of 3 withdrawals maximum, where each withdrawal can be up to 20% of 
the balance.

Please see the official challenge solution for additional private constexprs which can be added with the private access modifier. These help 
organize the code quite nicely.
   
Also, please note that this file follows the structure of the files: Account.h and Savings_Account.h, which were provided by the 
course instructor. Similarly, this challenge also requires the files: Account.cpp, Savings_Account.cpp, Account_Util.h, Account_Util.cpp 
and main.cpp, which can be found on the course website. Moreover, for this challenge and the solution shared here, Account_Util.h, 
Account_Util.cpp and main.cpp were modified to include the classes: Checking_Account and Trust_Account.

Finally, in the case of Account_Util.h and Account_Util.cpp, I did not share my changes because the modifications to make are very easy 
to understand after going through the course files.
***/   

#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_
#include "Savings_Account.h"

class Trust_Account: public Savings_Account {
    friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
    static constexpr int def_withdrawals = 0; 
    // def_withdrawals is actually not required, since we can initialize the withdrawals to 0 in the constructor
    // (please see the official solution available on the course website).
protected:
    int withdrawals;
public:
	// The constructor does not actually require "withdrawals" - as mentioned above, please see the official solution for details.
    Trust_Account(std::string name = def_name, double balance =def_balance, double int_rate = def_int_rate, int withdrawals = def_withdrawals);    
    bool deposit(double amount);
    bool withdraw(double amount);
};

#endif // _TRUST_ACCOUNT_H_