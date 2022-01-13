C++ = g++

RM = rm -f

C++FLAGS = -Wall -c -I include/

main: main.o calculator.o
	$(C++) $? -o $@

calculator.o: src/calculator.cpp include/calculator.h
	$(C++) $(C++FLAGS) src/calculator.cpp -o $@

main.o: src/main.cpp include/calculator.h
	$(C++) $(C++FLAGS) src/main.cpp -o $@

clean:
	$(RM) *.o main
