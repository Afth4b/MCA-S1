#sum of first 100 even numbers

print("First 100 even numbers are : ")
sum = 0
for i in range(1,101):
    print(i*2)
    sum = sum + (i*2)
print("Sum of first 100 even numbers is "+str(sum))