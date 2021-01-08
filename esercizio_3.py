def SerieDiFibonacci(num1, num2, cont1, cont2):
    print(num1)
    num3 = num1 +num2           
    num1 = num2
    num2 = num3
    if(cont1<cont2):            #condizione per evitare un loop
        cont1 = cont1+1         #si incrementa il contatore
        SerieDiFibonacci(num1,num2,cont1,cont2)   #richiamo ricorsivo della funzione  

def main():
    num = int(input("inserire un numero: "))
    while(num<=0):                  #verifica dell'input
        num = int(input("e' stato inserito un numero negativo, reinserire il numero: "))
    SerieDiFibonacci(1,1,0,num-1)   #si passa num-1 se no viene stampato un numero in più

if __name__ == "__main__":
    main()