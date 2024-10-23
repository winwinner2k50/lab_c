CC := gcc
CFLAGS := -std=c99 -Werror
CFLAGS_TEST := -std=c99 -Werror -lcheck -lsubunit -lrt -lm -lpthread

dir_out_default := out
dir_funcs_default := src
dir_headers_default := inc

dir_out_check := out_check
dir_funcs_check := unit_tests
dir_headers_check := unit_inc

FILE_FUNCS_DEFAULT := $(shell find ./$(dir_funcs_default) -name "*.c")
FILE_FUNCS_CHECK := $(shell find ./$(dir_funcs_check) -name "*.c")
# переписать через wildcard

FILE_MAIN := $(dir_funcs_default)/main.c

OBJS_FUNCS_DEFAULT :=  $(dir_out_default)/arr.o $(dir_out_default)/mysort.o $(dir_out_default)/key.o
OBJS_MAIN_DEFAULT := $(dir_out_default)/main.o
OBJS_CHECK := $(patsubst ./$(dir_funcs_check)/%.c,$(dir_out_check)/%.o,$(FILE_FUNCS_CHECK))

HEADERS := inc/arr.h inc/key.h inc/mysort.h
HEADERS_CHECK := $(shell find ./$(dir_headers_check) -name "*.h")

app.exe : $(dir_out_default) $(OBJS_FUNCS_DEFAULT) $(OBJS_MAIN_DEFAULT) 
	$(CC) $(CFLAGS) $(OBJS_MAIN_DEFAULT) $(OBJS_FUNCS_DEFAULT) -o $@

unit_tests.exe : $(dir_out_default) $(dir_out_check) $(OBJS_FUNCS_DEFAULT) $(OBJS_CHECK) $(HEADERS) $(HEADERS_CHECK) 
	$(CC) $(OBJS_FUNCS_DEFAULT) $(OBJS_CHECK) $(HEADERS) $(HEADERS_CHECK) -o $@ $(CFLAGS_TEST) $(HEADERS_CHECK)

$(dir_out_default) :
	mkdir -p $(dir_out_default)

$(dir_out_check) :
	mkdir -p $(dir_out_check)

$(dir_out_check)/check_%.o : $(dir_funcs_check)/check_%.c $(dir_headers_check)/*.h $(OBJS_FUNCS_DEFAULT) $(HEADERS)
	$(CC) $(CFLAGS) -I $(dir_headers_default) -I $(dir_headers_check) -c $< -o $@

$(dir_out_default)/%.o : $(dir_funcs_default)/%.c $(dir_headers_default)/*.h
	$(CC) $(CFLAGS) -I $(dir_headers_default) -c $< -o $@

clean :
	rm -f ./*.exe ./*.gcov ./*.gcda ./*.o ./*.gcno ./*.out ./*tmp*
	rm -rf .idea

.PHOHY : clean
