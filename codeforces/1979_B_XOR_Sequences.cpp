/*
	Problem Link: https://codeforces.com/problemset/problem/1979/B
*/

#include <bits/stdc++.h>

typedef long long ll;

#define endl '\n'

using namespace std;

ll myCeil(ll x, ll y) {
	return (x + y - 1) / y;
}

bool pairVectorSortParameterFunction(const pair <int,int> &a, const pair <int,int> &b) {
    // return a.second < b.second;
    return a.first < b.first;
}



int main() {
	ll testCasesNumber;
	cin >> testCasesNumber;
	while (testCasesNumber--) {
		ll x, y;
		cin >> x >> y;
		// std::string s = std::bitset< 64 >( 12345 ).to_string();
		string xx = bitset< 64 >(x).to_string();
		string yy = bitset< 64 >(y).to_string();
		// cout << xx << "\n" << yy << " \n\n";
		ll length = min(xx.size(), yy.size());
		ll cnt = 0;
		for (ll i = length - 1; i >= 0; i--) {
			if (xx[i] == yy[i]) {
				cnt++;
			}
			else {
				break;
			}
		}
		ll res = pow(2, cnt);
		cout << res << endl;
	} 
}
