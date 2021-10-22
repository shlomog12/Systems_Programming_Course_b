/**
 * --snowman--
 * A function that creates a snowman on an 8-digit number
 * When for each digit there is a choice of 4 options (1-4)
 * The first digit - chooses the type of head  
 * The second digit - the type of mouth
 * The third digit - left eye type
 * The fourth digit - right eye type
 * Fifth digit - left arm
 * The sixth digit - right arm
 * The seventh digit - torso
 * The eighth digit - base
 * For further reading, visit the address -  https://codegolf.stackexchange.com/q/49671/12019
 * 
 * Author: Shlomo Glick
 * Since : 2021-03
 */




#include "snowman.hpp"
#include <iostream>
#include <stdexcept>



const int MAX_IN_RANGE = 44444444; 
const int MIN_IN_RANGE = 11111111;
const int MINIMUM_CHOICE = 1;
const int MAXIMUM_CHOICE = 4;
const int COUNTING_BASE = 10;

enum cases{
    CASE_A=1,
    CASE_B,
    CASE_C
};



using namespace std;


namespace ariel{

    int last_index(int n){
        return n%COUNTING_BASE;
    }	
   
    int delete_last_digit(int n){
        return n/COUNTING_BASE;
    }

    void integrity_check(int choice){
        if (choice>MAXIMUM_CHOICE || choice<MINIMUM_CHOICE) {
            throw out_of_range("The number in each choice must be between 1 and 4");
        }
    }

    string create_snowman_base(int choice){
        integrity_check(choice);
        if (choice==CASE_A) { return " ( : ) ";}
        if (choice==CASE_B) { return " (\" \") ";}
        if (choice==CASE_C) { return " (___) ";}
        return " (   ) ";
    }

    string create_snowman_torso(int choice){
        integrity_check(choice);
        if (choice==CASE_A) { return "( : )";}
        if (choice==CASE_B) { return "(] [)";}
        if (choice==CASE_C) { return "(> <)";}
        return "(   )";
    }

    string create_upper_right_arm(int choice){
        integrity_check(choice);
        if (choice==CASE_B) { return "/";}
        return " ";
      }

    string create_lower_right_arm(int choice){
        integrity_check(choice);
        if (choice==CASE_A) { return ">";}
        if (choice==CASE_C) { return "\\";}
        return " ";
        }     

    string create_upper_left_arm(int choice){
            integrity_check(choice);
             if (choice==CASE_B) { return "\\";}
                return " ";
             }

    string create_lower_left_arm(int choice){
            integrity_check(choice);
            if (choice==CASE_A) { return "<";}
            if (choice==CASE_C) { return "/";}
            return " ";
        }  

    string create_snowman_eye(int choice){
            integrity_check(choice);
            if (choice==CASE_A) { return ".";}
            if (choice==CASE_B) { return "o";}
            if (choice==CASE_C) { return "O";}
            return "-";
        }

    string create_snowman_mouth(int choice){
        integrity_check(choice);
        if (choice==CASE_A) { return ",";}
        if (choice==CASE_B) { return ".";}
        if (choice==CASE_C) { return "_";}
        return " ";
    }

    string create_snowman_head(int choice){
        integrity_check(choice);
        if (choice==CASE_A) { return " _===_ ";}
        if (choice==CASE_B) { return "  ___  \n ..... ";}
        if (choice==CASE_C) { return "   _  \n  /_\\  ";}
        return "  ___  \n (_*_) ";
    }



    string snowman(int n){
    if (n<MIN_IN_RANGE || n>MAX_IN_RANGE) {
        throw out_of_range{"The number is not 8 digits long"};
        }



    int index=last_index(n);
    string Base =create_snowman_base(index);

    n=delete_last_digit(n);
    index=last_index(n);
    string Torso=create_snowman_torso(index);
    
    n=delete_last_digit(n);
    index=last_index(n);
    string upper_right_arm=create_upper_right_arm(index);
    string lower_right_arm=create_lower_right_arm(index);


    n=delete_last_digit(n);
    index=last_index(n);
    string upper_left_arm=create_upper_left_arm(index);
    string lower_left_arm=create_lower_left_arm(index);

    n=delete_last_digit(n);
    index=last_index(n);
    string Right_eye=create_snowman_eye(index);

    
    n=delete_last_digit(n);
    index=last_index(n);
    string Left_eye=create_snowman_eye(index);;
   
    n=delete_last_digit(n);
    index=last_index(n);
    string Mouth = create_snowman_mouth(index);


    n=delete_last_digit(n);
    index=last_index(n);
    string Head=create_snowman_head(index);


    string ans= Head+"\n"
                    + upper_left_arm+"(" + Left_eye + Mouth + Right_eye + ")" + upper_right_arm + "\n"
                         +lower_left_arm + Torso  + lower_right_arm + "\n" +Base + "\n";


    return ans;
}
}

