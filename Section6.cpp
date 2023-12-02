#include <iostream>

using namespace std;

int main(){
	const double small_price {25.0};
	const double large_price {35.0};
	const double per {0.06};
	const int day {30};
	
	int small_room_num, large_room_num;
	cout << "Hello, welcome to Nymaa's Carpet Cleaning Service." << endl;
	cout << "\nHow many small rooms would you like cleaned? ";
	cin >> small_room_num;
	cout << "How many large rooms would you like cleaned? ";
	cin >> large_room_num;
	cout << "\nEstimate for carpet cleaning service" << endl;
	cout << "Number of small rooms: " << small_room_num << endl;
	cout << "Number of large rooms: " << large_room_num << endl;
	cout << "Price per small room: $" << small_price << endl;
	cout << "Price per large room: $" << large_price << endl;
	cout << "Cost: $" << (small_room_num * small_price) + (large_room_num * large_price) << endl;
	cout << "Tax: $" << ((small_room_num * small_price) + (large_room_num * large_price)) * per<< endl;
	cout << "=======================" << endl;
	cout << "Total estimate: $" << ((small_room_num * small_price) + (large_room_num * large_price)) + 
	(((small_room_num * small_price) + (large_room_num * large_price)) * per)<< endl;
	cout << "This estimate is valid for " << day << " days" << endl; 
	return 0;
}