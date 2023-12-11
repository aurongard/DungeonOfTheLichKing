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

#ifndef EASTERNMAZE_H_
#define EASTERNMAZE_H_

//minitaur chance
void MiniTaurChance(playerCharacter& user) {
	int userHp = user.GetCurrHP(); //calls player hp
	srand((unsigned) time(NULL)); //creating seed value for random number generator
	int minitaurChance = rand() % 100 + 1; //generates a random number from 1 - 100.

	if (minitaurChance > 80) { // 20% chance that the Mini-Taur encounter will happen
		cout << "THE MINI-TAUR HAS FOUND YOU!" << endl;
		cout << endl;
		cout << "The clacking of hooves echo in the hall as you are suddenly assaulted by a two foot tall Mini-taur" << endl;
		cout << "brandishing a properly proportioned greataxe. It slashes your leg as it lets loose a hearty laugh" << endl;
		cout << "and runs past you and down the hall into darkness." << endl;
		cout << endl;

		cout << "[You take 1 mini-damage]" << endl;
		cout << endl;

		userHp -= 1;
		user.SetCurrHP(userHp); //rat bite reduces player health by 1
	}
}

//maze room 01
int roomMaze01(int menuChoice, roomEvents& game, playerCharacter& user) {
	bool navigation = false; //boolean that will hold the room for the player, once it's true it will switch to a different room
	string input; //string to hold the users command

	user.PrintAdventurer(); //displays adventurer stats at the start of the room
	cout << endl;

	cout << "You come to the entrance of the burial chambers. The walls are lined with bones and caskets." << endl;
	cout << endl;

	//checks if you encounter the Mini-Taur roaming the halls of the maze
	if (game.GetEvent(24) == false) {

		MiniTaurChance(user);

		if (user.GetCurrHP() <= 0) { //checks if player died and if a game over screen should appear
			menuChoice = 100;
			navigation = true;
		}
	}

	cout << "To the north there is a path." << endl;
	cout << "To the west is the hallway back to the entrance." << endl;
	cout << "To the south there is a path." << endl;
	cout << endl;

	//creates the room instance for the player to interact with the room.
	while (navigation == false) {

		cout << "Enter Command: ";
		getline(cin, input);
		cout << input << endl;

		//inspect the room
		if (input == "look room") {
			cout << "You come to the entrance of the burial chambers. The walls are lined with bones and caskets." << endl;
			cout << endl;
			cout << "To the north there is a path." << endl;
			cout << "To the west is the hallway back to the entrance." << endl;
			cout << "To the south there is a path." << endl;
			cout << endl;
		}

		//inspect the bones
		else if (input == "look bones") {
			cout << "For some reason the bones looked tortured and as though they're calling out for help. You don't " << endl;
			cout <<	"want to end up like them." << endl;
		}

		//inspect the caskets
		else if (input == "look casket") {
			cout << "Each casket is made out of rotting wood and has multiple iron chains wrapped around it. We're these " << endl;
			cout <<	"poor souls buried alive?" << endl;
		}

		//directional
		//north
		//inspect northern passageway
		else if ((input == "look n") || (input == "look north")) {
			cout << "You look north and see only walls lined with bones extending far past the light of your torch." << endl;
		}

		//walk north
		else if ((input == "walk n") || (input == "walk north")) {
			cout << "You walk north" << endl;
			menuChoice = 14; //room 02
			navigation = true;
		}

		//west
		//inspect western passageway
		else if ((input == "look w") || (input == "look west")) {
			cout << "You look west and see the pillars from the entrance hall." << endl;
		}

		//walk west
		else if ((input == "walk w") || (input == "walk west")) {
			cout << "You walk west towards the entrance" << endl;
			menuChoice = 7; //entrance of dungeon
			navigation = true;
		}

		//south
		//inspect southern passageway
		else if ((input == "look s") || (input == "look south")) {
			cout << "You look south and see only walls lined with bones extending far past the light of your torch." << endl;
		}

		//walk south
		else if ((input == "walk s") || (input == "walk south")) {
			cout << "You walk south" << endl;
			menuChoice = 25; //room 13
			navigation = true;
		}

		//calls help menu
		else if (input == "help") {
			menuChoice = 5;
			navigation = true;
		}

		//call the character menu
		else if (input == "character") {
			menuChoice = 90;
			navigation = true;
		}

		//for incorrect input.
		else {
			cout << "You can't do that. " << endl;
		}
		cout << endl;
	}
cout << "*************************************************************************************************" << endl;
cout << endl;
return menuChoice;
}

//maze room 02
int roomMaze02(int menuChoice, roomEvents& game, playerCharacter& user) {
	bool navigation = false; //boolean that will hold the room for the player, once it's true it will switch to a different room
	string input; //string to hold the users command

	user.PrintAdventurer(); //displays adventurer stats at the start of the room
	cout << endl;

	cout << "You come to an intersection. The walls are lined with bones and caskets." << endl;
	cout << endl;

	//checks if you encounter the Mini-Taur roaming the halls of the maze
	if (game.GetEvent(24) == false) {

		MiniTaurChance(user);

		if (user.GetCurrHP() <= 0) { //checks if player died and if a game over screen should appear
			menuChoice = 100;
			navigation = true;
		}
	}

	cout << "To the east there is a path." << endl;
	cout << "To the south there is a path." << endl;
	cout << endl;

	//creates the room instance for the player to interact with the room.
	while (navigation == false) {

		cout << "Enter Command: ";
		getline(cin, input);
		cout << input << endl;

		//inspect the room
		if (input == "look room") {
			cout << "You come to an intersection. The walls are lined with bones and caskets." << endl;
			cout << endl;
			cout << "To the east there is a path." << endl;
			cout << "To the south there is a path." << endl;
			cout << endl;
		}

		else if (input == "look bones") {
			cout << "For some reason the bones looked tortured and as though they're calling out for help. You don't " << endl;
			cout <<	"want to end up like them." << endl;
		}

		//inspect the caskets
		else if (input == "look casket") {
			cout << "Each casket is made out of rotting wood and has multiple iron chains wrapped around it. We're these " << endl;
			cout <<	"poor souls buried alive?" << endl;
		}

		//directional
		//east
		//inspect eastern passageway
		else if ((input == "look e") || (input == "look east")) {
			cout << "You look east and see only walls lined with bones extending far past the light of your torch." << endl;
		}

		//walk east
		else if ((input == "walk e") || (input == "walk east")) {
			cout << "You walk east" << endl;
			menuChoice = 15; //room 03
			navigation = true;
		}

		//south
		//inspect southern passageway
		else if ((input == "look s") || (input == "look south")) {
			cout << "You look south and see only walls lined with bones extending far past the light of your torch." << endl;
		}

		//walk south
		else if ((input == "walk s") || (input == "walk south")) {
			cout << "You walk south" << endl;
			menuChoice = 13; //room 01
			navigation = true;
		}

		//calls help menu
		else if (input == "help") {
			menuChoice = 5;
			navigation = true;
		}

		//call the character menu
		else if (input == "character") {
			menuChoice = 90;
			navigation = true;
		}

		//for incorrect input.
		else {
			cout << "You can't do that. " << endl;
		}
		cout << endl;
	}
cout << "*************************************************************************************************" << endl;
cout << endl;
return menuChoice;
}

//maze room 03
int roomMaze03(int menuChoice, roomEvents& game, playerCharacter& user) {
	bool navigation = false; //boolean that will hold the room for the player, once it's true it will switch to a different room
	string input; //string to hold the users command

	user.PrintAdventurer(); //displays adventurer stats at the start of the room
	cout << endl;

	cout << "You come to an intersection. The walls are lined with bones and caskets." << endl;
	cout << endl;

	//checks if you encounter the Mini-Taur roaming the halls of the maze
	if (game.GetEvent(24) == false) {

		MiniTaurChance(user);

		if (user.GetCurrHP() <= 0) { //checks if player died and if a game over screen should appear
			menuChoice = 100;
			navigation = true;
		}
	}

	cout << "To the north there is a path." << endl;
	cout << "To the east there is a path." << endl;
	cout << "To the west there is a path." << endl;
	cout << endl;

	//creates the room instance for the player to interact with the room.
	while (navigation == false) {

		cout << "Enter Command: ";
		getline(cin, input);
		cout << input << endl;

		//inspect the room
		if (input == "look room") {
			cout << "You come to an intersection. The walls are lined with bones and caskets." << endl;
			cout << endl;
			cout << "To the north there is a path." << endl;
			cout << "To the east there is a path." << endl;
			cout << "To the west there is a path." << endl;
			cout << endl;
		}

		else if (input == "look bones") {
			cout << "For some reason the bones looked tortured and as though they're calling out for help. You don't " << endl;
			cout <<	"want to end up like them." << endl;
		}

		//inspect the caskets
		else if (input == "look casket") {
			cout << "Each casket is made out of rotting wood and has multiple iron chains wrapped around it. We're these " << endl;
			cout <<	"poor souls buried alive?" << endl;
		}

		//directional
		//north
		//inspect northern passageway
		else if ((input == "look n") || (input == "look north")) {
			cout << "You look north and see only walls lined with bones extending far past the light of your torch." << endl;
		}

		//walk north
		else if ((input == "walk n") || (input == "walk north")) {
			cout << "You walk north" << endl;
			menuChoice = 16; //room 04
			navigation = true;
		}

		//east
		//inspect eastern passageway
		else if ((input == "look e") || (input == "look east")) {
			cout << "You look east and see only walls lined with bones extending far past the light of your torch." << endl;
		}

		//walk east
		else if ((input == "walk e") || (input == "walk east")) {
			cout << "You walk east." << endl;
			menuChoice = 19; //room 07
			navigation = true;
		}

		//west
		//inspect western passageway
		else if ((input == "look w") || (input == "look west")) {
			cout << "You look west and see only walls lined with bones extending far past the light of your torch." << endl;
		}

		//walk west
		else if ((input == "walk w") || (input == "walk west")) {
			cout << "You walk west." << endl;
			menuChoice = 14;
			navigation = true;
		}

		//calls help menu
		else if (input == "help") {
			menuChoice = 5;
			navigation = true;
		}

		//call the character menu
		else if (input == "character") {
			menuChoice = 90;
			navigation = true;
		}

		//for incorrect input.
		else {
			cout << "You can't do that. " << endl;
		}
		cout << endl;
	}
cout << "*************************************************************************************************" << endl;
cout << endl;
return menuChoice;
}

//maze room 04
int roomMaze04(int menuChoice, roomEvents& game, playerCharacter& user) {
	bool navigation = false; //boolean that will hold the room for the player, once it's true it will switch to a different room
	int userHp = user.GetCurrHP(); //calls player hp

	string input; //string to hold the users command

	user.PrintAdventurer(); //displays adventurer stats at the start of the room
	cout << endl;

	cout << "You come to an intersection. The walls are lined with bones and caskets. A single upright open" << endl;
	cout <<	"casket protrudes from the clay on the wall. A skeleton stands inside it, chained to the casket" << endl;
	cout << "itself. A small rat sits in the skeleton's mouth staring at you." << endl;
	cout << endl;

	//checks if you encounter the Mini-Taur roaming the halls of the maze
	if (game.GetEvent(24) == false) {

		MiniTaurChance(user);

		if (user.GetCurrHP() <= 0) { //checks if player died and if a game over screen should appear
			menuChoice = 100;
			navigation = true;
		}
	}

	cout << "To the east there is a path." << endl;
	cout << "To the south there is a path." << endl;
	cout << endl;

	//creates the room instance for the player to interact with the room.
	while (navigation == false) {

		cout << "Enter Command: ";
		getline(cin, input);
		cout << input << endl;

		//inspect the room
		if (input == "look room") {
			cout << "You come to an intersection. The walls are lined with bones and caskets. A single upright open" << endl;
			cout <<	"casket protrudes from the clay on the wall. A skeleton stands inside it, chained to the casket" << endl;
			cout << "itself. A small rat sits in the skeleton's mouth staring at you." << endl;
			cout << endl;
			cout << "To the east there is a path." << endl;
			cout << "To the south there is a path." << endl;
			cout << endl;
		}

		else if (input == "look bones") {
			cout << "For some reason the bones looked tortured and as though they're calling out for help. You don't " << endl;
			cout <<	"want to end up like them." << endl;
		}

		//inspect the caskets
		else if (input == "look casket") {
			cout << "Each casket is made out of rotting wood and has multiple iron chains wrapped around it. We're these " << endl;
			cout <<	"poor souls buried alive?" << endl;
		}

		//rat
		//inspect the rat
		else if (input == "look rat") {
			cout << "The rat stares at you hungrily. The creatures gaze makes you uneasy as you realize it probably sees you " << endl;
			cout << "as its next meal." << endl;
		}

		else if (input == "interact rat") {
			cout << "You reach out to touch the rat, and it bites your hand." << endl;
			cout << endl;

			cout << "[You take 1 damage]" << endl;

			userHp -= 1;
			user.SetCurrHP(userHp); //rat bite reduces player health by 1

			if (user.GetCurrHP() <= 0) { //checks if player died and if a game over screen should appear
				menuChoice = 100;
				navigation = true;
			}
		}

		//directional
		//east
		//inspect eastern passageway
		else if ((input == "look e") || (input == "look east")) {
			cout << "You look east and see only walls lined with bones extending far past the light of your torch." << endl;
		}

		//walk east
		else if ((input == "walk e") || (input == "walk east")) {
			cout << "You walk east." << endl;
			menuChoice = 17; //room 05
			navigation = true;
		}

		//south
		//inspect southern passageway
		else if ((input == "look s") || (input == "look south")) {
			cout << "You look south and see only walls lined with bones extending far past the light of your torch." << endl;
		}

		//walk south
		else if ((input == "walk s") || (input == "walk south")) {
			cout << "You walk south." << endl;
			menuChoice = 15; //room 03
			navigation = true;
		}

		//calls help menu
		else if (input == "help") {
			menuChoice = 5;
			navigation = true;
		}

		//call the character menu
		else if (input == "character") {
			menuChoice = 90;
			navigation = true;
		}

		//for incorrect input.
		else {
			cout << "You can't do that. " << endl;
		}
		cout << endl;
	}
cout << "*************************************************************************************************" << endl;
cout << endl;
return menuChoice;
}

//maze room 05
int roomMaze05(int menuChoice, roomEvents& game, playerCharacter& user) {
	bool navigation = false; //boolean that will hold the room for the player, once it's true it will switch to a different room
	string input; //string to hold the users command

	user.PrintAdventurer(); //displays adventurer stats at the start of the room
	cout << endl;

	cout << "You come to an intersection. The walls are lined with bones and caskets." << endl;
	cout << endl;

	//checks if you encounter the Mini-Taur roaming the halls of the maze
	if (game.GetEvent(24) == false) {

		MiniTaurChance(user);

		if (user.GetCurrHP() <= 0) { //checks if player died and if a game over screen should appear
			menuChoice = 100;
			navigation = true;
		}
	}

	cout << "To the north there is a path." << endl;
	cout << "To the west there is a path." << endl;
	cout << endl;

	//creates the room instance for the player to interact with the room.
	while (navigation == false) {

		cout << "Enter Command: ";
		getline(cin, input);
		cout << input << endl;

		//inspect the room
		if (input == "look room") {
			cout << "You come to an intersection. The walls are lined with bones and caskets." << endl;
			cout << endl;
			cout << "To the north there is a path." << endl;
			cout << "To the west there is a path." << endl;
			cout << endl;
		}

		else if (input == "look bones") {
			cout << "For some reason the bones looked tortured and as though they're calling out for help. You don't " << endl;
			cout <<	"want to end up like them." << endl;
		}

		//inspect the caskets
		else if (input == "look casket") {
			cout << "Each casket is made out of rotting wood and has multiple iron chains wrapped around it. We're these " << endl;
			cout <<	"poor souls buried alive?" << endl;
		}

		//directional
		//north
		//inspect northern passageway
		else if ((input == "look n") || (input == "look north")) {
			cout << "You look north and see only walls lined with bones extending far past the light of your torch." << endl;
		}

		//walk north
		else if ((input == "walk n") || (input == "walk north")) {
			cout << "You walk north" << endl;
			menuChoice = 18; //room 06
			navigation = true;
		}

		//west
		//inspect western passageway
		else if ((input == "look w") || (input == "look west")) {
			cout << "You look west and see only walls lined with bones extending far past the light of your torch." << endl;
		}

		//walk west
		else if ((input == "walk w") || (input == "walk west")) {
			cout << "You walk west." << endl;
			menuChoice = 16; //room 04
			navigation = true;
		}

		//calls help menu
		else if (input == "help") {
			menuChoice = 5;
			navigation = true;
		}

		//call the character menu
		else if (input == "character") {
			menuChoice = 90;
			navigation = true;
		}

		//for incorrect input.
		else {
			cout << "You can't do that. " << endl;
		}
		cout << endl;
	}
cout << "*************************************************************************************************" << endl;
cout << endl;
return menuChoice;
}

//maze room 06
int roomMaze06(int menuChoice, roomEvents& game, playerCharacter& user) {
	bool navigation = false; //boolean that will hold the room for the player, once it's true it will switch to a different room
	string input; //string to hold the users command

	user.PrintAdventurer(); //displays adventurer stats at the start of the room
	cout << endl;

	cout << "You enter into what is clearly a larger burial chamber with stone walls and a few sealed stone" << endl;
	cout << "sarcophagi. Whomever was buried here was important. A hole in the wall catches your eye." << endl;
	cout << endl;
	cout << "To the south there is a path." << endl;
	cout << endl;

	//creates the room instance for the player to interact with the room.
	while (navigation == false) {

		cout << "Enter Command: ";
		getline(cin, input);
		cout << input << endl;

		//inspect the room
		if (input == "look room") {
			cout << "You enter into what is clearly a larger burial chamber with stone walls and a few sealed stone" << endl;
			cout << "sarcophagi. Whomever was buried here was important. A hole in the wall catches your eye." << endl;
			cout << endl;
			cout << "To the south there is a path." << endl;
			cout << endl;
		}

		//sarcophagi
		//inspect the sarcophagi
		else if (input == "look casket" || input == "look sarcophagi") {
			cout << "The stone sarcophagi were made with care and look incredibly heavy. Whomever was buried inside" << endl;
			cout <<	"was likely a high ranking officer or family member for Vhile Bonsh." << endl;
		}
		//interact with the sarcophagi
		else if ((input == "interact casket") || (input == "interact sarcophagi")) {
			cout << "You're not sure why, but you try to open one of the stone lids, however it's too heavy. It's" << endl;
			cout << "probably best not to disturb the dead that faithfully served the powerful lich king" << endl;
		}

		//the hole
		//inspect the hole
		else if (input == "look hole") {
			if (game.GetEvent(23) == false) {
				cout << "You look into the hole and see a bunch of cobwebs and spiders, but the silhoutte catches your eye " << endl;
				cout << "and you can see an object deep inside. It looks like you might just be able to reach it if you" << endl;
				cout << "stick your arm inside." << endl;
			}
			else {
				cout << "You look into the hole and don't see anything else worth putting your arm inside for." << endl;
			}
		}

		//interact with the hole
		else if (input == "interact hole") {
			if (game.GetEvent(23) == false) {
				cout << "You carefully reach your arm into the hole in the wall. Your hand tears through mulptiple webs and" << endl;
				cout << "you can feel spiders crawling on your hand trying to get away. Finally your hand touches a cool metal" << endl;
				cout << "object. You grab it and pull it out." << endl;
				cout << endl;
				cout << "Under the torch light you see that you have the iron key to the front entrance in your hand. Carefully" << endl;
				cout << "you clean off the webbing from your sleeve and hand and put the key in your pack." << endl;
				cout << endl;

				game.EventTrigger(16, true);
				game.EventTrigger(23, true);
				cout << "[1 Iron Key added to Inventory]" << endl;


			}
			else {
				cout << "You put your hand in the hole and find nothing else of note and have caused economic devastation "<< endl;
				cout << "for dozens of innocent spiders by destroying their homes." << endl;
			}
		}

		//directional
		//south
		//inspect southern passageway
		else if ((input == "look s") || (input == "look south")) {
			cout << "You look south and see only walls lined with bones extending far past the light of your torch." << endl;
		}

		//walk south
		else if ((input == "walk s") || (input == "walk south")) {
			cout << "You walk south." << endl;
			menuChoice = 17; //room 05
			navigation = true;
		}

		//calls help menu
		else if (input == "help") {
			menuChoice = 5;
			navigation = true;
		}

		//call the character menu
		else if (input == "character") {
			menuChoice = 90;
			navigation = true;
		}

		//for incorrect input.
		else {
			cout << "You can't do that. " << endl;
		}
		cout << endl;
	}
cout << "*************************************************************************************************" << endl;
cout << endl;
return menuChoice;
}

//maze room 07
int roomMaze07(int menuChoice, roomEvents& game, playerCharacter& user) {
	bool navigation = false; //boolean that will hold the room for the player, once it's true it will switch to a different room
	string input; //string to hold the users command

	user.PrintAdventurer(); //displays adventurer stats at the start of the room
	cout << endl;

	//ATTN: add chance for the Mini-taur.

	cout << "You come to an intersection. The walls are lined with bones and caskets." << endl;
	cout << endl;

	//checks if you encounter the Mini-Taur roaming the halls of the maze
	if (game.GetEvent(24) == false) {

		MiniTaurChance(user);

		if (user.GetCurrHP() <= 0) { //checks if player died and if a game over screen should appear
			menuChoice = 100;
			navigation = true;
		}
	}

	cout << "To the east there is a path." << endl;
	cout << "To the west there is a path." << endl;
	cout << "To the south there is a path." << endl;
	cout << endl;

	//creates the room instance for the player to interact with the room.
	while (navigation == false) {

		cout << "Enter Command: ";
		getline(cin, input);
		cout << input << endl;

		//inspect the room
		if (input == "look room") {
			cout << "You come to an intersection. The walls are lined with bones and caskets." << endl;
			cout << endl;
			cout << "To the east there is a path." << endl;
			cout << "To the west there is a path." << endl;
			cout << "To the south there is a path." << endl;
			cout << endl;
		}

		else if (input == "look bones") {
			cout << "For some reason the bones looked tortured and as though they're calling out for help. You don't " << endl;
			cout <<	"want to end up like them." << endl;
		}

		//inspect the caskets
		else if (input == "look casket") {
			cout << "Each casket is made out of rotting wood and has multiple iron chains wrapped around it. We're these " << endl;
			cout <<	"poor souls buried alive?" << endl;
		}

		//directional
		//east
		//inspect eastern passageway
		else if ((input == "look e") || (input == "look east")) {
			cout << "You look east and see only walls lined with bones extending far past the light of your torch." << endl;
		}

		//walk east
		else if ((input == "walk e") || (input == "walk east")) {
			cout << "You walk east." << endl;
			menuChoice = 20; //room 08
			navigation = true;
		}

		//west
		//inspect western passageway
		else if ((input == "look w") || (input == "look west")) {
			cout << "You look west and see only walls lined with bones extending far past the light of your torch." << endl;
		}

		//walk west
		else if ((input == "walk w") || (input == "walk west")) {
			cout << "You walk west." << endl;
			menuChoice = 15; //room 03
			navigation = true;
		}

		//south
		//inspect southern passageway
		else if ((input == "look s") || (input == "look south")) {
			cout << "You look south and see only walls lined with bones extending far past the light of your torch." << endl;
		}

		//walk south
		else if ((input == "walk s") || (input == "walk south")) {
			cout << "You walk south." << endl;
			menuChoice = 21; //room 09
			navigation = true;
		}

		//calls help menu
		else if (input == "help") {
			menuChoice = 5;
			navigation = true;
		}

		//call the character menu
		else if (input == "character") {
			menuChoice = 90;
			navigation = true;
		}

		//for incorrect input.
		else {
			cout << "You can't do that. " << endl;
		}
		cout << endl;
	}
cout << "*************************************************************************************************" << endl;
cout << endl;
return menuChoice;
}

//maze room 08
int roomMaze08(int menuChoice, roomEvents& game, playerCharacter& user) {
	bool navigation = false; //boolean that will hold the room for the player, once it's true it will switch to a different room
	string input; //string to hold the users command

	user.PrintAdventurer(); //displays adventurer stats at the start of the room
	cout << endl;

	cout << "You come to a dead end. The walls are lined with bones and caskets." << endl;
	cout << endl;

	//checks if you encounter the Mini-Taur roaming the halls of the maze
	if (game.GetEvent(24) == false) {

		MiniTaurChance(user);

		if (user.GetCurrHP() <= 0) { //checks if player died and if a game over screen should appear
			menuChoice = 100;
			navigation = true;
		}
	}

	cout << "To the west there is a path." << endl;
	cout << endl;

	//creates the room instance for the player to interact with the room.
	while (navigation == false) {

		cout << "Enter Command: ";
		getline(cin, input);
		cout << input << endl;

		//inspect the room
		if (input == "look room") {
			cout << "You come to a dead end. The walls are lined with bones and caskets." << endl;
			cout << endl;
			cout << "To the west there is a path." << endl;
			cout << endl;
		}

		else if (input == "look bones") {
			cout << "For some reason the bones looked tortured and as though they're calling out for help. You don't " << endl;
			cout <<	"want to end up like them." << endl;
		}

		//inspect the caskets
		else if (input == "look casket") {
			cout << "Each casket is made out of rotting wood and has multiple iron chains wrapped around it. We're these " << endl;
			cout <<	"poor souls buried alive?" << endl;
		}

		//directional
		//west
		//inspect western passageway
		else if ((input == "look w") || (input == "look west")) {
			cout << "You look west and see only walls lined with bones extending far past the light of your torch." << endl;
		}

		//walk west
		else if ((input == "walk w") || (input == "walk west")) {
			cout << "You walk west." << endl;
			menuChoice = 19; //room 07
			navigation = true;
		}

		//calls help menu
		else if (input == "help") {
			menuChoice = 5;
			navigation = true;
		}

		//call the character menu
		else if (input == "character") {
			menuChoice = 90;
			navigation = true;
		}

		//for incorrect input.
		else {
			cout << "You can't do that. " << endl;
		}
		cout << endl;
	}
cout << "*************************************************************************************************" << endl;
cout << endl;
return menuChoice;
}

//maze room 09
int roomMaze09(int menuChoice, roomEvents& game, playerCharacter& user) {
	bool navigation = false; //boolean that will hold the room for the player, once it's true it will switch to a different room
	string input; //string to hold the users command

	user.PrintAdventurer(); //displays adventurer stats at the start of the room
	cout << endl;

	cout << "You come to an intersection. The walls are lined with bones and caskets." << endl;
	cout << endl;

	//checks if you encounter the Mini-Taur roaming the halls of the maze
	if (game.GetEvent(24) == false) {

		MiniTaurChance(user);

		if (user.GetCurrHP() <= 0) { //checks if player died and if a game over screen should appear
			menuChoice = 100;
			navigation = true;
		}
	}

	cout << "To the north there is a path." << endl;
	cout << "To the east there is a path." << endl;
	cout << "To the south there is a path." << endl;
	cout << endl;

	//creates the room instance for the player to interact with the room.
	while (navigation == false) {

		cout << "Enter Command: ";
		getline(cin, input);
		cout << input << endl;

		//inspect the room
		if (input == "look room") {
			cout << "You come to an intersection. The walls are lined with bones and caskets." << endl;
			cout << endl;
			cout << "To the north there is a path." << endl;
			cout << "To the east there is a path." << endl;
			cout << "To the south there is a path." << endl;
			cout << endl;
		}

		else if (input == "look bones") {
			cout << "For some reason the bones looked tortured and as though they're calling out for help. You don't " << endl;
			cout <<	"want to end up like them." << endl;
		}

		//inspect the caskets
		else if (input == "look casket") {
			cout << "Each casket is made out of rotting wood and has multiple iron chains wrapped around it. We're these " << endl;
			cout <<	"poor souls buried alive?" << endl;
		}

		//directional
		//north
		//inspect northern passageway
		else if ((input == "look n") || (input == "look north")) {
			cout << "You look north and see only walls lined with bones extending far past the light of your torch." << endl;
		}

		//walk north
		else if ((input == "walk n") || (input == "walk north")) {
			cout << "You walk north" << endl;
			menuChoice = 19; //room 07
			navigation = true;
		}

		//east
		//inspect eastern passageway
		else if ((input == "look e") || (input == "look east")) {
			cout << "You look east and see only walls lined with bones extending far past the light of your torch." << endl;
		}

		//walk east
		else if ((input == "walk e") || (input == "walk east")) {
			cout << "You walk east." << endl;
			menuChoice = 22; //room 10
			navigation = true;
		}

		//south
		//inspect southern passageway
		else if ((input == "look s") || (input == "look south")) {
			cout << "You look south and see only walls lined with bones extending far past the light of your torch." << endl;
		}

		//walk south
		else if ((input == "walk s") || (input == "walk south")) {
			cout << "You walk south." << endl;
			menuChoice = 23; //room 11
			navigation = true;
		}

		//calls help menu
		else if (input == "help") {
			menuChoice = 5;
			navigation = true;
		}

		//call the character menu
		else if (input == "character") {
			menuChoice = 90;
			navigation = true;
		}

		//for incorrect input.
		else {
			cout << "You can't do that. " << endl;
		}
		cout << endl;
	}
cout << "*************************************************************************************************" << endl;
cout << endl;
return menuChoice;
}

//maze room 10 - The Skull Room where the skull key is
int roomMaze10(int menuChoice, roomEvents& game, playerCharacter& user) {
	bool navigation = false; //boolean that will hold the room for the player, once it's true it will switch to a different room
	string input; //string to hold the users command

	user.PrintAdventurer(); //displays adventurer stats at the start of the room
	cout << endl;

	cout << "You enter into a room full of skulls. There are four pillars made of stacked skulls. There are piles of" << endl;
	cout << "skulls scattered all over the room. The walls, ceiling, and floor are all lined with skulls." << endl;
	cout << endl;
	cout << "This is clearly the 'head' room of the maze. At the center of the room is a throne made of skulls. A " << endl;
	cout << "skeleton sits upon the throne." << endl;
	cout << endl;
	cout << "To the west there is a path back into the maze." << endl;
	cout << endl;

	//creates the room instance for the player to interact with the room.
	while (navigation == false) {

		cout << "Enter Command: ";
		getline(cin, input);
		cout << input << endl;

		//inspect the room
		if (input == "look room") {
			cout << "You are in a room full of skulls. There are four pillars made of stacked skulls. There are piles of" << endl;
			cout << "skulls scattered all over the room. The walls, ceiling, and floor are all lined with skulls." << endl;
			cout << endl;
			cout << "This is clearly the 'head' room of the maze. At the center of the room is a throne made of skulls. A " << endl;
			cout << "skeleton sits upon the throne." << endl;
			cout << endl;
			cout << "To the west there is a path back into the maze." << endl;
			cout << endl;
		}
		//skulls
		//inspect the skulls
		else if (input == "look skulls") {
			cout << "Someone got a-'head' of themselves here." << endl;
		}

		//interact with skulls
		else if (input == "interact skulls") {
			cout << "You have no bones to pick here, and probably shouldn't desecrate anything." << endl;
		}

		//throne
		//inspect the throne
		else if (input == "look throne") {
			cout << "The throne is made up of human, elf, dwarf, and orc skulls. It sends chills down your spine. A " << endl;
			cout << "menacing skeleton sits on the throne and it's socketless eyes pierce through your very soul." << endl;
		}

		//interact with skulls
		else if (input == "interact throne") {
			cout << "This seat is taken." << endl;
		}

		//skeleton
		//inspect the skeleton of King Guy
		else if (input == "look skeleton") {
			cout << "The skeleton sits imposingly on this throne of skulls. The robes it wears are in tatters, and the " << endl;
			cout << "crown sitting atop its head made of gold melted to the skull when it was still alive. You believe" << endl;
			cout << "this to be the corpse of King Guy the 3rd, the first king to fall to Vhile Bonsh. This must be a " << endl;
			cout << "shrine to his fall, and the skulls here must be the remains of his army." << endl;
			cout << endl;
			if (game.GetEvent(25) == false) { //will only display this if you haven't taken the Skull Key
				cout << "In its right hand is a key with a skull on it." << endl;
			}
			if (game.GetEvent(26) == false) { //will only display this text if you haven't taken the shepards staff.
				cout << "In its left hand is a wooden shepards staff." << endl;
			}
		}

		//interact with skeleton of King Guy
		else if (input == "interact skeleton") {
			cout << "This skeleton has already been desecrated enough. Let's leave it alone." << endl;
		}

		//Skull key
		//inspect key
		else if ((input == "look skull key") || (input == "look key")) {
			if (game.GetEvent(25) == false) {
				cout << "The key is tarnished iron with an ivory skull at it's head. The bit of the key is made from teeth." << endl;
			}
			else {
				cout << "There's nothing to look at." << endl;
			}
		}

		//interact with key
		else if ((input == "interact skull key") || (input == "interact key")) {
			if (game.GetEvent(25) == false) {
				cout << "You take the Skull Key from the hand of the skeleton king." << endl;
				cout << endl;
				cout << "[1 Skull Key added to Inventory]" << endl;

				game.EventTrigger(25, true);
				game.EventTrigger(9, true);
			}
			else {
				cout << "There's nothing to take." << endl;
			}
		}

		//shepards staff
		//inspect staff
		else if ((input == "look staff") || (input == "look shepards staff")) {
			if (game.GetEvent(26) == false) {
				cout << "The wooden staff look very old, and like that of a shepard's staff to herd cattle." << endl;
			}
			else {
				cout << "There's nothing to look at." << endl;
			}
		}
		//interact with staff
		else if ((input == "interact staff") || (input == "interact shepards staff")) {
			if (game.GetEvent(26) == false) {
				cout << "You take the Shepard's Staff from the hand of the skeleton king." << endl;
				cout << endl;
				cout << "[1 Shepard's Staff added to Inventory]" << endl;

				game.EventTrigger(26, true);
				game.EventTrigger(24, true);
				game.EventTrigger(17, true);

				cout << endl;
				cout << "You hear a roar from the Mini-taur in the distance and then silence. What just happened?" << endl;
			}
			else {
				cout << "There's nothing to take." << endl;
			}
		}

		//directional
		//west
		//inspect western passageway
		else if ((input == "look w") || (input == "look west")) {
			cout << "You look west and see only walls lined with bones extending far past the light of your torch." << endl;
		}

		//walk west
		else if ((input == "walk w") || (input == "walk west")) {
			cout << "You walk west." << endl;
			menuChoice = 21; //room 09
			navigation = true;
		}

		//calls help menu
		else if (input == "help") {
			menuChoice = 5;
			navigation = true;
		}

		//call the character menu
		else if (input == "character") {
			menuChoice = 90;
			navigation = true;
		}

		//for incorrect input.
		else {
			cout << "You can't do that. " << endl;
		}
		cout << endl;
	}
cout << "*************************************************************************************************" << endl;
cout << endl;
return menuChoice;
}

//maze room 11
int roomMaze11(int menuChoice, roomEvents& game, playerCharacter& user) {
	bool navigation = false; //boolean that will hold the room for the player, once it's true it will switch to a different room
	string input; //string to hold the users command

	user.PrintAdventurer(); //displays adventurer stats at the start of the room
	cout << endl;

	cout << "You come to an intersection. The walls are lined with bones and caskets." << endl;
	cout << endl;

	//checks if you encounter the Mini-Taur roaming the halls of the maze
	if (game.GetEvent(24) == false) {

		MiniTaurChance(user);

		if (user.GetCurrHP() <= 0) { //checks if player died and if a game over screen should appear
			menuChoice = 100;
			navigation = true;
		}
	}

	cout << "To the north there is a path." << endl;
	cout << "To the east there is a path." << endl;
	cout << endl;

	//creates the room instance for the player to interact with the room.
	while (navigation == false) {

		cout << "Enter Command: ";
		getline(cin, input);
		cout << input << endl;

		//inspect the room
		if (input == "look room") {
			cout << "You come to an intersection. The walls are lined with bones and caskets." << endl;
			cout << endl;
			cout << "To the north there is a path." << endl;
			cout << "To the east there is a path." << endl;
			cout << endl;
		}

		else if (input == "look bones") {
			cout << "For some reason the bones looked tortured and as though they're calling out for help. You don't " << endl;
			cout <<	"want to end up like them." << endl;
		}

		//inspect the caskets
		else if (input == "look casket") {
			cout << "Each casket is made out of rotting wood and has multiple iron chains wrapped around it. We're these " << endl;
			cout <<	"poor souls buried alive?" << endl;
		}

		//directional
		//north
		//inspect northern passageway
		else if ((input == "look n") || (input == "look north")) {
			cout << "You look north and see only walls lined with bones extending far past the light of your torch." << endl;
		}

		//walk north
		else if ((input == "walk n") || (input == "walk north")) {
			cout << "You walk north" << endl;
			menuChoice = 21; //room 09
			navigation = true;
		}

		//east
		//inspect eastern passageway
		else if ((input == "look e") || (input == "look east")) {
			cout << "You look east and see only walls lined with bones extending far past the light of your torch." << endl;
		}

		//walk east
		else if ((input == "walk e") || (input == "walk east")) {
			cout << "You walk east." << endl;
			menuChoice = 24; //room 12
			navigation = true;
		}

		//calls help menu
		else if (input == "help") {
			menuChoice = 5;
			navigation = true;
		}

		//call the character menu
		else if (input == "character") {
			menuChoice = 90;
			navigation = true;
		}

		//for incorrect input.
		else {
			cout << "You can't do that. " << endl;
		}
		cout << endl;
	}
cout << "*************************************************************************************************" << endl;
cout << endl;
return menuChoice;
}

//maze room 12
int roomMaze12(int menuChoice, roomEvents& game, playerCharacter& user) {
	bool navigation = false; //boolean that will hold the room for the player, once it's true it will switch to a different room
	string input; //string to hold the users command

	user.PrintAdventurer(); //displays adventurer stats at the start of the room
	cout << endl;

	cout << "You come to a dead end. The walls are lined with bones and caskets." << endl;
	cout << endl;

	//checks if you encounter the Mini-Taur roaming the halls of the maze
	if (game.GetEvent(24) == false) {

		MiniTaurChance(user);

		if (user.GetCurrHP() <= 0) { //checks if player died and if a game over screen should appear
			menuChoice = 100;
			navigation = true;
		}
	}

	cout << "To the west there is a path." << endl;
	cout << endl;

	//creates the room instance for the player to interact with the room.
	while (navigation == false) {

		cout << "Enter Command: ";
		getline(cin, input);
		cout << input << endl;

		//inspect the room
		if (input == "look room") {
			cout << "You come to a dead end. The walls are lined with bones and caskets." << endl;
			cout << endl;
			cout << "To the west there is a path." << endl;
			cout << endl;
		}

		else if (input == "look bones") {
			cout << "For some reason the bones looked tortured and as though they're calling out for help. You don't " << endl;
			cout <<	"want to end up like them." << endl;
		}

		//inspect the caskets
		else if (input == "look casket") {
			cout << "Each casket is made out of rotting wood and has multiple iron chains wrapped around it. We're these " << endl;
			cout <<	"poor souls buried alive?" << endl;
		}

		//directional
		//west
		//inspect western passageway
		else if ((input == "look w") || (input == "look west")) {
			cout << "You look west and see only walls lined with bones extending far past the light of your torch." << endl;
		}

		//walk west
		else if ((input == "walk w") || (input == "walk west")) {
			cout << "You walk west." << endl;
			menuChoice = 23;//room 11
			navigation = true;
		}

		//calls help menu
		else if (input == "help") {
			menuChoice = 5;
			navigation = true;
		}

		//call the character menu
		else if (input == "character") {
			menuChoice = 90;
			navigation = true;
		}

		//for incorrect input.
		else {
			cout << "You can't do that. " << endl;
		}
		cout << endl;
	}
cout << "*************************************************************************************************" << endl;
cout << endl;
return menuChoice;
}

//maze room 13
int roomMaze13(int menuChoice, roomEvents& game, playerCharacter& user) {
	bool navigation = false; //boolean that will hold the room for the player, once it's true it will switch to a different room
	string input; //string to hold the users command

	user.PrintAdventurer(); //displays adventurer stats at the start of the room
	cout << endl;

	cout << "You come to an intersection. The walls are lined with bones and caskets." << endl;
	cout << endl;

	//checks if you encounter the Mini-Taur roaming the halls of the maze
	if (game.GetEvent(24) == false) {

		MiniTaurChance(user);

		if (user.GetCurrHP() <= 0) { //checks if player died and if a game over screen should appear
			menuChoice = 100;
			navigation = true;
		}
	}

	cout << "To the north there is a path." << endl;
	cout << "To the east there is a path." << endl;
	cout << endl;

	//creates the room instance for the player to interact with the room.
	while (navigation == false) {

		cout << "Enter Command: ";
		getline(cin, input);
		cout << input << endl;

		//inspect the room
		if (input == "look room") {
			cout << "You come to an intersection. The walls are lined with bones and caskets." << endl;
			cout << endl;
			cout << "To the north there is a path." << endl;
			cout << "To the east there is a path." << endl;
			cout << endl;
		}

		else if (input == "look bones") {
			cout << "For some reason the bones looked tortured and as though they're calling out for help. You don't " << endl;
			cout <<	"want to end up like them." << endl;
		}

		//inspect the caskets
		else if (input == "look casket") {
			cout << "Each casket is made out of rotting wood and has multiple iron chains wrapped around it. We're these " << endl;
			cout <<	"poor souls buried alive?" << endl;
		}

		//directional
		//north
		//inspect northern passageway
		else if ((input == "look n") || (input == "look north")) {
			cout << "You look north and see only walls lined with bones extending far past the light of your torch." << endl;
		}

		//walk north
		else if ((input == "walk n") || (input == "walk north")) {
			cout << "You walk north" << endl;
			menuChoice = 13;//room 01
			navigation = true;
		}

		//east
		//inspect eastern passageway
		else if ((input == "look e") || (input == "look east")) {
			cout << "You look east and see only walls lined with bones extending far past the light of your torch." << endl;
		}

		//walk east
		else if ((input == "walk e") || (input == "walk east")) {
			cout << "You walk east." << endl;
			menuChoice = 26;//room 14
			navigation = true;
		}

		//calls help menu
		else if (input == "help") {
			menuChoice = 5;
			navigation = true;
		}

		//call the character menu
		else if (input == "character") {
			menuChoice = 90;
			navigation = true;
		}

		//for incorrect input.
		else {
			cout << "You can't do that. " << endl;
		}
		cout << endl;
	}
cout << "*************************************************************************************************" << endl;
cout << endl;
return menuChoice;
}

//maze room 14
int roomMaze14(int menuChoice, roomEvents& game, playerCharacter& user) {
	bool navigation = false; //boolean that will hold the room for the player, once it's true it will switch to a different room
	string input; //string to hold the users command

	user.PrintAdventurer(); //displays adventurer stats at the start of the room
	cout << endl;

	cout << "You come to an intersection. The walls are lined with bones and caskets." << endl;
	cout << endl;

	//checks if you encounter the Mini-Taur roaming the halls of the maze
	if (game.GetEvent(24) == false) {

		MiniTaurChance(user);

		if (user.GetCurrHP() <= 0) { //checks if player died and if a game over screen should appear
			menuChoice = 100;
			navigation = true;
		}
	}

	cout << "To the east there is a path." << endl;
	cout << "To the west there is a path." << endl;
	cout << "To the south there is a path." << endl;
	cout << endl;

	//creates the room instance for the player to interact with the room.
	while (navigation == false) {

		cout << "Enter Command: ";
		getline(cin, input);
		cout << input << endl;

		//inspect the room
		if (input == "look room") {
			cout << "You come to an intersection. The walls are lined with bones and caskets." << endl;
			cout << endl;
			cout << "To the east there is a path." << endl;
			cout << "To the west there is a path." << endl;
			cout << "To the south there is a path." << endl;
			cout << endl;
		}

		else if (input == "look bones") {
			cout << "For some reason the bones looked tortured and as though they're calling out for help. You don't " << endl;
			cout <<	"want to end up like them." << endl;
		}

		//inspect the caskets
		else if (input == "look casket") {
			cout << "Each casket is made out of rotting wood and has multiple iron chains wrapped around it. We're these " << endl;
			cout <<	"poor souls buried alive?" << endl;
		}

		//directional
		//east
		//inspect eastern passageway
		else if ((input == "look e") || (input == "look east")) {
			cout << "You look east and see only walls lined with bones extending far past the light of your torch." << endl;
		}

		//walk east
		else if ((input == "walk e") || (input == "walk east")) {
			cout << "You walk east." << endl;
			menuChoice = 27; //room 15
			navigation = true;
		}

		//west
		//inspect western passageway
		else if ((input == "look w") || (input == "look west")) {
			cout << "You look west and see only walls lined with bones extending far past the light of your torch." << endl;
		}

		//walk west
		else if ((input == "walk w") || (input == "walk west")) {
			cout << "You walk west." << endl;
			menuChoice = 25;//room 13
			navigation = true;
		}

		//south
		//inspect southern passageway
		else if ((input == "look s") || (input == "look south")) {
			cout << "You look south and see only walls lined with bones extending far past the light of your torch." << endl;
		}

		//walk south
		else if ((input == "walk s") || (input == "walk south")) {
			cout << "You walk south." << endl;
			menuChoice = 29;//room 17
			navigation = true;
		}

		//calls help menu
		else if (input == "help") {
			menuChoice = 5;
			navigation = true;
		}

		//call the character menu
		else if (input == "character") {
			menuChoice = 90;
			navigation = true;
		}

		//for incorrect input.
		else {
			cout << "You can't do that. " << endl;
		}
		cout << endl;
	}
cout << "*************************************************************************************************" << endl;
cout << endl;
return menuChoice;
}

//maze room 15
int roomMaze15(int menuChoice, roomEvents& game, playerCharacter& user) {
	bool navigation = false; //boolean that will hold the room for the player, once it's true it will switch to a different room
	string input; //string to hold the users command

	user.PrintAdventurer(); //displays adventurer stats at the start of the room
	cout << endl;

	cout << "You come to an intersection. The walls are lined with bones and caskets." << endl;
	cout << endl;

	//checks if you encounter the Mini-Taur roaming the halls of the maze
	if (game.GetEvent(24) == false) {

		MiniTaurChance(user);

		if (user.GetCurrHP() <= 0) { //checks if player died and if a game over screen should appear
			menuChoice = 100;
			navigation = true;
		}
	}

	cout << "To the north there is a path." << endl;
	cout << "To the west there is a path." << endl;
	cout << endl;

	//creates the room instance for the player to interact with the room.
	while (navigation == false) {

		cout << "Enter Command: ";
		getline(cin, input);
		cout << input << endl;

		//inspect the room
		if (input == "look room") {
			cout << "You come to an intersection. The walls are lined with bones and caskets." << endl;
			cout << endl;
			cout << "To the north there is a path." << endl;
			cout << "To the west there is a path." << endl;
			cout << endl;
		}

		else if (input == "look bones") {
			cout << "For some reason the bones looked tortured and as though they're calling out for help. You don't " << endl;
			cout <<	"want to end up like them." << endl;
		}

		//inspect the caskets
		else if (input == "look casket") {
			cout << "Each casket is made out of rotting wood and has multiple iron chains wrapped around it. We're these " << endl;
			cout <<	"poor souls buried alive?" << endl;
		}

		//directional
		//north
		//inspect northern passageway
		else if ((input == "look n") || (input == "look north")) {
			cout << "You look north and see only walls lined with bones extending far past the light of your torch." << endl;
		}

		//walk north
		else if ((input == "walk n") || (input == "walk north")) {
			cout << "You walk north" << endl;
			menuChoice = 28;//room 16
			navigation = true;
		}

		//west
		//inspect western passageway
		else if ((input == "look w") || (input == "look west")) {
			cout << "You look west and see only walls lined with bones extending far past the light of your torch." << endl;
		}

		//walk west
		else if ((input == "walk w") || (input == "walk west")) {
			cout << "You walk west." << endl;
			menuChoice = 26; //room 14
			navigation = true;
		}

		//calls help menu
		else if (input == "help") {
			menuChoice = 5;
			navigation = true;
		}

		//call the character menu
		else if (input == "character") {
			menuChoice = 90;
			navigation = true;
		}

		//for incorrect input.
		else {
			cout << "You can't do that. " << endl;
		}
		cout << endl;
	}
cout << "*************************************************************************************************" << endl;
cout << endl;
return menuChoice;
}

//maze room 16
int roomMaze16(int menuChoice, roomEvents& game, playerCharacter& user) {
	bool navigation = false; //boolean that will hold the room for the player, once it's true it will switch to a different room
	string input; //string to hold the users command

	user.PrintAdventurer(); //displays adventurer stats at the start of the room
	cout << endl;

	cout << "You come to a dead end. The walls are lined with bones and caskets." << endl;
	cout << endl;

	//checks if you encounter the Mini-Taur roaming the halls of the maze
	if (game.GetEvent(24) == false) {

		MiniTaurChance(user);

		if (user.GetCurrHP() <= 0) { //checks if player died and if a game over screen should appear
			menuChoice = 100;
			navigation = true;
		}
	}

	cout << "To the south there is a path." << endl;
	cout << endl;

	//creates the room instance for the player to interact with the room.
	while (navigation == false) {

		cout << "Enter Command: ";
		getline(cin, input);
		cout << input << endl;

		//inspect the room
		if (input == "look room") {
			cout << "You come to a dead end. The walls are lined with bones and caskets." << endl;
			cout << endl;
			cout << "To the south there is a path." << endl;
			cout << endl;
		}

		else if (input == "look bones") {
			cout << "For some reason the bones looked tortured and as though they're calling out for help. You don't " << endl;
			cout <<	"want to end up like them." << endl;
		}

		//inspect the caskets
		else if (input == "look casket") {
			cout << "Each casket is made out of rotting wood and has multiple iron chains wrapped around it. We're these " << endl;
			cout <<	"poor souls buried alive?" << endl;
		}

		//directional
		//south
		//inspect southern passageway
		else if ((input == "look s") || (input == "look south")) {
			cout << "You look south and see only walls lined with bones extending far past the light of your torch." << endl;
		}

		//walk south
		else if ((input == "walk s") || (input == "walk south")) {
			cout << "You walk south." << endl;
			menuChoice = 27;//room 15
			navigation = true;
		}

		//calls help menu
		else if (input == "help") {
			menuChoice = 5;
			navigation = true;
		}

		//call the character menu
		else if (input == "character") {
			menuChoice = 90;
			navigation = true;
		}

		//for incorrect input.
		else {
			cout << "You can't do that. " << endl;
		}
		cout << endl;
	}
cout << "*************************************************************************************************" << endl;
cout << endl;
return menuChoice;
}

//maze room 17
int roomMaze17(int menuChoice, roomEvents& game, playerCharacter& user) {
	bool navigation = false; //boolean that will hold the room for the player, once it's true it will switch to a different room
	string input; //string to hold the users command

	user.PrintAdventurer(); //displays adventurer stats at the start of the room
	cout << endl;

	cout << "You come to an intersection. The walls are lined with bones and caskets." << endl;
	cout << endl;

	//checks if you encounter the Mini-Taur roaming the halls of the maze
	if (game.GetEvent(24) == false) {

		MiniTaurChance(user);

		if (user.GetCurrHP() <= 0) { //checks if player died and if a game over screen should appear
			menuChoice = 100;
			navigation = true;
		}
	}

	cout << "To the north there is a path." << endl;
	cout << "To the west there is a path." << endl;
	cout << endl;

	//creates the room instance for the player to interact with the room.
	while (navigation == false) {

		cout << "Enter Command: ";
		getline(cin, input);
		cout << input << endl;

		//inspect the room
		if (input == "look room") {
			cout << "You come to an intersection. The walls are lined with bones and caskets." << endl;
			cout << endl;
			cout << "To the north there is a path." << endl;
			cout << "To the west there is a path." << endl;
			cout << endl;
		}

		else if (input == "look bones") {
			cout << "For some reason the bones looked tortured and as though they're calling out for help. You don't " << endl;
			cout <<	"want to end up like them." << endl;
		}

		//inspect the caskets
		else if (input == "look casket") {
			cout << "Each casket is made out of rotting wood and has multiple iron chains wrapped around it. We're these " << endl;
			cout <<	"poor souls buried alive?" << endl;
		}

		//directional
		//north
		//inspect northern passageway
		else if ((input == "look n") || (input == "look north")) {
			cout << "You look north and see only walls lined with bones extending far past the light of your torch." << endl;
		}

		//walk north
		else if ((input == "walk n") || (input == "walk north")) {
			cout << "You walk north" << endl;
			menuChoice = 26;//room 14
			navigation = true;
		}

		//west
		//inspect western passageway
		else if ((input == "look w") || (input == "look west")) {
			cout << "You look west and see only walls lined with bones extending far past the light of your torch." << endl;
		}

		//walk west
		else if ((input == "walk w") || (input == "walk west")) {
			cout << "You walk west." << endl;
			menuChoice = 30;//room 18
			navigation = true;
		}

		//calls help menu
		else if (input == "help") {
			menuChoice = 5;
			navigation = true;
		}

		//call the character menu
		else if (input == "character") {
			menuChoice = 90;
			navigation = true;
		}

		//for incorrect input.
		else {
			cout << "You can't do that. " << endl;
		}
		cout << endl;
	}
cout << "*************************************************************************************************" << endl;
cout << endl;
return menuChoice;
}

//maze room 18
int roomMaze18(int menuChoice, roomEvents& game, playerCharacter& user) {
	bool navigation = false; //boolean that will hold the room for the player, once it's true it will switch to a different room
	string input; //string to hold the users command

	user.PrintAdventurer(); //displays adventurer stats at the start of the room
	cout << endl;

	cout << "You come to a dead end. The walls are lined with bones and caskets." << endl;
	cout << endl;

	//checks if you encounter the Mini-Taur roaming the halls of the maze
	if (game.GetEvent(24) == false) {

		MiniTaurChance(user);

		if (user.GetCurrHP() <= 0) { //checks if player died and if a game over screen should appear
			menuChoice = 100;
			navigation = true;
		}
	}

	cout << "To the east there is a path." << endl;
	cout << endl;

	//creates the room instance for the player to interact with the room.
	while (navigation == false) {

		cout << "Enter Command: ";
		getline(cin, input);
		cout << input << endl;

		//inspect the room
		if (input == "look room") {

		}

		else if (input == "look bones") {
			cout << "For some reason the bones looked tortured and as though they're calling out for help. You don't " << endl;
			cout <<	"want to end up like them." << endl;
		}

		//inspect the caskets
		else if (input == "look casket") {
			cout << "Each casket is made out of rotting wood and has multiple iron chains wrapped around it. We're these " << endl;
			cout <<	"poor souls buried alive?" << endl;
		}

		//directional
		//east
		//inspect eastern passageway
		else if ((input == "look e") || (input == "look east")) {
			cout << "You look east and see only walls lined with bones extending far past the light of your torch." << endl;
		}

		//walk east
		else if ((input == "walk e") || (input == "walk east")) {
			cout << "You walk east." << endl;
			menuChoice = 29;//room 17
			navigation = true;
		}

		//calls help menu
		else if (input == "help") {
			menuChoice = 5;
			navigation = true;
		}

		//call the character menu
		else if (input == "character") {
			menuChoice = 90;
			navigation = true;
		}

		//for incorrect input.
		else {
			cout << "You can't do that. " << endl;
		}
		cout << endl;
	}
cout << "*************************************************************************************************" << endl;
cout << endl;
return menuChoice;
}

#endif /* EASTERNMAZE_H_ */
