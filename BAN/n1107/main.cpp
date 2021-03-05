#include <iostream>
// 타겟n의 범위가 50만이라고 누를 수 있는 숫자가 50만까지 제한되는게 아님!
// +/-버튼을 눌러 이동할 수 있는 것을 고려했을 때 max 100만까지 고려해야함!
// 100 -> c -> n(타겟)
//     ||   ||
//    len + press => 정답
// (숫자버튼) (+/-버튼)

using namespace std;

bool broken[10] = {false,};
int possible(int c) {
    if(c == 0) {
        if(broken[0]) {
            return 0;
        }
        else {
            return 1;
        }
    }
    int len = 0;
    while(c>0) {
        if(broken[c%10]) {
            return 0;
        }
        else {
            ++len;
        }
        c/= 10;
    }
    
    return len;
}

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    int m;
    cin>>m;
    for(int i = 0; i < m; ++i) {
        int x;
        cin>>x;
        broken[x] = true;
    }
    int ans = n-100;         // 숫자안누르고 +/-이동횟수
    ans = ans < 0? -ans:ans;
    
    for(int i = 0; i <= 1000000; ++i) {
        int c = i;
        int len = possible(c); //숫자버튼 누른 갯수
        if(len > 0) {   //숫자버튼을 눌렀으면
            //+/- 누른 갯수
            int press = n - c;
            press = press > 0? press : -press;
            //숫자버튼 누른 갯수 + (+/-)버튼 누른개수 최솟값 비교유지
            ans = (ans > len + press)? len+press : ans;
        }
    }
    
    cout << ans <<'\n';
    
    return 0;
}
