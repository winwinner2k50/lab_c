out_dir := out
src_dir := src
inc_dir := inc
unit_tests := unit_tests
unit_inc := unit_inc

CC := gcc
CFLAGS := -std=c99 -Werror
CFLAGS1 := -std=c99 -Werror -lcheck  -lcheck -lsubunit -lrt -lm -lpthread

FILE := $(shell find ./$(src_dir) -name "*.c")
FILE_CHECK := $(shell find ./$(unit_tests) -name "*.c")
OBJS := $(patsubst ./$(src_dir)/%.c,$(out_dir)/%.o,$(FILE))

OBJS_NOT_MAIN := $(patsubst ./$(src_dir)/%.c,$(out_dir)/%.o,$(filter-out %main.c,$(FILE)))
OBJS_CHECK := $(patsubst ./$(unit_tests)/%.c,$(out_dir)/%.o,$(FILE_CHECK))

HEADERS := $(shell find ./$(inc_dir) -name "*.h")
HEADERS_CHECK := $(shell find ./$(unit_inc) -name "*.h")

app.exe : $(OBJS)
	mkdir -p $(out_dir)
	$(CC) $(OBJS) -o app.exe

unit_tests.exe : $(OBJS_NOT_MAIN) $(OBJS_CHECK) $(HEADERS) 
	mkdir -p $(out_dir)
	$(CC) $^ -o $@ $(CFLAGS1) $(HEADERS_CHECK)

$(out_dir)/check_%.o : $(unit_tests)/check_%.c $(inc_dir)/*.h $(unit_inc)/*.h
	mkdir -p $(out_dir)
	$(CC) $(CFLAGS) -I $(inc_dir) -I $(unit_inc) -c $< -o $@

$(out_dir)/%.o: $(src_dir)/%.c $(inc_dir)/*.h
	mkdir -p $(out_dir)
	$(CC) $(CFLAGS) -I $(inc_dir) -c $< -o $@

clean :0
	rm -f ./*.exe ./*.gcov ./*.gcda ./*.o ./*.gcno ./*.out ./*tmp*
	rm -rf .idea
