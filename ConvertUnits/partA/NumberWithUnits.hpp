#include <unordered_map>
#include <fstream>
namespace ariel{

    class NumberWithUnits
    {
    private:
        static inline std::unordered_map<std::string, std::unordered_map<std::string, double>> map;
        std::string type;
        double sum;

        static void update(const std::string &key1,const std::string &key2,const double &val);
        static bool contains(const std::string &key1,const std::string &key2);
        static bool contains(const std::string &key);

    public:
        NumberWithUnits(const double sum2,const std::string type):sum{sum2}{
           set_type(type);
        }
        NumberWithUnits(const NumberWithUnits &n):sum{n.sum},type{n.type}{}
        NumberWithUnits& set_type(std::string type) { 
         if (!contains(type)){
                throw std::out_of_range("The type does not exist");
            }
            else{
                this->type=type;
            }
        return *this;
        }



        static void read_units(std::ifstream &units_file);
        friend void check_match(const std::string &key1,const std::string &key2);

        friend NumberWithUnits operator+(const NumberWithUnits& n1,const NumberWithUnits& n2);
        friend const NumberWithUnits& operator+(const NumberWithUnits& n1);
        friend NumberWithUnits& operator+=(NumberWithUnits& n1,const NumberWithUnits& n2);
        friend NumberWithUnits operator-(const NumberWithUnits& n1,const NumberWithUnits& n2);
        friend NumberWithUnits operator-(const NumberWithUnits& n);
        friend NumberWithUnits& operator-=(NumberWithUnits& n1,const NumberWithUnits& n2);


        friend bool operator>(const NumberWithUnits &n1,const NumberWithUnits &n2);
        friend bool operator>=(const NumberWithUnits &n1,const NumberWithUnits &n2);
        friend bool operator<(const NumberWithUnits &n1,const NumberWithUnits &n2);
        friend bool operator<=(const NumberWithUnits &n1,const NumberWithUnits &n2);
        friend bool operator==(const NumberWithUnits &n1,const NumberWithUnits &n2);
        friend bool operator!=(const NumberWithUnits &n1,const NumberWithUnits &n2);

        friend NumberWithUnits& operator++(NumberWithUnits& n);
        friend NumberWithUnits operator++(NumberWithUnits& n,int dummy_flag_for_postfix_increment);
        friend NumberWithUnits& operator--(NumberWithUnits& n);
        friend NumberWithUnits operator--(NumberWithUnits& n,int dummy_flag_for_postfix_increment);

        friend NumberWithUnits operator*(const NumberWithUnits &n,const double &num);
        friend NumberWithUnits operator*(const double &num,const NumberWithUnits &n);

        friend std::ostream& operator<< (std::ostream& os,const NumberWithUnits& n);
        friend std::istream& operator>> (std::istream& input, NumberWithUnits& n);

    };



}
