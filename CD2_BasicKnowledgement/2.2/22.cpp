#include <fstream>
#include <math.h>

using namespace std;

int main() {
	fstream inp("22.inp"), out("22.out");
	long long n; inp >> n;
	long long tn = n;

	long long A[n];
	for (long long i = 0; i <= n; i++) A[i] = 0;


	for (long long i = 2; i <= sqrt(n); i++) {
		while (n % i == 0) {
			A[i]++;
			A[n/i]++;
			n = n / i;
		}
	}
	
	long long count = 2;
	long long sum = 1+tn;
	for (long long i = 2; i <= tn/2; i++) if (A[i] > 0) {
		count++;
		sum += i;
	}

	string str = "";
	for (long long i = 2; i <= sqrt(tn); i++) {
		while (A[i] > 0) {
			out << i << endl;
			A[i]--;
		}
	}

	out << "count = " << count << endl;
	out << "sum_count = " << sum;

	return 0;
}