// Many thanks to @ThAOSteen.

#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	clock_t begin = clock();

	auto m = 1000000000;
//	auto m = 10000000;
	auto s = 0;
	auto a = 0;
	auto l = 0;

	vector<long int> p(m, 1);
	p[0] = 0;
	p[1] = 0;

	for (long int i = 2; i * i < m; i++) {
		if (p[i]) {
			for (long int j = i * i; j < m; j += i) {
				p[j] = 0;
			}
		}
	}
	clock_t end = clock();
    double elapsed_secs = double(end - begin)/CLOCKS_PER_SEC;
    cout << "Seconds: " << elapsed_secs << endl;

    for (auto prime : p) {
    	if (prime) {
	    	l = a + s;
    		s++;
    	} else {
	    	a++;
    	}
    }

    cout << "Latest prime: " << l << endl;
	cout << "Number of primes: " << s << endl;
	cout << "Primes pr. sec: " << s / elapsed_secs << endl;
	return 0;
}