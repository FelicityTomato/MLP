#include<bits/stdc++.h>
using namespace std;
const int MAX=112345;
struct bst{
    int val;
    int lc, rc;
};
bst arr[MAX];
int last=0;
void build(int idx, int v){
    if(v<arr[idx].val){
        if(arr[idx].lc) build(arr[idx].lc,v);
        else{
            arr[idx].lc=last;
            arr[last].lc=0; arr[last].rc=0;
            arr[last].val=v;
            last++;
        }
    }
    else{
        if(arr[idx].rc) build(arr[idx].rc,v);
        else{
            arr[idx].rc=last;
            arr[last].lc=0; arr[last].rc=0;
            arr[last].val=v;
            last++;
        }
    }
}
void del(int idx, int v, int p, bool b){
    if(p==-1){
        if(arr[idx].val==v){
            p=idx;
            if(arr[idx].rc!=0) del(arr[idx].rc, v, p,0);
            if(b==0 && arr[idx].lc!=0){
                b=1;
                arr[p].val=arr[arr[idx].lc].val;
                arr[idx].lc=0;
            }
        }
        else if(arr[idx].val<v) del(arr[idx].rc, v, p, 0);
        else del(arr[idx].lc, v, p, 0);
    }
    else{
        if(arr[idx].rc!=0) del(arr[idx].rc, v, p,0);
        if(b==0 && arr[idx].lc!=0){
            b=1;
            arr[p].val=arr[arr[idx].lc].val;
            arr[idx].lc=0;
        }
    }
    return;
}

int query(int idx, int v){
    if(arr[idx].val==v) return idx;
    if(arr[idx].val>v){
        if(arr[idx].lc==0) return idx;
        if(arr[arr[idx].lc].val>v) return query(arr[idx].lc,v);
        else if(arr[idx].val-v<v-arr[arr[idx].lc].val) return idx;
        else return arr[idx].lc;
    }
    else{
        if(arr[idx].rc==0) return idx;
        if(arr[arr[idx].rc].val<v) return query(arr[idx].rc,v);
        else if(v-arr[idx].val<arr[arr[idx].rc].val-v) return idx;
        else return arr[idx].rc;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        string s; int n;
        cin >> s >> n;
        arr[0].lc=0; arr[0].rc=0;
        if(s=="insert"){
            build(0,n);
        }
        else if(s=="delete"){
            del(0,n,-1,0);
        }
        else{
            cout << query(0,n) << '\n';
        }
    }
    return 0;
}