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
	./julia 0.001 10 0.0005 5 5 50 0.0005 0.0004

# remove compilation products
clean:
	rm -f julia *.o *.d