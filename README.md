# Testy - Tree Traversal and Pathfinding

Testy is a command-line tool designed to implement and test tree traversal and pathfinding algorithms efficiently. It includes a robust testing framework to validate traversal logic in various data structures.

![Tree Traversal Visualization](https://github.com/ismaildaniyal/Tree_traversal/blob/main/Screenshot%20from%202025-02-26%2011-20-09.png)

## Features
- Implements **Breadth-First Search (BFS)** for tree traversal
- Uses **queue-based traversal** for efficient node processing
- Supports **pathfinding in grid-based structures**
- Provides functions for queue operations, state tracking, and visualization
- Comprehensive test suite with all functions implemented and tested

## Installation
```bash
# Clone the repository
git clone https://github.com/ismaildaniyal/Tree_traversal.git
cd Tree_traversal

# Ensure you have a C compiler installed
gcc --version
```

## Usage
To compile and run the tree traversal program:
```bash
gcc -o testy mazesolve_funcs.c -Wall -Wextra
./testy
```

## Tree Traversal & Pathfinding Module
This project includes a module for tree traversal and pathfinding, implemented in C (`mazesolve_funcs.c`). The key functionalities include:
- **Queue Operations:** Functions to add, remove, and process nodes in a queue.
- **BFS Implementation:** Functions to initialize and iterate through nodes using breadth-first search.
- **Pathfinding Methods:** Functions to extend paths, check blocked nodes, and determine traversal feasibility.
- **Visualization Tools:** Functions to print the tree structure and track traversal state.

## Development
All core functions have been implemented and successfully passed all test cases, ensuring stability and correctness. Further optimizations and enhancements are welcome.

## Requirements
- C Compiler (GCC recommended)
- Linux/macOS (recommended)

## License
MIT License

## Repository
[GitHub Repository](https://github.com/ismaildaniyal/Tree_traversal)

