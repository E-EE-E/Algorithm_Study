//string으로 한줄을 받되, 각 요소는 char임을 주의하자!(char to int!)
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//#define _DEBUG_
int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    vector<string> a(n, "");
    for(int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    vector<vector<int>> b(n, vector<int>(m, 0));
    int max = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(i == 0 || j == 0) {
                b[i][j] = a[i][j]-'0';
            }
            else {
                if(a[i][j]-'0' == 1) {
                    b[i][j] = min(min(b[i-1][j], b[i][j-1]), b[i-1][j-1]) + 1;
                }
            }
            if(b[i][j] > max) {
                max = b[i][j];
            }
        }
    }

#ifdef _DEBUG_
    cout<<"---------a---------\n";
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<"---------b---------\n";
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cout<<b[i][j]<<' ';
        }
        cout<<'\n';
    }
#endif
    cout<<max*max<<'\n';
    
    return 0;
}
