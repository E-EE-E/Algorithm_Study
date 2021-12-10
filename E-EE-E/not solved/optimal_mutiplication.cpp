//https://programmers.co.kr/learn/courses/30/lessons/12942
#include "iostream"
#include <string>
#include <vector>
#include "map"

using namespace std;

int solution(vector<vector<int>> matrix_sizes) {
    int answer = 0;
    map<int, map<int, int>> dir;
    for(auto x : matrix_sizes){
        dir[x[0]][x[1]]++;
    }
    printf("fdir\n");
    for(auto x : dir){
        for(auto y : x.second) printf("%d %d %d\n", x.first, y.first, y.second);
    }
    int cnt=0;



    int a, b, c;
    while(cnt<matrix_sizes.size()-1){
        cnt++;
        auto a=dir.begin();
        auto b=dir[(*a).first].begin();
        auto c=dir[(*b).first].begin();
        answer+=(*a).first*(*b).first*(*c).first;

        dir[(*a).first][(*b).first]++;
        bdir[(*c).first][(*b).first]++;
        printf("%d %d->%d %d->%d %d\n", (*a).first, (*b).first, (*b).second, (*c).first, (*c).second, answer);
        if(--(*b).second==0){
            fdir[(*a).first].erase(b);
            if(fdir[(*a).first].size()==0) fdir.erase(a);
        }
        if(--(*c).second==0){
            bdir[(*b).first].erase(bdir[(*b).first].begin());
            if(bdir[(*b).first].size()==0) bdir.erase(bdir.find((*b).first));
        }
    }
    
    return answer;
}

int main(){
    vector<vector<int>> matrix_sizes = {{5,3},{3,10},{10,6}};
    cout<<solution(matrix_sizes);
    return 0;
}