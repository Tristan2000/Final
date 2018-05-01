#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;
int main(int argc, char *argv[]) {
	char input = ' ';
	char s[1];
	//system("open /Users/student/Documents/Thistest.html");
	for(int c; c<10; c++){//(input != 'Q'){
		cout.flush();
		cin.get(s, 1);
		if(s[0] != '.'){
			cout << "You pressed " << s << "." << endl;
		}
	}
	system("");
	
}