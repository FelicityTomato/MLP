#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
#define pb push_back

int arr[3][3];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        string s;
        int O=0, X=0;
        for(int i=0; i<3; i++){
            cin >> s;
            for(int j=0; j<3; j++){
                if(s[j]=='O'){
                    arr[i][j]=1;
                    O++;
                }
                else if(s[j]=='X'){
                    arr[i][j]=2;
                    X++;
                }
                else arr[i][j]=0;
            }
        }
        if(O>X || X>O+1){
            cout << "Cheating!\n";
            continue;
        }
        int win=0, cheat=0;
        for(int i=0; i<3; i++){
            if(arr[i][0]!=0 && arr[i][0]==arr[i][1] && arr[i][1]==arr[i][2]){
                if(win==0) win=arr[i][0];
                else cheat=1;
            }
        }
        if(cheat==0){
            for(int i=0; i<3; i++){
                if(arr[0][i]!=0 && arr[0][i]==arr[1][i] && arr[1][i]==arr[2][i]){
                    if(win==0) win=arr[0][i];
                    else cheat=1;
                }
            }
        }
        if(cheat==0){
            if(arr[0][0]!=0 && arr[0][0]==arr[1][1] && arr[1][1]==arr[2][2]){
                if(win==0) win=arr[0][0];
                else cheat=1;
            }
        }
        if(cheat==0){
            if(arr[0][2]!=0 && arr[0][2]==arr[1][1] && arr[1][1]==arr[2][0]){
                if(win==0) win=arr[0][2];
                else cheat=1;
            }
        }
        if(cheat==1) cout << "Cheating!\n";
        else if(win==0){
            if(O+X==9) cout << "Tie\n";
            else cout << "Not yet\n";
        }
        else{
            if(win==1) cout << "O win\n";
            else cout<< "X win\n";
        }
    }
    return 0;
}
