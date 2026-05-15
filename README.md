*This project has been created as part of the 42 curriculum by loandria, tojorana.*

# Push_swap - Advanced Sorting with Limited Operations


## Description

Push_swap is an advanced sorting algorithm project that challenges you to sort numbers on a stack using a limited set of operations and the lowest possible number of actions. The project focuses on understanding algorithmic complexity and implementing multiple sorting strategies with different complexity classes.

The core challenge: Given two stacks (A and B), sort the numbers in stack A in ascending order using only 11 allowed operations, while minimizing the total number of operations executed.

This project demonstrates:
- Implementation of multiple sorting algorithms with different complexity classes
- Adaptive algorithm selection based on input disorder
- Performance optimization through operation counting and benchmarking
- Efficient use of two-stack data structures with limited primitive operations

## Features

### Four Sorting Strategies Implemented

1. **Simple Algorithm (O(n²))**
   - Selection sort adaptation using min/max extraction
   - Finds the minimum element and pushes it to stack B
   - Rotates as needed to minimize operations
   - Best for small datasets or highly sorted inputs

2. **Medium Algorithm (O(n√n))**
   - Chunk-based sorting strategy
   - Divides input into logical chunks based on input size
   - Dynamic chunk sizing: 20 elements for datasets ≤100, 45 for larger
   - Pushes elements with lower indices to stack B first
   - Efficiently reconstructs sorted array using max element positioning

3. **Complex Algorithm (O(n log n))**
   - Radix sort adaptation (Least Significant Digit)
   - Uses index-based bit analysis
   - Processes each bit position from least to most significant
   - Pushes elements to stack B based on bit value
   - Optimal for random or highly disordered inputs

4. **Adaptive Algorithm (Learner's Design)**
   - Automatically selects algorithm based on disorder metric
   - Low disorder (< 0.2): Uses Simple algorithm (O(n²))
   - Medium disorder (0.2 - 0.5): Uses Medium algorithm (O(n√n))
   - High disorder (≥ 0.5): Uses Complex algorithm (O(n log n))
   - Maximizes performance across diverse input distributions

### Allowed Operations

- **sa** - Swap first two elements of stack A
- **sb** - Swap first two elements of stack B
- **ss** - Perform sa and sb simultaneously
- **pa** - Push top element from B to A
- **pb** - Push top element from A to B
- **ra** - Rotate stack A upward (first element becomes last)
- **rb** - Rotate stack B upward
- **rr** - Perform ra and rb simultaneously
- **rra** - Reverse rotate A (last element becomes first)
- **rrb** - Reverse rotate B
- **rrr** - Perform rra and rrb simultaneously

### Key Features

- **Disorder Metric**: Calculates the disorder percentage before sorting
- **Performance Benchmarking**: Tracks all operations and provides statistics
- **Error Handling**: Validates input for integers, range, and duplicates
- **Strategy Selection**: Command-line flags to force specific algorithms
- **Indexing System**: Assigns ranks to elements for efficient comparison
- **Memory Management**: Proper allocation and deallocation with no leaks

## Instructions

### Compilation

```bash
make              # Compile the push_swap program
make clean        # Remove object files
make fclean       # Remove all generated files
make re           # Recompile everything
```

### Basic Usage

```bash
# Default (adaptive algorithm)
./push_swap 2 1 3 6 5 8

# Force specific algorithm
./push_swap --simple 5 4 3 2 1
./push_swap --medium 3 1 4 1 5 9
./push_swap --complex 10 9 8 7 6 5 4 3 2 1

# With benchmark mode
./push_swap --bench 4 67 3 87 23

# Pass arguments from file
ARG="4 67 3 87 23"; ./push_swap $ARG
shuf -i 0-9999 -n 500 > args.txt && ./push_swap $(cat args.txt) | wc -l
```

### Error Handling

The program detects and reports errors:
- Non-integer arguments
- Integer overflow (outside INT_MIN to INT_MAX range)
- Duplicate values
- Empty input

```bash
./push_swap --simple 3 2 3        # Error: duplicate
./push_swap 99999999999999 1 2    # Error: integer out of range
./push_swap 0 one 2               # Error: non-integer
```

### Benchmark Mode

When using `--bench` flag, the program outputs metrics to stderr:

```bash
./push_swap --bench 4 67 3 87 23
```

Output format:
```
[bench] disorder: XX.XX%
[bench] strategy: adaptive / O(nlogn)
[bench] total_ops: 42
[bench] sa: 0 sb: 1 ss: 0 pa: 5 pb: 6
[bench] ra: 10 rb: 8 rr: 3 rra: 2 rrb: 0 rrr: 1
```

## Performance Targets

The project includes performance benchmarks that must be met:

### For 100 random integers:
- **Minimum**: < 2000 operations
- **Good**: < 1500 operations
- **Excellent**: < 700 operations

### For 500 random integers:
- **Minimum**: < 12000 operations
- **Good**: < 8000 operations
- **Excellent**: < 5500 operations

## Project Structure

### Core Components

- **`push_swap.h`** - Main header with data structures and function declarations
- **`main.c`** - Entry point and program initialization
- **`main_utils.c`** - Algorithm selection and sorting orchestration

### Stack Management

- **`stack_init.c`** - Stack initialization and validation
- **`stack_size.c`** - Stack size calculation
- **`swap_utils.c`** - Utility functions (verification, sorting check, cleanup)
- **`put_index.c`** - Index assignment for rank-based operations

### Operations Implementation

- **`push_op.c`** - Push operations (pa, pb)
- **`swap_op.c`** - Swap operations (sa, sb, ss)
- **`rotate_op.c`** - Rotate operations (ra, rb, rr)
- **`reverse_rotate_op.c`** - Reverse rotate operations (rra, rrb, rrr)

### Algorithms

- **`simple_algo.c`** - O(n²) selection sort adaptation
- **`medium_algo.c`** - O(n√n) chunk-based sorting
- **`complex_algo.c`** - O(n log n) radix sort adaptation
- **`adaptive_str.c`** - Adaptive algorithm selector based on disorder
- **`get_condition.c`** - Handling small arrays (2-5 elements)
- **`sort_3_nb.c`**, **`sort_4_nb.c`**, **`sort_5_nb.c`** - Optimized small sorts

### Utilities

- **`parsing.c`** - Command-line argument parsing and validation
- **`is_split.c`** - String splitting functionality
- **`is_atoi.c`** - String to integer conversion with validation
- **`count_disorder.c`** - Disorder metric calculation
- **`get_max.c`** - Maximum value finder
- **`bench_utils.c`** - Benchmarking utilities
- **`bench_mod.c`** - Benchmark output formatting

### Printf Library

- **`ft_printf/`** - Custom printf implementation with format specifiers

## Algorithm Details

### Disorder Metric

Disorder is calculated as the ratio of inversions (pairs where a larger number appears before a smaller one) to the total number of pairs:

```
disorder = inversions / total_pairs

Where:
- inversions = count of (i, j) pairs where i < j and a[i] > a[j]
- total_pairs = n * (n-1) / 2

Range: [0, 1]
- 0 = fully sorted
- 1 = reverse sorted (worst case)
```

### Adaptive Strategy Selection

The program measures disorder before any operations and selects the optimal algorithm:

| Disorder Range | Algorithm | Complexity | Use Case |
|---|---|---|---|
| < 0.2 | Simple | O(n²) | Nearly sorted data |
| 0.2 - 0.5 | Medium | O(n√n) | Moderately shuffled |
| ≥ 0.5 | Complex | O(n log n) | Highly randomized |

### Index Assignment

Elements are assigned indices based on their rank in sorted order:
- Value 1 → Index 0
- Value 2 → Index 1
- Value 5 → Index 2
- etc.

This allows efficient bit manipulation in radix sort and simplified comparison operations.

## Data Structures

### Stack Node (t_stack)
```c
typedef struct s_stack {
    int value;              // Original integer value
    int index;              // Rank position (0 to n-1)
    struct s_stack *nxt;    // Pointer to next element
} t_stack;
```

### Benchmark Counter (t_bench)
```c
typedef struct s_bench {
    int sa, sb, ss;         // Swap operation counts
    int pa, pb;             // Push operation counts
    int ra, rb, rr;         // Rotate operation counts
    int rra, rrb, rrr;      // Reverse rotate counts
    int total_ops;          // Total operations
    int *mode;              // Benchmark mode flag
} t_bench;
```

## Resources

### Algorithm References

1. **Sorting Algorithms**
   - [Insertion Sort and Variants](https://en.wikipedia.org/wiki/Insertion_sort)
   - [Radix Sort Algorithm](https://en.wikipedia.org/wiki/Radix_sort)
   - [Bubble Sort and Optimizations](https://en.wikipedia.org/wiki/Bubble_sort)

2. **Complexity Analysis**
   - [Big O Notation Guide](https://en.wikipedia.org/wiki/Big_O_notation)
   - [Algorithm Complexity Classes](https://en.wikipedia.org/wiki/Computational_complexity_theory)
   - [Comparison of Sorting Algorithms](https://en.wikipedia.org/wiki/Sorting_algorithm#Comparison_of_sorting_algorithms)

3. **Stack-Based Sorting**
   - [Push Swap Problem Analysis](https://www.geeksforgeeks.org/stack/)
   - [Two-Stack Data Structure Uses](https://www.linkedin.com/pulse/push-swap-algorithm-explained-step-by-step-guide/)

4. **Performance Optimization**
   - [Operation Counting and Profiling](https://en.wikipedia.org/wiki/Program_profiling)
   - [Algorithmic Optimization Techniques](https://www.geeksforgeeks.org/analysis-of-algorithms-set-1-asymptotic-analysis/)

### Disorder and Inversion Counting

- [Inversion Counting Problem](https://www.geeksforgeeks.org/inversion-count-in-array-using-merge-sort/)
- [Kendall Tau Distance](https://en.wikipedia.org/wiki/Kendall_tau_distance)

## AI Usage

AI tools were utilized in the following areas:

1. **Documentation**
   - Generated initial documentation structure
   - Helped explain complex algorithm concepts clearly
   - Assisted in creating comprehensive error handling descriptions

2. **Testing & Debugging**
   - Suggested test cases for edge cases (empty stack, single element, duplicates)
   - Provided debugging strategies for operation sequences

All implementations were thoroughly reviewed, tested, and understood by both contributors before integration into the project.

## Mandatory Part Checklist

- ✓ Two stacks (A and B) implementation
- ✓ All 11 push_swap operations implemented
- ✓ Input validation (integers, range, duplicates)
- ✓ Disorder metric calculation
- ✓ Simple algorithm (O(n²))
- ✓ Medium algorithm (O(n√n))
- ✓ Complex algorithm (O(n log n))
- ✓ Adaptive algorithm with disorder-based selection
- ✓ Strategy selection flags (--simple, --medium, --complex, --adaptive)
- ✓ Benchmark mode (--bench)
- ✓ Performance targets met (100 and 500 element tests)
- ✓ Makefile with proper rules
- ✓ No memory leaks
- ✓ Error handling
- ✓ Norminette compliance


## Compilation and Usage Notes

### Important Files

- **push_swap**: Main sorting program
- **Makefile**: Build configuration with all required rules
- **ft_printf/**: Internal printf library

### No External Libraries Required

The project uses only standard C library functions:
- `read`, `write` - I/O operations
- `malloc`, `free` - Memory management
- `exit` - Program termination

### Norm Compliance

The project follows the 42 School Norm standards:
- Maximum 25 lines per function
- Maximum line length enforced
- Proper variable naming conventions
- Consistent formatting and indentation

## Contributors

- **loandria** - Primary developer
- **tojorana** - Co-developer

Both contributors have equally participated in algorithm design, implementation, testing, and documentation.

## License

This project is part of the 42 School curriculum and follows their academic guidelines.

---

**Last Updated**: April 22, 2026
