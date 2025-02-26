(TEST 4) tile_extend_path2 : ok
===============================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs tile_extend_path2
-------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs tile_extend_path2
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                        ===ACTUAL===
IF_TEST("tile_extend_path2") {                                    . IF_TEST("tile_extend_path2") {
    // Checks special case of path extension from a 0-length path .     // Checks special case of path extension from a 0-length path
    // which applies to the Start tile and its neighbors.         .     // which applies to the Start tile and its neighbors.
    direction_t *src_path =          // heap-allocated for bounds .     direction_t *src_path =          // heap-allocated for bounds
      malloc(sizeof(direction_t)*0); // checking in valgrind      .       malloc(sizeof(direction_t)*0); // checking in valgrind
    tile_t src = {.type=START, .path_len= 0, .path=src_path};     .     tile_t src = {.type=START, .path_len= 0, .path=src_path};
    tile_t dst = {.type=OPEN,  .path_len=-1, .path=NULL};         .     tile_t dst = {.type=OPEN,  .path_len=-1, .path=NULL};
    tile_extend_path(&src,&dst,NORTH);                            .     tile_extend_path(&src,&dst,NORTH);
    tile_print_path(&dst, PATH_FORMAT_VERBOSE);                   .     tile_print_path(&dst, PATH_FORMAT_VERBOSE);
    free(dst.path); free(src_path);                               .     free(dst.path); free(src_path);
}                                                                 . }
---OUTPUT---                                                      . ---OUTPUT---
path length: 1                                                    . path length: 1
 0: NORTH                                                         .   0: NORTH

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs tile_extend_path2
which may be pasted onto a command line to run it.

```
==15439== Memcheck, a memory error detector
==15439== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15439== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15439== Command: ./test_mazesolve_funcs tile_extend_path2
==15439== 
==15439== 
==15439== HEAP SUMMARY:
==15439==     in use at exit: 0 bytes in 0 blocks
==15439==   total heap usage: 2 allocs, 2 frees, 4 bytes allocated
==15439== 
==15439== All heap blocks were freed -- no leaks are possible
==15439== 
==15439== For lists of detected and suppressed errors, rerun with: -s
==15439== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
