#base class , constructor innovation , method overriding

class publisher :
    def __init__(self,name):
        self.name=name

    def display(self):
        print(f"publisher : {self.name}")

class book(publisher) :
    def __init__(self,name,title,author):
        super().__init__(name)
        self.title=title
        self.author=author

    def display(self):
        print(f"{self.title} written by {self.author}")
        super().display()

class python(book):
    def __init__(self,name,title,author,price,num_of_pages):
        super().__init__(name,title,author)
        self.price=price
        self.num_of_pages=num_of_pages

    def display(self):
        print(f"Price :{self.price} Number of pages :{self.num_of_pages}")
        super().display()

b=python(name="CET",title="Python Programming",author="Hafis",price="500$",num_of_pages=1000)
b.display()