/******************************\
* Program: EggTheif.cpp  BETA  *
* Creators: Tristan and Austin *
* Last Edit: 5/03/18           *
\******************************/
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
	int xPos = 0;
	int yPos = 0;
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
				if(field[x][y] != 'O'){
					yPos += 1;
				}
			}
			if(s == 'A' || s =='a'){
				cout << "You went left" << endl;
				if(field[x][y] != 'O'){
					xPos -= 1;
				}
			}
			if(s == 'S' || s =='s'){
				cout << "You went down" << endl;
				if(field[x][y] != 'O'){
					yPos -= 1;
				}
			}
			if(s == 'D' || s =='d'){
				cout << "You went right" << endl;
				if(field[x][y] != 'O'){
					xPos += 1;
				}
			}
			if(xPos >= 60){
				xPos = 0;
			}
			if(xPos < 0){
				xPos = 59;
			}
			if(yPos > 30){
				yPos = 0;
			}
			if(yPos < 0){
				yPos = 30;
			}
			if(field[x][y] == 'Θ'){
				levelup(level); // We will make this a function later.
			} else {
				field[x][y] = 'X';
			}
			if(s == 'q'){
				s = 'Q';
			}
		}

	system("stty cooked");
	
}
