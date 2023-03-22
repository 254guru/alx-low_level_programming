C-function poiners.
A pointer to a function in programming languages like C/C++ and similar languages, points to the memory address of the function code in the computer's memory.
a pointer to a function is a variable that stores the memory address of a function, allowing you to call the function indirectly through the pointer.
This can be useful in situations where you want to pass a function as an argument to another function, or when you want to select a function to call at runtime based on some criteria.
Pointer to function can also be used to implement various programming techniques like callbacks, function pointers, virtual functions, etc.

## facts about c function pointers
1) Unlike normal pointers, a function pointer points to code, not data. Typically a function pointer stores the start of executable code
2) Unlike normal pointers, we do not allocate de-allocate memory using function pointers.

3) A function’s name can also be used to get functions’ address. For example, in the below program, we have removed address operator ‘&’ in assignment. We have also changed function call by removing *, the program still works.
4) Like normal pointers, we can have an array of function pointers.
5) Function pointer can be used in place of switch case. 
6) Like normal data pointers, a function pointer can be passed as an argument and can also be returned from a function.
7) Many object oriented features in C++ are implemented using function pointers in C
