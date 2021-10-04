def num_rev_str(num):
    if num.isnumeric():
        rev_num_str = num[::-1]
        return int(rev_num_str)
    else:
        rev_num_str = num[::-1]
        return (rev_num_str + "\nData entered is not number...\nTry again.. :')")


num_str = input("Enter number to reverse - ")
print("Reverse of {} is equal to {} ".format(
    num_str, num_rev_str(num_str)))
