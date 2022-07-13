#include<bits/stdc++.h>
using namespace std;

struct k{
    int val;
    int lc,rc;
};
int last=0;
k arr[2123];
void build(int idx, int v){
    if(v<arr[idx].val){
        if(arr[idx].lc==0){
            arr[last].val=v;
            arr[idx].lc=last;
            arr[last].lc=0; arr[last].rc=0;
            last++;
        }
        else build(arr[idx].lc, v);
    }
    else{
        if(arr[idx].rc==0){
            arr[last].val=v;
            arr[idx].rc=last;
            arr[last].lc=0; arr[last].rc=0;
            last++;
        }
        else build(arr[idx].rc, v);
    }

}

void print(int idx){
    if(arr[idx].lc!=0) print(arr[idx].lc);
    if(arr[idx].rc!=0) print(arr[idx].rc);
    cout << arr[idx].val << '\n';
    return; 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    arr[0].lc=0; arr[0].rc=0;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        build(0,a);
    }
    print(0);
    return 0;
}