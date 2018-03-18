#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define tez std::ios::sync_with_stdio(false)
struct seg{
    ll val;int index;
};
void modify(int p, ll value, seg t[], int n) {  // set value at position p
  for (t[p += n].val = value; p > 1; p >>= 1){
    t[p>>1].val = max(t[p].val,t[p^1].val);
    if(t[p>>1].val==t[p].val)t[p>>1].index=t[p].index;
    else t[p>>1].index=t[p^1].index;
  }
}
seg query(int l, int r,seg t[],int n) {  // sum on interval [l, r)
  seg res ;
  res.index=-1;
  res.val=-1;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if(l&1){
        if(res.val<=t[l].val){res.val=t[l].val;res.index=t[l].index;}
        l++;
    }
    if(r&1){
        --r;
        if(res.val<=t[r].val){res.val=t[r].val;res.index=t[r].index;}
    }
  }
  return res;
}
int main(){
    tez;
    int n,q;
    cin>>n>>q;
    seg t[2*n];
    for(int i=0;i<n;i++){
        cin>>t[i+n].val;
        t[i+n].index=i;
    }
    for (int i = n - 1; i > 0; --i){
        if(t[i<<1].val >= t[i<<1|1].val){
            t[i].val=t[i<<1].val;
            t[i].index=t[i<<1].index;
        }
        else{
            t[i].val=t[i<<1|1].val;
            t[i].index=t[i<<1|1].index;
        }
    }
    while(q--){
        int che;
        cin>>che;
        if(che==1){
            int pos;ll val1;
            cin>>pos;cin>>val1;
            modify(pos-1,val1,t,n);
        }
        else{
            int l,r;
            cin>>l>>r;
            if(r-l+1>2){
                ll m1=0,m2=0,m3=0,ans=0;
                seg update[54];
                int loop=min(r-l+1,53),in=0;
                update[1]=query(l-1,r,t,n);
                m1=update[1].val;
                modify(update[1].index,0,t,n);
                update[2]=query(l-1,r,t,n);
                m2=update[2].val;
                modify(update[2].index,0,t,n);
                for(int i=3;i<loop+1;i++){
                    in=i;
                    update[i]=query(l-1,r,t,n);
                    m3=update[i].val;
                    modify(update[i].index,0,t,n);
                    if(m1<(m2+m3)){ans=m1+m2+m3;break;}
                    m1=m2;m2=m3;
                }
                for(int i=in;i>0;i--){
                    modify(update[i].index,update[i].val,t,n);
                }
                cout<<ans<<endl;
            }
            else cout<<0<<endl;
        }
    }
    return 0;
}
