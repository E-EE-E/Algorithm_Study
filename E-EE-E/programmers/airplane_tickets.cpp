//https://programmers.co.kr/learn/courses/30/lessons/43164
#include "iostream"
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, map<string, int>> tickets_map;
vector<string> answer, way={"ICN"};
int n, flag=0;
void dp (string port, int cnt){
    if(way.size()==n+1){
        answer=way;
        flag=1;
        return;
    }
    for(auto x : tickets_map[port]){
        if(tickets_map[port][x.first]>0){
            tickets_map[port][x.first]--;
            way.push_back(x.first);
            dp(x.first, cnt+1);
            if(flag==1) return;
            tickets_map[port][x.first]++;
            way.pop_back();
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    n = tickets.size();
    for(auto x : tickets)
        tickets_map[x[0]][x[1]]++;
    dp("ICN", 0);

    return answer;
}

int main(){
    vector<vector<string>> tickets;
    tickets = {{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}};
    for(auto x : solution(tickets)) cout<<x<<"\n";
    return 0;
}