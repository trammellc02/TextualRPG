#include "PlayerActions.h"

PlayerActions::PlayerActions() {
	this->theAction = PlayerActions::PlayerAction::DoNothing;
}

PlayerActions::PlayerActions(PlayerAction action) {
	this->theAction = action;
}

PlayerActions::PlayerActions(std::string actionString) {
	int matchingK;
	for (int k = 0; k < 48; k++) {
		if (actionNames[k] == actionString) {
		matchingK = k;
		this->theAction = static_cast<PlayerAction>(matchingK);
		break;
		}
	}
	
}

PlayerActions::PlayerAction PlayerActions::getAction() {
	return this->theAction;
}

std::string PlayerActions::toString() {

	return this->actionNames[static_cast<int>(theAction)];
}