#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n; 
ll arr[1123456], pre[1123456];
ll mod=10000019;

ll merge(ll l, ll r){
    if(l+1==r) return 0;
    ll m=l+(r-l)/2;
    ll sum=(merge(l,m)+merge(m,r))%mod, cnt=0;
    ll j=m, idx=0;
    ll tmp[r-l], pre=0;
    for(ll i=l; i<m; i++){
        while(j<r && arr[j]<arr[i]){
            pre+=arr[j];
            tmp[idx++]=arr[j++];
        }
        tmp[idx++]=arr[i];
        cnt+=(pre+(j-m)*arr[i])%mod;
        //for(int i=0; i<n; i++) cout << arr[i] << ' ' ; cout << endl;
        //cout << arr[i] << ' ' << arr[j-1] <<' ' <<m << ' '<< pre[j-1]-pre[m-1]+(j-m)*arr[i] << '\n';
        cnt%=mod;
    }
    for(int i=l; i<j; i++) arr[i]=tmp[i-l];
    return (sum+cnt)%mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    //pre[0]=arr[0];
    //for(int i=1; i<n; i++) pre[i]=pre[i-1]+arr[i];
    cout << merge(0,n) << '\n';
    return 0;
}