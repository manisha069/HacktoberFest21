# Getting user input to get length of sequence
n = int(input("Fibonacci Sequence of how many digits: "))

# Declaration of variables and first and second digit
n1, n2 = 0, 1
sum = 0
list = []

# Conditions to print the fibonacci sequence
if n == 1:
    print(list.append(n1))

elif n <= 0:
    print("Enter number greater than 0")
else:
    for i in range(n):
        list.append(n1)
        sum = n1 + n2
        n1 = n2
        n2 = sum

print(list)
