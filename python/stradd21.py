# add 'ing' or 'ly'

def add(str) :
    str = str.lower()
    if str[-1]=='g' and str[-2]=='n' and str[-3]=='i' :
        str += 'ly'
    else:
        str += 'ing'
    print(str)

str = input("Enter a string :")
add(str)

