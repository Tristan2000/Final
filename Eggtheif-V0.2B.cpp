/******************************\
* Program: EggTheif.cpp  BETA  *
* Creators: Tristan and Austin *
* Last Edit: 5/07/18           *
\******************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>

using namespace std;
void Field(char field[60][31]){
	int x = 0;
	int y = 0;
	ofstream land;
	land.open("Eggland.txt", ios::out);
	for(x = 0; x < 31; x++){
		for(y = 0; y < 60; y++){
			land << ' ';
		}
		land << endl;
	}
	land.close();
}
void StoreField(char field[60][31]){
	int x = 0;
	int y = 0;
	ofstream land;
	land.open("Eggland.txt", ios::out);
	for(x = 0; x < 31; x++){
		for(y = 0; y < 60; y++){
			land << field[y][x];
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
	int level = 1;
	int r1 = 0;
	int r2 = 0;
	int x = 0;
	int y = 0;
	srand(static_cast<int>(time(0)));
	
	system("open /Users/student/Documents/eggtheif.html");
	
	Field(field);
	for(x = 0; x < 0; x++){
		for(y = 0; y < 0; y++){
			field[x][y] = ' ';
		}
	}
	for(int t = 0; t < 15*level; t++){
		r1 = (rand() % (61)) - 1;
		r2 = (rand() % (32)) - 1;
		field[r1][r2] = 'O';
	}
	r1 = (rand() % (61)) - 1;
	r2 = (rand() % (32)) - 1;
	field[r1][r2] = '0';


	StoreField(field);
	
	while(s != 'Q'){
			system("stty raw");
			s = getchar();
			
			
			
			if(s == 'W' || s =='w'){
				cout << "You went up" << xPos << yPos << endl;
				if(field[xPos][yPos] != 'O'){
					yPos += 1;
				}
			}
			if(s == 'A' || s =='a'){
				cout << "You went left" << endl;
				if(field[xPos][yPos] != 'O'){
					xPos -= 1;
				}
			}
			if(s == 'S' || s =='s'){
				cout << "You went down" << endl;
				if(field[xPos][yPos] != 'O'){
					yPos -= 1;
				}
			}
			if(s == 'D' || s =='d'){
				cout << "You went right" << endl;
				if(field[xPos][yPos] != 'O'){
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
			if(field[xPos][yPos] == '0'){
				level += 1;
				Field(field);
				for(x = 0; x < 0; x++){
					for(y = 0; y < 0; y++){
						field[x][y] = ' ';
					}
				}
				for(int t = 0; t < 15*level; t++){
					r1 = (rand() % (61)) - 1;
					r2 = (rand() % (32)) - 1;
					field[r1][r2] = 'O';
				}
				r1 = (rand() % (61)) - 1;
				r2 = (rand() % (32)) - 1;
				field[r1][r2] = '0';
			} else {
				field[xPos][yPos] = 'X';
			}
			StoreField(field);
			if(s == 'q'){
				s = 'Q';
			}
		}

	system("stty cooked");
	
}