#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(ll i = a ; i <= b ; i++)
#define per(i,a,b) for(ll i = a ; i >= b ; i--)
#define x first
#define y second
typedef long long ll;
const int N = 2e5+7;
int a[N]
void solve() {
	int n;
	cin >> n;
	queue<pair<int,int> >b; //The first indicates the remaining value, the second indicates the subscript of the number
	int maxn = -1,maxi;
	rep(i,1,n) {
		scanf("%d",&a[i]);
		b.push({a[i],i});
		maxn = max(a[i],maxn);
		if(maxn==a[i]) maxi = i;
	}
	rep(i,1,n) { //Output the maximum value in b, and find the maximum value on the way to update array b
		printf("%d ",a[maxi]);
		queue<pair<int,int> > t;
		int maxt = -1,maxti = -1;
		while(b.size()) {
			auto x = b.front();
			b.pop();
			if(x.y==maxi)
				continue;
			x.x -= x.x&maxn;
			t.push(x);
			maxt = max(maxt,x.x);
			if(maxt==x.x) maxti = x.y;
		}
		maxn = maxt;
		maxi = maxti;
		b = t;

		if(maxn==0) {
			while(b.size()) {
				auto x = b.front();
				b.pop();
				printf("%d ",a[x.y]);
			}
			return;
		}
	}
}


int main() {
	int tc;
	cin >> tc;
	while(tc--)
		solve(),cout << endl;
}
