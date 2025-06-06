clear:
	rm -rf *.o *.a *_test garbage_collector_test

pool_allocator.o: pool_allocator.c pool_allocator.h
	gcc -c pool_allocator.c -o pool_allocator.o

pool_allocator.a: pool_allocator.o
	ar rc pool_allocator.a pool_allocator.o

garbage_collector.o: garbage_collector.c garbage_collector.h pool_allocator.h
	gcc -c garbage_collector.c -o garbage_collector.o

garbage_collector_test.o: garbage_collector_test.c garbage_collector.h pool_allocator.h
	gcc -c garbage_collector_test.c -o garbage_collector_test.o

garbage_collector_test: garbage_collector_test.o garbage_collector.o pool_allocator.a
	gcc -o garbage_collector_test garbage_collector_test.o garbage_collector.o pool_allocator.a

test: garbage_collector_test
	./garbage_collector_test

valgrind: garbage_collector_test
	valgrind --leak-check=full --error-exitcode=1 ./garbage_collector_test