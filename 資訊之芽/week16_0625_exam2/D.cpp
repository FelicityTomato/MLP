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
    ll cnt,tag;
};

int n,q;
ll arr[530005];
s st[1100005];
int stpr=1;

void build(int l, int r, int idx){
    st[idx].l=l, st[idx].r=r;
    st[idx].tag=0;
    if(l+1==r){
        if(idx&1 && arr[l]>=arr[l+1]) st[idx].cnt=1;
        else if(!(idx&1) && arr[l-1]<arr[l]) st[idx].cnt=1;
        return;
    }
    int m=(l+r)/2;
    int lc=st[idx].lc=stpr++;
    int rc=st[idx].rc=stpr++;
    build(l,m,lc);
    build(m,r,rc);
    st[idx].cnt=st[lc].cnt+st[rc].cnt;
}

void push(int idx){
    if(st[idx].tag==0) return;
    if(st[idx].l+1<st[idx].r){
        int lc=st[idx].lc, rc=st[idx].rc;
        st[lc].tag+=st[idx].tag;
        st[rc].tag+=st[idx].tag;
    } 
    else{
        arr[st[idx].l]+=st[idx].tag;
        if(idx&1 && arr[st[idx].l]>=arr[st[idx].l+1]) st[idx].cnt=1;
        else if(!(idx&1) && arr[st[idx].l-1]<arr[st[idx].l]) st[idx].cnt=1;
    }
    st[idx].tag=0;
}

void modify(int x, int l, int r, int idx){
    if(r<=st[idx].l || l>=st[idx].r) return;
    if(st[idx].l+1==st[idx].r){
        arr[st[idx].l]+=x;
        if(idx&1 && arr[st[idx].l]>=arr[st[idx].l+1]) st[idx].cnt=1;
        else if(!(idx&1) && arr[st[idx].l-1]<arr[st[idx].l]) st[idx].cnt=1;
        return;
    }
    if(l<=st[idx].l && st[idx].r<=r){
        st[idx].tag+=x;
        return;
    }
    push(idx);
    int lc=st[idx].lc, rc=st[idx].rc;
    modify(x,l,r,lc);
    modify(x,l,r,rc);
    st[idx].cnt=st[lc].cnt+st[rc].cnt;
}

ll query(int l, int r, int idx){
    if(r<=st[idx].l || l>=st[idx].r) return 0;
    if(l<=st[idx].l && st[idx].r<=r) return st[idx].cnt;
    push(idx);
    int lc=st[idx].lc, rc=st[idx].rc;
    int m=(st[idx].l+st[idx].r)/2;
    if(r<=m) return query(l,r,lc);
    else if(l>=m) return query(l,r,rc);
    return query(l,m,lc)+query(m,r,rc);
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
