(TEST 2) tile_print_path2 : ok
==============================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs tile_print_path2
------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs tile_print_path2
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                            ===ACTUAL===
IF_TEST("tile_print_path2") {                                         . IF_TEST("tile_print_path2") {
    // Check special cases of printing a length-0 path and printing a .     // Check special cases of printing a length-0 path and printing a
    // NULL path.                                                     .     // NULL path.
    printf("Length 0 path\n");                                        .     printf("Length 0 path\n");
    direction_t *path = malloc(sizeof(direction_t)*0);                .     direction_t *path = malloc(sizeof(direction_t)*0);
    tile_t tile = {.type=START, .path_len= 0, .path=path};            .     tile_t tile = {.type=START, .path_len= 0, .path=path};
    printf("VERBOSE FORMAT:\n");                                      .     printf("VERBOSE FORMAT:\n");
    tile_print_path(&tile, PATH_FORMAT_VERBOSE);                      .     tile_print_path(&tile, PATH_FORMAT_VERBOSE);
    printf("COMPACT FORMAT: {");                                      .     printf("COMPACT FORMAT: {");
    tile_print_path(&tile, PATH_FORMAT_COMPACT);                      .     tile_print_path(&tile, PATH_FORMAT_COMPACT);
    printf("}\n");                                                    .     printf("}\n");
    free(path);                                                       .     free(path);
    printf("NULL path\n");                                            .     printf("NULL path\n");
    tile.path_len = -1;                                               .     tile.path_len = -1;
    tile.path = NULL;                                                 .     tile.path = NULL;
    printf("VERBOSE FORMAT:\n");                                      .     printf("VERBOSE FORMAT:\n");
    tile_print_path(&tile, PATH_FORMAT_VERBOSE);                      .     tile_print_path(&tile, PATH_FORMAT_VERBOSE);
    printf("COMPACT FORMAT:\n");                                      .     printf("COMPACT FORMAT:\n");
    tile_print_path(&tile, PATH_FORMAT_COMPACT);                      .     tile_print_path(&tile, PATH_FORMAT_COMPACT);
    printf("\n");                                                     .     printf("\n");
}                                                                     . }
---OUTPUT---                                                          . ---OUTPUT---
Length 0 path                                                         . Length 0 path
VERBOSE FORMAT:                                                       . VERBOSE FORMAT:
path length: 0                                                        . path length: 0
COMPACT FORMAT: {}                                                    . COMPACT FORMAT: {}
NULL path                                                             . NULL path
VERBOSE FORMAT:                                                       . VERBOSE FORMAT:
No path found                                                         . No path found
COMPACT FORMAT:                                                       . COMPACT FORMAT:
No path found                                                         . No path found
                                                                      . 

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs tile_print_path2
which may be pasted onto a command line to run it.

```
==15438== Memcheck, a memory error detector
==15438== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15438== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15438== Command: ./test_mazesolve_funcs tile_print_path2
==15438== 
==15438== 
==15438== HEAP SUMMARY:
==15438==     in use at exit: 0 bytes in 0 blocks
==15438==   total heap usage: 1 allocs, 1 frees, 0 bytes allocated
==15438== 
==15438== All heap blocks were freed -- no leaks are possible
==15438== 
==15438== For lists of detected and suppressed errors, rerun with: -s
==15438== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
