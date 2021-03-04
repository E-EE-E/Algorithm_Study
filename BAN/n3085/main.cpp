#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
// 모든 swap 경우의 수만큼 시행
// swap한 부분에 해당하는 행, 열에서 max있나 구함

using namespace std;

int check(vector<string> &a, int n, size_t start_col, size_t end_col, size_t start_low, size_t end_low) {
    int cnt = 1;
    int max = 0;
    for(size_t i = start_col; i <= end_col; ++i) {
        for(size_t j = 0; j < n; ++j) {
            if(j+1 < n){
                if(a[i][j] == a[i][j+1]) {
                    ++cnt;
                } else {
                    max = (cnt > max) ? cnt : max;
                    cnt = 1;
                }
            }
        }
        max = (cnt > max) ? cnt : max;
        cnt = 1;
    }
    for(size_t i = start_low; i <= end_low; ++i) {
        for(size_t j = 0; j < n; ++j) {
            if(j+1 < n){
                if(a[j][i] == a[j+1][i]) {
                    ++cnt;
                } else {
                    max = (cnt > max) ? cnt : max;
                    cnt = 1;
                }
            }
        }
        max = (cnt > max) ? cnt : max;
        cnt = 1;
    }
    return max;
}

int main(int argc, const char * argv[]) {
    int N;
    cin>>N;
    
    vector<string> arr(N);
    for(size_t i = 0; i < N; ++i) {
        cin>>arr[i];
    }
    
    int ans = 0;
    int max = 1;
    for(size_t i = 0; i < N; ++i) {
        for(size_t j = 0; j < N; ++j) {
            if(j+1 < N) {
                //if(arr[i][j] != arr[i][j+1]) { //모든 경우의 수를 고려하기 위해 조건필요없음
                swap(arr[i][j], arr[i][j+1]);
                //check
                ans = check(arr, N, i, i, j, j+1);
                max = max < ans ? ans : max;
                swap(arr[i][j], arr[i][j+1]);
            //}
            }
            if(i+1 < N) {
                //if(arr[i][j] != arr[i+1][j]) {
                swap(arr[i][j], arr[i+1][j]);
                //check
                ans = check(arr, N, i, i+1, j, j);
                max = max < ans ? ans : max;
                swap(arr[i][j], arr[i+1][j]);
            //}
            }
        }
    }
    
    cout<< max << '\n';

    return 0;
}
