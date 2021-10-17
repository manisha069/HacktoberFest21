# -*- coding: utf-8 -*-
"""
Created on Thu May  20 22:29:00 2021

@author: Kamesh
"""

import time
string = "\nPython is an interpreted, high-level programming language"
word_count = len(string.split())
sepration = '*'*65

def createbox():
    print(sepration)
    print('\nEnter the below phrase as fast as possible and with accuracy')
    
while  True:
    t0 = time.time()
    createbox()
    print(string,'\n')
    print(sepration)
    inputText = str(input(">>"))
    t1 = time.time()
    lengthOfInput = len(inputText.split())
    accuracy = len(set(inputText.split()) & set(string.split()))
    accuracy = (accuracy/word_count)
    timeTaken = (t1 - t0)
    wordsperminute = (lengthOfInput/timeTaken)*60 
    #Showing results now
    print(sepration)
    print('Total words \t :' ,lengthOfInput)
    print('Time used \t :',round(timeTaken,2),'seconds')
    print('Your accuracy \t :',round(accuracy,3)*100,'%')
    print('Speed is \t :' , round(wordsperminute,2),'words per minute')
    print(sepration)
    print("Do you want to retry!!",end='')
    if input():
        continue
    else:
        print('Thank you, bye bye!!')
        break