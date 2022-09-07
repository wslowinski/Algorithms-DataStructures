.SUFFIXES: .cpp .x .o .h
DIR = `basename $(CURDIR)`

DICT = Dict
MAIN = main

EXEC_MAIN = $(MAIN)
OBJS_MAIN = $(MAIN).o
LIBS_MAIN = 

DICT_HEADER = $(DICT).h
DICT_IMP = $(DICT).cpp

CXXFLAGS = -std=c++17
LFLAGS = -std=c++17

CXX = g++
LD = $(CXX)

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $<

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

.PHONY: all
all: $(EXEC_MAIN) $(DICT_HEADER) $(DICT_IMP)

$(EXEC_MAIN): $(OBJS_MAIN) $(DICT_HEADER) $(DICT_IMP)
	$(LD) -o $@ $(LFLAGS) $^

.PHONY: clean zip
clean:
	rm -f *.o *.x main

zip: clean
	(cd ../; zip -r Vladyslav_Slovinskyi_$(DIR).zip  $(DIR) )

