#include <iostream>
// 주어진 E, S, M 에서 -1을 하면 범위가 의미하는 바는 15, 28, 19로 나눈 나머지를 의미하게 됨
// ex) year mod(%) E == 15
// 세 조건을 모두 만족하는 year를 찾고 year +1

using namespace std;
int main(int argc, const char * argv[]) {
    
    unsigned int E, S, M;
    unsigned int year = 0;
    
    cin>>E>>S>>M;
    
    for(year = 0; year < 15*28*19; ++year)
    {
        if(year%15 == E-1 && year%28 == S-1 && year%19 == M-1)
        {
            printf("%d\n", year+1);
            break;
        }
    }
    
    return 0;
}
