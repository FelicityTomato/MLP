#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
#define pb push_back
ll c=26, m=1000007;
string mp[1000007][3];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));
    string s; cin >> s;
    ll k=0;
    for(int i=0; i<6; i++) k=(k*c+s[i]-'a')%m;
    cout << k << '\n';
    return 0;
}