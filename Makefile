CFLAGS = -g -Wall
LDFLAGS =

CFLAGS += $(shell pkg-config --cflags htslib glib-2.0)
LDFLAGS += $(shell pkg-config --libs htslib glib-2.0)

OBJECTS =  src/main.o src/funcs.o

bin/samkit: $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

src/%.o: src/%.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf bin/samkit src/*.o
