/**
 * Running example for the "snowman" function
 * 
 * Author: Shlomo Glick
 * Since : 2021-03
 */

#include "snowman.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;


int main() {



    cout << "Hello!" << endl; 
    cout << "My name is Bob, and I'm a snowman" << endl; 


    cout << ariel::snowman(11331134) << endl;

    cout <<  "I say hello to you" << endl; 
    cout << ariel::snowman(11331234) << endl;
    cout << ariel::snowman(11331334) << endl; 
    cout <<  "I wink at you, wink back at me!" << endl; 
    cout << ariel::snowman(11311334) << endl;
    cout << ariel::snowman(11331334) << endl; 

    cout << ariel::snowman(11331134) << endl;
    cout <<  "I can change hats" << endl; 
    cout << ariel::snowman(21331134) << endl;
    cout << ariel::snowman(31331134) << endl;
    cout << ariel::snowman(41331134) << endl;
    cout << ariel::snowman(11331134) << endl;

    cout <<  "I can change my nose" << endl; 
    cout << ariel::snowman(12331134) << endl;
    cout << ariel::snowman(13331134) << endl;
    cout << ariel::snowman(14331134) << endl;
    cout << ariel::snowman(11331134) << endl;


    cout <<  " I can also close and open my eyes in all sorts of ways" << endl; 
    cout << ariel::snowman(11111134) << endl;
    cout << ariel::snowman(11221134) << endl;
    cout << ariel::snowman(11441134) << endl;
    cout << ariel::snowman(11131134) << endl;
    cout << ariel::snowman(11121134) << endl;
    cout << ariel::snowman(11141134) << endl;
    cout << ariel::snowman(11231134) << endl;






    cout <<  "I can also move my hands" << endl; 
    cout << ariel::snowman(11332234) << endl;
    cout << ariel::snowman(11333334) << endl;
    cout << ariel::snowman(11334434) << endl;
    cout << ariel::snowman(11331234) << endl;
    cout << ariel::snowman(11331334) << endl;
    cout << ariel::snowman(11331434) << endl;
    cout << ariel::snowman(11332434) << endl;
    cout << ariel::snowman(11332334) << endl;


    cout <<  "And the most surprising thing I also know how to dress alone" << endl; 
    cout << ariel::snowman(11331134) << endl;
    cout << ariel::snowman(11331144) << endl;
    cout << ariel::snowman(11331111) << endl;
    cout << ariel::snowman(11331122) << endl;
    cout << ariel::snowman(11331121) << endl;
    cout << ariel::snowman(11331123) << endl;
    cout << ariel::snowman(11331133) << endl;
    cout << ariel::snowman(11331134) << endl;



    cout <<  "And here are all my friends" << endl; 
    cout << ariel::snowman(11111111) << endl; 
    cout << ariel::snowman(22222222) << endl;
    cout << ariel::snowman(33333333) << endl;
    cout << ariel::snowman(44444444) << endl;
    cout << ariel::snowman(32143214) << endl;
    cout << ariel::snowman(12121244) << endl; 
    cout << ariel::snowman(31112211) << endl; 
    cout << ariel::snowman(11331134) << endl;
    cout << ariel::snowman(41141211) << endl; 
    cout << ariel::snowman(22331132) << endl;
    cout << ariel::snowman(43124432) << endl;
    cout << ariel::snowman(11332244) << endl; 
    cout << ariel::snowman(32143214) << endl;
    cout << ariel::snowman(12121244) << endl; 
    cout << ariel::snowman(31112211) << endl; 


    
    cout <<  "Try it for yourself," << endl; 
    cout <<  "Enter a valid 8-digit number with each digit between 1 and 4: " << endl;
    int n=0; 
    cin >> n;

	try {
		cout << ariel::snowman(n) << endl;
	} catch (out_of_range ex) {
	 	cout << "   caught exception: " << ex.what() << endl; 
	}













    //*************not good case******************



    // Not a good case because the number is too short
    try {
		cout << ariel::snowman(3445) << endl;
	} catch (out_of_range ex) {
	 	cout << "   caught exception: " << ex.what() << endl; 
	}

    // Not a good case because of the number 9
     try {
		cout << ariel::snowman(19234232) << endl;
	} catch (out_of_range ex) {
	 	cout << "   caught exception: " << ex.what() << endl; 
	}


    // Not a good case because the number is too long
    try {
		cout << ariel::snowman(123412341) << endl;
	} catch (out_of_range ex) {
	 	cout << "   caught exception: " << ex.what() << endl; 
	}




    
	return 0;
}
