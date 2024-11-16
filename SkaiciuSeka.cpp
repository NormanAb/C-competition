#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>

using namespace std;


int main() {
    int count = 0; //counter
    int input[5] = {51, 2, 3, 4, 5}; //input array

    vector<int> group; //where we store our answers

    int arrayLength = sizeof(input) / sizeof(input[0]);

    for (int i=0; i < arrayLength; i++) {
        for (int k = 0; k < arrayLength; k++) {
            if (input[i] < input[k]) count++;
        }
    }

    cout << "Count: " << count << endl;
    return 0;
    
}