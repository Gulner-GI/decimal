GCC         := gcc -Wall -Werror -Wextra -std=c11
TARGET      := s21_decimal

SOURCES     := $(wildcard *.c)
HEADERS     := $(wildcard *.h)

TEST_SRCS   := $(wildcard tests/test_s21_*.c)
TEST_NAMES  := $(TEST_SRCS:tests/test_s21_%.c=%)

GCOV_DIR := gcov/

OS := $(shell uname -s)
ifeq ($(OS), Darwin)
    CHECK_FLAGS := $(shell pkg-config --cflags --libs check)
    OPEN_CMD    := open
else
    CHECK_FLAGS := -lcheck -lpthread -lm -lrt -lsubunit
    OPEN_CMD    := xdg-open
endif

.PHONY: all clean test gcov_report clang

all: $(TARGET).a

rebuild: clean all

$(TARGET).a: $(TARGET).c
	@$(GCC) -c $< -o $(TARGET).o
	@ar rcs $@ $(TARGET).o
	@ranlib $@
	@echo "Библиотека $(TARGET).a собралась"

main: main.c $(TARGET).a
	@$(GCC) main.c $(TARGET).a
	@echo "main скомпилирован и связан с $(TARGET).a"

test: clean $(TARGET).a
	@bash tests/run_tests.sh "$(CHECK_FLAGS)"

gcov_report: clean
	@echo "Создание отчета о покрытии..."
	@mkdir -p $(GCOV_DIR)
	@$(GCC) --coverage $(TARGET).c tests/*.c $(CHECK_FLAGS) -o $(GCOV_DIR)/gcov_test
	@cd $(GCOV_DIR) && ./gcov_test > /dev/null
	@lcov -t "$(TARGET)" -o $(GCOV_DIR)/coverage.info -c -d $(GCOV_DIR) --ignore-errors graph,unused > /dev/null
	@lcov --remove $(GCOV_DIR)/coverage.info '*/tests/*' -o $(GCOV_DIR)/coverage.info --ignore-errors unused > /dev/null
	@genhtml -o report $(GCOV_DIR)/coverage.info > /dev/null
	@echo "Отчёт готов, введи команду: open report/index.html"

clean:
	@rm -rf *.o *.a tests/bin report gcov
	@rm -f tests/test_results.log tests/failed.log tests/*.gcda tests/*.gcno tests/*.info gcov_test tests/*.o
	@rm -f .clang-format
	@rm -f tests/.clang-format
	@rm -f a.out
	@echo "Чистка завершена"

clang:
	@cp ../materials/linters/.clang-format .
	@clang-format -i *.c *.h
	@cp .clang-format tests/
	@clang-format -i tests/*.c
	@rm -f .clang-format
	@rm -f tests/.clang-format
	@echo "Код отформатирован clang-format'ом"

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem $(SOURCES) $(TEST_SRCS)
	@echo "Код прошел cppcheck"

leaks:
	valgrind --tool=memcheck --leak-check=yes ./tests/bin/test_run
	@echo "Код проверен на утечки valgrind'ом"