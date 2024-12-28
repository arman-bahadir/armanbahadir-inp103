def einstellenprogramme():
    try:
        abschlussnote=float(input("Abschlussnote: "))
        if abschlussnote<0 or abschlussnote>100:
            print("Ungültig.")
            return
        
        if abschlussnote>=90:
            print("Einstellen.")
            return
          
        erfahrung=float(input("Programmiererfahrung: "))
        if erfahrung<0:
            print("Ungultig.")
            return
            
        if abschlussnote>=90:
            print("Einstellen.")
        elif abschlussnote>=70 and erfahrung>=5:
            print("Einstellen.")
        elif abschlussnote>=70 and erfahrung>=4:
            print("zum Gespräch einladen.")
        else:
            print("Erfüllt nicht die Kriterien.")
            
    except ValueError:
        print("Ungültig.")

einstellenprogramme()