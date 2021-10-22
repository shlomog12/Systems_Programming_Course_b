#include "Virologist.hpp"


namespace pandemic{

    Player& Virologist::treat(City city){
        // if(this->board.get_level(city)==0){
        //      throw std::out_of_range("It is not possible to lower a disease cube below 0");
        // }
        Color color=this->board.get_color(city);
        // std::cout << *this << std::endl;
        // std::cout << city << std::endl;
        if (!this->board.get_cure(color)){



            if (this->cards[city]<=0 && city!=this->current_location){
             throw std::out_of_range("You can not throw a card I do not have");
            }


            this->Drop_card(city);
            this->board.get_level(city)--;
        }else{
            this->board.get_level(city)=0;
        }  
        return *this;
    }
 }