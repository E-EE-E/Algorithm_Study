#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool check(string &str) {
    bool ret1 = false;
    bool ret2 = false;
    int cnt = 0;
    for(char c: str) {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            ret1 = true;
        else
            cnt += 1;
    }
    if(cnt >= 2) ret2 = true;
    return ret1 && ret2;
}
void go(int l, int index, string str, vector<char> &alpha) {
    if(str.length() == l) { //l개 선택하면
        if(check(str)) { //패스워드 조건에 부합하는지 확인 후
            cout<<str<<'\n'; //출력
        }
        return;
    }
    
    if(index >= alpha.size()) return; //c개보다 넘어가면 종료
    go(l, index + 1, str + alpha[index], alpha);//선택한다
    go(l, index + 1, str, alpha); //선택하지않는다.
    
    
}
int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int tc;
    cin>> tc;
    for(int t = 1; t <= tc; ++t) {
        int l, c;
        cin>>l>>c;
        vector<char> alpha(c);
        for(int i = 0; i < c; ++i) {
            cin>>alpha[i];
        }
        sort(alpha.begin(), alpha.end());
        //vector<bool> check(alpha.size(), false);
        string str = "";
        cout<<'#'<<t<<'\n';
        go(l, 0, str, alpha);
        
        
    }
    return 0;
}
