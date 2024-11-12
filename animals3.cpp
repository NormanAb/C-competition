#include <iostream>
#include <vector>


using namespace std;

static int mini = 0;
static int maxi = 0;


struct gyvunas {

    int startHour;
    int startMinute;

    int endHour;
    int endMinute;

    int startTotal =;

    int endTotal;

};

bool checkforIntersect(gyvunas a, gyvunas b) {
    cout << "startTotal: " << startTotal << endl;
    cout << "endTotal: "
    if (a.endTotal > b.startTotal || b.startTotal < b.endTotal) { //finding the highest starting time and smallest ending time
        return true;
    }
    else return false;

    //kaip aprasyti intervala kaip viena objekta isduodama?
}


int main() {

    int n;
    cout << "Irasykite n skaiciu: " << endl;
    cin >> n;

    cout << mini << " " << maxi << endl;

    bool found;

    vector<gyvunas> gyvunai(n);

    if (n > 1) {
         for (int i=0; i < n; i ++)
        { //obtain data
            cout << "Irasykite gyvuno intervala: " << endl;
            cin >> gyvunai[i].startHour >> gyvunai[i].startMinute >> gyvunai[i].endHour >> gyvunai[i].endMinute;
            gyvunai[i].startTotal = gyvunai[i].startHour * 60 + gyvunai[i].startMinute;
            gyvunai[i].endTotal = gyvunai[i].endHour * 60 + gyvunai[i].endMinute;

            cout << "Gyvunas: " << gyvunai[i].startHour << " " << gyvunai[i].startMinute << " " << gyvunai[i].endHour << " " << gyvunai[i].endMinute << " " << endl;;
            
            
            
            if (i == 0) continue;

            //Check if there is an intersection
            //Holding value of current possible intersection
            else if (checkforIntersect(gyvunai[i-1], gyvunai[i]) == true)
                {
                    found = true;
                    mini = min(gyvunai[i].endTotal, gyvunai[i-1].endTotal); //pabaiga
                    maxi = max(gyvunai[i].startTotal, gyvunai[i-1].startTotal); //pradzia
                }
            else found = false;

        }
    }

    else cout << "Nepalyginsi tik 1 gyvuno" << endl;

    if (found == true)
    {
        cout << "TAIP" << endl;
        cout << maxi / 60 << " " << maxi % 60 << " " << mini / 60 << " " << maxi % 60;
    }
    else {
            cout << "NE" << endl;
            cout << "maxi: " << maxi << endl;
            cout << "mini: " << mini << endl;
    }


    return 0;
}


