# About Push_swap

This algorithmic project is about sorting data with only 2 stacks and using the minimum of a limited set of instructions.
To get the max grade, the algo must be able to sort 100 and 500 numbers in, respectively, less than 800 and less than 5500 operations.

# Instructions

| Name | Purpose |
|------|---------|
|   sa | swap a |
|   sb | swap b |
|   ss | swap a & b |
|   pa | push a  |
|   pb | push b  |
|   ra | rotate a |
|   rb | rotate b |
|   rr | rotate a & b |
|  rra | reverse rotate a |
|  rrb | reverse rotate b |
|  rrr | reverse rotate a & b |

# Algorithm

I used a quick sort algo with double linked list. 
The first step is to normalise the given numbers: -5 54 33 8 becomes 1 4 3 2, this is particularly useful for finding pivots efficiently. The algorithm uses recursion, and "divide and conquer" principle: it divides in 3 chunks, min, mid and max the numbers, until having a chunk of 3 or less numbers wich we can sort efficiently with a small algo. 
All the instructions are stocked in a simple list, and an optimisation is then performed: instructions that can be cancelled/combined are simplified. With this technic, sa - sb becomes ss, and pa - pa - pa - pb - pb - pb are cancelled.

# Results

100 numbers --> ~720 instructions  
500 numbers --> ~4200 instructions  
