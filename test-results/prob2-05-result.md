(TEST 5) maze_allocate_free1 : ok
=================================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs maze_allocate_free1
---------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs maze_allocate_free1
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                               ===ACTUAL===
IF_TEST("maze_allocate_free1") {                         . IF_TEST("maze_allocate_free1") {
    int rows=3, cols=5;                                  .     int rows=3, cols=5;
    maze_t *maze = maze_allocate(rows,cols);             .     maze_t *maze = maze_allocate(rows,cols);
    printf("maze->rows: %d\n",maze->rows);               .     printf("maze->rows: %d\n",maze->rows);
    printf("maze->cols: %d\n",maze->cols);               .     printf("maze->cols: %d\n",maze->cols);
    printf("maze->start_row: %d\n",maze->start_row);     .     printf("maze->start_row: %d\n",maze->start_row);
    printf("maze->start_col: %d\n",maze->start_col);     .     printf("maze->start_col: %d\n",maze->start_col);
    printf("maze->end_row: %d\n",maze->end_row);         .     printf("maze->end_row: %d\n",maze->end_row);
    printf("maze->end_col: %d\n",maze->end_col);         .     printf("maze->end_col: %d\n",maze->end_col);
    printf("maze->queue: %p\n",maze->queue);             .     printf("maze->queue: %p\n",maze->queue);
    for(int i=0; i<rows; i++){                           .     for(int i=0; i<rows; i++){
      for(int j=0; j<cols; j++){                         .       for(int j=0; j<cols; j++){
        printf("maze->tiles[%d][%d]: ",i,j);             .         printf("maze->tiles[%d][%d]: ",i,j);
        tile_t *tile = &maze->tiles[i][j];               .         tile_t *tile = &maze->tiles[i][j];
        printf("type %d state %d path_len %d path %p\n", .         printf("type %d state %d path_len %d path %p\n",
               tile->type, tile->state,                  .                tile->type, tile->state,
               tile->path_len, tile->path);              .                tile->path_len, tile->path);
      }                                                  .       }
    }                                                    .     }
    maze_free(maze);                                     .     maze_free(maze);
}                                                        . }
---OUTPUT---                                             . ---OUTPUT---
maze->rows: 3                                            . maze->rows: 3
maze->cols: 5                                            . maze->cols: 5
maze->start_row: -1                                      . maze->start_row: -1
maze->start_col: -1                                      . maze->start_col: -1
maze->end_row: -1                                        . maze->end_row: -1
maze->end_col: -1                                        . maze->end_col: -1
maze->queue: (nil)                                       . maze->queue: (nil)
maze->tiles[0][0]: type 0 state 1 path_len -1 path (nil) . maze->tiles[0][0]: type 0 state 1 path_len -1 path (nil)
maze->tiles[0][1]: type 0 state 1 path_len -1 path (nil) . maze->tiles[0][1]: type 0 state 1 path_len -1 path (nil)
maze->tiles[0][2]: type 0 state 1 path_len -1 path (nil) . maze->tiles[0][2]: type 0 state 1 path_len -1 path (nil)
maze->tiles[0][3]: type 0 state 1 path_len -1 path (nil) . maze->tiles[0][3]: type 0 state 1 path_len -1 path (nil)
maze->tiles[0][4]: type 0 state 1 path_len -1 path (nil) . maze->tiles[0][4]: type 0 state 1 path_len -1 path (nil)
maze->tiles[1][0]: type 0 state 1 path_len -1 path (nil) . maze->tiles[1][0]: type 0 state 1 path_len -1 path (nil)
maze->tiles[1][1]: type 0 state 1 path_len -1 path (nil) . maze->tiles[1][1]: type 0 state 1 path_len -1 path (nil)
maze->tiles[1][2]: type 0 state 1 path_len -1 path (nil) . maze->tiles[1][2]: type 0 state 1 path_len -1 path (nil)
maze->tiles[1][3]: type 0 state 1 path_len -1 path (nil) . maze->tiles[1][3]: type 0 state 1 path_len -1 path (nil)
maze->tiles[1][4]: type 0 state 1 path_len -1 path (nil) . maze->tiles[1][4]: type 0 state 1 path_len -1 path (nil)
maze->tiles[2][0]: type 0 state 1 path_len -1 path (nil) . maze->tiles[2][0]: type 0 state 1 path_len -1 path (nil)
maze->tiles[2][1]: type 0 state 1 path_len -1 path (nil) . maze->tiles[2][1]: type 0 state 1 path_len -1 path (nil)
maze->tiles[2][2]: type 0 state 1 path_len -1 path (nil) . maze->tiles[2][2]: type 0 state 1 path_len -1 path (nil)
maze->tiles[2][3]: type 0 state 1 path_len -1 path (nil) . maze->tiles[2][3]: type 0 state 1 path_len -1 path (nil)
maze->tiles[2][4]: type 0 state 1 path_len -1 path (nil) . maze->tiles[2][4]: type 0 state 1 path_len -1 path (nil)

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs maze_allocate_free1
which may be pasted onto a command line to run it.

```
==15440== Memcheck, a memory error detector
==15440== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15440== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15440== Command: ./test_mazesolve_funcs maze_allocate_free1
==15440== 
==15440== 
==15440== HEAP SUMMARY:
==15440==     in use at exit: 0 bytes in 0 blocks
==15440==   total heap usage: 5 allocs, 5 frees, 424 bytes allocated
==15440== 
==15440== All heap blocks were freed -- no leaks are possible
==15440== 
==15440== For lists of detected and suppressed errors, rerun with: -s
==15440== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
