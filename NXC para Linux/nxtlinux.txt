For ubuntu and other recent linux distributions here is a new procedure that I recommend using to configure your Linux box for use with the NXT:

1. Add a legonxt group.  From a terminal prompt type

sudo addgroup legonxt

2. Add your account to the legonxt group.  From a terminal prompt type

sudo adduser YourUserName legonxt

3. Create a file called 45-legonxt.rules using your favorite text editor.  Its contents should look like this:

# NXT brick 
SUBSYSTEM=="usb", ATTRS{idVendor}=="0694", ATTRS{idProduct}=="0002", SYMLINK+="legonxt-%k", GROUP="legonxt", MODE="0666"

# NXT brick in firmware update mode (Atmel SAM-BA mode)
SUBSYSTEM=="usb", ATTRS{idVendor}=="03eb", ATTRS{idProduct}=="6124", SYMLINK+="legonxt-%k", GROUP="legonxt", MODE="0666"

4. Copy this file to /etc/udev/rules.d.  From a terminal prompt type

sudo cp 45-legonxt.rules /etc/udev/rules.d

5. That should be all you need to do (aside from reboot) to make sure that your NXT will always be accessible via USB for any user who is a member of the legonxt group.  Whenever you plug in your NXT it should show up in /dev as

/dev/legonxt-x-y

where x and y depend on which USB port you plug the NXT into.  On my laptop which has 4 USB ports I get 1-1, 1-2, 2-1, and 2-2 depending on which port I plug into.  There will be other entries such as /dev/legonxt-usbdevx.y where y increments but you should be able to use the above device alias without any problems.  

6. That should take care of USB support.  Now let's work on Bluetooth support.

7. The procedure below is described by Tony Buser here: http://www.juju.org/articles/2006/10/22/bluetooth-serial-port-to-nxt-in-linux

8. You may need to install bluetooth support using apt-get.  If hcitool doesn't work then from a terminal prompt type

sudo apt-get install bluetooth

9. Get your NXT's bluetooth address using hcitool.  From a terminal prompt type

sudo hcitool scan

10. Edit a file called /etc/bluetooth/rfcomm.conf using your favorite text editor.  Add an entry for your NXT that looks like this:

rfcomm0 {
	# Automatically bind the device at startup
	bind yes;
	# Bluetooth address of the device
	device 00:16:53:FF:01:56;
	# RFCOMM channel for the connection
	channel	1;
	# Description of the connection
	comment "JCH2";
}

Make sure you enter your NXT's bluetooth address as shown by the hcitool scan.  If you have more than one NXT you can create additional entries in this file with incremental rfcomm names (e.g., rfcomm1, rfcomm2, etc...).

11. Now restart your bluetooth services.  From a terminal prompt type

sudo /etc/init.d/bluetooth restart

You may have to use /etc/init.d/bluez-utils restart but on my ubuntu system it uses bluetooth instead.

12. Make sure rfcomm is working properly.  From a terminal prompt type

rfcomm

You should see

rfcomm0: 00:16:53:FF:01:56 channel 1 clean

with your NXT's bluetooth address instead, of course.

13. Make sure the device shows up in /dev and that you have permission to read/write to it.  On my system it shows it associated with the dialout group and my user account is in the dialout group as shown below.  Make sure yours looks similar.

john@john-laptop:~/Desktop$ ls -l /dev/rfcomm0
crw-rw---- 1 root dialout 216, 0 2008-04-02 20:52 /dev/rfcomm0

john@john-laptop:~/Desktop$ groups
users adm dialout cdrom floppy audio dip video plugdev scanner lpadmin admin netdev powerdev legonxt

14. As Tony mentions, the first time you try to connect to /dev/rfcomm0 you should be prompted on your PC and your NXT to enter or accept the PIN number.  Use 1234.  Once that has been exchanged once you should not have to do that again.

In other utilities you should be able to use /dev/legonxt-x-y or /dev/rfcomm0 to communicate with your NXT by USB or Bluetooth respectively.

The NBC compiler has built-in usb and bluetooth support for Linux.  You can just type

nbc -d -S=usb program.nxc

and the compiler will compile the program and download it to your NXT.  The NeXTTool utility is also available with lots of NXT communication options from a terminal prompt.  I also have an NeXT Tools graphical utility working for Linux too.


