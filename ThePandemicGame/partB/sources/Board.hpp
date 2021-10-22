
#ifndef BOARD_HPP
#define BOARD_HPP

#include "City.hpp"
#include "Color.hpp"
#include <unordered_map>
#include <iostream>
#include <utility>


namespace pandemic{

    class Board{
        protected:
            struct Data{
                Color color;
                int level_disease;
                bool research_stations;
                std::unordered_map<City,int> neighbors;
            };
            int count_player=0;
            std::unordered_map<City, Data> data;
            std::unordered_map<Color,bool> cure;
            void city_neighborhoods_update();
            void update_colors_for_cities();
            void update_color(City city,Color color);
            void add_nei(City c1,City c2);
            void add_nei(City c1,City c2,City c3);
            void add_nei(City c1,City c2,City c3,City c4);
            void add_nei(City c1,City c2,City c3,City c4,City c5);
            void add_nei(City c1,City c2,City c3,City c4,City c5,City c6);
            std::unordered_map<City,int>& get_nei(City city);
            void update_cure(); 
        public:
            bool& is_research_stations(City city);
            Board(){
                city_neighborhoods_update();
                update_colors_for_cities();
                update_cure();
            };
            bool is_nei(City c1,City c2);
            int& operator[](City city);
            bool is_clean() const;
            bool& get_cure(Color);
            Color& get_color(City city);
            int& get_level(City city);
            friend std::ostream& operator<< (std::ostream& os,const Board& board);
            static std::string get_name(City city);
            static std::string get_name(Color color);
            friend class Player;
            void remove_cures();
            void remove_stations();
    };
}


#endif