#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define X first
#define Y second

bool next(pair<int, int> p, pair<int, int> q, pair<int, int> r){
	int a=(q.Y - p.Y) * (r.X - q.X) - (q.X - p.X) * (r.Y - q.Y); 
	if(a>=0) return false;
	else return true;
}

void gift_wrap(vector<pair<int, int> > &P){
	int n=P.size();
	if(n<3) return ;
	vector<pair<int, int> > hull;
	int left=0;
	for(int i=1;i<n;i++){
		if(P[i].X < P[left].X) left=i;
	}
	
	int p=left,q=0;
	
	do{
		hull.pb(P[p]);
		q=(p+1)%n;
		//----Find next point of hull
		for(int i=0;i<n;i++){
			if(next(P[p], P[i], P[q])) q=i;
		}
		p=q;
	} while(p!=left);
	
	for(int i=0;i<hull.size();i++){
		cout<<hull[i].X<<" "<<hull[i].Y<<endl;
	}
	
}



int main() {
	
	vector<pair<int, int> > Points;
	Points.pb(mp(3,3));
	Points.pb(mp(3,-3));
	Points.pb(mp(-3,3));
	Points.pb(mp(-3,-3));
	Points.pb(mp(0,0));
	Points.pb(mp(-2,-2));
	Points.pb(mp(-1,-1));
	
	gift_wrap(Points);
	return 0;
}