
#include "OperationsExpert.hpp"


namespace pandemic{

    Player& OperationsExpert::build(){
        
        City c1= this->current_location;
        this->board.is_research_stations(c1)=true;
        return *this;
    }


 }