def cripta(stringa):
    stringa2 = ""
    for carattere in stringa:
        if carattere in alfabeto1:
            stringa2 += alfabeto1[carattere]
        else:
            stringa2 += carattere
    return stringa2

def decripta(stringa): 
    stringa2 = ""
    for carattere in stringa:                    #per ogni carattere nella stringa
        if carattere in alfabeto2:               #se il carattere è presente nell'alfabeto
            stringa2 += alfabeto2[carattere]     #stringa sarà la string a+ il carattere dell'alfabeto alla posizione carattere
        else:
            stringa2 += carattere                #se no sarà solamente il carattere
    return stringa2

alfabeto1 = {'a': 'l', 'b': 'm', 'c': 'n', 'd': 'o', 'e': 'p', 'f': 'q', 'g': 'r', 'h': 's', 'i': 't', 'j': 'u', 'k': 'v', 'l': 'w', 'm': 'x', 'n': 'y', 'o': 'z', 'p': 'a', 'q': 'b', 'r': 'c', 's': 'd', 't': 'e', 'u': 'f', 'v': 'g', 'w': 'h', 'x': 'i', 'y': 'j', 'z': 'k', 'A': 'L', 'B': 'M', 'C': 'N', 'D': 'O', 'E': 'P', 'F': 'Q', 'G': 'R', 'H': 'S', 'I': 'T', 'J': 'U', 'K': 'V', 'L': 'W', 'M': 'X', 'N': 'Y', 'O': 'Z', 'P': 'A', 'Q': 'B', 'R': 'C', 'S': 'D', 'T': 'E', 'U': 'F', 'V': 'G', 'W': 'H', 'X': 'I', 'Y': 'J', 'Z': 'K'}
alfabeto2 = {'l': 'a', 'm': 'b', 'n': 'c', 'o': 'd', 'p': 'e', 'q': 'f', 'r': 'g', 's': 'h', 't': 'i', 'u': 'j', 'v': 'k', 'w': 'l', 'x': 'm', 'y': 'n', 'z': 'o', 'a': 'p', 'b': 'q', 'c': 'r', 'd': 's', 'e': 't', 'f': 'u', 'g': 'v', 'h': 'w', 'i': 'x', 'j': 'y', 'k': 'z', 'L': 'A', 'M': 'B', 'N': 'C', 'O': 'D', 'P': 'E', 'Q': 'F', 'R': 'G', 'S': 'H', 'T': 'I', 'U': 'J', 'V': 'K', 'W': 'L', 'X': 'M', 'Y': 'N', 'Z': 'O', 'A': 'P', 'B': 'Q', 'C': 'R', 'D': 'S', 'E': 'T', 'F': 'U', 'G': 'V', 'H': 'W', 'I': 'X', 'J': 'Y', 'K': 'Z'}
stringaIn = str(input("inserire una stringa: "))
scelta = input("inserire c per criptarla, o d per decriptarla: ")
while (scelta != 'c' and scelta != 'd'):
    scelta = input("carattere inserirto errato, inserire c per criptarla, o d per decriptarla: ")
if (scelta == 'c'):
    print(f"la stringa {stringaIn} criptata diventa: {cripta(stringaIn)}")
else:
    print(f"la stringa {stringaIn} decriptata diventa: {decripta(stringaIn)}")