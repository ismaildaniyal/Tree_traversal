(TEST 1) tile_print_path1 : ok
==============================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs tile_print_path1
------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs tile_print_path1
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                           ===ACTUAL===
IF_TEST("tile_print_path1") {                                        . IF_TEST("tile_print_path1") {
    // Checks that the VERBOSE and COMPACT format for printing paths .     // Checks that the VERBOSE and COMPACT format for printing paths
    // (arrays of directions) is correct.                            .     // (arrays of directions) is correct.
    direction_t *path = malloc(sizeof(direction_t)*6);               .     direction_t *path = malloc(sizeof(direction_t)*6);
    path[0] = NORTH;        // heap-allocated for bounds             .     path[0] = NORTH;        // heap-allocated for bounds
    path[1] = EAST;         // checking in valgrind                  .     path[1] = EAST;         // checking in valgrind
    path[2] = EAST;                                                  .     path[2] = EAST;
    path[3] = SOUTH;                                                 .     path[3] = SOUTH;
    path[4] = SOUTH;                                                 .     path[4] = SOUTH;
    path[5] = WEST;                                                  .     path[5] = WEST;
    tile_t tile = {.type=OPEN, .path_len= 6, .path=path};            .     tile_t tile = {.type=OPEN, .path_len= 6, .path=path};
    printf("VERBOSE FORMAT:\n");                                     .     printf("VERBOSE FORMAT:\n");
    tile_print_path(&tile, PATH_FORMAT_VERBOSE);                     .     tile_print_path(&tile, PATH_FORMAT_VERBOSE);
    printf("COMPACT FORMAT: {");                                     .     printf("COMPACT FORMAT: {");
    tile_print_path(&tile, PATH_FORMAT_COMPACT);                     .     tile_print_path(&tile, PATH_FORMAT_COMPACT);
    printf("}\n");                                                   .     printf("}\n");
    free(path);                                                      .     free(path);
}                                                                    . }
---OUTPUT---                                                         . ---OUTPUT---
VERBOSE FORMAT:                                                      . VERBOSE FORMAT:
path length: 6                                                       . path length: 6
 0: NORTH                                                            .   0: NORTH
 1: EAST                                                             .   1: EAST
 2: EAST                                                             .   2: EAST
 3: SOUTH                                                            .   3: SOUTH
 4: SOUTH                                                            .   4: SOUTH
 5: WEST                                                             .   5: WEST
COMPACT FORMAT: {NEESSW}                                             . COMPACT FORMAT: {NEESSW}

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs tile_print_path1
which may be pasted onto a command line to run it.

```
==15436== Memcheck, a memory error detector
==15436== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15436== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15436== Command: ./test_mazesolve_funcs tile_print_path1
==15436== 
==15436== 
==15436== HEAP SUMMARY:
==15436==     in use at exit: 0 bytes in 0 blocks
==15436==   total heap usage: 1 allocs, 1 frees, 24 bytes allocated
==15436== 
==15436== All heap blocks were freed -- no leaks are possible
==15436== 
==15436== For lists of detected and suppressed errors, rerun with: -s
==15436== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
