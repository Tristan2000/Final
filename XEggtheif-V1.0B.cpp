/******************************\
* Program: EggTheif.cpp  BETA  *
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
	
	// Stores the array to the Field TXT \\
	
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
	
	// Declaration of Variables \\
	
	char field[60][31] = {'O'};
	char s = ' ';
	int xPos = 0;
	int yPos = 0;
	int level = 1;
	int r1 = 0;
	int r2 = 0;
	int x = 0;
	int y = 0;
	int count = 0;
	string highs = "";
	int highScore;
	bool checkOpen = false;
	bool canOpen = true;
	ifstream high;
	ofstream newHigh;
	
	// Initialization of Random Numbers and HTML \\
	
	srand(static_cast<int>(time(0)));
	system("open /Users/student/Downloads/Final-master/Egg-Theif-V1.0B.html");
	
	// Initializing as clear field \\
	
	for(x = 0; x < 60; x++){
		for(y = 0; y < 31; y++){
			field[x][y] = ' ';
		}
	}
	
	// Generation of Rocks for Level 1 \\
	
	for(int t = 0; t < 100*level; t++){
		r1 = (rand() % (61)) - 1;
		r2 = (rand() % (32)) - 1;
		field[r1][r2] = 'O';
	}
	
	// Initial Location of X and @ \\
	
	xPos = (rand() % (61)) - 1;
	yPos = (rand() % (32)) - 1;
	field[xPos][yPos] = 'X';
	r1 = (rand() % (61)) - 1;
	r2 = (rand() % (32)) - 1;
	field[r1][r2] = '@';
	
	// Saving field to the TXT \\
	
	StoreField(field);
	
	// Initialize continuous character inputs \\
	
	system("stty raw");

	// Main game loop \\
	
	while(s != 'q'){
		
		// Getting character input \\
				
		s = getchar();
		
		// Clearing off X so it will only be where placed after movement \\
		
		if(field[xPos][yPos] != '@'){
			field[xPos][yPos] = ' ';
		}
		
		// Proccessing direction of movement \\
		
		if(s == 'W' || s =='w'){
			if(field[xPos][yPos-1] != 'O'){
				yPos -= 1;
			}
		}
		if(s == 'A' || s =='a'){
			if(field[xPos-1][yPos] != 'O'){
				xPos -= 1;
			}
		}
		if(s == 'S' || s =='s'){
			if(field[xPos][yPos+1] != 'O'){
				yPos += 1;
			}
		}
		if(s == 'D' || s =='d'){
			if(field[xPos+1][yPos] != 'O'){
				xPos += 1;
			}
		}
		
		// Transferring across map when leaving the edge \\
		
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
		
		// Check for and code for Level up \\
		
		if(field[xPos][yPos] == '@'){
			level += 1;
			
			// Clearing field \\
			
			for(x = 0; x < 60; x++){
				for(y = 0; y < 31; y++){
					field[x][y] = ' ';
				}
			}
			
			// Generation of next level Rocks \\
			
			for(int t = 0; t < 100*level; t++){
				r1 = (rand() % (61)) - 1;
				r2 = (rand() % (32)) - 1;
				field[r1][r2] = 'O';
			}
			
			// Replacement of X and @ \\
			
			xPos = (rand() % (61)) - 1;
			yPos = (rand() % (32)) - 1;
			field[xPos][yPos] = 'X';
			r1 = (rand() % (61)) - 1;
			r2 = (rand() % (32)) - 1;
			field[r1][r2] = '@';
		} else {
			// Placement of X if not Level up \\
			
			field[xPos][yPos] = 'X';
		}
		
		// Storing the field at the end of turn \\
		
		StoreField(field);
		
		// Check for attempt to Quit \\
		
		if(s == 'Q'){
			s = 'q';
		}
	}
	cout << "Quitting!";
	// Game Over operations \\
	
	string end = "";
	end = "  Game Over, Score: " + to_string(level) + "  ";
	for(x = 0; x < end.length(); x++){
		field[x+20][10] = end[x];
	}
	
	// Store Game Over Message \\
	
	cout << 0;
	StoreField(field);
	
	// Retrieve Highscore \\
	
	cout << 1;
	while(checkOpen == false && canOpen == true){
		high.open("HighScore.txt");
		checkOpen = high.is_open();
		count += 1;
		if(count >= 100){
			cerr << "Error: Failed to open file in " << count << " attempts.";
			canOpen = false;
		}
	}
	cout << 2;
	if(canOpen == true){
		high >> highs;
		high.close();
		stringstream geek(highs);
		geek >> highScore;
	}
	cout << 3;
	// Check for and store New Highscore \\
	
	if(level > highScore){
		newHigh.open("HighScore", ios::out);
		newHigh << highScore;
		newHigh.close();
		end = "  New Highscore, Past Highscore: " + to_string(highScore) + "  ";
		for(x = 0; x < end.length(); x++){
			field[x+20][11] = end[x];
		}
		StoreField(field);
	}
	cout << 4;
	// Final Closing Operations \\
	
	system("stty cooked");
	
}
