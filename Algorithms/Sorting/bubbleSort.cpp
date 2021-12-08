#include <iostream>
using namespace std;

void bubbleSort(int arr[],int arrlen){
	for(int i = 0; i < arrlen;++i){
		for(int j = i + 1; j < arrlen; ++j){
			if(arr[i] > arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

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
	bubbleSort(arr,arrlen);
	return 0;
}