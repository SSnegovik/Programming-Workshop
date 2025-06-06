clear:
	rm -rf *.o *.a *_test

check_fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"` --dry-run --Werror

fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"`

TASK_DIRS := $(shell find . -maxdepth 1 -type d -name 'task[0-9]*')

.PHONY: test valgrind $(TASK_DIRS)

test: $(TASK_DIRS)
	@echo "¬се тесты завершены успешно или их не было вообще"

valgrind:
	@for dir in $(TASK_DIRS); do \
		echo "ѕроверка на утечки пам€ти в $$dir..."; \
		$(MAKE) -C $$dir valgrind || exit 1; \
	done
	@echo "ѕроверка пам€ти завершена успешно"

$(TASK_DIRS):
	$(MAKE) -C $@ test