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
bool flag;

void sol(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    cin>>n;
    ll k=1<<20;
    // k = 2 pow 20
    cout<<1<<" "<<k<<endl;
    ll j;
    cin>>j;
    ll t=n*k;
    ll sum=j-t;
    // sum of sequence
    int a[20]={0};
    // array to store no. of bit
    ll res=0;
    rep(i,0,19){
        k=1<<i;
        // output 2 pow i for each bit from 0 to 18
        cout<<1<<" "<<k<<endl;
        cin>>j;
        ll l=abs(j-sum)/k;
        // diff of input sum and actual sum and l = no. of element greater or less than prev element having with 2 pow k bit
        if(j>sum){
            ll x=(n-l)/2;
            // if new sum is greater than actual sum then no. of element will be x + x+l=n
            if(x%2!=0) a[i]=1;
            // x is odd then that bit will be count in xor 
            res+=(x<<i);
            // sum till ith bit of all no. having ith bit in it
        }else{
            ll x=(n+l)/2;
            //// if new sum is lesser than actual sum then no. of element  x+x-l=n
            if(x%2!=0) a[i]=1;
            // x is odd then that bit will be count in xor 
            res+=(x<<i);
            // sum till ith bit of all no. having ith bit in it
        }
    }
    int ans=0;
    ll des=(sum-res)/(1<<19);
    if(des%2!=0) a[19]=1;
    rep(i,0,20){
        ans+=(a[i]<<i);
    }
    cout<<2<<" "<<ans<<endl;
    int s;
    cin>>s;
    if(s==-1) flag=0;
}

int main(){
    IOS;
    int t=1;
    cin>>t;  
    while(t--){
        flag=1;
        sol();
        if(!flag)exit;
    }
    return 0;
}
