#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

vector<long int> v_primes;


void InitVector(long int s) {
	v_primes.reserve(s);
	v_primes.push_back(2);
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();

	auto max = 10000000;
	auto lprime = 2;
	auto b = static_cast<int>(sqrt(lprime));
	auto is_prime = true;

	InitVector(max);

	auto v_primes_s = v_primes.size();

	for (long int i = 3; i < max; i += 2) {
		is_prime = true;
		b = static_cast<int>(sqrt(i));
		for (auto j = 0; b >= v_primes[j]; ++j) {
			if (i % v_primes[j] == 0) {
				is_prime = false;
			}
		}
		if (is_prime) {
			v_primes.push_back(i);
		}
		lprime = i;
	}

	clock_t end = clock();
    double elapsed_secs = double(end - begin)/CLOCKS_PER_SEC;
    cout << "Seconds: " << elapsed_secs << endl;

	cout << "Latest prime: " << lprime << endl;
	cout << "Number of primes: " << v_primes.size() << endl;
	cout << "Primes pr. sec: " << v_primes.size() / elapsed_secs << endl;
	return 0;
}