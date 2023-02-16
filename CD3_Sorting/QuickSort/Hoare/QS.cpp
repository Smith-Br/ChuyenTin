#include <fstream>

using namespace std;

int partition(int Arr[], int l, int r) {
	int pivot = Arr[(l + r) / 2];
	int i = l - 1, j = r + 1;
	while (true) {
		do {
			i++;
		} while (Arr[i] < pivot);
		do {
			j--;
		} while (Arr[j] > pivot);
		if (i < j) {
			swap(Arr[i], Arr[j]);
		} else return j;
	}
}

void quickSort(int Arr[], int l, int r) {
	if (l >= r) return;
	int pivot = partition(Arr, l, r);
	quickSort(Arr, l, pivot);
	quickSort(Arr, pivot + 1, r);
}

int main() {
	fstream inp("QS.inp"), out("QS.out");
	int n; inp >> n;
	int Arr[100];
	for (int i = 0; i < n; i++) {
		inp >> Arr[i];
	}
	quickSort(Arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		out << Arr[i] << " ";
	}
	return 0;
}