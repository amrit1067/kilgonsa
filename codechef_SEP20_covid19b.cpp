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
    int v[n];
    rep(i,0,n) cin>>v[i];
    int max_ans=1,min_ans=INT_MAX;
    rep(i,0,n){
        int k=1;
        bool flag=0;
        int mn=INT_MAX;
        int mx=0;
        rep(j,i+1,n){
            if(v[j]<v[i]) {
                k++;
                flag=1;
                mn=min(mn,v[j]);
            }
        }
        if(flag){
            rep(j,0,i){
                if(v[j]<=v[i]&&v[j]>mn) k++;
            }
        }
        flag=0;
        rep(j,0,i){
            if(v[j]>v[i]){
                k++;
                flag=1;
                mx=max(mx,v[j]);
            }
        }
        if(flag){
            rep(j,i+1,n){
                if(v[j]<mx&&v[j]>=v[i]) k++;
            }
        }
        //cout<<k<<" ";
        min_ans=min(min_ans,k);
        max_ans=max(max_ans,k);
    }
    cout<<min_ans<<" "<<max_ans<<"\n";
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
