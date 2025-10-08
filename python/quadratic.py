#to find the roots of a quadratic equation
import math
a = int(input("Enter the coefficient for a : "))
b = int(input("Enter the coefficient for b : "))
c = int(input("Enter the coefficient for c : "))

d= (b**2)-(4*a*c)

if d == 0:
    print("Only one root")
    r = (-b)/2*a
    print("root : ",r)
elif d>0:
    print("Two real roots")
    r1 = ((-b)+math.sqrt(d))//2*a
    r2 = ((-b)-math.sqrt(d))//2*a
    print("root 1 : ",r1)
    print("root 2 : ",r2)
else:
    print("No real roots")