#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
#define pb push_back

ll arr[100005];
ll ans[100005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        for(int i=0; i<n; i++) cin >> arr[i];
        for(int i=0; i<n; i++) ans[i]=0;
        ans[0]=m;
        int idx=0;
        for(int i=0; i<n; i++){
            int k=0,k2=0;
            if(2*arr[i]>=m){
                k2=upper_bound(ans, ans+idx+1, 2*arr[i])-ans;
                if(ans[k2]==0) ans[k2]=2*arr[i];
                else ans[k2]=min(ans[k2], 2*arr[i]);
                //idx=max(idx,k);
            }
            if(arr[i]>=m){
                k=upper_bound(ans, ans+idx+1, arr[i])-ans;
                if(ans[k]==0) ans[k]=arr[i];
                else ans[k]=min(ans[k], arr[i]);
                //idx=max(idx,k);
            }
            idx=max(idx,max(k, k2));
        }
        cout << idx << '\n';
        //for(int i=0; i<=idx; i++) cout << ans[i] << ' '; cout << '\n';
    }
    return 0;
}