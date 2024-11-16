#include <bits/stdc++.h>

using namespace std;

void calculateOutput(map<int, int>& bank, int input) {
    int remainder = abs(input); // positive value for comfort with dealing with map

    for (int i=1024; i > 0; i /= 2) { //Find the change i need to give from largest to smallest banknotes
        if (remainder >= i && bank.at(i) > 0) {

            cout << i << " ";

            //updating values
            bank.at(i)--;
            remainder -= i;

            if (remainder >= i) i *= 2;
        }
    }

    cout <<  endl;
}


int main() {
    map<int, int> bank; //initialize our bank of banknotes

    bank.insert({1, 0});
    bank.insert({2, 0});
    bank.insert({4, 0});
    bank.insert({8, 0});
    bank.insert({16, 0});
    bank.insert({32, 0});
    bank.insert({64, 0});
    bank.insert({128, 0});
    bank.insert({256, 0});
    bank.insert({512, 0});
    bank.insert({1024, 0});

    int T;
    cin >> T;
    int input;

    for (int i=0; i < T; i++) {
        cin >> input;

        //check if we have a positive or negative number and act accordingly
        if (input > 0) bank[input]++; //important to do bank[input] in some cases instead of bank.at();  since bank[input] will create the value if it does not exist

        else {
            calculateOutput(bank, input);
        }

    }

    return 0;
}

//DONE IN ~30 minutes