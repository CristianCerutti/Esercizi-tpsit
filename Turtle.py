from turtle import *

nlati = int(input("inserire il numero dei lati: \n"))
begin_fill()
cont = nlati
while(cont > 0):
    forward(40)
    left(360/nlati)
    cont = cont-1
end_fill()
done()