CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -fprofile-arcs -ftest-coverage
TEST_FLAGS = -lcheck -lm -lpthread -lsubunit

PROJECT_NAME = matrix

LIBRARY_NAME = s21_$(PROJECT_NAME)
LIBRARY = $(BUILD_DIR)/$(LIBRARY_NAME).a
TEST_TARGET = $(BUILD_DIR)/test_$(LIBRARY_NAME)

SRC_DIR = .
TEST_DIR = tests
BUILD_DIR = build
COVERAGE_DIR = $(BUILD_DIR)/coverage_html
COVERAGE_INFO = $(BUILD_DIR)/coverage.info

SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:%.c=$(BUILD_DIR)/%.o)
HEADERS = $(wildcard *.h)

TEST_SOURCES = $(wildcard $(TEST_DIR)/*.c)
TEST_OBJECTS = $(TEST_SOURCES:$(TEST_DIR)/%.c=$(BUILD_DIR)/%.o)

all: library test

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

library: $(LIBRARY)

$(LIBRARY): $(OBJECTS) | $(BUILD_DIR)
	ar rcs $@ $^
	ranlib $@

test: $(TEST_TARGET)

$(TEST_TARGET): $(LIBRARY) $(TEST_OBJECTS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $(TEST_OBJECTS) $(LIBRARY) $(TEST_FLAGS)

$(BUILD_DIR)/%.o: %.c $(HEADERS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(SRC_DIR) -c $< -o $@

run_test: test
	./$(TEST_TARGET)

clean:
	rm -rf $(BUILD_DIR) coverage_html coverage.info

rebuild: clean all
	
clang:
	clang-format -n $(SOURCES) $(HEADERS) $(TEST_SOURCES)
	clang-format -i $(SOURCES) $(HEADERS) $(TEST_SOURCES)

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem $(SOURCES) $(TEST_SOURCES)

leaks: $(TEST_TARGET)
	valgrind --tool=memcheck --leak-check=yes ./$(TEST_TARGET)

gcov_report: $(TEST_TARGET)
	./$(TEST_TARGET)
	lcov --capture --directory $(BUILD_DIR) --output-file $(COVERAGE_INFO)
	lcov --remove $(COVERAGE_INFO) "*/tests/*" --output-file $(COVERAGE_INFO)
	genhtml $(COVERAGE_INFO) --output-directory $(COVERAGE_DIR)

.PHONY: all clean rebuild cppcheck clang leaks library test run_test gcov_report