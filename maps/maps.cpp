/* importing required libraries */
#include <iostream>
#include <map>
#include <iterator>
using namespace std;


/* Defining a Map */
map<int,string> numInWords;
map<int,string>::iterator iter;

int main(int argc, char const *argv[])
{
	/*assing values to the map */
	numInWords.insert(pair<int,string>(1,"one"));
	cout<<(numInWords.begin())->first<<"\t";
	cout<<(numInWords.begin())->second<<endl;
	return 0;
}
