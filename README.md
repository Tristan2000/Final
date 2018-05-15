# Egg Thief

## Description
It is a basic game, that is currently only available for calculators. It has been a fairly popular on calculators and needs to have a version meant for computers. In the game you are a Thief, represented by an 'X', and you have to collect all of the Eggs, represented as a '@', as the level in the game rises so does the number of rocks, represented by an 'O', that you have to navigate around to get the eggs.

## Running
To properly run this you may, it might also work if the files are in the documents folder, need to copy the html file path and paste it in the line 56 section making it so the C++ will know where it is located on your computer.
system("open /Users/student/Downloads/Final-master/Egg-Theif-V1.0B.html");
When you start the program you will need to switch to whatever you are using to run C++. This is because C++ takes your input and not the html. Make sure to use the cpp labeled as V1.0 and have all other V1.0 files in the folder with it as well as the proper system path for the html, the html does not have to be in the same folder as long as its path is copied corectly.

## Example Code
// Initial Location of X and @ \\
	
	xPos = (rand() % (61)) - 1;
	yPos = (rand() % (32)) - 1;
	field[xPos][yPos] = 'X';
	r1 = (rand() % (61)) - 1;
	r2 = (rand() % (32)) - 1;
	field[r1][r2] = '@';
## Contributors
Austin and Tristan.
