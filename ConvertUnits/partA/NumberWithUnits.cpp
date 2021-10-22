#include "NumberWithUnits.hpp"
#include <string>
using namespace std;

const double EPS = 0.001;
namespace ariel{

    bool NumberWithUnits::contains(const std::string &key1,const std::string &key2){
        return (contains(key1) && map[key1].count(key2)!=0);
    }
    bool NumberWithUnits::contains(const std::string &key){
        return (map.count(key)!=0);
    }

    void NumberWithUnits::update(const string &key1,const string &key2,const double &val){
            map[key1][key2]=val;
            if (!contains(key2,key1)){
                update(key2,key1,1.0/val);
            }
            for (const auto &nei : map[key2]){
                if (!contains(key1,nei.first) && key1 != nei.first){update(key1,nei.first,val*nei.second);}
            }
        };
    void NumberWithUnits::read_units (std::ifstream &units_file){
            while (!units_file.eof()){
                int one=0;
                string key;
                string comp;
                double val=0;
                string type;
                units_file >> one >> key >> comp >> val >> type;
                if (one==1){
                NumberWithUnits::update(key,type,val);
                map[key][key]=1;
                map[type][type]=1;
                }
            }
            /*
            cout << "        table  :     " << std::endl;
            for (const auto &myPair : map){
                for(const auto &myPair2 : myPair.second){
                std::cout << myPair.first << " = " << myPair2.second << "  " << myPair2.first << std::endl;
                }
            }
            */

    }
    void check_match(const string &key1,const string &key2){
        if (!NumberWithUnits::contains(key1,key2)){
             throw out_of_range("Units do not match - ["+key2+"] cannot be converted to ["+key1+"]");
        }
    }


    NumberWithUnits operator+(const NumberWithUnits& n1,const NumberWithUnits& n2){
        check_match(n1.type,n2.type);
        return NumberWithUnits(n1.sum+NumberWithUnits::map[n2.type][n1.type]*n2.sum,n1.type);
        } 
    const NumberWithUnits& operator+(const NumberWithUnits &n){
        return n;
    }
    NumberWithUnits& operator+=(NumberWithUnits& n1,const NumberWithUnits& n2){
        check_match(n1.type,n2.type);
        n1.sum+=(NumberWithUnits::map[n2.type][n1.type])*n2.sum;
        return n1;
    }
    NumberWithUnits operator-(const NumberWithUnits& n1,const NumberWithUnits& n2){
        check_match(n1.type,n2.type);
        return NumberWithUnits(n1.sum-NumberWithUnits::map[n2.type][n1.type]*n2.sum,n1.type);
    }
    NumberWithUnits operator-(const NumberWithUnits& n){
        return NumberWithUnits(-n.sum,n.type);
    }
    NumberWithUnits& operator-=(NumberWithUnits& n1,const NumberWithUnits& n2){
        check_match(n1.type,n2.type);
        n1.sum-=(NumberWithUnits::map[n2.type][n1.type])*n2.sum;
        return n1;
    }
    
    bool operator>(const NumberWithUnits &n1,const NumberWithUnits &n2){
        check_match(n1.type,n2.type);
        double x=n1.sum;
        double y=(NumberWithUnits::map[n2.type][n1.type])*n2.sum;
        return ((x-EPS)>y);
    }
    bool operator>=(const NumberWithUnits &n1,const NumberWithUnits &n2){
        return ((n1>n2) || (n1==n2));
    }
    bool operator<(const NumberWithUnits &n1,const NumberWithUnits &n2){
        check_match(n1.type,n2.type);
        double x=n1.sum;
        double y=(NumberWithUnits::map[n2.type][n1.type])*n2.sum;
        return ((x+EPS)<y);
    }
    bool operator<=(const NumberWithUnits &n1,const NumberWithUnits &n2){
        return ((n1<n2) || (n1==n2));
    }
    bool operator==(const NumberWithUnits &n1,const NumberWithUnits &n2){
        check_match(n1.type,n2.type);
        double x=n1.sum;
        double y=(NumberWithUnits::map[n2.type][n1.type])*n2.sum;
        return (abs(x-y)<EPS);
    }
    bool operator!=(const NumberWithUnits &n1,const NumberWithUnits &n2){
        return (!(n1==n2));
    }

    NumberWithUnits& operator++(NumberWithUnits& n){
        n.sum++;
        return n;
    }
    NumberWithUnits operator++(NumberWithUnits &n,int dummy_flag_for_postfix_increment){
        NumberWithUnits copy=NumberWithUnits(n);
        ++n;
        return copy;
    }
    NumberWithUnits& operator--(NumberWithUnits& n){
        n.sum--;
        return n;
    }
    NumberWithUnits operator--(NumberWithUnits &n,int dummy_flag_for_postfix_increment){
        NumberWithUnits copy=NumberWithUnits(n);
        --n;
        return copy;
    }

    NumberWithUnits operator*(const NumberWithUnits& n,const double& num){
        NumberWithUnits n2=NumberWithUnits(n);
        n2.sum*=num;
        return n2;
    }
    NumberWithUnits operator*(const double& num,const NumberWithUnits& n){
        return n*num;
    }

    ostream& operator<< (ostream& os,const NumberWithUnits& n){
        return (os << n.sum << '[' << n.type << ']');
    }

    static istream& getAndCheckNextCharIs(istream& input, char expectedChar) {
        char actualChar=0;
        input >> actualChar;
        if (!input) {return input;}
        if (actualChar!=expectedChar){ 
            input.setstate(ios::failbit);
        }
        return input;
    }
    istream& operator>> (istream& input, NumberWithUnits& n) {

        double new_sum=0;
        string new_type;
        ios::pos_type startPosition = input.tellg();
        if ( (!(input >> new_sum)) || (!getAndCheckNextCharIs(input,'[')) || 
            (!(input >> new_type))) {
         
                auto errorState = input.rdstate(); 
                input.clear(); 
                input.seekg(startPosition); 
                input.clear(errorState); 
            } else {
                unsigned long index=new_type.length()-1;
                if (new_type.at(index)==']'){
                    new_type=new_type.substr(0,index);   
                }
                n.set_type(new_type);
                n.sum = new_sum;
            }
       


        return input;
    }
    
}

