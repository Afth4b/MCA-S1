# sort dictionary - ascending and descending

n = int(input("Enter no of key value pairs : "))
dict = {}
for i in range(1,n+1):
    key = input("Enter key : ")
    value = input("Enter value : ")
    dict[key] = value

print(dict)

list1 = list(dict.items())
for i in range(len(list1)-1):
    for j in range(0,len(list1)-i-1):
        if list1[j][1]>list1[j+1][1]:
            list1[j],list1[j+1]=list1[j+1],list1[j]
sorted = list1

print(list1)
