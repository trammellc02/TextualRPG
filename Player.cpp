
#include <iostream>
#include <sstream>
#include "Player.h"


Player::Player() {
    playerName = "";
    characterName = "";
    characterAge = 0;
    characterDesc = "";
}
//setting the variables
Player::Player(std::string playerName, std::string characterName, int characterAge, std::string characterDesc) {
    this->playerName = playerName;
    this->characterName = characterName;
    this->characterAge = characterAge;
    this->characterDesc = characterDesc;
}

CharacterTypes Player::getCharacterType() {
    return CharacterTypes::CharacterType::Generic;
}

bool Player::canPerformAction(PlayerActions anAction) {
    return (anAction.getAction() == PlayerActions::PlayerAction::DoNothing || anAction.getAction() == PlayerActions::PlayerAction::DoAnything);
}

List<PlayerActions>* getPlayerActions() {
    List<PlayerActions>* playerActions = new List<PlayerActions>();
    // create a PlayerActions object (wrapped enum) representing do nothing
    PlayerActions* doNothing = new PlayerActions(PlayerActions::PlayerAction::DoNothing);

    // create                                                    do anything
    PlayerActions* doAnything = new PlayerActions(PlayerActions::PlayerAction::DoAnything);

    // insert into list
    playerActions->insertAtEnd(doAnything);
    playerActions->insertAtEnd(doAnything);

    // return the list pointer
    return playerActions;
}


std::string Player::getPlayerName() {
    return playerName;
}

void Player::setPlayerName(std::string playerName) {
    this->playerName = playerName;
}

std::string Player::getCharacterName() {
    return characterName;
}

void Player::setCharacterName(std::string characterName) {
    this->characterName = characterName;
}

int Player::getCharacterAge() {
    return characterAge;
}

void Player::setCharacterAge(int characterAge) {
    this->characterAge = characterAge;
}

std::string Player::getCharacterDesc() {
    return characterDesc;
}

void Player::setCharacterDesc(std::string characterDesc) {
    this->characterDesc = characterDesc;
}

std::string Player::toString() {
    std::ostringstream stringStream;
    stringStream << "Character Name: " << characterName << std::endl;
    stringStream << "Player Name: " << playerName << std::endl;
    stringStream << "Character Description: " << characterDesc << std::endl;
    stringStream << "Character Type: Generic" << std::endl;
    stringStream << "The Players Actions Are: DoNothing and DoAnything " << std::endl;

    return stringStream.str();
}

