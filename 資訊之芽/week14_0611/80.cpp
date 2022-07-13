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
    int mn;
};

int arr[1000005];
s st[2000005];
int k=1;
void build(int l, int r, int idx){
    st[idx].l=l, st[idx].r=r;
    if(l+1==r){
        st[idx].mn=arr[l];
    }
    else{
        int m=(l+r)/2;
        int li=st[idx].lc=k++;
        int ri=st[idx].rc=k++;
        build(l,m,li);
        build(m,r,ri);
        st[idx].mn=min(st[li].mn, st[ri].mn);
    }
}

void modify(int x, int v, int idx){
    if(st[idx].l+1==st[idx].r) st[idx].mn=v;
    else{
        int m=(st[idx].l+st[idx].r)/2;
        if(x<m) modify(x,v,st[idx].lc);
        else modify(x,v,st[idx].rc);
        st[idx].mn=min(st[st[idx].lc].mn, st[st[idx].rc].mn);
    }
}

int query(int l, int r,int idx){
    if(st[idx].l==l && st[idx].r==r) return st[idx].mn;
    int m=(st[idx].l+st[idx].r)/2;
    if(r<=m) return query(l,r,st[idx].lc);
    else if(l>=m) return query(l,r,st[idx].rc);
    else return min(query(l,m,st[idx].lc),query(m,r,st[idx].rc));
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t,n;
    cin >> t >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    build(0,n,0);
    while(t--){
        int a,x,y;
        cin >> a >> x >> y;
        if(a==1) cout << query(x,y+1,0) << '\n';
        else modify(x,y,0);
    }
    return 0;
}
