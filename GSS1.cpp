#include <bits/stdc++.h>
#define ll long long int
using namespace std;
struct node{
	ll sum;
	ll pre;
	ll suff;
	ll best;
};
ll A[1000000];
node S[1000000];
void build(ll A[],ll start,ll end,ll pos)
{
	if(start==end)
	{S[pos].best=S[pos].pre=S[pos].suff=S[pos].sum=A[start];
	return;
	}
	
	ll mid=(end-start)/2+start;
	build(A,start,mid,pos*2+1);
	build(A,mid+1,end,pos*2+2);
	S[pos].sum=S[pos*2+1].sum+S[pos*2+2].sum;
	
	
		S[pos].pre=max(S[pos*2+1].sum+S[pos*2+2].pre,S[pos*2+1].pre);
		
			S[pos].suff=max(S[pos*2+2].sum+S[pos*2+1].suff,S[pos*2+2].suff);
				S[pos].best=max(max(S[2*pos+1].best,S[pos*2+2].best),S[pos*2+1].suff+S[pos*2+2].pre);
			
	
	return;
	
}
void bld(ll A[],ll n)
{
	build(A,0,n-1,0);
}
node querry(ll qs,ll qe,ll start,ll end,ll pos)
{
	node res; res.best=res.sum=res.pre=res.suff=-99999999;
node left,right;
	left=right=res;
	if(qs>end||qe<start)
	return res;
	if(qs<=start&&qe>=end)
	return S[pos];
	ll mid=(end-start)/2+start;
 
	if(qs<=mid)
	 left=querry(qs,qe,start,mid,pos*2+1);
	if(qe>mid)
 right=querry(qs,qe,mid+1,end,pos*2+2);	
res.sum=left.sum+right.sum;
res.pre=max(left.sum+right.pre,left.pre);
res.suff=max(right.suff,right.sum+left.suff);
res.best=max(max(left.best,right.best),left.suff+right.pre);
return res;
	
}
ll querrytill(ll qs,ll qe,ll n)
{node R=querry(qs,qe,0,n-1,0);
return R.best;
}
int main()
{std::ios::sync_with_stdio(false);
	ll n;cin>>n;
	for(ll i=0;i<n;i++)
	cin>>A[i];
	bld(A,n);
	ll m;cin>>m;
	while(m--)
	{ll xi,yi;cin>>xi>>yi;
	cout<<querrytill(xi-1,yi-1,n)<<endl;
	}
} 
