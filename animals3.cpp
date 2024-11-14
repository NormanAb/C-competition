#include <iostream>
#include <vector>


using namespace std;


struct gyvunas {

    int startHour;
    int startMinute;

    int endHour;
    int endMinute;

    int startTotal;

    int endTotal;

};

bool checkforIntersect(gyvunas a, gyvunas b) {
    cout << "A startTotal: " << a.startTotal << " B start total " << b.startTotal << endl;
    cout << "A endTotal: " << a.endTotal << " B end total " << b.endTotal << endl;
    if (a.startTotal < b.endTotal && b.startTotal < a.endTotal) { //finding the highest starting time and smallest ending time
        return true;
    }
    //a.endTotal > b.startTotal || b.startTotal < a.endTotal
    else return false;

    //kaip aprasyti intervala kaip viena objekta isduodama?
}


int main() {
    
    int mini = 60 * 24;
    int maxi = 0;

    int n;
    cout << "Irasykite n skaiciu: " << endl;
    cin >> n;

    bool found = false;

    vector<gyvunas> gyvunai(n);

    if (n > 1) {
         for (int i=0; i < n; i ++)
        { //obtain data
            cout << "Irasykite gyvuno intervala: " << endl;
            cin >> gyvunai[i].startHour >> gyvunai[i].startMinute >> gyvunai[i].endHour >> gyvunai[i].endMinute;
            
            
            gyvunai[i].startTotal = gyvunai[i].startHour * 60 + gyvunai[i].startMinute;
            gyvunai[i].endTotal = gyvunai[i].endHour * 60 + gyvunai[i].endMinute;

            cout << "Gyvunas: " << gyvunai[i].startHour << " " << gyvunai[i].startMinute << " " << gyvunai[i].endHour << " " << gyvunai[i].endMinute << " " << endl;;


            //Check if there is an intersection
            //Holding value of current possible intersection
            if ( i > 0 && checkforIntersect(gyvunai[i-1], gyvunai[i]) == true)
                {
                    found = true;
                    mini = min(mini, gyvunai[i].endTotal, gyvunai[i-1].endTotal); //pabaiga
                    maxi = max(maxi, gyvunai[i].startTotal, gyvunai[i-1].startTotal); //pradzia
                    
                    cout << "Mini: " << mini << " Maxi: " << maxi << endl;
            }
        }
    }

    else cout << "Nepalyginsi tik 1 gyvuno" << endl;

    if (found)
    {
        cout << "TAIP" << endl;
        cout << maxi / 60 << " " << maxi % 60 << " " << mini / 60 << " " << mini % 60;
    }
    else {
            cout << "NE" << endl;
            cout << "maxi: " << maxi << endl;
            cout << "mini: " << mini << endl;
    }


    return 0;
}
