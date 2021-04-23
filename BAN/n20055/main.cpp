#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> a;
int solution() {
    int len = 2*n;
    vector<bool> robot(len, false);
    
    int ans = 0;
    int cnt = 0;
    while(true) {
        ans += 1;
        //1.벨트 한칸 회전
        rotate(a.rbegin(), a.rbegin() + 1, a.rend());
        rotate(robot.rbegin(), robot.rbegin()+1, robot.rend());
        if(robot[n-1] == true) {
            robot[n-1] = false;
        }
        for(int i = n-2; i >= 0; --i) {//n-1에는 로봇이 오지않기때문에 n-1~2n-1까지는 로봇이 없다!!
            if(robot[i] == true) { //current robot
                if(robot[i+1] == false) { //next part- no robot
                    if(a[i+1] > 0) {
                        robot[i+1] = true;
                        robot[i] = false;
                        a[i+1] -= 1;
                        if(a[i+1] == 0) {
                            cnt += 1;
                        }
                    }
                }
            }
        }
        if(robot[n-1] == true) {
            robot[n-1] = false;
        }
        
        if(a[0] > 0 && robot[0] == false) {
            a[0] -= 1;
            robot[0] = true;
            if(a[0] == 0) {
                cnt += 1;
            }
        }
        if(cnt >= k) break;
    }
    
    return ans;
}
int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int tc;
    cin>>tc;
    for(int t = 1; t <= tc; ++t) {
        a.clear();
        cin>>n>>k;
        for(int i = 0; i < 2*n; ++i) {
            int x;
            cin>>x;
            a.push_back(x);
        }
        cout<<'#'<<t<<' ';
        cout<<solution();
        cout<<'\n';
    }
    return 0;
}
