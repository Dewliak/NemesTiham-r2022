#include <bits/stdc++.h>

using namespace std;

vector<int> hogolyok{};

/*
Módszer:
    Priority queueban tárolom a hógolyókat, és egy másik tömbben a gyerek utolsó magasságát, mivel a prio q sorba van rendezve,
    ezért errõlrõl indulva folyamatosan csökken a hógolyók nagysága. Ha az elõzõnél egyenlõ akkor nem megy tovább mert az utána
    lévõ biztosan egyenlõ vagy kisebb nála. Tehát ha kimondottan kisebb akkor megy csak tovább.

*/


int main()
{

    int N,D;

    priority_queue<int> pq;
    cin >> N >> D;
    int gyerekek [D];
    int gyerekCounter = 0, height = 0;
    // init list to max
    for(int i =0; i < D; i++){
        gyerekek[i] = 1000000001; // max + 1 mert ez biztos nagyobb mitn a leheto legnagyobb
    }
    for(int i = 0; i < N ; i++){
        int a;
        cin >> a;
        pq.push(a);
    }

    while(!pq.empty()){
        int top = pq.top();
        pq.pop();
        // A mostani gyerek mostani hogolya kimondottan nagyobb mint a mostani
        if(gyerekek[gyerekCounter % D] >  top){
            gyerekek[gyerekCounter % D] = top;
            // Ha a vegen van, akkor noveljuk a max magassagot 1-el
            if((gyerekCounter % D) == D-1){
                height++;
            }
            gyerekCounter += 1;
        }
    }
    cout << height << endl;
    return 0;
}

/*
6 2
1 4 2 1 5 1
*/
