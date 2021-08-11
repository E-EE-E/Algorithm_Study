//최소값만 더하면 최소, 최대값만 더하면 최대라는 접근 방법은 반례가 있음(1->5->0)
//모든 경우를 다해보기엔 3^100,000???INF!!
//dp를 통해 점화식세워서 풀이 - 위에서 아래로 최대최소값과 더하는 것이 아닌, 아래에서 위로 무엇을 더했을때 최대최소값을 만들수있는가에 포커스
//d[N][0] = minmax(d[N-1][0], d[N-1][1]);
//d[N][1] = minmax(d[N-1][0], d[N-1][1], d[N-1][2]);
//d[N] = minmax(d[N-1][1], d[N-1][2]);

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int columnsize = 3;
int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int tc; cin>>tc;
    for(int t = 1; t <= tc; ++t) {
        int n;
        cin>>n;
//        vector<vector<int>> a(n, vector<int>(columnsize,0));
        vector<int> a(columnsize,0);
        vector<vector<int>> dmax(2, vector<int>(columnsize, 0));
        vector<vector<int>> dmin(2, vector<int>(columnsize, 0));

        for(int j = 0; j < columnsize; ++j) {
            cin>>a[j];
        }
        dmax[0] = dmin[0] = a;
        for(int i = 1; i < n; ++i) {
            cin>>a[0]>>a[1]>>a[2];
            dmax[1][0] = a[0] + max(dmax[0][0], dmax[0][1]);
            dmax[1][1] = a[1] + max(max(dmax[0][0], dmax[0][1]), dmax[0][2]);
            dmax[1][2] = a[2] + max(dmax[0][2], dmax[0][1]);
            dmax[0] = dmax[1];

            dmin[1][0] = a[0] + min(dmin[0][0], dmin[0][1]);
            dmin[1][1] = a[1] + min(min(dmin[0][0], dmin[0][1]), dmin[0][2]);
            dmin[1][2] = a[2] + min(dmin[0][2], dmin[0][1]);
            dmin[0] = dmin[1];

        }
        int ans_max = max(max(dmax[0][0], dmax[0][1]), dmax[0][2]);
        int ans_min = min(min(dmin[0][0], dmin[0][1]), dmin[0][2]);
        
        cout<<'#'<<t<<' ';
        cout<<ans_max<<' '<<ans_min<<'\n';
    }
    return 0;
}
