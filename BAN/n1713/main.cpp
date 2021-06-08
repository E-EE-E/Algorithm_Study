#include <cstdio>
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

bool cmp(const tuple<int, int, int> &u, const tuple<int, int, int> &v) {
    if(get<0>(u) == get<0>(v))
        return get<1>(u) < get<1>(v);
    return get<0>(u) < get<0>(v);
}
bool resetcmp(const tuple<int, int, int> &u, const tuple<int, int, int> &v) {
    return get<2>(u) < get<2>(v);
}
int main(int argc, const char * argv[]) {

    int n, m;
    cin>>n>>m;
    vector<tuple<int, int, int>> a; //추천수, 시간, 번호
    for(int i = 0; i < 100; ++i) {
        a.push_back(make_tuple(0, 0, i));
    }
    int cnt = 0;
    for(int i = 0; i < m; ++i) {
        int p;
        cin>> p; p--;
        if(get<0>(a[p]) != 0) {
            get<0>(a[p]) += 1;
        } else {
            cnt += 1;
            if(cnt > n) {
                sort(a.begin(), a.end(), cmp);
                int index = 0;
                for(auto &temp : a) {
                    if(get<0>(temp) == 0) continue;
                    index = get<2>(temp); break;
                }
                sort(a.begin(), a.end(), resetcmp);
                get<0>(a[index]) = 0;
                get<1>(a[index]) = 0;
            }
            get<0>(a[p]) += 1;
            get<1>(a[p]) = i+1;
        }
    }
    for(int i = 0; i < a.size(); ++i) {
        if(get<1>(a[i]) == 0) continue;
        cout<<get<2>(a[i])+1<<' ';
    }
    return 0;
}
