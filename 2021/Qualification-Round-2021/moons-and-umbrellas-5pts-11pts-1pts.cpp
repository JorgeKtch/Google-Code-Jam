#include<bits/stdc++.h>
using namespace std;
void replace(string &s, int first, int last){
    char c;
    if(first == -1 && last == s.length()){
        c = 'J';
    }else{
        if(last == s.length()) c = s[first];
        else c = s[last];
    }
    for(int pos=first+1; pos<last; pos++){
        s[pos] = c;
    }
}
int main(){
    int t; cin >> t;
    for(int c=0; c<t; c++){
        int x, y;
        cin >> x >> y;
        string s;
        cin >> s;
        int first = -1, last, pos = 0;
        bool acum = false;
        while(pos < s.length()){
            if(s[pos] == 'C' || s[pos] == 'J'){
                if(acum){
                    last = pos;
                    acum = false;
                    replace(s, first, last);
                }else{
                    first = pos;
                }
            }else if(s[pos] == '?'){
                if(acum){
                    last = pos+1;
                }else{
                    first = pos-1;
                    last = pos+1;
                    acum = true;
                }
            }
            pos++;
        }
        if(acum){
            last = s.length();
            replace(s, first, last);
        }
        int cost = 0;
        if(s.length()>1){
            for(int i=0; i<s.length()-1; i++){
                if(s[i]=='C' && s[i+1]=='J'){
                    cost += x;
                }else if(s[i]=='J' && s[i+1]=='C'){
                    cost += y;
                }
            }
        }
        cout << "Case #" << c+1 << ": " << cost << endl;
    }
    return 0;
}