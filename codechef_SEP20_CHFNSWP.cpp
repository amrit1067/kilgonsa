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
    ll n;
    cin>>n;
    ll sum=((n)*(n+1))/2;
    if(sum%2!=0) {
        cout<<0<<"\n";
        return;
    }
    ll k=4*sum+1;
    ll p=sqrt(k);
    ll m=(p-1)/2;
    ll msum=m*(m+1)/2;
    ll d=sum/2-msum;
    ll ans=d;
    if(d+m>n){
        ans=n-m;
    }
    if(msum*2==sum){
        ll j=(m-n);
        ans=m*(m-1)/2+j*(j-1)/2;
        ans+=j;
    }
    d+=m;
    if(d<=n){
        ans+=(n-d);
    }
    cout<<ans<<"\n";
    /*if(d+m<=n){
        cout<<d<<"\n";
        return ;
    }else{
        cout<<n-m<<"\n";
    }*/
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
