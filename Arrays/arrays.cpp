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

	cout<<"First day of a week is "<<days[0]<<endl;
	
	return 0;
}