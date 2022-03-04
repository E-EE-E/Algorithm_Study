// https://programmers.co.kr/learn/courses/30/lessons/92344
#include <iostream>

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    vector<vector<int>> mask;
    mask.assign(board.size(), {});
    for(size_t i = 0; i<mask.size() ; i++) mask[i].assign(board[0].size(), 0);
    for(auto it_skill : skill){
        if(it_skill[1]>0)
            mask[it_skill[1]-1][it_skill[4]] += (it_skill[0]==1?1:-1) * it_skill[5];
        if(it_skill[2]>0)
            mask[it_skill[3]][it_skill[2]-1] += (it_skill[0]==1?1:-1) * it_skill[5];
        if(it_skill[1]>0 && it_skill[2]>0)
            mask[it_skill[1]-1][it_skill[2]-1] += (it_skill[0]==1?-1:1) * it_skill[5];
        mask[it_skill[3]][it_skill[4]] += (it_skill[0]==1?-1:1) * it_skill[5];
    }
    vector<vector<int>> result = mask;
    for(int i = result.size()-1 ; i >= 0 ; i--){
        for(int j = result[0].size()-2 ; j >= 0 ; j--){
            result[i][j] += result[i][j+1];
        }
    }
    for(int i = result.size()-2 ; i >= 0 ; i--){
        for(int j = result[0].size()-1 ; j >= 0 ; j--){
            result[i][j]+=result[i+1][j];
        }
    }

    int answer = 0;
    for(size_t i = 0 ; i < result.size() ; i++){
        for(size_t j = 0 ; j < result[0].size() ; j++){
            if(result[i][j]+board[i][j]>0) answer++;
        }
    }
    return answer;
}

int main(){
    vector<vector<int>> board = {{5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5}};
    vector<vector<int>> skill = {{1,0,0,3,4,4},{1,2,0,2,3,2},{2,1,0,3,1,2},{1,0,1,3,3,1}};
    int result = 10;
    cout<<solution(board, skill);
    return 0;
}