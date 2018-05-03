#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;
int main(int argc, char *argv[]) {
	char input = ' ';
	char s = ' ';
	char x = ' ';
	system("open /Users/student/Documents/Egg-Theif_V0.2b.html");
	
	while(s != 'Q' || s != 'q'){
			system("stty raw");
			s = getchar();
			
			
			
			if(s == 'W' || s =='w'){
				cout << "You went up" << endl;
			}
			if(s == 'A' || s =='a'){
				cout << "You went left" << endl;
			}
			if(s == 'S' || s =='s'){
				cout << "You went down" << endl;
			}
			if(s == 'D' || s =='d'){
				cout << "You went right" << endl;
			}
		}

	system("stty cooked");
	
}