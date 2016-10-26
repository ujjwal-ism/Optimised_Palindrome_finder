#include <iostream>
#include "PalindromeFinder.h"

int main() {

    int n=10;
    string* strings = new string[n];

    strings[0] = "zero";
    strings[1] = "one";
    strings[2] = "two";
    strings[3] = "three";
    strings[4] = "four";
    strings[5] = "five";
    strings[6] = "six";
    strings[7] = "seven";
    strings[8] = "eight";
    strings[9] = "nine";

    PalindromeFinder* palindromeFinder = new PalindromeFinder();
    palindromeFinder->getLargestPalindrome(strings, n);

    cout << endl << palindromeFinder->toString() << endl;

    

    return 0;
}
