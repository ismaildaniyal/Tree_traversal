(TEST 15) maze_print_state4 : ok
================================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs maze_print_state4
-------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs maze_print_state4
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                            ===ACTUAL===
IF_TEST("maze_print_state4") {                                        . IF_TEST("maze_print_state4") {
    // Computer approximate path lengths from the start tile for each .     // Computer approximate path lengths from the start tile for each
    // non-wall tile in the given maze and prints the state to check  .     // non-wall tile in the given maze and prints the state to check
    // formatting. The exact paths are not computed nor allocated,    .     // formatting. The exact paths are not computed nor allocated,
    // only a rough path length which is stored in each tile.         .     // only a rough path length which is stored in each tile.
    char *maze_str =                                                  .     char *maze_str =
      "################\n"                                            .       "################\n"
      "#S             #\n"                                            .       "#S             #\n"
      "# ### ###### # #\n"                                            .       "# ### ###### # #\n"
      "# ### ##E  #   #\n"                                            .       "# ### ##E  #   #\n"
      "# ### #### ##  #\n"                                            .       "# ### #### ##  #\n"
      "#              #\n"                                            .       "#              #\n"
      "################\n";                                           .       "################\n";
    maze_t *maze = maze_from_string(maze_str);                        .     maze_t *maze = maze_from_string(maze_str);
    for(int i=0; i<maze->rows; i++){                                  .     for(int i=0; i<maze->rows; i++){
      for(int j=0; j<maze->cols; j++){                                .       for(int j=0; j<maze->cols; j++){
        tile_t *tile = &maze->tiles[i][j];                            .         tile_t *tile = &maze->tiles[i][j];
        if(tile->type != WALL){                                       .         if(tile->type != WALL){
          tile->state = FOUND;                                        .           tile->state = FOUND;
          tile->path_len = i-1 + j-1;                                 .           tile->path_len = i-1 + j-1;
        }                                                             .         }
      }                                                               .       }
    }                                                                 .     }
    printf("PRINTING STATE WITH APPROXIMATE PATHS:\n");               .     printf("PRINTING STATE WITH APPROXIMATE PATHS:\n");
    maze_print_state(maze);                                           .     maze_print_state(maze);
    maze_free(maze);                                                  .     maze_free(maze);
}                                                                     . }
---OUTPUT---                                                          . ---OUTPUT---
PRINTING STATE WITH APPROXIMATE PATHS:                                . PRINTING STATE WITH APPROXIMATE PATHS:
################:  0                                                  . ################:  0
#0123456789a123#:  1                                                  . #0123456789a123#:  1
#1###5######2#4#:  2                                                  . #1###5######2#4#:  2
#2###6##9a1#345#:  3                                                  . #2###6##9a1#345#:  3
#3###7####2##56#:  4                                                  . #3###7####2##56#:  4
#456789a1234567#:  5                                                  . #456789a1234567#:  5
################:  6                                                  . ################:  6
0123456789012345                                                      . 0123456789012345
0         1                                                           . 0         1     
null queue                                                            . null queue

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs maze_print_state4
which may be pasted onto a command line to run it.

```
==15476== Memcheck, a memory error detector
==15476== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15476== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15476== Command: ./test_mazesolve_funcs maze_print_state4
==15476== 
==15476== 
==15476== HEAP SUMMARY:
==15476==     in use at exit: 0 bytes in 0 blocks
==15476==   total heap usage: 9 allocs, 9 frees, 2,784 bytes allocated
==15476== 
==15476== All heap blocks were freed -- no leaks are possible
==15476== 
==15476== For lists of detected and suppressed errors, rerun with: -s
==15476== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
