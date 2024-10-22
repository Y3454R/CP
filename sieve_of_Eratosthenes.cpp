#include <bits/stdc++.h>

typedef long long ll;

#define endl '\n'

using namespace std;

vector <ll> sieve_of_Eratosthenes(ll n) {
	vector <bool> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (ll i = 2; i <= n; i++) {
		if (is_prime[i] && i*i <= n) {
			for (ll j = i * i ; j <= n; j += i) {
				is_prime[j] = false;
			}
		}
	}
	vector <ll> primeNumbers;
	for (ll i = 2; i <= n; i++) {
		if (is_prime[i]) {
			primeNumbers.push_back(i);
		}
	}
	return primeNumbers;
}

int main() {
	vector <ll> primes = sieve_of_Eratosthenes(1000);
	for (auto itr: primes) {
		cout << itr << " ";
	}
}
