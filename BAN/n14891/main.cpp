#include <iostream>
#include <vector>
// 1. 조사 - 어떤톱니 어떤방향으로 회전
// 2. 회전
// 3. 최종 점수합산
using namespace std;

int main(int argc, const char * argv[]) {
    int n = 4;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int k;
    cin>> k;
    while(k--) {
        int no, dir;
        cin>>no>>dir;
        no -= 1;
        //1. 조사 - 어떤 톱니가 어떤 방향으로 회전해야하는지
        vector<int> d(n);
        d[no] = dir;
        //왼쪽
        for(int i = no-1; i >= 0; --i) {
            if (a[i][2] != a[i+1][6]) {//왼쪽 인접
                d[i] = -d[i+1];
            } else {
                break;
            }
        }
        //오른쪽
        for(int i = no+1; i <n; ++i) {
            if (a[i][6] != a[i-1][2]) {//오른쪽 인접
                d[i] = -d[i-1];
            } else {
                break;
            }
        }
        //2. 회전
        for(int i = 0; i < n; ++i) {
            if (d[i] == 0) continue;
            if (d[i] == 1) {    // 시계방향 회전
                char temp = a[i][7];
                for(int j = 7; j >= 1; j--) {
                    a[i][j] = a[i][j-1];
                }
                a[i][0] = temp;
            } else if (d[i] == -1) {    //반시계방향 회전
                char temp = a[i][0];
                for(int j = 0; j < 7; ++j) {
                    a[i][j] = a[i][j+1];
                }
                a[i][7] = temp;
            }
        }
    }
    //3. 점수합산
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i][0] == '1') {
            ans |= (1<<i);
        }
    }
    cout<< ans << '\n';
    return 0;
}
