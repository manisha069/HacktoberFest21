import sys
sys.setrecursionlimit(1000000000)
from collections import defaultdict
class Graph:
 

    def __init__(self):

        self.graph = defaultdict(list)
        self.visit = {}
        self.count={}
        self.time=0
        self.disc={}
        self.low={}
        self.papa={}
        self.ans={}

    def addEdge(self,a,b):
        
        self.graph[a].append(b)

 
    def dfs(self, v):
        
        self.visit[v]=1
        self.time+=1
        self.disc[v]=self.time
        self.low[v]=self.time
        
        for i in self.graph[v]:
            if i not in self.visit:
                self.papa[i]=v
                self.dfs(i)
                self.low[v]=min(self.low[v],self.low[i])

                if(self.disc[v]<self.low[i]):
                    self.ans[(v,i)]=1
                
        
            else:
                if(self.papa[v]!=i):
                    self.low[v]=min(self.low[v],self.disc[i])

g = Graph()
n,m = map(int,input().split())
ll=[]
for __ in range(m):
    a,b = map(int,input().split())
    g.addEdge(a,b)
    g.addEdge(b,a)
    ll.append((a,b))

ff= int(input())
for i in range(1,n+1):
    try:
        g.visit[i]+=1
    except:
        g.papa[i]=-1
        g.dfs(i)


for ___ in range(ff):
    x = int(input())
    try:
        
        g.ans[ll[x-1]]+=1

        print("Unhappy")
    except:
        try:
            lp = list(ll[x-1])
            lp.reverse()
            lp = tuple(lp)
            
            g.ans[lp]+=1
            print("Unhappy")
        except:
            print("Happy")
