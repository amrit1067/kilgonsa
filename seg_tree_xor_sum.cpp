//Hackerearth
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
typedef vector<bool> vb;
typedef vector<vector<int> > graph;
typedef vector<vector<ll> > lgraph;
const ll INF = 1e9+7;
const int N=100005;
graph adj(500010);
ll a[N];
int n;
ll seg[N][42]={0};
void build(){
    rep(i,0,42){
        rep(j,1,n+1){
            seg[j][i]=seg[j-1][i];
            if(a[j]&(1LL<<i)) seg[j][i]++;
        }
    }
}


void sol(){
    cin>>n;
    rep(i,1,n+1) cin>>a[i];
    int q,x;
    cin>>q>>x;

    build();
    int l,r;
    while(q--){
        cin>>l>>r;
        ll ans=0,ans1=0,cnt1,cnt0;

        rep(i,0,42){
            cnt1=seg[r][i]-seg[l-1][i];
            cnt0=r-l+1-cnt1;

            ans1=(cnt1*(cnt1-1)*(cnt1-2))/6;
            ans1+=cnt1*(cnt0)*(cnt0-1)/2;

            ans1=((ans1%mod)*(1LL<<i)%mod)%mod;
            ans=((ans)%mod+(ans1%mod))%mod;
        }
        cout<<ans<<nl;
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
