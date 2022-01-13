CC=g++

all: cmd_parse_app

cmd_parse_app: cmd_parse_app.o
	$(CC) cmd_parse_app.o -o cmd_parse_app

cmd_parse_app.o: cmd_parse_app.cpp
	$(CC) -c cmd_parse_app.cpp

clean:
	rm -rf *.o cmd_parse_app