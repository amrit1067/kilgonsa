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

unsigned long long power(ll x, unsigned int y,int p) {  
    ll res = 1;     // Initialize result  
  
    x = x % p; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % p;  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (x*x) % p;  
    }  
    return res;  
}
unsigned long long modInverse(unsigned long long n, int p) 
{ 
    return power(n, p - 2,p); 
} 
  
// Returns nCr % p using Fermat's little 
// theorem. 
unsigned long long nCrModPFermat(unsigned long long n, 
                                 int r, int p) 
{ 
    // Base case 
    if (r == 0) 
        return 1; 
  
    // Fill factorial array so that we 
    // can find all factorial of r, n 
    // and n-r 
    unsigned long long fac[n + 1]; 
    fac[0] = 1; 
    for (int i = 1; i <= n; i++) 
        fac[i] = (fac[i - 1] * i) % p; 
  
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p; 
}

void sol(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,0,n) cin>>a[i];
    sort(all(a));
    ll k=a[n-1];
    int cnt=0;
    rrep(i,n-1,0){
        if(a[i]==k) cnt++;
        else break;
    }
    ll ans=power(2,n,M);
    if(cnt%2!=0) {
        cout<<ans;
        return;
    }
    int s=n-cnt;
    ll l=power(2,s,M);
    ll nc=nCrModPFermat(cnt,cnt/2,M);
    l=((nc)%M*l%M)%M;
    if(l<ans){
        ans=(ans-l)%M;
        cout<<ans;
        return;
    }else{
        ans=(ans+M-l)%M;
        cout<<ans;
        return;
    }
}

int main(){
    IOS;
    int t=1;
    cin>>t;  
    while(t--){
        sol();
        cout<<"\n";
    }
    return 0;
}
