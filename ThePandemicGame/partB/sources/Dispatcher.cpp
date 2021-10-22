
#include "Dispatcher.hpp"


namespace pandemic{
    Player& Dispatcher::fly_direct(City city){
        City cur=this->current_location;
        if (cur==city ) {
             throw std::out_of_range("Can not fly from city to city");
        }	

        if (this->board.is_research_stations(cur)){
            this->set_current_location(city);
            return *this;
        }
        if (this->cards[city] ==0){
            throw std::out_of_range("It is not possible to fly to the city without the appropriate ticket");
        }
        Drop_card(city);
        this->set_current_location(city);
        return *this;
    }
 }

 