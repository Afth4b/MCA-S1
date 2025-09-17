from datetime import datetime

yr1 = datetime.now().year
yr2 = int(input("enter the ending year : "))
for i in range(yr1, yr2+1):
    if(i%4==0 and i%100!=0) or (i%400==0):
        print("%d is a leap year"%i)