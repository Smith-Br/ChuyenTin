#include <fstream>
#include <math.h>

using namespace std;

int main() {
	fstream inp("22.inp"), out("22.out");
	int n; inp >> n;

	int A[n];
	for (int i = 0; i <= n; i++) A[i] = 0;

	for (int i = 2; i <= sqrt(n); i++) {
		while (n % i == 0) {
			A[i]++;
			A[n/i]++;
			n = n / i;
		}
	}

	for (int i = 2; i <= n/2; i++) {
		while (A[i] > 0) {
			out << A[i] << '.';
			A[i]--;
		}
	}

	return 0;
}