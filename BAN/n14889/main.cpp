//풀이 2 - 재귀함수에서 최솟값 비교 후 리턴하는 코드
// 1. N 명 중 N/2(m) 명을 선택
//   선택한 N/2 명의 check[p] = 1 = 스타트팀
//   선택하지 않은 나머지 check[p] = -1 = 링크팀
//   L 2. 각 팀별 능력치 구한 뒤 차이구함
//   3.능력치 차이를 비교하여 최소값 구하는 문제
//
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
//int ans;
int a[20][20];
int check[20];

int simulation(int n, int m) {
    int answer = 0;
    int sum1 = 0;
    int sum2 = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i == j) continue;
            if(check[i] == 1 && check[j] == 1) {
                sum1 += a[i][j];
            }
            else if(check[i] == -1 && check[j] == -1) {
                sum2 += a[i][j];
            }
        }
    }
    answer = abs(sum1 - sum2);
    return answer; //두 팀의 능력치 차이
}
int go(int index, int p, int n, int m) {
    if(index == m) {
        int ret = simulation(n, m);
        //if(ret < ans) ans = ret;
        return ret;
    }
    if(check[p] != -1) return -1;
    int ans = -1;
    check[p] = 1;
    int temp = go(index + 1, p+1, n, m);
    if(ans == -1 || (temp != -1 && ans > temp)) {
        ans = temp;
    }
    check[p] = -1;
    int temp2 = go(index, p+1, n, m);
    if(ans == -1 || (temp2 != -1 && ans > temp2)) {
        ans = temp2;
    }
    
    return ans;
}
int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int tc;
    cin>> tc;
    for(int t = 1; t <= tc; ++t) {
        int n;
        cin>> n;
        memset(a, 0, sizeof(a));
        
        for(int i = 0; i < n; ++i) {
            check[i] = -1; //초기화
            for(int j = 0; j < n; ++j) {
                cin>> a[i][j];
            }
        }
        int m = n/2;
        cout<<'#'<<t<<' ';
        cout<<go(0, 0, n, m);
        //cout<< ans;
        cout<<'\n';
    }
    return 0;
}
