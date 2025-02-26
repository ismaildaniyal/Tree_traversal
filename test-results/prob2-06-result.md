(TEST 6) maze_allocate_free2 : ok
=================================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs maze_allocate_free2
---------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs maze_allocate_free2
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                             ===ACTUAL===
IF_TEST("maze_allocate_free2") {                                       . IF_TEST("maze_allocate_free2") {
    // Allocates a maze and sets some tile information to include      .     // Allocates a maze and sets some tile information to include
    // state, paths, etc. then prints out tiles in the maze. There are .     // state, paths, etc. then prints out tiles in the maze. There are
    // non-NULL paths in some tiles and the maze queue is initialized  .     // non-NULL paths in some tiles and the maze queue is initialized
    // which checks that the maze_free() function de-allocates all     .     // which checks that the maze_free() function de-allocates all
    // non-NULL paths and the queue.                                   .     // non-NULL paths and the queue.
    int rows=4, cols=2;                                                .     int rows=4, cols=2;
    maze_t *maze = maze_allocate(rows,cols);                           .     maze_t *maze = maze_allocate(rows,cols);
    maze->start_row = 3;                                               .     maze->start_row = 3;
    maze->start_col = 1;                                               .     maze->start_col = 1;
    maze->end_row = 1;                                                 .     maze->end_row = 1;
    maze->end_col = 0;                                                 .     maze->end_col = 0;
    maze->tiles[3][1].state = START;                                   .     maze->tiles[3][1].state = START;
    maze->tiles[3][1].path_len = 0;                                    .     maze->tiles[3][1].path_len = 0;
    maze->tiles[3][1].path = malloc(sizeof(direction_t)*0);            .     maze->tiles[3][1].path = malloc(sizeof(direction_t)*0);
    maze->tiles[2][1].path_len = 1;                                    .     maze->tiles[2][1].path_len = 1;
    maze->tiles[2][1].path = malloc(sizeof(direction_t)*1);            .     maze->tiles[2][1].path = malloc(sizeof(direction_t)*1);
    maze->tiles[2][1].path[0] = NORTH;                                 .     maze->tiles[2][1].path[0] = NORTH;
    maze->tiles[1][1].path_len = 2;                                    .     maze->tiles[1][1].path_len = 2;
    maze->tiles[1][1].path = malloc(sizeof(direction_t)*2);            .     maze->tiles[1][1].path = malloc(sizeof(direction_t)*2);
    maze->tiles[1][1].path[0] = NORTH;                                 .     maze->tiles[1][1].path[0] = NORTH;
    maze->tiles[1][1].path[1] = NORTH;                                 .     maze->tiles[1][1].path[1] = NORTH;
    maze->tiles[1][0].state = END;                                     .     maze->tiles[1][0].state = END;
    maze->tiles[1][0].path_len = 3;                                    .     maze->tiles[1][0].path_len = 3;
    maze->tiles[1][0].path = malloc(sizeof(direction_t)*3);            .     maze->tiles[1][0].path = malloc(sizeof(direction_t)*3);
    maze->tiles[1][0].path[0] = NORTH;                                 .     maze->tiles[1][0].path[0] = NORTH;
    maze->tiles[1][0].path[1] = NORTH;                                 .     maze->tiles[1][0].path[1] = NORTH;
    maze->tiles[1][0].path[2] = WEST;                                  .     maze->tiles[1][0].path[2] = WEST;
    maze->queue = rcqueue_allocate();                                  .     maze->queue = rcqueue_allocate();
    rcqueue_add_rear(maze->queue, 1, 0);                               .     rcqueue_add_rear(maze->queue, 1, 0);
    printf("maze->rows: %d\n",maze->rows);                             .     printf("maze->rows: %d\n",maze->rows);
    printf("maze->cols: %d\n",maze->cols);                             .     printf("maze->cols: %d\n",maze->cols);
    printf("maze->start_row: %d\n",maze->start_row);                   .     printf("maze->start_row: %d\n",maze->start_row);
    printf("maze->start_col: %d\n",maze->start_col);                   .     printf("maze->start_col: %d\n",maze->start_col);
    printf("maze->end_row: %d\n",maze->end_row);                       .     printf("maze->end_row: %d\n",maze->end_row);
    printf("maze->end_col: %d\n",maze->end_col);                       .     printf("maze->end_col: %d\n",maze->end_col);
    for(int i=0; i<rows; i++){                                         .     for(int i=0; i<rows; i++){
      for(int j=0; j<cols; j++){                                       .       for(int j=0; j<cols; j++){
        printf("maze->tiles[%d][%d]: ",i,j);                           .         printf("maze->tiles[%d][%d]: ",i,j);
        tile_t *tile = &maze->tiles[i][j];                             .         tile_t *tile = &maze->tiles[i][j];
        printf("type %d state %d path_len %d path ",                   .         printf("type %d state %d path_len %d path ",
               tile->type, tile->state,                                .                tile->type, tile->state,
               tile->path_len);                                        .                tile->path_len);
        tile_print_path(tile,PATH_FORMAT_COMPACT);                     .         tile_print_path(tile,PATH_FORMAT_COMPACT);
        if(tile->path!=NULL){ printf("\n"); }                          .         if(tile->path!=NULL){ printf("\n"); }
      }                                                                .       }
    }                                                                  .     }
    printf("maze->queue: \n");                                         .     printf("maze->queue: \n");
    rcqueue_print(maze->queue);                                        .     rcqueue_print(maze->queue);
    maze_free(maze);                                                   .     maze_free(maze);
}                                                                      . }
---OUTPUT---                                                           . ---OUTPUT---
maze->rows: 4                                                          . maze->rows: 4
maze->cols: 2                                                          . maze->cols: 2
maze->start_row: 3                                                     . maze->start_row: 3
maze->start_col: 1                                                     . maze->start_col: 1
maze->end_row: 1                                                       . maze->end_row: 1
maze->end_col: 0                                                       . maze->end_col: 0
maze->tiles[0][0]: type 0 state 1 path_len -1 path No path found       . maze->tiles[0][0]: type 0 state 1 path_len -1 path No path found
maze->tiles[0][1]: type 0 state 1 path_len -1 path No path found       . maze->tiles[0][1]: type 0 state 1 path_len -1 path No path found
maze->tiles[1][0]: type 0 state 5 path_len 3 path NNW                  . maze->tiles[1][0]: type 0 state 5 path_len 3 path NNW
maze->tiles[1][1]: type 0 state 1 path_len 2 path NN                   . maze->tiles[1][1]: type 0 state 1 path_len 2 path NN
maze->tiles[2][0]: type 0 state 1 path_len -1 path No path found       . maze->tiles[2][0]: type 0 state 1 path_len -1 path No path found
maze->tiles[2][1]: type 0 state 1 path_len 1 path N                    . maze->tiles[2][1]: type 0 state 1 path_len 1 path N
maze->tiles[3][0]: type 0 state 1 path_len -1 path No path found       . maze->tiles[3][0]: type 0 state 1 path_len -1 path No path found
maze->tiles[3][1]: type 0 state 4 path_len 0 path                      . maze->tiles[3][1]: type 0 state 4 path_len 0 path 
maze->queue:                                                           . maze->queue: 
queue count: 1                                                         . queue count: 1
NN ROW COL                                                             . NN ROW COL
 0   1   0                                                             .  0   1   0

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs maze_allocate_free2
which may be pasted onto a command line to run it.

```
==15442== Memcheck, a memory error detector
==15442== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15442== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15442== Command: ./test_mazesolve_funcs maze_allocate_free2
==15442== 
==15442== 
==15442== HEAP SUMMARY:
==15442==     in use at exit: 0 bytes in 0 blocks
==15442==   total heap usage: 12 allocs, 12 frees, 328 bytes allocated
==15442== 
==15442== All heap blocks were freed -- no leaks are possible
==15442== 
==15442== For lists of detected and suppressed errors, rerun with: -s
==15442== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
