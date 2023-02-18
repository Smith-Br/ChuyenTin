#include <iostream>

using namespace std;

int count = 0;
bool diagleft[16], diagright[16], col[8], row[8];

void Backtracking(int i) {
    for (int j = 1; j <= 8; j++) {
        if (col[j] == 1 && diagleft[i + j] == 1 && diagright[i - j + 8] == 1) {
            col[j] = diagleft[i + j] = diagright[i - j + 8] = 0;
            if (i == 8) count++;
            else Backtracking(i+1);
            col[j] = diagleft[i + j] = diagright[i - j + 8] = 1;
        }
    }
}

int main() {
	for (int i = 0; i < 9; i++) {
		col[i] = true;
		row[i] = true;
	} for (int i = 0; i < 16; i++) {
		diagleft[i] = true;
		diagright[i] = true;
	}

	Backtracking(1);
	cout << count;

	return 0;
}