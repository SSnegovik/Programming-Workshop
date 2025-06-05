clear:
	rm -rf *.o *.a *_test

linear_allocator.o: linear_allocator.h linear_allocator.c
	gcc -c linear_allocator.c

linear_allocator.a: linear_allocator.o
	ar rc linear_allocator.a linear_allocator.o

linear_allocator_test.o: linear_allocator_test.c linear_allocator.h
	gcc -c linear_allocator_test.c

linear_allocator_test: linear_allocator_test.o linear_allocator.a
	gcc -o linear_allocator_test linear_allocator_test.o linear_allocator.a

test: linear_allocator_test
	./linear_allocator_test