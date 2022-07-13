#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
#define pb push_back

int n,q;
ll arr[530005];
ll cnt[530005]={0};
struct s{
    int l,r;
    int lc, rc;
    int idx, cnt;
};

s st[2000005];
int k=1;
void build(int l, int r, int idx){
    //cout << l << ' ' << r << '\n';
    st[idx].l=l, st[idx].r=r;
    if(l+1==r){
        st[idx].idx=l;
        st[idx].cnt=0;
    }
    else{
        int m=(l+r)/2;
        int li=st[idx].lc=k++;
        int ri=st[idx].rc=k++;
        build(l,m,li);
        build(m,r,ri);
        if(arr[st[li].idx]>=arr[st[ri].idx]){
            st[idx].idx=st[li].idx;
        }
        else st[idx].idx=st[ri].idx;
        st[idx].cnt=st[li].cnt+st[ri].cnt+1;
    }
}

void modify(int x, int v, int idx){
    if(st[idx].l+1==st[idx].r) arr[st[idx].l]+=v;
    else{
        int m=(st[idx].l+st[idx].r)/2;
        int li=st[idx].lc, ri=st[idx].rc;
        if(x<m) modify(x,v,li);
        else modify(x,v,ri);
        if(arr[st[li].idx]>=arr[st[ri].idx]){
            st[idx].idx=st[li].idx;
        }
        else if(arr[st[li].idx]<arr[st[ri].idx]){
            st[idx].idx=st[ri].idx;
        }
    }
}


int query(int l, int r,int idx){
    if(st[idx].l==l && st[idx].r==r) return st[idx].cnt;
    int m=(st[idx].l+st[idx].r)/2;
    int k=0;
    if(st[idx].idx>=l && st[idx].idx<r) k=1;
    if(r<=m) return query(l,r,st[idx].lc)+k;
    else if(l>=m) return query(l,r,st[idx].rc)+k;
    else return query(l,m,st[idx].lc)+query(m,r,st[idx].rc)+k;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> arr[i];
    build(1,n+1,0);
    //for(int i=1; i<=n; i++) cout << cnt[i] << ' '; cout << '\n';
    while(q--){
        int k;
        cin >> k;
        if(k==1){
            int l,r,x;
            cin >> l >> r >> x;
            for(int i=l; i<=r; i++) modify(i,x,0);
            //for(int i=1; i<=n; i++) cout << cnt[i] << ' '; cout << '\n';
        }
        else{
            int l,r;
            cin >> l >> r;
            cout <<query(l,r+1,0) << '\n';
        }
    }
    return 0;
}
