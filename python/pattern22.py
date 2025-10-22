#Construct the pattern using nested loop

def pattern(num):
    for i in range(num):
        for j in range(num - i - 1):
            print(" ", end="")  
        print("*" * (2 * i + 1))  

# def triangle(num):
#     for i in range(num):
#         print("*"*(i+1))



num = int(input("Enter number of lines : "))
pattern(num)
