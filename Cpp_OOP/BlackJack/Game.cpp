#include "Game.h"
#include "Player.h"
#include "Deck.h"
#include "House.h"
#include <vector>
#include <string>
#include <iostream>
#include <limits>
#include <memory>

Game::Game(std::vector<std::string> players_names){
    for (std::string name : players_names)
        m_players.push_back(std::make_shared<Player>(name));
    m_house = std::make_shared<House>();
    m_deck = std::make_shared<Deck>();
    m_deck->Shuffle();
}

Game::~Game(){
    m_players.clear();
}

void Game::ShowTable() const {
    std::cout << "\n****************** Table ******************" << std::endl;
    for (std::shared_ptr<Player> player : m_players){
        std::cout << *player << std::endl;
    }
    std::cout << *m_house << std::endl;
    std::cout << "*******************************************" << std::endl;
}


void Game::Play(){
    for (std::shared_ptr<Player> player : m_players){
        m_deck->Deal(*player);
        m_deck->Deal(*player);
    }
    m_deck->Deal(*m_house);
    m_deck->Deal(*m_house);
    m_house->FlipFirstCard();
    ShowTable();
    for (std::shared_ptr<Player> player : m_players){
        std::cout << "\nPlayer ";
        m_deck->AdditionalCards(*player);
        std::cout << std::endl;
    }
    m_house->FlipFirstCard();
    ShowTable();
    std::cout << std::endl;
    m_deck->AdditionalCards(*m_house);
    ShowTable();
    std::cout << std::endl;
    std::cout << "Results: " << std::endl;
    for (std::shared_ptr<Player> player : m_players){
        if (player->isBoosted()){
            player->Bust();
            continue;
        }
        if (m_house->isBoosted()){
            player->Win();
            continue;
        }
        if (player->GetValue() > m_house->GetValue())
            player->Win();
        else if (player->GetValue() == m_house->GetValue())
            player->Push();
        else 
            player->Lose();
    }
    m_house->Clear();
    for (std::shared_ptr<Player> player : m_players)
        player->Clear();
    m_deck->Clear();
    m_deck->Populate();
    m_deck->Shuffle(); 
}