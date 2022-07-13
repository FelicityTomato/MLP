#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int arr[2000][2000];
/*
void Report(int a){
    return;
}
*/
void dc(int x, int y, int n){
    if(n==2){
        arr[x][y]=1;
        arr[x+1][y]=3;
        arr[x][y+1]=2;
        arr[x+1][y+1]=1;
        return;
    }
    dc(x, y, n/2);
    for(int i=x; i<x+n/2; i++) for(int j=y; j<y+n/2; j++) arr[i+n/2][j+n/2]=arr[i][j];
    for(int i=0; i<n/2; i++) for(int j=0; j<n/2; j++) arr[x+i][x+n/2+j]=n+(i+j)%(n/2);
    for(int i=0; i<n/2; i++) for(int j=0; j<n/2; j++) arr[x+n/2+i][x+j]=n+n/2+(i+j)%(n/2);
    return;
}

void solve(int n){
    dc(0,0,n);
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) Report(arr[i][j]);
}
/*
int main(){
    int n; cin >> n;
    solve(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cout << arr[i][j] << ' ';
        cout << endl;
    }
}
*/