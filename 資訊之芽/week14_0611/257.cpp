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
    ll c1,c2,c3;
    ll plus;
    bool b;
};

int n,m;
s st[4000005];
int stpr=1;

void build(int l, int r, int idx){
    st[idx].l=l, st[idx].r=r;
    if(l+1==r){
        st[idx].lc=-1;
        st[idx].rc=-1;
        st[idx].c1=1;
        st[idx].c2=st[idx].c3=st[idx].plus=st[idx].b=0;
    }
    else{
        int lc=st[idx].lc=stpr++;
        int rc=st[idx].rc=stpr++;
        int m=(l+r)/2;
        build(l,m,lc);
        build(m,r,rc);
        st[idx].c1=r-l;
        st[idx].c2=st[idx].c3=st[idx].plus=st[idx].b=0;
    }
}

void push(int idx){
    int lc=st[idx].lc, rc=st[idx].rc;
    if(st[idx].b==1){
        if(lc!=-1){
            st[lc].b=1;
            st[lc].plus=0;
            st[lc].c1=st[lc].r-st[lc].l;
            st[lc].c2=st[lc].c3=0;
        }
        if(rc!=-1){
            st[rc].b=1;
            st[rc].plus=0;
            st[rc].c1=st[rc].r-st[rc].l;
            st[rc].c2=st[rc].c3=0;
        }
        st[idx].b=0;
    }
    if(st[idx].plus>0){
        if(lc!=-1){
            st[lc].plus+=st[idx].plus;
            if(st[idx].plus%3==1){
                swap(st[lc].c2, st[lc].c3);
                swap(st[lc].c1, st[lc].c2);
            }
            else if(st[idx].plus%3==2){
                swap(st[lc].c1, st[lc].c3);
                swap(st[lc].c1, st[lc].c2);
            }
        }
        if(rc!=-1){
            st[rc].plus+=st[idx].plus;
            if(st[idx].plus%3==1){
                swap(st[rc].c2, st[rc].c3);
                swap(st[rc].c1, st[rc].c2);
            }
            else if(st[idx].plus%3==2){
                swap(st[rc].c1, st[rc].c3);
                swap(st[rc].c1, st[rc].c2);
            }
        }
        st[idx].plus=0;
    }
}
void turn(int l, int r, int idx){
    if(r<=st[idx].l || l>=st[idx].r) return;
    if(l<=st[idx].l && st[idx].r<=r){
        st[idx].plus++;
        swap(st[idx].c2, st[idx].c3);
        swap(st[idx].c1, st[idx].c2);
    }
    else{
        push(idx);
        int lc=st[idx].lc, rc=st[idx].rc;
        turn(l,r,lc);
        turn(l,r,rc);
        st[idx].c1=st[idx].c2=st[idx].c3=0;
        if(lc!=-1){
            st[idx].c1+=st[lc].c1;
            st[idx].c2+=st[lc].c2;
            st[idx].c3+=st[lc].c3;
        }
        if(rc!=-1){
            st[idx].c1+=st[rc].c1;
            st[idx].c2+=st[rc].c2;
            st[idx].c3+=st[rc].c3;
        }
    }
}

void reset(int l, int r, int idx){
    if(r<=st[idx].l || l>=st[idx].r) return;
    if(l<=st[idx].l && st[idx].r<=r){
        st[idx].b=1;
        st[idx].plus=0;
        st[idx].c1=st[idx].r-st[idx].l;
        st[idx].c2=st[idx].c3=0;
    }
    else{
        push(idx);
        int lc=st[idx].lc, rc=st[idx].rc;
        reset(l,r,st[idx].lc);
        reset(l,r,st[idx].rc);
        st[idx].c1 =st[idx].c2= st[idx].c3 = 0;
        if(lc!=-1){
            st[idx].c1+=st[lc].c1;
            st[idx].c2+=st[lc].c2;
            st[idx].c3+=st[lc].c3;
        }
        if(rc!=-1){
            st[idx].c1+=st[rc].c1;
            st[idx].c2+=st[rc].c2;
            st[idx].c3+=st[rc].c3;
        }
    }
}

ll query(int l, int r, int idx){
    if(r<=st[idx].l || l>=st[idx].r) return 0;
    if(l==st[idx].l && st[idx].r==r) return st[idx].c1;
    push(idx);
    int m=(st[idx].l+st[idx].r)/2;
    if(r<=m) return query(l,r,st[idx].lc);
    else if(l>=m) return query(l,r,st[idx].rc);
    return query(l,m,st[idx].lc)+query(m,r,st[idx].rc);
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
        if(s=="TURN") turn(l-1,r,0);
        else if(s=="RESET") reset(l-1,r,0);
        else cout << query(l-1,r,0) << '\n';
        /*
        for(int i=0; i<stpr; i++){
            cout << st[i].l+1 << ' ' << st[i].r << ' ' << st[i].c1 << ' ' << st[i].c2 << ' ' << st[i].c3 << ' ' << st[i].plus << '\n';
        }
        */
    }
    return 0;
}
