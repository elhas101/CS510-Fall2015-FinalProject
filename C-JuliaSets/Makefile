OBJS := cplane.o julia.o complex.o

# link
all: $(OBJS)
	gcc $(OBJS) -o julia

# pull in dependency info for *existing* .o files
-include $(OBJS:.o=.d)

# compile and generate dependency info
%.o: %.c
	gcc -c $(CFLAGS) $*.c -o $*.o
	gcc -MM $(CFLAGS) $*.c > $*.d

julia: all 
	./julia -2 2 -2 2 1000 1000 -1.037 0.17

# remove compilation products
clean:
	rm -f julia *.o *.d