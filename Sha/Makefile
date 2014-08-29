obj=sha.o sha1.o
cc=gcc
sha:$(obj)
	$(cc)  -o sha sha.o sha1.o
sha1.o:sha1.c sha1.h
	$(cc) -c sha1.c


clean: 
	rm -f $(obj)

