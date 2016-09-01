// Ninth Program: Tic-Tac-Toe
// TaiJon Smith
// 03/19/16
// Section 1

#include <time.h>
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
char cOptions[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};  //array for placement options on the board
bool board();  //function for game board setings/situations; if false game is over

//shouldve created a class (check lab 10)

main() {
	int player; //indicates player's turn
	char cFirst; // first player's option (X or O)
	int iSecond; // cpu choice
	srand(time(NULL));	
	player = rand() % 2; //first player chosen at random
	do {
		cout << "Tic-Tac-Toe \n\nYou Are Playing As \"X\"\nThe CPU Is Playing As \"O\"\n\n";   //Gameboard of the tic tac-toe board
		cout << " \t \t \t  |   | \n";
		cout << " \t \t \t" << cOptions[1] <<" | " << cOptions[2] << " | "<< cOptions[3] << "\t \n";
		cout << " \t \t \t  |   | \n";
		cout << "\t\t      ____________\t \n";
		cout << " \t \t \t  |   | \n";
		cout << " \t \t \t" << cOptions[4] <<" | " << cOptions[5] << " | "<< cOptions[6] << "\t \n";	
		cout << " \t \t \t  |   | \n";
		cout << "\t\t      ____________\t \n";
		cout << " \t \t \t  |   | \n";
		cout << " \t \t \t" << cOptions[7] <<" | " << cOptions[8] << " | "<< cOptions[9] << "\t \n";
		cout << " \t \t \t  |   | \n\n";
	if (player % 2 == 0) {  //user's turn
		cFirst = 'X';
		cout << "\nIt's Your Turn.\n\nEnter the Number For The Spot You Want To Place X: ";
		cin >> iSecond;
	}
	else {  //CPU's turn
		cFirst = 'O';
		iSecond = rand() % 10 + 1; //random choice for "O" placement
	}
	// spot holders
	if (iSecond == 1 && cOptions[1] == '1') {
		cOptions[1] = cFirst;
	}
	else if (iSecond == 2 && cOptions[2] == '2') {
		cOptions[2] = cFirst;
	}
	else if (iSecond == 3 && cOptions[3] == '3') {
		cOptions[3] = cFirst;
	}
	else if (iSecond == 4 && cOptions[4] == '4') {
		cOptions[4] = cFirst;
	}
	else if (iSecond == 5 && cOptions[5] == '5') {
		cOptions[5] = cFirst;
	}
	else if (iSecond == 6 && cOptions[6] == '6') {
		cOptions[6] = cFirst;
	}
	else if (iSecond == 7 && cOptions[7] == '7') {
		cOptions[7] = cFirst;
	}
	else if (iSecond == 8 && cOptions[8] == '8') {
		cOptions[8] = cFirst;
	}
	else if (iSecond == 9 && cOptions[9] == '9') {
		cOptions[9] = cFirst;
	}
	else if (player % 2 == 0) {   //if you type an invalid option that isn't 1-9
		cout << "Error: Invalid Choice!\nEnter Any Key To Continue.\n";
		getch(); //waits until user presses a key
		player--; //next player's turn
	}
	else {
	player--; //switch turns
	}
	
	player++; //switch turns
	system("CLS"); //for purposes of keeping one board on the screen
	board();
	} while (board() == true);	//game is still playable (no one has won yet)

	string winner = "default";
	if (player % 2 == 0) { //if cpu wins
		winner = "CPU Wins!";
		}
	else {
		winner = "You Win!"; //if you win
		}
		cout << winner << "\n";
		cout << "Press Any Key To Exit...";
		getch();
}

bool board () {
	//possible ways to win game
	if (cOptions[1] == cOptions[2] && cOptions[2] == cOptions[3]) {
		return (false);
	}
	else if (cOptions[4] == cOptions[5] && cOptions[5] == cOptions[6]) {
		return (false);
	}
	else if (cOptions[7] == cOptions[8] && cOptions[8] == cOptions[9]) {
		return (false);
	}
	else if (cOptions[1] == cOptions[4] && cOptions[4] == cOptions[7]) {
		return (false);
	}
	else if (cOptions[1] == cOptions[5] && cOptions[5] == cOptions[9]) {
		return (false);
	}
	else if (cOptions[2] == cOptions[5] && cOptions[5] == cOptions[8]) {
		return (false);
	}
	else if (cOptions[3] == cOptions[5] && cOptions[5] == cOptions[7]) {
		return (false);
	}
	else if (cOptions[3] == cOptions[6] && cOptions[6] == cOptions[9]) {
		return (false);
		}
	//if there are no 3-in-a-row combinations, game ends in a draw
	else if (cOptions[1] != '1' &&  cOptions[2] != '2'  &&  cOptions[3] != '3' && cOptions[4] != '4' && cOptions[5] != '5' 
    && cOptions[6] != '6' && cOptions[7] != '7' && cOptions[8] != '8' && cOptions[9] != '9') {
		cout << "Game Ends In A Draw!\n";
		cout << "Press Any Letter To Exit...";
		getch();
		return (false);
	}
	else {
		return (true); //game continues
	}
}
