# Square Matrix Operators - Assignment 2

**Student ID:** 326063260  
**Email:** dvir.opa@gmail.com

##  Overview
This project implements a class `SquareMat` that represents square matrices of real numbers, supporting various matrix operations using operator overloading in C++. 

It follows the principles taught in lectures 4 and 5, including:
- Operator overloading (binary and unary operators)
- The Rule of Three
- Manual memory management using dynamic arrays
- Avoidance of STL containers (like `std::vector`)

## File Structure
```
├── SquareMat.h       # Declaration of the SquareMat class
├── SquareMat.cpp     # Implementation of SquareMat methods
├── Node.h            # Declaration of the linked-list based Node class
├── Node.cpp          # Implementation of Node methods
├── test_matrices.cpp # Doctest-based unit tests for SquareMat
├── main.cpp          # (Optional) Demo program
├── Makefile          # Build and test automation
```

## Features Implemented
### Class: SquareMat
- Internal structure: Linked list of rows, each holding a dynamically allocated array of doubles
- Supports square matrices only (NxN)

### Operators Overloaded
- `+`, `-` : Matrix addition and subtraction
- `*` : Matrix multiplication and scalar multiplication (both orders)
- `%` : Element-wise matrix multiplication and modulo with scalar
- `/` : Division of each matrix element by a scalar
- `^` : Matrix exponentiation (positive integer powers only)
- `~` : Transpose of the matrix
- `-` (unary) : Negation of matrix elements
- `++`, `--` : Pre/post increment/decrement all elements by 1
- `==`, `!=`, `<`, `<=`, `>`, `>=` : Based on sum of matrix elements
- `!` : Determinant calculation using recursive cofactor expansion
- `[]` : Access to rows with support for indexing elements
- Combined assignment: `+=`, `-=`, `*=`, `/=`, `%=`
- Stream output: `<<` for printing the matrix

### Rule of Three
- Custom Copy Constructor
- Custom Destructor
- Custom Assignment Operator

## How to Compile and Run
Use the provided Makefile:

```bash
make test       # Compiles and runs unit tests
make valgrind   # Checks for memory leaks using valgrind
make clean      # Removes build artifacts
```

## Memory Safety
All memory allocations are freed correctly. `valgrind` output confirms no memory leaks.

## Unit Testing
Implemented using the [doctest](https://github.com/doctest/doctest) framework.
Tests include:
- Matrix creation
- Arithmetic operations
- Scalar operations
- Transposition
- Equality and comparison
- Determinant correctness

## Submission Details
- Student ID: [Your ID here]
- GitHub Repo: [Your GitHub URL here]
- Commit Hash: [Commit hash here]

---

## Notes
- Only raw arrays and pointers were used (no `std::vector`)
- All requirements of the assignment were met
- AI tools (like ChatGPT) were used to debug memory errors and clarify operator behaviors, but not to copy code.

---

Feel free to modify and extend this project to support non-square matrices, LU decomposition, or matrix inversion!