#include "Virologist.hpp"


namespace pandemic{

    Player& Virologist::treat(City city){
        if(this->board.get_level(city)==0){
             throw std::out_of_range("It is not possible to lower a disease cube below 0");
        }
        Color color=this->board.get_color(city);
        if (this->board.get_cure(color)){
            this->board.get_level(city)=0;
        }else{
            this->board.get_level(city)--;
        }  
        return *this;
    }
 }