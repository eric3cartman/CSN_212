#include <bits/stdc++.h>
using namespace std;
 
int a[10100],b[20100],dp[10100];

int greater_than_or_equal(int s[],int r,int key)
{
	int l=0;
	while(r-l>1)
	{
		int mid=(l+r)/2;
		if(s[mid]>key) r=mid;
		else l=mid;
	}
	return r;
}
 
int LIS(int i,int n)
{
	for(int j=0;j<n;j++) dp[j]=0;
	dp[0]=b[i];
	int len=1;
	for(int j=i+1;j<n+i;j++)
	{
		if(b[j] < dp[0])  dp[0] = b[j];
		else if (b[j] > dp[len-1])  dp[len++]=b[j];
		else dp[greater_than_or_equal(dp,len-1,b[j])]=b[j];
	}
	return len;
}
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			b[i]=a[i]; b[n+i]=a[i];
    	}
	    int ans=0,res;
		for(int i=0;i<n;i++)
		{	
	    	res = LIS (i,n);     //start from here
		    ans = max(ans,res);
	   	}
		cout<<ans<<endl;
	}
	return 0;
} 