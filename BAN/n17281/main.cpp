#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
vector<vector<int>> inning;
vector<int> player;
vector<bool> check;

int solution() {
    int now = 0;
    int score = 0;

    for(int i = 0; i < n; ++i) {
        int b1 = 0;
        int b2 = 0;
        int b3 = 0;
        int out = 0;
        while(out < 3) {
            int ret = inning[i][player[now]];
            if(ret == 0) {
                out += 1;
            }else if(ret == 1) {
                score+= b3;
                b3 = b2; b2 = b1; b1 = 1;
            }else if(ret == 2) {
                score+= b3+b2;
                b3=b1; b2=1; b1 = 0;
            }else if(ret == 3) {
                score+= b3+b2+b1;
                b3 = 1; b2 = 0; b1 = 0;
            }else {
                score+= b3+b2+b1+1;
                b3 = b2 = b1 = 0;
            }
            now+=1;
            if(now == 9) now = 0;
        }
    }
    
    return score;
}
int go(int idx) {
    if(idx == 9) {//1번선수빼고 8명타자 다 모았으면
        return solution();
    }
    if(idx == 3) { //4번타자이면
        player[idx] = 0; //4번타자 = 1번선수
        return go(idx + 1);
    }
    int ans = 0;
    for(int i = 1; i < 9 ; ++i) {
        if(check[i]) continue;
        check[i] = true;
        player[idx] = i;

        int temp = go(idx + 1); //solution야구게임 돌고오면
        if(ans < temp) ans = temp;
        check[i] = false;
        player[idx] = 0;
        
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int tc;
    cin>> tc;
    for(int t = 1; t <= tc; ++t) {
        cin>>n;
        inning.clear();
        for(int i = 0; i < n; ++i) {
            vector<int> temp;
            for(int j = 0; j < 9; ++j) {
                int x;
                cin>>x;
                temp.push_back(x);
            }
            inning.push_back(temp);
        }
        for(int j = 0; j < 9; ++j) {
            check.push_back(false);
            player.push_back(0);
        }
        cout<<'#'<<t<<' ';
        cout<<go(0);
        cout<<'\n';
    }
    return 0;
}
