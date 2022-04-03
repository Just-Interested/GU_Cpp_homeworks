#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <vector>

class Card{
public:
	enum Suit {SPADES, HEARTS, DIAMONDS, CLUBS};
	enum Rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
               JACK, QUEEN, KING};
	Card();
    
	Card(Rank rank, Suit suit, bool m_IsFaceUp = false);

	void flip();

	int getValue() const;

	void show() const;

private:
	Suit suit;
	Rank rank;
	bool m_IsFaceUp;
};


class Hand{
private:
    std::vector<Card*> m_cards;
public:
    Hand();
    ~Hand();
    void Add(Card* pCard);
    void Clear();
    int GetValue();
};


#endif