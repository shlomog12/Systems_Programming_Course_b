#include "Player.hpp"


namespace pandemic{
class OperationsExpert: public Player
{
    private:
        
    public:
        OperationsExpert(Board &board, City city):Player(board,city){};
        Player& build() override;
};




}