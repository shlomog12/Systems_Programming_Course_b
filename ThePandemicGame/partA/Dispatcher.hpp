

#include "Player.hpp"

namespace pandemic{
class Dispatcher : public Player
{
    private:
        
    public:
        Dispatcher(Board& board, City city):Player(board,city){};
        Player& fly_direct(City city) override;
    };

}

