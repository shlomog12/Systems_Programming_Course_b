
#include "Medic.hpp"


namespace pandemic{
    Player& Medic::treat(City city){
        if (this->current_location!=city){
             throw std::out_of_range("It is not possible to remove an illness from a city where you are not");
        }
        if(this->board.get_level(city)==0){
             throw std::out_of_range("It is not possible to lower a disease cube below 0");
        }
            this->board.get_level(city)=0;
        return *this;
    }
    void Medic::set_current_location(City city){
        Color color= this->board.get_color(city);
        if (this->board.get_cure(color)){
            board.get_level(city)=0;
        }
        this->current_location=city;
    }

}