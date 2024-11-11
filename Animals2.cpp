#include <iostream>
#include <vector>


using namespace std;

struct animal 
{
        int startingHour;
        int startingMin;
        int startingTotalMinutes;


        int endingHour;
        int endingMin;
        int endingTotalMinutes;

        void input();
};


void animal::input() 
{
    cin >> startingHour >> startingMin >> endingHour >> endingMin;
}

int main() 
{
    int n;
    bool found = false;
    int startMax;
    int endMin;

    cout << "Enter the number of animals: ";
    cin >> n;

    vector<animal> animals(n);

    for (int i=0; i < n; i++) { //create a vector of animals
        animals[i].input();

        animals[i].startingTotalMinutes = animals[i].startingHour * 60 + animals[i].startingMin;

        if (animals[i].endingHour < animals[i].startingHour)  //checking for time shift from 23:59 to 00:00
        { //searching for interval start and end points

            animals[i].endingTotalMinutes = (animals[i].endingHour * 60 + animals[i].endingMin + 60 * 24); //adding in 'lost' minutes
        }
        else 
        {
            animals[i].endingTotalMinutes = (animals[i].endingHour * 60 + animals[i].endingMin);
        }
    }
    //Now we have the time beginning and end intervals in "proper minutes"

    startMax = animals[0].startingTotalMinutes;
    endMin = animals[0].endingTotalMinutes;

    for (int k = 1; k < n; k++) {

            startMax = max(startMax, animals[k].startingTotalMinutes);
            endMin = min(endMin, animals[k].endingTotalMinutes);

            if (startMax < endMin) {
                found = true;
            }
            else found = false;
    }

    if (found) cout << "FOUND: " << startMax / 60 << " " <<  startMax % 60 << " " << (endMin / 60) % 24 << " " << endMin % 60 << endl;
    else cout << "not FOUND" << endl;

    return 0;
}