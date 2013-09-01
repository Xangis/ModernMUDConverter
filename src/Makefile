# Main executable file
PROGRAM = ModernMUDConvertor

# Object files
OBJECTS = comm.o const.o db.o handler.o mem.o spec_mob.o string.o

CXX = gcc

.SUFFIXES:	.o .cpp

.cpp.o :
	$(CXX) -c -o $@ $<

all:    $(PROGRAM)

$(PROGRAM):	$(OBJECTS)
	$(CXX) -o $(PROGRAM) $(OBJECTS)

clean: 
	rm -f *.o $(PROGRAM)
