cmake_minimum_required(VERSION 2.8.12) 
									
project(BlackJack)				

set(SOURCE main.cpp Card.cpp GenericPlayer.cpp Hand.cpp Player.cpp House.cpp Deck.cpp Game.cpp)

include_directories(include)								

add_executable(main ${SOURCE})		