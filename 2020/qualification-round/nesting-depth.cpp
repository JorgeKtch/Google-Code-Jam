#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    for(int c=0; c<t; c++){
        string s; cin >> s;
        vector<vector<char>> data;
        vector<char> temp;
        temp.push_back(s[0]);
        for(int i=1; i<s.length(); i++){
            if(s[i]==s[i-1]){
                temp.push_back(s[i]);
            }else{
                data.push_back(temp);
                temp.clear();
                temp.push_back(s[i]);
            }
        }
        data.push_back(temp);
        string s_new = "", s_temp;
        for(int i=0; i<data.size(); i++){
            s_temp = "";
            for(int j=0; j<data[i][0]-'0'; j++){
                s_temp = "("+s_temp;
            }
            for(int j=0; j<data[i].size(); j++){
                s_temp = s_temp+data[i][j];
            }
            for(int j=0; j<data[i][0]-'0'; j++){
                s_temp = s_temp+")";
            }
            s_new += s_temp;
        }
        cout << "Case #" << c+1 << ": " << s_new << "\n";
    }
    return 0;
}