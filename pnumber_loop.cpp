#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

vector<long int> primes;


void InitVector(long int s) {
	primes.reserve(s/10);
	primes.emplace_back(2);
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();

	auto max = 10000000;
	auto lprime = 2;
	auto b = 1;
	auto c = 0;
	auto square = 1;
	auto is_prime = true;

	InitVector(max);

	auto primes_s = primes.size();

	for (long int i = 3; i < max; i += 2) {
		is_prime = true;
		for (auto j = 0; b >= primes[j] && is_prime; ++j) {
			if (i % primes[j] == 0) {
				is_prime = false;
			}
		}
		if (is_prime) {
			primes.emplace_back(i);
			lprime = i;
		}
		if (i > square) {
			b++;
			c++;
			square = square + 1 + 2 * c;
		}
	}

	clock_t end = clock();
	double elapsed_secs = double(end - begin)/CLOCKS_PER_SEC;
	cout << "Seconds: " << elapsed_secs << endl;

	cout << "Latest prime: " << lprime << endl;
	cout << "Number of primes: " << primes.size() << endl;
	cout << "Primes pr. sec: " << primes.size() / elapsed_secs << endl;
	return 0;
}