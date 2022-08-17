.SUFFIXES: .cpp .x .o .h .hpp
DIR = `basename $(CURDIR)`

MAIN = main
EDGE = Edge
GRAPH = GraphAsMatrix
VERTEX = Vertex
VISITOR = Visitor

EXEC_MAIN = $(MAIN).x
OBJS_MAIN = $(MAIN).o
LIBS_MAIN =  

IMP_EDGE = $(EDGE).cpp
IMP_VERTEX = $(VERTEX).cpp
IMP_GRAPH = $(GRAPH).cpp
IMP_VISITOR = $(VISITOR).cpp

CXXFLAGS = -std=c++14
LFLAGS = -std=c++14

CXX = g++
LD = $(CXX)

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $<

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

.PHONY: all
all: clean $(EXEC_MAIN)

$(EXEC_MAIN): $(OBJS_MAIN) $(IMP_EDGE) $(IMP_VERTEX) $(IMP_VISITOR) $(IMP_GRAPH)
	$(LD) -o $@ $(LFLAGS) $^


.PHONY: clean zip
clean:
	rm -f *.o *.x

zip: clean
	(cd ../; zip -r Vladyslav_Slovinskyi_$(DIR).zip  $(DIR) )

test: clean $(MAIN).x
	./$(MAIN).x < data.txt
