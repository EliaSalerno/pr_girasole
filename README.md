![Logo](/arduino/doc_utili/img/logo2.png) IL SOLE E' DI CHI LO GUARDA
--------------------------------------
# Divari - Il pannello girasole
## Un pannello solare che insegue il sole

Sfruttando i sensori di luminosità manipolare la rotazione di un servomotore
per simulare la rotazione di un pannello solare. In realtà secondo il progetto 
da me ideato, il pannello gira grazie al servomotore...
Ebbene per iniziare a lavorare in modo adeguato su questo progetto vi propongo 
la visione di alcuni video. 

--------------------------------------
## Progetto diviso in più fasi:

 - [Fase1](#Fase1): studiamo il funzionamento di un partitore di tensione per la fotoresistenza;
 - [Fase2](#Fase2): studiamo il funzionamento di un servomotore per il movimento del pannello.

## Fase1
![foto resistenza](/arduino/doc_utili/img/fotoresistenza.png) COME UTILIZZARE LA FOTORESISTENZA?
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
Restitenza: 1k
Alimentazione: 5v sul capo libero della foto resistenza
Negativo: sul capo libero della resistenza
Per la lettura: pin analogico collegato all'incrocio tra fotoresistenza e resistenza.
```
## Fase2
![servo-motor](/arduino/doc_utili/img/servo_motor/servomotore.png) Cos'è un servomotore?
<br>Per spiegare il funzionamento del servomotore usiamo un grafico ad onda quadra ottenuto mediante l'uso di un oscilloscopio:
![sheet servo-motor](/arduino/doc_utili/img/servo_motor/quadra_servo.png)
L'onda PWM si caratterizza per il "duty cycle", ovvero il rapporto tra il tempo in cui l'onda resta a 1 nel tempo T, mentre T è il periodo. 
Il Servo è un motore in grado di effettuare rotazioni di massimo 270° ed è molto utilizzato nella robotica e nella modellistica.

Caratteristiche tecniche progetto:
```
Restitenza: non servono resistenze
Alimentazione: 5v sul filo rosso
Negativo: sul filo nero
Per la lettura: filo bianco su un pwm (pulse with modulation).
```
