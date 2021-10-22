

#include "Player.hpp"
#include <stdexcept>
#include <string.h>
#include <stdio.h>

 namespace pandemic{
    const unsigned int healing_cost=5;
    Player& Player::drive(City city){
        City c2=this->current_location;
        if (this->board.is_nei(city,c2)){
            this->set_current_location(city);
        }else{
            throw std::out_of_range("Tried to move between cities that are not neighbors");
        }
        return *this;
    }
    Player& Player::fly_charter(City city){
        City c1= this->current_location;
        if (this->cards[c1] ==0){
             throw std::out_of_range("It is not possible to fly with -fly_charter- without the current city card");
        }
        Drop_card(c1);
        this->set_current_location(city);
        return *this;
    }
    Player& Player::fly_shuttle(City city){
        City cur=this->current_location;	
        if (!this->board.is_research_stations(cur) || !this->board.is_research_stations(city)){
             throw std::out_of_range("You can fly - fly_shuttle - only between two cities that both have a research station");
        }
        this->set_current_location(city);
        return *this;
    } 
    Player& Player::fly_direct(City city){
        if (this->cards[city] !=0){
            Drop_card(city);
            this->set_current_location(city);
        }else{
             throw std::out_of_range("It is not possible to fly to the city without the appropriate ticket");
        }
        return *this;
    }  
    Player& Player::build(){
        City c1= this->current_location;
        if (this->cards[c1] ==0){
             throw std::out_of_range("It is impossible to build a research station without the card of the current city");
        }
        if (!this->board.is_research_stations(c1)){
            Drop_card(c1);
        } 
        this->board.is_research_stations(c1)=true;
        return *this;
    }
    Player& Player::discover_cure(Color color){  
        City city=this->current_location;
        if (!this->board.is_research_stations(city)){
             throw std::out_of_range("A drug can only be discovered in the city with a research station");
        }
        if (this->count_cards_color[color]<healing_cost){
             throw std::out_of_range("There are not enough cards to heal");
            };
        int count=0;
        for (const auto &card : cards){
            if (count==healing_cost) {break;}
            if (card.second !=0 && this->board.get_color(card.first)==color){
                    Drop_card(card.first);
                    count++;
            }
        }
        this->board.get_cure(color)=true;
        return *this; 
    }
    Player& Player::treat(City city){
        if (this->current_location!=city){
             throw std::out_of_range("It is not possible to remove an illness from a city where you are not");
        }
        if(this->board.get_level(city)==0){
            throw std::out_of_range("It is not possible to lower a disease cube below 0");
        }
        Color color=this->board.get_color(city);
        // std::cout << color << " #$this . " << this->board.get_cure(color) << std::endl;
        if (this->board.get_cure(color)){
            this->board.get_level(city)=0;
        }else{
            this->board.get_level(city)--;
        }  
        return *this;
    }
    std::string Player::role() const{
        const unsigned int len_of_shit=12;
        std::string str=typeid(*this).name();
        if ('0' > str.at(len_of_shit-1) || str.at(len_of_shit-1) > '9'){
             str=str.substr(len_of_shit-1);
        }else{
            str=str.substr(len_of_shit);
        }

        unsigned long x=str.length()-1;
        str=str.substr(0,x);
        
        return  str;
    }
    Player& Player::take_card(City city){
        if (this->cards[city] ==0){
            this->cards[city]++;     
            Color color=this->board.get_color(city);
            this->count_cards_color[color]++;
        }
        return *this;
    }
    void Player::Drop_card(City city){
        this->cards[city]--;
        Color color=this->board.get_color(city);
        this->count_cards_color[color]--; 
    }
    void Player::set_current_location(City city){
        this->current_location=city;
    }
    std::ostream& operator<< (std::ostream& os,const Player& player){
        os  <<"***************MY PLAYER:********************"<< std::endl;
        os  << "type: " << player.role() << std::endl;
        os  << "current location: " << Board::get_name(player.current_location) << std::endl;
        os  << "my cards: " <<  std::endl;

        for (const auto &card : player.cards){
            if (card.second!=0){
                City city=card.first;
                Color color =player.board.get_color(city);
                os << "     City: " << Board::get_name(city);
                os << "  Color:" << Board::get_name(color) <<std::endl; 

            }
        }  
        return os;            
    }
 
 
 }