n = int(input("Enter no of key value pairs in first dictionary : "))
dict1 = {}
for i in range(1,n+1):
    key = input("Enter key : ")
    value = input("Enter value : ")
    dict1[key] = value
print(dict1)

n1 = int(input("Enter no of key value pairs in second dictionary : "))
dict2 = {}
for i in range(1,n1+1):
    key = input("Enter key : ")
    value = input("Enter value : ")
    dict2[key] = value

print(dict2)

dict1.update(dict2)
print("MERGED DICTIONARY IS :",dict1)

