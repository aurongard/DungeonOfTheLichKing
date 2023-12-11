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
using namespace std;

#include "DungeonCrawl.h" //header for the variables for the character and event classes
#include "CentralRooms.h" //header for the central dungeon rooms
#include "EasternMaze.h" //header for the eastern maze dungeon rooms
#include "WesternDungeonRooms.h" //header for the western dungeon rooms
#include "DungeonNPCs.h" //header for the NPCs.
#include "CharacterMenu.h" //header for the player menus

//********************************************
//playerCharacter class mutators and accessors
//********************************************
//default contructor
playerCharacter::playerCharacter() {
	charName = "Adventurer";
	currHP = 10;
	maxHP = 10;
	currRoom = 0;
	countdown = 15;
}
//resets player object to default settings for returning to main menu
void playerCharacter::SetDefaults() {
	charName = "Adventurer";
	currHP = 10;
	maxHP = 10;
	currRoom = 0;
	countdown = 15;
}
//sets adventurer name
void playerCharacter::SetName(string userName) {
	charName = userName;
}
//sets current hp
void playerCharacter::SetCurrHP(int currHitPoints) {
	currHP = currHitPoints;
}
//sets max hp
void playerCharacter::SetMaxHP(int maxHitPoints) {
	maxHP = maxHitPoints;
}
//tracks current room
void playerCharacter::SetCurrentRoom(int currentRoom) {
	currRoom = currentRoom;
}
//sets countdown number for the end
void playerCharacter::SetCountdown(int cDown) {
	countdown = cDown;
}
//calls adventurer name
string playerCharacter::GetName() const {
	return charName;
}
//calls current hp
int playerCharacter::GetCurrHP() const {
	return currHP;
}
//calls current max hp
int playerCharacter::GetMaxHP() const {
	return maxHP;
}
//calls the current room
int playerCharacter::GetCurrentRoom() const {
	return currRoom;
}
//calls the countdown timer
int playerCharacter::GetCountdown() const {
	return countdown;
}
//outputs the current player stats
void playerCharacter::PrintAdventurer() const {
	string room = "null"; //will hold the room name after the room number is fed into the switch below

	cout << "*** Name: " << charName;
	cout << " * HP: " << currHP << "/" << maxHP;
	//switch to associate room names to the currRoom number.
	switch (currRoom) {

	case 7: //case for roomEntrance
		room = "Entrance";
		break;
	case 8://case for roomHall1
		room = "Western Intersection";
		break;
	case 9: //case for strange door
		room = "Strange Door";
		break;
	case 10: //case for Ritual Pools
		room = "Ritual Pools";
		break;
	case 11: //case for Old Chapel
		room = "Old Chapel";
		break;
	case 12: //case for Lava Room
		room = "Lava Room";
		break;
	case 13:
	case 14:
	case 15:
	case 16:
	case 17:
	case 18:
	case 19:
	case 20:
	case 21:
	case 22:
	case 23:
	case 24:
	case 25:
	case 26:
	case 27:
	case 28:
	case 29:
	case 30: //case for The Maze. Cover rooms 13-30.
		room = "The Maze";
		break;
	case 31: //The final room
		room = "Vhile Bonsh Tomb";
		break;
	}

	cout << " * Current Room: " << room << " ***"<< endl;
}
//***************************************
//roomEvents class mutators and accessors
//***************************************
//sets all booleans to false by default
roomEvents::roomEvents() {
	//items
	torch = true;
	skullKey = false;
	fireKey = false;
	redCloth = false;
	emptyVial = false;
	waterVial = false;
	heatGloves = false;
	silverKey = false;
	ShepardsStaff = false;

	//events
	roomOneIntro = false;
	roomOneSkel = false;
	westNorthDoor01 = false;
	westNorthDoor02 = false;
	statue = false;
	stoneVial = false;
	moltenEgg = false;
	moltenKey = false;
	entranceKey = false;
	gargoyle = false;
	gargoyleDoor = false;
	shroudIntro = false;
	shroudKey = false;
	FireKeyDoor = false;
	SkullKeyDoor = false;
	EntranceKeyHole = false;
	MiniTaur = false;
	SkullKeyTaken = false;
	StaffTaken = false;
	phylacterySmash  = false;
	phylacteryAbsorb  = false;
	entranceDoor = false;

}

//sets object back to defaults. Used for returning to main menu
void roomEvents::SetDefaults(){
	//items
	torch = true;
	skullKey = false;
	fireKey = false;
	redCloth = false;
	emptyVial = false;
	waterVial = false;
	heatGloves = false;
	silverKey = false;
	ShepardsStaff = false;

	//events
	roomOneIntro = false;
	roomOneSkel = false;
	westNorthDoor01 = false;
	westNorthDoor02 = false;
	statue = false;
	stoneVial = false;
	moltenEgg = false;
	moltenKey = false;
	entranceKey = false;
	gargoyle = false;
	gargoyleDoor = false;
	shroudIntro = false;
	shroudKey = false;
	FireKeyDoor = false;
	SkullKeyDoor = false;
	EntranceKeyHole = false;
	MiniTaur = false;
	SkullKeyTaken = false;
	StaffTaken = false;
	phylacterySmash  = false;
	phylacteryAbsorb = false;
	entranceDoor = false;
}

//will be used to mark specific booleans as true or false
void roomEvents::EventTrigger(int eventNumber, bool boolStatus){
	switch(eventNumber) {

	//events
	case 0://will prevent entrance intro from repeating every time player enters room.
		roomOneIntro = boolStatus;
		break;
	case 1: //will only allow the intro text to display once from the Strange Door.
		westNorthDoor01 = boolStatus;
		break;
	case 2: //Will unlock the Strange Door.
		westNorthDoor02 = boolStatus;
		break;
	case 3: //removes red cloak from skeleton
		roomOneSkel = boolStatus;
		break;
	case 4: //will cover the statues eyes and release the vial with the key in it
		statue = boolStatus;
		break;
	case 5: //checks if vial is turned to stone
		stoneVial = boolStatus;
		break;
	case 6: //checks if egg has been cooled or not
		moltenEgg = boolStatus;
		break;
	case 7: //checks if the the fire key has been taken or not
		moltenKey = boolStatus;
		break;

	//items
	case 8: //shows the torch in your inventory
		torch = boolStatus;
		break;
	case 9: //adds/removes skull key to inventory
		skullKey = boolStatus;
		break;
	case 10: //adds/removes fire key to inventory
		fireKey = boolStatus;
		break;
	case 11: //adds/removes the red cloth
		redCloth = boolStatus;
		break;
	case 12: //adds/removes the empty vial
		emptyVial = boolStatus;
		break;
	case 13: //adds/removes the vial of ice water
		waterVial = boolStatus;
		break;
	case 14: //adds/removes the heat gloves
		heatGloves = boolStatus;
		break;
	case 15: //adds/removes lock box key from specter
		silverKey = boolStatus;
		break;
	case 16: //add/removes entrance key
		entranceKey = boolStatus;
		break;
	case 17: //shepards staff, stops the Mini-taur from attacking you
		ShepardsStaff = boolStatus;
		break;

	//more events
	case 18: //once the strange door is open
		gargoyleDoor = boolStatus;
		break;
	case 19: //the first time you speak to the shrouded figure
		shroudIntro = boolStatus;
		break;
	case 20: //shrouded figure asking for the key
		shroudKey = boolStatus;
		break;
	case 21: //if fire key has been used on main door
		FireKeyDoor = boolStatus;
		break;
	case 22: //if skull key has been used on main door
		SkullKeyDoor = boolStatus;
		break;
	case 23: //if entrance key has been removed from the hole in maze room 06
		EntranceKeyHole = boolStatus;
		break;
	case 24://if the Mini-Taur will randomly attack you.
		MiniTaur = boolStatus;
		break;
	case 25: //once you have taken the skull key
		SkullKeyTaken = boolStatus;
		break;
	case 26: //once you have taken the shepards staff
		StaffTaken = boolStatus;
		break;
	case 27: //event for breaking the phylactery
		phylacterySmash = boolStatus;
		break;
	case 28://if you insult the gargoyle it will stop speaking
		gargoyle = boolStatus;
		break;
	case 29://if the entrance has been unlocked or not
		entranceDoor = boolStatus;
		break;
	case 30:
		phylacteryAbsorb = boolStatus;
		break;
	}
}

//will call a specific boolean and return if it's true or false
bool roomEvents::GetEvent(int eventNumber) {
	bool event = false;

	switch(eventNumber) {

	case 0://returns the status of the intro text for the entrance room.
		event = roomOneIntro;
		break;
	case 1: //returns status of strange door intro
		event = westNorthDoor01;
		break;
	case 2://returns status of strange door open or close
		event = westNorthDoor02;
		break;
	case 3://returns status of red cloak
		event = roomOneSkel;
		break;
	case 4://returns status of statues gaze being covered
		event = statue;
		break;
	case 5: //returns status of vial and if it's stone or not
		event = stoneVial;
		break;
	case 6://returns status if egg has been cooled or not
		event = moltenEgg;
		break;
	case 7: //returns if the key has been taken or not.
		event = moltenKey;
		break;

	//items
	case 8: //shows the torch in your inventory
		event = torch;
		break;
	case 9: //adds/removes skull key to inventory
		event = skullKey;
		break;
	case 10: //adds/removes fire key to inventory
		event = fireKey;
		break;
	case 11: //adds/removes the red cloth
		event = redCloth;
		break;
	case 12: //adds/removes the empty vial
		event = emptyVial;
		break;
	case 13: //adds/removes the vial of ice water
		event = waterVial;
		break;
	case 14: //adds/removes the heat gloves
		event = heatGloves;
		break;
	case 15: //adds/removes lock box key from specter
		event = silverKey;
		break;
	case 16: //adds/removes entrance key
		event = entranceKey;
		break;
	case 17: //shepards staff, stops the Mini-taur from attacking you
		event = ShepardsStaff;
		break;

	//more events
	case 18: //once the strange door is open
		event = gargoyleDoor;
		break;
	case 19: //the first time you speak to the shrouded figure
		event = shroudIntro;
		break;
	case 20: //shrouded figure asking for the key
		event = shroudKey;
		break;
	case 21: //if fire key has been used on the main door
		event = FireKeyDoor;
		break;
	case 22: //if the skull key has been used on the main door
		event = SkullKeyDoor;
		break;
	case 23: //if entrance key has been removed from the hole in maze room 06
		event = EntranceKeyHole;
		break;
	case 24: //if the Mini-Taur will randomly attack you.
		event = MiniTaur;
		break;
	case 25: //once you have taken the skull key
		event = SkullKeyTaken;
		break;
	case 26: //once you have taken the shepards staff
		event = StaffTaken;
		break;
	case 27: //event for breaking the phylactery
		event = phylacterySmash;
		break;
	case 28: //controls wheter the gargoyle is angry at you or not
		event = gargoyle;
		break;
	case 29: //if the entrance has been unlocked or not
		event = entranceDoor;
		break;
	case 30:
		event = phylacteryAbsorb;
		break;
	}
	return event;
}

string roomEvents::GetItem(int eventNumber) {
	string item;

	switch(eventNumber) {

		case 8: //Torch
			item = "Torch";
			break;
		case 9: //skull key to inventory
			item = "Skull Key";
			break;
		case 10: //fire key to inventory
			item = "Fire Key";
			break;
		case 11: //the red cloth
			item = "Red Cloak";
			break;
		case 12: //empty vial
			item = "Glass Vial - (empty)";
			break;
		case 13: //vial of ice water
			item = "Glass Vial - (full of Ice Cold Water)";
			break;
		case 14: //the heat gloves
			item = "Heat Gloves";
			break;
		case 15: //lock box key
			item = "Silver Key";
			break;
		case 16: //entrance key
			item = "Iron Key";
			break;
		case 17: //shepards staff
			item = "Shepards Staff";
			break;
	}

	return item;
}

int main () {
	playerCharacter user; //initializes the character object
	roomEvents game; //initializes the defaults for the room events

	bool gameStatus = true; //while gameStatus is true, the program runs.
	int menuChoice = 0; //this int is passed through the functions to dictate the next screen.
	string userName; //triggers the adventurers name

	//Once it is changed to false the loop will end and exit the program.
	while (gameStatus == true) {

		//countdown for the building to collapse, but does not trigger for menus
		if ((menuChoice > 6) && (menuChoice < 32)) {
			//trigger for the buildings collapse and countdown
			if (game.GetEvent(27) == true) {
				int countdown = user.GetCountdown();
				--countdown;

				if (countdown > 0) {
					cout << "The structure around continues to shake. Dust and debris falls from the ceiling and cracks" << endl;
					cout << "are forming on the walls. You need to hurry up and escape!" << endl;
					cout << endl;
				}
				else {
					menuChoice = 100; //triggers the ending if the player doesn't make it out on time
				}
				user.SetCountdown(countdown); //updates user countdown
			}
		}

		//runs a switch with the while loop to move the user through rooms.
		switch (menuChoice) {

			//calls the start screen and will return a number based on user input.
			case 0:
				menuChoice = startScreen(menuChoice);
				break;
			//calls intro to start a new game.
			case 1:
				menuChoice = newGameIntro(menuChoice);
				break;
			//will load a new game
			case 2:
				menuChoice = LoadGame(menuChoice, game, user);
				break;
			//will call instructions for how to play from main menu.
			case 3:
				menuChoice = instructionsMM(menuChoice);
				break;
			//exits the program.
			case 4:
				gameStatus = false;
				break;
			//calls the help menu
			case 5:
				menuChoice = HelpMenu(menuChoice, game, user);
				break;
			//will create a new character.
			case 6:
				userName = createCharacter(); //calls method for user to name character
				user.SetName(userName); //associates name returned by createCharacter to the character object

				menuChoice = 7; //sets the switch to move to room 1 of the dungeon
				break;
			//Entrance to dungeon
			case 7:
				user.SetCurrentRoom(7); //sets the room to Entrance
				menuChoice = roomEntrance(menuChoice, game, user); //Calls the dungeon entrance
				break;

			//western halls
			//western intersection
			case 8:
				user.SetCurrentRoom(8); //sets the room to Western Intersection
				menuChoice = roomHall1(menuChoice, game, user); //calls the western intersection room
				break;
			//strange door
			case 9:
				user.SetCurrentRoom(9);//sets the room to Strange Door
				menuChoice = roomWestNorthDoor(menuChoice, game, user);//calls the strange door
				break;
			//ritual pools
			case 10:
				user.SetCurrentRoom(10); //sets room to Ritual Pools
				menuChoice = roomRitualPools(menuChoice, game, user); //calls the ritual pools room
				break;
			//old chapel
			case 11:
				user.SetCurrentRoom(11); //sets room to Old Chapel
				menuChoice = roomOldChapel(menuChoice, game, user); //calls the old chapel room
				break;
			//lava room.
			case 12:
				user.SetCurrentRoom(12); //sets room to Lava Room
				menuChoice = roomLavaRoom(menuChoice, game, user); //calls the lava room with the fire egg
				break;

			//eastern maze
			//Maze Room 01
			case 13:
				user.SetCurrentRoom(13);
				menuChoice = roomMaze01(menuChoice, game, user); //calls the entrance to the maze
				break;
			//Maze Room 02
			case 14:
				user.SetCurrentRoom(14);
				menuChoice = roomMaze02(menuChoice, game, user);
				break;
			//Maze Room 03
			case 15:
				user.SetCurrentRoom(15);
				menuChoice = roomMaze03(menuChoice, game, user);
				break;
			//Maze Room 04
			case 16:
				user.SetCurrentRoom(16);
				menuChoice = roomMaze04(menuChoice, game, user);
				break;
			//Maze Room 05
			case 17:
				user.SetCurrentRoom(17);
				menuChoice = roomMaze05(menuChoice, game, user);
				break;
			//Maze Room 06
			case 18:
				user.SetCurrentRoom(18);
				menuChoice = roomMaze06(menuChoice, game, user);
				break;
			//Maze Room 07
			case 19:
				user.SetCurrentRoom(19);
				menuChoice = roomMaze07(menuChoice, game, user);
				break;
			//Maze Room 08
			case 20:
				user.SetCurrentRoom(20);
				menuChoice = roomMaze08(menuChoice, game, user);
				break;
			//Maze Room 09
			case 21:
				user.SetCurrentRoom(21);
				menuChoice = roomMaze09(menuChoice, game, user);
				break;
			//Maze Room 10
			case 22:
				user.SetCurrentRoom(22);
				menuChoice = roomMaze10(menuChoice, game, user);
				break;
			//Maze Room 11
			case 23:
				user.SetCurrentRoom(23);
				menuChoice = roomMaze11(menuChoice, game, user);
				break;
			//Maze Room 12
			case 24:
				user.SetCurrentRoom(24);
				menuChoice = roomMaze12(menuChoice, game, user);
				break;
			//Maze Room 13
			case 25:
				user.SetCurrentRoom(25);
				menuChoice = roomMaze13(menuChoice, game, user);
				break;
			//Maze Room 14
			case 26:
				user.SetCurrentRoom(26);
				menuChoice = roomMaze14(menuChoice, game, user);
				break;
			//Maze Room 15
			case 27:
				user.SetCurrentRoom(27);
				menuChoice = roomMaze15(menuChoice, game, user);
				break;
			//Maze Room 16
			case 28:
				user.SetCurrentRoom(28);
				menuChoice = roomMaze16(menuChoice, game, user);
				break;
			//Maze Room 17
			case 29:
				user.SetCurrentRoom(29);
				menuChoice = roomMaze17(menuChoice, game, user);
				break;
			//Maze Room 18
			case 30:
				user.SetCurrentRoom(30);
				menuChoice = roomMaze18(menuChoice, game, user);
				break;
			//Final Room for the Phylactery
			case 31:
				user.SetCurrentRoom(31);
				menuChoice = roomFinal(menuChoice, game, user);
				break;

			//conversations
			//talk to Gargoyle
			case 50:
				menuChoice = talkGargoyle(menuChoice, game, user);
				break;
			//talks to the shrouded figure in the old chapel
			case 51:
				menuChoice = talkShroud(menuChoice, game, user);
				break;

			//player menus
			//main player menu
			case 90:
				menuChoice = playerMenu(menuChoice, game, user);
				break;

			//game over screen
			case 100:
				menuChoice = gameOver(menuChoice, game, user); //moves to the game over screen
				break;
		}
	}


	return 0;
}
