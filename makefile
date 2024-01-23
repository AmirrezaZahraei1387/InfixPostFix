
CXX = g++
CXX_FLAGS = -Wall -g
EXE_NAME = InfixPostFixConvertor
VALGRIND_FLAGS = --leak-check=yes --track-origins=yes

# source files
SOURCE = oper/resolveNum.cpp oper/inOutE.cpp main.cpp

#object files
OBJ = inOutE.o main.o resolveNum.o

IN_POS_PRE_FIX: $(source_files)
	$(CXX) $(CXX_FLAGS) -c $(SOURCE)

all: IN_POS_PRE_FIX $(OBJ)
	$(CXX) $(CXX_FLAGS) -o $(EXE_NAME) $(OBJ)

run: $(EXE_NMAE)
	./$(EXE_NAME)

valgrind: $(EXE_NAME)
	valgrind $(VALGRIND_FLAGS) ./$(EXE_NAME)

clean: $(OBJ) $(EXE_NAME)
	rm $(EXE_NAME) $(OBJ)


