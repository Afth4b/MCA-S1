a=int(input("Enter a number : "))
b=int(input("Enter second number : "))

print("gcd(%d,%d)"%(a,b))

while b:
    a,b = b, a%b

print("Gcd is : "+str(a))