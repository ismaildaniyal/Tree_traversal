#include "mazesolve.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *maze_file;
    if (argc == 2) {
        maze_file = argv[1];
        LOG_LEVEL = 0;  // Turn logging off
    } else if (argc == 4 && strcmp(argv[1], "-log") == 0) {
        LOG_LEVEL = atoi(argv[2]);
        maze_file = argv[3];
    } else {
        printf("Usage: %s [-log N] <mazefile>\n", argv[0]);
        return 1;
    }

    maze_t *maze = maze_from_file(maze_file);
    if (maze == NULL) {
        printf("Could not load maze file. Exiting with error code 1\n");
        return 1;
    }

    // Print the initial maze state (without extra header)
    maze_print_tiles(maze);

    // Solve the maze
    maze_bfs_iterate(maze);
    int ret = maze_set_solution(maze);

    if (ret) {
        printf("\nSOLUTION:\n");
        maze_print_tiles(maze);
        tile_t *end_tile = &maze->tiles[maze->end_row][maze->end_col];
        if (end_tile->path != NULL && end_tile->path_len > 0) {
            printf("path length: %d\n", end_tile->path_len);
            for (int i = 0; i < end_tile->path_len; i++) {
                if (i < 10)
                    printf(" %d: %s\n", i, direction_verbose_strs[end_tile->path[i]]);
                else
                    printf("%d: %s\n", i, direction_verbose_strs[end_tile->path[i]]);
            }
            
        }
    } else {
        printf("\nNO SOLUTION FOUND\n");

    }

    maze_free(maze);
    return 0;
}
