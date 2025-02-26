(TEST 10) maze_print_tiles2 : ok
================================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs maze_print_tiles2
-------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs maze_print_tiles2
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                             ===ACTUAL===
IF_TEST("maze_print_tiles2") {                                         . IF_TEST("maze_print_tiles2") {
    // Prints a maze that is created from a string. A complete path of .     // Prints a maze that is created from a string. A complete path of
    // ONPATH tiles from START to END is present.                      .     // ONPATH tiles from START to END is present.
    char *maze_str =                                                   .     char *maze_str =
      "################\n"                                             .       "################\n"
      "#S             #\n"                                             .       "#S             #\n"
      "#.### ###### # #\n"                                             .       "#.### ###### # #\n"
      "#.### ##E..#   #\n"                                             .       "#.### ##E..#   #\n"
      "#.### ####.##  #\n"                                             .       "#.### ####.##  #\n"
      "#..........    #\n"                                             .       "#..........    #\n"
      "################\n";                                            .       "################\n";
    maze_t *maze = maze_from_string(maze_str);                         .     maze_t *maze = maze_from_string(maze_str);
    printf("PRINTING TILES:\n");                                       .     printf("PRINTING TILES:\n");
    maze_print_tiles(maze);                                            .     maze_print_tiles(maze);
    maze_free(maze);                                                   .     maze_free(maze);
}                                                                      . }
---OUTPUT---                                                           . ---OUTPUT---
PRINTING TILES:                                                        . PRINTING TILES:
maze: 7 rows 16 cols                                                   . maze: 7 rows 16 cols
      (1,1) start                                                      .       (1,1) start
      (3,8) end                                                        .       (3,8) end
maze tiles:                                                            . maze tiles:
################                                                       . ################
#S             #                                                       . #S             #
#.### ###### # #                                                       . #.### ###### # #
#.### ##E..#   #                                                       . #.### ##E..#   #
#.### ####.##  #                                                       . #.### ####.##  #
#..........    #                                                       . #..........    #
################                                                       . ################
                                                                       ) 

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs maze_print_tiles2
which may be pasted onto a command line to run it.

```
==15466== Memcheck, a memory error detector
==15466== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15466== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15466== Command: ./test_mazesolve_funcs maze_print_tiles2
==15466== 
==15466== 
==15466== HEAP SUMMARY:
==15466==     in use at exit: 0 bytes in 0 blocks
==15466==   total heap usage: 9 allocs, 9 frees, 2,784 bytes allocated
==15466== 
==15466== All heap blocks were freed -- no leaks are possible
==15466== 
==15466== For lists of detected and suppressed errors, rerun with: -s
==15466== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
