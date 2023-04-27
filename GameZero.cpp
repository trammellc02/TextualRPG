#include <random>
#include <sstream>

#include "GameZero.h"
#include "Vertex.h"

GameZero::GameZero() {
	this->thePlayer = new Player();
	this->theGraph = nullptr;

	//build the game graph
	this->buildGameGraph();

	//get plater information
	this->getUserInfo();

	std::cout << thePlayer->toString() << std::endl;
}

GameZero::GameZero(Player* Player) {
	this->thePlayer = Player;
	this->theGraph = nullptr;
	this->buildGameGraph();

	std::cout << thePlayer->toString() << std::endl;

}

void GameZero::startGame() {
	this->printVertexData();
	this->simulateFight();
}

void GameZero::endGame() {
	std::cout<< "See ya!" << std::endl;
	std::exit(0);
}

std::string GameZero::toString() {
	std::ostringstream sout;
	sout << "GameZero at " << this << std::endl;
	sout << "Player info: " << std::endl;
	sout << this->thePlayer->toString();
	sout << " " << std::endl;
	sout << "Story in the dragon Lair: " << std::endl;//
	//get a pointer to the list of strings stored in vertex 0
	
	List<std::string>* storyList = this->theGraph->getVertexData(0);
	for (int k= 0; k<storyList->getSize(); k++)	{
		//get item k from the list
		std::string* item = storyList->peek(k);
		sout << *item << std::endl;
	}//
	return sout.str();
}

void GameZero::getUserInfo() {

	//get player name 
	std::cout << "enter your real name: " << std::endl;
	std::string playerName = getUserResponse();
	this->thePlayer->setPlayerName(playerName);

	//get character name 
	std::cout << "enter your characters name: " << std::endl;
	std::string characterName = getUserResponse();
	this->thePlayer->setCharacterName(characterName);

	//get character age
	std::cout << "how old is your character? " << std::endl;
	std::string charAgeStr = getUserResponse();
	try {
		int charAge = std::stoi(charAgeStr);
		this->thePlayer->setCharacterAge(charAge);
	}
	catch (const std::exception e) {
		std::cout << e.what() << std::endl;
		//set characters age to 30
		std::cout << "invalid age string. Setting characters age to 30." << std::endl;
		this->thePlayer->setCharacterAge(30);
	}
	
	
	//get character discription 
	std::cout << "enter a breif descritiption of your character." << std::endl;
	std::cout << " ";
	std::string charDescription = getUserResponse();
	this->thePlayer->setCharacterDesc(charDescription);
}

std::string GameZero::getUserResponse() {
	std::string result = "";
	//allow the user to respond catch the response using getline 
	
	std::getline(std::cin, result);
	if (result == "exit") {
		std::cout << "Loser you quit too soon" << std::endl;
		this->endGame();

	}
	else {
		return result;
	}
}

void GameZero::buildGameGraph() {
	this->theGraph = new Graph <List<std::string>, List<std::string>>();
	//add a single certex
	Vertex<List<std::string>>*dragonLair = new Vertex<List<std::string>>();
	this->theGraph->addVertex(dragonLair);
	//add some string data to describe the story that occurs in the dragon lair 
	List<std::string>* storyList = new List<std::string>();
	//add some strings to the list 
	storyList->insertAtEnd(new std::string(" You awaken in a dark underground hall, better get up!"));
	
	storyList->insertAtEnd(new std::string(" I dont know if its just me but I swear I hear a Dragon, I dont know though might just be me."));
	
	storyList->insertAtEnd(new std::string(" 'You continue to walk and find a big pile of gold all by itself'"));

	storyList->insertAtEnd(new std::string(" You know these usally have dragons on them but maybe thats just a myth"));

	storyList->insertAtEnd(new std::string(" 'You hear a loud dragon breath that shakes the pillars and walls around you'"));

	storyList->insertAtEnd(new std::string(" I told you these had dragons onn them so what are we going to do fight or run"));

	storyList->insertAtEnd(new std::string(" Looks like you dont have a choice fire ghosts are coming out of its mouth, did not know that was a thing"));
	
	
	

	//store the list in the vertex of this graph
	this->theGraph->storeInVertex(storyList, 0);
}

/*
	 Prints the string data stored in the vertex of the game graph. The method
	 should print one string at a time, then accept user input, then print the
	 next string, and so on, until no more strings are left to print.
	 */
void GameZero::printVertexData() {
	std::cout << "Story in the dragon Lair: " << std::endl;
	//get a pointer to the list of strings stored in vertex 0

	List<std::string>* storyList = this->theGraph->getVertexData(0);
	for (int k = 0; k < storyList->getSize(); k++) {
		//get item k from the list
		std::string* item = storyList->peek(k);
		std::cout << *item << std::endl;
		this->getUserResponse();
	}//
}

void GameZero::simulateFight() {

	//std::cout << "This is the SimulateFight() working! " << std::endl;

	//build a continus random number generator 
	std::random_device r;
	std::default_random_engine engn(r());
	std::uniform_real_distribution<double> prng(0.0, 1.0);

	double randVal = prng(engn);
	//std::cout << " random value from (0,1): " << randVal << std::endl;

	//set up players vitality hit point values and hit probabilty 
	int playerVitality = 100;
	int playerDamagePerHit = 10;
	double playerHitProbibilty = .9;

	// set up the ghosts vitality hit points and hit probabilities 
	int ghostsVitality[3] = { 30, 30, 30 };
	int ghostDamagePerHit = 5;
	double ghostHitProbibility = 0.3;

	//round counter 
	int roundNumber = 1;

	//Main simulatioon loop
	while (playerVitality > 0){
		std::cout << "simulateFight Round: " << roundNumber << std::endl;

		//for each ghost remains alive, check (a) if the player blow
		// lands on a the ghost. 
		//(B) if the ghosts blow lands on the player 
		for (int k = 0; k < 3; k++) {
			if (ghostsVitality[k] > 0) {
				//check if player lands on blow on the ghost if so update
				// vitality points for the ghost, and print a message to the console
				double randVal = prng(engn);
				if (randVal <= playerHitProbibilty) {
					//demcremnt vitality points 
					ghostsVitality[k] -= ghostDamagePerHit;
					std::cout << "Player lands hit on ghosts " << k << ", vitality is now " << ghostsVitality[k] << std::endl;
					this->getUserResponse();
				}
				//if ghost k is still alive let them try to land a blow on the player 
				if (ghostsVitality[k] > 0) {
					//check if ghost  k lands a blow on the player if so update points adn print a message 
					randVal = prng(engn);
					if (randVal <= ghostHitProbibility) {
						//decrement the platers health 
						playerVitality -= playerDamagePerHit;
						std::cout << "Ghost " << k << " lands a hit on player, vitality is now " << playerVitality << std::endl;
						this->getUserResponse();
						if (playerVitality <= 0) {
							std::cout << "Player is dead: Vitality score is " << playerVitality << std::endl;
							this->getUserResponse();
							this->endGame();
						}
					}
				}
			}
		}
		//Check to see if any ghosts remian alive if not the player has won 
		if (ghostsVitality[0] <= 0 && ghostsVitality[1] <= 0 && ghostsVitality[2] <= 0) {
			std::cout << "Player wins all ghosts are dead!" << std::endl;
			this->endGame();
		}
		//Increament roundNumber
		roundNumber++;

	}


	
}