#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *p = fopen("45-legonxt.rules", "w");
	system("sudo addgroup legonxt");
	system("sudo adduser CarlosAdir legonxt");
	fprintf(p, "# NXT brick\n");
	fprintf(p, "SUBSYSTEM==\"usb\", ATTRS{idVendor}==\"0694\", ATTRS{idProduct}==\"0002\", SYMLINK+=\"legonxt-%%k\", GROUP=\"legonxt\", MODE=\"0666\"\n\n");
	fprintf(p, "# NXT brick in firmware update mode (Atmel SAM-BA mode)\n");
	fprintf(p, "SUBSYSTEM==\"usb\", ATTRS{idVendor}==\"03eb\", ATTRS{idProduct}==\"6124\", SYMLINK+=\"legonxt-%%k\", GROUP=\"legonxt\", MODE=\"0666\"");
	system("sudo cp 45-legonxt.rules /etc/udev/rules.d");
	system("echo off");
	system("sudo apt-get install nbc");
	return 0;
}