#include "Player.hpp"

namespace pandemic{
class FieldDoctor: public Player
{
    private:
    
    public:
        FieldDoctor(Board &board, City city):Player(board,city){};
        Player& treat(City city) override;

};
}

