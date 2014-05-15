PROG=main
C1=CryptarithmeticPuzzle
C2=GeneticAlgorithm
C3=Genotype
C4=Individual
C5=Phenotype
CXX=mpic++
CXXFLAGS =-Wall -g
LIBRARIES =-lm
NODES=nodes
NPROC=3

all : clean $(PROG)

$(PROG): $(PROG).o $(C1).o $(C2).o $(C3).o $(C4).o $(C5).o 
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LIBRARIES)

$(PROG).o: $(PROG).cpp
	$(CXX) -c $(CXXFLAGS) $(PROG).cpp -o $(PROG).o

$(C1).o: $(C1).cpp
	$(CXX) -c $(CXXFLAGS) $(C1).cpp -o $(C1).o

$(C2).o: $(C2).cpp
	$(CXX) -c $(CXXFLAGS) $(C2).cpp -o $(C2).o

$(C3).o: $(C3).cpp
	$(CXX) -c $(CXXFLAGS) $(C3).cpp -o $(C3).o

$(C4).o: $(C4).cpp
	$(CXX) -c $(CXXFLAGS) $(C4).cpp -o $(C4).o

$(C5).o: $(C5).cpp
	$(CXX) -c $(CXXFLAGS) $(C5).cpp -o $(C5).o


.PHONY : prep clean run valgrind drmemory gdb

prep:
	export PATH=/opt/nfs/mpich-3.0.2/bin:$PATH
	export LDLIPRARYPATH=/opt/nfs/mpich-3.0.2/lib
	export MANPATCH=/opt/nfs/mpich-3.0.2/share/man
	

clean:
	rm -f *.o $(PROG)

run:
	mpiexec ./$(PROG)

runn:
	mpiexec -n $(NPROC) ./$(PROG)

runf:
	mpiexec -n $(NPROC) -f $(NODES) ./$(PROG)

valgrind:
	valgrind --leak-check=full  ./$(PROG)

drmemory:
	drmemory $(PROG).exe

gdb: # $(PROG)
	gdb $(PROG)
