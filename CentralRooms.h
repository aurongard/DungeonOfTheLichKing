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


#ifndef CENTRALROOMS_H_
#define CENTRALROOMS_H_


//********
//New game
//********
int newGameIntro(int menuChoice){

	//Intro story piece
	cout << "*************************************************************************************************" << endl;
	cout << endl;
	cout << "     For nearly 1,000 years the Lich King Vhile Bonsh has reigned over the lands with an iron " << endl;
	cout << "grip. In the beginning he overthrew towns and cities, regardless of the the devastation, his  " << endl;
	cout << "army grew. Building his undead army from his fallen enemies, no one could stand up to his might " << endl;
	cout << "in the end. All nations either fell to his armies or submitted to his power and became vassal " << endl;
	cout << "states." << endl;
	cout << endl;

	cout << "     However, lurking in the shadows a rebel faction grew their numbers. They collected artifacts " << endl;
	cout << "to obscure themselves from the mind of Vhile Bonsh while they gathered themselves together. Slowly" << endl;
	cout << "a plan to find his weakness came together. Generations of searching finally revealed secret" << endl;
	cout << "catacombs and the phylactery that housed Vhile Bonsh's soul, his only weakness." << endl;
	cout << endl;

	cout << "     Having only a single chance to end the reign of Vhile Bonsh, the rebels launched an assault" << endl;
	cout << "far away from the catacombs while a lone adventurer snuck into the catacombs. Their goal, to find" << endl;
	cout << "and destroy that phylactery and end Vhile Bonsh's reign of terror once and for all." << endl;
	cout << endl;

	//sends the menu to character creation
	return menuChoice = 6;
}


string createCharacter() {
	bool nameSelection = true;
	string userName;
	char choice;

	//asks the user for their character name
	cout << "Brave adventurer who would risk your life, tell us your name." << endl;
	cout << endl;
	cout << "Enter your name: ";
	cin >> userName;
	cout << endl;

	while (nameSelection == true) {
		//displays the entered name and verify's if it is correct
		cout << "Is " << userName << " correct? [y] or [n]" << endl;
		cin >> choice;
		cout << endl;

		choice = (char)tolower(choice);

		//ends the while loop and preps to return the name to the switch
		if (choice == 'y') {
			nameSelection = false;
		}
		//if incorrect it asks the user to enter a new name.
		else if (choice == 'n') {
			cout << "Tell us your name, brave adventurer. " << endl;
			cin >> userName;
			cout << endl;
		}
		//a catch just in case the user enters a choice besides y or n.
		else {
			cout << "Invalid selection. " << endl;
		}
	}

	cout << "Go forth " << userName << ", the brave adventurer, the fate of the world rests in your hands now!" << endl;
	cout << endl;
	cout << "*************************************************************************************************" << endl;
	cout << endl;

	//returns the user name to main
	return userName;
}

//*********************
//Central Dungeon Rooms
//*********************

//dungeon entrance
int roomEntrance(int menuChoice, roomEvents& game, playerCharacter& user) {
	bool navigation = false; //boolean that will hold the room for the player, once its true it will switch to a different room
	int bones = 0; // a variable to count how many times the skeleton has been interacted with.

	string input; //holds the user commands

	//will only display this on a new game. Subsequent returns to this room will
	if (game.GetEvent(0) == false) {
		cout << "You find the old entrance hidden behind thick vines and bushes. If you hadn't known it was there" << endl;
		cout << "you would have never found it. It appears that the information dealer was correct. " << endl;
		cout << endl;
		cout << "With a deep breath to steele yourself, you use the key you were given and enter the ancient" << endl;
		cout << "catacombs. You know you can't turn back now. Once inside, you close and lock the door behind you." << endl;
		cout << endl;
		cout << "Before you can light your torch, something bites your leg in the darkness and you drop the key. " << endl;
		cout << "You hear the squeek of a rat and the scraping of the key. Caught off guard you couldn't tell which" << endl;
		cout << "direction the rat went. You need to get that key back if you want to be able escape." << endl;
		cout << endl;
		cout << "You light the torch in your hand and the room illuminates. Find the phylactery and destroy it." << endl;
		cout << endl;

		//sets the event trigger to true to prevent this text from displaying again.
		game.EventTrigger(0, true);

		getline(cin, input);
	}

	//displays adventurer stats at the start of the room
	user.PrintAdventurer();

	cout << endl;
	cout << "You stand in a stone room with 6 pillars, a skeleton leans against one of the pillars nearest to" << endl;
	cout << "the entrance. Dusty cobwebs hang loosely from the ceiling." << endl;
	cout <<  endl;

	if (game.GetEvent(27) == true) {//will collapse the western passages if the phylactery was broken
		cout << "The western passage has collapsed. You can no longer go that way." << endl;
		cout << endl;
	}

	cout << "To the north there is an ornate iron door. " << endl;
	cout << "To the east there is a hallway." << endl;

	if (game.GetEvent(27) == false) { //will no longer display if the phylactery is destroyed
		cout << "To the west there is a hallway." << endl;
	}
	cout << "To the south is the entrance door to the catacombs." << endl;
	cout << endl;

	//creates the room instance for the player to interact with the room.
	while (navigation == false) {

		cout << "Enter Command: ";
		getline(cin, input);
		cout << input << endl;

		//outputs the room description
		if ((input == "look room")) {
			cout << "You stand in a stone room with six pillars, a skeleton leans against one of the pillars nearest to " << endl;
			cout << "the entrance. Dusty cobwebs hang loosely from the ceiling." << endl;
			cout << endl;

			if (game.GetEvent(27) == true) { //will collapse the western passages if the phylactery was broken
				cout << "The western passage has collapsed. You can no longer go that way." << endl;
				cout << endl;
			}

			cout << "To the north there is an ornate iron door. " << endl;
			cout << "To the east there is a hallway." << endl;

			if (game.GetEvent(27) == false) {//will no longer display if the phylactery is destroyed
				cout << "To the west there is a hallway." << endl;
			}
			cout << "To the south is the entrance door to the catacombs." << endl;
		}
		//cobweb commands
		//looks at the cobwebs
		else if ((input == "look cobweb") || (input == "look cobwebs")) {
			cout << "Looks like even the spiders are terrified of Vhile Bonsh. These cobwebs have a for rent sign" << endl;
			cout << "and have clearly been vacant for some time." << endl;
		}
		//interacts with the cobwebs
		else if ((input == "interact cobwebs") || (input == "interact cobweb")) {
			cout << "That's gross, don't touch that." << endl;
		}

		//skeleton
		//look at the skeleton and drops hint about the red cloth)
		else if((input == "look skeleton") || (input == "look spooky boi")) {
			if (game.GetEvent(1) == false) {
				cout << "The skeletal remains stare, mouth agape, in the direction of the entrance door. Its clothes are in tatters " << endl;
				cout << "except for the mostly intact red cloak draped over its left arm" << endl;
			}
			else {
				cout << "The skeletal remains stare, mouth agape, in the direction of the entrance door. Its clothes are in tatters." << endl;
			}
		}
		//look at the cloak
		else if(input == "look cloak") {
			if (game.GetEvent(1) == false) {
				cout << "Somehow this cloak has survived an untold amount of time down here." << endl;
			}
			else {
				cout << "There's nothing to look at." << endl;
			}
		}

		//interact with the skeleton
		else if((input == "interact skeleton") || (input == "interact spooky boi")) {
			if (bones < 5) {
				cout << "The bones rattle a bit." << endl;
				++bones;
			}
			else {
				cout << "The bones are rattled out." << endl;
			}
		}

		//add cloak to inventory
		else if((input == "interact cloak") || (input == "interact red cloak")) {
			if (game.GetEvent(1) == false) {
				cout << "You take the red cloak." << endl;
				cout << endl;
				cout << "[1 Red Cloak added to Inventory]" << endl;

				game.EventTrigger(1, true); //updates the skeleton to have cloak removed
				game.EventTrigger(11, true); //adds cloak to inventory
			}
			else {
				cout << "There's nothing to take." << endl;
			}
		}

		//pillar commands
		//looks at the pillars
		else if ((input == "look pillar") || (input == "look pillars")) {
			cout << "These pillars look sturdy and well supported." << endl;
		}
		//interacts with the pillars
		else if ((input == "interact pillar") || (input == "interact pillars")) {
			cout << "You push on the pillar, it doesn't budge." << endl;
		}

		//iron door commands
		//inspects the iron door
		else if ((input == "look ornate door")|| (input == "look iron door")) {
			if (game.GetEvent(21) == false && game.GetEvent(22) == false) { //if you've found no keys
				cout << "A large ornate iron door stands before you. It is engraved with an image of an imposing person" << endl;
				cout << "wielding a staff, and beneath him are wailing souls. You assume this figure to be Vhile Bonsh. There" << endl;
				cout << "are two keyholes beneath the iron handle. One bares the mark of a skull and the other a mark of fire." << endl;
			}

			else if (game.GetEvent(21) == true && game.GetEvent(22) == false) { //if you've used the fire key on the door
				cout << "A large ornate iron door stands before you. It is engraved with an image of an imposing person" << endl;
				cout << "wielding a staff, and beneath him are wailing souls. You assume this figure to be Vhile Bonsh. There" << endl;
				cout << "are two keyholes beneath the iron handle. One bares the mark of a skull and the other a mark of fire." << endl;
				cout << endl;
				cout << "The Fire Key rests in its slot. You still need to find the Skull Key." << endl;
			}

			else if (game.GetEvent(21) == false && game.GetEvent(22) == true) { //if you've used the skull key on the door
				cout << "A large ornate iron door stands before you. It is engraved with an image of an imposing person" << endl;
				cout << "wielding a staff, and beneath him are wailing souls. You assume this figure to be Vhile Bonsh. There" << endl;
				cout << "are two keyholes beneath the iron handle. One bares the mark of a skull and the other a mark of fire." << endl;
				cout << endl;
				cout << "The Skull Key rests in its slot. You still need to find the Fire Key." << endl;
			}
			else if (game.GetEvent(21) == false && game.GetEvent(22) == false) { //once both keys have been used on the door
				cout << "The door is now open and a foul stench attacks your senses." << endl;
			}

			//ATTN: add statement for when the door is unlocked.
		}
		else if ((input == "interact ornate door")|| (input == "interact iron door")) {
			if (game.GetEvent(21) == false || game.GetEvent(22) == false) {
				cout << "The door is locked" << endl;
			}
			else if (game.GetEvent(21) == true && game.GetEvent(22) == true) {
				cout << "The door is already open" << endl;
			}
		}

		//ATTN: Add entrance door statements
		//entrance door
		//inspects the entrance door
		else if (input == "look entrance door") {
			//entrance door if the phylactery is unbroken, you haven't used the iron key, and you don't have the iron key
			if ((game.GetEvent(29) == false) && (game.GetEvent(16) == false) && (game.GetEvent(27) == false)) {
				cout << "The door is locked, so at least no one can follow you in. You need to find and destroy the" << endl;
				cout << "phylactery, and find the iron key that unlocks this door." << endl;
			}
			//entrance door if the phylactery is destroyed, you haven't used the iron key, and you don't have the iron key
			else if ((game.GetEvent(29) == false) && (game.GetEvent(16) == false) && (game.GetEvent(27) == true)) {
				cout << "The door is locked! You have to hurry and find the key so you can escape!" << endl;
			}
			//entrance door if the phylactery is destroyed, you haven't used the iron key, and you DO have the iron key
			else if ((game.GetEvent(29) == false) && (game.GetEvent(16) == true) && (game.GetEvent(27) == true)) {
				cout << "The door is locked! You have to hurry and use the iron key to unlock the door so you can escape!" << endl;
			}
			//entrance door if the phylactery is unbroken, you have used the iron key, and you don't have the iron key
			else if ((game.GetEvent(29) == true) && (game.GetEvent(16) == false) && (game.GetEvent(27) == false)) {
				cout << "The door is unlocked! But you need to destroy the phylactery still." << endl;
			}
			//entrance door if the phylactery is destroyed, you have used the iron key, and you don't have the iron key
			else if ((game.GetEvent(29) == true) && (game.GetEvent(16) == false) && (game.GetEvent(27) == true)) {
				cout << "The door is unlocked! You have to hurry and get through this door. The place is falling apart." << endl;
			}
		}
		//interact with the entrance door
		else if (input == "interact entrance door") {
			//entrance door if the phylactery is unbroken, you haven't used the iron key, and you don't have the iron key
			if ((game.GetEvent(29) == false) && (game.GetEvent(16) == false) && (game.GetEvent(27) == false)) {
				cout << "The door is locked, so at least no one can follow you in. You need to find and destroy the" << endl;
				cout << "phylactery, and find the iron key that unlocks this door." << endl;
			}

			//entrance door if the phylactery is destroyed, you haven't used the iron key, and you DO have the iron key
			else if ((game.GetEvent(29) == false) && (game.GetEvent(16) == true)) {
				cout << "You take out the iron key and unlock it." << endl;
				cout << endl;
				cout << "[1 Iron Key removed from Inventory]" << endl;

				game.EventTrigger(16, false); //removes iron key from inventory
				game.EventTrigger(29, true); // set the door to unlocked
			}
			else if ((game.GetEvent(29) == true) && (game.GetEvent(27) == false) ) {
				cout << "You need to destroy Vhile Bonsh phylactery first!" << endl;
			}

			else if ((game.GetEvent(29) == true) && (game.GetEvent(27) == true) ) {
				cout << "You pull the door open and run through." << endl;
				menuChoice = 100;
				navigation = true;
			}
		}

		//directional
		//north
		//moves to the crypt of Vhile Bonsh
		else if ((input == "walk n") || (input == "walk north")) {
			if (game.GetEvent(21) == false || game.GetEvent(22) == false) {
				cout << "The door is locked, you'll need to find the keys. Hopefully they're somewhere in these catacombs." << endl;
			}
			else if (game.GetEvent(21) == true && game.GetEvent(22) == false) {
				cout << "The door is locked, you still need to find the Skull Key." << endl;
			}
			else if (game.GetEvent(21) == false && game.GetEvent(22) == true) {
				cout << "The door is locked, you still need to find the Fire Key." << endl;
			}
			else if (game.GetEvent(21) == true && game.GetEvent(22) == true) {
				cout << "You walk through the open door." << endl;

				menuChoice = 31;
				navigation = true;
			}
		}

		//looks north
		else if ((input == "look n") || (input == "look north")) {
			// if the door is open
			if (game.GetEvent(21) == true && game.GetEvent(22) == true) {
				cout << "The ornate iron door is open." << endl;
			}
			//if you've used the fire key but not the skull key
			else if (game.GetEvent(21) == true && game.GetEvent(22) == false) {
				cout << "The ornate iron door is locked, you still need to find the Skull Key." << endl;
			}
			//if you've used the skull key but not the fire key
			else if (game.GetEvent(21) == false && game.GetEvent(22) == true) {
				cout << "The ornate iron door is locked, you still need to find the Fire Key." << endl;
			}
			//if you've not used either key
			else {
				cout << "An ornate iron door stands before you." << endl;
			}
		}

		//east
		//moves to the eastern halls
		else if ((input == "walk e") || (input == "walk east")) {
			cout << "You walk down the eastern hallway." << endl;
			menuChoice = 13;
			navigation = true;
		}
		//looks east
		else if ((input == "look e") || (input == "look east")) {
			cout << "A long, dark hallway sprawls ahead." << endl;
		}

		//west
		//moves to the Western Intersection
		else if ((input == "walk w") || (input == "walk west") ){
			if (game.GetEvent(27) == true) {
				cout << "The passageway collapsed. You cannot go that way." << endl;
			}
			else {
				cout << "You walk down the western hallway." << endl;
				menuChoice = 8;
				navigation = true;
			}
		}
		//looks west
		else if ((input == "look w") || (input == "look west") ){
			if (game.GetEvent(27) == true) {
				cout << "The passageway collapsed." << endl;
			}
			else {
				cout << "You look down the dark hallway and see that there is an intersection ahead." << endl;
			}
		}

		//south
		//attempts to exit the dungeon
		else if ((input == "walk s") || (input == "walk south")) {
			//entrance door if the phylactery is unbroken, you haven't used the iron key, and you don't have the iron key
			if ((game.GetEvent(29) == false) && (game.GetEvent(16) == false) && (game.GetEvent(27) == false)) {
				cout << "You can't leave even if you wanted to. You have to find the phylactery and that key..." << endl;
			}

			//if the door is unlocked but you haven't broken the phylactery
			else if ((game.GetEvent(29) == true) && (game.GetEvent(27) == false) ) {
				cout << "You need to destroy Vhile Bonsh phylactery first!" << endl;
			}

			//if the door is unlocked and you destroyed the phylactery
			else if ((game.GetEvent(29) == true) && (game.GetEvent(27) == true) ) {
				cout << "You pull the door open and run through." << endl;
				menuChoice = 100;
				navigation = true;
			}
		}
		else if ((input == "look s") || (input == "look south")) {
			if (game.GetEvent(29) == false) {
				cout << "The locked entrance door." << endl;
			}
			else if (game.GetEvent(29) == true) {
				cout << "The unlocked entrance door." << endl;
			}
		}

		//using items
		//fire key
		else if ((input == "use fire key")) {
			if (game.GetEvent(10) == true) { //checks if you have the fire key.
				cout << "You insert the key into the lock and turn it. You hear a loud clanking noise. The key is locked" << endl;
				cout << "in place and you cannot remove it now." << endl;
				cout << endl;
				cout << "[1 Fire Key removed from inventory]" << endl;

				game.EventTrigger(10, false); //removes fire key from you inventory
				game.EventTrigger(21, true); //event that the fire key is in the door

				if (game.GetEvent(22) == true && game.GetEvent(21) == true) { // checks if you have put the opposite key into the door.
					cout << endl;
					cout << "The door opens slowly letting out a musty and foul air. A strong presence of evil lays beyond." << endl;
					cout << "Do you dare step foot inside?" << endl;
				}
			}
			else {
				cout << "You can't do that." << endl;
			}
		}

		//skull key
		else if ((input == "use skull key")) {
			if (game.GetEvent(9) == true) { //checks if you have the fire key.
				cout << "You insert the key into the lock and turn it. You hear a loud clanking noise. The key is locked" << endl;
				cout << "in place and you cannot remove it now." << endl;
				cout << endl;
				cout << "[1 Skull Key removed from inventory]" << endl;

				game.EventTrigger(9, false); //removes skull key from you inventory
				game.EventTrigger(22, true); //event that the skull key is in the door

				if (game.GetEvent(22) == true && game.GetEvent(21) == true) { // checks if you have put the opposite key into the door.
					cout << endl;
					cout << "The door opens slowly letting out a musty and foul air. A strong presence of evil lays beyond." << endl;
					cout << "Do you dare step foot inside?" << endl;
				}
			}
			else {
				cout << "You can't do that." << endl;
			}
		}

		else if (input == "use iron key") {
			if (game.GetEvent(16) == true) {
				cout << "You unlock the entrance door." << endl;
				cout << endl;
				cout << "[1 Iron Key removed from Inventory]" << endl;

				game.EventTrigger(16, false); //removes iron key from inventory
				game.EventTrigger(29, true); // set the door to unlocked
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
		}
		cout << endl;
	}
	cout << "*************************************************************************************************" << endl;
	cout << endl;
	return menuChoice;
}

//dungeon entrance
int roomFinal(int menuChoice, roomEvents& game, playerCharacter& user) {
	bool navigation = false; //boolean that will hold the room for the player, once its true it will switch to a different room
	bool decision = false; //boolean that will hold the decision to break the phylactery
	string input; //holds the user commands
	int userHp = user.GetCurrHP(); //calls player hp

	user.PrintAdventurer();//displays adventurer stats at the start of the room
	cout << endl;

	if (game.GetEvent(27) == false) {
		cout << "You enter into a massive chamber with five stone pillars marking the points of a massive star drawn" << endl;
		cout << "onto the floor in blood. Runes are drawn in blood to form a circle around the star. At its very" << endl;
		cout << "center is a pedestal with a strange object on it." << endl;
		cout << endl;
		cout << "To the south there is a dark hallway." << endl;
		cout << endl;
	}
	else {
		cout << "You enter into a massive chamber with five stone pillars marking the points of a massive star drawn" << endl;
		cout << "onto the floor in blood. Runes are drawn in blood to form a circle around the star. At its very" << endl;
		cout << "center is a pedestal. Around it are the shards of the broken phylactery" << endl;
		cout << endl;
		cout << "To the south there is a dark hallway." << endl;
		cout << endl;
	}

	//creates the room instance for the player to interact with the room.
	while (navigation == false) {

		cout << "Enter Command: ";
		getline(cin, input);
		cout << input << endl;

		//outputs the room description
		if ((input == "look room")) {
			if (game.GetEvent(27) == false) {
				cout << "You enter into a massive chamber with five stone pillars marking the points of a massive star drawn" << endl;
				cout << "onto the floor in blood. Runes are drawn in blood to form a circle around the star. At its very" << endl;
				cout << "center is a pedestal with a strange object on it." << endl;
				cout << endl;
				cout << "To the south there is a dark hallway." << endl;
				cout << endl;
			}
			else {
				cout << "You enter into a massive chamber with five stone pillars marking the points of a massive star drawn" << endl;
				cout << "onto the floor in blood. Runes are drawn in blood to form a circle around the star. At its very" << endl;
				cout << "center is a pedestal. Around it are the shards of the broken phylactery" << endl;
				cout << endl;
				cout << "To the south there is a dark hallway." << endl;
				cout << endl;
			}
		}

		//star and rune circle
		//inspect
		else if ((input == "look star") || (input == "look circle") || (input == "look blood")) {
			if (game.GetEvent(27) == false) {
				cout << "The blood that this was drawn with appears to be flowing somehow. It makes you uneasy to look at." << endl;
			}
			else {
				cout << "The blood that this was drawn with appears to have dried up." << endl;
			}
		}
		//interact
		else if ((input == "interact star") || (input == "interact circle") || (input == "interact blood")) {
			if (game.GetEvent(27) == false) {
				cout << "Something deep inside you tells you that this is a VERY bad idea and decide that it is best left alone." << endl;
			}
			else {
				cout << "You wipe away some of the dried blood with your foot. You really don't have time for this." << endl;
			}
		}

		//pillars
		//inspect
		else if ((input == "look pillars") || (input == "look pillar")) {
			if (game.GetEvent(27) == false) {
				cout << "The pillars look similar to the pillars in the entrance room, but bigger. You also feel an energy flowing" << endl;
				cout << "from them." << endl;
			}
			else {
				cout << "The pillars look similar to the pillars in the entrance room, but bigger. The energy is gone now." << endl;
			}
		}
		//interact
		else if ((input == "interact pillars") || (input == "interact pillar")) {
			if (game.GetEvent(27) == false) {
				cout << "The pillar is warm to the touch and you hear thousands of voices all at once. You quickly pull your hand" << endl;
				cout << "from the pillar and the room goes quiet once more." << endl;
			}
			else {
				cout << "The pillar is cold to the touch now. You really don't have time for this." << endl;
			}
		}

		//pedestal
		//inspect
		else if ((input == "look pedestal")) {
			if (game.GetEvent(27) == false) {
				cout << "The pedestal appears to be made from black marble. An obsidian skull with a still living eye sits on the" << endl;
				cout << "pedestal." << endl;
			}
			else {
				cout << "The pedestal appears to be made from black marble." << endl;
			}
		}
		//interact
		else if ((input == "interact pedestal")) {
			if (game.GetEvent(27) == false) {
				cout << "You touch the pedestal and it is hot to the touch. You feel thousands of souls coursing through it to the" << endl;
				cout << "obsidian skull. You felt their pleas begging you to free them." << endl;
			}
			else {
				cout << "The pedestal is cold to the touch now. You really don't have time for this." << endl;
			}
		}

		//phylactery
		//inspect
		else if ((input == "look phylactery") || (input == "look object") || (input == "look skull") || (input == "look obsidian skull")) {
			if (game.GetEvent(27) == false) {
				cout << "The obsidian skull is cracked with a polished surface. The skull appears humanoid, however all of the teeth are sharp" <<endl;
				cout << "and a still living eye sits in the left socket. The eye stares at you. You can feel it prying into your mind. " << endl;
				cout << "Vhile Bonsh knows you're here. He's coming! You have to end this! ...Or do you?" << endl;
			}
			else {
				cout << "The shards of the skull are scattered all around. The eye is nowhere in sight. You really don't have time for this." << endl;
			}
		}
		//interact
		else if ((input == "interact phylactery") || (input == "interact object") || (input == "interact skull") || (input == "interact obsidian skull")) {
			if (game.GetEvent(27) == false) {

				cout << "You pick up the obsidian skull and bring its face up to yours. The singular eye peering deep into" << endl;
				cout << "your own. You can feel absolute power flowing from this skull into your hands." << endl;
				cout << endl;

				userHp = 10;
				user.SetCurrHP(userHp); //fully heals player

				cout << "[Your HP is fully restored]" << endl;
				cout << endl;

				cout << "Your own life force is being restored by this artifact. But as you look to your hands, you see that" << endl;
				cout << "at some point the teeth had pierced your skin. Blood trickles down your arms." << endl;
				cout << endl;
				cout << "The eye stares more intently into yours and you realize a voice is calling to you. There are no words, " << endl;
				cout << "instead images and ideas come flooding into your mind. These visions show you powerful, immortal, and " << endl;
				cout << "you overtaking Vhile Bonsh. The world bends to your will." << endl;
				cout << endl;
				cout << "The power you feel is overwhelming... What do you do?" << endl;
				cout << endl;

				cout << "'absorb' - Absorb the obsidian skull's power into your being." << endl;
				cout << "'destroy' - Smash the skull to the ground and destroy it." << endl;
				cout << endl;

				while (decision == false) {

					cout << "Enter Command: ";
					getline(cin, input);
					cout << input << endl;

					//to absorb the skull
					if (input == "absorb") {
						game.EventTrigger(30, true); //event marker for absorbing the skull
						menuChoice = 100;
						navigation = true;
						decision = true;
					}

					//to destroy the skull
					else if (input == "destroy") {
						cout << "You ignore the temptations offered to you and thrust the skull towards the ground with all your might." << endl;
						cout << "It explodes into thousands of pieces and you are knocked back several feet by a blast of magical energy." << endl;
						cout << endl;
						cout << "You pick yourself up and realize that the building is shaking. Whatever magics held this unholy place" << endl;
						cout << "together are no gone and it has begun collapsing. You need to get out of here, NOW!" << endl;

						game.EventTrigger(27, true); //event marker for smashing the skull
						decision = true;
					}

					//for incorrect input.
					else {
						cout << "You can't do that. " << endl;
					}
				}
			}
			else {
				cout << "You've already destroyed the phylactery. You really don't have time for this." << endl;
			}
		}

		//direction
		//south
		//moves to entrance
		else if ((input == "walk s") || (input == "walk south")) {
			//ATTN: add check for the entrance key that the rat took
			cout << "You walk towards the entrance." << endl;
			menuChoice = 7;
			navigation = true;
		}
		else if ((input == "look s") || (input == "look south")) {
			cout << "You look through the doorway and see the entrance hall." << endl;
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



#endif /* CENTRALROOMS_H_ */
