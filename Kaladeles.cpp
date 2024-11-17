#include <bits/stdc++.h>

using namespace std;

bool checkIfPossible(unordered_map<char,int> pairs, int n) {
    for (auto& i : pairs) {
        if (i.second > (n + 1) / 2) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    char output;


    
    unordered_map<char, int> pairs;

    for (int i=0; i < n; i++) { //collect data into a map
        cin >> output;

        pairs[output]++;
    }

    if (!checkIfPossible(pairs, n)) { //check if it can be done or not
        cout << "NE" << endl;
        return -1;
    }

    //-------
    string result = "";
    pair<int, char> temp = {-1, '\0'};
    priority_queue<pair<int, char>> maxHeap; //create the priority list
    //-------

    for (auto& i : pairs) {
        maxHeap.push({i.second, i.first});
    }


    while (!maxHeap.empty()) { //Rearrange
        pair<int, char> current = maxHeap.top();
        maxHeap.pop();

        result += current.second;
        current.first--;

        if (temp.first > 0) {
            maxHeap.push(temp);
        }
        
        if (current.first > 0) temp = current;

        else temp = {-1, '\0'};
    }


    cout << result << endl;
    return 0;


}