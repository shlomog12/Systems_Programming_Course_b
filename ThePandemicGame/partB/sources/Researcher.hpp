#include "Player.hpp"

namespace pandemic{
class Researcher: public Player
{
private:
    /* data */
public:
    Researcher(Board& board, City city):Player(board,city){};
    Player& discover_cure(Color color) override;
};

}

