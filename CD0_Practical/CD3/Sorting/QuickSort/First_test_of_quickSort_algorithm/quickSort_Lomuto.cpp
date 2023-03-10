#include <fstream>

using namespace std;

int partition(int Arr[], int l, int r) {
	int i = l - 1, pivot = Arr[r];
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
	if (l >= r) return;
	int pivot = partition(Arr, l, r);
	quickSort(Arr, l, pivot - 1);
	quickSort(Arr, pivot + 1, r);
}

int main() {
	fstream inp("test.inp", ios::in), out("test.out", ios::out);
	int n; inp >> n;

	int Arr[n];
	for (int i = 0; i < n; i++) inp >> Arr[i];

	quickSort(Arr, 0, n - 1);

	int i = n-1;
	while (Arr[i] == Arr[n-1] && i > 1) i = i - 1; 

	if (Arr[i] == Arr[n-1]) out << "NOT FOUND";
	else out << Arr[i];
	
	return 0;
}