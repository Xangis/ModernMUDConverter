ModernMUDConverter version 1.26

September 1, 2013

ModernMUDConverter is for converting old-style *.are Basternae II areas to
the new-style XML ModernMUD engine area format.  It is designed to work with
batches of area files.

Put all of the areas you want to convert into the /area directory and add
them to the list of files in AREA.LST.  Converted files should be output
to the same directory with ".xml" added to the filename.

Keep an eye on the log screen -- it will tell you if anything goes wrong.
There may be data in the file that the converter does not understand.

BE WARNED:

This application does its best to replace ampersands and < > symbols in text,
but it is not yet perfect.  This means that if an XML parser chokes on the
file after the conversion, you will need to:

1. Replace any rogue instances of "&" with "&amp;"
2. Replace any rogue instances of "<" with "&lt;"
3. Replace any rogue instances of ">" with "&gt;"

An easy way to check whether the XML file is valid is to drag and drop it into
Visual Studio. It's nice enough to point out any errors so they're easy to find.

ALSO, if someone mistakenly uses an &m instead of an &n for color codes, that
has been known to break loading a zone post-convert.  You will have to go back
to the source zone and correct that.  The same may happen with other typoed
ANSI codes, so be aware.

----- KNOWN ISSUES ----

Duris-format equipment resets ('E') do not convert properly -- arguments are in
a different order.

----- CHANGES -----
1.26:  - Remove lots more extraneous code.
1.25:  - Remove more extraneous code.
1.24:  - Better error messages for duplicate index numbers, cleaned up code.
1.23:  - Add saving of spell effects for objects, added some spell conversions.
1.22:  - Fix for quest converting (tag names changed in zone format).
1.21:  - Fix for converting Umber Hulk race, fix for blocked exit IS_DOOR flag, fix
         for loading 'grant pet' quests.
1.20:  - Fix to remove ANSI codes from exit keywords, partial fix for missing object
         and death specials.
1.19:  - Fix to make objects retain affects like +hitroll or +hp during conversion.
1.18:  - Fix to is_number check for trap flags that caused pointer errors and chaos and
         a fix to a problem that caused zones with "& " in any description to fail to
         load after generation.
1.17:  - Fix for wear_flags value in ModernMUD-format objects.  Fix for extra_flags[0]
         being erroneously stored in affect_flags[0].
1.16:  - Fix for builders text in zones.
1.15:  - Fix for death on spells without ModernMUD equivalents, fix for exit description
         ampersand escaping, fix for size any being invalid.
1.14:  - Missing file no longer a non-recoverable error, pause on most crashes.
1.13:  - Added support for DurisEdit-format mobiles, including class conversion.
         Added support for translating the newer class types found in DikuEdit -
         Chronomancer, Warlock, and Enslaver.
1.12:  - Changed AntiFlags and AntiFlags2 into a single UseFlags bitvector.  Changed
         WearFlags into a bitvector.
1.11:  - Changed all underscored tag names to camel case.
1.10:  - Changed Room to RoomTemplate to reflect new room class structure.
1.09:  - Fixed room loading.  Previously, target room vnums and key vnums failed to
         load for exits.
1.08:  - Changed conversion to work with new enumerations.  Many integer values have
         been changed into string values.
1.07:  - Fixed race conversion -- all races above #19 had skewed and inaccurate values.
         Animals no longer show up as Dracoliches and similar fixes.
1.06:  - Changed area data saving to match enum conversion of sex and size values
         in Basternae 3.
1.05:  - Changed area data saving to coincide with the new repop code changes in B3.
1.04:  - Fixed mob act flags saving.
       - Fixed loading of resets flagged 'P'.
       - Fix to object name loading that would prefix all object names with "0 "
         in some areas.
1.03:  - Fixed failure to save reset data.
       - Fixed saving of quest item type string.
       - Added removal of newlines in descriptions.
1.02:  - Fixed mixup of mob long descriptions vs. mob in-room descriptions.
1.01:  - Added makezone.bat and saving of quest item types as the enum used in
         the game engine.
1.00:  - Initial version.