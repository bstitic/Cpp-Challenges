/***
Please see the official solution available on the course website. In this file, I have only included the code I added to test the classes:
Trust_Account and Checking_Account. The testing process of these two classes follows a similar logic to the testing of the classes: Account 
and Savings_Account (in the original main.cpp file). Finally, please see the comments in the other shared files for more about the required files 
which are available on the course website.
***/

#include "Account_Util.h" //This was provided by the instructor.
#include "Checking_Account.h"
#include "Trust_Account.h"

using namespace std; //This line of code was provided by the course instructor

int main() {
	// These two lines of code were provided by the course instructor 
    cout.precision(2);
    cout << fixed;
    
    // Checking accounts
    vector<Checking_Account> check_accounts;
    check_accounts.push_back(Checking_Account {} );
    check_accounts.push_back(Checking_Account {"Cookie"} );
    check_accounts.push_back(Checking_Account {"Burger", 2000} );
    check_accounts.push_back(Checking_Account {"Domino", 5000} );

    display(check_accounts);
    deposit(check_accounts, 1000);
    withdraw(check_accounts, 2000);
    
    // Trust accounts
    vector<Trust_Account> trust_accounts;
    trust_accounts.push_back(Trust_Account {} );
    trust_accounts.push_back(Trust_Account {"Mario"} );
    trust_accounts.push_back(Trust_Account {"Luigi", 2000} );
    trust_accounts.push_back(Trust_Account {"Kirby", 5000, 5.0} );

    
    // Please see the official solution for alternative testing (with loop)
    display(trust_accounts);
    
    deposit(trust_accounts, 1000);
    deposit(trust_accounts, 5000);
    
    withdraw(trust_accounts, 5000); //should fail (less than 20%)
    
    withdraw(trust_accounts, 100);
    withdraw(trust_accounts, 100);
    withdraw(trust_accounts, 100);
    withdraw(trust_accounts, 100); //should fail 
    
    return 0;
}