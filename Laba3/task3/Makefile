clear:
	rm -rf *.o *_test destructor_test

pool_allocator.o: pool_allocator.c pool_allocator.h
	gcc -c pool_allocator.c -o pool_allocator.o

destructor.o: destructor.c destructor.h pool_allocator.h
	gcc -c destructor.c -o destructor.o

destructor_test.o: destructor_test.c destructor.h pool_allocator.h
	gcc -c destructor_test.c -o destructor_test.o

destructor_test: destructor_test.o destructor.o pool_allocator.o
	gcc -o destructor_test destructor_test.o destructor.o pool_allocator.o

test: destructor_test
	./destructor_test

valgrind: destructor_test
	valgrind --leak-check=full --error-exitcode=1 ./destructor_test