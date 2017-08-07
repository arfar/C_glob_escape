CC = gcc

VER_MAJ = 0
VER_MIN = 1
VER = "$(VER_MAJ).$(VER_MIN)"
VERSION_DEFINES = -DVERSION='$(VER)' -DVERSION_MAJOR='$(VER_MAJ)' -DVERSION_MINOR='$(VER_MIN)'
CFLAGS = -Wall -pedantic $(VERSION_DEFINES)
DEPS = globescape.h

LIBS = libglobescape.a libglobescape.so

all: $(LIBS) globescape.o test

libs: $(LIBS)

test: test.o globescape.o $(DEPS)
	$(CC) -o $@ $^

libglobescape.a: globescape.o
	ar rs $@ $<

libglobescape.so: globescape.lo
	$(CC) -shared -o $@ $<

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

%.lo: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -fpic -o $@ $<

install:
	install -o root -d $(DESTDIR)/usr/lib
	install -o root -d $(DESTDIR)/usr/include
	install -p -o root $(LIBS) $(DESTDIR)/usr/lib
	install -p -o root globescape.h $(DESTDIR)/usr/include

run_tests: test
	./test

clean:
	rm -f $(LIBS) *.o *.lo test

.PHONY: all libs clean
