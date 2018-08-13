import bluetooth
import os
import sys
import spidev
import time

spi=spidev.SpiDev()
spi.open(0,0)
spi.max_speed_hz=3900000

adresaBluetoothMAC = "20:16:10:20:52:66" #adresa mac bluetooth arduino
portDeConectareRFCOMM = 1
socket = bluetooth.BluetoothSocket (bluetooth.RFCOMM)
socket.connect((adresaBluetoothMAC, portDeConectareRFCOMM))

def decodificareDate(frameDirectie):
    
    
    frameBinar = [ bin(ord(byte))[2:].zfill(8) for byte in frameDirectie ] #convertire frame in baza 2
    directieASCII = ""
    print(frameDirectie)
    #print(frameBinar)

    if len(frameBinar) == 5:
	detectieErori = frameBinar[2]
	directieBinar=frameBinar[1]
        if (directieBinar.count('1')+int(detectieErori[7]))%2 == 0:
            directieASCII=frameDirectie[1]
        else:
            print("Datele sunt incorecte! Verificati bitii de paritate!")
        #print(directieASCII)
        if directieASCII in "NSEV" :
	    return directieASCII

def primesteDeLaArduinoBT():
    
    datePrimiteBT=""
    directie = ""

    while 1:
        try:
            datePrimiteBT+=socket.recv(1024)
            datePrimiteBTend=datePrimiteBT.find('\n') #find returneaza -1 daca nu gaseste
            if datePrimiteBTend != -1:  #daca gaseste \n continua programul 
                frameDirectie = datePrimiteBT[:datePrimiteBTend]
                print(frameDirectie)
		#print(date)
		#print(frameBinar)
		if decodificareDate(frameDirectie):
			directie = decodificareDate(frameDirectie)
			print "Directia primita este: " , directie
			resp=spi.xfer2([hex(ord(directie))])
                        #print chr(resp[0])
                        #time.sleep(0.5)
			trimiteCatreArduinoBT(resp)
                datePrimiteBT = datePrimiteBT[datePrimiteBTend+1:]
	    
	    
        except KeyboardInterrupt:
            break
    
    socket.close()

def trimiteCatreArduinoBT(data):
    socket.send(data)
    

primesteDeLaArduinoBT()
