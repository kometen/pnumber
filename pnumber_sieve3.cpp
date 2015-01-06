// Many thanks to @ThAOSteen.

#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	clock_t begin = clock();

	unsigned short reverse = 1;
	unsigned short one = 1;
	uint less = 0;

	const uint m = 1e2;

	vector<uint> p(m/2, 1);
	vector<uint> primes;
	primes.reserve(m/16);

	for (uint i = 5; i * i < m; i += 2) {
		less += reverse ^= one;
		int n = ((i - 5) / 2) - less;
		if (p[n]) {
			for (uint j = i * i; j < m; j += (2 * i)) {
				uint o = (j - 3) / 2;
				cout << "j: " << j << ", n: " << n << ", o: " << o << endl;
				p[o] = 0;
			}
		}
	}

	primes.clear();
	primes.push_back(2);
	primes.push_back(3);

	less = 0;
	for (uint i = 5; i < m; i += 2) {
		uint n = ((i - 5) / 2) + less;
		less += reverse ^= one;
		cout << less << endl;
		if (p[n]) {
			primes.push_back(2 * less + 3);
		}
	}

	clock_t end = clock();

	double elapsed_secs = double(end - begin)/CLOCKS_PER_SEC;
	cout << "Seconds: " << elapsed_secs << endl;
	cout << "Number of primes: " << primes.size() << endl;
	cout << "Primes pr. sec: " << primes.size() / elapsed_secs << endl;

   for (auto prime : primes) {
		cout << prime << endl;
    }

	return 0;
}