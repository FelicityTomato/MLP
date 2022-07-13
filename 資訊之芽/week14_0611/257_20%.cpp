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
    int c1,c2,c3;
};

int n,m;
s st[2000005];
int k=1;
void build(int l, int r, int idx){
    st[idx].l=l, st[idx].r=r;
    if(l+1==r){
        st[idx].c1=1;
        st[idx].c2=st[idx].c3=0;
    }
    else{
        int m=(l+r)/2;
        int lc=st[idx].lc=k++;
        int rc=st[idx].rc=k++;
        build(l,m,lc);
        build(m,r,rc);
        st[idx].c1=r-l;
        st[idx].c2=st[idx].c3=0;
    }
}

void turn(int x, int idx){
    if(st[idx].l+1==st[idx].r){
        swap(st[idx].c2, st[idx].c3);
        swap(st[idx].c1, st[idx].c2);
    }
    else{
        int m=(st[idx].l+st[idx].r)/2;
        if(x<m) turn(x,st[idx].lc);
        else turn(x,st[idx].rc);
        st[idx].c1=st[st[idx].lc].c1+st[st[idx].rc].c1;
        st[idx].c2=st[st[idx].lc].c2+st[st[idx].rc].c2;
        st[idx].c3=st[st[idx].lc].c3+st[st[idx].rc].c3;
    }
}

void reset(int x, int idx){
    if(st[idx].l+1==st[idx].r){
        st[idx].c1=1;
        st[idx].c2=st[idx].c3=0;
    }
    else{
        int m=(st[idx].l+st[idx].r)/2;
        if(x<m) reset(x,st[idx].lc);
        else reset(x,st[idx].rc);
        st[idx].c1=st[st[idx].lc].c1+st[st[idx].rc].c1;
        st[idx].c2=st[st[idx].lc].c2+st[st[idx].rc].c2;
        st[idx].c3=st[st[idx].lc].c3+st[st[idx].rc].c3;
    }
}

int query(int l, int r,int idx){
    if(st[idx].l==l && st[idx].r==r) return st[idx].c1;
    int m=(st[idx].l+st[idx].r)/2;
    if(r<=m) return query(l,r,st[idx].lc);
    else if(l>=m) return query(l,r,st[idx].rc);
    else return query(l,m,st[idx].lc)+query(m,r,st[idx].rc);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    build(0,n,0);
    while(m--){
        string s;
        int l,r;
        cin >> s>> l >>r;
        if(s=="TURN"){
            for(int i=l-1; i<r; i++) turn(i,0);
        }
        else if(s=="RESET"){
            for(int i=l-1; i<r; i++) reset(i,0);
        }
        else cout << query(l-1,r,0) << '\n';
    }
    return 0;
}
