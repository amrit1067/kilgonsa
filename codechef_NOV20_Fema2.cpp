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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vi il,m;
    int c[n],x[n];
    set0(c);
    set0(x);
    rep(i,0,n){
        if(s[i]=='I'){
            il.pb(i);
        }else if(s[i]=='M'){
            m.pb(i);
        }
        if(i>0)
        c[i]=c[i-1]+(s[i]==':'),x[i]=x[i-1]+(s[i]=='X');
        else c[i]=(s[i]==':'),x[i]=(s[i]=='X');
    }
    int i=0,j=0;
    int cnt=0;
    while(i<sz(il)&&j<sz(m)){
        int x1=x[il[i]];
        int x2=x[m[j]];
        int c1=c[il[i]];
        int c2=c[m[j]];
        if(abs(x1-x2)==0){
            if(k+1-abs(il[i]-m[j])-abs(c1-c2)>0){
                //cout<<k+1-abs(il[i]-m[j])-abs(c1-c2)<<nl;
                cnt++;
                j++;
                i++;
            }else{
                if(m[j]>il[i]) i++;
                else j++;
            }
        }else{
            if(m[j]>il[i]) i++;
            else j++;
        }
    }
    cout<<cnt;
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
