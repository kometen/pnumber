#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

vector<long int> primes;


void InitVector() {
	primes.push_back(2);
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();

	auto max = 10000000;
	auto lprime = 2;
	auto b = static_cast<int>(sqrt(lprime));
	auto is_prime = true;

	InitVector();

	auto primes_s = primes.size();

	for (long int i = 3; i < max; i += 2) {
		is_prime = true;
		b = static_cast<int>(sqrt(i));
		for (auto j = 0; b >= primes[j] && is_prime; ++j) {
			if (i % primes[j] == 0) {
				is_prime = false;
			}
		}
		if (is_prime) {
			primes.push_back(i);
			lprime = i;
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