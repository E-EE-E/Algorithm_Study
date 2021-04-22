#include <iostream>
// 풀이 2 - 선택
// 비내림차순(중복+오름차순)

using namespace std;
bool c[10]; int a[10];
int cnt[10];
void go(int index, int num, int n, int m) {
    if(index == m) {
        //출력 주의
        for(int i = 1; i <=n; ++i) { //1~N의 수를
            for(int j = 1; j <= cnt[i] ; ++j) //반복되는 개수만큼 출력
                cout<<i<<' ';
        }
        cout<<'\n';
        return ;
    }
    if(num > n) return;
    for(int i = m-index; i>= 1; --i) {
        cnt[num] = i; //반복되는 횟수 저장
        go(index+i, num+1, n, m);
    }
    cnt[num] = 0;
    go(index, num+1, n, m);
}
int main(int argc, const char * argv[]) {
    
    int n, m;
    cin>>n>>m;
    
    go(0, 1, n, m);
    
    return 0;
}
