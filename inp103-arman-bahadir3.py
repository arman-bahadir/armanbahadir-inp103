kontostand=1000
print("Ihr Kontostand:", kontostand, "EURO")
transaktion=input("einzahlung oder auszahlung? ")
betrag=int(input("Wie viel EURO? "))

if betrag<=0:
    print("ungültiger Betrag.")
else:
    if transaktion=="einzahlung":
        kontostand=kontostand+betrag
        print("Einzahlung erfolgreich!")
    elif transaktion=="auszahlung":
        if betrag>kontostand:
            print("Nicht genügend Guthaben!")
        else:
            kontostand=kontostand - betrag
            print("Auszahlung erfolgreich!")
    else:
        print("Ungültige Transaktion")
    
    if kontostand<0:
        print("Negativer Kontostand ist nicht möglich!")
    else:
        print("Ihr aktueller Kontostand:", kontostand, "EURO")