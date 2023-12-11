/*
 * Author: Tom Williams
 * Final Project
 * CIS 127.1993.F23
 * Date: 10/13/23
 *
 * Requirements:
 * A text based dungeon crawl game.
 * Will need to do the following:
 * 	Store game info to a file - at least 6 pieces of information
 * 	Prompt user for directions
 * 	Gather and store items
 * 	Remove items from inventory when used
 * 	Player must encounter other characters
 *
 * Description:
 * The player's goal will be to steal the lich king's phylactery and destroy it to save the kingdom.
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>

#ifndef CHARACTERMENU_H_
#define CHARACTERMENU_H_

int playerMenu(int menuChoice, roomEvents& game, playerCharacter& user) {

	bool menu = false; //boolean that will keep menu running.
	bool quit = false; //boolean to check if player wants to quit.
	char input; // user input to move around the menu
	int i; //integer used to pull inventory data
	int iNum = 1; //inventory number
	string cInput = "a"; //string to help clear a phantom input

	cout << "*************************************************************************************************" << endl;
	cout << "*Player Menu:                                                                                   *" << endl;
	cout << "*************************************************************************************************" << endl;
	cout << "*[c] - Display Character Stats                                                                  *" << endl;
	cout << "*[i] - Display Inventory                                                                        *" << endl;
	cout << "*[s] - Save Game                                                                                *" << endl;
	cout << "*[x] - Return to Game                                                                           *" << endl;
	cout << "*                                                                                               *" << endl;
	cout << "*[q] - Return to Main Menu                                                                      *" << endl;
	cout << "*************************************************************************************************" << endl;
	cout << endl;

	while (menu == false) {

		cout << "Enter Command: ";
		cin >> input;
		cout << endl;
		input = (char)tolower(input); //ensures the menu choice is lowercase.

		//displays character stats
		if (input == 'c') {
			user.PrintAdventurer();
		}

		//displays character inventory
		else if (input == 'i') {
			iNum = 1; //resets inventory number back to 1.

			cout << "*************************************************************************************************" << endl;
			cout << "*Player Inventory:                                                                              *" << endl;
			cout << "*************************************************************************************************" << endl;

			//checks against switches for true items only
			for (i = 8; i <= 17; ++i) {
				if (game.GetEvent(i) == true) {
					cout << iNum << ": " << game.GetItem(i) << endl;
					++iNum;
				}
			}
		}

		//for help menu
		else if (input == 's') {
			ofstream outFS;
			unsigned int s;

			outFS.open("dungeon.csv");

			if (!outFS.is_open()) {
				cout << "Could not open file dungeon.csv" << endl;
				return 1;
			}

			//saves character class data
			outFS << user.GetName() << endl;
			outFS << user.GetCurrHP() << endl;
			outFS << user.GetMaxHP() << endl;
			outFS << user.GetCurrentRoom() << endl;
			outFS << user.GetCountdown() << endl;

			//save event/item/conversation triggers
			for (s = 0; s <= 30; ++s) {
				outFS << game.GetEvent(s) << endl;
			}

			outFS.close();

			cout << "**Game Saved!**" << endl;
		}

		//returns to previous room the player was in
		else if (input == 'x') {
			menuChoice = user.GetCurrentRoom(); //returns player to the last room that they were in.
			menu = true;
		}

		//for help menu
		else if (input == 'q') {
			cout << "Quit current game and return to main menu, [y] or [n]?" << endl;
			while (quit == false) {
				cout << "Enter Command: ";
				cin >> input;
				cout << endl;
				input = (char)tolower(input);

				//if player wants to exit to main menu
				if (input == 'y') {
					cout << "Returning to main menu." << endl;
					user.SetDefaults(); //sets player object back to default. Just in case a new game is selected while at main menu.
					game.SetDefaults(); //sets event triggers object to defaults. Just in case a new game is selected while at main menu.
					menuChoice = 0; //sets switch to go to main menu
					menu = true;
					quit = true;
				}
				else if (input == 'n') {
					cout << "Returning to character menu." << endl;
					cout << endl;

					cout << "*************************************************************************************************" << endl;
					cout << "*Player Menu:                                                                                   *" << endl;
					cout << "*************************************************************************************************" << endl;
					cout << "*[c] - Display Character Stats                                                                  *" << endl;
					cout << "*[i] - Display Inventory                                                                        *" << endl;
					cout << "*[h] - Display How to Play                                                                      *" << endl;
					cout << "*[s] - Save Game                                                                                *" << endl;
					cout << "*[x] - Return to Game                                                                           *" << endl;
					cout << "*                                                                                               *" << endl;
					cout << "*[q] - Return to Main Menu                                                                      *" << endl;
					cout << "*************************************************************************************************" << endl;
					quit = true;
				}
			}
			quit = false; //resets boolean so player can change their mind
		}
		else {
			cout << "You can't do that." << endl;
		}
		cout << endl;
	}
	getline(cin, cInput); //used to clear a phantom input
	return menuChoice;
}



#endif /* CHARACTERMENU_H_ */
