#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> boxes{};
vector<int> edges{};
pair<int,int> firstP{};
pair<int,int> lastP{};

/* Kiszámolja a távolságot 2 pont között*/
int calculateDist(pair<int,int> f, pair<int,int> l){
    return sqrt((f.first - l.first)*(f.first - l.first) + (f.second - l.second)* (f.second - l.second));
}

string solve(vector<int> b){
    int counter = 0;
    bool flag{true};

    /* Lemásoljuk a vectort */
    vector<int> e;
    e = edges;
    /* Amíg nem megy végig az összes élen, vagy amíg nem talál egy olyat, amelyet nem lehet kirakni  */
    while(counter < edges.size() && flag == true){
        /*  */
        for(int i = 2; i >= 0; i--){
            /*
            cout << "DEBUG: counter: " << counter << " B[0]: " << b[0] << " B[1]: " << b[1] << " B[2]" << b[2] << endl;
            for(int i: b){
                cout << i << " ";
            }
            cout << endl;
            */
            if(b[i] == 0){
                continue;
            }
            else{
            int a;
            a = e[counter]/(i+1);
            if(a <= b[i]){
                e[counter] -= a * (i+1) ;
                b[i] -= a;
            }
            else{
                e[counter] -= b[i] * (i+1);
                b[i] = 0;
            }

            }
        }
        if(e[counter] > 0){
            flag = false;
            break;
        }
        if(counter < (edges.size()-1) && b[0] == 0 && b[1] == 0 && b[2] == 0){
            flag = false;
            break;
        }
        counter++;
    }
    if(flag == true){
        return "IGEN";
    }
    else{
        return "NEM";
    }
}

int main()
{
    /* Behúzzuk az adatokat */
    int N,D,counter{0};
    cin >> N;
    for(int i =0; i < N; i++){
        int a,b;
        cin >> a >> b;
        /* Amikor az elsõ lépésben vagyunk, akkor nem tudjuk mihez mérni a pontot,
           ezért ezt a pontot elmentjük egy külön változóba is, mivel az utolsó lépésben
           összekötjük azt a pontott ezzel */
        if(counter == 0){
            firstP = make_pair(a,b);
            lastP = make_pair(a,b);
            counter++;
        }
        /* Kiszámolja a távolságot az elõzõ ponthot képest, majd elrakja az élek tömbbe */
        else{
            edges.push_back(calculateDist(lastP,make_pair(a,b)));
            lastP = make_pair(a,b);
            counter++;
        }
        /* Ha az utolsó lépésben vagyunk, akkor összekötjuk az elsõ ponttal*/
        if(counter == N){
            edges.push_back(calculateDist(firstP,make_pair(a,b)));
        }
    }
    /* Sortírozzuk nagyság szerint*/
    sort(edges.begin(),edges.end(),greater<int>());

    /* DEBUG*/
    for(int i =0; i < N; i++){
        cout << edges[i] << " ";
    }
    cout << endl;

    /* Dobozok adatainak beolvasása */
    cin >> D;

    for(int i =0; i < D; i++){
        int a,b,c;
        cin >> a >> b >> c;
        vector<int> t{a,b,c};
        boxes.push_back(t);
    }
    /* Minden egyes dobozra megoldjuk */
    for(int i =0; i < D; i++){
        cout << solve(boxes[i]) << endl;
    }

    return 0;
}

/*
4
0 0
1 0
1 2
0 2
3
6 0 0
2 2 0
1 1 1

*/
