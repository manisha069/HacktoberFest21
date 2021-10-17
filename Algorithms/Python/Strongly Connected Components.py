from collections import defaultdict
class Graph2:

    def __init__(self):

        self.graph = defaultdict(list)
        self.visit = {}
        
        self.tr=[]
        self.count=0

    def addEdge(self,a,b):
        
        self.graph[a].append(b)

    def dfs(self, v):

        self.visit[v]=1
        self.count+=1
        for i in self.graph[v]:
            if(i not in self.visit):
                self.dfs(i)
    
    


class Graph:
 

    def __init__(self):

        self.graph = defaultdict(list)
        self.visit = {}
        self.count={}
        self.tr=[]
        

    def addEdge(self,a,b):
        
        self.graph[a].append(b)

 
    def dfs(self, v):
        
        self.visit[v]=1
       
        
        for neighbour in self.graph[v]:
            if neighbour not in self.visit:
                self.dfs(neighbour)

        self.tr.append(v)





g = Graph() 
g2 = Graph2()
n,m = map(int,input().split())
for i in range(m):
    x,y = map(int,input().split())
    g.addEdge(x,y)
    g2.addEdge(y,x)


for i in range(1,n+1):
    try:
        g.visit[i]+=1
    except:
        g.dfs(i)


c=0
for i in (reversed(g.tr)):
    try:
        g2.visit[i]+=1
    except:
        
        g2.dfs(i)
        if(g2.count==1):
            c+=1
            g2.count=0
        else:
            g2.count=0
            
print(c)
