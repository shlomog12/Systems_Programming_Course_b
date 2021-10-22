


#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <typeinfo>
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <string>
#include <unordered_map>
namespace pandemic{

    
    class Player
    {
    // private:
    protected:
        Board& board;
        City current_location;
        std::unordered_map<City, int> cards;
        std::unordered_map<Color, int> count_cards_color;
        std::string str="";
        virtual void set_current_location(City city);
    public:
        Player(Board &board, City city):board(board),current_location(city){};
        Player& drive(City city);
        virtual Player& fly_direct(City city);
        Player& fly_charter(City city);
        Player& fly_shuttle(City city);
        virtual Player& build();
        virtual Player& discover_cure(Color color);
        virtual Player& treat(City city);
        std::string role() const;
        Player& take_card(City city);
        void Drop_card(City city);
        Board& get_board(){
            return this->board;
        };
        friend std::ostream& operator<< (std::ostream& os,const Player& Player);


    };

    



}

#endif