#include "Deck.h"
#include "Card.h"
#include "Hand.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <vector>

Deck::Deck(){
    Populate();
}


void Deck::Populate(){
    for (int s = Card::SPADES; s < (Card::CLUBS + 1); s++)
        for (int r = Card::ACE; r < (Card::KING + 1); r++)
            Add(new Card(static_cast<Card::Rank>(r), static_cast<Card::Suit>(s)));
}


void Deck::Shuffle(){
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(m_cards.begin(), m_cards.end(), g);
}


void Deck::Deal(Hand& hand){
    if (!m_cards.empty()){
        hand.Add(m_cards.back());
        m_cards.pop_back();
    }
}


void Deck::AdditionalCards(GenericPlayer& aGenericPlayer){
    std::cout << aGenericPlayer;
    while (aGenericPlayer.isHitting()){
        Deal(aGenericPlayer);
        std::cout << aGenericPlayer;  
    }
}
