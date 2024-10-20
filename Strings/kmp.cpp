#include <bits/stdc++.h>
using namespace std;

void findPattern(string text, string pattern){
    //construct prefix table by passing the pattern
    int m  = text.size();
/*  pattern = "aadac"
    1   2   3   4   5
    a   a   d   a   c
    0   1   0   1   0
*/
    int n = pattern.size();
    vector<int> lps(n, 0);
    int i,j;
    j = 0;
    i = 1; 

    while (i < n ){
        if (pattern[i] == pattern[j]){
            j += 1;
            lps[i] = j;
            i += 1;
        } else {
            if (j != 0){
                j = lps[j-1];
            } else {
                lps[i] = 0;
                i = i+ 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << lps[i] << " ";
    }
    cout << endl;
    i = 0; j = 0;
    while (i < m){
        if (text[i] == pattern[j]){
            i += 1;
            j += 1;
        } 
        
        if (j == n) {
            cout << "Pattern found at index " << (i - j) << endl;
            j = lps[j-1]; // continue search for more matchyes
        } else if( i < m and text[i] !=pattern[j]){
            if ( j != 0) {
                j = lps[j-1];
            }else {
                i += 1;
            }
        }
    }
}

int main(){
    string text = "abcdabafaadacgaadac";
    string pattern = "aadac";
    findPattern(text, pattern);
    return 0;
}