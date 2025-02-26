(TEST 1) maze_bfs_init1 : ok
============================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs maze_bfs_init1
----------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs maze_bfs_init1
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                           ===ACTUAL===
IF_TEST("maze_bfs_init1") {                                          . IF_TEST("maze_bfs_init1") {
    // Initialize a maze for BFS search and print the resulting      .     // Initialize a maze for BFS search and print the resulting
    // state. Logging is enabled so the initialization function will .     // state. Logging is enabled so the initialization function will
    // produce some output.                                          .     // produce some output.
    char *maze_str =                                                 .     char *maze_str =
      "################\n"                                           .       "################\n"
      "#S             #\n"                                           .       "#S             #\n"
      "# ### ###### # #\n"                                           .       "# ### ###### # #\n"
      "# ### ##E  #   #\n"                                           .       "# ### ##E  #   #\n"
      "# ### #### ##  #\n"                                           .       "# ### #### ##  #\n"
      "#              #\n"                                           .       "#              #\n"
      "################\n";                                          .       "################\n";
    maze_t *maze = maze_from_string(maze_str);                       .     maze_t *maze = maze_from_string(maze_str);
    LOG_LEVEL = LOG_ALL;                                             .     LOG_LEVEL = LOG_ALL;
    printf("Maze BEFORE bfs_init()\n");                              .     printf("Maze BEFORE bfs_init()\n");
    maze_print_state(maze);                                          .     maze_print_state(maze);
    maze_bfs_init(maze);                                             .     maze_bfs_init(maze);
    printf("Maze AFTER bfs_init()\n");                               .     printf("Maze AFTER bfs_init()\n");
    maze_print_state(maze);                                          .     maze_print_state(maze);
    maze_free(maze);                                                 .     maze_free(maze);
}                                                                    . }
---OUTPUT---                                                         . ---OUTPUT---
Maze BEFORE bfs_init()                                               . Maze BEFORE bfs_init()
################:  0                                                 . ################:  0
#S             #:  1                                                 . #S             #:  1
# ### ###### # #:  2                                                 . # ### ###### # #:  2
# ### ##E  #   #:  3                                                 . # ### ##E  #   #:  3
# ### #### ##  #:  4                                                 . # ### #### ##  #:  4
#              #:  5                                                 . #              #:  5
################:  6                                                 . ################:  6
0123456789012345                                                     . 0123456789012345
0         1                                                          . 0         1     
null queue                                                           . null queue
LOG: BFS initialization complete                                     . LOG: BFS initialization complete
################:  0                                                 . ################:  0
#0             #:  1                                                 . #0             #:  1
# ### ###### # #:  2                                                 . # ### ###### # #:  2
# ### ##E  #   #:  3                                                 . # ### ##E  #   #:  3
# ### #### ##  #:  4                                                 . # ### #### ##  #:  4
#              #:  5                                                 . #              #:  5
################:  6                                                 . ################:  6
0123456789012345                                                     . 0123456789012345
0         1                                                          . 0         1     
queue count: 1                                                       . queue count: 1
NN ROW COL                                                           . NN ROW COL
 0   1   1                                                           .  0   1   1
Maze AFTER bfs_init()                                                . Maze AFTER bfs_init()
################:  0                                                 . ################:  0
#0             #:  1                                                 . #0             #:  1
# ### ###### # #:  2                                                 . # ### ###### # #:  2
# ### ##E  #   #:  3                                                 . # ### ##E  #   #:  3
# ### #### ##  #:  4                                                 . # ### #### ##  #:  4
#              #:  5                                                 . #              #:  5
################:  6                                                 . ################:  6
0123456789012345                                                     . 0123456789012345
0         1                                                          . 0         1     
queue count: 1                                                       . queue count: 1
NN ROW COL                                                           . NN ROW COL
 0   1   1                                                           .  0   1   1

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs maze_bfs_init1
which may be pasted onto a command line to run it.

```
==15518== Memcheck, a memory error detector
==15518== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15518== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15518== Command: ./test_mazesolve_funcs maze_bfs_init1
==15518== 
==15518== 
==15518== HEAP SUMMARY:
==15518==     in use at exit: 0 bytes in 0 blocks
==15518==   total heap usage: 12 allocs, 12 frees, 2,828 bytes allocated
==15518== 
==15518== All heap blocks were freed -- no leaks are possible
==15518== 
==15518== For lists of detected and suppressed errors, rerun with: -s
==15518== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
