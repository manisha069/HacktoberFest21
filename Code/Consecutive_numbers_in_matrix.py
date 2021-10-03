n=int(input())
res=[]
l=[]
for i in range(n):
    arr=[int(i) for i in input().split()]
    l.append(arr)
for i in range(len(l)):
    for j in range(len(l[0])-2):
        if(l[i][j]==l[i][j+1]==l[i][j+2]):
            res.append(l[i][j])
for i in range(len(l)-2):
    for j in range(len(l[0])):
        if(l[i][j]==l[i+1][j]==l[i+2][j]):
            res.append(l[i][j])  
for i in range(len(l)):
    for j in range(len(l[0])):
        if((j<len(l)-2) and (i<len(l)-2)):
            if(l[i][j]==l[i+1][j+1]==l[i+2][j+2]):
                res.append(l[i][j]) 
        if((j>=2) and (i<len(l)-2)):
            if(l[i][j]==l[i+1][j-1]==l[i+2][j-2]):
                res.append(l[i][j])  
print(min(res))