#include <bits/stdc++.h>
#include <boost/functional/hash.hpp>
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
const ll po = pow(2,32);
vector<bool> vis(300010,false);
vi adj[300010];
vll w(300010);
vll pre(300010);
vll ht(300010);
ll height;
/*struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};*/ 
unordered_map<pair<int,int>,ll,boost::hash<pair<int, int>>> mp;

void add(int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfspar(int u,int par[]){
    vis[u]=1;
    for(int x:adj[u]){
        if(!vis[x]){
            par[x]=u;
            ht[x]=ht[u]+1;
            pre[x]=(pre[u]%po+w[x-1]*w[x-1]%po)%po;
            //cout<<par[x]<<" ";
            dfspar(x,par);
        }
    }
    height=max(height,ht[u]);
}


ll func(int fu, int fv,int par[]){
    if(fu==1){
        mp[{fu,fv}]=(w[0]*w[0])%po;
        return mp[{fu,fv}];
    }
    ll ans=0;
    int x=par[fu];
    int y=par[fv];
    if(x>y) swap(x,y);
    if(x==y){
        //cout<<x<<" "<<y<<" "<<pre[x]<<" ";
        ans=(pre[x]%po+(w[fu-1]*w[fv-1])%po)%po;
        mp[{fu,fv}]=ans%po;
    }else
    if(!mp.count({x,y})){
        ans=(func(x,y,par)%po+(w[fu-1]*w[fv-1])%po)%po; 
        mp[{fu,fv}]=ans%po;
    }else{
        ans=((w[fu-1]*w[fv-1])%po+mp[{x,y}]%po)%po;
        mp[{fu,fv}]=ans%po;
    }
    return ans%po;
}
ll res(int fu, int fv,int par[]){
    if(fu==fv) return pre[fu]%po;
    ll ans=0;
    int a=fu,b=fv;
    int i=ht[fu];
    while(i--){
        if(a==b){
            ans=ans%po+pre[a]%po;
            return ans%po;
        }
        ans=(ans%po+(w[a-1]*w[b-1])%po)%po;
        a=par[a];
        b=par[b];
    }
    return ans;
}
void sol(){
    ll n,q;
    cin>>n>>q;
    rep(i,0,n) cin>>w[i];
    rep(i,0,n-1){
        int u,v;
        cin>>u>>v;
        add(u,v);
    }
    
    //cout<<po<<nl;
    
    int par[n+1];

    ht[0]=0;
    ht[1]=1;
    height=0;
    pre[0]=1;
    pre[1]=(w[0]*w[0])%po;
    dfspar(1,par);
    par[0]=-1;
    par[1]=1;
    ll ans=0;
    height--;
    if(q*height<=3e8){
        rep (i,0,q){
            ans=0;
            int a,b;
            cin>>a>>b;
            ans=res(a,b,par)%po;
            cout<<ans<<nl;
        }
    }
    else{
        rep (i,0,q){
            ans=0;
            int a,b;
            cin>>a>>b;
            if(a>b) swap(a,b);
            if(a==b){
                mp[{a,b}]=pre[a]%po;
                ans=pre[a]%po;
            }else
            if(!mp.count({a,b})){
                ans=func(a,b,par);
                //mp[{a,b}]=ans;
            }else{
                ans=mp[{a,b}];
            }
            cout<<ans<<nl;
        }
    }
}

int main(){
    fast;
    int t=1;
    //cin>>t;
    while(t--){
        sol();
        //cout<<nl;
    }
    return 0;
}
