/******************************\
* Program: EggThief.cpp  BETA  *
* Creators: Tristan and Austin *
* Last Edit: 5/11/18           *
\******************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include <sstream>

using namespace std;
void StoreField(char field[60][31]){
	
	/* Stores the array to the Field TXT */
	
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
	
	/* Declaration of Variables */
	
	char field[60][31] = {'O'};
	char s = ' ';
	int xPos = 0;
	int yPos = 0;
	int level = 1;
	int r1 = 0;
	int r2 = 0;
	int x = 0;
	int n = 0;
	int y = 0;
	int count = 0;
	string highs = "";
	int highScore;
	ifstream high;
	ofstream newHigh;
	
	/* Initialization of Random Numbers and HTML */
	
	srand(static_cast<int>(time(0)));
	system("open /Users/student/Documents/Egg-Thief-V1.0.html");
	
	cout << "Please Select CodeRunner to Continue." << endl;
	
	/* Initializing as clear field */
	
	for(x = 0; x < 60; x++){
		for(y = 0; y < 31; y++){
			field[x][y] = ' ';
		}
	}
	
	/* Generation of Rocks for Level 1 */
	
	for(int t = 0; t < 100*level; t++){
		r1 = (rand() % (61)) - 1;
		r2 = (rand() % (32)) - 1;
		field[r1][r2] = 'O';
	}
	
	/* Initial Location of X and @ */
	
	xPos = (rand() % (61)) - 1;
	yPos = (rand() % (32)) - 1;
	field[xPos][yPos] = 'X';
	r1 = (rand() % (61)) - 1;
	r2 = (rand() % (32)) - 1;
	field[r1][r2] = '@';
	
	/* Saving field to the TXT */
	
	StoreField(field);
	
	/* Initialize continuous character inputs */
	
	system("stty raw");

	/* Main game loop */
	
	do {
		
		/* Getting character input */
				
		s = getchar();
		
		/* Clearing off X so it will only be where placed after movement */
		
		if(field[xPos][yPos] != '@'){
			field[xPos][yPos] = ' ';
		}
		
		/* Proccessing direction of movement and transferring across map when leaving the edge */
		
		if(s == 'W' || s =='w'){
			cout << "You went up" << endl;
			yPos -= 1;
			if(yPos < 0){
				yPos = 30;
			}
			if(field[xPos][yPos] == 'O'){
				yPos += 1;
			}
		}
		if(s == 'A' || s =='a'){
			cout << "You went left" << endl;
			xPos -= 1;
			if(xPos < 0){
				xPos = 59;
			}
			if(field[xPos][yPos] == 'O'){
				xPos += 1;
			}
		}
		if(s == 'S' || s =='s'){
			cout << "You went down" << endl;
			yPos += 1;
			if(yPos > 30){
				yPos = 0;
			}
			if(field[xPos][yPos] == 'O'){
				yPos -= 1;
			}
		}
		if(s == 'D' || s =='d'){
			cout << "You went right" << endl;
			xPos += 1;
			if(xPos >= 60){
				xPos = 0;
			}
			if(field[xPos][yPos] == 'O'){
				xPos -= 1;
			}
		}
		
		/* Check for and code for Level up */
		
		if(field[xPos][yPos] == '@'){
			level += 1;
			
			/* Clearing field */
			
			for(x = 0; x < 60; x++){
				for(y = 0; y < 31; y++){
					field[x][y] = ' ';
				}
			}
			
			/* Generation of next level Rocks */
			
			for(int t = 0; t < 100*level; t++){
				r1 = (rand() % (61)) - 1;
				r2 = (rand() % (32)) - 1;
				field[r1][r2] = 'O';
			}
			
			/* Replacement of X and @ */
			
			xPos = (rand() % (61)) - 1;
			yPos = (rand() % (32)) - 1;
			field[xPos][yPos] = 'X';
			r1 = (rand() % (61)) - 1;
			r2 = (rand() % (32)) - 1;
			field[r1][r2] = '@';
		} else {
			/* Placement of X if not Level up */
			
			field[xPos][yPos] = 'X';
		}
		
		/* Storing the field at the end of turn */
		
		StoreField(field);
		
		/* Check for attempt to Quit */
		
		if(s == 'Q'){
			s = 'q';
		}
	} while(s != 'q');
	
	/* Final Closing Operations */
	
	system("stty cooked");
	
	cout << "Quitting!" << endl;
	/* Game Over operations */
	
	string end = "";
	end = "  Game Over, Score: " + to_string(level) + "  ";
	for(x = 0; x < (end.length() - 1); x++){
		field[x+20][10] = end.at(x);
	}
	
	/* Store Game Over Message */
	
	StoreField(field);
	
	/* Retrieve Highscore */
	
	/*high.open("HighScore.txt", ios::in);
	if (high.is_open()){
		high >> highs;
		getline(high, highs, '#');
		high.close();
	}
	//stringstream geek(highs);
	//geek >> highScore;
	
	highScore = stoi(highs); 	
	*/
	
	cout << "Please enter highscore from bottom of webpage: ";
	cin >> highScore;
	
	/* Check for and store New Highscore */
	string newHighscore = "";
	if(level > highScore){
		newHigh.open("HighScore.txt", ios::out);
		newHigh << to_string(level);
		newHigh.close();
		newHighscore = "  New Highscore, Past Highscore: " + to_string(highScore) + "  ";
		for(n = 0; n < (newHighscore.length() - 1); n++){
			field[n+15][11] = newHighscore.at(n);
		}
		StoreField(field);
	}
	
}
