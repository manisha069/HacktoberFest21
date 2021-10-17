# Searching an element in a list/array in python
# can be simply done using \'in\' operator
# Example:
# if x in arr:
#   print arr.index(x)
  
# If you want to implement Linear Search in python
  
# Linearly search x in arr[]
# If x is present then return its location
# else return -1
  
def search(arr, x):
  
    for i in range(len(arr)):
        #returning the index of the element if found
        if arr[i] == x:
            return i
        
  
    return -1


# implementation

numbers = ["zero","one","two","three","four"]

s = input("Enter the search keyword:-")

ans = search(numbers, s)

if ans == -1:
    print(f"{s} is not present")
else:
    print(f"{s} is present at position {ans}")