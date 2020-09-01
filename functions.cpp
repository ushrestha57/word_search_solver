#include <vector>
#include <string>
#include "functions.h"
#include <sstream>
#include <iostream>
using namespace std;


bool check(string row, string word)
{
    int wordIndex = 0;
    for(int i =0; i < row.length(); i++)
    {
        if(word[wordIndex] == row[i])
        {
           wordIndex++;
        }
        else
        {
            wordIndex =0;
        }
        if(wordIndex == word.length())
        {
            return true;
        }
    }
    return false;
}

string getColumn(vector<string> text, int index)
{
    string returned = "";
    for(int i =0; i < text.size(); i++)
    {
        returned += text[i].at(index);
    }
    return returned;
}

string checkDiagDown(vector<string> text, int yDimension, string word)
{
    
    for(int i = 0; i < text.size(); i++)
    {
        for(int j = 0; j < yDimension; j++)
        {
            string diagString = getDiagDown(text,yDimension,i,j);
            if(diagString == word )
            {
                return i + " " + j;
            }
        }
    }
    return "null";
}

string getDiagDown(vector<string> text, int yDimension, int xPos, int yPos)
{
    string builder = "";
     while(xPos < text.size() && yPos < yDimension)
            {
                builder+=text[xPos].at(yPos);
                xPos++;
                yPos++;
            }
    return builder;
}
string reverse(string word)
{
    stringstream returned;
    for(int i =word.size(); i > 0; i--)
    {
        returned << word.at(i-1);
    }
    return returned.str();
}

string getCoords( vector<string> text,string word,int yDimension)
{
    stringstream returned;
    for(int i = 0; i < text.size(); i++)
    {
        if(check(text[i],word) || check(text[i],reverse(word)))
        {
            returned <<  word << " is in row " << i+1;
            return returned.str();
        }
    }
    for(int i = 0; i < yDimension; i++)
    {
        if(check(getColumn(text,i),word) || check(getColumn(text,i),reverse(word)))
        {
            returned <<  word << " is in column " << i+1;
            return returned.str();
        }
    }
    for(int i = 0; i < text.size(); i++)
    {
        for(int j = 0; j < yDimension; j++)
        {
            if(check(getDiagDown(text,yDimension,i,j),word) || check(getDiagDown(text,yDimension,i,j),reverse(word)))
            {
                returned <<  word << " is in pos (" << i+1 << "," << j+1 << ").";
                return returned.str();
            }
        }
    }

    return returned.str();
} 