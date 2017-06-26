# Main executable file
PROGRAM = ModernMUDConverter

# Object files
OBJECTS = comm.o const.o db.o handler.o mem.o spec_mob.o string.o

.SUFFIXES:	.o .cpp

.cpp.o :
	$(CC) -c -o $@ $<

all:    $(PROGRAM)

$(PROGRAM):	$(OBJECTS)
	$(CC) -o $(PROGRAM) $(OBJECTS)

clean: 
	rm -f *.o $(PROGRAM)
