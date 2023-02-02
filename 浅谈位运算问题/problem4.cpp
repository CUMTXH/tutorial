#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(ll i = a ; i <= b ; i++)
#define per(i,a,b) for(ll i = a ; i >= b ; i--)
#define x first
#define y second
typedef long long ll;
const int N = 2e5+7;

void solve() {
	ll x;
	cin >> x ;
	ll y = x*2;
	if(x%2) y+=1;
	ll a = 0, b = 0;
	ll t = 1;
	rep(i,1,31) t*=2ll;
	bool flag = 0;
	per(i,32,1) {
		if(flag) {
			if((x&t)==0) {
				flag = 0;
				a+=t,b+=t;
			} else if(y&t) {
				puts("-1");
				return ;
			}
		}
		if(x&t) {
			a+=t;
		}
		if((x&t)==0 && (y&t)) {
			flag = 1;
		}
		t/=2;
	}
	cout << a << " " << b << endl;
}


int main() {
	int tc;
	cin >> tc;
	while(tc--)
		solve();
}
