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

#ifndef DUNGEONNPCS_H_
#define DUNGEONNPCS_H_


//*********************
//Non Player Characters
//*********************
int talkGargoyle(int menuChoice, roomEvents& game, playerCharacter& user) {
	bool gargoyleSpeak = game.GetEvent(28); // checks to see if you've offended the gargoyle
	bool conversation = true; //boolean to keep the conversation going.
	string userInput; //holds the user responses.

	cout << "Dialogue:----------------------------------------------------------------------------------------" << endl;
	cout << "The gargoyle smiles at you wryly and says excitedly, 'Oh my! A bit of company! Are you lost?' " << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;

	while (conversation == true) {
		cout << "Dialogue options:" << endl;
		cout << "[a] You can speak!?" << endl;
		cout << "[b] Can you open this door?" << endl;
		cout << "[c] Yes, I am lost. Can you help me?" << endl;
		cout << "[d] No, I'm not lost. I know exactly where I am." << endl;
		cout << "[e] Goodbye." << endl;
		cout << "-------------------------------------------------------------------------------------------------" << endl;
		cout << endl;

		//requests user input for menu choice
		cout << "Enter response: ";
		getline(cin, userInput);
		cout << endl;

		//you can speak!? response
		if (userInput == "a") {
			cout << "Dialogue:----------------------------------------------------------------------------------------" << endl;
			cout << "The stone creatures snorts and states in a matter of fact tone, 'Of course I can speak, I'm the " << endl;
			cout << "guardian of this door, and let me tell you it's too hot to handle.'" << endl;
			cout << "-------------------------------------------------------------------------------------------------" << endl;
			cout << "Dialogue options:" << endl;
			cout << "[a] Some guardian you are, you're just a decoration." << endl;
			cout << "[b] Clearly, you are a stoic protector. Can you open this door for me?" << endl;
			cout << "-------------------------------------------------------------------------------------------------" << endl;
			cout << endl;

			bool conv2 = true; //boolean
			while (conv2 == true) {
				cout << "Enter response: ";
				getline(cin, userInput);
				cout << endl;

				//Some guardian you are, you're just a decoration response
				if (userInput == "a") { //rude dialogue option. stops gargoyle from responding to user.
					cout << "Dialogue:----------------------------------------------------------------------------------------" << endl;
					cout << "The gargoyle hisses at you and declares, 'How rude! I refuse to speak to someone so awful!'" << endl;
					cout << "Turning its head to the side, the stone guardian decides not to acknowledge you any further." << endl;
					cout << "-------------------------------------------------------------------------------------------------" << endl;
					cout << endl;

					conv2 = false; //breaks current conversation loop
					conversation = false; //breaks main conversation loop
					gargoyleSpeak = true;//trigger to ensure gargoyle will not respond going forward
					game.EventTrigger(28, gargoyleSpeak); //trigger to ensure gargoyle will not respond going forward
				}

				//Clearly, you are a stoic protector. Can you open this door for me? response
				else if (userInput == "b") {
					cout << "Dialogue:----------------------------------------------------------------------------------------" << endl;
					cout << "The gargoyle sways its head triumphantly and declares, 'Thank you for noticing! Just for that " << endl;
					cout << "I will let you in on a secret, you need special gloves to touch this door or you'll be burned." << endl;
					cout << "The specter in the old chapel has them.' " << endl;
					cout << "-------------------------------------------------------------------------------------------------" << endl;
					cout << endl;

					conv2 = false; //breaks current conversation loop
				}
			}
		}

		//Can you open this door? response
		else if (userInput == "b") {
			cout << "Dialogue:----------------------------------------------------------------------------------------" << endl;
			cout << "The gargoyle responds dryly, 'I cannot, for I do not have arms. But should you have the " << endl;
			cout << "protection of the old gods, you can open it yourself.'" << endl;
			cout << "-------------------------------------------------------------------------------------------------" << endl;
			cout << endl;
		}

		//Yes, I am lost. Can you help me? response
		else if (userInput == "c") {
			cout << "Dialogue:----------------------------------------------------------------------------------------" << endl;
			cout << "The gargoyle thinks for a moment and says, 'All I've known is this hallway and you came from a  " << endl;
			cout << "place that I cannot see. But straight ahead is the old chapel where the old specter dwells." << endl;
			cout << "Maybe they can help you?' " << endl;
			cout << "-------------------------------------------------------------------------------------------------" << endl;
			cout << endl;
		}

		//No, I'm not lost. I know exactly where I am. response
		else if (userInput == "d") {
			cout << "Dialogue:----------------------------------------------------------------------------------------" << endl;
			cout << "The gargoyle rolls its eyes and responds sarcastically, 'Whatever you say.'" << endl;
			cout << "-------------------------------------------------------------------------------------------------" << endl;
			cout << endl;
		}

		//exits conversation
		else if (userInput == "e") {
			cout << "Dialogue:----------------------------------------------------------------------------------------" << endl;
			cout << "The gargoyle seems a little sad, and dejectedly responds, 'Goodbye. Feel free to come back.' " << endl;
			cout << "-------------------------------------------------------------------------------------------------" << endl;
			cout << endl;

			conversation = false;
		}
		//for incorrect input.
		else {
			cout << "Invalid input. " << endl;
			cout << endl;
		}
	}
	return menuChoice = 9; //returns to strange door
}

int talkShroud(int menuChoice, roomEvents& game, playerCharacter& user) {
	bool conversation = true; //boolean to keep the conversation going.

	while (conversation == true) {

		if (game.GetEvent(19) == false) {

			//greeting the shrouded figure and moving the quest forward.
			cout << "Dialogue:----------------------------------------------------------------------------------------" << endl;
			cout << "The shrouded figure's prayer stops suddenly, and the hooded head turns towards you in" << endl;
			cout << "acknowledgment." << endl;
			cout << "-------------------------------------------------------------------------------------------------" << endl;
			cout << endl;

			game.EventTrigger(19, true);
		}

		//once you've initially spoken to shrouded figure and have not yet given them the silvery key
		else if (game.GetEvent(19) == true && game.GetEvent(20) == false) {
			if (game.GetEvent(15) == false) { //if you do not have the key
				cout << "Dialogue:----------------------------------------------------------------------------------------" << endl;
				cout << "The shrouded figure says in a raspy and meloncholic voice, 'The keeper of the maze took my key and" << endl;
				cout << "gave it to the stone beast. If you could break its gaze and bring it to me, I will reward you with" << endl;
				cout << "passage to the north." <<endl;
				cout << "-------------------------------------------------------------------------------------------------" << endl;
				cout << endl;

				conversation = false;
			}

			if (game.GetEvent(15) == true) { // if you find the key
				cout << "Dialogue:----------------------------------------------------------------------------------------" << endl;
				cout << "The shrouded figure says in an excited tone, 'You have the key! I can smell it!'" << endl;
				cout << endl;
				cout << "[You hand the silver key to the shrouded figure]" << endl;

				game.EventTrigger(15, false);

				cout << "The shrouded figured stands up with a groan and ushers towards to altar and uses the key on the " <<endl;
				cout << "small wooden box. It produces a pair of strange gloves and presents them to you." << endl;
				cout << endl;
				cout << "'These will allow you to open the door to the north.'" << endl;
				cout << endl;
				cout << "[1 pair of Heat Gloves added to Inventory]" << endl;
				cout << endl;
				cout << "The shrouded figure closes and locks the small wooden box once more, and then sits back down" << endl;
				cout << "only to begin their quiet chanting once more." << endl;
				cout << "-------------------------------------------------------------------------------------------------" << endl;
				cout << endl;

				game.EventTrigger(20, true);
				game.EventTrigger(14, true);

				conversation = false;
			}
		}
		else if (game.GetEvent(19) == true && game.GetEvent(20) == true) {
			cout << "Dialogue:----------------------------------------------------------------------------------------" << endl;
			cout << "The shrouded figure does not acknowledge you and continues their quiet chanting." << endl;
			cout << "-------------------------------------------------------------------------------------------------" << endl;

			conversation = true;
		}
	}
	return menuChoice = 11;
}



#endif /* DUNGEONNPCS_H_ */
