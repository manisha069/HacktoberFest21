import random

# Banner
print("""     _ _          
    | (_)         
  __| |_  ___ ___ 
 / _` | |/ __/ _ \\
| (_| | | (_|  __/
 \__,_|_|\___\___|\n""")

x="y"
n=int(input("Enter the number of die you wanna throw: "))

def roll():
    dice = {
        1: """|----------|
|          |
|    O     |
|          |
|----------|""",
        2: """|----------|
|          |
|  O    O  |
|          |
|----------|""",
        3: """|----------|
| O        |
|     O    |
|        O |
|----------|""",
        4: """|----------|
| O      O |
|          |
| O      O |
|----------|""",
        5: """|----------|
| O      O |
|     O    |
| O      O |
|----------|""",
        6: """|----------|
| O      O |
| O      O |
| O      O |
|----------|"""
    }
    rand = random.randint(1, 6)
    print(dice.get(rand, "nothing"))
    print(f"You Rolled a {rand}")

while(x!="q"):
    for i in range(0,n):
        roll()
    x=input("Enter any key to Roll Again or 'q' to exit: ")




