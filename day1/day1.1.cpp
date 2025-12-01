#include <fstream>
#include <iostream>
#include <list>

using namespace std;
int main(){
	int starting_number = 50;
	int count = 0;
	string inputFile = "input.txt"

	list<string> input = {};

	ifstream f(inputFile);

    if (!f.is_open()) {
        cerr << "Error opening the file!";
        return 1;
    }
    string s;
    while (getline(f, s)){
		input.push_back(s);
	}
    f.close();

	for (string i : input){

		string text = i;
		text[0] = '0';
		string temp;
		int temper;

		if(i[3] && i[2] != 0) text[1] = '0';
		if(i[0] == 'L') starting_number = starting_number - stoi(text);
		if(i[0] == 'R') starting_number = starting_number + stoi(text);

		if(starting_number < 0) {starting_number = 100 - abs(starting_number);
		}
		
		if (starting_number >= 100 || starting_number < 0){ 
			temp = to_string(abs(starting_number))[0];
			starting_number = starting_number - (stoi(temp)*100);
		}
		if(starting_number == 0) count += 1;
	}
	cout << count << endl;
	
}
