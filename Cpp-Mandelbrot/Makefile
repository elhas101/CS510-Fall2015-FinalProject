OBJS := cplane.o julia.o mandelbrot.o

# link
mandelbrot: $(OBJS)
	gcc $(OBJS) -o mandelbrot

# pull in dependency info for *existing* .o files
-include $(OBJS:.o=.d)

# compile and generate dependency info
%.o: %.c
	gcc -c $(CFLAGS) $*.c -o $*.o
	gcc -MM $(CFLAGS) $*.c > $*.d

run: all
	./mandelbrot -2 2 -2 2 100 100

# remove compilation products
clean:
	rm -f mandelbrot *.o *.d