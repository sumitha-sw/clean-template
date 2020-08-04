all:
	g++ -Wall -Wextra -o testchecker *.cpp -lgtest -lpthread -fprofile-arcs -ftest-coverage -fPIC -O0 
