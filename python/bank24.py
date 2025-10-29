#Bank account (constructor and methods)

class account:
    
    def __init__(self,accno,name,type,bal):
        self.accno=accno
        self.name=name
        self.type=type
        self.bal=bal

    def deposit(self,amount):
        if amount>0:
            bal+=amount
            print(f"Amount {amount} added succesfully")
            print(f"Account no :{self.accno} Name :{self.name} Type :{self.type} Balance :{self.bal}")
        else:
            print("Invalid amount")

    def withdraw(self,amount):
        if amount>bal:
            print("Insufficient Balance")
            print(f"Account no :{self.accno} Name :{self.name} Type :{self.type} Balance :{self.bal}")
        else:
            bal-=amount
            print(f"Amount {amount} withdrawal successfull")
            print(f"Account no :{self.accno} Name :{self.name} Type :{self.type} Balance :{self.bal}")

    def display(self):
        print(f"Account no :{self.accno} Name :{self.name} Type :{self.type} Balance :{self.bal}")

accno=int(input("Enter Account Number :"))
name=input("Enter Name :")
type=input("Enter Account Type :")


member=account(accno,name,type,0)

while true:
    member.display()
    t=int(input("Enter 1 to DEPOSIT , 2 to WITHDRAW "))