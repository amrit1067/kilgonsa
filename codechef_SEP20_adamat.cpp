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
    bool vec[n];
    memset(vec,0,n);
    int a[n][n];
    bool flag=true;
    rep(i,0,n)
        rep(j,0,n) cin>>a[i][j];
    rrep(i,n-1,0){
        rep(j,0,i+1){
            if(a[i][j]<a[j][i]&&flag){
                vec[i]=1;
                flag=!flag;
                break;
            }else if(a[i][j]>a[j][i]&&!flag){
                vec[i]=1;
                flag=!flag;
                break;
            }
        }
    }
    int ans=0;
    rep(i,0,n) ans+=vec[i];
    cout<<ans<<"\n";
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
