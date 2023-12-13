#include <iostream>
#include <string>

using namespace std;

int main(){
	
	string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	string key{"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
	
	string sec_msg{};
	
	cout << "Enter your secret message: ";
	getline(cin, sec_msg);
	
	cout << "\nEncrypting message..." << endl;
	string enc_msg{};
	
	for(char c: sec_msg){
		size_t position = alphabet.find(c);
		if(position != string::npos){
			char new_pos{key.at(position)};
			enc_msg += new_pos;
		}
		else{
			enc_msg += c;
		}
	}
	cout << "\nEncrypted message: " << enc_msg << endl;
	
	string dec_msg{};
	
	for(char c: enc_msg){
		size_t position = key.find(c);
		if(position != string::npos){
			char new_pos{alphabet.at(position)};
			dec_msg += new_pos;
		}
		else{
			dec_msg += c;
		}
	}
	
	cout << "\nDecrypted message: " << dec_msg << endl;

	
	return 0;
}	