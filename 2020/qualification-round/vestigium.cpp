#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    for(int c=0; c<t; c++){
        int n; cin >> n;
        int mi; vector<vector<int>> m;
        int trace = 0;
        for(int i=0; i<n; i++){
            vector<int> r;
            for(int j=0; j<n; j++){
                cin >> mi; r.push_back(mi);
                if(i==j) trace += mi;
            }
            m.push_back(r);
        }
        vector<int> voriginal;
        for(int i=0; i<n; i++) voriginal.push_back(i+1);
        int rows_r = 0;
        for(int row=0; row<n; row++){
            vector<int> vrow;
            for(int j=0; j<n; j++){
                vrow.push_back(m[row][j]);
            }
            sort(vrow.begin(), vrow.end());
            if(vrow != voriginal) rows_r++;
        }
        int cols_r = 0;
        for(int col=0; col<n; col++){
            vector<int> vcol;
            for(int i=0; i<n; i++){
                vcol.push_back(m[i][col]);
            }
            sort(vcol.begin(), vcol.end());
            if(vcol != voriginal) cols_r++;
        }
        cout << "Case #" << c+1 << ": " << trace << " " << rows_r << " " << cols_r << "\n";
    }
    return 0;
}