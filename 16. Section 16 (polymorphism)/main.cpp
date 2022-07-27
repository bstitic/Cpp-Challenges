/***
This challenge starts from the official solution to the previous challenge (Section 15). The following files, which are 
required for this challenge (Section 16) and should be modified, were provided by the instructor: Account.h, Account.cpp, Account_Util.h, 
Account_Util.cpp, Checking_Account.h, Checking_Account.cpp, Savings_Account.h, Savings_Account.cpp, Trust_Account.h, Trust_Account.cpp, main.cpp. 
Please refer to the course website for these files.  

I will only be sharing my modified Account_Util.cpp file and the additional tests I added in my main.cpp file. This is because the 
modifications I made to the other files are very similar to the official changes made by the instructor. Also, regarding my Account_Util.cpp, 
despite my solution being very similar to the official one there are some key differences which is why I've decided to share it. Specifically,
the differences refer to the for loops, the rest is the same (the first std::cout lines of every function + function signatures). Moreover, the 
two additional files I created for this challenge, which are related to an abstract class which is used as an interface, are also pretty much 
the same as the ones which are part of the official solution (it also includes two extra files). 

Everything I described in the previous paragraph is influenced by the fact that some code was already available in the challenge description.
Also, the modifications to make were very clearly described by the instructor.  Therefore, please refer to the course website for the 
official solution. 
***/

// The following #include directives were provided by the instructor.
#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std; // This was provided by the instructor.

int main() {
	// The following two lines were provided by the instructor.
    cout.precision(2);
    cout << fixed;

    cout << "Hi! This starts here!\n" << endl;
    
    //Please refer to the official solution for account 'frank'.
    frank.deposit(1000);
    frank.withdraw(500);
    cout << frank << endl;
    cout << endl;
    
    //Testing a local object (Savings_Account). 
    Savings_Account cookie {"Cookie", 30000, 5};
    cout << cookie << endl;
    cookie.deposit(1000);
    cookie.withdraw(500);
    cout << cookie << endl;
    cout << endl;
    
    // Testing a local object (Trust_Account).
    Trust_Account muffin {"Muffin", 10000, 5};
    cout << muffin << endl;
    muffin.deposit(1000);
    muffin.deposit(5000);
    muffin.withdraw(10000);
    muffin.withdraw(10);
    muffin.withdraw(10);
    muffin.withdraw(10);
    muffin.withdraw(10);
    cout << muffin << endl;
    cout << endl;
    
	// Please refer to the official solution for the tests carried out with a std::vector<Account *> 
	// to test out dynamic binding/dynamic polymorphism. The tests above refer to static binding instead.

    return 0;
}

