#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool find_in(int n,vector<int> arr);
bool solve(vector<vector<int>> doboz,map<int,vector<vector<int>>> szemely_kapcsolatok,int i, int j);

int main()
{
    int N,M; // N - ugynokok szama, M - a a kapcsolatok szama
    vector<vector<int>> kapcsolatok{};
    map<int,vector<vector<int>>> szemely_kapcsolatok;

    // adatok beszerzese
    cin >> N >> M;
    for(int i =0; i < M; i++){
        int k,l;
        cin >> k >> l;
        kapcsolatok.insert(kapcsolatok.end(),{k,l});
        vector<int> kapcsolat_l{k,i},kapcsolat_k{l,i};
        szemely_kapcsolatok[l].push_back(kapcsolat_l);
        szemely_kapcsolatok[k].push_back(kapcsolat_k);
    }
    /* DEBUG: Ki irja az emberekhez tartozo kapcsolatokat
    cout  << endl;
    for(int i = 0; i < N; i++){
        cout << i+1 << ": ";
        for(auto m : szemely_kapcsolatok[i]){
            cout << m << " ";
        }
        cout << endl;
    }
    */
    int counter{0};
    // benne van az osszes hasznalt szamok hogy ne kelljen mindig ujat csinalni
    vector<vector<int>> doboz{};
    for(int i = 0; i < M;i++){
        doboz.clear();
        doboz.push_back(kapcsolatok[i]);
        for(int j = i; j<M;j++){
            if(i != j){
                doboz.push_back(kapcsolatok[j]);
            }
            if(solve(doboz,szemely_kapcsolatok,i,j) == true){
                // ide lehet rakni a debugra a megoldasokat
                //megoldasok.insert(megoldasok.end(),{i,j});
                counter += 1;
            }
            else{
                break; // kilep ha egyik resze nem jo az elso jo ciklusbol, mert intervallumokat keresunk
            }
        }
    }
    cout << endl;
    return 0;
}

bool solve(vector<vector<int>> doboz,map<int,vector<vector<int>>> szemely_kapcsolatok,int i,int j){
    vector<int> used_numbers{};
    for(int a =0; a< doboz.size(); a++){
        vector<int> got_the_intel{};
        for(int b= 0; b< 2; b++){
            //megnezi hogy a szamtol intul e mar-e teszt
            if(find_in(doboz[a][b],used_numbers)==false){
                used_numbers.push_back(doboz[a][b]);

            }
        }
    }

}

bool find_in(int n; vector<int> arr){
    for(int i: arr){
        if(n == arr[i]){
            return true;
        }
    }
    return false;

}



/*
4 5
1 3
3 2
2 1
1 4
4 2
*/
