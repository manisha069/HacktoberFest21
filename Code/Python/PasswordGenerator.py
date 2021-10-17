import random

name = input("Enter your name:")
print("Hey",name +'! Let me help you by generating a random password for you!')

chars = 'QAZWSXEDCRFVTGBYHNUJMIKLOPqazwsxedcrfvtgbyhnujmikolp1234567890_@!#$%^&*:;'

length = int(input('Enter the length of password required:'))

password = ''
for c in range(length):
    password += random.choice(chars)
print(password)

print("I hope this helped. Thankyou for using!")
