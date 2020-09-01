using namespace std;
#include <string>
bool check(string row, string word);
string getCoords( vector<string> text, string word,int yDimension);
string getColumn(vector<string> text, int index, int numColumns);
string getDiagDown(vector<string> text, int yDimension, int xPos, int yPos);
string getDiagUp(vector<string> text, int xPos, int yPos);