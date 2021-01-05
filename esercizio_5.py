import turtle
import time
import random

delay = 0.1
score = 0
high_score = 0
win = turtle.Screen()
win.title("Snake")                      #nome della finestra
win.bgcolor('green')                    #colore della finestra
win.setup(width=600, height=600)        #grendezza della finestra
win.tracer(0)

head = turtle.Turtle()
head.speed(0)               #velocità della testa
head.shape("square")        #forma della testa
head.color("black")         #colore della testa
head.penup()                #non fa disegnare la turtle
head.goto(0,0)              #si mette la testa al centro della finestra
head.direction = "stop"

food= turtle.Turtle()
food.speed(0)                   #imposta la velocità nel disegnare il cibo, noi lo vogliamo istantaneo quindi 0
food.shape("circle")            #imposta la forma del cibo
food.color("red")               #imposta il colore del cibo
food.penup()                    #pen up non fa disegnare la turle
food.goto(0,100)                #il il cibo va alla coordinate indicate, ovvero subito davanti allo snake

segments = []               #la lista creata sarà la coda dello snake
sc = turtle.Turtle()
sc.speed(0)
sc.shape("square")          #imposta la forma della turtle
sc.color("black")           #si imposta il colore
sc.penup()
sc.hideturtle()             #hide fa diventare la turtle invisibile
sc.goto(0,260)              #impostiamo le coordinate della scritta del punteggio
sc.write("punteggio: 0  miglior punteggio: 0", align = "center", font=("ds-digital", 24, "normal"))     #write scrive un testo alla posizione in cui si trova la turtle


def go_up():
    if head.direction != "down":           #per andare in alto
        head.direction = "up"               
def go_down():
    if head.direction != "up":             #per andare in basso
        head.direction = "down"            
def go_left():
    if head.direction != "right":          #per andare a sinistra
        head.direction = "left"
def go_right():                                 
    if head.direction != "left":           #per andare a destra
        head.direction = "right"
def move():
    if head.direction == "up":
        y = head.ycor()                    #ycor ritorna alle coordinate y della turtle, stessa cosa xcor
        head.sety(y+20)                    #si aumenta la posizione delle y della turtle di 20, stessa cosa per gli altri moviemnti
    if head.direction == "down":
        y = head.ycor()
        head.sety(y-20)
    if head.direction == "left":
        x = head.xcor()
        head.setx(x-20)
    if head.direction == "right":
        x = head.xcor()
        head.setx(x+20)

win.listen()                                        #mette la finestra in ascolto
win.onkeypress(go_up, "w")                          #se si preme w va su
win.onkeypress(go_down, "s")                        #se si mette s va sotto
win.onkeypress(go_left, "a")                        #se si preme a va a sinistra
win.onkeypress(go_right, "d")                       #se si preme d va adestra


while True:                                         #per farlo durare all'infinito
    win.update()

    if head.xcor()>290 or head.xcor()<-290 or head.ycor()>290 or head.ycor()<-290:
        time.sleep(1)                   #si aspetta 1 secondo                                               
        head.goto(0,0)                  #go to, muove la turtle nelle cordinate indicate, prim oargomento cordX secondo cordY
        head.direction = "stop"         #ferma la testa

        for segment in segments:                #per resettare la coda dello snake
            segment.goto(1000,1000) 
        
        segments.clear()
        score = 0       #resetta il punteggio
        delay = 0.1     #ritardo nel resettare

        sc.clear()                  #cancella il disegno della turtle
        sc.write("punteggio: {}  miglior punteggio: {}".format(score, high_score), align="center", font=("ds-digital", 24, "normal"))       #scrive il punteggio

    if head.distance(food) <20:                 #collisioni con il cibo

        x = random.randint(-290,290)            #randint, importato da random, da un numero intero casuale
        y = random.randint(-290,290)            #genera un x e y a caso
        food.goto(x,y)                          #il cibo viene spawnato alle coordinate casuali generate prima
        new_segment = turtle.Turtle()           #aggiunge un segmento allo snake
        new_segment.speed(0)
        new_segment.shape("square")
        new_segment.color("black")
        new_segment.penup()
        segments.append(new_segment)   #append aggiunge un elemento in fondo alla lista
        delay -= 0.001                 #diminuisce il ritardo
        score += 5                     #incrementa il punteggio
        if score > high_score:
            high_score = score         #per settare il punteggio più alto
        sc.clear()
        sc.write("punteggio: {}  miglior punteggio: {}".format(score,high_score), align="center", font=("ds-digital", 24, "normal"))        #viene aggiornato a schermo il punteggio

    for indice in range(len(segments)-1,0,-1):
        x = segments[indice-1].xcor()
        y = segments[indice-1].ycor()           #serve a far si che i segmenti seguano la testa
        segments[indice].goto(x,y)

    if len(segments)>0:
        x = head.xcor()                         #si imposta la testa
        y = head.ycor()
        segments[0].goto(x,y)
    move()

    for segment in segments:
        if segment.distance(head)<20:           #collisione con lo snake stesso
            time.sleep(1)
            head.goto(0,0)
            head.direction = "stop"

            for segment in segments:
                segment.goto(1000,1000)         #si fa sparire la coda
            segments.clear()
            score = 0                           #sii resetta il punteggio
            delay = 0.1
    
            sc.clear()                      
            sc.write("punteggio: {}  miglior punteggio: {}".format(score,high_score), align="center", font=("ds-digital", 24, "normal"))   #aggiorna il punteggio
    time.sleep(delay)
win.mainloop()   