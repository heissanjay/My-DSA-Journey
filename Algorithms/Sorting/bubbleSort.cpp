#include <iostream>
using namespace std;



int main(int argc, char const *argv[])
{
	int arr[10] = {12,3,56,78,6,45,23,89,1,7};
	int arrlen = sizeof(arr)/sizeof(arr[0]);
	cout<<"Array Before Sorted : ";
	for (int i = 0; i < arrlen; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<'\n';
	
	return 0;
}