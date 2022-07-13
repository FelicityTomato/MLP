#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

ll arr[1000005],h=73939133, bs=29137;
vector<int> v;
ll hsh_1(string s){
    int cnt=0;
    for(char c:s){
        cnt=(cnt*bs+c)%h;
    }
    return cnt;
}

void hsh_2(string s){
    int cnt=0;
    for(int i=0; i<s.size(); i++){
        cnt=(cnt*bs+s[i])%h;
        arr[i]=cnt;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a,b;
    cin >> a >> b;
    ll tmp=hsh_1(a);
    hsh_2(b);
    ll pw=1;
    for(int i=0; i<a.size(); i++) pw=(pw*bs)%h;
    int ans=0;
    if(arr[a.size()-1]==tmp) v.pb(0);
    for(int i=a.size(); i<b.size(); i++){
        if((arr[i]-pw*arr[i-a.size()]%h+h)%h==tmp) v.pb(i - a.size()+1);
    }
    for(int i=0; i<v.size(); i++) cout << v[i] << " \n"[i==v.size()-1];
    return 0;
}
