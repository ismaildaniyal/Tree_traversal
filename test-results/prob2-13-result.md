(TEST 13) maze_print_state2 : ok
================================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs maze_print_state2
-------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs maze_print_state2
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                             ===ACTUAL===
IF_TEST("maze_print_state2") {                                         . IF_TEST("maze_print_state2") {
    // Creates a large-ish maze of mostly open tiles and assigns path  .     // Creates a large-ish maze of mostly open tiles and assigns path
    // lengths to open tiles before printing. Output will show         .     // lengths to open tiles before printing. Output will show
    // formating of the axis labels and digits indicating length from  .     // formating of the axis labels and digits indicating length from
    // (0,0) including printing a for 10, b for 20, c for 30 using     .     // (0,0) including printing a for 10, b for 20, c for 30 using
    // characters from the digit10_chars[] global array. START and END .     // characters from the digit10_chars[] global array. START and END
    // tiles are included but both have a path so should print the     .     // tiles are included but both have a path so should print the
    // last digit of the path length rather than S/E.                  .     // last digit of the path length rather than S/E.
    int rows=15, cols=35;                                              .     int rows=15, cols=35;
    maze_t *maze = maze_allocate(rows,cols);                           .     maze_t *maze = maze_allocate(rows,cols);
    for(int i=0; i<rows; i++){                                         .     for(int i=0; i<rows; i++){
      for(int j=0; j<cols; j++){                                       .       for(int j=0; j<cols; j++){
        if((i>0 && i==j) || i==rows-1 || j==cols-1){                   .         if((i>0 && i==j) || i==rows-1 || j==cols-1){
          maze->tiles[i][j].type = WALL;                               .           maze->tiles[i][j].type = WALL;
          maze->tiles[i][j].state = NOTFOUND;                          .           maze->tiles[i][j].state = NOTFOUND;
        }                                                              .         }
        else{                                                          .         else{
          maze->tiles[i][j].path = malloc(sizeof(direction_t)*(i+j));  .           maze->tiles[i][j].path = malloc(sizeof(direction_t)*(i+j));
          maze->tiles[i][j].path_len = i+j;                            .           maze->tiles[i][j].path_len = i+j;
          maze->tiles[i][j].type = OPEN;                               .           maze->tiles[i][j].type = OPEN;
          maze->tiles[i][j].state = FOUND;                             .           maze->tiles[i][j].state = FOUND;
        }                                                              .         }
      }                                                                .       }
    }                                                                  .     }
    maze->tiles[0][0].type = START;                                    .     maze->tiles[0][0].type = START;
    maze->tiles[rows-2][cols-2].type=END;                              .     maze->tiles[rows-2][cols-2].type=END;
    maze_print_state(maze);                                            .     maze_print_state(maze);
    maze_free(maze);                                                   .     maze_free(maze);
}                                                                      . }
---OUTPUT---                                                           . ---OUTPUT---
0123456789a123456789b123456789c123#:  0                                . 0123456789a123456789b123456789c123#:  0
1#3456789a123456789b123456789c1234#:  1                                . 1#3456789a123456789b123456789c1234#:  1
23#56789a123456789b123456789c12345#:  2                                . 23#56789a123456789b123456789c12345#:  2
345#789a123456789b123456789c123456#:  3                                . 345#789a123456789b123456789c123456#:  3
4567#9a123456789b123456789c1234567#:  4                                . 4567#9a123456789b123456789c1234567#:  4
56789#123456789b123456789c12345678#:  5                                . 56789#123456789b123456789c12345678#:  5
6789a1#3456789b123456789c123456789#:  6                                . 6789a1#3456789b123456789c123456789#:  6
789a123#56789b123456789c123456789d#:  7                                . 789a123#56789b123456789c123456789d#:  7
89a12345#789b123456789c123456789d1#:  8                                . 89a12345#789b123456789c123456789d1#:  8
9a1234567#9b123456789c123456789d12#:  9                                . 9a1234567#9b123456789c123456789d12#:  9
a123456789#123456789c123456789d123#: 10                                . a123456789#123456789c123456789d123#:  10
123456789b1#3456789c123456789d1234#: 11                                . 123456789b1#3456789c123456789d1234#:  11
23456789b123#56789c123456789d12345#: 12                                . 23456789b123#56789c123456789d12345#:  12
3456789b12345#789c123456789d123456#: 13                                . 3456789b12345#789c123456789d123456#:  13
###################################: 14                                . ###################################:  14
01234567890123456789012345678901234                                    . 01234567890123456789012345678901234
0         1         2         3                                        . 0         1         2         3    
null queue                                                             . null queue

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs maze_print_state2
which may be pasted onto a command line to run it.

```
==15473== Memcheck, a memory error detector
==15473== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15473== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15473== Command: ./test_mazesolve_funcs maze_print_state2
==15473== 
==15473== 
==15473== HEAP SUMMARY:
==15473==     in use at exit: 0 bytes in 0 blocks
==15473==   total heap usage: 480 allocs, 480 frees, 55,824 bytes allocated
==15473== 
==15473== All heap blocks were freed -- no leaks are possible
==15473== 
==15473== For lists of detected and suppressed errors, rerun with: -s
==15473== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
