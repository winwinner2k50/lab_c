#include <stdio.h>
#include <string.h>
#include "str_io.h"

int main()
{
  char str[] = "QQQQ";
 
  // поиск первого вхождения в строку str любого из символов строки keys
  char *pch = my_strrchr(str, 0);

  printf("%p\n", pch);
  printf("%p", str + 4);          // позиция найденной цифры
  return 0;
}