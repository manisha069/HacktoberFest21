class MyStack:

def __init__(self):
    self.queue = []

def push(self, x: int) -> None:
    self.queue = [x] + self.queue

def pop(self) -> int:
    ans = self.queue        
    self.queue = ans[1:]
    return ans[0]

def top(self) -> int:
    return self.queue[0]

def empty(self) -> bool:
    return not self.queue
