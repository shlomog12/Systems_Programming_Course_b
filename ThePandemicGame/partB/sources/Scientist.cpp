
#include "Scientist.hpp"


namespace pandemic{

    Player& Scientist::discover_cure(Color color){
        City city=this->current_location;
        if (!this->board.is_research_stations(city)){
             throw std::out_of_range("A drug can only be discovered in the city with a research station");
        }
        int healing_cost2=this->n;
        if (this->count_cards_color[color]<healing_cost2){
            throw std::out_of_range("There are not enough cards to heal");
            }
        int count=0;
        for (const auto &card : cards){
            if (count==healing_cost2) {break;}
            if (card.second !=0 && this->board.get_color(card.first)==color){
                    Drop_card(card.first);
                    count++;
            }
        }
        this->board.get_cure(color)=true;
        return *this; 
    }
    
    
    //     if (this->count_cards_color[color]<healing_cost){
    //          throw std::out_of_range("There are not enough cards to heal");
    //         };
    //     int count=0;
    //     for (const auto &card : cards){
    //         if (count==healing_cost) {break;}
    //         if (card.second !=0 && this->board.get_color(card.first)==color){
    //                 Drop_card(card.first);
    //                 count++;
    //         }
    //     }
    //     this->board.get_cure(color)=true;
    //     return *this; 
    // }

 }