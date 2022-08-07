.SUFFIXES: .cpp .x .o .h
DIR = `basename $(CURDIR)`

QUEUE = Queue
GENERATOR = Generator
RADIX = Radix
ARRAY_QUEUE = ArrayQueue
LINKED_QUEUE = LinkedQueue

EXEC_QUEUE = $(QUEUE).x
OBJS_QUEUE = $(QUEUE).o
LIBS_QUEUE = $(ARRAY_QUEUE).h

EXEC_RADIX = $(RADIX).x
OBJS_RADIX = $(RADIX).o
LIBS_RADIX = $(LINKED_QUEUE).h

EXEC_GENERATOR = $(GENERATOR).x
OBJS_GENERATOR = $(GENERATOR).o
LIBS_GENERATOR = 

IMP_ARRAY = $(ARRAY_QUEUE).cpp
IMP_LINKED = $(LINKED_QUEUE).cpp

CXXFLAGS = -std=c++14 -fPIC
LFLAGS = -std=c++14

CXX = g++
LD = $(CXX)

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $<

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

.PHONY: all
all: $(EXEC_QUEUE) $(EXEC_RADIX) $(EXEC_GENERATOR)

$(EXEC_GENERATOR): $(OBJS_GENERATOR)
	$(LD) -o $@ $(LFLAGS) $^

$(EXEC_QUEUE): $(OBJS_QUEUE) $(LIBS_QUEUE) $(IMP_ARRAY)
	$(LD) -o $@ $(LFLAGS) $^

$(EXEC_RADIX): $(OBJS_RADIX) $(LIBS_RADIX) $(IMP_LINKED)
	$(LD) -o $@ $(LFLAGS) $^

.PHONY: clean zip
clean:
	rm -f *.o *.x data.txt

zip: clean
	(cd ../; zip -r Vladyslav_Slovinskyi_$(DIR).zip  $(DIR) )
