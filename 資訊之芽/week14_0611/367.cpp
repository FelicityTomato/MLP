#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
#define pb push_back

struct s{
    int l,r;
    int lc, rc;
    ll mx,tag;
};

int n,q;
ll arr[100005];
s st[200005];
int stpr=1;

void build(int l, int r, int idx){
    st[idx].l=l, st[idx].r=r;
    st[idx].tag=0;
    if(l+1==r){
        st[idx].mx=arr[l];
        return;
    }
    int m=(l+r)/2;
    int lc=st[idx].lc=stpr++;
    int rc=st[idx].rc=stpr++;
    build(l,m,lc);
    build(m,r,rc);
    st[idx].mx=max(st[lc].mx, st[rc].mx);
}

void push(int idx){
    if(st[idx].tag==0) return;
    if(st[idx].l+1<st[idx].r){
        int lc=st[idx].lc, rc=st[idx].rc;
        st[lc].tag+=st[idx].tag;
        st[rc].tag+=st[idx].tag;
        st[lc].mx+=st[idx].tag;
        st[rc].mx+=st[idx].tag;
    }
    st[idx].tag=0;
}

void modify(int x, int l, int r, int idx){
    if(r<=st[idx].l || l>=st[idx].r) return;
    if(l<=st[idx].l && st[idx].r<=r){
        st[idx].tag+=x;
        st[idx].mx+=x;
        return;
    }
    push(idx);
    int lc=st[idx].lc, rc=st[idx].rc;
    modify(x,l,r,lc);
    modify(x,l,r,rc);
    st[idx].mx=max(st[lc].mx, st[rc].mx);
}

ll query(int l, int r, int idx){
    if(r<=st[idx].l || l>=st[idx].r) return 0;
    if(l<=st[idx].l && st[idx].r<=r) return st[idx].mx;
    push(idx);
    int lc=st[idx].lc, rc=st[idx].rc;
    return max(query(l,r,lc), query(l,r,rc));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> arr[i];
    build(1,n+1,0);
    while(q--){
        int k;
        cin >> k;
        if(k==1){
            int l,r,x;
            cin >> l >> r >> x;
            modify(x,l,r+1,0);
        }
        else{
            int l,r;
            cin >> l >> r;
            cout << query(l,r+1,0) << '\n';
        }
    }
    return 0;
}
