# Write a python dictionary to a CSV file, read the CSV and display its content
import csv

mydict = [
    {"first": "Aafthab", "last": "K I"},
    {"first": "Ajmal", "last": "K P"}, 
    {"first": "Hafis", "last": "Mohammed"}
]

with open("new.csv", "w") as file:
    writer = csv.DictWriter(file, fieldnames=["first", "last"])
    writer.writeheader()
    writer.writerows(mydict)
    
    
# Read the file
with open("new.csv", "r") as csvfile:
    file = csv.DictReader(csvfile)
    for row in file:
        print(row)
    