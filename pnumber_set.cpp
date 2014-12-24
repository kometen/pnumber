#include <cmath>
#include <ctime>
#include <iostream>
#include <set>

using namespace std;

set<long int> primes;

void InitPrimes() {
	primes.insert(2);
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();

	auto max = 10000000;
	auto lprime = 2;
	auto b = static_cast<int>(sqrt(lprime));
	auto is_prime = true;

	InitPrimes();

	auto primes_s = primes.size();

	for (long int i = 3; i < max; i += 2) {
		is_prime = true;
		b = static_cast<int>(sqrt(i));
		for (auto it = primes.begin();it != primes.end() && is_prime; ++it) {
			if (i % *it == 0) {
				is_prime = false;
			}
		}
		if (is_prime) {
			primes.insert(i);
			lprime = i;
		}
	}

	clock_t end = clock();
    double elapsed_secs = double(end - begin)/CLOCKS_PER_SEC;
    cout << "Seconds: " << elapsed_secs << endl;

	cout << "Latest prime: " << lprime << endl;
	cout << "Number of primes: " << primes.size() << endl;
	cout << "Primes pr. sec: " << primes.size() / elapsed_secs << endl;

/*	for (auto it = primes.begin(); it != primes.end(); ++it) {
		cout << *it << endl;
	}*/
	return 0;
}