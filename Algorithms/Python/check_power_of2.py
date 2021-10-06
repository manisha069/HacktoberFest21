def check(n):
    if n&(n-1)==0:   #this operation will replace rightest set bit with zero 
        return True  # so as power of 2 as only one set bit so one remvoving that set bit number will be 0
    else:            #for ex (8(1000)&7((111)) is 0 so it is power of 2)
        return False
                   
        
print(10&9)