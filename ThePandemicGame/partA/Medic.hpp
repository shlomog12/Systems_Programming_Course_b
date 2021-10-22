#include "Player.hpp"

namespace pandemic{
class Medic: public Player{
    private:
    
    public:
        Medic(Board& board, City city):Player(board,city){};
        void set_current_location(City city) override;
        Player& treat(City city) override;
};
}


