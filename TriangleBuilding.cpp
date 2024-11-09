#include <iostream>

using namespace std;

int main() {
    int n;

    cin >> n;

    int total = n;
    int b = 0; //blocks used. We are going up from 1 to n. For the Triangles to have the same k height and k base, it just means that they need to be "correct" pyramids.
    int sum = 0;

    for (int i=0; i < n; i++) { 
        b++;
        sum += b;

        if (total == 0) break;

        else if ( total - sum < 0) {
            sum = sum - b;
            cout << b - 1 << endl;

            total = total - sum; 
            
            b = 0;
            sum = 0;
        }
    }
}
