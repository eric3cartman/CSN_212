#include <bits/stdc++.h>
using namespace std;

int a[100];

int longest(int n){
	int s[n];
	int l[n];
	int ans;
	for(int i=0;i<n;i++) {
		s[i]=l[i]=-1;
	}
	s[0]=1,l[0]=1;
	for(int i=1;i<n;i++){
		for(int j=i-1;j>=0;j--){
			if(a[j]<a[i]) s[i]=max(l[j]+1 ,s[i]);
			if(a[j]>a[i]) l[i]=max(s[j]+1 ,l[i]);
		}
		ans=max(s[i],l[i]);
	}
	return ans;
}

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<longest(n)<<endl;
	return 0;
}