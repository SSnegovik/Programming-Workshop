clear:
	rm -rf *.o *.a *_test

pool_allocator.o: pool_allocator.h pool_allocator.c
	gcc -Wall -Wextra -std=c11 -c pool_allocator.c

pool_allocator.a: pool_allocator.o
	ar rc pool_allocator.a pool_allocator.o

array_list.o: array_list.h array_list.c pool_allocator.h
	gcc -Wall -Wextra -std=c11 -c array_list.c

array_list.a: array_list.o
	ar rc array_list.a array_list.o

array_list_test.o: array_list_test.c array_list.h pool_allocator.h
	gcc -Wall -Wextra -std=c11 -c array_list_test.c

array_list_test: array_list_test.o array_list.a pool_allocator.a
	gcc -o array_list_test array_list_test.o array_list.a pool_allocator.a

test: array_list_test
	./array_list_test