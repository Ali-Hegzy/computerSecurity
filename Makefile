buildRun:
	gcc main.c src/ciphers.c src/matrix.c -o main && ./main
build:
	gcc main.c src/ciphers.c src/matrix.c -o main
run:
	./main
test:
	gcc test.c src/ciphers.c src/matrix.c -o test && ./test
