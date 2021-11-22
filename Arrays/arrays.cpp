#include <iostream>
using namespace std;

/* Creating an array 
	syntax

datatype arr_name[arr_size] ; //

	initializing an array
	
datatype arr_name[arr_size] = {value1,value2,value3....valueN};

*/
string days[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};


int main(int argc, char const *argv[])
{
	// Accessing element of an array
	// Array index is start from 0

	// cout<<"First day of a week is "<<days[0]<<endl;

	/* we can able to loop through th array */
	cout<<"The days in a week are "<<endl;
	for (int i = 0; i < (sizeof(days)/sizeof(days[0])); ++i)
	{
		
		cout<<i+1<<". "<<days[i]<<" "<<"\n";
	}
	
	return 0;
}