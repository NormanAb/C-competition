#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


void sortBubble (vector<int>& array1, int n) { 
    for (int i = 0; i < n; i++) {
        for (int k = i+1; k < n; k++) {
           if (array1[k] < array1[i]) {
            int temp = array1[k];
            array1[k] = array1[i];
            array1[i] = temp;
           }
        } 
    }
    cout << "Sorted array: " << endl;
    for (int k=0; k < n; k++) {
        cout << array1[k] << " ";
    }
}




int main() {
    vector <int> array1;
    int n;
    int count=0;
    
    while (cin >> n) { //Input any number of values
        array1.push_back(n);
        count++;
    }


    if (count == 0) cout << "No numbers inputted" << endl;

    else sortBubble(array1, count); //sorting the values

    return 0;
}