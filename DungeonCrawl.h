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

#ifndef DUNGEONCRAWL_H_
#define DUNGEONCRAWL_H_

//playerCharacter variables
class playerCharacter {

public:
	//mutators
	playerCharacter();//default constructor
	void SetDefaults(); //sets object back to defaults. Used for returning to main menu
	void SetName(string userName); //sets adventurer name
	void SetCurrHP(int currHitPoints); //sets current hp
	void SetMaxHP(int maxHitPoints); //sets max hp
	void SetCurrentRoom(int currentRoom); //tracks current room
	void SetCountdown(int cdown); //sets countdown for the end

	//accessors
	string GetName() const; //calls adventurer name
	int GetCurrHP() const; //calls current hp
	int GetMaxHP() const; //calls current max hp
	int GetCurrentRoom() const; //calls the current room
	int GetCountdown() const; //calls the countdown timer
	void PrintAdventurer() const; //outputs the current player stats


private:
	string charName; //holds adventurer name
	int currHP; //keeps track of current hp
	int maxHP; //current max hp
	int currRoom; //marks current room
	int countdown; // countdown until the structure collapses
};

//Room Events variables
class roomEvents {

public:
	roomEvents(); //default constructor
	void EventTrigger(int eventNumber, bool boolStatus); //will be used to mark specific booleans as true or false
	bool GetEvent(int eventNumber); //will call a specific boolean and return if it's true or false
	string GetItem(int eventNumber); //will call a specific item to be printed for player inventory
	void SetDefaults(); //sets object back to defaults. Used for returning to main menu

private:
	//items   //boolean description - case number
	bool torch; // just a descriptor for your torch - 8
	bool skullKey; //skull key item - 9
	bool fireKey; //fire key item - 10
	bool redCloth; //cloth to cover the statues eyes -11
	bool emptyVial; //empty vial - 12
	bool waterVial; //vial of icey water - 13
	bool heatGloves; //heat resitant gloves that let the player open the strange door - 14
	bool silverKey; //key to give to specter - 15
	bool entranceKey; //key to open dungeon entrance to espace - 16
	bool ShepardsStaff; //shepards staff, stops the Mini-taur from attacking you - 17

	//events
	bool roomOneIntro; //displays intro in room 1 if new game. - 0
	bool roomOneSkel; //changes text about skeleton - 1
	bool westNorthDoor01; //talking door intro - 2
	bool westNorthDoor02; //talking door locked or unlocked - 3
	bool statue; //cover statues gaze - 4
	bool stoneVial; //if vial is stone or note - 5
	bool moltenEgg; //checks if egg has been cooled or not - 6
	bool moltenKey; //checks if the key is still on the table - 7
	bool gargoyleDoor; //when the door is open - 18
	bool shroudIntro; //first time you speak to the shrouded figure - 19
	bool shroudKey; //shrouded figure asking for key - 20
	bool FireKeyDoor; //if firekey has been used on door - 21
	bool SkullKeyDoor; //if skullkey has been used on door - 22
	bool EntranceKeyHole; //if entrance key has been removed from the hole in maze room 06 - 23
	bool MiniTaur; //if the Mini-Taur will randomly attack you. - 24
	bool SkullKeyTaken; //once you have taken the skull key - 25
	bool StaffTaken; //once you have taken the shepards staff - 26
	bool phylacterySmash; //event for breaking the phylactery - 27
	bool gargoyle; //decides whether or not the gargoyle will speak to you or not. - 28
	bool entranceDoor; //if the entrance has been unlocked or not - 29
	bool phylacteryAbsorb; //if the player absorbes the phylactery - 30
};

//**********************
//Start screen/Main Menu
//**********************
int startScreen(int menuChoice) {
	bool startMenu = false;
	string choice;

	cout << "*************************************************************************************************" << endl;
	cout << "*Dungeon of the Lich King                                                                       *" << endl;
	cout << "*************************************************************************************************" << endl;
	cout << "*[n] - New Game                                                                                 *" << endl;
	cout << "*[c] - Continue                                                                                 *" << endl;
	cout << "*[i] - How to Play                                                                              *" << endl;
	cout << "*[q] - Quit Game                                                                                *" << endl;
	cout << "*************************************************************************************************" << endl;
	cout << endl;



	//requests user input and takes user choice to move to correct menu choice.
	while (startMenu == false) {
		cout << "Please enter your selection: ";
		getline(cin, choice);

		//choice for new game
		if (choice == "n") {
			menuChoice = 1;
			startMenu = true;
		}
		//choice for continuing or loading a previous save
		else if (choice == "c") {
			cout << "Continue!" << endl;
			menuChoice = 2;
			startMenu = true;
		}
		//choice to show instructions
		else if (choice == "i") {
			cout << "How to play!" << endl;
			menuChoice = 3;
			startMenu = true;
		}
		//choice to exit the game
		else if (choice == "q") {
			cout << "Thank you for playing." << endl;
			cout << "Exiting game..." << endl;
			menuChoice = 4;
			startMenu = true;
		}
		//a catch if anything else is entered that isn't an option
		else {
			cout << "Invalid entry, please enter your selection: " << endl;
		}
	}
	return menuChoice;
}

//****************
//load game method
//****************

int LoadGame(int menuChoice, roomEvents& game, playerCharacter& user) {
	ifstream inFS;
	std::ifstream file("dungeon.csv");
	string name = "Hero";
	int currHP = 10;
	int maxHP = 10;
	int currRoom = 0;
	int countdown = 15;
	bool event = false;
	unsigned int l;
	int eventNum = 0;

	inFS.open("dungeon.csv");

	if (!inFS.is_open()) {
		cout << "Could not open file dungeon.csv" << endl;
		cout << "There is no save data present." << endl;
		cout << endl;
		menuChoice = 0;
	}

	else {
		while (!inFS.eof()) {
			//loads player name
			inFS >> name;
			user.SetName(name);

			//loads current hp
			inFS >> currHP;
			user.SetCurrHP(currHP);

			//loads max hp
			inFS >> maxHP;
			user.SetMaxHP(maxHP);

			//loads current room
			inFS >> currRoom;
			user.SetCurrentRoom(currRoom);

			//sets countdown timer
			inFS >> countdown;
			user.SetCountdown(countdown);

			for (l = 0; l <= 30; ++l) {
				inFS >> event;
				game.EventTrigger(eventNum, event);
				++eventNum;
			}
		}
		cout << "**Game Loaded!**" << endl;

		//testing parameters for loading the file correctly
		/*user.PrintAdventurer();

		cout << "Countdown: " << user.GetCountdown() << endl;

		for(l = 0; l <= 29; ++l) {
			cout << game.GetEvent(l) << endl;
		}*/

		cout << endl;
		menuChoice = user.GetCurrentRoom(); //sets the room to the last room the player was in
	}

	inFS.close();
	return menuChoice;
}

//***********************************************
// Main Menu Instructions on how to play the game
//***********************************************
int instructionsMM(int menuChoice) {
	string moveFwd = "a";

	cout << "*************************************************************************************************" << endl;
	cout << "*How to play:                                                                                   *" << endl;
	cout << "*************************************************************************************************" << endl;
	cout << "All commands should be in lowercase. Please do not capitalize any of your lettering." <<endl;
	cout << endl;
	cout << "List of available commands -- Description of the command " << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	cout << "'character'                -- Opens the character menu." << endl;
	cout << "'help'                     -- Shows list of available commands." << endl;
	cout << "'walk [direction]'         -- Allows the player to move in the desired direction" << endl;
	cout << "                           ** Example: 'walk north' or 'walk n' to walk north." << endl;
	cout << "'look [object]'            -- Calls an object or room description." << endl;
	cout << "                           ** Example: 'look room' will call the room description." << endl;
	cout << "                           ** Example: 'look skeleton' will inspect the skeleton." << endl;
	cout << "'interact [object]'        -- Allows player to take items, talk to NPCs, and interact with objects." << endl;
	cout << "                           ** Example: 'interact gargoyle' will speak to the gargoyle." << endl;
	cout << "                           ** Example: 'interact cloak' will add the cloak to inventory." << endl;
	cout << "'use [object]'             -- Use items from the player's inventory." << endl;
	cout << "                           ** Example: 'use skull key' will use the key on the door." << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	cout << endl;

	cout << "Type [r] and press enter to return to main menu." << endl;

	while (moveFwd != "r") { //loop breaks once the char 'r' is entered to move back to main men.
		getline(cin, moveFwd);
		if (moveFwd != "r") { //A catch to inform a user that they have entered the wrong command.
			cout << "Invalid Input. Type [r] and press enter to return to main menu." << endl;
		}
	}
	cout << endl;

	return menuChoice = 0; //returns to main menu
}

//*********
//help menu
//*********

int HelpMenu(int menuChoice, roomEvents& game, playerCharacter& user) {

	cout << "Help: all commands should be in lowercase. Please do not capitalize any of your lettering." <<endl;
	cout << endl;
	cout << "List of available commands -- Description of the command " << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	cout << "'character'                -- Opens the character menu." << endl;
	cout << "'help'                     -- Shows list of available commands." << endl;
	cout << "'walk [direction]'         -- Allows the player to move in the desired direction" << endl;
	cout << "                           ** Example: 'walk north' or 'walk n' to walk north." << endl;
	cout << "'look [object]'            -- Calls an object or room description." << endl;
	cout << "                           ** Example: 'look room' will call the room description." << endl;
	cout << "                           ** Example: 'look skeleton' will inspect the skeleton." << endl;
	cout << "'interact [object]'        -- Allows player to take items, talk to NPCs, and interact with objects." << endl;
	cout << "                           ** Example: 'interact gargoyle' will speak to the gargoyle." << endl;
	cout << "                           ** Example: 'interact cloak' will add the cloak to inventory." << endl;
	cout << "'use [object]'             -- Use items from the player's inventory." << endl;
	cout << "                           ** Example: 'use skull key' will use the key on the door." << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	cout << endl;

	return menuChoice = user.GetCurrentRoom();
}
//****************
//Game over screen
//****************

int gameOver(int menuChoice, roomEvents& game, playerCharacter& user) {

	//ending if the character dies before completing their mission
	if ((game.GetEvent(27) == false) && (game.GetEvent(30) == false)) {
		cout << "*************************************************************************************************" << endl;
		cout << "*                                         GAME OVER                                             *" << endl;
		cout << "*************************************************************************************************" << endl;
		cout << endl;
		cout << "You have fallen to one of Vhile Bonsh traps and have failed your mission. Yet you rise once more" << endl;
		cout << "an undead servant of the Lich King, a new protector of this wretched place." << endl;
		cout << endl;
		cout << "*************************************************************************************************" << endl;
		cout << endl;
	}

	//ending if the player cannot escape before the structure collapses.
	else if (game.GetEvent(27) == true && user.GetCountdown() == 0) {
		cout << "*************************************************************************************************" << endl;
		cout << "*                                         GAME OVER                                             *" << endl;
		cout << "*************************************************************************************************" << endl;
		cout << endl;
		cout << "You have destroyed Vhile Bonsh phylactery, and broken his hold upon the world." << endl;
		cout << endl;
		cout << "However as you made your attempt to escape his catacombs, the structure collapsed on you once the" << endl;
		cout << "magic that held it together had been destroyed." << endl;
		cout << endl;
		cout << "You are a hero. You saved the world from the evil that gripped at it. However, you will never know" << endl;
		cout << "this new peaceful world. But rest easy brave " << user.GetName() << ", for they will sing songs" << endl;
		cout << "and tell tales of your heroism until the end of time." << endl;
		cout << endl;
		cout << "*************************************************************************************************" << endl;
		cout << endl;
	}

	//ending if the player escapes successfully after destroying the phylactery
	else if (game.GetEvent(27) == true && user.GetCountdown() > 0) {
		cout << "*************************************************************************************************" << endl;
		cout << "*                                         GAME OVER                                             *" << endl;
		cout << "*************************************************************************************************" << endl;
		cout << endl;
		cout << "You have destroyed Vhile Bonsh phylactery, and broken his hold upon the world." << endl;
		cout << endl;
		cout << "Despite all odds, you solved the mysteries of the catacombs and defeated the Lich King. You" << endl;
		cout << "overcame strange puzzles, monsters, and all temptations of power. In the end you even survived the" << endl;
		cout << "collapsing tomb." << endl;
		cout << endl;
		cout << "You are truly a hero. You saved the world from the evil that gripped it fiercly and jealously. The" << endl;
		cout << "world you now enter into will need to rebuild." << endl;
		cout << endl;
		cout << "But it is your time to rest easy brave " << user.GetName() << ". Your job is done now, and " << endl;
		cout << "they will sing songs and tell tales of your heroism until the end of time." << endl;
		cout << endl;
		cout << "*************************************************************************************************" << endl;
		cout << endl;
	}

	//ending if the player decides to absorb the power within the phylactery
	else if (game.GetEvent(30) == true) {
		cout << "*************************************************************************************************" << endl;
		cout << "*                                         GAME OVER                                             *" << endl;
		cout << "*************************************************************************************************" << endl;
		cout << "You accept the eyes offer silently. Tentacles explode from behind the eye and tear out your own" << endl;
		cout << "and it pulls itself into the empty socket. The world around you becomes a blur as it spins. " << endl;
		cout << endl;
		cout << "Before blacking out, you see Vhile Bonsh rushing into the room. You hold out your hand and " << endl;
		cout << "tentacles made of a viscous black liquid shoot out from your hand." << endl;
		cout << endl;
		cout << "The world goes black for a second and when you come to you see the broken bodies of your foes" << endl;
		cout << "and you standing over the former Lich King. You are reaching for his crown." << endl;
		cout << endl;
		cout << "The colors blur and you are returned to darkness once more." << endl;
		cout << endl;
		cout << "You awaken unable to speak or move. You see your body placing you on a pedestal in a strange room." << endl;
		cout << endl;
		cout << "Energy begins coursing through you and the thoughts and desires of so many voices flood into your" << endl;
		cout << "mind. You find it hard to focus as you feel their raw power being stripped away from their very" << endl;
		cout << "souls. All of it being funneled away from you towards your body." << endl;
		cout << endl;
		cout << "It is now that you realize that you didn't absorb the power of the skull, you traded places with" << endl;
		cout << "the last victim. You are now nothing more than a conduit for whoever is in your body now. You watch" << endl;
		cout << "in horror as your former body walks away and closes the door behind them, bathing you in darkness." << endl;
		cout << endl;
		cout << "*************************************************************************************************" << endl;
		cout << endl;
	}
	return menuChoice = 0;
}

#endif /* DUNGEONCRAWL_H_ */
