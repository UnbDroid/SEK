import os
import sys

system = os.system

try:
	nome = sys.argv[1]

	print("Comandos efetuados:")
	print("sudo addgroup legonxt")
	#system("sudo addgroup legonxt")
	print("sudo adduser " + nome + " legonxt")
	#system("sudo adduser CarlosAdir legonxt")

	print("Escrevemos entao no arquivo 45-legonxt.rules.")
	arq = open("45-legonxt.rules", "w")
	arq.write("# NXT brick\n")
	arq.write("SUBSYSTEM==\"usb\", ATTRS{idVendor}==\"0694\", ATTRS{idProduct}==\"0002\", SYMLINK+=\"legonxt-%k\", GROUP=\"legonxt\", MODE=\"0666\"\n\n")
	arq.write("# NXT brick in firmware update mode (Atmel SAM-BA mode)\n")
	arq.write("SUBSYSTEM==\"usb\", ATTRS{idVendor}==\"03eb\", ATTRS{idProduct}==\"6124\", SYMLINK+=\"legonxt-%k\", GROUP=\"legonxt\", MODE=\"0666\"")
	arq.close()

	print("sudo cp 45-legonxt.rules /etc/udev/rules.d")
	#system("sudo cp 45-legonxt.rules /etc/udev/rules.d")
	#system("echo off");
	print("sudo apt-get install nbc");
	#system("sudo apt-get install nbc");

except:
	print('Voce nao colocou o nome da sua conta. Para ver isso, digite sem as aspas: "users"')