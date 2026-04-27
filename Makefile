buildRun:
	gcc main.c src/ciphers/enc/utilites.c src/ciphers/enc/ciphers.c src/ciphers/dec/iciphers.c src/matrix.c src/inputs.c src/controlPanals/encControlPanal.c src/controlPanals/decControlPanal.c src/controlPanals/mainPanal.c -o main && ./main
build:
	gcc main.c src/ciphers/enc/utilites.c src/ciphers/enc/ciphers.c src/ciphers/dec/iciphers.c src/matrix.c src/inputs.c src/controlPanals/encControlPanal.c src/controlPanals/decControlPanal.c src/controlPanals/mainPanal.c -o main
run:
	./main
Test:
	gcc test.c src/ciphers/enc/utilites.c src/ciphers/enc/ciphers.c src/ciphers/dec/iciphers.c src/matrix.c src/inputs.c src/controlPanals/encControlPanal.c src/controlPanals/decControlPanal.c src/controlPanals/mainPanal.c -o test && ./test
