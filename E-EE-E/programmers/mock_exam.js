//let answers = [1,2,3,4,5];
let answers = [1,3,2,4,2]
console.log(solution(answers));
function solution(answers) {
    var answer = [];
    let way = [[1,2,3,4,5], [2,1,2,3,2,4,2,5], [3,3,1,1,2,2,4,4,5,5]];
    let cnt = [0,0,0];
    for(let i=0;i<way.length;i++){
        for(let j=0;j<answers.length;j++){
            if(answers[j]==way[i][j%way[i].length]) cnt[i]++;
        }
    }
    let max = Math.max.apply(null, cnt);
    for(let i=0;i<way.length;i++) if(cnt[i]==max) answer.push(i+1);
    return answer;
}