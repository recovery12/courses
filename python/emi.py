
l = float(input("Enter the loan amount: "))
i = float(input("Enter rate of interest: "))
n = float(input("Enter loan period(in months): "))

i = i/12

emi = (l*i)*(((1+i)**n)/(((1+i)**n)-1))
print(emi)
