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
struct cell{
    int x,y,dist;
    cell(){}
    cell(int xd,int yd,int d){
        x=xd;
        y=yd;
        dist=d;
    }
};
int dx[]={1,1,-1,-1,2,2,-2,-2};
int dy[]={2,-2,2,-2,1,-1,1,-1};

bool issafe(int x,int y,int n){
    if(x>=1&&x<=n&&y>=1&&y<=n)
        return true;
    return false;
}

void sol(){
    int n,xi,yi,xf,yf;
    cin>>n>>xi>>yi>>xf>>yf;
    bool vis[n+1][n+1];
    set0(vis);
    
    vis[xi][yi]=1;
    queue<cell> q;
    q.push(cell(xi,yi,0));
    cell t;
    int x,y;
    while(!q.empty()){
        t=q.front();
        q.pop();
        if(t.x==xf&&t.y==yf){
            cout<<t.dist;
            return;
        }
        for(int i=0;i<8;i++){
            x = t.x + dx[i]; 
            y = t.y + dy[i];
            if(issafe(x,y,n)&&!vis[x][y]){
                vis[x][y]=1;
                q.push(cell(x,y,t.dist+1));
            }
        }
    }
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
