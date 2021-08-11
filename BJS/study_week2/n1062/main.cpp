#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
int ans = 0;
void go(int k, int index, int bitmask, vector<int> &words) {
    if(k < 0) { //왜 여기서 세면 안되지? 중복인가? // 더이상 선택할 알파벳 개수가 남지 않았으므로 종료
//        int sum = 0;
//        for(int i = 0; i < words.size(); ++i) {
//            int word = words[i];
//            if(word == (word & bitmask))
//                sum += 1;
//        }
//        if(sum > ans) {
//            ans = sum;
//        }
        return;
    }
    if(index == 26) { // 모든 알파벳을 지나면 종료
        int sum = 0;
        for(int i = 0; i < words.size(); ++i) {
            int word = words[i];
            if(word == (word & bitmask))
                sum += 1;
        }
        if(sum > ans) {
            ans = sum;
        }
        return;
    }
    
    go(k - 1, index + 1, bitmask | (1<<index), words);
    
    if((index != 'a'-'a')&&(index != 'n'-'a')&&(index != 'i'-'a')&&(index != 't'-'a')&&(index != 'c'-'a')) {
        go(k, index + 1, bitmask, words);
    }
    
}
int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int tc;
    cin>>tc;
    for(int t = 1; t <= tc; ++t) {
        ans = 0;
        int n, k;
        cin>>n>>k;
        vector<int> words(n, 0);
        for(int i = 0; i < n; ++i) {
            string tmp;
            cin>>tmp;
            for(char c : tmp) {
                words[i] |= (1<<(c-'a'));
            }
        }
        go(k, 0, 0, words);
        cout<<'#'<<t<<' ';
        cout<<ans<<'\n';
        
    }
    return 0;
}
