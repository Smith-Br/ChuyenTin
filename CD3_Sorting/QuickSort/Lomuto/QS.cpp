#include <fstream>

using namespace std;

int partition(int Arr[], int l, int r) {
	int pivot = Arr[r];
	int i = l - 1;
	for (int j = l; j < r; j++) {
		if (Arr[j] <= pivot) {
			i++;
			swap(Arr[i], Arr[j]);
		}
	}
	i++;
	swap(Arr[i], Arr[r]);
	return i;
}

void quickSort(int Arr[], int l, int r) {
	if ( l >= r) return;
	int pivot = partition(Arr, l, r);
	quickSort(Arr, l, pivot - 1);
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