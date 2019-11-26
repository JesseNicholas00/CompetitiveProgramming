#include<bits/stdc++.h>

using namespace std;

int segmentTree[(int)4e6 + 1];

void update(int u, int tl, int tr, int pos, int val) {
	
	if(tl > tr)return;

	if(tl == tr) {
		segmentTree[u] = val;
	}
	else {
		int tm = (tl+tr)/2;
		if(pos <= tm)
			update(2*u,tl,tm,pos,val);
		else
			update(2*u+1,tm+1,tr,pos,val);
	}
}

int query(int u, int tl, int tr, int l, int r) {
	
	if(l > r)return 0;

	if(tl == l && tr == r)return segmentTree[u];

	int tm = (tl+tr)/2;

	return
		query(2*u,tl,tm,l,min(tm,r)) +
		query(2*u+1,tm+1,tr,max(tm+1,l),r);
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	return 0;
}
