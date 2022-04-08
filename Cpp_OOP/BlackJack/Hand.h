#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"

class Hand{
private:
    std::vector<Card*> m_cards;
public:
    ~Hand();
    void Add(Card* pCard);
    void Clear();
    int GetValue() const;
};

#endif