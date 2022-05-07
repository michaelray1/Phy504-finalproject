
all: lorenz_system


#Debug mode
compute_motion.o: compute_motion.cpp Lorenz.H
	g++ -std=c++17 -g -c compute_motion.cpp

lorenz_system: compute_motion.o
	g++ -std=c++17 -g -o compute_motion compute_motion.o

test: unit_test_lorenz.cpp compute_motion.o
	g++ -std=c++17 -o test unit_test_lorenz.cpp
