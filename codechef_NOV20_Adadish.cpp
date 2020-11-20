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
    rep(i,0,n) cin>>a[i];
    sort(a,a+n,greater<int>());
    int x=0,y=0;
    x=a[0];
    //cout<<x<<" ";
    rep(i,1,n){
        if(x>=y){
            y+=a[i];
        }else{
            x+=a[i];
        }
    }
    cout<<max(x,y);
}
/*3
3
2 2 2
3
1 2 3
4
2 3 4 5*/
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
