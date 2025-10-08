
s=input("Enter a string :")

if len(s)<2:
    print("String length should be at least 2")
    exit()
else:
    print("String before exchange : ",s)
    print("String after exchanging last and first characters :",s[-1]+s[1:-1]+s[0])