all: pipe_chat pipe1_chat pipe2_chat

pipe_chat: pipe_chat.c pipe_header.h
	gcc -o pipe_chat.out pipe_chat.c -lrt
	
pipe1_chat: pipe1_chat.c pipe_header.h
	gcc -o pipe1_chat.out pipe1_chat.c -lrt

pipe2_chat: pipe2_chat.c pipe_header.h
	gcc -o pipe2_chat.out pipe2_chat.c -lrt

	
runpipe:
	./pipe_chat.out

runpipe1:
	./pipe1_chat.out

runpipe2:
	./pipe2_chat.out

clean:
	rm -rf *.out *.o
