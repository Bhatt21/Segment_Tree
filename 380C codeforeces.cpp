#include <bits/stdc++.h>
#define ll  int
using namespace std;

struct node{
	
	ll len;
	ll open;
	ll close;
};

node S[1000007*4];
void segutill(char A[],ll start,ll end,ll pos)
{
	
	ll mid=(start+end)/2;
	if(start==end)
{
if(A[start]=='(')
{
S[pos].open=1;
S[pos].len=1;
S[pos].close=0;}
else if(A[start]==')')
{
	S[pos].open=0;
S[pos].len=1;
S[pos].close=1;
	
}

//cout<<S[pos]<<" "<<pos<<" ";
return;}


ll left=2*pos+1;
ll right=left+1;

	segutill(A,start,mid,left);
	segutill(A,mid+1,end,right);

	
		ll t=min(S[left].open,S[right].close);
		S[pos].len=S[left].len+S[right].len-2*t;
		S[pos].open=S[left].open+S[right].open-t;
		S[pos].close=S[left].close+S[right].close-t;
	
	
	return;
}
node sumutill(char A[],ll start,ll end,ll xi,ll yi,ll pos)
{node res; 
res.open=res.close=res.len=0;

if(start>end)
return res;
if(xi>end||yi<start)
return res;
	if(xi<=start&&yi>=end)
	return S[pos];
	
	ll left=2*pos+1;
	ll right=left+1;
	
		ll mid=(start+end)/2;
	if(xi>mid)
	return sumutill(A,mid+1,end,xi,yi,right);
	
	if(yi<=mid)
	return sumutill(A,start,mid,xi,yi,left);
	

	
node a=	sumutill(A,start,mid,xi,yi,left);
node b=	sumutill(A,mid+1,end,xi,yi,right);
	
	
	ll t;
	t=min(a.open,b.close);

res.len=a.len+b.len-t*2;
res.open=a.open+b.open-t;
res.close=a.close+b.close-t;


return res;
	
	
	

	
	
	
	
	
	
	
	
	
	
}

void maxsumq(char A[],ll n,ll xi,ll yi)
{

ll ans=	(yi-xi+1)-sumutill(A,0,n-1,xi,yi,0).len;
printf("%d\n", ans);
	return;
}
void seg(char A[],ll n)
{ll pos=0;
	segutill(A,0,n-1,pos);


	
	return;

}
int main()
{
	char A[1000007];
scanf("%s",A);
//	ll A[n];
	//for(ll i=0;i<n;i++)
	//cin>>A[i];
	ll n=strlen(A);
  seg(A,n);
  ll m;
  scanf("%d", &m);
  for(ll i=0;i<m;i++)
  {
  	ll xi,yi;
  	scanf("%d%d", &xi, &yi); 
  	xi--;yi--;
  	maxsumq(A,n,xi,yi);
  }
}
