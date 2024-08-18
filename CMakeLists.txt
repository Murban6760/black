cmake_minimum_required(VERSION 3.0.0)
project(BlackJack VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(BlackJack BlackJack.cpp CardDeck.cpp Dealer.cpp Agent.cpp Strategy.cpp Player.cpp )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
