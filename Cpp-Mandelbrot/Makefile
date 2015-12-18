OBJS := cplane.o julia.o mandelbrot.o

# link
all: $(OBJS)
	g++ $(OBJS) -o mandelbrot

# pull in dependency info for *existing* .o files
-include $(OBJS:.o=.d)

# compile and generate dependency info
%.o: %.c
	g++ -c $(CFLAGS) $*.c -o $*.o
	g++ -MM $(CFLAGS) $*.c > $*.d

mandelbrot: all
	./mandelbrot -2 2 -2 2 1000 1000

# remove compilation products
clean:
	rm -f mandelbrot *.o *.d