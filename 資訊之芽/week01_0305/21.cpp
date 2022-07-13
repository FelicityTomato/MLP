#include<bits/stdc++.h>
using namespace std;
int n,m;
struct link{
    int arr[112345][2];
    bool b[112345];
    void mk(){
        for(int i=1; i<=n; i++){
            arr[i][0]=i-1;
            arr[i][1]=i+1;
            b[i]=1;
        }
    }
    int x(int a){
        return arr[a][0];
    }
    int y(int a){
        return arr[a][1];
    }
    void pop(int a){
        arr[x(a)][1]=y(a);
        arr[y(a)][0]=x(a);
        arr[a][0]=-1;
        arr[a][1]=01;
        b[a]=0;
    }
    void mv(int a){
        if(x(a)==0) return;
        int t1=x(x(a)), t2=x(a), t3=a, t4=y(a);
        arr[t3][0]=t1;
        arr[t3][1]=t2;
        arr[t1][1]=t3;
        arr[t2][0]=t3;
        arr[t2][1]=t4;
        arr[t4][0]=t2;
    }
    void print(int idx){
        cout << ' ' << idx;
        if(y(idx)==n+1) return;
        print(y(idx));
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    link l;
    l.mk();
    while(m--){
        int a, b;
        cin >> a >> b;
        if(a==0) l.pop(b);
        else l.mv(b);
    }
    int k;
    for(int i=1; i<=n; i++){
        if(l.arr[i][0]==0 && l.b[i]){
            k=i;
            break;
        }
    }
    cout << k ;
    l.print(l.y(k));
    cout << '\n';
    return 0;
}   
