#include "FieldDoctor.hpp"


namespace pandemic{
    

     Player& FieldDoctor::treat(City city){

        if (this->current_location!=city && !this->board.is_nei(current_location,city)){
             throw std::out_of_range("It is not possible to remove an illness from a city where you are not");
        }
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