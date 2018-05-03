#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;
void Field(char field[60][31]){
	int x = 0;
	int y = 0;
	ofstream land;
	land.open("Eggland.txt", ios::out);
	for(x = 0; x < 31; x++){
		for(y = 0; y < 60; y++){
			land << 'O';
		}
		land << endl;
	}
	land.close();
}

int main(int argc, char *argv[]) {
	
	char field[60][31] = {'O'};
	char s = ' ';
		
	system("open /Users/student/Documents/Egg-Theif_V0.2b.html");
	
	Field(field);
	/*int x = 0;
	int y = 0;
	for(x = 0; x < 0; x++){
		for(y = 0; y < 0; y++){
			cout << field[x][y];
		}
		cout << endl;
	}*/

	
	while(s != 'Q'){
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
			if(s == 'q'){
				s = 'Q';
			}
		}

	system("stty cooked");
	
}
