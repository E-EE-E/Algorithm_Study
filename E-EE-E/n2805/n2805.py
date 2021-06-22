#runtimeout
N, M = input().split(' ')
N=int(N)
M=int(M)
arr = []
arr=list(map(int, input().split(" ")))
arr.sort(reverse=True)
k=arr[0]
cnt=sum=0
while(k>-1):
    if(cnt<len(arr) and k<arr[cnt]):
        cnt+=1
        continue
    sum+=cnt
    if(sum>=M):
        print(k)
        break
    k-=1