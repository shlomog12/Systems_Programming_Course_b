#include "doctest.h"
#include "Board.hpp"
#include "Player.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"
#include <vector>
using namespace pandemic;
using namespace std;

void build_by_anonimus_OperationsExpert(Board& board,City city){
    OperationsExpert operationsExpert(board,city);
    operationsExpert.build();
}
void take_four_Black_cards(Player& player) {
    player.take_card(City::Algiers)
        .take_card(City::Baghdad)
        .take_card(City::Cairo)
        .take_card(City::Chennai);
}
void take_five_Black_cards(Player& player) {
	take_four_Black_cards(player);
    player.take_card(City::Istanbul);
}
void take_Blue_card(Player& player) {
    player.take_card(City::Madrid);
}
void take_two_Yellow_cards(Player& player){
    player.take_card(City::SaoPaulo)
        .take_card(City::Bogota);
}
void take_three_Yellow_cards(Player& player){
    take_two_Yellow_cards(player);
    player.take_card(City::BuenosAires);
}
void take_four_Yellow_cards(Player& player){
    take_three_Yellow_cards(player);
    player.take_card(City::Johannesburg);
} 
void take_five_Yellow_cards(Player& player){
    take_four_Yellow_cards(player);
    player.take_card(City::Khartoum);
}
void discover_yellow_cure(Board& board){
    Researcher researcher(board,City::Algiers);
    take_five_Yellow_cards(researcher);
    researcher.discover_cure(Color::Yellow);
}
void check_discover_cure_for_Scientist(Board& board){
    Scientist scientist_n_2_is_research_stations(board,City::Algiers,2);
    Scientist scientist_n_3_is_research_stations(board,City::Algiers,3);
    Scientist scientist_n_4_is_research_stations(board,City::Algiers,4);
    take_two_Yellow_cards(scientist_n_2_is_research_stations);
    take_two_Yellow_cards(scientist_n_3_is_research_stations);
    take_two_Yellow_cards(scientist_n_4_is_research_stations);
    CHECK_NOTHROW(scientist_n_2_is_research_stations.discover_cure(Color::Yellow));
    CHECK_THROWS(scientist_n_3_is_research_stations.discover_cure(Color::Yellow));
    CHECK_THROWS(scientist_n_4_is_research_stations.discover_cure(Color::Yellow));
    take_Blue_card(scientist_n_3_is_research_stations);
    take_Blue_card(scientist_n_4_is_research_stations);
    CHECK_THROWS(scientist_n_3_is_research_stations.discover_cure(Color::Yellow));
    CHECK_THROWS(scientist_n_4_is_research_stations.discover_cure(Color::Yellow));
    take_three_Yellow_cards(scientist_n_3_is_research_stations);
    take_three_Yellow_cards(scientist_n_4_is_research_stations);
    CHECK_NOTHROW(scientist_n_3_is_research_stations.discover_cure(Color::Yellow));
    CHECK_THROWS(scientist_n_4_is_research_stations.discover_cure(Color::Yellow));
    take_four_Yellow_cards(scientist_n_4_is_research_stations);
    CHECK_NOTHROW(scientist_n_4_is_research_stations.discover_cure(Color::Yellow));
    Scientist scientist_n_2_is_not_research_stations(board,City::London,2);
    Scientist scientist_n_3_is_not_research_stations(board,City::London,3);
    Scientist scientist_n_4_is_not_research_stations(board,City::London,4);
    take_five_Yellow_cards(scientist_n_2_is_not_research_stations);
    take_five_Yellow_cards(scientist_n_2_is_not_research_stations);
    take_five_Yellow_cards(scientist_n_2_is_not_research_stations);
    CHECK_THROWS(scientist_n_2_is_not_research_stations.discover_cure(Color::Yellow));
    CHECK_THROWS(scientist_n_3_is_not_research_stations.discover_cure(Color::Yellow));
    CHECK_THROWS(scientist_n_4_is_not_research_stations.discover_cure(Color::Yellow));
}

void check_drive(Player* player){
    CHECK_THROWS(player->drive(City::Chicago));
    CHECK_NOTHROW(player->drive(City::Madrid));
    CHECK_THROWS(player->drive(City::SanFrancisco));
    CHECK_THROWS(player->drive(City::Essen));
    CHECK_NOTHROW(player->drive(City::London));
    CHECK_NOTHROW(player->drive(City::Madrid));
    CHECK_NOTHROW(player->drive(City::Algiers));
}
void check_fly_direct(Player* player,Board& board){
    build_by_anonimus_OperationsExpert(board,City::Algiers);
    if (player->role()=="Dispatcher"){
        CHECK_NOTHROW(player->fly_direct(City::NewYork));  //There is a research station in Algiers
    }
    CHECK_THROWS(player->fly_direct(City::Tokyo));
    CHECK_THROWS(player->fly_direct(City::Paris));
    player->take_card(City::Cairo).take_card(City::Tokyo).take_card(City::Algiers);
    CHECK_NOTHROW(player->fly_direct(City::Tokyo));
    CHECK_THROWS(player->fly_direct(City::Paris));
    CHECK_THROWS(player->fly_direct(City::Tokyo));
    CHECK_NOTHROW(player->fly_direct(City::Cairo));
    CHECK_NOTHROW(player->fly_direct(City::Algiers));
}
void check_fly_charter(Player* player){
    CHECK_THROWS(player->fly_charter(City::Tokyo));
    CHECK_THROWS(player->fly_charter(City::Paris));
    player->take_card(City::Tokyo);
    CHECK_THROWS(player->fly_charter(City::Tokyo));
    player->take_card(City::Algiers);
    CHECK_NOTHROW(player->fly_charter(City::Tokyo));
    CHECK_NOTHROW(player->fly_charter(City::Algiers));
    CHECK_THROWS(player->fly_charter(City::Tokyo));
}
void check_fly_shuttle(Player* player,Board& board){
    build_by_anonimus_OperationsExpert(board,City::Madrid);
    build_by_anonimus_OperationsExpert(board,City::Istanbul);
    player->drive(City::Madrid).drive(City::Paris);
    CHECK_THROWS(player->fly_shuttle(City::NewYork));
    CHECK_THROWS(player->fly_shuttle(City::Istanbul));
    player->drive(City::Madrid);
    CHECK_THROWS(player->fly_shuttle(City::NewYork));
    CHECK_NOTHROW(player->fly_shuttle(City::Istanbul));
    player->drive(City::Algiers);
}
void check_build(Player* player){
    player->drive(City::Madrid);
    if (player->role()=="OperationsExpert"){
        CHECK_NOTHROW(player->build());
        player->take_card(City::SaoPaulo);
        CHECK_NOTHROW(player->build());
    }else{
        CHECK_THROWS(player->build());
        player->take_card(City::SaoPaulo);
        CHECK_THROWS(player->build());
    }
    player->take_card(City::Madrid);
    CHECK_NOTHROW(player->build());
    player->drive(City::Algiers);
}
void check_discover_cure(Player* player,Board& board){
    build_by_anonimus_OperationsExpert(board,City::Algiers);
    if (player->role()=="Scientist"){
        check_discover_cure_for_Scientist(board);   
    }
    CHECK_THROWS(player->discover_cure(Color::Black));
    CHECK_THROWS(player->discover_cure(Color::Red));
    take_four_Black_cards(*player);
    take_Blue_card(*player);
    if (player->role()=="GeneSplicer"){
        CHECK_NOTHROW(player->discover_cure(Color::Red));
    }
    CHECK_THROWS(player->discover_cure(Color::Black));
    CHECK_THROWS(player->discover_cure(Color::Red));
    take_five_Black_cards(*player);
    CHECK_NOTHROW(player->discover_cure(Color::Black));
    CHECK_THROWS(player->discover_cure(Color::Red));
    player->drive(City::Paris);
    CHECK_THROWS(player->discover_cure(Color::Yellow));
    CHECK_THROWS(player->discover_cure(Color::Blue));;
    take_five_Yellow_cards(*player);
    CHECK_THROWS(player->discover_cure(Color::Red));
    if (player->role()=="Researcher"){
        CHECK_NOTHROW(player->discover_cure(Color::Yellow)); 
    }else{
        CHECK_THROWS(player->discover_cure(Color::Yellow));
    }
}
void check_treat(Player* player,Board& board){
    board.remove_cures();
    player->drive(City::Madrid);
    board[City::Kinshasa] = 3;
    if (player->role()!="Virologist"){
        CHECK_THROWS(player->treat(City::Kinshasa)); 
    }
    if (player->role()=="FieldDoctor"){
        board[City::London] = 3;
        CHECK_NOTHROW(player->treat(City::London));
        CHECK_EQ(board[City::London],2);
    }
    board[City::Madrid] = 3;
    player->treat(City::Madrid);
    if (player->role()=="Medic"){
        CHECK_EQ(board[City::Madrid],0);
        CHECK_THROWS(player->treat(City::Madrid));
        board[City::Khartoum] = 5;
        board[City::Kinshasa] = 5;
        board[City::Miami] = 4;
        board[City::Santiago] = 4;
        discover_yellow_cure(board);
        CHECK_EQ(board[City::Khartoum],5);
        player->take_card(City::Khartoum);
        player->fly_direct(City::Khartoum);
        CHECK_EQ(board[City::Khartoum],0);
        CHECK_EQ(board[City::Kinshasa],5);
        player->drive(City::Kinshasa);
        CHECK_EQ(board[City::Kinshasa],0);
        CHECK_EQ(board[City::Miami],4);
        player->take_card(City::Kinshasa);
        player->fly_charter(City::Miami);
        CHECK_EQ(board[City::Miami],0);
        build_by_anonimus_OperationsExpert(board,City::Miami);
        build_by_anonimus_OperationsExpert(board,City::Santiago);
        CHECK_EQ(board[City::Santiago],4);
        player->fly_shuttle(City::Santiago);
        CHECK_EQ(board[City::Santiago],0);
        return;
    }
    CHECK_EQ(board[City::Madrid],2);
    player->treat(City::Madrid).treat(City::Madrid);
    CHECK_EQ(board[City::Madrid],0);
    CHECK_THROWS(player->treat(City::Madrid));
    player->take_card(City::Khartoum);
    player->fly_direct(City::Khartoum);
    board[City::Khartoum] = 5; 
    discover_yellow_cure(board);
    player->treat(City::Khartoum);
    CHECK_EQ(board[City::Khartoum],0);
    player->drive(City::Kinshasa);
    board[City::Kinshasa] = 5;
    player->treat(City::Kinshasa);
    CHECK_EQ(board[City::Kinshasa],0);   
}  
/**
 * Tests all the functions of the players
 * note:In all tests, starting location - Algiers
 * 
 * ------------Neighborhood map for tests------------------
 * Algiers -> Madrid, Paris, Istanbul, Cairo
 * Madrid -> London, NewYork, Paris, SaoPaulo, Algiers
 * NewYork -> Montreal Washington London Madrid
 * */ 
void check(Player* player,Board& board){
    check_drive(player);
    check_fly_direct(player,board);
    check_fly_charter(player);
    check_fly_shuttle(player,board);
    check_build(player);
    check_discover_cure(player,board);
    check_treat(player,board);
}
    
TEST_CASE("test to board"){
    Board board;
    CHECK(board.is_clean());
    board[City::HongKong] = 2;
    CHECK_FALSE(board.is_clean());
    CHECK_EQ(board[City::HongKong],2);
    board[City::Paris] = 5;
    board[City::Paris] = 4;
    CHECK_EQ(board[City::Paris],4);
    board[City::Paris] = 0;
    board[City::HongKong] = 0;
    CHECK(board.is_clean());
}
TEST_CASE("test to players") {
    Board board;
    City city=City::Algiers;
    Player player(board,city);
    OperationsExpert operationsExpert(board,city);
    Dispatcher dispatcher(board,city);
    Scientist scientist(board,city,5);
    Researcher researcher(board,city);
    Medic medic(board,city);
    Virologist virologist(board,city);
    GeneSplicer geneSplicer(board,city);
    FieldDoctor fieldDoctor(board,city);
    CHECK(player.role()=="Player");
    CHECK(operationsExpert.role()=="OperationsExpert");
    CHECK(dispatcher.role()=="Dispatcher");
    CHECK(scientist.role()=="Scientist");
    CHECK(researcher.role()=="Researcher");
    CHECK(medic.role()=="Medic");
    CHECK(virologist.role()=="Virologist");
    CHECK(geneSplicer.role()=="GeneSplicer");
    CHECK(fieldDoctor.role()=="FieldDoctor");
    vector<Player*> players; 
    players.push_back(&player);
    players.push_back(&operationsExpert);
    players.push_back(&dispatcher);
    players.push_back(&scientist);
    players.push_back(&researcher);
    players.push_back(&medic);
    players.push_back(&virologist);
    players.push_back(&geneSplicer);
    players.push_back(&fieldDoctor);
    for (auto i = players.begin(); i != players.end(); ++i){
        check(*i,board);
    }
}
