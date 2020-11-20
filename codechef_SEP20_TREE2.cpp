#include <bits/stdc++.h>

using namespace std;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define rep(i,init,n) for(int i=init;i<n;i++)
#define rrep(i,init,n) for(int i=init;i>=n;i--)

using ll = long long;
using pi = pair<int, int>;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ld long double
const int M = 1e9+7;
const int N = 200000;
vector<pi> adj[1005];



void sol(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    map<int,int> mp;
    int j;
    rep(i,0,n){
        cin>>j;
        if(j==0) continue;
        mp[j]++;
    }
    cout<<sz(mp)<<"\n";
}

int main(){
    IOS;
    int t=1;
    cin>>t;  
    while(t--){
        sol();
    }
    return 0;
}
