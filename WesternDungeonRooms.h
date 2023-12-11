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

#ifndef WESTERNDUNGEONROOMS_H_
#define WESTERNDUNGEONROOMS_H_


//*************
//Dungeon Rooms
//*************

int roomHall1(int menuChoice, roomEvents& game, playerCharacter& user) {
	bool navigation = false; //boolean that will hold the room for the player, once it's true it will switch to a different room

	//string to hold the users command
	string input;

	//displays adventurer stats at the start of the room
	user.PrintAdventurer();
	cout << endl;

	cout << "You find yourself at an intersection. " << endl;
	cout << endl;
	cout << "To the north there is a hallway with a door. " << endl;
	cout << "To the east leads to back to the entrance." << endl;
	cout << "To the west there is a hallway with a dim light at the end." << endl;
	cout << "To the south there is a dark hallway." << endl;
	cout << endl;

	while (navigation == false) {
		cout << "Enter Command: ";
		getline(cin, input);
		cout << endl;

		//outputs the room description
		if ((input == "look room")) {
			cout << "You find yourself at an intersection. " << endl;
			cout <<  endl;
			cout << "To the north there is a hallway with a door. " << endl;
			cout << "To the east leads to back to the entrance." << endl;
			cout << "To the west there is a hallway with a dim light at the end." << endl;
			cout << "To the south there is a dark hallway." << endl;
		}

		//directional
		//north
		//moves to gargoyle door
		else if ((input == "walk n") || (input == "walk north")) {
			//ATTN: add check for lock switch
			cout << "You walk down the northern hallway." << endl;
			menuChoice = 9;
			navigation = true;
		}
		//looks north
		else if ((input == "look n") || (input == "look north")) {
			cout << "You see a closed door down the hallway." << endl;
			cout << endl;
			if (game.GetEvent(1) == false) { //checks if you have interacted with the gargoyle before or not
				cout << "You can hear whispers coming from the northern path." << endl;
			}
			else {
				cout << "You no longer hear the gargoyle talking to itself." << endl;
			}
		}

		//east
		//walks to the entrance.
		else if ((input == "walk e") || (input == "walk east")) {
			cout << "You walk down the eastern hall to the entrance." << endl;
			menuChoice = 7;
			navigation = true;
		}
		//looks towards the entrance
		else if ((input == "look e") || (input == "look east")) {
			cout << "You look down the hall and can faintly see the silhouettes of the pillars from the entrance." << endl;
		}

		//west
		//moves to the ritual pools
		else if ((input == "walk w") || (input == "walk west") ){
			cout << "You walk down the western hallway towards the dim light." << endl;
			menuChoice = 10;
			navigation = true;
		}
		//looks towards the ritual pool
		else if ((input == "look w") || (input == "look west") ){
			cout << "You see a faint blue light shimmering at the end of the hall." << endl;
		}

		//south
		//moves to the old chapel
		else if ((input == "walk s") || (input == "walk south")) {
			//ATTN: add check for the entrance key that the rat took
			cout << "You walk down the dark southern hallway ." << endl;
			menuChoice = 11;
			navigation = true;
		}
		//looks towards the old chapel
		else if ((input == "look s") || (input == "look south") ){
			cout << "The hallway is dark, but you can faintly make out a doorway at the end." << endl;
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

int roomWestNorthDoor(int menuChoice, roomEvents& game, playerCharacter& user) {
	bool navigation = false; //boolean that will hold the room for the player, once it's true it will switch to a different room
	int userHp = user.GetCurrHP(); //calls current hp for traps.
	string input; //string to hold the users command

	user.PrintAdventurer(); //displays adventurer stats at the start of the room
	cout << endl;

	if (game.GetEvent(2) == false ) { //first time dialogue for the gargoyle that shows only once.
		cout << "As you walk towards the door, the whispers stop. That's when you notice the a stone head of a " << endl;
		cout << "gargoyle staring at you, it's gaze following your steps towards the door." << endl;

		game.EventTrigger(2, true);
	}

	if (game.GetEvent(3) == false) { //if you haven't opened the door
		cout << "You stand before a strange wooden door with iron fittings. There's no handle and no sign of decay." << endl;
		cout << "A stone gargoyle head looks down at you from the arch above the sealed door." << endl;
		cout <<  endl;
		cout << "To the north there is a closed door. " << endl;
		cout << "To the south there is the western intersection." << endl;
		cout << endl;
	}
	else { //if you have opened the door
		cout << "You stand before an open door. Heat eminates from the open passage and stings you senses. " << endl;
		cout << "A stone gargoyle head looks down at you from the arch above the sealed door." << endl;
		cout <<  endl;
		cout << "To the north there is a passage to a room. " << endl;
		cout << "To the south there is the western intersection." << endl;
		cout << endl;
	}

	while (navigation == false) {
			cout << "Enter Command: ";
			getline(cin, input);
			cout << endl;

			//outputs the room description
			if ((input == "look room")) {
				if (game.GetEvent(3) == false) { //if you haven't opened the door
					cout << "You stand before a strange wooden door with iron fittings. There's no handle and no sign of decay." << endl;
					cout << "A stone gargoyle head looks down at you from the arch above the sealed door." << endl;
					cout <<  endl;
					cout << "To the north there is a closed door. " << endl;
					cout << "To the south there is the western intersection." << endl;
					cout << endl;
				}
				else { //if you have opened the door
					cout << "You stand before an open door. Heat eminates from the open passage and stings you senses. " << endl;
					cout << "A stone gargoyle head looks down at you from the arch above the sealed door." << endl;
					cout <<  endl;
					cout << "To the north there is a passage to a room. " << endl;
					cout << "To the south there is the western intersection." << endl;
					cout << endl;
				}
			}

			//room objects
			//inpsect door
			else if (input == "look door") {
				if (game.GetEvent(14) == false) { //if you haven't opened the door
					cout << "The door is closed. It looks to be made of a rich mahogony and held together with well crafted" << endl;
					cout << "iron fittings, however there is no handle. The door shows know signs of decay and looks very sturdy." << endl;
				}
				else {//if you have opened the door
					cout << "The door is open now." << endl;
				}
			}
			//touch the door
			else if (input == "interact door") {
				if (game.GetEvent(3) == false) { //if you haven't opened the door
					if (game.GetEvent(14) == false) {
						cout << "You attempt to touch the door, however it is hot to the touch and you burn your hand." << endl;
						cout << endl;
						cout << "[You take 2 damage]" << endl;

						userHp -= 2;

						user.SetCurrHP(userHp); //trap reduces player health by 2
						if (user.GetCurrHP() <= 0) {//checks if player died and if a game over screen should appear
							menuChoice = 100;
							navigation = true;
						}
					}
					else if (game.GetEvent(3) == false && game.GetEvent(14) == true) { //for the player to open the door
						cout << "You put on the heat gloves and push the door open without burning your hands." << endl;
						game.EventTrigger(3, true); //opens door.
						game.EventTrigger(18, true); //makes the gargoyle permanently stone
					}
				}
				else {//if you have opened the door
					cout << "The door is already open." << endl;
				}
			}

			//gargoyle
			//talk to gargoyle
			else if (input == "interact gargoyle") {
				if (game.GetEvent(18) == true) {
					cout << "Dialogue:----------------------------------------------------------------------------------------" << endl;
					cout << "The gargoyle does not acknowledge you and seems to be nothing more than a stone sculpture now." << endl;
					cout << "Perhaps you were only imagining it talking before?" << endl;
					cout << "-------------------------------------------------------------------------------------------------" << endl;
				}

				else if (game.GetEvent(28) == false) {//will only have this loop available unless you "anger" the gargoyle. Then it closes off.
					menuChoice = 50;
					input.clear();
					navigation = true;
				}
				else {
					cout << "Dialogue:----------------------------------------------------------------------------------------" << endl;
					cout << "The gargoyle refuses to acknowledge you." << endl;
					cout << "-------------------------------------------------------------------------------------------------" << endl;
					cout << endl;
				}
			}
			//inspect the gargoyle
			else if (input == "look gargoyle") {
				cout << "The gargoyle's gaze meets your own, and for a second you see its gaze move to your torch before " << endl;
				cout << "returning to meet your own once again." << endl;
			}

			//directional
			//north
			//moves to gargoyle door
			else if ((input == "walk n") || (input == "walk north")) {
				if (game.GetEvent(3) == false) { //while the door is closed.
					cout << "The door is closed, you need to figure out how to open it." << endl;
				}
				else { // once the door is open
					cout << "You walk through the door." << endl;

					menuChoice = 12;
					navigation = true;
				}
			}
			//looks north
			else if ((input == "look n") || (input == "look north")) {
				if (game.GetEvent(2) == false) {
					cout << "You see a strange, sealed wooden door with iron fittings." << endl;
				}
				else { // once the door is open
					cout << "The door is open, revealing a room eminating lots of heat. The room is well lit. There seems to " << endl;
					cout << "be something up ahead at the far end of that room." << endl;
				}
			}

			//south
			//moves to western intersection
			else if ((input == "walk s") || (input == "walk south")) {
				//ATTN: add check for the entrance key that the rat took
				cout << "You walk down the southern hallway towards the Western Intersection." << endl;
				menuChoice = 8;
				navigation = true;
			}
			else if ((input == "look s") || (input == "look south")) {
				cout << "You look down the dark hallway and see that there is an intersection ahead." << endl;
			}

			//items
			//use heat gloves
			else if ((input == "use gloves") || (input == "use heat gloves")) {
				if (game.GetEvent(14) == false) { //if you haven't opened the door
					cout << "What gloves?" << endl;

				}
				else if (game.GetEvent(3) == false && game.GetEvent(14) == true) { //for the player to open the door
					cout << "You put on the heat gloves and push the door open without burning your hands." << endl;
					game.EventTrigger(3, true); //opens door.
					game.EventTrigger(18, true); //makes the gargoyle permanently stone
				}
				else {//if you have opened the door
					cout << "The door is already open." << endl;
				}
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
				cout << endl;
			}
			cout << endl;
		}
	cout << "*************************************************************************************************" << endl;
	cout << endl;
	return menuChoice;
}

//ritual pools room
int roomRitualPools(int menuChoice, roomEvents& game, playerCharacter& user) {
	bool navigation = false; //boolean that will hold the room for the player, once it's true it will switch to a different room
	int userHp = user.GetCurrHP(); //calls player hp

	string input; //string to hold the users command

	user.PrintAdventurer(); //displays adventurer stats at the start of the room
	cout << endl;

	if (game.GetEvent(4) == false) {//if the statue is still uncovered
		cout << "In the center of this room is a pool of cold water, light dances off of the surface of the pool " << endl;
		cout << "reflecting dim light from a crack in the ceiling. at the center is a great stone statue of a " << endl;
		cout << "beast. The beast's gaze falls to a stone plate." << endl;
		cout <<  endl;
		cout << "To the east is the western intersection. " << endl;
		cout << endl;
	}
	else {
		cout << "In the center of this room is a pool of cold water, light dances off of the surface of the pool " << endl;
		cout << "reflecting dim light from a crack in the ceiling. At the center is a great stone statue of a " << endl;
		cout << "beast. The red cloak covers its head. A bronze plate sits beside the pool. " << endl;
		cout <<  endl;
		cout << "To the east is the western intersection. " << endl;
		cout << endl;
	}

	while (navigation == false ) {

		cout << "Enter Command: ";
		getline(cin, input);
		cout << endl;

		//outputs the room description
		if (input == "look room") {
			if (game.GetEvent(4) == false) {//if the statue is still uncovered
				cout << "In the center of this room is a pool of cold water, light dances off of the surface of the pool " << endl;
				cout << "reflecting dim light from a crack in the ceiling. at the center is a great stone statue of a " << endl;
				cout << "beast. The beast's gaze falls to a stone plate." << endl;
				cout <<  endl;
				cout << "To the east is the western intersection. " << endl;
				cout << endl;
			}
			else {
				cout << "In the center of this room is a pool of cold water, light dances off of the surface of the pool " << endl;
				cout << "reflecting dim light from a crack in the ceiling. At the center is a great stone statue of a " << endl;
				cout << "beast. The red cloak covers its head. A bronze plate sits beside the pool. " << endl;
				cout <<  endl;
				cout << "To the east is the western intersection. " << endl;
				cout << endl;

			}
		}
		//looks at the great beast
		else if ((input == "look beast") || (input == "look statue")) {
			if (game.GetEvent(4) == false) { //if the statue is still uncovered
				cout << "The horned beast looks as though it could come alive, and stares intently at the stone plate" << endl;
				cout << "on the other side of the pool. A cloth of some kind could be used to cover the head. You know" << endl;
				cout << "you've seen one around these catacombs somewhere." << endl;
			}
			else {
				cout << "The red cloak covers the beasts head. Probably for the best, it gave you the creeps anyway." << endl;
			}
		}

		//inspect the crack in the ceiling
		else if ((input == "look crack")) {
			cout << "A ray of sunlight creeps in from the stone ceiling. Its warmth brings you comfort in this dark place." << endl;
		}

		//inspect the pool
		else if (input == "look pool") {
			cout << "The water is crystal clear; the blue tile beneath reflects the a blue-ish hue onto the ceiling " << endl;
			cout << "and walls. It looks clean enough to drink." << endl;
		}
		//touches the pool. This gives a hint for the molten egg.
		else if ((input == "interact pool") || (input == "interact water")) {
			if (game.GetEvent(4) == false) {
				cout << "Against your better judgment, you give into your thirst and drink from the waters." << endl;
				cout << "The evil of the beast makes the water sting your mouth." << endl;
				cout << endl;
				cout << "[You take 1 damage]" << endl;

				userHp -= 1;
				user.SetCurrHP(userHp); //trap reduces player health by 1
				if (user.GetCurrHP() <= 0) { //checks if player died and if a game over screen should appear
					menuChoice = 100;
					navigation = true;
				}
			}
			else {
				cout << "Against your better judgment, you give into your thirst and drink from the waters." << endl;
				cout << "The evil of the stone beast no longer affects the water. It is ice cold and refreshing." << endl;
				cout << endl;
				cout << "[You heal 5 HP]" << endl;


				userHp += 5;
				if (userHp > user.GetMaxHP()) {
					userHp = user.GetMaxHP();
				}
				user.SetCurrHP(userHp);
			}
		}

		//plate
		//inspect the platter
		else if ((input == "look plate") || (input == "look bronze plate") || (input == "look stone plate")) {
			//if the statue head is uncovered
			if (game.GetEvent(4) == false) {
				cout << "A stone plate sets on the edge of the pool. A stone cylinder lays in the middle of plate." << endl;
			}
			//if statue head is covered and the vial is still on the plate
			else if ((game.GetEvent(4) == true) && (game.GetEvent(5) == false)) {
				cout << "A bronze plate sets on the edge of the pool. A glass vial lays in the middle of the plate. A silver" << endl;
				cout << "key lays inside the vial." << endl;
			}
			//if the statue head is covered and the vial has been taken
			else if ((game.GetEvent(4) == true) && (game.GetEvent(5) == true)) {
				cout << "A bronze plate sets on the edge of the pool." << endl;
			}
		}

		//attempt to take the plate
		else if ((input == "interact plate") || (input == "interact bronze plate") || (input == "interact stone plate")) {
			//if the statue head is uncovered
			if (game.GetEvent(4) == false) {
				cout << "There's no need to take a stone plate. You have nice stoneware at home." << endl;
			}
			//if statue head is covered and the vial is still on the plate
			else if ((game.GetEvent(4) == true) && (game.GetEvent(5) == false)) {
				cout << "There's no need to take a bronze plate. You have nice bronzeware at home. That vial looks like you" << endl;
				cout << "could take it though. Maybe that key inside it is useful?" << endl;
			}
			//if the statue head is covered and the vial has been taken
			else if ((game.GetEvent(4) == true) && (game.GetEvent(5) == true)) {
				cout << "There's no need to take a bronze plate. You have nice bronzeware at home." << endl;
			}
		}

		//vial
		//inspect the vial
		else if ((input == "look vial") || (input == "look glass vial") || (input == "look cylinder") || (input == "look stone cylinder")) {
			//if the statue head is uncovered
			if (game.GetEvent(4) == false) {
				cout << "The stone cylinder appears to have been made as part of the plate. What a strange design." << endl;
			}
			//if statue head is covered and the vial is still on the plate
			else if ((game.GetEvent(4) == true) && (game.GetEvent(5) == false)) {
				cout << "A glass vial with a silver key inside lays on the bronze plate." << endl;
			}
			//if the statue head is covered and the vial has been taken
			else if ((game.GetEvent(4) == true) && (game.GetEvent(5) == true)) {
				cout << "There's nothing to look at." << endl;
			}
		}


		//take the vial			else if ((input == "interact vial") || (input == "interact glass vial") || (input == "interact cylinder") || (input == "interact stone cylinder")) {
			//if the statue head is uncovered
			if (game.GetEvent(4) == false) {
				cout << "The stone cylinder doesn't budge." << endl;
			}
			//if statue head is covered and the vial is still on the plate
			else if ((game.GetEvent(4) == true) && (game.GetEvent(5) == false)) {
				cout << "You take the glass vial from the plate. You remove the key and put both into your pack.." << endl;
				cout << endl;

				game.EventTrigger(5, true);
				game.EventTrigger(12, true);
				game.EventTrigger(15, true);

				cout << "[1 Glass Vial added to Inventory]" << endl;
				cout << "[1 Silver Key added to Inventory]" << endl;
			}
			//if the statue head is covered and the vial has been taken
			else if ((game.GetEvent(4) == true) && (game.GetEvent(5) == true)) {
				cout << "There's nothing to look at." << endl;
			}
		}

		//items
		//the cloak
		else if (input == "use cloak") {
			if ((game.GetEvent(4) == false) && (game.GetEvent(11) == true)) {
				cout << "You place the cloak over the beast's head. The magical energies of the room have shifted." << endl;
				game.EventTrigger(4, true);
				game.EventTrigger(11, false);
			}
			else if ((game.GetEvent(4) == true)) {
				cout << "You don't think it's a good idea to remove the cloak." << endl;
			}
			else {
				cout << "You can'd do that." << endl;
			}
		}

		//the empty vial
		else if (input == "use vial") {
			if (game.GetEvent(12) == true) {
				cout << "You fill the vial with water from the pool." << endl;
				cout << endl;
				cout << "[1 vial of water added to Inventory]" << endl;

				game.EventTrigger(12, false);
				game.EventTrigger(13, true);
			}
			else {
				cout << "You can't do that. " << endl;
			}
		}

		//directions
		//east
		//looks towards the western intersection that is to the east... confusing name from this rooms perspective.
		else if ((input == "look e") || (input == "look east")) {
			cout << "You see the Western Intersection down the hall." << endl;
		}
		//walk back to the wester intersection
		else if ((input == "walk e") || (input == "walk east")) {
			cout << "You walk towards the Western Intersection" << endl;
			menuChoice = 8;
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
			cout << endl;
		}
		cout << endl;
	}

	cout << "*************************************************************************************************" << endl;
	cout << endl;
	return menuChoice;
}

//old chapel room
int roomOldChapel(int menuChoice, roomEvents& game, playerCharacter& user) {
	bool navigation = false; //boolean that will hold the room for the player, once it's true it will switch to a different room

	string input; //string to hold the users command

	user.PrintAdventurer(); //displays adventurer stats at the start of the room
	cout << endl;

	cout << "You find yourself in an old chapel. Six rows of stone pews line the walls leading to a strange alter" << endl;
	cout << "at the head of the room. A few small candles flicker on the edges of the altar. A small wooden box" << endl;
	cout << "sits in the center of the altar. " << endl;
	cout << "A figure shrouded in a black cloak sits silently at the front pew on the right. It doesn't seem to" << endl;
	cout << "acknowledge your presence." << endl;
	cout << endl;
	cout << "To the north there is a doorway leading to the Western Intersection. " << endl;
	cout << endl;

	while (navigation == false) {
		cout << "Enter Command: ";
		getline(cin, input);
		cout << endl;

		//redisplays the room description
		if (input == "look room") {
			cout << "You find yourself in an old chapel. Six rows of stone pews line the walls leading to a strange alter" << endl;
			cout << "at the head of the room. A few small candles flicker on the edges of the altar. A small wooden box" << endl;
			cout << "sits in the center of the altar. " << endl;
			cout << "A person shrouded in a black cloak sits silently at the front pew on the right. They don't seem to" << endl;
			cout << "acknowledge your presence." << endl;
			cout << endl;
			cout << "To the north there is a doorway leading to the Western Intersection. " << endl;
			cout << endl;
		}

		//shrouded figure
		//inspect the figure
		else if ((input == "look person") || (input == "look shrouded person") || (input == "look figure") || (input == "look shrouded figure") || (input == "look shroud")) {
			cout << "You look the shrouded figure up and down and cannot see any part of their person exposed. Their hands" << endl;
			cout << "are hidden inside their robes, interlocked together. You can hear the faintest sounds of a repetitive" << endl;
			cout << "chant coming from beneath the hood. However, their voice is too quiet to discern what they are saying." << endl;
		}

		//speak to the figure
		else if ((input == "interact person") || (input == "interact shrouded person") || (input == "interact figure") || (input == "interact shrouded figure") || (input == "interact shroud")) {
			menuChoice = 51; //moves to the conversation method
			navigation = true;
		}

		//altar
		//inspect the altar
		else if (input == "look altar") {
			cout << "You look over the stone altar. A few small lit candles dot the edges of the altar top. A small" << endl;
			cout << "wooden box sits in the center. A circle and unrecognizable symbols are drawn in a thick red liquid." <<endl;
		}

		//interact with the altar
		else if (input == "interact altar") {
			cout << "You start to reach your hand towards it, but a chill runs down your spine and you recoil. You" << endl;
			cout << "don't think you should touch that." << endl;
		}

		//small wooden box
		//look at the small wooden box on the altar
		else if ((input == "look wooden box") || (input == "look small wooden box") || (input == "look box") || (input == "look small box")){
			cout << "The small wooden box looks very generic, and rather uninteresting. A small keyhole rests below the " << endl;
			cout << "lid. However, looking at it makes you uncomfortable and you turn away." << endl;
		}

		//interact with the wooden box
		else if ((input == "interact wooden box") || (input == "interact small wooden box") || (input == "interact box") || (input == "interact small box")){
			cout << "You feel that might be a bad idea." << endl;
		}

		//directions
		//north
		//looks to the northern direction
		else if ((input == "look north") || (input == "look n")) {
			cout << "You can faintly make out the Western Intersection from the doorway." << endl;
		}

		//walk north
		else if ((input == "walk north") || (input == "walk n")) {
			cout << "You walk to the north towards the Western Intersection." << endl;
			menuChoice = 8; //moves back to the western intersection method
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

//lava room that holds the fire key
int roomLavaRoom(int menuChoice, roomEvents& game, playerCharacter& user) {
	bool navigation = false; //boolean that will hold the room for the player, once it's true it will switch to a different room
	int userHp = user.GetCurrHP(); //calls player hp

	string input; //string to hold the users command

	user.PrintAdventurer(); //displays adventurer stats at the start of the room
	cout << endl;

	cout << "You enter into a room and are instantly blasted by intense heat. Looking around there is a stone" << endl;
	cout << "path leading to a stone pedestal. Resting atop the pedestal is a molten egg. Around the path is" << endl;
	cout << "bubbling lava." << endl;
	cout << endl;
	cout << "To the south there is a doorway leading to the strange door. " << endl;
	cout << endl;

	while (navigation == false) {
		cout << "Enter Command: ";
		getline(cin, input);
		cout << endl;

		//inspect the room
		if (input == "look room") {
			cout << "You enter into a room and are instantly blasted by intense heat. Looking around there is a stone" << endl;
			cout << "path leading to a stone pedestal. Resting atop the pedestal is a molten egg. Around the path is" << endl;
			cout << "bubbling lava." << endl;
			cout << endl;
			cout << "To the south there is a doorway leading to the strange door. " << endl;
		}

		//pedestal
		//inspect pedestal
		else if (input == "look pedestal") {
			cout << "The stone pedestal is covered in strange rune markings that seem to pulse with faint red light." << endl;
		}

		//interact with the pedestal
		else if (input == "interact pedestal") {
			cout << "You trace your finger over one of the rune markings and despite the heat of the room, does not" << endl;
			cout << "burn your hand." << endl;
		}

		//egg
		//inspect the egg
		else if ((input == "look egg") || (input == "look molten egg")) {
			if (game.GetEvent(6) == false) { //if the egg has not been cooled
				cout << "The egg glows seems to produce more heat than the lava around your feet. Perhaps you could cool" << endl;
				cout << "it enough to touch it?" << endl;
			}
			else if ((game.GetEvent(6) == true) && (game.GetEvent(7) == false)){ //if the egg has been cooled and the key has not been taken
				cout << "The cooled stone that was the egg has broken into smaller obsidian shards, and an emblazened key" << endl;
				cout << "lies between the pieces." << endl;
			}
			else { //if the egg has cooled and you've taken the key.
				cout << "The cooled stone that was the egg has broken into smaller obsidian shards." << endl;
			}
		}
		//inspect the egg
		else if ((input == "interact egg") || (input == "interact molten egg")) {
			if (game.GetEvent(6) == false) { //if the egg has not been cooled
				cout << "You can see that this is moleten and feel the heat through your gloves, but touch it anyway." << endl;
				cout << "The heat pierces through the glove and it's one of the worst pains you've ever felt." << endl;
				cout << endl;
				cout << "[You take 8 damage]" << endl;

				userHp -= 8;
				user.SetCurrHP(userHp); //trap reduces player health by 8
				if (user.GetCurrHP() <= 0) { //checks if player died and if a game over screen should appear
					menuChoice = 100;
					navigation = true;
				}
			}
			else { //if the egg has been cooled
				cout << "The shards of the egg are smooth and sharp. You handle them carefully so not to cut yourself." << endl;
			}
		}

		//fire key
		//inspect the key
		else if ((input == "look key") || (input == "look molten key")) {
			if (game.GetEvent(6) == false) { //if the egg has not been cooled
				cout << "You can't do that. " << endl;
			}
			else if ((game.GetEvent(6) == true) && (game.GetEvent(7) == false)){ //if the egg has been cooled and the key has not been taken
				cout << "An iron key with molten cracks lays amidst the obsidian shards." << endl;
			}
			else { //if the egg has cooled and you've taken the key.
				cout << "There's nothing to look at." << endl;
			}
		}

		//take the key
		else if ((input == "interact key") || (input == "interact molten key")) {
			if (game.GetEvent(6) == false) { //if the egg has not been cooled
				cout << "You can't do that. " << endl;
			}
			else if ((game.GetEvent(6) == true) && (game.GetEvent(7) == false)){ //if the egg has been cooled and the key has not been taken
				cout << "You pick up the Fire Key." << endl;
				cout << endl;
				cout << "[1 Fire Key added to Inventory]" << endl;

				game.EventTrigger(7, true);
				game.EventTrigger(10, true);
			}
			else { //if the egg has cooled and you've taken the key.
				cout << "There's nothing to take." << endl;
			}
		}

		//LAVA (This is here, because we all know someone is going to do it. lol.
		//inspect lava
		else if ((input == "look lava") || (input == "look liquid hot magma")) {
			cout << "The molten rock bubbles and churns slowly. The heat is burning your exposed skin. You probably shouldn't" << endl;
			cout << "stay here long." << endl;
		}

		//interact lava
		else if ((input == "interact lava") || (input == "interact liquid hot magma")) {
			cout << "You reach down and attempt to touch the lava. However the glove and your sleeve catch on fire within inches" << endl;
			cout << "of nearing the lava. Startled, you fall forward into the lava and experience an excruciating end." << endl;

			menuChoice = 100; //game over screen
			navigation = true;
		}

		//using the vial
		else if (input == "use vial") {
			if (game.GetEvent(6) == false && game.GetEvent(13) == true) { //if the egg has not been cooled
				cout << "You pour the ice cold water out onto the molten egg. As the egg cools, it hisses and steams. The gloves" << endl;
				cout << "protect your hands from the heat, but the vial shatters in your hand." << endl;
				cout << endl;
				cout << "[1 glass vial removed from inventory]" << endl;
				cout << endl;
				cout << "As the steam dissipates the molten egg turns to a glassy obsidian and then shatters. It looks like an " << endl;
				cout << "object is mixed in with the obsidian glass." << endl;

				game.EventTrigger(13, false); //removes vial
				game.EventTrigger(6, true); //changes the egg's state
			}

			else {
				cout << "You can't do that." << endl;
			}
		}

		//directions
		//south
		//looks to the southern direction
		else if ((input == "look south") || (input == "look s")) {
			cout << "You can see the open mahogany door." << endl;
		}

		//walk north
		else if ((input == "walk south") || (input == "walk s")) {
			cout << "You walk to the south through the mahogany door." << endl;
			menuChoice = 9; //moves back to the strange door
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


#endif /* WESTERNDUNGEONROOMS_H_ */
