/**
 * This is an implementation for the "Board" class that represents a bulletin board.
 * Author: Shlomo Glick
 * Since : 2021-03
*/

#include "Board.hpp"
using namespace std;
const int COUNTING_BASE = 10;

namespace {
    
    unsigned int get_number_of_digits(unsigned int num){
        if (num==0){
            return 1;
        }
        unsigned int ans=0;
        while (num>0){
            ans++;
            num/=COUNTING_BASE;
        }
        return ans;
    }
    unsigned int length_of_inclusive_range(const unsigned int &max, const unsigned int &min){
        return max-min+1;
    }
    unsigned int number_of_spaces_before_the_board(const unsigned int &dis_to_begin_board, const unsigned int &num) {
        return dis_to_begin_board-get_number_of_digits(num);
    }
}

namespace ariel{

    void Board::update_min_column(const unsigned int &col){
        this->min_col=min( this->min_col, col);
    }
    void Board::update_max_column(const unsigned int &col_last_of_current){
        this->max_col=max(col_last_of_current, this->max_col);
    }
    void Board::update_min_row(const unsigned int &row){
         this->min_row=min(row, this->min_row);
    }
    void Board::update_max_row(const unsigned int &row_last_of_current){
        this->max_row =max(row_last_of_current, this->max_row);
    }
    
    void Board::horizontal_size_update(const unsigned int &row, const unsigned int &col, const unsigned int &len){
        this->update_min_column(col);
        this->update_max_column(col+len-1);
        this->update_min_row(row);
        this->update_max_row(row);
    }
    void Board::vertical_size_update(const unsigned int &row, const unsigned int &col, const unsigned int &len){
        this->update_min_column(col);
        this->update_max_column(col);
        this->update_min_row(row);
        this->update_max_row(row+len-1);
  
    }
    void Board::horizontal_writing(const unsigned int &row, const unsigned int &col, const string &message){
        unsigned int len=message.length();
        this->horizontal_size_update(row, col, len);
        for (size_t i = 0; i < len; i++){
            this->board[row][col+i]=message.at(i);   
        }
    }
    void Board::vertical_writing(const unsigned int &row, const unsigned int &col, const string &message){
        unsigned int len=message.length();
        this->vertical_size_update(row, col, len);
        for (size_t i = 0; i < len ; i++){
            this->board[row+i][col]=message.at(i);
        }
    }
    void Board::post(const unsigned int &row, const unsigned int &col, const ariel::Direction &direction, const string &message){
        if (direction==Direction::Vertical){
            vertical_writing(row, col, message);
            return;
        }
        horizontal_writing(row, col, message);
    }
    
    bool Board::contains(const unsigned int &row, const unsigned int &col){
        return (this->board.count(row)!=0 && this->board[row].count(col)!=0 );
    }
    string Board::horizontal_reading(const unsigned int &row, const unsigned int &col, const unsigned int &length){
        std::string ans;
        for (size_t i = 0; i < length; i++) {
                if (contains(row, col+i)){
                    ans+= this->board[row][col+i];
                }else{
                    ans+='_';
                }
        }
        return ans;
    }
    string Board::vertical_reading(const unsigned int &row, const unsigned int &col, const unsigned int &length){
        std::string ans;
        for (size_t i = 0; i < length; i++){
            if (this->contains(row+i, col)){
                ans+= this->board[row+i][col];
            }else{
                ans+='_';
            }
        }
        return ans;
    }
    string Board::read(const unsigned int &row, const unsigned int &col, const ariel::Direction &direction , const unsigned int &length){
        if (direction==Direction::Vertical){
            return vertical_reading(row, col, length);
        }
        return horizontal_reading(row, col, length);
    }
    void Board::show(){
        if (this->max_row<this->min_row){
            cout << "\n   The board is blank\n" << endl;
            return;
        }

        unsigned int dis_to_begin_board=get_number_of_digits(this->max_row)+2;
        unsigned int horizontal_range=length_of_inclusive_range(this->max_col, this->min_col);
        unsigned int vertical_range=length_of_inclusive_range(this->max_row, this->min_row);
        // Top frame printing
        cout << "\n\n" << string(number_of_spaces_before_the_board(dis_to_begin_board,0)+3, ' ')  <<  string(horizontal_range, '_') << endl;
        for (size_t i = 0; i < vertical_range; i++){
            unsigned int row_current=this->min_row +i;
            cout << row_current << ':' <<  string(number_of_spaces_before_the_board(dis_to_begin_board,row_current), ' ')
                    << '|' << this->read(row_current, this->min_col,Direction::Horizontal,horizontal_range) << '|' << endl ; 
        }
        //Bottom frame printing 
        cout << string(number_of_spaces_before_the_board(dis_to_begin_board,0)+2, ' ') << '\\' << string(horizontal_range, '_') << '/' << endl;
    }
}
