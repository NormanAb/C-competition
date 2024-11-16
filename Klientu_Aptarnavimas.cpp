#include <bits/stdc++.h>

using namespace std;

int main() {
    queue<int> klientuEile;

    int k;
    cin >> k;

    int timeSum = 0;
    int ID[k];
    int time;
    int index = 0;

    for (int i=0; i < k; i++) {
        cin >> ID[i] >> time;

        klientuEile.push(time);
        timeSum += time;
    }
    //Test case: | 5 | 1 10 | 2 5 | 3 8 | 4 12 | 5 6 |
    while (!klientuEile.empty()) {
        cout << "Klientas " << ID[index] << ",  laikas: " << klientuEile.front() << endl;;

        index++;
        klientuEile.pop();
    }

    cout << "Bendras laikas: " << timeSum << " minutes";
}