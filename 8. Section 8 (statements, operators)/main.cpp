// For the alternative solution, please refer to Section 8 of the course
#include <iostream>

using namespace std; 

int main() {

    const int DOLLAR {100}; // 1 dollar = 100 cents
    const int QUARTER {25}; // 1 quarter = 25 cents
    const int DIME {10}; // 1 dime = 10 cents
    const int NICKEL {5}; // 1 nickel = 5 cents
    const int PENNY {1}; // 1 penny = 1 cent
    
    cout << "Enter an amount in cents: ";
    int cents_user {0};
    cin >> cents_user; 
    
    int remainder {0};
    int dollars {0};
    int quarters {0};
    int dimes {0};
    int nickels {0};
    int pennies {0};
    
    if (cents_user <= 0){ //0 cents 
       ; //do nothing, leave everything as 0
    } else {
        dollars = (cents_user / DOLLAR); //STEP 1: dollars
        remainder = (cents_user - (dollars*DOLLAR)); //eg. 150 - (1*100) = 100
        
        if (remainder > 0){ // STEP 2: quarters
            quarters = (remainder/QUARTER);
            remainder = (remainder - (quarters*QUARTER));
            
            if (remainder > 0){ // STEP 3: dimes 
                    dimes = (remainder/DIME);
                    remainder = (remainder - (dimes*DIME));
                    
                    if (remainder > 0){
                            nickels = (remainder/NICKEL);
                            remainder = (remainder - (nickels*NICKEL));
                            
                            if (remainder > 0 ){
                                    pennies = (remainder/PENNY);
                                    remainder = (remainder - (pennies*PENNY));
                            }
                    }
            }

        } 
                
    }
    
    cout << "\nYou can provide this change as follows:" << endl;
    cout << "dollars: " << dollars << endl;
    cout << "quarters: " << quarters << endl;
    cout << "dimes: " << dimes << endl;
    cout << "nickels: " << nickels << endl;
    cout << "pennies: " << pennies << endl;
    
    return 0;
}