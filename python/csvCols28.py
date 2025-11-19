# Read specific columns of a given csv file print their contents
import csv


col1 = int(input("Enter the first column number : "))
col2 = int(input("Enter the second column number : "))


with open('data.csv','r') as file:
    reader = csv.reader(file)

    for row in reader:
        print(row[col1], row[col2])