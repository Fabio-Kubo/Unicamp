saida: entrada1.o entrada2.o
	ld -dynamic-linker /lib64/ld-linux-x86-64.so.2 /usr/lib64/crt1.o /usr/lib64/crti.o -L/usr/lib64 entrada1.o entrada2.o -lc /usr/lib64/crtn.o -o saida
entrada1.o: entrada1.s
	as entrada1.s -o entrada1.o
entrada2.o: entrada2.s
	as entrada2.s -o entrada2.o
entrada1.s: entrada1.c
	gcc -S entrada1.c -o entrada1.s
entrada2.s: entrada2.c
	gcc -S entrada2.c -o entrada2.s
