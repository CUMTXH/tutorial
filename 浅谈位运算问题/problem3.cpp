#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i = a ; i <= b ; i++)
#define per(i,a,b) for(ll i = a ; i >= b ; i--)
#define x first
#define y second

const int N = 4e5+7;

ll a[N*2],cnt[N*2];
ll n;
ll mp[N*2];
vector<ll>x;
void solve() {
	cin >> n;
	rep(i,1,n) {
		cin >> a[i];
	}
	ll sum = 0;
	ll ans = 0;
	rep(i,1,n) {
		ans += n-i+1;
	}
	rep(i,1,n) {
		sum ^= a[i];
		if(mp[sum])
			ans--;
		for(auto &j:x) {
			ans -= cnt[j^sum];
		}
		cnt[sum]++;
	}
	cout << ans << endl;
	sum = 0;
	rep(i,1,n) {
		sum ^= a[i];
		cnt[sum] = 0;
	}
}
int main() {
	rep(i,0,N) {
		if(i*i>=N)
			break;
		mp[i*i] = 1;
		x.push_back(i*i);
	}
	int tc;
	cin >> tc;
	while(tc--)
		solve();
}
