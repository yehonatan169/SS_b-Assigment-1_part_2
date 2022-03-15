#include "mat.hpp"
#include "stdexcept"
#include <iostream>
using namespace ariel;
int main()
{
    // Function Call
    const int r=15;
    const int c=7;
    cout << mat(c, r, '@', '-') << endl;
    cout << mat(c, r, '$', '*') << endl;

    try {
        cout << ariel::mat(10, 5, '$', '%') << endl; // Exception - not a valid code
    } catch (exception& ex) {
        cout << "   caught exception: " << ex.what() << endl;  // should print "Mat size is always odd"
    }
    cout << mat(c, r, '%', '$') << endl;
    try {
        cout << ariel::mat(13, 5, ' ', '%') << endl;
    } catch (exception& ex) {
        cout << "   caught exception: " << ex.what() << endl;  // should print "Mat size is always odd"
    }
}