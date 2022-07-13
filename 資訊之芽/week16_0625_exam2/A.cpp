#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
#define pb push_back

const int mod=1e9+7;
const int N = 205, W = 200005;
ll cost[N], weight[N];
ll c[W + 1]={0};
ll way[W + 1]={0}; 

void knapsack(int n, int w)
{
    way[0] = 1;
    for (int i = n-1; i >= 0; i--){
        for (int j = w; j >= weight[i]; j--){
            if (c[j - weight[i]] + cost[i] < c[j])
                {   
    //              way[j] = way[j];
                }
            else if (c[j - weight[i]] + cost[i] > c[j])
            {
                c[j] = c[j - weight[i]] + cost[i];
                way[j] = way[j - weight[i]];
            }
            else 
            {
                way[j] = way[j] + way[j - weight[i]];
                way[j]%=mod;
            }
        }
    }
    cout << c[w] << ' '<< way[w] << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,c; 
    cin >> n >> m >> c;
    for(int i=0; i<n; i++) cin >> weight[i] >> cost[i];
    knapsack(n,c);
    return 0;
}