#!/usr/bin/python3

from person import Person

"""
    Method Over-ridding (Single Inheritance)

    Class
"""

class Employee():
    def __init__(self, name, age=None, job=None):
        self.name = name
        self.age = age
        self.job = job
    def __str__(self):
        return "(Name, Age, Job)-> %s %d %s"%(self.name, self.age, self.job)
    def computeSalary(self, hours):
        self.sal = 0.25*hours
    def retire():
        if age > 60:
            print("Retirement is near")

class Engineer(Employee):
    def __init__(self, name, age):       # Customizing the constructor
        Employee.__init__(self, name, age, "Engineer")
    def computeSalary(self, days):
        self.sal = 2.5*days

class Company():
    def __init__(self, *args):
        self.members = list(args)
    def addEmployee(self, Employee):
        self.members.append(Employee)
    def display(self):
        for person in self.members:
            print(person)

if __name__ == '__main__':
    bob = Employee("Bob", 35)
    sue = Employee("Sue", 32)
    tom = Engineer("Tom", 34)

    tony = Person("Tony Stark", "Iron man", 23000000000)
    peter = Person("Peter Parker", "Spider-man")
    star = Person("Star Lord")

    company = [bob, sue, tom]

    for emp in company:
        emp.computeSalary(23)
        print(emp)

    # Gives a details of superclass
    print(Engineer.__bases__)

    # Gives name of module and class from instance
    print(tony.__class__)

    # Passing as arguments
    #comp = Company(bob, sue)
    #comp.addEmployee(tom)
    #comp.display()

    for key in tony.__dict__:
        print(key, "==>", getattr(tony, key))
