//https://programmers.co.kr/learn/courses/30/lessons/42862?language=javascript
let n = 5;
let lost = [2,4];
let reserve = [1,3,5];
console.log(solution(n ,lost, reserve));

function solution(n, lost, reserve) {
    var answer = 0;
    let arr = [];
    for(let i=0;i<n;i++) arr.push(1);    
    for(let i=0;i<lost.length;i++) arr[lost[i]-1]--;
    for(let i=0;i<reserve.length;i++) arr[reserve[i]-1]++;
    for(let i=0;i<n;i++){
        if(arr[i]==0){
            if(i-1>-1 && arr[i-1]>1) arr[i-1]--, arr[i]++;
            else if(i+1<n && arr[i+1]>1) arr[i+1]--, arr[i]++;
        }
    }
    for(let i=0;i<n;i++) if(arr[i]>0) answer++;
    return answer;
}