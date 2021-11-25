function solution(n, lost, reserve) {
    var CanAttend = [0];
    for( let i = 0 ; i<n; i++){ CanAttend.push(1); }
    CanAttend.push(0);
    for( let i = 0 ; i<lost.length; i++){ CanAttend[lost[i]] --;  }
    for( let i = 0 ; i<reserve.length; i++){ CanAttend[reserve[i]] ++; }
    for( let i = 0 ; i<lost.length; i++){
        if(CanAttend[lost[i]] == 1 ){ continue; }
        if(CanAttend[lost[i]-1] > 1 ){ 
            CanAttend[lost[i]-1] --;
            CanAttend[lost[i]] ++;
            continue;
        }
        if(CanAttend[lost[i]+1] > 1 ){ 
            CanAttend[lost[i]+1] --;
            CanAttend[lost[i]] ++;
            continue;
        } 
    }
    var answer = 0;
    for( let i = 0; i<CanAttend.length; i++){ CanAttend[i]>0 ? answer++ : answer}
    return answer;
}