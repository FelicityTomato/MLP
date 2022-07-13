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
    ll mx, lmx, rmx, cnt;
};
int n,q;
ll arr[100005];
s st[400005];
int stpr=1;

void build(int l, int r, int idx){
    st[idx].l=l, st[idx].r=r;
    if(l+1==r){
        st[idx].mx=st[idx].lmx=st[idx].rmx=st[idx].cnt=arr[l];
    }
    else{
        int lc=st[idx].lc=stpr++;
        int rc=st[idx].rc=stpr++;
        int m=(l+r)/2;
        build(l,m,lc);
        build(m,r,rc);
        st[idx].cnt=st[lc].cnt+st[rc].cnt;
        st[idx].lmx=max(st[lc].lmx, st[lc].cnt+st[rc].lmx);
        st[idx].rmx=max(st[rc].rmx, st[rc].cnt+st[lc].rmx);
        st[idx].mx=max(st[lc].rmx+st[rc].lmx, max(st[lc].mx, st[rc].mx));
    }
}

s query(int l, int r, int idx){
    if(st[idx].l==l && st[idx].r==r) return st[idx];
    int m=(st[idx].l+st[idx].r)/2;
    if(r<=m) return query(l,r,st[idx].lc);
    else if(l>=m) return query(l,r,st[idx].rc);
    else{
        s a=query(l,m,st[idx].lc) ,b=query(m,r,st[idx].rc);
        s k;
        k.cnt=a.cnt+b.cnt;
        k.lmx=max(a.lmx, a.cnt+b.lmx);
        k.rmx=max(b.rmx, b.cnt+a.rmx);
        k.mx=max(a.rmx+b.lmx, max(a.mx, b.mx));
        return k;
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i=0; i<n; i++) cin >> arr[i];
    build(0,n,0);
    while(q--){
        int l,r;
        cin >> l >> r;
        cout << max((ll)0,query(l-1,r,0).mx) << '\n';
    }
    return 0;
}
