#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	
	int N;
	cin >> N;

	int max_arr[3], min_arr[3];
	int before_max[3], before_min[3];



	for (int j = 0; j < 3; j++) {
		cin >> before_min[j];
		before_max[j] = before_min[j];
	}

	int input;
	int temp_min = INT_MAX, temp_max=INT_MIN;
	int n = 1, i=0;
	for (n = 1; n < N; n++) {
		for (i = 0; i < 3; i++) {
			cin >> input;
	
			if (i == 0) {
				min_arr[0] = min(before_min[0], before_min[1])+input;
				max_arr[0] = max(before_max[0], before_max[1]) + input;
			}
			else if (i == 1) {
				temp_min = min(before_min[0], before_min[1]);
				min_arr[1] = min(temp_min, before_min[2]) + input;

				temp_max = max(before_max[0], before_max[1]);
				max_arr[1] = max(temp_max, before_max[2]) + input;
			}
			else {
				min_arr[2] = min(before_min[1], before_min[2]) + input;
				max_arr[2] = max(before_max[1], before_max[2]) + input;
			}
		}

		//이전 값으로 업데이트
		for (int i = 0; i < 3; i++) {
			before_min[i] = min_arr[i];
			before_max[i] = max_arr[i];
		}


	}

	int result_min = INT_MAX, result_max=INT_MIN;
	for (int i = 0; i < 3; i++) {
		result_min = min(result_min, before_min[i]);
		result_max = max(result_max, before_max[i]);
	}
	
	cout << result_max << " " << result_min;
}