clear:
	rm -rf *.o *.a *_test

pool_allocator.o: pool_allocator.h pool_allocator.c
	gcc -Wall -Wextra -std=c11 -c pool_allocator.c

pool_allocator.a: pool_allocator.o
	ar rc pool_allocator.a pool_allocator.o

hashtable.o: hashtable.h hashtable.c pool_allocator.h
	gcc -Wall -Wextra -std=c11 -c hashtable.c

hashtable.a: hashtable.o
	ar rc hashtable.a hashtable.o

hashtable_test.o: hashtable_test.c hashtable.h pool_allocator.h
	gcc -Wall -Wextra -std=c11 -c hashtable_test.c

hashtable_test: hashtable_test.o hashtable.a pool_allocator.a
	gcc -o hashtable_test hashtable_test.o hashtable.a pool_allocator.a

test: hashtable_test
	./hashtable_test