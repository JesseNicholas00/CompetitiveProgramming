#include<bits/stdc++.h>

using namespace std;

int segmentTree[(int)4e6 + 1];

bool lazy[(int)4e6+1];

void up(int node) {

	if(lazy[node]) {
		
		segmentTree[2*node] = segmentTree[node];
		segmentTree[2*node+1] = segmentTree[node];

		lazy[node*2] = true;
		lazy[node*2+1] = true;

		lazy[node] = false;
	}
}

void update(int node, int tl, int tr, int l, int r, int val) {

	if(l > r)return;

	if(tl == l && tr == r) {
		segmentTree[node] = val;
		lazy[node] = true;

		return;
	}
	
	up(node);

	int tm = (tl+tr)/2;
	
	update(node*2,tl,tm,l,min(tm,r),val);
	update(node*2+1,tm+1,tr,max(tm+1,l),r,val);
}

int query(int node, int tl, int tr, int l, int r) {

	if(l > r)return 0;

	if(tl == l && tr == r) return segmentTree[node];

	up(node);

	int tm = (tl+tr)/2;

	return
		query(node*2,tl,tm,l,min(tm,r)) +
		query(node*2+1,tm+1,tr,max(tm+1,l),r);
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	return 0;
}
