#include <iostream>
#include <vector>
using namespace std;

//inorder : L/ Root / R
//postorder : L/R/Root
//preorder : Root/L/R
int inidx[100001];
void go(int si, int ei, int sp, int ep, vector<int> &in, vector<int> &post) {
    if(si > ei || sp > ep) {
        return;
    }
    int root = post[ep]; //root 값
    cout<<root<<' ';
    
    int idx = inidx[root]; //in에서의 root 위치
    int length = idx - si;
    //L
    go(si, idx-1, sp, sp+length-1, in, post);
    //R
    go(idx+1, ei, sp+length, ep-1, in, post);
}
int main() {
    int n;
    cin>>n;
    vector<int> in(n+1, 0);//1~n (범위 주의하자!)
    vector<int> post(n+1, 0);
    for(int i = 1; i <= n; ++i) {
        cin>>in[i];
    }
    for(int i = 1; i <= n; ++i) {
        cin>>post[i];
    }
    for(int i = 1; i <= n; ++i) {
        inidx[in[i]] = i; //in값이 몇번 index냐
    }
    
    go(1, n, 1, n, in, post);
    
    return 0;
}
