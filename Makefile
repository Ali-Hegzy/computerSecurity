buildRun:
	gcc main.c src/ciphers.c src/matrix.c src/inputs.c src/controlPanal.c -o main && ./main
build:
	gcc main.c src/ciphers.c src/matrix.c src/inputs.c src/controlPanal.c -o main
run:
	./main
Test:
	gcc test.c src/ciphers.c src/matrix.c src/inputs.c src/controlPanal.c -o test && ./test
