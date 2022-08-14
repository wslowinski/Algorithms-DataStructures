.SUFFIXES: .cpp .x .o .h
DIR = `basename $(CURDIR)`

MAIN = main
SET = SetAsArray
VISITOR = AddingVisitor
ODD_VISITOR = OddVisitor

EXEC_MAIN = $(MAIN).x
OBJS_MAIN = $(MAIN).o
LIB1_MAIN = $(SET).h
LIB2_MAIN = $(VISITOR).hpp
LIB3_MAIN = $(ODD_VISITOR).hpp

IMP_SET = $(SET).cpp

CXXFLAGS = -std=c++14
LFLAGS = -std=c++14

CXX = g++
LD = $(CXX)

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $<

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

.PHONY: all
all: $(EXEC_MAIN)

$(EXEC_MAIN): $(OBJS_MAIN) $(LIB1_MAIN) $(LIB2_MAIN) $(LIB3_MAIN) $(IMP_SET)
	$(LD) -o $@ $(LFLAGS) $^

.PHONY: clean zip
clean:
	rm -f *.o *.x a.out

zip: clean
	(cd ../; zip -r Vladyslav_Slovinskyi_$(DIR).zip  $(DIR) )