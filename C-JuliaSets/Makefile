OBJS := cplane.o julia.o complex.o

# link
julia: $(OBJS)
	gcc $(OBJS) -o julia

# pull in dependency info for *existing* .o files
-include $(OBJS:.o=.d)

# compile and generate dependency info
%.o: %.c
	gcc -c $(CFLAGS) $*.c -o $*.o
	gcc -MM $(CFLAGS) $*.c > $*.d

run: julia 
	./julia 0.0001 10 0.000002 2 2 20 0.000002 0.0000004

# remove compilation products
clean:
	rm -f julia *.o *.d