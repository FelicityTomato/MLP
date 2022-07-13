#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
#define pb push_back

ll b=191, p=1e9+33;
ll k=0, m=0, g=1;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s,t;
    cin >> s >> t;
    for(int i=0; i<s.size(); i++) k=(k*b+s[i])%p;
    for(int i=0; i<s.size()-1; i++) g=(g*b)%p;
    for(int i=0; i<s.size(); i++) m=(m*b+t[i])%p;
    //cout << k << '\n' << m << '\n';
    for(int i=s.size(); i<t.size(); i++){
        if(m==k) cout << i-s.size() << ' ';
        m=(((((m-t[i-s.size()]*g)%p+p)%p)*b+t[i]))%p;
        //cout << m << '\n';
    }
    if(m==k) cout << t.size()-s.size() << ' ';
    cout << '\n';
    return 0;
}