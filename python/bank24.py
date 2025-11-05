#Bank account (constructor and methods)

class account:
    
    def __init__(self,accno,name,type,bal):
        self.accno=accno
        self.name=name
        self.type=type
        self.bal=bal

    def deposit(self,amount):
        if amount>0:
            self.bal+=amount
            print(f"Amount {amount} added succesfully")
        else:
            print("Invalid amount")

    def withdraw(self,amount):
        if amount>self.bal:
            print("Insufficient Balance")
        else:
            self.bal-=amount
            print(f"Amount {amount} withdrawal successfull")

    def display(self):
        print(f"Account no :{self.accno} Name :{self.name} Type :{self.type} Balance :{self.bal}")

accno=int(input("Enter Account Number :"))
name=input("Enter Name :")
type=input("Enter Account Type :")


member=account(accno,name,type,0)

while True:
    t=int(input("Enter 1 to DEPOSIT , 2 to WITHDRAW , 3 to BALANCE ENQUIRY , 4 to EXIT:"))
    if t==1:
        member.deposit(int(input("Enter the amount to deposit :")))
    elif t==2:
        member.withdraw(int(input("Enter the amount to withdraw :")))
    elif t==3:
        member.display()
    elif t==4:
        exit()
    else :
        print("Invalid choice!!!!")