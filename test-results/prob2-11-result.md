(TEST 11) maze_print_tiles3 : ok
================================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs maze_print_tiles3
-------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs maze_print_tiles3
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                       ===ACTUAL===
IF_TEST("maze_print_tiles3") {                                   . IF_TEST("maze_print_tiles3") {
    // Prints a maze with tiles that are determined from raw     .     // Prints a maze with tiles that are determined from raw
    // structs. The maze includes most tile types that should be .     // structs. The maze includes most tile types that should be
    // printed normally.                                         .     // printed normally.
    tile_t rows[5][3] = {                                        .     tile_t rows[5][3] = {
      { {.type=WALL},{.type=WALL},  {.type=START} },// 0         .       { {.type=WALL},{.type=WALL},  {.type=START} },// 0
      { {.type=OPEN},{.type=ONPATH},{.type=ONPATH}},// 1         .       { {.type=OPEN},{.type=ONPATH},{.type=ONPATH}},// 1
      { {.type=END}, {.type=OPEN},  {.type=WALL}  },// 2         .       { {.type=END}, {.type=OPEN},  {.type=WALL}  },// 2
      { {.type=WALL},{.type=OPEN},  {.type=WALL}  },// 3         .       { {.type=WALL},{.type=OPEN},  {.type=WALL}  },// 3
      { {.type=OPEN},{.type=OPEN},  {.type=OPEN}  },// 4         .       { {.type=OPEN},{.type=OPEN},  {.type=OPEN}  },// 4
      //     0            1             2                        .       //     0            1             2
    };                                                           .     };
    tile_t *tiles[5] =                                           .     tile_t *tiles[5] =
      {rows[0],rows[1],rows[2],rows[3],rows[4]};                 .       {rows[0],rows[1],rows[2],rows[3],rows[4]};
    maze_t maze = {.rows=5, .cols=3, .tiles=tiles};              .     maze_t maze = {.rows=5, .cols=3, .tiles=tiles};
    printf("PRINTING TILES:\n");                                 .     printf("PRINTING TILES:\n");
    maze_print_tiles(&maze);                                     .     maze_print_tiles(&maze);
}                                                                . }
---OUTPUT---                                                     . ---OUTPUT---
PRINTING TILES:                                                  . PRINTING TILES:
maze: 5 rows 3 cols                                              . maze: 5 rows 3 cols
      (0,0) start                                                .       (0,0) start
      (0,0) end                                                  .       (0,0) end
maze tiles:                                                      . maze tiles:
##S                                                              . ##S
 ..                                                              .  ..
E #                                                              . E #
# #                                                              . # #
                                                                 .    
                                                                 ) 

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs maze_print_tiles3
which may be pasted onto a command line to run it.

```
==15468== Memcheck, a memory error detector
==15468== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15468== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15468== Command: ./test_mazesolve_funcs maze_print_tiles3
==15468== 
==15468== 
==15468== HEAP SUMMARY:
==15468==     in use at exit: 0 bytes in 0 blocks
==15468==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==15468== 
==15468== All heap blocks were freed -- no leaks are possible
==15468== 
==15468== For lists of detected and suppressed errors, rerun with: -s
==15468== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
