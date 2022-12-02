//  implementation of heaps
#include <iostream>
#include <vector>
using namespace std;

vector<int> sortedHeap;

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
//  heapify

void heapify(vector<int> &hp, int i){ // pass the ref of arr and i th node
    int size = hp.size();
    int par = i; // init the i as largest
    int l = 2 * i + 1; // left child
    int r = 2 * i + 2; // right child

    if (l < size && hp[l] > hp[par]){
        par = l;
    }
    if (r < size && hp[r] > hp[par]){
        par = r;
    }
    if(par != i){
        swap(&hp[i],&hp[par]);
        heapify(hp,par);
    }
}

void insert(vector<int> &hp, int item){
    int s = hp.size();
    if(s == 0){
        hp.push_back(item);
    }
    else{
        hp.push_back(item);
        for(int i = s / 2 - 1  ; i >= 0; i--)
            heapify(hp,i);
    }
}

void deleteItem(vector<int> &hp, int delItem){
    int s = hp.size();
    int i=0; // initialize i , we need the scope of i throught the function
    for(i=0 ; i < s;i++){
        if(hp[i] == delItem)
            break;
    }
    swap(&hp[i],&hp[s-1]); // swap the ele with last element
    sortedHeap.push_back(hp[s-1]);
    hp.pop_back(); // del the ele
    for(int i= s / 2 - 1; i >= 0; i--) // heapfiy the rest
        heapify(hp,i);
}
void heapsort(vector<int> &hp){
    for(int i=0; i<hp.size();i++){
        deleteItem(hp,hp[i]);
    }
}
void printHeap(vector<int> &hp){
    for(int i = 0 ; i < hp.size();i++)
        cout<<hp[i]<<" ";
    cout<<"\n";
}

void findMax(vector<int> &hp){
    cout<<hp[0]<<" ";
}

int main(){
    vector<int> heap;

    insert(heap, 3);
    insert(heap, 4);
    insert(heap, 9);
    insert(heap, 5);
    insert(heap, 2);
    insert(heap, 21);
    insert(heap, 45);
    insert(heap, 12);
    insert(heap, 7);



    cout << "Max-Heap array: ";
    printHeap(heap);

    heapsort(heap);
    printHeap(sortedHeap);
    return 0;
}