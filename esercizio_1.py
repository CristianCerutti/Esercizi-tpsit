from random import randint
import random
import string
tipo = int(input("inserire il tipo di password: "))
password = ""
while(tipo != 8 and tipo != 20):
    tipo = int(input("è stato inserito un numero non valido, riprovare: "))
alfabetos = {1:"a", 2:"b", 3:"c", 4:"d", 5:"e", 6:"f", 7:"g", 8:"h", 9:"i", 10:"j", 11:"k", 12:"l", 13:"m", 14:"n", 15:"o", 16:"p", 17:"q", 18:"r", 19:"s", 20:"t", 21:"u", 22:"v", 23:"w", 24:"x", 25:"y", 26:"z", 27:"0", 28:"1", 29:"2", 30:"3", 31:"4", 32:"5", 33:"6", 34:"7", 35:"8", 36:"9", 37:"A", 38:"B", 39:"C", 40:"D", 41:"E", 42:"F", 43:"G", 44:"H", 45:"I", 46:"J", 47:"K", 48:"L", 49:"M", 50:"N", 51:"O", 52:"P", 53:"Q", 54:"R", 55:"S", 56:"T", 57:"U", 58:"V", 59:"w", 60:"X", 61:"Y", 62:"Z"}
if(tipo == 8):
    for _ in range(tipo):
        num = randint(0, 62)
        password = password + alfabetos[num]
else:
    for _ in range(tipo):
        lett = random.choice(string.ascii_letters)
        password = password + lett
print(f"la password generata e': {password}")
