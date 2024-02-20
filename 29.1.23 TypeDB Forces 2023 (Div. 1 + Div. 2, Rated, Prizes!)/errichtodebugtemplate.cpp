
// 12:00

#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }


void test_case() {
	int n;
	cin >> n;
	vector<pair<int,int>> all;
	for (int p = 2; p * p <= n; p++) {
		if (n % p == 0) {
			int count = 0;
			while (n % p == 0) {
				count++;
				n /= p;
			}
			all.emplace_back(p, count);
		}
	}
	if (n > 1) {
		all.emplace_back(n, 1);
	}
	debug() << imie(all);
	int sum = 0;
	while (true) {
		int product = 1;
		for (pair<int,int>& p : all) {
			if (p.second > 0) {
				product *= p.first;
				p.second--;
			}
		}
		if (product == 1) {
			break;
		}
		sum += product;
	}
	cout << sum << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		test_case();
	}
}
