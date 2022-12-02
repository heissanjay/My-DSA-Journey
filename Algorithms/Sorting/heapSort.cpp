#include <iostream>
#include <vector>

using namespace std;
void swap(int *a,int *b){
    int temp = *a;
    *a  =*b;
    *b = temp;
}

void heapify(vector<int> &heap,int s,int i){
    int par = i;
    int l = 2*i + 1;
    int r= 2*i + 2;

    if(l < s && heap[l] > heap[par]){
        par = l;
    }
    if(r < s && heap[r] > heap[par]){
        par = r;
    }

    if(par != i){
        swap(&heap[par],&heap[i]);
        heapify(heap,s,par);
    }
}
void heapsort(vector<int> &arr,int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(arr[0], arr[i]);

      // Heapify root element to get highest element at root again
      heapify(arr, i, 0);
    }
}
void printHeap(vector<int> &heap){
    for(int i = 0 ; i < heap.size(); i++){
        cout<<heap[i]<<" ";
    }
    cout<<"\n";
}
int main(){
    vector<int> heap = {45, 12, 21, 7, 2, 9, 3, 4, 5};
    int size = heap.size();
    heapsort(heap,size);
    printHeap(heap);
    return 0;
}