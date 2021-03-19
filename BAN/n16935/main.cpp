#include <iostream>
#include <vector>
// 배열연산에 따라 index바꿔주기

using namespace std;
vector<vector<int>> operation1(vector<vector<int>> a) {
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> ans(n, vector<int>(m));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            ans[i][j] = a[n-i-1][j];
        }
    }
    return ans;
}
vector<vector<int>> operation2(vector<vector<int>> a) {
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> ans(n, vector<int>(m));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            ans[i][j] = a[i][m-j-1];
        }
    }
    return ans;
}
vector<vector<int>> operation3(vector<vector<int>> a) {
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> ans(m, vector<int>(n));
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            ans[i][j] = a[n-j-1][i];
        }
    }
    return ans;
}
vector<vector<int>> operation4(vector<vector<int>> a) {
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> ans(m, vector<int>(n));
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            ans[i][j] = a[j][m-i-1];
        }
    }
    return ans;
}
vector<vector<int>> operation5(vector<vector<int>> a) {
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> ans(n, vector<int>(m));
    for(int i = 0; i < n/2; ++i) {
        for(int j = 0; j < m/2; ++j) {
            ans[i][j+m/2] = a[i][j];
            ans[i+n/2][j+m/2] = a[i][j+m/2];
            ans[i+n/2][j] = a[i+n/2][j+m/2];
            ans[i][j] = a[i+n/2][j];
        }
    }
    return ans;
}
vector<vector<int>> operation6(vector<vector<int>> a) {
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> ans(n, vector<int>(m));
    for(int i = 0; i < n/2; ++i) {
        for(int j = 0; j < m/2; ++j) {
            ans[i+n/2][j] = a[i][j];
            ans[i+n/2][j+m/2] = a[i+n/2][j];
            ans[i][j+m/2] = a[i+n/2][j+m/2];
            ans[i][j] = a[i][j+m/2];
        }
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    int n, m, r;
    cin>>n>>m>>r;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin>>a[i][j];
        }
    }
    while(r--) {
        int op;
        cin>>op;
        switch(op){
            case 1:
                a = operation1(a);
                break;
            case 2:
                a = operation2(a);
                break;
            case 3:
                a = operation3(a);
                break;
            case 4:
                a = operation4(a);
                break;
            case 5:
                a = operation5(a);
                break;
            case 6:
                a = operation6(a);
                break;
        }
    }
    for(int i = 0; i < a.size(); ++i) {
        for(int j = 0; j < a[0].size(); ++j) {
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
