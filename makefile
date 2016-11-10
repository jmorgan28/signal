sigtest: proc.c
	gcc proc.c -o sigtest

run: sigtest
	./sigtest

clean:
	rm sigtest
	rm *.exe
	rm *~
	rm *dump 
