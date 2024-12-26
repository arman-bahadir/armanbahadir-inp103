alter=int(input("Alter:"))
note=(input("Abschlussnote:"))
if alter>=20 and alter<=50 and note>=80 and note<=100:
  print("Einstellen.")
else:
  print("Ablehnen.")