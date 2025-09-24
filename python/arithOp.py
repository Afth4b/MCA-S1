#Arithmetic Operations

num1= int(input("Enter operand 1 : "))
num2 = int(input("Enter operand 2 : "))

print("Select Operation : ")
print("1.Addition (+)")
print("2.Substract (-)")
print("3.Multiplication (*)")
print("4.Division (/)")

choice = input("Enter your choice (1,2,3,4) : ")

if choice =='1':
    result = num1+num2
    print(f"{num1} + {num2} = {result}")
elif choice == '2':
    result = num1-num2
    print(f"{num1} - {num2} = {result}")
elif choice == '3':
    result = num1*num2
    print(f"{num1} * {num2} = {result}")
elif choice == '4':
    if num2 == 0:
        print("Invalid operands")
    else:
        result = num1/num2
        print(f"{num1} / {num2} = {result}")
