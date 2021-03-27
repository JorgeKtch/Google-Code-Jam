#include<bits/stdc++.h>
using namespace std;
int reversort(vector<int> &arr){
    int cost = 0;
    for(int i=0; i<arr.size()-1; i++){
        int j = std::min_element(arr.begin()+i,arr.end()) - arr.begin();
        reverse(arr.begin()+i, arr.begin()+j+1);
        cost += j-i+1;
    }
    return cost;
}
void generate_data(map<int,map<int,vector<vector<int>>>> &mapa){
    for(int n=2; n<7+1; n++){
        map<int,vector<vector<int>>> temp;
        vector<int> v = vector<int>(n);
        iota(v.begin(), v.end(), 1);
        do {
            vector<int> v_temp = v;
            int cost = reversort(v_temp);
            temp[cost].push_back(v);
        } while (next_permutation(v.begin(), v.end()));
        mapa[n] = temp;
    }
}
int main(){
    int t; cin >> t;
    map<int,map<int,vector<vector<int>>>> mapa;
    generate_data(mapa);
    for(int ci=0; ci<t; ci++){
        int n, c;
        cin >> n >> c;
        cout << "Case #" << ci+1 << ": ";
        if(2<=n && n<=7){
            if(mapa[n][c].size()>0){
                for(int i=0; i<mapa[n][c][0].size(); i++){
                    cout << mapa[n][c][0][i] << " ";
                }
            }else{
                cout << "IMPOSSIBLE";
            }
        }else{
            cout << "IMPOSSIBLE";
        }
        cout << endl;
    }
    return 0;
}