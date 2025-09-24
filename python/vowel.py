word=input("Enter a word:")
a=[]
for i in range(len(word)):
    if word[i] in "aeiouAEIOU":
        a.append(word[i])
if len(a) > 0:
    print(f"vowels in the list are : {a}")
else:
    print("No vowels found")

