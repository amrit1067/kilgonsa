#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a[200001];//array for height
ll b[200001];//array for taste
ll lval[200001];//array for storing ans from 0 to i i.e going left to right
ll rval[200001];//array for storing ans from n-1 to i i.e going right to left
ll ltree[800001];//storing sum of lval
ll rtree[800001];//storing sum of rval
ll llazy[800001];
ll rlazy[800001];


void lvalue(int n){
    //storing value till next greater or equal element
    stack <int> s;
    s.push(0);
    lval[0]=b[0];
    for(int i=1;i<n;i++){
        while(s.empty()==false&&a[s.top()]<=a[i]){
            s.pop();
        }
        if(s.empty()==true){
            s.push(i);
            lval[i]=b[i];
        }else{
            int j=s.top();
            s.push(i);
            lval[i]=lval[j]+b[i];
        }
    }
}

void rvalue(int n){
    //storing value till prev greater or equal element
    stack <int> s;
    s.push(n-1);
    rval[n-1]=b[n-1];
    for(int i=n-2;i>=0;i--){
        while(s.empty()==false&&a[s.top()]<=a[i]){
            s.pop();
        }
        if(s.empty()==true){
            s.push(i);
            rval[i]=b[i];
        }else{
            int j=s.top();
            s.push(i);
            rval[i]=rval[j]+b[i];
        }
    }
}

void ne(int arr[],int n){
    //storing next greater or equal element
    stack <int> s;
    s.push(0);

    for(int i=1;i<n;i++){
        while(s.empty()==false&&a[s.top()]<=a[i]){
            arr[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }
}
void gr(int grr[],int n){
    //storing next (only) greater element
    stack <int> s;
    s.push(0);

    for(int i=1;i<n;i++){
        while(s.empty()==false&&a[s.top()]<a[i]){
            grr[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }
}
void pe(int brr[],int n){
    //storing previous greater or equal element
    stack <int> s;
    s.push(n-1);

    for(int i=n-2;i>=0;i--){
        while(s.empty()==false&&a[s.top()]<=a[i]){
            brr[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }
}
void le(int lee[],int n){
    //storing previous greater element
    stack <int> s;
    s.push(n-1);

    for(int i=n-2;i>=0;i--){
        while(s.empty()==false&&a[s.top()]<a[i]){
            lee[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }
}


ll lcst(int ss,int se,int si){
    //constructing segment tree storing sum of lval
    if(ss==se){
        ltree[si]=lval[ss];
        return lval[ss];
    }
    int mid=(ss+se)/2;
    ltree[si]=lcst(ss,mid,2*si+1)+lcst(mid+1,se,2*si+2);
    return ltree[si];
}

ll rcst(int ss,int se,int si){
    //constructing segment tree storing sum of rval
    if(ss==se){ 
        rtree[si]=rval[ss];
        return rval[ss];
    }
    int mid=(ss+se)/2;
    rtree[si]=rcst(ss,mid,2*si+1)+rcst(mid+1,se,2*si+2);
    return rtree[si];
} 

ll lget(int qs,int qe,int ss,int se,int si){
    //function to get value while going left to right
    if(llazy[si]!=0){
        ltree[si]+=(se-ss+1)*llazy[si];
        if(ss != se){ 
            llazy[si*2+1] += llazy[si]; 
            llazy[si*2+2] += llazy[si];
        }
        llazy[si]=0;
    }
    if(se<qs||ss>qe) return 0;
    if(qs<=ss&&qe>=se) return ltree[si];
    int mid=(ss+se)/2;

    return lget(qs,qe,ss,mid,2*si+1)+lget(qs,qe,mid+1,se,2*si+2);
}

ll rget(int qs,int qe,int ss,int se,int si){
    //function to get value while going right to left
    if(rlazy[si]!=0){
        rtree[si]+=(se-ss+1)*rlazy[si];
        if(ss != se){ 
            rlazy[si*2+1] += rlazy[si]; 
            rlazy[si*2+2] += rlazy[si]; 
        }
        rlazy[si]=0;
    }

    if(se<qs||ss>qe) return 0;
    if(qs<=ss&&qe>=se) return rtree[si];
    int mid=(ss+se)/2;

    return rget(qs,qe,ss,mid,2*si+1)+rget(qs,qe,mid+1,se,2*si+2);
}

void lupdate(int ss,int se,int si,int qs,int qe,ll diff){
    
    //updating query in ltree
    if(llazy[si]!=0){
        ltree[si]+=(se-ss+1)*llazy[si];
        if(ss!=se){
            llazy[2*si+1]+=llazy[si];
            llazy[2*si+2]+=llazy[si];
        }
        llazy[si]=0;
    }
    if(ss>se||ss>qe||se<qs) return ;

    if(ss>=qs && se<=qe){
        ltree[si] += (se-ss+1)*diff;
        if(ss != se){
            llazy[si*2 + 1]   += diff; 
            llazy[si*2 + 2]   += diff; 
        } 
        return; 
    } 
  
    int mid = (ss+se)/2;

    lupdate( ss, mid,2*si+1, qs, qe, diff); 
    lupdate( mid+1, se,si*2+2, qs, qe, diff); 

    ltree[si] = ltree[si*2+1] + ltree[si*2+2];

}
void rupdate(int ss,int se,int si,int qs,int qe,ll diff){

    //updating query in rtree
    if(rlazy[si]!=0){
        rtree[si]+=(se-ss+1)*rlazy[si];
        if(ss!=se){
            rlazy[2*si+1]+=rlazy[si];
            rlazy[2*si+2]+=rlazy[si];
        }
        rlazy[si]=0;
    }
    if(ss>se||ss>qe||se<qs) return ;

    if(ss>=qs && se<=qe){

        rtree[si] += (se-ss+1)*diff;
        if(ss != se){
            rlazy[si*2 + 1]   += diff; 
            rlazy[si*2 + 2]   += diff; 
        } 
        return; 
    } 
  
    int mid = (ss+se)/2; 
    rupdate( ss, mid,2*si+1, qs, qe, diff); 
    rupdate( mid+1, se,si*2+2, qs, qe, diff); 

    rtree[si] = rtree[si*2+1] + rtree[si*2+2];

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,q;
    cin>>n>>q;

    for(int i=0;i<n;i++){
        cin>>a[i];
        //taking height as input
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        //taking taste as input
    }
    int arr[n],brr[n],grr[n],lee[n];
    for(int i=0;i<n;i++){
        arr[i]=-1;//array to store next greater or equal element
        brr[i]=-1;//array to store prev greater or equal element
        grr[i]=-1;//array to store next greater element
        lee[i]=-1;//array to store prev greater element
        //initialising each to -1
    }

    ne(arr,n);
    pe(brr,n);
    lvalue(n);
    rvalue(n);
    gr(grr,n);
    le(lee,n);
    lcst(0,n-1,0);
    rcst(0,n-1,0);

    while(q--){
        ll x,y,z;
        cin>>x>>y>>z;
        if(x==1){
            y--;
            ll k=z-b[y];
            
            int fpos=arr[y];
            if(fpos==-1){
                fpos=n;
            }
            fpos--;
            int ipos=brr[y];
            ipos++;
            if(ipos<0) ipos=0;
            lupdate(0,n-1,0,y,fpos,k);
            rupdate(0,n-1,0,ipos,y,k);
            b[y]=z;
        }
        else{
            y--;
            z--;
            ll ans;
            if(y==z) ans=b[y];
            else if(y<z){
                if(arr[y]>y&&arr[y]<=z){
                    //if next greater or equal element lies between this range 
                   ans=-1;
                }else{
                    ans=lget(z,z,0,n-1,0);//getting value
                    if(lee[y]!=-1){
                        //if there exist an element greater than this element previously
                        ans-=lget(lee[y],lee[y],0,n-1,0);//subtract till that
                    }
                }
            }else{
                if(brr[y]<y&&brr[y]>=z){
                    //if prev greater or equal element lies between this range
                    ans=-1;
                }else{
                    ans=rget(z,z,0,n-1,0);//getting value
                    if(grr[y]!=-1){
                        //if there exist an element greater than this element after this
                        ans-=rget(grr[y],grr[y],0,n-1,0);//subtract till that
                    }
                }
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
