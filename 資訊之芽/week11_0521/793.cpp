#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
#define pb push_back

int n,k,q;
ll p=1e9+33;
int cnt[500005]={0};
ll ran[500005], arr[500005], f[500005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));
    for(int i=0; i<500005; i++) ran[i]=rand()%INT_MAX;
    cin >> n >> k >> q;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        cnt[arr[i]]++;
        if(cnt[arr[i]]%k==0) f[i]=((f[i-1]-(k-1)*ran[arr[i]])%p+p)%p;
        else f[i]=(f[i-1]+ran[arr[i]])%p;
    }
    for(int i=0; i<q; i++){
        int l,r;
        cin >> l >> r;
        if((f[r]-f[l-1])%p==0) cout << 1;
        else cout << 0;
    }
    cout << '\n';
    return 0;
}
/*
10 2 10
1 2 3 2 4 4 3 1 3 1
1 8
1 10
5 6
1 4
5 10
2 7
1 7
8 9
7 9
3 7
*/