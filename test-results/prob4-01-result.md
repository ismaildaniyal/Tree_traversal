(TEST 1) maze_from_small : ok
=============================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs maze_from_file_small
----------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs maze_from_file_small
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                         ===ACTUAL===
IF_TEST("maze_from_file_small") {                                  . IF_TEST("maze_from_file_small") {
    // Load a small maze from a file                               .     // Load a small maze from a file
    LOG_LEVEL = LOG_ALL;                                           .     LOG_LEVEL = LOG_ALL;
    maze_t *maze = maze_from_file("data/maze-small-twopath1.txt"); .     maze_t *maze = maze_from_file("data/maze-small-twopath1.txt");
    printf("LOADED MAZE:\n");                                      .     printf("LOADED MAZE:\n");
    maze_print_tiles(maze);                                        .     maze_print_tiles(maze);
    maze_free(maze);                                               .     maze_free(maze);
}                                                                  . }
---OUTPUT---                                                       . ---OUTPUT---
LOG: expecting 5 rows and 5 columns                                . LOG: expecting 5 rows and 5 columns
LOG: beginning to read tiles                                       . LOG: beginning to read tiles
LOG: (0,0) has character '#' type 1                                . LOG: (0,0) has character '#' type 1
LOG: (0,1) has character '#' type 1                                . LOG: (0,1) has character '#' type 1
LOG: (0,2) has character '#' type 1                                . LOG: (0,2) has character '#' type 1
LOG: (0,3) has character '#' type 1                                . LOG: (0,3) has character '#' type 1
LOG: (0,4) has character '#' type 1                                . LOG: (0,4) has character '#' type 1
LOG: finished reading row 0 of tiles                               . LOG: finished reading row 0 of tiles
LOG: (1,0) has character '#' type 1                                . LOG: (1,0) has character '#' type 1
LOG: (1,1) has character ' ' type 2                                . LOG: (1,1) has character ' ' type 2
LOG: (1,2) has character 'S' type 4                                . LOG: (1,2) has character 'S' type 4
LOG: setting START at (1,2)                                        . LOG: setting START at (1,2)
LOG: (1,3) has character ' ' type 2                                . LOG: (1,3) has character ' ' type 2
LOG: (1,4) has character '#' type 1                                . LOG: (1,4) has character '#' type 1
LOG: finished reading row 1 of tiles                               . LOG: finished reading row 1 of tiles
LOG: (2,0) has character '#' type 1                                . LOG: (2,0) has character '#' type 1
LOG: (2,1) has character ' ' type 2                                . LOG: (2,1) has character ' ' type 2
LOG: (2,2) has character '#' type 1                                . LOG: (2,2) has character '#' type 1
LOG: (2,3) has character ' ' type 2                                . LOG: (2,3) has character ' ' type 2
LOG: (2,4) has character '#' type 1                                . LOG: (2,4) has character '#' type 1
LOG: finished reading row 2 of tiles                               . LOG: finished reading row 2 of tiles
LOG: (3,0) has character '#' type 1                                . LOG: (3,0) has character '#' type 1
LOG: (3,1) has character ' ' type 2                                . LOG: (3,1) has character ' ' type 2
LOG: (3,2) has character 'E' type 5                                . LOG: (3,2) has character 'E' type 5
LOG: setting END at (3,2)                                          . LOG: setting END at (3,2)
LOG: (3,3) has character ' ' type 2                                . LOG: (3,3) has character ' ' type 2
LOG: (3,4) has character '#' type 1                                . LOG: (3,4) has character '#' type 1
LOG: finished reading row 3 of tiles                               . LOG: finished reading row 3 of tiles
LOG: (4,0) has character '#' type 1                                . LOG: (4,0) has character '#' type 1
LOG: (4,1) has character '#' type 1                                . LOG: (4,1) has character '#' type 1
LOG: (4,2) has character '#' type 1                                . LOG: (4,2) has character '#' type 1
LOG: (4,3) has character '#' type 1                                . LOG: (4,3) has character '#' type 1
LOG: (4,4) has character '#' type 1                                . LOG: (4,4) has character '#' type 1
LOG: finished reading row 4 of tiles                               . LOG: finished reading row 4 of tiles
LOADED MAZE:                                                       . LOADED MAZE:
maze: 5 rows 5 cols                                                . maze: 5 rows 5 cols
      (1,2) start                                                  .       (1,2) start
      (3,2) end                                                    .       (3,2) end
maze tiles:                                                        . maze tiles:
#####                                                              . #####
# S #                                                              . # S #
# # #                                                              . # # #
# E #                                                              . # E #
#####                                                              . #####
                                                                   ) 

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs maze_from_file_small
which may be pasted onto a command line to run it.

```
==15602== Memcheck, a memory error detector
==15602== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15602== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15602== Command: ./test_mazesolve_funcs maze_from_file_small
==15602== 
==15602== 
==15602== HEAP SUMMARY:
==15602==     in use at exit: 0 bytes in 0 blocks
==15602==   total heap usage: 9 allocs, 9 frees, 5,248 bytes allocated
==15602== 
==15602== All heap blocks were freed -- no leaks are possible
==15602== 
==15602== For lists of detected and suppressed errors, rerun with: -s
==15602== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
