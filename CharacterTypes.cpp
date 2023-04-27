#include "CharacterTypes.h"







CharacterTypes::CharacterTypes() {
	this->theType = CharacterTypes::CharacterType::Unknown;
}

CharacterTypes::CharacterTypes(CharacterTypes::CharacterType type) {
	this->theType = type;
}


CharacterTypes::CharacterType CharacterTypes::getType() {
	return this->theType;
}


std::string CharacterTypes::toString() {

	return this->typeNames[static_cast<int>(theType)];
}
