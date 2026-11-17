hepsi: make calistir

main:
	gcc  -c -I "./include" ./src/main.c -o ./lib/main.o

make: main canli bitki bocek sinek pire habitat
	gcc ./lib/main.o -o ./bin/make

canli:
	gcc -c -I "./include" ./src/Canli.c -o ./lib/Canli.o 

bitki:
	gcc -c -I "./include" ./src/Bitki.c -o ./lib/Bitki.o 

bocek:
	gcc -I ./include/ -o ./lib/Bocek.o -c ./src/Bocek.c

sinek:
	gcc -I ./include/ -o ./lib/Sinek.o -c ./src/Sinek.c

pire:
	gcc -I ./include/ -o ./lib/Pire.o -c ./src/Pire.c

habitat:
	gcc -I ./include/ -o ./lib/Habitat.o -c ./src/Habitat.c

calistir:
	./bin/make.exe