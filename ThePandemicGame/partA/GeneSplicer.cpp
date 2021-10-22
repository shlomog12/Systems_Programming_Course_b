#include "GeneSplicer.hpp"


namespace pandemic{
    const unsigned int healing_cost=5;
    Player& GeneSplicer::discover_cure(Color color){
        City city=this->current_location;
        
        if (!this->board.is_research_stations(city)){
             throw std::out_of_range("A drug can only be discovered in the city with a research station");
        }
        
        //    ***********Maybe************
        // if (this->board.get_cure(color) ){return *this;}
        
        int all_card=this->count_cards_color[Yellow];
        all_card+=this->count_cards_color[Red];   
        all_card+=this->count_cards_color[Black];
        all_card+=this->count_cards_color[Blue];
        if (all_card<healing_cost){
             throw std::out_of_range("There are not enough cards to heal");
        }
        int count=0;
        for (const auto &card : cards){
            if (count==healing_cost) {break;}
            if (card.second !=0){
                    Drop_card(card.first);
                    count++;
            }
        }
        this->board.get_cure(color)=true;
        return *this; 
   }




 }