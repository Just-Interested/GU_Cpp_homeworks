#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H

#include <string>
#include "Hand.h"

class GenericPlayer : public Hand {
protected:
	std::string name = "";
public:
	GenericPlayer(const std::string& name) : name(name) {}
	virtual ~GenericPlayer(){};
	virtual bool isHitting() const = 0;
	bool isBoosted() const;
	void Bust() const;
	friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);
};

#endif