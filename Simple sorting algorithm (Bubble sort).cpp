#include <iostream>
#include <vector>

using namespace std;


void sort (vector<int> array1, int n) {
    for (int i=1; i < n; i++) {
        if (array1[i] < array1[i-1]) {
            int temp = array1[i];
            array1[i] = array1[i-1];
            array1[i-1] = temp;
        }
    }
    cout << "Sorted array: " << endl;
    for (int k=0; k < n; k++) {
        cout << array1[k] << " ";
    }
}




int main() {
    int n;
    cin >> n;

    vector <int> array1(n);

    for (int i = 0; i < n; i++) {
        cin >> array1[i];
    }

    sort(array1, n);


    //Make it more universal now:
    while (n != NULL) {

    }

}
