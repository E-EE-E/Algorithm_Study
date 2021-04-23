/*
 1. 26개의 알파벳이므로 0부터 25까지 index에 선택 한다/안한다 (2가지)경우로
    2^26가지의 경우의 수를 구함, 그 중 k개를 선택
  L 2. N개의 단어 중 배운 알파벳으로만 이루어진 단어를 카운트
 주의사항! 모든 단어에 들어가는 anta/tica에 해당하는 알파벳 a,n,t,i,c는 무조건 배워야 단어를 읽을 수 있음!
 */
#include <cstring>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int n, k;
int ans = 0;

int count (int mask, vector<int> words) { //mask = 배운 알파벳
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if((words[i] & (1<<26)-1-mask) == 0) //단어 & ~mask (안배운 알파벳) == 0-> 배우지않은 알파벳이 들어가지 않은 단어다.
            ans+= 1;
    }
    return ans;
}
int go(int index, int cnt, vector<int> words, int mask) {
    if(cnt < 0) return 0; //cnt개 선택 다 했으면 종료
    if(index == 26) {//26개 알파벳 모두 순회했으면 종료
        //if(index==26 && cnt==0)인 조건을 걸어버리면 26개에서 2개만 선택한 경우 넘어가버림
        if(cnt != 0) return 0; //이 조건 없으면 372ms, 있으면 228ms
        return count(mask, words);
    }
    int ans = 0;
    int temp = go(index + 1, cnt-1, words, mask | (1<<index)); //(mask |= (1<<index))이면 mask값에 업데이트 되므로 주의!
    if(temp > ans) {
        ans = temp;
    }
    if(index != 'a'-'a' && index != 'c' - 'a' && index != 'i'-'a' && index != 't'-'a'
       && index != 'n' - 'a') { //a,c,i,t,n은 꼭 배워야 하므로, 선택하지 않을 수 없음.
        int temp2 = go(index +1, cnt, words, mask);
        if(temp2 > ans) {
            ans = temp2;
        }
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int tc;
    cin>>tc;
    for(int t = 1; t <= tc; ++t) {
        cin >>n>>k;
        vector<int> words(n);
        for(int i = 0; i < n; ++i) {
            string str;
            cin>>str;
            for(int j = 0; j < str.length(); ++j) {
                words[i] |= (1<<(str[j] - 'a')); //문자열 내 문자에 해당하는 비트를 1로 추가
            }
        }
        cout<<'#'<<t<<' ';
        cout<<go(0, k, words, 0);
        cout<< '\n';
    }
    return 0;
}
