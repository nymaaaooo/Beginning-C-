#include <iostream>
#include <vector>

using namespace std;

int main(){
	
	vector<int> my_list{};
	char selection{};
	
	do{
		cout << "\nP - Print numbers" << endl;
		cout << "A - Add number" << endl;
		cout << "M - Display mean of the numbers" << endl;
		cout << "S - Display the smallest number" << endl;
		cout << "L - Display the largest number" << endl;
		cout << "Q - Quit" << endl;
		
		cout << "\nEnter your choice: ";
		cin >> selection;
		
		if(selection == 'P' || selection == 'p'){
			if(my_list.size() == 0)
				cout << "[] - the list is empty" << endl;
			else{
				cout << "[ ";
				for(auto item: my_list)
					cout << item << " ";
				cout << "]" << endl;
			}
		}
		else if(selection == 'A' || selection == 'a'){
			int add_num;
			cout << "Enter an integer to add to the list: ";
			cin >> add_num;
			my_list.push_back(add_num);
			cout << add_num << " added" << endl;
		}
		else if(selection == 'M' || selection == 'm'){
			if(my_list.size() == 0)
				cout << "Unable to calculate mean - no data" << endl;
			else{
				int total{};
				for (auto num: my_list)
					total += num;
				cout << "The mean is: " << static_cast<double>(total) / my_list.size()<< endl;
			}
		}
		else if(selection == 'S' || selection == 's'){
			if(my_list.size() == 0)
				cout << "Unablr to determine the smallest - list is empty" << endl;
			else {
				int smallest = my_list.at(0);
				for (auto i: my_list){
					if (i < smallest)
						smallest = i;
				}
				cout << "The smallest number is " << smallest << endl;
			}
		}
		else if(selection == 'L' || selection == 'l'){
			if(my_list.size() == 0)
				cout << "Unable to determine the largest - list is empty" << endl;
			else{
				int largest = my_list.at(0);
				for (auto i: my_list){
					if(i > largest)
						largest = i;
				}
				cout << "The largest number is " << largest << endl;
			}
		}
		else if(selection == 'Q' || selection == 'q'){
			cout << "Goodbye" << endl;
		}
		else{
			cout << "Unknown selection, please try again" << endl;
		}

	}while(selection != 'q' && selection != 'Q');
	
	return 0;
}