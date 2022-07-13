#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
#define pb push_back
ll c=26, m=1000007;
string mp[1000007][3];
bool b=0;
void f(string s, ll k, int j){
    if(b==1) return;
    if(j==6){
        if(mp[k][0]=="") mp[k][0]=s;
        else if(mp[k][1]=="") mp[k][1]=s;
        else{
            cout << k << '\n';
            cout << mp[k][0] << ' ' << mp[k][1] << ' ' << s << '\n';
            b=1;
            //cout << k << '\n';
        }
        return;
    }
    for(int i=0; i<26; i++){
        ll t=(k*c+i)%m;
        s[j]=(char)('a'+i);
        f(s,t,j+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));
    for(int i=0; i< 1000007; i++) for(int j=0; j<3; j++) mp[i][j]="";
    f("      ", 0, 0);
    return 0;
}