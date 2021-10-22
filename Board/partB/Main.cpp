/**
 * program for message-board exercise.
 * Author: shlomo glick
 * Since : 2021-03
 */

#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {

	ariel::Board board_blank;
	board_blank.show();

	ariel::Board board_little;
	board_little.post(0, 1, Direction::Horizontal, "short short short");
	board_little.post(0, 2, Direction::Vertical, "Little Little");
	board_little.show();

	ariel::Board board;

	board.post(400, 500, Direction::Horizontal, "abcd"); 
    	board.post(401, 503, Direction::Vertical, "shlomo");
    	board.post(403, 502, Direction::Horizontal, "shira");
	board.post(405, 500, Direction::Horizontal, "12345");
	board.post(399, 500, Direction::Horizontal, "ABCD");
    	board.post(398, 500, Direction::Horizontal, "1234");
	board.post(408, 500, Direction::Horizontal, "hello my name is bob");
	board.post(408, 503, Direction::Horizontal, "Successfully!!");
	board.show();

	board.post(394, 514, Direction::Vertical, "this is my program");
	board.post(398, 502, Direction::Vertical, "XXXXXXXXXXX");
	board.show();

	cout <<"\n\nread Horizontal,   line - 405,  col - 497, len - 8:       "<< board.read(405, 497, Direction::Horizontal, 8) <<endl;
	cout <<"\n\nread Vertical,   line - 403,  col - 504, len - 5:         "<< board.read(403, 504, Direction::Vertical, 5) <<endl;
	cout <<"\n\nread Vertical,   line - 397,  col - 501, len - 6:         "<< board.read(397, 501, Direction::Vertical, 6) << endl;

	board.post(350, 580, Direction::Horizontal, "abcd"); 
   	board.post(401, 503, Direction::Vertical, "shlomo");
    	board.post(360,550, Direction::Horizontal, "          /\\        "); 
	board.post(361,550, Direction::Horizontal, "   ______/__\\_____  "); 
	board.post(362,550, Direction::Horizontal, "   \\    /    \\    / ");
	board.post(363,550, Direction::Horizontal, "    \\  /      \\  /  "); 
	board.post(364,550, Direction::Horizontal, "     \\/        \\/   "); 
	board.post(365,550, Direction::Horizontal, "     /\\        /\\   "); 
	board.post(366,550, Direction::Horizontal, "    /__\\______/__\\  "); 
	board.post(367,550, Direction::Horizontal, "        \\   /       ");
	board.post(368,550, Direction::Horizontal, "         \\ /        ");
	
	board.post(386,550, Direction::Horizontal, "                    ");
	board.post(387,550, Direction::Horizontal, "                 )  "); 
	board.post(388,550, Direction::Horizontal, "                (   "); 
	board.post(389,550, Direction::Horizontal, "         / \\    )   ");
	board.post(390,550, Direction::Horizontal, "        /   \\  __   "); 
	board.post(391,550, Direction::Horizontal, "       /     \\|  |  "); 
	board.post(392,550, Direction::Horizontal, "      /       \\  |  "); 
	board.post(393,550, Direction::Horizontal, "     /         \\ |  "); 
	board.post(394,550, Direction::Horizontal, "    /           \\|  ");
	board.post(395,550, Direction::Horizontal, "   /_____________\\  ");
	board.post(396,550, Direction::Horizontal, "   |   _     _   |  ");
	board.post(397,550, Direction::Horizontal, "   |  |_|   |_|  |  "); 
	board.post(398,550, Direction::Horizontal, "   |     ___     |  "); 
	board.post(399,550, Direction::Horizontal, "   |    |   |    |  "); 
	board.post(400,550, Direction::Horizontal, "   |____|___|____|  ");
	board.post(401,550, Direction::Horizontal, "                    "); 
	board.show();


	ariel::Board board2;
	board2.post(10, 0, Direction::Horizontal, "                                                               "); 
	board2.post(11, 0, Direction::Horizontal, "             ##         ##         ##         ##               "); 
	board2.post(12, 0, Direction::Horizontal, "            ####       ####       ####       ####              "); 
	board2.post(13, 0, Direction::Horizontal, "           ######     ######     ######     ######             "); 
	board2.post(14, 0, Direction::Horizontal, "          ########   ########   ########   ########            "); 
	board2.post(15, 0, Direction::Horizontal, "         ########## ########## ########## ##########           "); 
	board2.post(16, 0, Direction::Horizontal, "       ##############################################          "); 
	board2.post(17, 0, Direction::Horizontal, "      #                                              #         "); 
	board2.post(18, 0, Direction::Horizontal, "     #                                                #        "); 
	board2.post(19, 0, Direction::Horizontal, "    #       #########              #########           #       "); 
	board2.post(20, 0, Direction::Horizontal, "    #     #############          #############         #       "); 
	board2.post(21, 0, Direction::Horizontal, "    #     #############          #############         #       "); 
	board2.post(22, 0, Direction::Horizontal, "    #       #########              #########           #       "); 
	board2.post(23, 0, Direction::Horizontal, "    #                                                  #       "); 
	board2.post(24, 0, Direction::Horizontal, "    #                     ##                           #       "); 
	board2.post(25, 0, Direction::Horizontal, "    #                       ##                         #       "); 
	board2.post(26, 0, Direction::Horizontal, "     #                       ##                        #       "); 
	board2.post(27, 0, Direction::Horizontal, "     #                     ##                         #        "); 
	board2.post(28, 0, Direction::Horizontal, "      #                                              #         "); 
	board2.post(29, 0, Direction::Horizontal, "       #                                            #          "); 
	board2.post(30, 0, Direction::Horizontal, "        #          ###################             #           "); 
	board2.post(31, 0, Direction::Horizontal, "         #           ###############              #            "); 
	board2.post(32, 0, Direction::Horizontal, "          #                                      #             "); 
	board2.post(33, 0, Direction::Horizontal, "           #                                    #              "); 
	board2.post(34, 0, Direction::Horizontal, "             #                                #                "); 
	board2.post(35, 0, Direction::Horizontal, "              #  #                        #  #                 "); 
	board2.post(36, 0, Direction::Horizontal, "                  #                     #                      "); 
	board2.post(37, 0, Direction::Horizontal, "                    #                  #                       "); 
	board2.post(38, 0, Direction::Horizontal, "                    #                 #                        ");
	board2.post(39, 0, Direction::Horizontal, "                                                               ");
	board2.show();

}
