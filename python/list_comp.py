a = []
a = input("Enter numbers : ").split()
b = []

for i in a:
    num = int(i)  
    if num > 0:
        b.append(num)

print(b)