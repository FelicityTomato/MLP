#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
#define pb push_back

ll b1=191, b2=29137,b3=29137, p1=1e9+33, p2=73939133, p3=1e9+9;
ll k1=0, k2=0, k3=0, m1=0, m2=0, m3=0, g1=1, g2=1, g3=1;
vector<int> v;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s,t;
    cin >> s >> t;
    for(int i=0; i<s.size(); i++) k1=(k1*b1+s[i])%p1;
    for(int i=0; i<s.size(); i++) k2=(k2*b2+s[i])%p2;
    for(int i=0; i<s.size(); i++) k3=(k3*b3+s[i])%p3;
    for(int i=0; i<s.size()-1; i++) g1=(g1*b1)%p1;
    for(int i=0; i<s.size()-1; i++) g2=(g2*b2)%p2;
    for(int i=0; i<s.size()-1; i++) g3=(g3*b3)%p3;
    for(int i=0; i<s.size(); i++) m1=(m1*b1+t[i])%p1;
    for(int i=0; i<s.size(); i++) m2=(m2*b2+t[i])%p2;
    for(int i=0; i<s.size(); i++) m3=(m3*b3+t[i])%p3;
    //cout << k << '\n' << m << '\n';
    for(int i=s.size(); i<t.size(); i++){
        if(m1==k1 && m2==k2 && m3==k3) v.pb(i-s.size());
        m1=(((((m1-t[i-s.size()]*g1)%p1+p1)%p1)*b1+t[i]))%p1;
        m2=(((((m2-t[i-s.size()]*g2)%p2+p2)%p2)*b2+t[i]))%p2;
        m3=(((((m3-t[i-s.size()]*g3)%p3+p3)%p3)*b3+t[i]))%p3;
        //cout << m << '\n';
    }
    if(m1==k1 && m2==k2 && m3==k3) v.pb(t.size()-s.size());
    for(int i=0; i<v.size(); i++) cout << v[i] << " \n"[i==v.size()-1];
    if(v.size()==0) cout << '\n';
    return 0;
}