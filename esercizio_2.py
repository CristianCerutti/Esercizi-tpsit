from random import randint
indirizzoMac = ""       #indirizzo MAC
cont = 0
alfabeto = {1:"A", 2:"B", 3:"C", 4:"D", 5:"E", 6:"F", 7:"G", 8:"H", 9:"I", 10:"J", 11:"K", 12:"L", 13:"M", 14:"N", 15:"O", 16:"P", 17:"Q", 18:"R", 19:"S", 20:"T", 21:"U", 22:"V", 23:"W", 24:"X", 25:"Y", 26:"Z", 27:"0", 28:"1", 29:"2", 30:"3", 31:"4", 32:"5", 33:"6", 34:"7", 35:"8", 36:"9"}
for _ in range(0,6):
    carattere = randint(0,36)
    indirizzoMac = indirizzoMac + alfabeto[carattere] #si  crea il primo carattere dell'n gruppo
    carattere = randint(0,36)
    indirizzoMac = indirizzoMac + alfabeto[carattere] #si crea il secondo carattere dell'n gruppo
    cont = cont+1                                     #se cont vale 6 non si mette i : alla fine
    if (cont != 6):                                   #i : vanno messi tra due gruppi, ma non alla fine dell'indirizzo
        indirizzoMac = indirizzoMac + ':'
print(f"l'indirizzo MAC generato e': {indirizzoMac}")