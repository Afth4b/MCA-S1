n=int(input("Enter the number:"));

if n<=0:
    print("Invalid Input..!!")
else:
    for i in range(1,n+1):
        print(f"Square of {i} is {i**2}")