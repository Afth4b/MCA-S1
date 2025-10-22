#Fibonacci series of N terms

def fibonacci(num):
    a,b = 0,1
    if num<=0:
        print("Enter positive number...!!")
    elif num == 1:
        print("Fibonacci series upto ",num," : ")
        print(a)
    else:
        print("Fibonacci series upto ",num," : ")
        for i in range(num):
            print(a,end=" ")
            a,b=b,a+b

num =int(input("Enter the number of terms : "))
fibonacci(num)