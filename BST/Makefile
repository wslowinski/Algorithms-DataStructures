.SUFFIXES: .cpp .x .o .h
DIR = `basename $(CURDIR)`

BST = BinaryTree
MAIN = main

EXEC_MAIN = $(MAIN).x
OBJS_MAIN = $(MAIN).o
LIBS_MAIN = 

BST_HEADER = $(BST).h
BST_IMP = $(BST).cpp


CXXFLAGS = -std=c++14
LFLAGS = -std=c++14

CXX = g++
LD = $(CXX)

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $<

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

.PHONY: all
all: $(EXEC_MAIN) $(BST_HEADER) $(BST_IMP)

$(EXEC_MAIN): $(OBJS_MAIN) $(BST_HEADER) $(BST_IMP)
	$(LD) -o $@ $(LFLAGS) $^


.PHONY: clean zip
clean:
	rm -f *.o *.x

zip: clean
	(cd ../; zip -r Vladyslav_Slovinskyi_$(DIR).zip  $(DIR) )

