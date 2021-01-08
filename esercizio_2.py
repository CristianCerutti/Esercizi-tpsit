from random import randint
indirizzoMac = ""       #indirizzo MAC
cont = 0
alfabeto = {1:"A", 2:"B", 3:"C", 4:"D", 5:"E", 6:"F", 7:"0", 8:"1", 9:"2", 10:"3", 11:"4", 12:"6", 13:"6", 14:"7", 15:"8", 16:"9"}
for _ in range(0,6):
    carattere = randint(0,16)
    indirizzoMac = indirizzoMac + alfabeto[carattere] #si  crea il primo carattere dell'n gruppo
    carattere = randint(0,16)
    indirizzoMac = indirizzoMac + alfabeto[carattere] #si crea il secondo carattere dell'n gruppo
    cont = cont+1                                     #se cont vale 6 non si mette i : alla fine
    if (cont != 6):                                   #i : vanno messi tra due gruppi, ma non alla fine dell'indirizzo
        indirizzoMac = indirizzoMac + ':'
print(f"l'indirizzo MAC generato e': {indirizzoMac}")