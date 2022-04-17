#ifndef CARD_H
#define CARD_H

#include <iostream>

class Card{
public:
	enum Suit {SPADES, HEARTS, DIAMONDS, CLUBS};
	enum Rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
               JACK, QUEEN, KING};
	Card();
    
	Card(Rank rank, Suit suit, bool m_IsFaceUp = false);

	void flip();

	int getValue() const;

	friend std::ostream& operator<<(std::ostream& os, const Card& rCard);

private:
	Suit suit;
	Rank rank;
	bool m_IsFaceUp;
};


#endif