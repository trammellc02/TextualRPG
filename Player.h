#pragma once
#include <string>
#include "CharacterTypes.h"
#include "List.h"
#include "PlayerActions.h"

class Player {
public:

    Player();

    Player(std::string playerName, std::string characterName, int characterAge, std::string characterDesc);

    /*
     Returns the character type of this player. For the base class
     Player, the character type should be CharacterType::Generic
     */
    virtual CharacterTypes getCharacterType();

    /*
     Returns true if and only if this player is capable of the specified action.
     For the base class Player this method returns true if and only if the
     specified action is either PlayerAction::DoAnything or PlayerAction::DoNothing.
     */
    virtual bool canPerformAction(PlayerActions anAction);

    /*
    Returns a list of the actions this player is capable of. For
    the base class Player, this method returns a list containing
    two actions: PlayerAction::DoAnything and PlayerAction::doNothing.
    */
    virtual List<PlayerActions>* getPlayerActions();

    //gets and sets players name 
    std::string getPlayerName();
    void setPlayerName(std::string playerName);


    //gets and sets characters name 
    std::string getCharacterName();
    void setCharacterName(std::string characterName);

    //gets and sets character age 
    int getCharacterAge();
    void setCharacterAge(int characterAge);

    //gets and sets character discriptions 
    std::string getCharacterDesc();
    void setCharacterDesc(std::string characterDesc);

    

    virtual std::string toString();

protected:

    std::string playerName;
    std::string characterName;
    int characterAge;
    std::string characterDesc;

    /*
    List to hold the actions this player is capable of.
    */
    List<PlayerActions>* playerActions;

};



