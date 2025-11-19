# Read each row from a given csv file and print it as a list of strings
import csv
with open('data.csv','r') as file:
    reader = csv.reader(file)

    for row in reader:
        print(row)