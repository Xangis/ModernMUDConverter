Basternae 2 / Magma to ModernMUD Zone Converter
-----------------------------------------------

This program converts Basternae 2 and Magma MUD format zones to the ModernMUD
XML zone format.

It is configured much like an Envy-based MUD in that you edit the AREA.LST file
in the /area directory to add the zones you want to convert and then run the
executable.  The zones, typically with a ".are" file format, will be loaded
and then written out to the ".xml" file format.

There is an executable, ModernMUDConverter.exe included for Windows. For Linux,
you will need GCC installed. Go into the /src folder and type "make". If all
goes well, you should have a binary called ModernMUDConverter that you can run.

The converter does its best to convert, map, and translate things so that the
ModernMUD can load converted zones without any additional work, but it is not
perfect, and some things either don't translate or will have to be modified by
hand.

If you have a Basternae 1 zone created with DikuEdit or Duris zones created with
older versions of DikuEdit, you can use "convzone" utility in the Magma MUD 
codebase to convert those into Basternae 2 format. Those zones can then be used 
either  with the Magma MUD engine, or loaded into the ModernMUD converter for use
with ModernMUD. It has not been tested with (and may or may not work with) zones 
created with recent versions of DurisEdit.

