#factorial using function

def factorial(n):
    if n < 2:
        return 1
    else:
        return n*factorial(n-1)


num = int(input("Enter the number to find factorial : "))

if(num<0):
    print("Finding factorial is not possible..!!")
else:
    result = factorial(num)
    print(f"Factorial of {num} = {result}")