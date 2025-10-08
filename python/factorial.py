#program to find factorial of a number
num = int(input("Enter the number to find factorial : "))
factorial = 1
for i in range(1,num+1):
    factorial = i*factorial
print(f"factorial of {num} is {factorial}")
