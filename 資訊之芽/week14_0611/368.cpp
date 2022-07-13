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
    ll mx,add,chg;
};

int n,q;
ll arr[100005];
s st[200005];
int stpr=1;

void build(int l, int r, int idx){
    st[idx].l=l, st[idx].r=r;
    st[idx].add=st[idx].chg=0;
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
    int lc=st[idx].lc, rc=st[idx].rc;
    if(st[idx].chg!=0){
        if(st[idx].l+1<st[idx].r){
            st[lc].chg=st[idx].chg;
            st[rc].chg=st[idx].chg;
            st[lc].add=0;
            st[rc].add=0;
            st[lc].mx=st[idx].chg;
            st[rc].mx=st[idx].chg;
        }
        st[idx].chg=0;
    }
    if(st[idx].add!=0){
        if(st[idx].l+1<st[idx].r){
            st[lc].add+=st[idx].add;
            st[rc].add+=st[idx].add;
            st[lc].mx+=st[idx].add;
            st[rc].mx+=st[idx].add;
        }
        st[idx].add=0;
    }
}

void add(int x, int l, int r, int idx){
    if(r<=st[idx].l || l>=st[idx].r) return;
    push(idx);
    if(l<=st[idx].l && st[idx].r<=r){
        st[idx].add += x;
        st[idx].mx+=x;
        return;
    }
    //push(idx);
    int lc=st[idx].lc, rc=st[idx].rc;
    add(x,l,r,lc);
    add(x,l,r,rc);
    st[idx].mx=max(st[lc].mx, st[rc].mx);
}

void chg(int x, int l, int r, int idx){
    if(r<=st[idx].l || l>=st[idx].r) return;
    push(idx);
    if(l<=st[idx].l && st[idx].r<=r){
        st[idx].chg=x;
        st[idx].mx=x;
        st[idx].add=0;
        return;
    }
    //push(idx);
    int lc=st[idx].lc, rc=st[idx].rc;
    chg(x,l,r,lc);
    chg(x,l,r,rc);
    st[idx].mx=max(st[lc].mx, st[rc].mx);
}

ll query(int l, int r, int idx){
    if(r<=st[idx].l || l>=st[idx].r) return 0;
    if(l==st[idx].l && st[idx].r==r) return st[idx].mx;
    push(idx);
    int lc=st[idx].lc, rc=st[idx].rc;
    int m=(st[idx].l+st[idx].r)/2;
    if(r<=m) return query(l,r,lc);
    else if(l>=m) return query(l,r,rc);
    return max(query(l,m,lc), query(m,r,rc));
}

void print_debug() {
    for (int i=0; i<stpr; i++ ) {
        s S = st[i];
        cout << "idx(l, r) = " << i  << " ( " <<  S.l << ", " << S.r << " )"
        << "  max = " << S.mx
        << "  (lc, rc = ( " <<  S.lc << ", " << S.rc << " )"
        << "  ( add, chg ) = ( " <<  S.add << ", " << S.chg << " )"
        << endl;
    }
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
            add(x,l,r+1,0);
        }
        else if(k==2){
            int l,r;
            cin >> l >> r;
            cout << query(l,r+1,0) << '\n';
        }
        else if (k==0) {
            print_debug();
        }
        else{
            int l,r,x;
            cin >> l >> r >> x;
            chg(x,l,r+1,0);
        }
    }
    return 0;
}
