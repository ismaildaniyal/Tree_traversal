(TEST 3) tile_extend_path1 : ok
===============================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs tile_extend_path1
-------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs tile_extend_path1
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                          ===ACTUAL===
IF_TEST("tile_extend_path1") {                                      . IF_TEST("tile_extend_path1") {
    // Check that the path from one tile can be extended to another .     // Check that the path from one tile can be extended to another
    direction_t *src_path = malloc(sizeof(direction_t)*5);          .     direction_t *src_path = malloc(sizeof(direction_t)*5);
    src_path[0] = NORTH;        // heap-allocated for bounds        .     src_path[0] = NORTH;        // heap-allocated for bounds
    src_path[1] = EAST;         // checking in valgrind             .     src_path[1] = EAST;         // checking in valgrind
    src_path[2] = EAST;                                             .     src_path[2] = EAST;
    src_path[3] = SOUTH;                                            .     src_path[3] = SOUTH;
    src_path[4] = SOUTH;                                            .     src_path[4] = SOUTH;
    tile_t src = {.type=OPEN, .path_len= 5, .path=src_path};        .     tile_t src = {.type=OPEN, .path_len= 5, .path=src_path};
    tile_t dst = {.type=OPEN, .path_len=-1, .path=NULL};            .     tile_t dst = {.type=OPEN, .path_len=-1, .path=NULL};
    tile_extend_path(&src,&dst,WEST);                               .     tile_extend_path(&src,&dst,WEST);
    tile_print_path(&dst, PATH_FORMAT_VERBOSE);                     .     tile_print_path(&dst, PATH_FORMAT_VERBOSE);
    printf("COMPACT: {");                                           .     printf("COMPACT: {");
    tile_print_path(&dst, PATH_FORMAT_COMPACT);                     .     tile_print_path(&dst, PATH_FORMAT_COMPACT);
    printf("}\n");                                                  .     printf("}\n");
    free(dst.path); free(src_path);                                 .     free(dst.path); free(src_path);
}                                                                   . }
---OUTPUT---                                                        . ---OUTPUT---
path length: 6                                                      . path length: 6
 0: NORTH                                                           .   0: NORTH
 1: EAST                                                            .   1: EAST
 2: EAST                                                            .   2: EAST
 3: SOUTH                                                           .   3: SOUTH
 4: SOUTH                                                           .   4: SOUTH
 5: WEST                                                            .   5: WEST
COMPACT: {NEESSW}                                                   . COMPACT: {NEESSW}

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs tile_extend_path1
which may be pasted onto a command line to run it.

```
==15437== Memcheck, a memory error detector
==15437== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15437== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15437== Command: ./test_mazesolve_funcs tile_extend_path1
==15437== 
==15437== 
==15437== HEAP SUMMARY:
==15437==     in use at exit: 0 bytes in 0 blocks
==15437==   total heap usage: 2 allocs, 2 frees, 44 bytes allocated
==15437== 
==15437== All heap blocks were freed -- no leaks are possible
==15437== 
==15437== For lists of detected and suppressed errors, rerun with: -s
==15437== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
