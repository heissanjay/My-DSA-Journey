/* importing required libraries */
#include <iostream>
#include <map>
#include <iterator>
using namespace std;


/* Defining a Map */
map<int,string> numInWords;

int main(int argc, char const *argv[])
{
	/*assing values to the map */
	// numInWords.insert(pair<int,string>(1,"one"));
	// numInWords.insert(pair<int,string>(2,"two"));
	// numInWords.insert(pair<int,string>(3,"three"));
	// numInWords.insert(pair<int,string>(4,"four"));
	// numInWords.insert(pair<int,string>(5,"five"));
	// numInWords.insert(pair<int,string>(6,"six"));

	/* alternate way of inserting */
	numInWords.insert({1,"one"});
	numInWords.insert({2,"two"});
	numInWords.insert({3,"three"});
	numInWords.insert({4,"four"});
	numInWords.insert({5,"five"});
	numInWords.insert({6,"six"});

	/* iterating through the map */
	map<int,string>::iterator iter; // create an iterator
	for(iter = numInWords.begin();iter!=numInWords.end();++iter){
		cout<<iter->first<<"\t"<<iter->second<<"\n";
	}	
	return 0;
}
