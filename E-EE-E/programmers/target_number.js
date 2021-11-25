//https://programmers.co.kr/learn/courses/30/lessons/43165
let numbers = [1,1,1,1,1], target = 3;
console.log(solution(numbers, target));

function solution(numbers, target) {
    var answer = 0;
    let set = [];
    function dfs(){
        if(set.length==numbers.length){
            let result = 0;
            for(let i =0;i<numbers.length;i++) result+=numbers[i]*set[i];
            if(result==target) answer++;
            return;
        }
        set.push(1);
        dfs();
        set.pop();
        set.push(-1);
        dfs();
        set.pop();
        return;
    }
    dfs();
    return answer;
}

