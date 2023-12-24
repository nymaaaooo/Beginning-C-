#include <iostream>
#include <vector>
#include <cctype> // for toupper

using namespace std;

// Prototypes for displaying the menu and getting user selection
void display_menu();
char get_selection();

// Menu handling function prototypes
void handle_display(const vector<int> &v);
void handle_add(vector<int> &v);
void handle_mean(const vector<int> &v);
void handle_small(const vector<int> &v);
void handle_large(const vector<int> &v);
void handle_find(const vector<int> &v);

// Prototypes for functions that work with the list
// to display it, calculate mean, etc.
double calculate_mean(const vector<int> &v);
double get_small(const vector<int> &v);
double get_large(const vector<int> &v);
bool find(const vector<int> &v, int);

int main(){
	
	char selection{};
	vector<int> numbers{};
	
	do{
		display_menu();
		selection = get_selection();
		switch(selection){
			case 'P': handle_display(numbers); break;			
			case 'A': handle_add(numbers); break;
			case 'M': handle_mean(numbers); break;
			case 'S': handle_small(numbers); break;
			case 'L': handle_large(numbers); break;
			case 'F': handle_find(numbers); break;
			case 'Q': cout << "Goodbye" << endl; break;
			default: cout << "Unknown selection, please try again" << endl;
		}
	}while(selection != 'Q');
	
	return 0;
}


void display_menu(){
	cout << "\nP - Print numbers" << endl;
	cout << "A - Add a number" << endl;
	cout << "M - Display mean of the numbers" << endl;
	cout << "S - Display the smallest number" << endl;
	cout << "L - Display the largest number" << endl;
	cout << "F - Find a number" << endl;
	cout << "Q - Quit" << endl;
	cout << "\nEnter your choice: ";
}

char get_selection(){
	char selection;
	cin >> selection;
	return toupper(selection);
}

void handle_display(const vector<int> &v){
	if(v.size() != 0){
		cout << "[ ";
		for(auto i: v){
			cout << i << " ";
		}
		cout << "]" << endl;
	}
	else
		cout << "[] - the list is empty" << endl;
}

void handle_add(vector<int> &v){
	int add_num{};
	cout << "Enter an integer to add to the list: ";
	cin >> add_num;
	v.push_back(add_num);
	cout << add_num << " added" << endl;
}

void handle_mean(const vector<int> &v){
	if(v.size() == 0)
		cout << "Unable to determine the smallest number - list is empty" << endl;
	else
		cout << "The mean is: " << calculate_mean(v) << endl;
}

void handle_small(const vector<int> &v){
	if(v.size() == 0)
		cout << "Unable to determine the smallest number - list is empty" << endl;
	else
		cout << "The smallest number is " << get_small(v) << endl;
}

void handle_large(const vector<int> &v){
	if(v.size() == 0)
		cout << "Unable to determine the largest number - list is empty" << endl;
	else 
		cout << "The largest number is " << get_large(v) << endl;
}

// Гараас 'F' сонголтыг хийх үед энэ функц дуудагдана.
void handle_find(const vector<int> &v){
	int target{};
    cout << "Enter the number to find: ";
    cin >> target;
    if (find(v, target)) 
        cout << target << " was found" << endl;
    else
        cout << target << " was not found" << endl;
}

double calculate_mean(const vector<int> &v){
	int total{};
	for(auto i: v)
		total += i;
	return static_cast<double>(total) / v.size();
}

double get_small(const vector<int> &v){
	int smallest = v.at(0);
	for(auto i: v)
		if(smallest > i)
		smallest = i;
	return smallest;
}

double get_large(const vector<int> &v){
	int largest = v.at(0);
	for(auto i: v)
		if(largest < i)
			largest = i;
	return largest;
}

bool find(const vector<int> &v, int target){
	for(auto i: v)
		if(target == i)
			return true;
	return false;
}