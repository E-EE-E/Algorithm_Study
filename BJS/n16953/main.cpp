#include <iostream>
#include <vector>
using namespace std;

int a, b;
int min_ans = -1;
void go(string res, int ans) {
    if(stoll(res) == b) {
        if(min_ans == -1 || ans < min_ans)
            min_ans = ans;
        return;
    }
    if(stoll(res) > b) return;
    
    go(to_string(stoll(res)*2), ans+1);
    go(res+"1", ans+1);
}

int main(int argc, const char * argv[]) {
    cin>>a>>b;
    go(to_string(a), 1);
    
    cout<<min_ans<<'\n';
    
    return 0;
}
