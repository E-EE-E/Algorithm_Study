// https://programmers.co.kr/learn/courses/30/lessons/92341
#include <iostream>

#include <string>
#include <vector>
#include <map>

using namespace std;
vector<string> temp;
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<int, bool> check;
    map<int, int> parking_time;
    for(auto record : records){
        size_t it=0, pos=0;
        while(it++<record.length()){
            if(record.c_str()[it] == ':') break;
        }
        int hour = stoi(record.substr(pos, it));
        pos = ++it;
        while(it++<record.length()){
            if(record.c_str()[it] == ' ') break;
        }
        int minute = stoi(record.substr(pos, it-pos));
        pos = ++it;
        while(it++<record.length()){
            if(record.c_str()[it] == ' ') break;
        }
        int car_number = stoi(record.substr(pos, it-pos));
        pos = ++it;
        bool state = record.substr(pos, record.length()-pos)=="IN"?true:false;
        check[car_number]=state;
        int time = hour * 60 + minute;
        if(state) parking_time[car_number] -= time;
        else parking_time[car_number] += time;
    }
    for(auto it_check : check){
        if(it_check.second) parking_time[it_check.first]+=23 * 60 + 59; 
    }
    map<int, int> parking_fee;
    for(auto it_car : parking_time){
        parking_fee[it_car.first]=0;
        if(parking_time[it_car.first]>0){
            parking_time[it_car.first]-=fees[0];
            parking_fee[it_car.first]+=fees[1];
        }
        while(parking_time[it_car.first]>0){
            parking_time[it_car.first]-=fees[2];
            parking_fee[it_car.first]+=fees[3];
        }
    }
    for(auto temp : parking_fee) answer.emplace_back(temp.second);
    return answer;
}

int main(){
    vector<int> fees ={180, 5000, 10, 600};
    vector<string> records = {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"};
    vector<int> result = {14600, 34400, 5000};
    auto answer = solution(fees, records);
    for (auto x : answer) cout<<x<<"\n";
}