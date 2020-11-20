#include <bits/stdc++.h>
using namespace std;

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
const int MxN = 1e5+1;
int tre[MxN];
int a[MxN];
int p[MxN];
int n;
int ind=0;
struct ltreee{
  int val;
  int lazy;
  int rightside;
  int leftside;
}uns[5550000];

bool isPerfectSquare(ll x) 
{ 
    ll s = sqrt(x); 
    return (s*s == x); 
}

ll countdivisors(ll n){
  ll count =0;
  for(ll i=1;i<=sqrt(n);i++){
    if(n%i==0){
      if(n/i==i){
        count++;
      }else{
        count=count+2;
      }
    }
  }
 return count;
}

int ceilIdx(int tail[],int l,int r,int x){
    while(r>l){
        int m=l+(r-l)/2;
        if(tail[m]==x){
            return m;
        }
        if(tail[m]<=x){
            r=m;
        }else l=m+1;
    }
    return r;
}

void s(int v,int p,int x){
 
  if(x==1){ 
    uns[++ind]=uns[uns[p].rightside];
    uns[p].rightside=ind; 
  }else{ 
    uns[++ind]=uns[uns[p].leftside];
    uns[p].leftside=ind; 
  }
}

int lis(int arr[],int l,int r){
    int n=r-l+1;
    int tail[n];
    //int par[n];
    tail[0]=arr[r];
    int mx=1;
    int len=1;
    rrep(i,r-1,l){
        if(arr[i]<tail[len-1]){
            tail[len]=arr[i];
            len++;
            mx=max(mx,len);
        }else if(arr[i]==tail[len-1]){
            mx=max(mx,len);
        }else{
            int c=ceilIdx(tail,0,len-1,arr[i]);
            tail[c]=arr[i];
            len=c+1;
            mx=max(mx,len);
        }
    }
    return mx;
}

void func(int l,int r){
    while(a[l]<a[r]){
        l=p[l];
    }
    p[r]=l;
}

void update(int v,int L,int R,int l,int r,int x){
  if(l==L&&r==R){
       uns[v].lazy+=x;
       return;
   }

    else{  
       int mid=(L+R)/2;
     if(l>mid){
       s(uns[v].rightside,v,1);
       update(uns[v].rightside,mid+1,R,l,r,x);
     }
        else if(r<=mid){
       s(uns[v].leftside,v,0);
       update(uns[v].leftside,L,mid,l,r,x);
     }
     else{
       s(uns[v].rightside,v,1);
       s(uns[v].leftside,v,0);
       update(uns[v].rightside,mid+1,R,mid+1,r,x);
       update(uns[v].leftside,L,mid,l,mid,x);
     }
     uns[v].val=max(uns[uns[v].rightside].val+uns[uns[v].rightside].lazy,uns[uns[v].leftside].val+uns[uns[v].leftside].lazy);

     }
}
int digSum(int x) 
{ 
    
   int sum=0;
   while(x>0)
   {
         sum+=x%10;
         x=x/10;
   }
       
 
    return sum; 
} 
ll exponentMod(ll A, ll B, ll C)  
{  
    if (A == 0)  
        return 0;  
    if (B == 0)  
        return 1;  
    ll y;  
    if (B % 2 == 0) {  
        y = exponentMod(A, B / 2, C);  
        y = (y * y) % C;  
    }  
    else {  
        y = A % C;  
        y = (y * exponentMod(A, B - 1, C) % C) % C;  
    } 
    return (ll)((y + C) % C);  
} 
int call(int par[],int arr[],int l,int r){
    int mx=1;
    if(par[r]==1){
        //cout<<"hello";
        return *max_element(par+l,par+r+1);
    }
    int ind=l-1;
    rrep(i,r-1,l){
        if(par[i]<par[i+1]){
            ind=i;
            break;
        }
    }
    //cout<<ind;
    int k=par[r]-1;
    rep(i,l,r+1){
        if(i>ind){
            mx=max(mx,par[i]-k);
        }else{
            mx=max(mx,par[i]);
        }
    }
    return mx;
}

int query(int v,int L,int R,int l,int r){   
  if(v==0)
        return 0;
  if(L==l&&R==r)
    return uns[v].val+uns[v].lazy;
    
  else{  
    int mid=(L+R)/2;
    if(l>mid)
      return query(uns[v].rightside,mid+1,R,l,r)+uns[v].lazy;
    else if(r<=mid)
      return query(uns[v].leftside,L,mid,l,r)+uns[v].lazy;
    else{
      return max(query(uns[v].rightside,mid+1,R,mid+1,r)+uns[v].lazy,query(uns[v].leftside,L,mid,l,mid)+uns[v].lazy);
     }
  }
}

ll factor(int x){
  if(x<=0) return 1;
  return 1*factor(x-1);
}

ll summationof(int x){
  if(x==0) return x;
  return x+summationof(x-1);
}


void sol1(){
    int q,s;
    cin>>q>>s;
    rep(i,0,n) cin>>a[i];
    int last=0;
    while(q--){
        int x,y;
        cin>>x>>y;
        int l=(x+s*last-1)%n+1;
        int r=(y+s*last-1)%n+1;
        if(l>r) swap(l,r);
        last=lis(a,l-1,r-1);
        cout<<last<<nl;
    }
}
void sol(){   
  int q,si;
    tre[0]=0;
    p[0]=0;
    cin>>q>>si;
    for(int i=1;i<=n;i++) cin>>a[i];
    a[0]=999999;
    summationof(10);
    //cout<<summationof(10)<<endl;
    for(int i=1;i<=n;i++){  
      func(i-1,i);  
    }
    factor(20);
    //cout<<factor(20)<<endl;
  for(int i=1;i<=n;i++){
    uns[tre[i]=++ind]=uns[tre[i-1]];
    update(tre[i],1,n,p[i]+1,i,1);
 }
  digSum(198);
  int l,r;
  int last=0;
       if(si==0){
     for(int i=1;i<=q;i++){ 
       cin>>l>>r;
        if(r<l)
           swap(l,r);
       cout<<query(tre[r],1,n,l,r)<<endl;
     }
       }
       else{  
         int last=0;

    for(int i=1;i<=q;i++){
      cin>>l>>r;
         l=(l+last-1)%n+1;
         r=(r+last-1)%n+1;
         if(r<l)
           swap(l,r);
       last=query(tre[r],1,n,l,r);
       cout<<last<<endl;
     }
       }
}
int main(){
    fast;
    int t=1;
    //cin>>t;
    while(t--){
      cin>>n;
      if(n<=1000) sol1();
      else
      sol();
        //cout<<nl;
    }
    return 0;
}
