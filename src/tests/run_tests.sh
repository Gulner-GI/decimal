#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'
BOLD='\033[1m'

GCC="gcc -Wall -Werror -Wextra -std=c11"
CHECK_FLAGS=$1
BIN_DIR="tests/bin"
LOG_FILE="tests/test_results.log"

mkdir -p $BIN_DIR
rm -f $LOG_FILE

echo -e "Компиляция всех тестов..."

$GCC tests/*.c s21_decimal.a $CHECK_FLAGS -o "$BIN_DIR/test_run" >> "$LOG_FILE" 2>&1

if [ $? -ne 0 ]; then
    echo -e "${RED}Компиляция не удалась!${NC}"
    echo -e "Check $LOG_FILE for errors."
    exit 1
fi

echo -e "${GREEN}Компиляция успешна!${NC}"
echo -e "Запуск тестов..."
echo "---------------------------------------"

./$BIN_DIR/test_run

RESULT=$?

echo "---------------------------------------"
if [ $RESULT -eq 0 ]; then
    echo -e "${GREEN}Все тесты пройдены!${NC}"
else
    echo -e "${RED}Некоторые тесты не прошли!${NC}"
    exit 1
fi