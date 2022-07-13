#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[112345];

void f(int n){
    if(n==1) a[0]=1;
    else if(n%2==0){
        f(n/2);
        for(int i=0; i<n/2; i++) a[i]=a[i]*2-1;
        for(int i=n/2; i<n; i++) a[i]=a[i-n/2]+1;
    }
    else{
        f((n+1)/2);
        for(int i=0; i<(n+1)/2; i++) a[i]=a[i]*2-1;
        int k=0;
        for(int i=(n+1)/2; k<(n+1)/2; k++){
            if(a[k]!=n) a[i++]=a[k]+1;
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    f(n);
    for(int i=0; i<n; i++) cout << a[i] << ' ';
    cout << '\n';
    return 0;
}