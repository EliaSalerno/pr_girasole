import serial
import time
import serial.tools.list_ports
from datetime import datetime

#MANCA IL SALVATAGGIO IN JSON

# lsdevice ritorna la lista delle porte occupate

def lsdevice():
    ports=serial.tools.list_ports.comports()
    listPort=[]
    for p in sorted(ports):
       listPort.append(p)
    if len(listPort)>0:
        return listPort

# sfind effettua la connessione con dispositivi che inviano/ricevono ('R' per
# ricezione da arduino, 'T' per trasmissione)

def sfind(s):
    listPort=lsdevice()
    for i in range(len(listPort)):
        arduino=serial.Serial(listPort[i].name,115200)
        for b in range(10):
            if arduino.in_waiting>0 and s=='R':
                return arduino
            else:
                time.sleep(0.3)
        if s=='T':
            return arduino

# effettuato il collegamento in base alle proprie esigenze nel codice seguente
# si preleva il pacchetto da arduino e si stampa in output la data, l'ora e
# la temperatura rilevata

arduino=sfind('R')
print(arduino)
while arduino.in_waiting > 0:
    if arduino.in_waiting > 3:
        buffer=arduino.read(7)
        temp=buffer.decode() # .decode per convertire da byte in stringa
        print(datetime.now(),": ",temp)
        time.sleep(1)
