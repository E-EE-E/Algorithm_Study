#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;
struct term {
    int num;
    int op;
};
string str;
vector<term> equation;
int n;
int calc(deque<char> str) {
    int ans = str.front() - '0'; str.pop_front();
    while(!str.empty()) {
        char x = str.front(); str.pop_front();
        if(x == '+') {
            int y = str.front() - '0'; str.pop_front();
            ans += y;
        } else if(x == '-') {
            int y = str.front() - '0'; str.pop_front();
            ans -= y;
        } else if(x == '*') {
            int y = str.front() - '0'; str.pop_front();
            ans *= y;
        } else if(x == '/') {
            int y = str.front() - '0'; str.pop_front();
            ans /= y;
        }
    }
    
    return ans;
}
int solution() {
    vector<term> a(n);
    for(int i = 0; i < str.length(); ++i) {
        if(i % 2 == 0) {
            a[i] = {str[i] - '0', 0};
        } else {
            char c = str[i];
            int op = 0;
            if(c == '*') {
                op = 1;
            } else if(c == '+') {
                op = 2;
            } else if(c == '-') {
                op = 3;
            }
            a[i] = {0, op};
        }
    }
    //int ans = 0; //failed의 원인 - 주의하자
    int ans = -2147483648; //정수의 연산에서 음수도 나온다!!!주의하자
    vector<term> b(n);
    int m = (n-1)/2;
    for(int i = 0; i < (1<<m); ++i) {
        b = a; // 수식 리셋
        bool ok = true;
        for(int j = 0; j < m-1; ++j) {
            if((i&(1<<j))>0 && (i&(1<<(j+1)))>0) {
                ok = false;
            }
        }
        
        if(!ok) continue;
        //괄호 (먼저연산) 먼저 연산하기
        for(int j = 0; j < m; ++j) { //m개 연산 중
            if((i & (1<<j)) > 0) { // 먼저연산 O 이면
                int k = 2*j+1;   //해당 연산의 수식 중 인덱스
                if(b[k].op == 1) {
                    b[k-1].num *= b[k+1].num;
                    b[k].op = 2;
                    b[k+1].num = 0;
                } else if(b[k].op == 2) {
                    b[k-1].num += b[k+1].num;
                    b[k].op = 2;
                    b[k+1].num = 0;
                } else if(b[k].op == 3) {
                    b[k-1].num -= b[k+1].num;
                    b[k].op = 2;
                    b[k+1].num = 0;
                }
            }
        }
        int ret = b[0].num;
        for(int j = 0; j <m; ++j) {
            int k = 2*j+1;
            if(b[k].op == 1){
                ret *= b[k+1].num;
            } else if(b[k].op == 2) {
                ret += b[k+1].num;
            } else if(b[k].op == 3) {
                ret -= b[k+1].num;
            }
        }
        if(ans < ret) ans = ret;
    }
    
    
    return ans;
}
int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int tc;
    cin>>tc;
    for(int t = 1; t <= tc; ++t) {
        cin>>n;
        str = "";
        cin >> str;
        
        cout<<'#'<<t<<' ';
        cout<<solution();
        cout<<'\n';
    }
    return 0;
}
