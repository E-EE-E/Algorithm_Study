#include <iostream>
// 모든 경우 다해서 퇴사일될때까지 얻은 수익 중 최대값 출력
// O(2^n)

using namespace std;

int n;
int t[15];
int p[15];
int ans = 0;
void go(int day, int sum) {
    if(day==n) {    //정답 퇴사일
        if(ans < sum) ans = sum;
        return;
    }
    if(day > n) {   //불가능
        return;
    }
    //수행
    //1.선택함
    go(day+t[day], sum + p[day]);
    //2.선택안함
    go(day+1, sum);
}

int main(int argc, const char * argv[]) {
    cin>>n;
    for(int i = 0; i < n; ++i) {
        cin>>t[i]>>p[i];
    }
    
    go(0, 0);
    cout<<ans<<'\n';
    return 0;
}
