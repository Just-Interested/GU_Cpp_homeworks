#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H

#include <string>
#include "Hand.h"

class GenericPlayer : public Hand {
private:
	std::string name = "";
public:
	GenericPlayer(std::string name) : name(name) {}
	virtual bool isHitting() = 0;
	bool isBoosted() const;
	void Bust() const;
};

#endif