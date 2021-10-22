#include "Board.hpp"
// #include "City.hpp"

namespace pandemic{


// *************public**********************************
 
    int& Board::operator[](City city){
            return this->data[city].level_disease;
        }
    bool Board::is_clean() const{
       for (const auto &cur : this->data){
            if (cur.second.level_disease!=0) {return false;}
       }
        return true;
    }
    std::ostream& operator<< (std::ostream& os,const Board& board){
        os  <<"***************MY BOARD:********************"<< std::endl;
        for (const auto &data_cur : board.data){
            if (data_cur.second.level_disease!=0 || data_cur.second.research_stations){
                os  << Board::get_name( data_cur.first) << ":" << std::endl;
                os << "     level = " << data_cur.second.level_disease << std::endl;
                os << "     research_stations = " <<data_cur.second.research_stations<< std::endl;
            } 
        }
        for (const auto &is_cure : board.cure){
            if (is_cure.second){
               os << "A cure for --" << Board::get_name(is_cure.first) << "-- disease has been discovered"<< std::endl;
            }
        }

        //  for (const auto &player : board.players){
        //     os << "player "<< player.first << ":" << std::endl;
        //     os << player.second;
        // }
        
        return os;
          
          
    }

 // ****************************************************


    bool Board::is_nei(City c1,City c2){
        return (get_nei(c1)[c2]==1);
    }
    bool& Board::get_cure(Color color){
        return this->cure[color];
    }
    std::unordered_map<City,int>& Board::get_nei(City city){
        return this->data[city].neighbors;
    }
    Color& Board::get_color(City city){
        return this->data[city].color;
    }
    int& Board::get_level(City city){
        return this->data[city].level_disease;
    }
    bool& Board::is_research_stations(City city){
        bool &b=this->data[city].research_stations;
        // std::cout << " is "  << std::endl;
        return b;
    }
    void Board::remove_cures(){
        for (auto &color : cure){
            color.second=false;
        }       
    }
    void Board::remove_stations(){
        for (auto &city : data){
            city.second.research_stations=false;
        }  
    }

// *************init board******************************

    void Board::update_color(City city,Color color){
        get_color(city)=color;
    }
    void Board::update_colors_for_cities(){
            update_color(Algiers, Black);
            update_color(Atlanta ,Blue);
            update_color(Baghdad, Black);
            update_color(Bangkok, Red);
            update_color(Beijing, Red);
            update_color(Bogota, Yellow);
            update_color(BuenosAires, Yellow);
            update_color(Cairo, Black);
            update_color(Chennai, Black);
            update_color(Chicago, Blue);
            update_color(Delhi, Black);
            update_color(Essen, Blue);
            update_color(HoChiMinhCity, Red);
            update_color(HongKong, Red);
            update_color(Istanbul, Black);
            update_color(Jakarta, Red);
            update_color(Johannesburg ,Yellow);
            update_color(Karachi, Black);
            update_color(Khartoum, Yellow);
            update_color(Kinshasa, Yellow);
            update_color(Kolkata, Black);
            update_color(Lagos, Yellow);
            update_color(Lima, Yellow);
            update_color(London, Blue);
            update_color(LosAngeles, Yellow);
            update_color(Madrid, Blue);
            update_color(Manila, Red);
            update_color(MexicoCity, Yellow);
            update_color(Miami, Yellow);
            update_color(Milan, Blue);
            update_color(Montreal, Blue);
            update_color(Moscow, Black);
            update_color(Mumbai, Black);
            update_color(NewYork, Blue);
            update_color(Osaka, Red);
            update_color(Paris, Blue);
            update_color(Riyadh, Black);
            update_color(SanFrancisco, Blue);
            update_color(Santiago, Yellow);
            update_color(SaoPaulo, Yellow);
            update_color(Seoul, Red);
            update_color(Shanghai, Red);
            update_color(StPetersburg, Blue);
            update_color(Sydney, Red);
            update_color(Taipei, Red);
            update_color(Tehran,Black);
            update_color(Tokyo, Red);
            update_color(Washington, Blue);
    }
    void Board::city_neighborhoods_update(){
        add_nei(Algiers, Madrid ,Paris ,Istanbul ,Cairo);
        add_nei(Atlanta , Chicago ,Miami, Washington);
        add_nei(Baghdad , Tehran, Istanbul ,Cairo ,Riyadh, Karachi);
        add_nei(Bangkok ,Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong);
        add_nei(Beijing, Shanghai, Seoul);
        add_nei(Bogota , MexicoCity, Lima ,Miami ,SaoPaulo ,BuenosAires);
        add_nei(BuenosAires , Bogota, SaoPaulo);
        add_nei(Cairo, Algiers ,Istanbul, Baghdad, Khartoum ,Riyadh);
        add_nei(Chennai , Mumbai, Delhi, Kolkata, Bangkok ,Jakarta);
        add_nei(Chicago, SanFrancisco ,LosAngeles ,MexicoCity, Atlanta, Montreal);
        add_nei(Delhi, Tehran, Karachi, Mumbai ,Chennai, Kolkata);
        add_nei(Essen, London, Paris, Milan, StPetersburg);
        add_nei(HoChiMinhCity , Jakarta ,Bangkok ,HongKong, Manila);
        add_nei(HongKong , Bangkok ,Kolkata ,HoChiMinhCity, Shanghai ,Manila);
        add_nei(HongKong , Taipei);
        add_nei(Istanbul , Milan, Algiers ,StPetersburg, Cairo, Baghdad );
        add_nei(Istanbul  ,Moscow);
        add_nei(Jakarta , Chennai ,Bangkok ,HoChiMinhCity ,Sydney);
        add_nei(Johannesburg , Kinshasa, Khartoum);
        add_nei(Karachi , Tehran ,Baghdad ,Riyadh, Mumbai ,Delhi);
        add_nei(Khartoum ,Cairo ,Lagos, Kinshasa ,Johannesburg);
        add_nei(Kinshasa , Lagos ,Khartoum ,Johannesburg);
        add_nei(Kolkata , Delhi ,Chennai ,Bangkok, HongKong);
        add_nei(Lagos , SaoPaulo, Khartoum ,Kinshasa);
        add_nei(Lima , MexicoCity, Bogota, Santiago);
        add_nei(London , NewYork, Madrid, Essen, Paris);
        add_nei(LosAngeles , SanFrancisco, Chicago, MexicoCity, Sydney);
        add_nei(Madrid, London ,NewYork, Paris ,SaoPaulo, Algiers);
        add_nei(Manila , HongKong ,Taipei ,SanFrancisco, HoChiMinhCity, Sydney);
        add_nei(MexicoCity , LosAngeles, Chicago, Miami, Lima, Bogota);
        add_nei(Miami ,Atlanta ,MexicoCity ,Washington ,Bogota);
        add_nei(Milan ,Essen ,Paris, Istanbul);
        add_nei(Montreal , Chicago, Washington, NewYork);
        add_nei(Moscow, StPetersburg ,Istanbul, Tehran);
        add_nei(Mumbai , Karachi, Delhi, Chennai);
        add_nei(NewYork , Montreal, Washington, London ,Madrid);
        add_nei(Osaka ,Taipei ,Tokyo);
        add_nei(Paris ,Algiers ,Essen, Madrid, Milan, London);
        add_nei(Riyadh , Baghdad, Cairo, Karachi);
        add_nei(SanFrancisco , LosAngeles ,Chicago, Tokyo, Manila);
        add_nei(Santiago , Lima);
        add_nei(SaoPaulo , Bogota ,BuenosAires ,Lagos, Madrid);
        add_nei(Seoul , Beijing, Shanghai ,Tokyo);
        add_nei(Shanghai, Beijing, HongKong, Taipei, Seoul, Tokyo);
        add_nei(StPetersburg , Essen ,Istanbul, Moscow);
        add_nei(Sydney ,Jakarta, Manila, LosAngeles);
        add_nei(Taipei, Shanghai, HongKong ,Osaka, Manila);
        add_nei(Tehran , Baghdad, Moscow, Karachi ,Delhi);
        add_nei(Tokyo , Seoul, Shanghai, Osaka, SanFrancisco);
        add_nei(Washington , Atlanta, NewYork ,Montreal, Miami);
    }
    void Board::add_nei(City c1,City c2){
               get_nei(c1)[c2]=1;
        }
    void Board::add_nei(City c1,City c2,City c3){
                add_nei(c1, c2);  
                add_nei(c1, c3); 
        }
    void Board::add_nei(City c1,City c2,City c3,City c4){
                add_nei(c1, c2,c3);  
                add_nei(c1, c4); 
        }
    void Board::add_nei(City c1,City c2,City c3,City c4,City c5){
            add_nei(c1, c2,c3,c4);  
            add_nei(c1, c5); 
            add_nei(c1, c4);
            add_nei(c1, c5); 
        }
    void Board::add_nei(City c1,City c2,City c3,City c4,City c5,City c6){
            add_nei(c1, c2,c3,c4);  
            add_nei(c1, c5,c6); 
        } 
    void Board::update_cure(){
        get_cure(Red)=false;
        get_cure(Blue)=false;
        get_cure(Black)=false;
        get_cure(Yellow)=false;
    }
    std::string Board::get_name(City city) {
        switch(city){
            case  Algiers: return "Algiers";
            case  Atlanta: return "Atlanta";
            case  Baghdad: return "Baghdad";
            case  Bangkok: return "Bangkok";
            case  Beijing: return "Beijing";
            case  Bogota: return "Bogota";
            case  BuenosAires: return "BuenosAires";
            case  Cairo: return "Cairo";
            case  Chennai: return "Chennai";
            case  Chicago: return "Chicago";
            case  Delhi: return "Delhi";
            case  Essen: return "Essen";
            case  HoChiMinhCity: return "HoChiMinhCity";
            case  HongKong: return "HongKong";
            case  Istanbul: return "Istanbul";
            case  Jakarta: return "Jakarta";
            case  Johannesburg: return "Johannesburg";
            case  Karachi: return "Karachi";
            case  Khartoum: return "Khartoum";
            case  Kinshasa: return "Kinshasa";
            case  Kolkata: return "Kolkata";
            case  Lagos: return "Lagos";
            case  Lima: return "Lima";
            case  London: return "London";
            case  LosAngeles: return "LosAngeles";
            case  Madrid: return "Madrid";
            case  Manila: return "Manila";
            case  MexicoCity: return "MexicoCity";
            case  Miami: return "Miami";
            case  Milan: return "Milan";
            case  Montreal: return "Montreal";
            case  Moscow: return "Moscow";
            case  Mumbai: return "Mumbai";
            case  NewYork: return "NewYork";
            case  Osaka: return "Osaka";
            case  Paris: return "Paris";
            case  Riyadh: return "Riyadh";
            case  SanFrancisco: return "SanFrancisco";
            case  Santiago: return "Santiago";
            case  SaoPaulo: return "SaoPaulo";
            case  Seoul: return "Seoul";
            case  Shanghai: return "Shanghai";
            case  StPetersburg: return "StPetersburg";
            case  Sydney: return "Sydney";
            case  Taipei: return "Taipei";
            case  Tehran: return "Tehran";
            case  Tokyo: return "Tokyo";
            case  Washington: return "Washington";
        }
    } 
    std::string Board::get_name(Color color) {
        switch(color){
            case  Yellow: return "Yellow";
            case  Red: return "Red";
            case  Black: return "Black";
            case  Blue: return "Blue";
        }
    }
   

// *****************************************************



}



