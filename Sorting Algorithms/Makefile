.SUFFIXES: .cpp .x .o .h
DIR = `basename $(CURDIR)`

BUBBLESORT = BubbleSort
MOD_BUBBLESORT = ModifiedBubbleSort
INSERTIONSORT = InsertionSort
SELECTIONSORT = SelectionSort
GENERATOR = Generator

EXEC_B_SORT = $(BUBBLESORT).x
OBJS_B_SORT = $(BUBBLESORT).o
LIBS_B_SORT = 

EXEC_M_B_SORT = $(MOD_BUBBLESORT).x
OBJS_M_B_SORT = $(MOD_BUBBLESORT).o
LIBS_M_B_SORT = 

EXEC_I_SORT = $(INSERTIONSORT).x
OBJS_I_SORT = $(INSERTIONSORT).o
LIBS_I_SORT = 

EXEC_S_SORT = $(SELECTIONSORT).x
OBJS_S_SORT = $(SELECTIONSORT).o
LIBS_S_SORT = 


CXXFLAGS = -std=c++17
LFLAGS = -std=c++17

CXX = g++
LD = $(CXX)

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $<

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

.PHONY: all
all: $(EXEC_B_SORT) $(EXEC_I_SORT) $(EXEC_S_SORT) $(EXEC_M_B_SORT)

$(EXEC_B_SORT): $(OBJS_B_SORT)
	$(LD) -o $@ $(LFLAGS) $^

$(EXEC_M_B_SORT): $(OBJS_M_B_SORT)
	$(LD) -o $@ $(LFLAGS) $^

$(EXEC_I_SORT): $(OBJS_I_SORT)
	$(LD) -o $@ $(LFLAGS) $^

$(EXEC_S_SORT): $(OBJS_S_SORT)
	$(LD) -o $@ $(LFLAGS) $^


.PHONY: clean zip
clean:
	rm -f *.o *.x *.txt

zip: clean
	(cd ../; zip -r Vladyslav_Slovinskyi_$(DIR).zip  $(DIR) )

