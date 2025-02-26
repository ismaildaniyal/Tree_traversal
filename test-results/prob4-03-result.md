(TEST 3) maze_from_file_no_file : ok
====================================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs maze_from_file_no_file
------------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs maze_from_file_no_file
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                            ===ACTUAL===
IF_TEST("maze_from_file_no_file") {                                   . IF_TEST("maze_from_file_no_file") {
    // Intentionally try to load a file that does not exist to ensure .     // Intentionally try to load a file that does not exist to ensure
    // that NULL is returned.                                         .     // that NULL is returned.
    LOG_LEVEL = LOG_ALL;                                              .     LOG_LEVEL = LOG_ALL;
    maze_t *maze = maze_from_file("data/no-such-maze.txt");           .     maze_t *maze = maze_from_file("data/no-such-maze.txt");
    printf("maze: %p\n",maze);                                        .     printf("maze: %p\n",maze);
}                                                                     . }
---OUTPUT---                                                          . ---OUTPUT---
ERROR: could not open file data/no-such-maze.txt                      . ERROR: could not open file data/no-such-maze.txt
maze: (nil)                                                           . maze: (nil)

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs maze_from_file_no_file
which may be pasted onto a command line to run it.

```
==15601== Memcheck, a memory error detector
==15601== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15601== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15601== Command: ./test_mazesolve_funcs maze_from_file_no_file
==15601== 
==15601== 
==15601== HEAP SUMMARY:
==15601==     in use at exit: 0 bytes in 0 blocks
==15601==   total heap usage: 1 allocs, 1 frees, 472 bytes allocated
==15601== 
==15601== All heap blocks were freed -- no leaks are possible
==15601== 
==15601== For lists of detected and suppressed errors, rerun with: -s
==15601== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
