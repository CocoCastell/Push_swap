# About Push_swap

This algorithmic project is about sorting numbers (without duplicates) with only 2 stacks and using the minimum of a limited set of instructions.
To get the max grade, the algo must be able to sort 100 and 500 numbers in, respectively, less than 800 and less than 5500 operations.

The bonus part consist of implementing a simple sorted checker.  

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

# How to run

First, compile in the directory with
```
make
```
Then run the programm with your set of numbers
```
./push_swap 4 3 -1 32 43 -23
```
For the bonus, provide the set of numbers as arguments and the instructions as input.
```
make bonus
```
```
./checker 4 3 -1 32 43 -23
sa  pb  ss  rra
```

# Algorithm

I used a quick sort algo with double linked list.  
The first step is to normalise the given numbers: -5 54 33 8 becomes 1 4 3 2, this is particularly useful for finding pivots efficiently. The algorithm uses recursion, and "divide and conquer" principle: it divides in 3 chunks, min, mid and max the numbers, until having a chunk of 3 or less numbers wich we can sort efficiently with a small algo.  
All the instructions are stocked in a simple list, and an optimisation is then performed: instructions that can be cancelled/combined are simplified. With this technic, sa - sb becomes ss, and pa - pa - pa - pb - pb - pb are cancelled.

# Results

✅ 125/100  
100 numbers --> ~720 instructions  
500 numbers --> ~4200 instructions  

# Ressources

This amazing tutorial helped me a lot understanding the main principles: https://medium.com/@ulysse.gerkens/push-swap-in-less-than-4200-operations-c292f034f6c0.  
