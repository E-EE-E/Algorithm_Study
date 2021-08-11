#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
int numsize = 10;
int num[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int getnum(string str, vector<pair<int, int>> &select) {
    int ret = 0;
    for(int i = 0; i < str.length(); ++i) {
        int temp = 0;
        for(auto s : select) {
            if(s.first == str[i] - 'A') {
                temp = s.second;
                break;
            }
        }
        ret = ret * 10 + temp;
    }
    
    return ret;
}
int go(vector<string> &words, vector<pair<int, int>> &select, int index, int cnt, vector<bool> & visited) {
    if(index == cnt) {
        int sum = 0;
        for(string word : words) {
            sum += getnum(word, select);
        }
        return sum;
    }
    int ans = -1;
    for(int i = 0; i < numsize; ++i) {
        if(visited[i] == true) continue;
        visited[i] = true;
        select[index].second = num[i];
        int temp = go(words, select, index + 1, cnt, visited);
        if (ans == -1 || temp > ans) {
            ans = temp;
        }
        visited[i] = false;
    }
    
    return ans;
}
int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int tc;
    cin>>tc;
    for(int t = 1; t <= tc; ++t) {
        int ans = 0;
        int n;
        cin>>n;
        vector<string> words(n);
        vector<pair<int, int>> select;//알파벳, 숫자

        char temp = ' ';
        for(int i = 0; i < n; ++i) {
            cin>>words[i];
            for(char c : words[i]) {
                if(c != temp) {
                    temp = c;
                    select.push_back(make_pair(c-'A', -1));
                }
            }
        }
        vector<bool> visited(numsize, false);
        ans = go(words, select, 0, (int)select.size(), visited);
        cout<<'#'<<t<<' ';
        cout<<ans<<'\n';
    }
    return 0;
}
