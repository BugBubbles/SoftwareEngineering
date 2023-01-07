#include "common.h"
#include <windows.h>
// #include "gui.h"
// #include "interpret.h"
// compiled under MSVC, plain char[char] is unsigned.
int main()
{
  /*cli_result res = cli_handler("line 1 10 20 30 50");
  printf("%d\n", res);
  res = cli_handler("square 0 40 40 30 1");
  printf("%d\n", res);
  res = cli_handler("circ 2 80 30 20");
  printf("%d\n", res);
  res = cli_handler("triangle 3 35 40 50 20 100 60");
  printf("%d\n", res);
  res = cli_handler("draw");
  printf("%d\n", res);
  res = cli_handler("colorrev");
  printf("%d\n", res);
  gui_export_ram_source("../../cbj0.c");
  gui_export_ram_binary("../../cbj0.bin");*/
  HINSTANCE hinst = LoadLibraryA("cbj1.dll");
  if (hinst)
  {
    char(__cdecl * cli_handler)(char *cmd) = (void *)GetProcAddress(hinst, "cli_handler");
    char res = cli_handler("line 1 10 20 30 50");
    printf("%d\n", res);
    res = cli_handler("square 0 40 40 30 1");
    printf("%d\n", res);
    res = cli_handler("circ 2 80 30 20");
    printf("%d\n", res);
    res = cli_handler("triangle 3 35 40 50 20 100 60");
    printf("%d\n", res);
    res = cli_handler("draw");
    printf("%d\n", res);
    res = cli_handler("colorrev");
    printf("%d\n", res);
    res = cli_handler("export");
    printf("%d\n", res);
    FreeLibrary(hinst);
  }
  system("pause");
  return 0;
}