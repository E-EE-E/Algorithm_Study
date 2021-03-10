#include <iostream>
#include <algorithm>
#include <vector>
// 사전순이므로 먼저 입력 알파벳을 오름차순으로 정렬
// 각 자리마다 알파벳을 사용할지 안할지를 선택하는 것이 기준
// 함수 호출마다 선택할경우, 선택하지 않을 경우로 함수 2번 호출 => O(2^C)

using namespace std;
bool check(string &password) {
    int ja = 0;
    int mo = 0;
    for(char x:password) {
        if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u') {
            mo+=1;
        } else {
            ja +=1;
        }
    }
    return ja >=2 && mo >= 1;
}
void go(int l, vector<char> &alpha, string password, int index) {
    if(password.length() == l) {
        if(check(password)) {
            cout<<password<<'\n';
        }
        return;
    }
    if(index >= alpha.size())  return;
    
    go(l, alpha, password+alpha[index], index+1);
    go(l, alpha, password, index+1);
}

int main(int argc, const char * argv[]) {
    
    int L, C;
    cin >> L >> C;
    
    vector<char> a(C);
    for(int i=0; i < C; ++i) {
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    
    go(L, a, "", 0);
    
    return 0;
}
