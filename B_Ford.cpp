#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define X first
#define Y second

int main() {
	int n,m,s,a,b,w;
	
	vector<pair< pair<int, int>, int> > edge;
	
	int d[n+1];
	
	cin>>n; //number of vertices
	cin>>m; //number of edges
	
	for(int i=0;i<m;i++){
		cin>>a>>b; //input edge from a to b
		cin>>w;    //input weight
		edge.pb(mp(mp(a,b),w));
	}
	
	cin>>s; //input source
	
	for(int i=1;i<=n;i++){
		d[i]=10000;
	}
	d[s]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<edge.size();j++){
			a=(edge[j].X).X;
			b=(edge[j].X).Y;
			w=(edge[j].Y);
			//cout<<a<<b<<w;
			if(d[b] > d[a] + w){
				if(i==n){
					cout<<"negative Cycle"<<endl;
					break;
				}
				d[b]=d[a]+w;
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		cout<<d[i]<<" "<<endl;
	}
	return 0;
}