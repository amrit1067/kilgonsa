#include <bits/stdc++.h>
using namespace std;

#define mod         1000000007
#define sz(v) ((int)(v).size())
#define fast       ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define fs          first
#define sc          second
#define pb         push_back
#define nl          '\n'
#define all(a) a.begin(),a.end()
#define unique(c) (c).resize(unique(all(c)) - (c).begin())

#define set0(a)     memset(a,0,sizeof(a))
#define setneg(a)   memset(a,-1,sizeof(a))
#define setinf(a)   memset(a,126,sizeof(a))

#define rep(i,start,end) for (int i = start; i <end; i++)
#define rrep(i,end,start) for (int i=end; i>=start ;i--)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > graph;
typedef vector<vector<ll> > lgraph;
const ll INF = 1e9+7;

void sol(){
    int n;
    cin>>n;
    int a[n];
    unordered_map<int,int> mp;
    vector<int> b;
    rep(i,0,n){
        cin>>a[i];
        if(!mp.count(a[i])){
            mp[a[i]]=0;
            b.push_back(a[i]);
        }
    }
    sort(b.begin(),b.end());
    int k=1;
    rrep(i,sz(b)-1,0){
        mp[b[i]]=k++;
    }
    rep(i,0,n){
        cout<<mp[a[i]]<<" ";
    }
}

int main(){
    fast;
    int t=1;
    cin>>t;
    while(t--){
        sol();
        cout<<nl;
    }
    return 0;
}
