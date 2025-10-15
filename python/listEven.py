# From a list, create a list removing all even numbers

n = int(input("Enter limit for list : "))
numlist = []

for i in range(1,n+1):
    num = int(input(f"Enter number {i} : "))
    numlist.append(num)

oddlist = [num for num in numlist if num%2 != 0]
print(f"list : {numlist}")
print(f"After removing even numbers : {oddlist}")

