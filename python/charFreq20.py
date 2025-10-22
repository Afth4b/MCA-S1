#character frequency in a string

def frequency(str):
    f = {}
    for i in str:
        if i in f:
            f[i] += 1
        else:
            f[i] = 1
    print(f)    

str = input("Enter a string : ")
frequency(str)