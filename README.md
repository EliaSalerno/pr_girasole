![Logo](/arduino/doc_utili/img/Simbolo%20progetto%20.png) 
# IL SOLE E' DI CHI LO CERCA
--------------------------------------
# Divari - Il pannello girasole
## Un pannello solare che insegue il sole

Quando durante il giorno il sole cambia direzione, per effetto del moto terrestre intorno ad esso, solitamente il pannello resta fisso e questo ha una 
conseguenza sul suo rendimento.
In questa situazione abbiamo un quantitativo ridotto di raggi solari che colpiscono la superficie del pannello. 

Per ovviare a questo problema, la superficie del pannello deve sempre avere il massimo dell'esposizione, e per raggiungere tale obiettivo 
dobbiamo progettare un sistema che permetta al pannello di roteare con un movimento simile al girasole.

Sfruttando i sensori di luminosità manipolare la rotazione di un servomotore per simulare la rotazione di un pannello solare. In realtà secondo il progetto 
da me ideato, il pannello gira grazie al servomotore...
Ebbene per iniziare a lavorare in modo adeguato su questo progetto vi propongo la visione di alcuni video. 

[![Watch the video](/arduino/doc_utili/img/video.jpg)](https://www.youtube.com/watch?v=m9kkf-XXQVU)
[![Watch the video](/arduino/doc_utili/img/video.jpg)](https://www.youtube.com/watch?v=pDeTyFnBG2M)

--------------------------------------
## Progetto diviso in più fasi:

 - [Fase1](#Fase1): studiamo il funzionamento di un partitore di tensione per la fotoresistenza;
 - [Fase2](#Fase2): studiamo il funzionamento di un servomotore per il movimento del pannello.

## Fase 1 - COME UTILIZZARE LA FOTORESISTENZA?

![Sheet partitore di tensione](/arduino/doc_utili/img/schema_partitore_foto.png)

<br> Si tratta di un componente elettronico la cui resistenza è inversamente proporzionale alla 
quantità di luce che lo colpisce. 
Il fuzionamento della fotoresistenza si basa sull'effetto conduttivo dei materiali semiconduttori: 
quando una radiazione luminosa colpisce il semiconduttore, i fotoni possono rompere il legame covalente
(elettroce-lacuna) generando una coppia elettrone libero-lacuna, contribuendo così ad aumentare 
i portatori di carica e di conseguenza la conducibilità del materiale (quindi la resistenza del materiale 
diminuisce).

Caratteristiche tecniche progetto:
```
Resistenza: 1k
Alimentazione: 5v sul capo libero della foto resistenza
Negativo: sul capo libero della resistenza
Per la lettura: pin analogico collegato all'incrocio tra fotoresistenza e resistenza.
```
## Fase 2 - Cos'è un servomotore?
![servo-motor](/arduino/doc_utili/img/servo_motor/servomotore.png) 
<br>Per spiegare il funzionamento del servomotore usiamo un grafico ad onda quadra ottenuto mediante l'uso di un oscilloscopio:
![sheet servo-motor](/arduino/doc_utili/img/servo_motor/quadra_servo.png)
L'onda PWM si caratterizza per il "duty cycle", ovvero il rapporto tra il tempo in cui l'onda resta a 1 nel tempo T, mentre T è il periodo. 
Il Servo è un motore in grado di effettuare rotazioni di massimo 270° ed è molto utilizzato nella robotica e nella modellistica.

Caratteristiche tecniche progetto:
```
Resistenza: non servono resistenze
Alimentazione: 5v sul filo rosso
Negativo: sul filo nero
Per la lettura: filo bianco su un pwm (pulse with modulation).
```
