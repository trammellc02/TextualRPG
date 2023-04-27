#include<sstream>
#include "Paladin.h"


//defult construcutor

Paladin::Paladin() {
	this->playerName = "Unnamed Player";
	this->characterName = "Unnamed Character";
	this->characterAge = 0;
	this->characterDesc = "No description available";
	//Creat the list of players actions that a paladin is capable of
	this->playerActions = new List<PlayerActions>();
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::Fight));
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::SwordFight));
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::CastSpell));
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::RideHorse));
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::PutOnArmor));
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::TakeOffArmor));
}

//second constructor 
Paladin::Paladin(std::string playerName, std::string characterName, int characterAge) {
	this->playerName = playerName;
	this->characterName = characterName;
	this->characterAge = characterAge;
	this->characterDesc = "No description available";
	//Creat the list of players actions that a paladin is capable of
	this->playerActions = new List<PlayerActions>();
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::Fight));
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::SwordFight));
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::CastSpell));
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::RideHorse));
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::PutOnArmor));
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::TakeOffArmor));
}

CharacterTypes Paladin::getCharacterType() {
	CharacterTypes* result = new CharacterTypes(CharacterTypes::CharacterType::Paladin);
	return *result;
}

List<PlayerActions>* Paladin::getPlayerActions() {
	return this->playerActions;
}


bool Paladin::canPerformAction(PlayerActions anAction) {
	bool result = false;
	for (int k = 0; k < this->playerActions->getSize(); k++) {
		PlayerActions* actionK = this->playerActions->peek(k);
		if (anAction == *actionK) {
			result = true;
			break;
		}
	}
	return result = false;
}

void Paladin::fight() {
	std::cout << "Get that sword up big dawg" << std::endl;
}

std::string Paladin::toString() {
	std::ostringstream sout;
	sout << "Character Name: " << characterName << std::endl;
	sout << "Player Name: " << playerName << std::endl;
	sout << "Character Description: " << characterDesc << std::endl;
	sout << "Character Type: Generic" << std::endl;
	sout << "The Players Actions Are: DoNothing and DoAnything " << std::endl;

	sout << "Character Type: P"<<std::endl;

	return sout.str();
}