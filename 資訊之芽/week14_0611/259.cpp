#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
#define pb push_back

ll arr[2000005]={0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    while(m--){
        int op;
        cin >> op;
        if(op==1){
            int l,r,h;
            cin >> l >> r >> h;
            for(int i=l; i<=r; i++) if(arr[i]<h) arr[i]=h;
        }
        else{
            int l,r,h;
            cin >> l >> r >> h;
            for(int i=l; i<=r; i++) if(arr[i]>h) arr[i]=h;
        }
    }
    for(int i=0; i<n; i++) cout << arr[i] << '\n';
    return 0;
}