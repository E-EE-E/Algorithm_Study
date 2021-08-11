#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int main() {
	int N, S;
	scanf("%d %d", &N, &S);

	int * arr = new int[N];

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	int start = 0, end=0;
	int sum = 0;
	int length = 0;
	int min_val = INT_MAX;
	for (start = 0; start < N; start++) {
		while (sum <= S && end < N) {
			sum += arr[end];
			end++;
		}
		if (sum >= S) {
			length = end - start;
			min_val = min(min_val, length);
		}

		sum -= arr[start];
	}
	if (min_val == INT_MAX) {
		cout << 0;
	}
	else {
		cout << min_val;
	}
	
	delete[] arr;
	return 0;
}