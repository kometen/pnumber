// Many thanks to @ThAOSteen.

#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	clock_t begin = clock();

	const auto m = 1e7;
	auto l = 0;

	vector<uint> p(m/2, 1);
	vector<uint> primes;
	primes.reserve(m/15);

	for (uint i = 3; i * i < m; i += 2) {
		int n = (i - 3) / 2;
		if (p[n]) {
			for (uint j = i * i; j < m; j += (2 * i)) {
				int o = (j - 3) / 2;
				p[o] = 0;
			}
		}
	}

	primes.clear();
	primes.push_back(2);

	for (uint i = 3; i < m; i += 2) {
		uint n = (i - 3) / 2;
		if (p[n]) {
			primes.push_back(2 * n + 3);
		}
	}

	clock_t end = clock();

    double elapsed_secs = double(end - begin)/CLOCKS_PER_SEC;
    cout << "Seconds: " << elapsed_secs << endl;
    cout << "Latest prime: " << l << endl;
	cout << "Number of primes: " << primes.size() << endl;
	cout << "Primes pr. sec: " << primes.size() / elapsed_secs << endl;

/*   for (auto prime : primes) {
		cout << prime << endl;
    }*/

	return 0;
}