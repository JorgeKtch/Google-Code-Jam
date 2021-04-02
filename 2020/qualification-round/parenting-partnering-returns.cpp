#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    for(int c=0; c<t; c++){
        int n; cin >> n;
        vector<int> s; int si;
        vector<int> e; int ei;
        map<int, map<int, int>> m;
        bool possible = true;
        for(int i=0; i<n; i++){
            cin >> si; s.push_back(si);
            cin >> ei; e.push_back(ei);
            for(int j=si; j<ei; j++){
                m[j][j+1] ++;
                if(m[j][j+1]>2){
                    possible = false;
                    break;
                }
            }
            if(!possible){
                break;
            }
        }
        if(possible){
            for(int i=0; i<n; i++){
                int is_c = true;
                for(int j=s[i]; j<e[i]; j++){
                    if(m[j][j+1]==1){
                        is_c = false;
                        break;
                    }
                }
                if(is_c) cout << "C";
                else cout << "J";
            }
        }else{
            cout << "IMPOSSIBLE";
        }
        cout << "\n";
    }
    return 0;
}