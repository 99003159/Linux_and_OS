all: server client

server: server.c header.h
	gcc -o server.out server.c -lrt
	
client: client.c header.h
	gcc -o client.out client.c -lrt
	
clientRun:
	./client.out

serverRun:
	./server.out

clean:
	rm -rf *.out *.o
