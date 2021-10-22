#include "Player.hpp"
namespace pandemic{

class GeneSplicer: public Player
{
    private:
        /* data */
    public:
        GeneSplicer(Board& board, City city):Player(board,city){};
        Player& discover_cure(Color color) override;
};

}


