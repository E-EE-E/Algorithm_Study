X, Y=input().split(' ')
x=float(X)
y=float(Y)
z=-1
for i in range(99):
    if(x*(i/100)<=y and y<x*((i+1)/100)):
        z=i
        break
if(z==-1):
    print(z)
    exit()
k=((z+1)*x-100*y)/(99-z)
if(int(k)<k):
    k+=1;
print(int(k))
