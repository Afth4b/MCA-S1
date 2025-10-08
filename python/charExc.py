#create single string sfrom two strings by swapping the character position at 1

s1=input("Enter a string : ")
s2=input("Enter second string : ")
print("First string is : ",s1)
print("Second string is : ",s2)
print("String created by swapping charecter postion at 1 : ")
print(s1[0]+s2[1]+s1[2:]+s2[0]+s1[1]+s2[2:])
