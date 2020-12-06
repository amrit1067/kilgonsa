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
const int N=1000005;
int tree[4*N]={0};
int a[N];
void build(int ss,int se,int si){
    if(ss==se){
        tree[si]=a[ss];
        return;
    }
    int mid=(ss+se)/2;
    build(ss,mid,2*si);
    build(mid+1,se,2*si+1);
    tree[si]=tree[2*si]+tree[2*si+1];
}

void update(int ss,int se,int i,int si,int diff){
    if(i<ss||i>se||ss>se) return;
    tree[si]=tree[si]+diff;
    if(se>ss){
        int mid=(ss+se)/2;
        update(ss,mid,i,2*si,diff);
        update(mid+1,se,i,2*si+1,diff);
    }
}
int get(int k,int ss,int se,int si){
    if(tree[si]<k) return -1;
    if(ss==se) return ss;
    int mid=(ss+se)/2;
    int left=tree[2*si];
    if(k>left){
        return get(k-left,mid+1,se,2*si+1);
    }else{
        return get(k,ss,mid,2*si);
    }
}
void sol(){
    int n,q;
    cin>>n>>q;
    rep(i,0,n+1) a[i]=1;
    int i,k;
    build(1,n,1);
    while(q--){
        cin>>i>>k;
        if(i==0){
            if(a[k]==1){
                a[k]=0;
                update(1,n,k,1,-1);
            }
        }else{
            cout<<get(k,1,n,1)<<nl;
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
