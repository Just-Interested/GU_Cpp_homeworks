#ifndef BLACKJACK_GAME_H
#define BLACKJACK_GAME_H

#include "Deck.h"
#include "Player.h"
#include "House.h"
#include <vector>
#include <memory>

class Game{
private:
    std::shared_ptr<Deck> m_deck;
    std::shared_ptr<House> m_house;
    std::vector<std::shared_ptr<Player>> m_players;
public:
    Game(std::vector<std::string> players_names);
    ~Game();
    void Play();
    void ShowTable() const;
    bool Again() const;
};


#endif