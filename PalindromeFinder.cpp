#include "PalindromeFinder.h"
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

void truncate(string& input){

    for (int i = 0, len = input.length(); i < len; i++)
    {
        if (ispunct(input[i]))
        {
            input.erase(i--, 1);
            len = input.length();
        }
    }

    for (int i = 0, len = input.length(); i < len; i++)
    {
        if (input[i] ==' ')
        {
            input.erase(i--, 1);
            len = input.length();
        }
    }

   transform(input.begin(), input.end(), input.begin(), ::tolower);

}

PalindromeFinder::PalindromeFinder(){}

string PalindromeFinder::toString(){
    stringstream ss;
    ss << "largest palindrome seen so far is \"" << this->getLargestPalindromeFound();
    ss << "\" with size " << this->getSizeOfLargestPalindromeFound();
    return ss.str();
}

string PalindromeFinder::getLargestPalindromeFound(){
    return this->largestPalindromeFound;
}

int PalindromeFinder::getSizeOfLargestPalindromeFound(){
    return this->largestPalindromeFound.length();
}

//returns true if input is a palindrome, false otherwise. If it is a palindrome and
// it is the largest seen so far, it should be stored in largestPalindromeFound.
bool PalindromeFinder::isPalindrome(string input){
    
    truncate(input);
    int n = input.length();

    for (int i = 0; i < (n/2); ++i)
    {
        if(input.at(i) != input.at(n-i-1))
            return false;
    }
    if(input.length()> this->getSizeOfLargestPalindromeFound()){
        this->largestPalindromeFound=input;
    }
    return true;
    
}

//Returns the largest palindrome in the string array inputStrings. If this is the
// the largest palindrome seen, this instance of the class should store it in
// largestPalindromeFound.
string PalindromeFinder::getLargestPalindrome(string* inputStrings, int numberOfStrings){

    string largestPalindrome = "";
    int largestsize=0;

    for(int i=0; i<numberOfStrings; i++){

        string currentstring = *(inputStrings+i);
        truncate(currentstring);

        if(this->isPalindrome(currentstring) && (currentstring.length() > largestsize)){
            largestPalindrome = *(inputStrings + i);
            largestsize = currentstring.length();
        }
    
    if(largestsize > this->getSizeOfLargestPalindromeFound())
        this->largestPalindromeFound = currentstring;
   } 

    return largestPalindrome;
}

//truncates the input string to its largest substring that is a palindrome.
// If this palindrome is the biggest seen so far, the class should store it
// in largestPalindromeFound.
void PalindromeFinder::truncateToLargestPalindrome(string& inputString){
    //Simple but time consuming algorithm ....... can be improved.
    truncate(inputString);

    string biggestsubPalindrome ="";
    int largestsize=0;
    int n = inputString.length();

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n-i+1; ++j)
        {
            string substring = inputString.substr(i,j);
            if(this->isPalindrome(substring) && (substring.length()> largestsize)){
                    biggestsubPalindrome = substring;
                    largestsize = substring.length();
            }
        }
    }
    if(largestsize > this->getSizeOfLargestPalindromeFound()){
        this->largestPalindromeFound = biggestsubPalindrome;
    }

    inputString = biggestsubPalindrome;
}
// The main begins.............

int main(int argc, char const *argv[])
{
    PalindromeFinder *baba = new PalindromeFinder();
    string str,str1;

    cout<< "Enter a string>>>>"<<endl;
    getline(cin,str);

    cout<< baba->isPalindrome(str)<<endl;
    
    string strings[3];

    strings[0]="Panama";
    strings[1]="Mad,,..am";
    strings[2]="A man, a plan, a canal, Panama,";

    cout<< baba->getLargestPalindrome(strings,3)<<endl;

    cout << "Enter a string to check whether it's any substring is a palindrome or not:"<<endl;
    getline(cin,str1);

    baba->truncateToLargestPalindrome(str1);
    cout<< str1<<endl;

    cout << baba->toString()<<endl;

    return 0;
}