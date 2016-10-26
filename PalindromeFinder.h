#ifndef MONSOON_2016_STRINGWRAPPER_H
#define MONSOON_2016_STRINGWRAPPER_H

#include <string>
#include <iostream>

using namespace std;

class PalindromeFinder {

private:
    string largestPalindromeFound;

public:
    PalindromeFinder();
    string toString();
    string getLargestPalindromeFound();
    int getSizeOfLargestPalindromeFound();

    bool isPalindrome(string);
    string getLargestPalindrome(string*, int);
    void truncateToLargestPalindrome(string&);
};


#endif 
