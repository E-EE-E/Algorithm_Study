#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m, k;

vector<vector<int>> a;
vector<vector<int>> rcs;

void array_op(vector<int> rcs) {
    int r = rcs[0];
    int c = rcs[1];
    int s = rcs[2];
    vector<vector<int>> groups;
    for(int g = 0; g < s; ++g) {
        vector<int> group;
        for(int j = g; j <= 2*s-g; ++j) {
            group.push_back(a[r-s+g][c+s-j]);
        }
        for(int i = g+1; i < 2*s-g; ++i) {
            group.push_back(a[r-s+i][c-s+g]);
        }
        for(int j = g; j <= 2*s-g; ++j) {
            group.push_back(a[r+s-g][c-s+j]);
        }
        for(int i = g+1; i < 2*s-g; ++i) {
            group.push_back(a[r+s-i][c+s-g]);
        }
        groups.push_back(group);
    }
    for(int g = 0; g < s; ++g) {
        vector<int> &group = groups[g];
        int len = (int)group.size();
        int idx = 1;
        for(int j = g; j <= 2*s-g; ++j, idx = (idx+1)%len) {
            a[r-s+g][c+s-j] = group[idx];
        }
        for(int i = g+1; i < 2*s-g; ++i, idx = (idx+1)%len) {
            a[r-s+i][c-s+g] = group[idx];
        }
        for(int j = g; j <= 2*s-g; ++j, idx = (idx+1)%len) {
            a[r+s-g][c-s+j] = group[idx];
        }
        for(int i = g+1; i < 2*s-g; ++i, idx = (idx+1)%len) {
            a[r+s-i][c+s-g] = group[idx];
        }
    }
}

int solution() {
    int ans = 100000;
    vector<vector<int>> temp;
    temp =a;
    do {
        int min = 10000;
        //연산
        for(int i = 0; i < k; ++i) {
            array_op(rcs[i]);
        }
        //연산 후 최소값 구하기!!!!
        for(int i = 0; i < n; ++i) {
            int sum = 0;
            for(int j = 0; j < m; ++j) {
                sum += a[i][j];
            }
            min = min > sum? sum: min;
        }
        ans = min < ans? min : ans;
        a = temp; //다시 원래 배열로 돌려놓기!!!!
    }while(next_permutation(rcs.begin(), rcs.end())); //순열구하기
    
    return ans;
}

int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int tc;
    cin>>tc;
    for(int t = 1; t<= tc; ++t) {
        cin>>n>>m>>k;
        for(int i = 0; i < n; ++i) {
            vector<int> temp;
            for(int j = 0; j < m; ++j) {
                int x;
                cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
        rcs.clear();
        for(int i = 0; i < k; ++i) {
            int r, c, s;
            cin>>r>>c>>s;
            r-=1; c-=1;
            vector<int> temp;
            temp.push_back(r);
            temp.push_back(c);
            temp.push_back(s);
            rcs.push_back(temp);
        }
        sort(rcs.begin(), rcs.end());  //순열구하기 전에 정렬한번하기!!!!!
        cout<<'#'<<t<<' ';
        cout<< solution();
        cout<<'\n';
    }
    return 0;
}
