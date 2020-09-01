#include <iostream>
#include <fstream>
#include <vector>
#include "functions.h"
#include <string>
using namespace std;


int main()
{
    int xDimension;
    int yDimension;
    int numWords;
    ifstream wordSearch;
    ifstream getWords;
    vector<string> text;
    vector<string> words;

    cin >> xDimension >> numWords;


    wordSearch.open("wordSearch.txt");
    string input;
    for(int i =0; i <xDimension; i++)
    {
        getline(wordSearch,input);
        text.push_back(input);
    }
    yDimension = text[0].size();

    wordSearch.close();
    getWords.open("words.txt");
    for(int i =0; i <numWords; i++)
    {
        getline(getWords,input);
        words.push_back(input);
    }
    for(int i = 0; i < words.size(); i++)
    {
        cout << getCoords(text,words[i],yDimension) << endl;
       
    }
    

}