while True:
  s1=int(input("Zahl 1:"))
  s2=int(input("Zahl 2:"))
  if s1<s2:
    for i in range(s1,s2+1):
      print(i)
  elif s1>s2:
    for i in range(s2,s1+1):
      print(i)
  else:
    print("ungültig")