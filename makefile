
CXX := g++
CXX_FLAGS := -Wall -g
EXE_NAME := InfixPostFixConvertor
VALGRIND_FLAGS := --leak-check=yes --track-origins=yes
OBJECTS := inOutE.o resolveNum.o main.o

.PHONY: all
all: $(OBJECTS)
	$(CXX) $(CXX_FLAGS) -o $(EXE_NAME) $^

.PHONY: clean
clean: $(OBJECTS) $(EXE_NAME)
	rm $^

.PHONY: valgrind
valgrind:
	valgrind $(VALGRIND_FLAGS) ./$(EXE_NAME)

.PHONY: run
run:
	./$(EXE_NAME)

inOutE.o: oper/inOutE.hpp oper/loader/loader.hpp oper/inOutE.cpp
	$(CXX) $(CXX_FLAGS) -c oper/inOutE.cpp

resolveNum.o: oper/inOutE.hpp preCheck/except.hpp oper/resolveNum.cpp
	$(CXX) $(CXX_FLAGS) -c oper/resolveNum.cpp

main.o: oper/inOutE.hpp expTree/expTree.hpp preCheck/INPosPreFinder.hpp preCheck/except.hpp main.cpp
	$(CXX) $(CXX_FLAGS) -c main.cpp

