#include <iostream>

using namespace std;

int main(){
	
//  define conversion values in cents
	const int dollar{100}; 
	const int quarter{25}; 
	const int dime{10};
	const int nickel{5}; 
	const int penny{1};
	
	int cents{};
	int amount_dollars{}, amount_quarters{}, amount_dimes{},
	amount_nickels{}, amount_penny{}, balance{};
	
	cout << "Enter an amount in cents: ";
	cin >> cents;
	
	amount_dollars = cents / dollar;
	balance = cents - (dollar * amount_dollars);
	
	amount_quarters = balance / quarter;
	balance -= quarter * amount_quarters;
	
	amount_dimes = balance / dime;
	balance -= dime * amount_dimes;
	
	amount_nickels = balance / nickel;
	balance -= nickel * amount_nickels;
	
	amount_penny = balance / penny;
	balance -= penny * amount_penny;


	cout << "You can provide change for this change as follows: " << endl;
	cout << "dollars  : " << amount_dollars << endl;
	cout << "querters : " << amount_quarters << endl;
	cout << "dimes    : " << amount_dimes << endl;
	cout << "nickels  : " << amount_nickels << endl;
	cout << "pennies  : " << amount_penny << endl;
	
	return 0;
}