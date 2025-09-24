word=input("Enter a word:")
a=[]
for i in range(len(word)):
    if word[i] in "aeiouAEIOU":
        a.append(word[i])
print(a)

