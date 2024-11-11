#include <iostream>
#include <vector>


using namespace std;

struct animal 
{
        int startingHour;
        int startingMin;

        int endingHour;
        int endingMin;

        void input();
};


void animal::input() 
{
    cin >> startingHour >> startingMin >> endingHour >> endingMin;
}


int main() 
{
    int n;

    int maxStartingTime=0;
    int minEndingTime=0;

    cout << "Enter the number of animals: ";
    cin >> n;

    vector<animal> animals(n);

    for (int i=0; i < n; i++) { //create a vector of animals
        animals[i].input();
        if (animals[i].endingHour == 0) animals[i].endingHour = 24;
        if (animals[i].startingHour == 0) animals[i].startingHour = 24;
    }
    

    for (animal i : animals) { //figure out the max starting time and max ending time
        cout << "Animal: " << i.startingHour << " " << i.startingMin << " " << i.endingHour << " " << i.endingMin << endl;
        maxStartingTime = max(maxStartingTime, (i.startingHour * 60 + i.startingMin));
        minEndingTime = min(minEndingTime, (i.endingHour * 60 + i.endingMin));
    }

    if (maxStartingTime > minEndingTime) {
        cout << "TAIP" << endl;
        cout << "Time:   " << maxStartingTime / 60 << " " << maxStartingTime % 60 << " " << minEndingTime / 60 << minEndingTime % 60 << endl;
    }

    else cout << "NE" << endl;

}