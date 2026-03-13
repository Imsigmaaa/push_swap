
*This project has been created as part of the 42 curriculum by xingchen*

# Description

Push_swap is an algorithm project: sort a stack of integers using a limited set of operations, with as few moves as possible.
You have two stacks, `a` and `b`, and a set of operations to move elements between them. At the start, stack `a` holds a list of unique integers and stack `b` is empty. The goal is to sort a in ascending order.

The project has two programs:

- `push_swap`: calculates and prints each move to sort the stack in the most efficient way possible

# Instructions

## Compilation
```bash
make
```

## Usage

### push_swap
```bash
./push_swap 3 2 1 5 4
```

Prints the list of operations to sort the stack, one per line:
```
pb
pb
sa
pa
pa

```


## Error handling

The program prints `Error` in the following cases:

- An argument is not an integer
- An argument is outside the `int` range
- There are duplicate values

## Available operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first 2 elements at the top of stack `a` |
| `sb` | Swap the first 2 elements at the top of stack `b` |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Take the first element at the top of `b` and put it at the top of `a` |
| `pb` | Take the first element at the top of `a` and put it at the top of `b` |
| `ra` |(rotate `a`): Shift up all elements of stack `a` by 1.|
| `rb` |(rotate `b`):Shift up all elements of stack `b` by 1.|
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate `a`: Shift down all elements of stack `a` by 1. |
| `rrb` | Reverse rotate `b`: Shift down all elements of stack `b` by 1.|
| `rrr` | `rra` and `rrb` at the same time |

# Algorithm — Turkish Sort

1. **Normalize** the input to indices (0, 1, 2 ... n-1) to simplify cost calculations
2. **Push to b** — push elements from `a` to `b` until 3 elements remain in `a`
3. **Sort 3** — sort the remaining 3 elements in `a` with at most 2 operations
4. **Push back to a** — for each element in `b`, calculate the cheapest cost to insert it into its correct position in `a` (using `rr`/`rrr` to combine rotations when both stacks move in the same direction)
5. **Final rotate** — rotate `a` to bring the smallest element to top


# Resources

- [Push_Swap Turk algorithm explained1](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0)
- [Push_Swap Turk algorithm explained2](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

**AI usage:** AI tools were used only to better understand stack rotations and algorithm concepts. All code was written and tested by the author.