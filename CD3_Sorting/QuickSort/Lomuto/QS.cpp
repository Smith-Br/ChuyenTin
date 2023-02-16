#include <fstream>

using namespace std;

void swap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

int partition(int Arr[], int l, int r) {
	int pivot = Arr[r];
	int i = l - 1;
	for (int j = l; j < r; j++) {
		if (Arr[j] <= pivot) {
			i++;
			swap(Arr[i], Arr[j]);
		}
	}
}

int main() {
	

	return 0;
}