shell: shell.o
	gcc shell.o -o trabalho
	./trabalho
clean:
	rm trabalho
	rm *.o

