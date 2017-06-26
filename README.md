# Basternae 2 / Magma to ModernMUD Zone Converter

This program converts Basternae 2 and Magma MUD format zones to the ModernMUD
XML zone format.

It is a separate project due to the different licensing requirements. For the
ModernMUD project, see here:

https://github.com/Xangis/ModernMUD

The ModernMUD Zone Converter is configured much like an Envy-based MUD in that
you edit the AREA.LST file in the /area directory to add the zones you want to
convert and then run the executable.  The zones, typically with a ".are" file
format, will be loaded and then written out to the ".xml" file format. Zones
should be stored in the /area directory, and output will also be in the /area
directory.

There is an executable, /src/ModernMUDConverter.exe included for Windows. For
Linux, you will need GCC or Clang installed (it has been tested with both). Go 
into the /src folder and type "make". If all goes well, you should have a binary 
called ModernMUDConverter that you can run. On Windows, there is a Visual Studio 
2012 project included in /src.  If you use an older version of VS, just create 
an empty console project and add the .c and .h files. Newer versions should 
convert the project just fine. The project is plain C with no special 
dependencies.

The converter does its best to convert, map, and translate things so that the
ModernMUD can load converted zones without any additional work, but it is not
perfect, and some things either don't translate or will have to be modified by
hand.

If you have a Basternae 1 zone created with DikuEdit or Duris zones created with
older versions of DikuEdit, you can use "convzone" utility in the Magma MUD 
codebase to convert those into Basternae 2 format. Those zones can then be used 
either  with the Magma MUD engine, or loaded into the ModernMUD converter for use
with ModernMUD. It has not been tested with (and may or may not work with) zones 
created with recent versions of DurisEdit. For the Magma MUD codebase and
convzone, check here:

https://github.com/Xangis/magma

I would like to add support for converting other zone types to the ModernMUD area
format. If you have a zone that fails to convert using one of the supported zone
types, or have a zone type that you would like to have support added for, please
contact me at jchampion [at] zetacentauri {dot} com.

## Development Status

The converter is not under active development, but it is maintained to be sure that
it will build. I am willing to accept pull requests if you have improvements to
contribute.
