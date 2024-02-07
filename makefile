COMPILATEUR=gcc
EXEC1=server
EXEC2=client
SERVER=src/server
CLIENT=src/client
EX=src/Example/Example
FILES=src/Files/Files
BYTES=src/Bytes/Bytes
MSG=src/Msg/Msg




1: server clean

2: client clean

server: server.o example.o files.o bytes.o msg.o
	gcc *.o -o $(EXEC1)

server.o: $(SERVER).c $(EX).h $(FILES).h $(BYTES).h $(MSG).h
	gcc -g -Wall -c $(SERVER).c


client: client.o example.o files.o bytes.o msg.o
	gcc *.o -o $(EXEC2)

client.o: $(CLIENT).c $(EX).h $(FILES).h $(BYTES).h $(MSG).h
	gcc -g -Wall -c $(CLIENT).c


example.o: $(EX).c $(EX).h
	gcc -g -Wall -c $(EX).c
	
files.o: $(FILES).c $(FILES).h
	gcc -g -Wall -c $(FILES).c
	
bytes.o: $(BYTES).c $(BYTES).h
	gcc -g -Wall -c $(BYTES).c
	
msg.o: $(MSG).c $(MSG).h
	gcc -g -Wall -c $(MSG).c


clean:
	rm -rf *.o


