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
const ll MAX = 1e9+7, MIN = -(1e9+7);
int Parents[200001];
int RANK[200001];
int V;
struct edges{
    int src;
    int dest;
    ll weight;
    edges(int x,int y,ll z){
        src=x;
        dest=y;
        weight=z;
    }
};
bool mycomp(edges e1,edges e2){
    return e1.weight<e2.weight;
}
void init(){
    rep(i,0,V){
        Parents[i]=i;
        RANK[i]=0;
    }
}
int find(int x){
    if(Parents[x]==x) return x;
    Parents[x]=find(Parents[x]);
    return Parents[x];
}
void Union( int x,int y){
    int x_rep=find(x);
    int y_rep=find(y);
    if(x_rep==y_rep) return;
    if (RANK[x_rep]<RANK[y_rep])
        Parents[x_rep]=y_rep;
    else if (RANK[x_rep]>RANK[y_rep])
        Parents[y_rep]=x_rep;
    else {
        Parents[y_rep]=x_rep;
        RANK[x_rep]++;
    }
}
ll diff(vi x,vi y){
    ll diff=0;
    rep(i,0,x.size()){
        diff+=abs(x[i]-y[i]);
    }
    return diff;
}

ll kruskal(vector<edges> arr){
    sort(arr.begin(),arr.end(),mycomp);
    ll res=0;
    for(ll i=0;i<arr.size();i++){
        edges e=arr[i];
        int x=find(e.src);
        int y=find(e.dest);
        if(x!=y){
            res+=e.weight;
            Union(x,y);
            //s++;
        }
    }
    return res;
}


vector<edges> call(graph vec){
    int n=vec.size();
    int d=vec[0].size();
    vector<edges> ed;
    ll x = 1 << (d-1);

    vector<vector<ll> >prob(n , vector<ll> (x));
    for(ll i = 0;i<n;i++)
    {
       for(ll j =0;j<x;j++)
       {
           ll res = 0;
           for(ll k = 0;k<d;k++)
           {
               if(j & (1 << k))
               res = res - vec[i][k]; 
               else 
               res = res + vec[i][k];
           }
           prob[i][j] = res;                            
       }
    }
    for(ll j = 0 ;j<x;j++)
    {
        ll mini = INT64_MAX , maxi = INT64_MIN;
        ll min_idx = -1 , max_idx = -1;

        for(ll i = 0; i<n;i++)
        {
            if(mini > prob[i][j])
                mini = prob[i][j] , min_idx = i;
            else if(maxi < prob[i][j])
                maxi = prob[i][j] , max_idx = i;
        }

        for(ll i = 0;i<n;i++)
        {
            ll low = abs(mini - prob[i][j]);
            ll high = abs(maxi - prob[i][j]);

            if(low > high)
            {
                edges curr(i,min_idx,-low);
                ed.pb(curr);
            }
            else if(high >= low )
            {
                edges curr(i,max_idx,-high);
                ed.pb(curr);
               
            }           
        }
    }
    return ed;
}
void sol(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,d;
    cin>>n>>d;
    V=n;
    graph v;
    init();
    rep(i,0,n){
        vi vc;
        rep(j,0,d ){
            int k;
            cin>>k;
            vc.pb(k);
        }
        v.pb(vc);
    }
    vector<edges> ed=call(v);
    
    ll ans=kruskal(ed);
    cout<<abs(ans);
}

int main(){
    fast;
    int t=1;
    //cin>>t;  
    while(t--){
        sol();
    }
    return 0;
}