#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    string friendName;

    map<string, int> friends;

    for (int i=0; i < 2; i++) { //2 sarasai draugu
        cin >> n;
        for (int k = 0; k < n; k++) { //idesime n draugu sarase
            cin >>  friendName;
            if ( friends.find(friendName) != friends.end() ) friends.at(friendName)++;
            else friends.insert({friendName, 1});
        }
    }

    for (auto i : friends) {
        if (i.second > 1) cout << i.first << " " << i.second << endl;
    }
}