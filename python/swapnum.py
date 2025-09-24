num1 = int(input("Enter first number : "))
num2 = int(input("Enter second number : "))

print("Numbers before swap : ")
print(f"Number 1 : {num1}")
print(f"Number 2 : {num2}")

num1 = num1+num2
num2 = num1 - num2
num1 = num1 - num2

print("Numbers after swap : ")
print(f"Number 1 : {num1}")
print(f"Number 2 : {num2}")