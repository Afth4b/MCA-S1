# Copy odd lines of one file to another
f = open("file1.txt","r")
s = open("file2.txt","w")

lines = f.readlines()

s.write("File 2.txt : \n")
for i in range(0,(len(lines))):
    if i%2==0:
        
        s.write(lines[i])

f.close()
s.close()