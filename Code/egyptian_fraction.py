import math

#Egyptian fraction representation via greedy algorithm
def egyptian_fraction(numerator, denominator):
 
    print("The representation of {0}/{1} is".format(numerator, denominator), end=" ")
 
    lst = []
    while numerator != 0:
        ceil_value = math.ceil(denominator/numerator)
        lst.append(ceil_value)
        numerator = ceil_value * numerator - denominator
        denominator = denominator * ceil_value
 
    for i in range(len(lst)):
        if i != len(lst) - 1:
            print(" 1/{0} +" .format(lst[i]), end = " ")
        else:
            print(" 1/{0}" .format(lst[i]), end = " ")

numerator = int(input("Enter the numerator"))
denominator = int(input("Enter the denominator"))
egyptian_fraction(numerator, denominator)