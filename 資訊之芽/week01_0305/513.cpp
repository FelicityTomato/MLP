#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    ll arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    stack<ll> s;
    ll ans[n],mx=0;
    for(int i=0; i<n; i++){
        ans[i]=-1;
        while(s.size()&& arr[s.top()]>arr[i]){
            mx=max(mx,(i-ans[s.top()])*arr[s.top()]);
            //cout << i << ' ' << s.top() << ' ' << ans[s.top()] << ' ' << mx <<'\n';
            ans[i]=ans[s.top()];
            s.pop();
        }
        if(s.empty() || arr[s.top()]<arr[i]) s.push(i);
        if(ans[i]==-1) ans[i]=i;
    }
    while(s.size()){
        //cout << s.top() << ' ' <<ans[s.top()] << '\n';
        mx=max(mx,(n-ans[s.top()])*arr[s.top()]);
        s.pop();
    }
    //for(int i=0; i<n; i++) cout << ans[i] << ' '; cout << '\n';
    cout << mx << '\n';
    return 0;
}   
