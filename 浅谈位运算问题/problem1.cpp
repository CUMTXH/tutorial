#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i = a ; i <= b ; i++)
#define per(i,a,b) for(ll i = a ; i >= b ; i--)

const int N = 2e5+7;
int cnt[N];
vector<int>a[N];
void solve() {
	int n;
	cin >> n;
	rep(i,1,n) {
		int k,t;
		scanf("%d",&k);
		rep(j,1,k) {
			scanf("%d",&t);
			a[i].push_back(t);
			cnt[t]++;
		}
	}
	rep(i,1,n) {
		int flag = 1;
		for(auto &j:a[i])
			if(cnt[j]==1) {
				flag = 0;
				break;
			}
		if(flag) {
			puts("YES");
			rep(i,1,n) {
				for(auto &j:a[i]) {
					cnt[j] = 0;
				}
				a[i].clear();
			}
			return ;
		}
	}
	puts("NO");
	rep(i,1,n) {
		for(auto &j:a[i]) {
			cnt[j] = 0;
		}
		a[i].clear();
	}
	return ;
}
int main() {
	int tc;
	cin >> tc;
	while(tc--)
		solve();
}
