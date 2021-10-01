#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> res;
void go(int index, int start, vector<int> &a) {
    if(index == m) {
        for(int r : res) cout<<r<<' ';
        cout<<'\n';
        return;
    }
    vector<bool> check(n, false);
    for(int i = start; i < n; ++i) {
        if (check[i]) continue;
        check[i] = true;
        res.push_back(a[i]);
        go(index + 1, i, a);
        res.pop_back();
    }
}
int main(int argc, const char * argv[]) {
    cin>>n>>m;
    vector<int> a(n, 0);
    for(int i = 0; i < n; ++i) {
        cin>> a[i];
    }
    sort(a.begin(), a.end());
    go(0, 0, a);
    
    return 0;
}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int n, m;
//vector<int> res;
//void go(int index, vector<int> &a) {
//    if(index == m) {
//        for(int r : res) cout<<r<<' ';
//        cout<<'\n';
//        return;
//    }
//    vector<bool> check(n, false);
//    for(int i = 0; i < n; ++i) {
//        if (check[i]) continue;
//        if(!res.empty() && res.back() > a[i]) continue;
//        check[i] = true;
//        res.push_back(a[i]);
//        go(index + 1, a);
//        res.pop_back();
//    }
//}
//int main(int argc, const char * argv[]) {
//    cin>>n>>m;
//    vector<int> a(n, 0);
//    for(int i = 0; i < n; ++i) {
//        cin>> a[i];
//    }
//    sort(a.begin(), a.end());
//    go(0, a);
//
//    return 0;
//}
