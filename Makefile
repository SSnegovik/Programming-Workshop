clean:
	rm -rf *.o *.a *_test

# Проверка форматирования
check_fmt:
	clang-format -style=LLVM --dry-run --Werror `find . -regex ".*\.[ch]"`

fmt:
	clang-format -style=LLVM -i `find . -regex ".*\.[ch]"`

TASK_DIRS := $(shell find . -maxdepth 1 -type d -name 'task[0-9]*')

.PHONY: test $(TASK_DIRS) clean fmt check_fmt

test: $(TASK_DIRS)
	@echo "Все тесты завершены успешно или их не было вообще"

$(TASK_DIRS):
	$(MAKE) -C $@ test
