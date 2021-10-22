/**
 * This is a class that represents a bulletin board,
 * The class allows:
 * Write on the board using the "post" function,
 * Read a row / column from the board using the "read" function,
 * View the entire board using the "show" function.
 * Author: Shlomo Glick
 * Since : 2021-03
**/

#include <bits/stdc++.h>
#include <unordered_map>
#include "Direction.hpp"

namespace ariel{

  class Board {

    private:

      unsigned int min_row = UINT_MAX;
      unsigned int max_row =0;
      unsigned int min_col= UINT_MAX;
      unsigned int max_col= 0;
      std::unordered_map<unsigned int, std::unordered_map<unsigned int, char>> board;

      void update_min_column(const unsigned int &col);
      void update_max_column(const unsigned int &col);
      void update_min_row(const unsigned int &row);
      void update_max_row(const unsigned int &row);
      void horizontal_size_update(const unsigned int &row, const unsigned int &col,
            const unsigned int &len);
      void vertical_size_update(const unsigned int &row,const unsigned int &col,
            const unsigned int &len);
      void horizontal_writing(const unsigned int &row, const unsigned int &col, const std::string &message);
      void vertical_writing(const unsigned int &row, const unsigned int &col, const std::string& message);
      bool contains(const unsigned int &row, const unsigned int &col);
      std::string horizontal_reading(const unsigned int &row, const unsigned int &col, const unsigned int &length);
      std::string vertical_reading(const unsigned int &row, const unsigned int &col, const unsigned int &length);

    public:
      /**
      * Writes the message in the corresponding row and column on the board
      * @param row Row number on which to start the message
      * @param col Column number on which to start the message
      * @param direction The direction of writing
      * @param message Message you want to write on the board
      */
      void post(const unsigned int &row, const unsigned int &col,
               const ariel::Direction &direction, const std::string &message);
      /**
      * Reads a string from the board
      * @param row Row number on which to start the message
      * @param col Column number on which to start the message
      * @param direction The direction of reading
      * @param length The number of characters you want to read
      * @return The string of characters that are on the board
      * according to the given location, direction, and length.
      * Note: If the location on a blank panel the function returns '_'
      */ 
      std::string read(const unsigned int &row, const unsigned int &col,
              const ariel::Direction &direction, const unsigned int &length);
      /**
      * Prints a view of the board
      * Note: Print only areas where there are messages
      */        
      void show();
  };
}
