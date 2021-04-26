//피보나치 풀이 1
//정수 범위 주의
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector<long long> a;
long long ans = 0;
void go(int index, long long sum, int n) {
    if(index == n) {
        ans = sum;
        return;
    }
    if(index < 2) {
        a.push_back(index);
        go(index +1, 1, n);
    } else {
        a.push_back(sum);
        go(index + 1, a[index] + a[index-1], n);
    }
}

int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);

    int n;
    cin>>n;
    go(0, 0, n);
    cout<< ans <<'\n';
    return 0;
}
