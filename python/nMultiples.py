#First n multiples

num = int(input("Enter a number : "))
n = int(input("How many multiples do you want to print : "))

if(n<=0):
    print("Invalid input")
else:
    print(f"Mulitples of {num}")
    for i in range(1,n+1):
        mul = num*i
        print(f"{i} * {num} = {mul}")