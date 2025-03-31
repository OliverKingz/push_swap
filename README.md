# push_swap

[42-Cursus] A sorting algorithm project where you must sort data on a stack using a limited set of instructions in the fewest moves possible.  
This project is designed to enhance skills in **sorting algorithm design**, **stack manipulation**, and **C programming**.

![Example push_swapk](assets/push_swap_ksort.gif)

Keywords:

- Sorting algorithms
- Stack manipulation
- C programming
- Algorithm optimization
- Complexity analysis

---

## Overview

The **push_swap** project involves sorting a stack of integers using two stacks (`stack_a` and `stack_b`) and a limited set of operations. The goal is to sort the numbers in ascending order with the fewest possible moves.

You will need to implement various sorting algorithms and choose the most efficient solution for different configurations of integers. This project is a great way to learn about **algorithm complexity** and **optimization**.

---

## Features

- Sort a stack of integers using a limited set of operations.
- Use two stacks (`stack_a` and `stack_b`) to manipulate the data.
- Implement efficient sorting algorithms to minimize the number of moves.
- Handle edge cases such as duplicate numbers, invalid inputs, and empty stacks.
- Validate the correctness of the sorting using a provided checker program.

## Bonus Features

- Checker Program: A bonus program that verifies if the operations generated by push_swap correctly sort the stack.

### Operations Allowed

- **sa**: Swap the first two elements of `stack_a`.
- **sb**: Swap the first two elements of `stack_b`.
- **ss**: Perform `sa` and `sb` simultaneously.
- **pa**: Push the first element of `stack_b` to `stack_a`.
- **pb**: Push the first element of `stack_a` to `stack_b`.
- **ra**: Rotate `stack_a` (shift all elements up by one, the first element becomes the last).
- **rb**: Rotate `stack_b` (shift all elements up by one, the first element becomes the last).
- **rr**: Perform `ra` and `rb` simultaneously.
- **rra**: Reverse rotate `stack_a` (shift all elements down by one, the last element becomes the first).
- **rrb**: Reverse rotate `stack_b` (shift all elements down by one, the last element becomes the first).
- **rrr**: Perform `rra` and `rrb` simultaneously.

---

## Performance Requirements

To validate the project, you must meet the following performance criteria:

- **100 random numbers**: Sort in less than **700 moves**.
- **500 random numbers**: Sort in less than **5500 moves**.

These benchmarks ensure that your algorithm is efficient and optimized for larger datasets.

---

## How to Use

1. Clone this repository:

   ```bash
   git clone https://github.com/yourusername/push_swap.git
   cd push_swap
   ```

2. Compile the project using the provided **Makefile**:

   ```bash
   make
   ```

3. Run the program with a list of integers as arguments:

   ```bash
   ./push_swap 3 2 1 0
   ```

4. Use the **checker** program to validate the sorting:
   ```bash
   ARG="3 2 1 0"; ./push_swap $ARG | ./checker_linux $ARG
   ```
   If the output is **OK**, the stack is sorted correctly.

## Example Usage

| **Input Command**                 | **Description**                                      | **Expected Output**                                  |
| --------------------------------- | ---------------------------------------------------- | ---------------------------------------------------- |
| `./push_swap 3 2 1`               | Sorts three numbers in descending order.             | `sa`, `rra` (or similar minimal operations).         |
| `./push_swap 1 5 2 4 3`           | Sorts five numbers in random order.                  | A sequence of operations like `pb`, `ra`, `sa`, etc. |
| `./push_swap -1 -5 -3 -4 -2`      | Sorts negative numbers.                              | A sequence of operations like `pb`, `ra`, `sa`, etc. |
| `./push_swap "5 4" 3 2 1`         | Sorts a stack in reverse order.                      | A sequence of operations like `sa`, `pb`, `ra`, etc. |
| `./push_swap "9 8 7 6 5 4 3 2 1"` | Sorts numbers provided as a single string.           | A sequence of operations like `sa`, `pb`, `ra`, etc. |
| `./push_swap`                     | No input                                             | No output.                                           |
| `./push_swap 42`                  | Single number (already sorted).                      | No output.                                           |
| `./push_swap 1 2 3 4 5`           | No operations needed if the stack is already sorted. | No output.                                           |

## Bonus Usage

The **checker** program is a bonus feature that validates whether the instructions generated by `push_swap` correctly sort the stack.

### How to Use

1. Compile the checker program:

   ```bash
   make bonus
   ```

<<<<<<< Updated upstream
| **Input Command**                                      | **Description**                                                                 | **Expected Output**                                                                          |
|--------------------------------------------------------|---------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------|
| `ARG="3 2 1"; ./push_swap $ARG \| ./checker $ARG`      | Combines `push_swap` and `checker` to validate sorting.                         | `OK` if the stack is sorted, `KO` otherwise.                                                 |
| `ARG="1 2 3"; ./push_swap $ARG \| ./checker $ARG`      | Validates an already sorted stack.                                              | `OK` (no operations needed).                                                                 |
| `./checker 3 2 1`                                      | Validates the operations generated by `push_swap`.                              | `OK` if the stack is sorted, `KO` otherwise.                                                 |
| `./checker 1`                                          | Single number as input, it should wait for operations                           | `OK` as long as you don’t perform any operations, or Stack A operations only                 |
| `./checker 1 2`                                        | Input is sorted                                                                 | `OK` as long as you don’t perform any operations, or if your operations don’t mess things up |

## Error Handling

| **Input Command**                                      | **Description**                                                                 | **Expected Output**                                                                 |
|--------------------------------------------------------|---------------------------------------------------------------------------------|-------------------------------------------------------------------------------------|
| `./push_swap 3 2 one`                                  | Invalid argument (non-integer).                                                 | `Error`                                                                            |
| `./push_swap 3 2 3`                                    | Duplicate numbers.                                                              | `Error`                                                                            |
| `./push_swap 2147483648 2 3`                           | Number outside the `int` range (too large).                                     | `Error`                                                                            |
| `./push_swap -2147483649 2 3`                          | Number outside the `int` range (too small).                                     | `Error`                                                                            |
| `./push_swap "3 2 1" 4 five`                           | Mixed valid and invalid arguments.                                              | `Error`                                                                            |
| `./push_swap "3 2 1" "4 5 six"`                        | Invalid argument in a multi-string input.                                       | `Error`                                                                            |
| `./push_swap 3 2 1 +-2`                                | Invalid format (misuse of `+` and `-`).                                         | `Error`                                                                            |
| `./push_swap 3 2 1 9999999999999999999999999999999999` | Extremely large number (outside `int` range).                                   | `Error`                                                                            |
| `./push_swap ""`                                       | Empty argument.                                                                 | `Error`                                                                            |
| `./push_swap "     "`                                  | Argument filled with spaces.                                                    | `Error`                                                                            |
| `./push_swap "     " 3 2 1 "    "`                     | Argument filled with spaces. You need to check each arg has a valid nbr         | `Error`                                                                            |
| `./checker -`                                          | Invalid argument for checker                                                    | `Error`                                                                            |
=======
2. Run the checker with a list of integers:

   ```bash
   ./checker 3 2 1 0
   ```

3. Input the instructions generated by `push_swap`. If the stack is sorted, the checker will output **OK**; otherwise, it will output **KO**.

| **Input Command**                                 | **Description**                                         | **Expected Output**                          |
| ------------------------------------------------- | ------------------------------------------------------- | -------------------------------------------- |
| `./checker 3 2 1`                                 | Validates the operations generated by `push_swap`.      | `OK` if the stack is sorted, `KO` otherwise. |
| `ARG="3 2 1"; ./push_swap $ARG \| ./checker $ARG` | Combines `push_swap` and `checker` to validate sorting. | `OK` if the stack is sorted, `KO` otherwise. |
| `ARG="1 2 3"; ./push_swap $ARG \| ./checker $ARG` | Validates an already sorted stack.                      | `OK` (no operations needed).                 |

## Error Handling

| **Input Command**                                      | **Description**                                                         | **Expected Output** |
| ------------------------------------------------------ | ----------------------------------------------------------------------- | ------------------- |
| `./push_swap 3 2 one`                                  | Invalid argument (non-integer).                                         | `Error`             |
| `./push_swap 3 2 3`                                    | Duplicate numbers.                                                      | `Error`             |
| `./push_swap 2147483648 2 3`                           | Number outside the `int` range (too large).                             | `Error`             |
| `./push_swap -2147483649 2 3`                          | Number outside the `int` range (too small).                             | `Error`             |
| `./push_swap "3 2 1" 4 five`                           | Mixed valid and invalid arguments.                                      | `Error`             |
| `./push_swap "3 2 1" "4 5 six"`                        | Invalid argument in a multi-string input.                               | `Error`             |
| `./push_swap 3 2 1 +-2`                                | Invalid format (misuse of `+` and `-`).                                 | `Error`             |
| `./push_swap 3 2 1 9999999999999999999999999999999999` | Extremely large number (outside `int` range).                           | `Error`             |
| `./push_swap ""`                                       | Empty argument.                                                         | `Error`             |
| `./push_swap "     "`                                  | Argument filled with spaces.                                            | `Error`             |
| `./push_swap "     " 3 2 1 "    "`                     | Argument filled with spaces. You need to check each arg has a valid nbr | `Error`             |
>>>>>>> Stashed changes

---

## Sorting Algorithms

### Quick Sort (Indexing)

Before sorting, numbers are indexed using a replica of C's qsort() function to assign relative positions. This simplifies operations by working with sequential indexes (1,2,3...) instead of arbitrary values, while maintaining the original number relationships.

**Divide and Conquer**: Partitions array using a pivot element

- Elements > pivot move to right partition
- Elements < pivot move to left partition

**Recursive Process**: Each partition is sorted independently

**Implementation**: Used to convert input numbers into sequential indexes

- Example: [7, 2, 8, 1] → [3, 2, 4, 1]

**Performance**:

- Average time complexity: O(n log n)
- Efficient for large datasets
- In-place sorting

### Simple Comparison and Swap

Used for 2 numbers:

- Direct comparison between elements
- Single swap if needed (sa)
- Time complexity: O(1)

### Permutation Sort

Used for 3 numbers:

- Implements 5 possible permutations (6 total - 1 sorted)
- Pre-calculated optimal move sequences
- Maximum 2 moves needed
- Time complexity: O(1)

### Selection and Permutation Sort

Used for 4 and 5 numbers:

Selection Phase

- Iteratively finds minimum value
- Pushes minimum to stack B
- Repeats once for 4 numbers, twice for 5

Permutation Sort Phase

- Sorts remaining 3 numbers using permutation sort
- Returns minimum values from Stack B in order
- Time complexity: O(n²)

### K-Sort Algorithm

Used for 6+ numbers, this algorithm efficiently sorts large datasets. It is a custom sorting algorithm for **push_swap** that requires indexed data to optimize comparisons and movements. This indexed approach:

- Converts original values to sequential positions (1, 2, 3...)
- Eliminates the complexity of handling negative numbers
- Simplifies range calculations and comparisons

**Stack Operations**

- **Stack A**: Holds the initial numbers and the final sorted result.
- **Stack B**: Used as temporary storage for segmented chunks of numbers.
- **Chunk Strategy**: Numbers are pushed to Stack B in chunks based on a calculated range.

**K-Pattern in Stack B**
During the push phase (`k_sort1`), smaller numbers are pushed to Stack B and rotated to the bottom (`rb`), while larger numbers remain at the top. This causes **Stack B to form a K-pattern**:

- **Top and bottom of Stack B** contain larger numbers.
- **Middle of Stack B** holds smaller numbers from earlier ranges.

**Sorting Strategy**

1. **K_Sort1 (Push Phase)**

   - Uses a range-based strategy to determine which numbers to push to Stack B.
   - Numbers smaller than the current target (`i`) are pushed and rotated to the bottom of Stack B.
   - Numbers within the current range (`i < value <= i + range`) are pushed to Stack B without rotation.
   - Larger numbers are skipped and rotated in Stack A for later processing.
   - Stack B maintains a partially organized structure, with the K-pattern emerging from the rotation of smaller values.

2. **K_Sort2 (Return Phase)**
   - Returns numbers from Stack B to Stack A in sorted order.
   - Calculates the most efficient rotations to bring the target value to the top of Stack B.
   - Optimally performs rotations (`rb` or `rrb`) before pushing back to Stack A.
   - Builds the final sorted sequence in Stack A.

**Performance**

- **Time Complexity**: O(n log n)
- **Optimized Operations**: Minimizes the number of moves for large datasets.
- Efficient and scalable for sorting indexed data.

---

## What I Learned

This project was a great opportunity to deepen my understanding of:

- **Sorting Algorithms**: Implementing and comparing different algorithms like **quicksort**, **permutation sort**, and **selection sort**.
- **Algorithm Complexity**: Analyzing the time and space complexity of different approaches.
- **Data Structures**: Using stacks and linked lists to manipulate data efficiently.
- **Optimization**: Reducing the number of operations to achieve the desired result.
- **Error Handling**: Validating inputs and handling edge cases gracefully.

---

## Author

- **Name**: Oliver King Zamora
- **GitHub**: [oliverkingz](https://github.com/oliverkingz)
- **42 Login**: ozamora-

---

## Acknowledgments

This project is part of the **42 Cursus**, a rigorous programming curriculum that emphasizes hands-on learning and problem-solving. Special thanks to the 42 team for providing this challenging and rewarding project!

---
