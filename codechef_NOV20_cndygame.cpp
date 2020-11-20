#include <bits/stdc++.h>
using namespace std;

//#define mod         1000000007
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
const ll mod = 1e9+7;

void sol(){
    ll n;
    cin>>n;
    ll a[n];
    int idx=-1;
    rep(i,0,n) {
        cin>>a[i];
        if(a[i]==1)idx=i;
    }
    int q;
    cin>>q;
    ll presum[n];
    set0(presum);

    if(a[0]==1){
        while(q--){
            ll x;
            cin>>x;
            if(n==1){
                cout<<x%mod<<nl;
            }else{
                if(x==1) cout<<x<<nl;
                else {
                    cout<<ceil(((double)(x-1))/(double)n)<<nl;
                }
            }
        }
        return;
    }


    if(n==1){
        while(q--){
            ll x;
            cin>>x;
            ll ans=0;
            if(a[0]%2==0)
            ans=(a[0]+(x-1)*(a[0]-1))%mod;
            else
            ans=((x%mod)*(a[0]%mod))%mod;
            
            cout<<ans<<nl;
        }
        return;
    }


    if(idx==-1||idx==n-1){
        rep(i,0,n-1){
            if(i>0)
            presum[i]=presum[i-1];
            if(a[i]%2==0) presum[i]+=a[i];
            else presum[i]+=a[i]-1;
        }
        presum[n-1]=presum[n-2];
        if(a[n-1]%2!=0) presum[n-1]+=a[n-1];
        else presum[n-1]+=a[n-1]-1;
    }else{
        rep(i,0,n){
            if(i>0)
            presum[i]=presum[i-1];
            if(i==idx) continue;
            if(i+1==idx||i==n-1){
                if(a[i]%2!=0) presum[i]+=a[i];
                else presum[i]+=a[i]-1;
            }else{
                if(a[i]%2==0) presum[i]+=a[i];
                else presum[i]+=a[i]-1;
            }
        }
    }

    
    while(q--){
        ll r;
        cin>>r;
        r--;
        ll ans=0;
        ll l=r%n;
        ll p=r/n;
        if(l>0) ans+=presum[l-1];
        ans+=a[l];
        if(a[l]==1&&l!=n-1&&l>0){
            if(a[l-1]%2==0) ans++;
            else ans--; 
        }
        if(p>0) ans+=((p%mod)*presum[n-1])%mod;
        cout<<ans%mod<<nl;
    }
}


int main(){
    fast;
    int t=1;
    cin>>t;
    while(t--){
        sol();
        //cout<<nl;
    }
    return 0;
}
