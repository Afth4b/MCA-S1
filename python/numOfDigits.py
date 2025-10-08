#find the number of digits
num = int(input("Enter a number : "))
x = num
count = 0
while x !=0:
    x //=10
    count+=1
print(f"Number of digits in {num} is {count}")
