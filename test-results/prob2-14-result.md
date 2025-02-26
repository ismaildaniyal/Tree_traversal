(TEST 14) maze_print_state3 : ok
================================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs maze_print_state3
-------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs maze_print_state3
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                             ===ACTUAL===
IF_TEST("maze_print_state3") {                                         . IF_TEST("maze_print_state3") {
    // Prints prints the state of a maze that has no paths set in      .     // Prints prints the state of a maze that has no paths set in
    // it. This should look identical to the output of                 .     // it. This should look identical to the output of
    // maze_print_tiles() except that the header information is not    .     // maze_print_tiles() except that the header information is not
    // present and axis labels are printed. No numbers appear as there .     // present and axis labels are printed. No numbers appear as there
    // are no paths set in the maze.                                   .     // are no paths set in the maze.
    char *maze_str =                                                   .     char *maze_str =
      "################\n"                                             .       "################\n"
      "#S             #\n"                                             .       "#S             #\n"
      "# ### ###### # #\n"                                             .       "# ### ###### # #\n"
      "# ### ##E  #   #\n"                                             .       "# ### ##E  #   #\n"
      "# ### #### ##  #\n"                                             .       "# ### #### ##  #\n"
      "#              #\n"                                             .       "#              #\n"
      "################\n";                                            .       "################\n";
    maze_t *maze = maze_from_string(maze_str);                         .     maze_t *maze = maze_from_string(maze_str);
    printf("PRINTING STATE WITH NO PATHS:\n");                         .     printf("PRINTING STATE WITH NO PATHS:\n");
    maze_print_state(maze);                                            .     maze_print_state(maze);
    maze_free(maze);                                                   .     maze_free(maze);
    maze_str =                                                         .     maze_str =
      "################\n"                                             .       "################\n"
      "#S             #\n"                                             .       "#S             #\n"
      "#.### ###### # #\n"                                             .       "#.### ###### # #\n"
      "#.### ##E..#   #\n"                                             .       "#.### ##E..#   #\n"
      "#.### ####.##  #\n"                                             .       "#.### ####.##  #\n"
      "#..........    #\n"                                             .       "#..........    #\n"
      "################\n";                                            .       "################\n";
    maze = maze_from_string(maze_str);                                 .     maze = maze_from_string(maze_str);
    printf("PRINTING STATE WITH NO PATHS:\n");                         .     printf("PRINTING STATE WITH NO PATHS:\n");
    maze_print_state(maze);                                            .     maze_print_state(maze);
    maze_free(maze);                                                   .     maze_free(maze);
}                                                                      . }
---OUTPUT---                                                           . ---OUTPUT---
PRINTING STATE WITH NO PATHS:                                          . PRINTING STATE WITH NO PATHS:
################:  0                                                   . ################:  0
#S             #:  1                                                   . #S             #:  1
# ### ###### # #:  2                                                   . # ### ###### # #:  2
# ### ##E  #   #:  3                                                   . # ### ##E  #   #:  3
# ### #### ##  #:  4                                                   . # ### #### ##  #:  4
#              #:  5                                                   . #              #:  5
################:  6                                                   . ################:  6
0123456789012345                                                       . 0123456789012345
0         1                                                            . 0         1     
null queue                                                             . null queue
PRINTING STATE WITH NO PATHS:                                          . PRINTING STATE WITH NO PATHS:
################:  0                                                   . ################:  0
#S             #:  1                                                   . #S             #:  1
#.### ###### # #:  2                                                   . #.### ###### # #:  2
#.### ##E..#   #:  3                                                   . #.### ##E..#   #:  3
#.### ####.##  #:  4                                                   . #.### ####.##  #:  4
#..........    #:  5                                                   . #..........    #:  5
################:  6                                                   . ################:  6
0123456789012345                                                       . 0123456789012345
0         1                                                            . 0         1     
null queue                                                             . null queue

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs maze_print_state3
which may be pasted onto a command line to run it.

```
==15474== Memcheck, a memory error detector
==15474== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15474== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15474== Command: ./test_mazesolve_funcs maze_print_state3
==15474== 
==15474== 
==15474== HEAP SUMMARY:
==15474==     in use at exit: 0 bytes in 0 blocks
==15474==   total heap usage: 18 allocs, 18 frees, 5,568 bytes allocated
==15474== 
==15474== All heap blocks were freed -- no leaks are possible
==15474== 
==15474== For lists of detected and suppressed errors, rerun with: -s
==15474== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
