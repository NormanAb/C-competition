#include <iostream>
#include <vector>

using namespace std;

struct uzsakymai {
    int time; //laikas kada gautas
    int value; //uzsakymo verte
};

struct vairuotojai {
    int revenue = 0;
    int timeRequired; //per kiek laiko gali ivykdyti uzsakyma
    int orderStartTime = 0;

    int orderEndTime = 0; //iki kada atliks savo uzsakyma

    bool avaliable(int orderTime) {
        if (orderTime >= orderEndTime || orderEndTime == 0) return true;
        else return false;
    }; //ar jis yra uzimtas ar ne

};



int main () 
{
    int n;
    int m;
    int mini = 101;
    int index;
    int found = false;


    cin >> n >> m;
    
    vector<vairuotojai> vairuotojas(n);

    vector<uzsakymai> uzsakymas(m);



    for (int i=0; i < m; i++) 
    {
        cin >> uzsakymas[i].time  >> uzsakymas[i].value;

        for (int k=0; k < n; k++) 
        {
            
            cin >> vairuotojas[k].timeRequired;
            
            if (vairuotojas[k].avaliable(uzsakymas[i].time)) {
                if ( vairuotojas[k].timeRequired < mini) {
                    mini = min(mini, vairuotojas[k].timeRequired);
                    index = k;
                }

                found = true;
            }
        }

        if (found == false) {
            continue;
        }

        else {
            vairuotojas[index].orderStartTime = uzsakymas[i].time;
            vairuotojas[index].revenue += uzsakymas[i].value;

            vairuotojas[index].orderEndTime = vairuotojas[index].orderStartTime + vairuotojas[index].timeRequired;
        }

        found = false; //reset flag
        mini = 101; //reset minimum
    }


    for (vairuotojai i : vairuotojas) { //atsakymo isvedimas
        cout << i.revenue << " ";
    }

    return 0;

    //
}