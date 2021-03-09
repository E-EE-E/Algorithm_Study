#include <iostream>
// 10, 100, 1000 단위로 끊어서 자릿수를 더해줌
// n <= 100,000,000 이므로 최대 9번만 돌면 됨 => 복잡도 O(logN)

using namespace std;
int main(int argc, const char * argv[]) {

    int n;
    cin>>n;
    
    int ans = 0;
    for(int len=1, start=1; start <=n; ++len, start*=10) {
        int end = start*10 -1;
        if(end > n) {
            end = n;
        }
        ans += (long long)(end - start +1)*len; // 최대 경우 21억 이상(9백경)이므로
    }
    
    cout<< ans <<'\n';
    
    return 0;
}
