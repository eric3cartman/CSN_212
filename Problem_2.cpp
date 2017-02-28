#include <bits/stdc++.h>
using namespace std;

bool A[60][60][2];
long long dp[60][60];

int main() {
	int w,l,a,b,c,d;
	cin>>w>>l;
	w++,l++;
	for(int i=0;i<w;i++){
		for(int j=0;j<l;j++){
			A[i][j][0]=1; //connected to point just below
			A[i][j][1]=1; //connected to point just left
			dp[i][j]=0;
		}
	}
	
	string s;
	getline(cin,s); //go to next line
	getline(cin,s);
	int n=s.length();
	//cout<<s<<endl;
	if(n>2){
		for(int i=2;i<n;i=i+11){
			a=s[i]-48;
			b=s[i+2]-48;
			c=s[i+4]-48;
			d=s[i+6]-48;
			//cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
			if(a==c) A[c][d][0]=0;
			else A[c][d][1]=0;
		}
	}
	//initialize dp
	dp[0][0]=1;
	for(int i=1;i<w;i++){
		if(A[i][0][1]==1) dp[i][0]+=dp[i-1][0];
	}
	for(int i=1;i<l;i++){
		if(A[0][i][0]==1) dp[0][i]+=dp[0][i-1];
	}
	//form table
	for(int i=1;i<w;i++){
		for(int j=1;j<l;j++){
			if(A[i][j][0]==1) dp[i][j]+=dp[i][j-1];
			if(A[i][j][1]==1) dp[i][j]+=dp[i-1][j];
		}
	}
	/*for(int i=0;i<l;i++){
		for(int j=0;j<w;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	cout<<dp[w-1][l-1];
	return 0;
}