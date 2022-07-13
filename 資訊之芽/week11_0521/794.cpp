#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
#define pb push_back

int n,q;
int arr[500005];
vector<int> v[500005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));
    cin >> n >> q;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        v[arr[i]].pb(i);
    }
    while(q--){
        int a,b;
        cin >> a >> b;
        bool bol=0;
        for(int i=0; i<30; i++){
            int k=arr[rand()%(b-a+1)+a];
            int r=upper_bound(v[k].begin(), v[k].end(), b)-v[k].begin();
            int l=lower_bound(v[k].begin(), v[k].end(), a)-v[k].begin();
            if(2*(r-l)>(b-a+1)){
                cout << k << '\n';
                bol=1;
                break;
            }
        }
        if(bol==0) cout << 0 << '\n';
    }
    return 0;
}