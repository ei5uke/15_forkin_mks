work15: work15.c
	gcc -o work15 work15.c

run: work15
	./work15

clean:
	rm work15
	echo Clean Done
	