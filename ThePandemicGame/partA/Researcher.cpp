#include "Researcher.hpp"


namespace pandemic{



    const unsigned int healing_cost=5;
    Player& Researcher::discover_cure(Color color){

        //    ***********Maybe************
        // if (this->board.get_cure(color) ){return *this;}

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


 }