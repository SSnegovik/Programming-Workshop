clear:
	rm -rf *.o *.a *_test

pool_allocator.o: pool_allocator.h pool_allocator.c
	gcc -c pool_allocator.c

pool_allocator.a: pool_allocator.o
	ar rc pool_allocator.a pool_allocator.o

pool_allocator_test.o: pool_allocator_test.c pool_allocator.h
	gcc -c pool_allocator_test.c

pool_allocator_test: pool_allocator_test.o pool_allocator.a
	gcc -o pool_allocator_test pool_allocator_test.o pool_allocator.a

test: pool_allocator_test
	./pool_allocator_test