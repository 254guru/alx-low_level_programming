# Bit Manipulation
Bit manipulation is the process of manipulating individual bits or groups of bits within a binary number. It is a fundamental concept in computer science and is used in a wide variety of applications, such as cryptography, computer graphics, and network protocols.
In programming, bit manipulation is commonly used to optimize algorithms and data structures, as well as to perform low-level operations such as encoding and decoding of data. Bit manipulation can be done using bitwise operators such as AND, OR, XOR, and NOT, as well as shift operators such as left shift and right shift.

#### Binary
Binary is a base-2 number system that uses two symbols, typically "0" and "1", to represent numbers. Each digit in a binary number is called a bit, and each bit represents a power of two starting from 2^0 on the rightmost bit and doubling the power for each subsequent bit to the left.
#### Hexadecimal
Hexadecimal is a numbering system that uses 16 as its base. It is often used in computing because it is a more compact way of representing binary data. In hexadecimal, the digits are represented by the numbers 0-9 and the letters A-F. The value of each digit is determined by its position in the number, with the rightmost digit representing the units, the next digit to the left representing the sixteens, the next representing the 256s, and so on.
#### Decimal
Decimal is a numbering system that uses 10 as its base. It is the most commonly used number system in everyday life and is used in mathematics, finance, and many other fields. In decimal, the digits are represented by the numbers 0-9, and the value of each digit is determined by its position in the number. The rightmost digit represents the units, the next digit to the left represents the tens, the next represents the hundreds, and so on.

## Bitwise operators
	AND - denoted by &
	OR - denoted by |
	XOR - denoted by ^
	NOT - denoted by ~

### NOT
In bit manipulation, the NOT operator (also known as bitwise complement operator) is a unary operator that flips each bit of the operand. The result of the operation is a new binary number where each 0 bit in the original number is replaced by a 1 bit, and each 1 bit is replaced by a 0 bit.

### XOR
In bit manipulation, the XOR operator is a bitwise operator that performs a logical XOR (exclusive OR) operation on each pair of corresponding bits in two binary numbers. The result of the operation is a new binary number where each bit is set to 1 only if one of the corresponding bits in the input numbers is set to 1, but not both. If both corresponding bits are set to 0 or both corresponding bits are set to 1, then the result bit is set to 0.

### OR
In bit manipulation, the OR operator is a bitwise operator that performs a logical OR operation on each pair of corresponding bits in two binary numbers. The result of the operation is a new binary number where each bit is set to 1 if at least one of the corresponding bits in the input numbers is set to 1. If both of the corresponding bits are set to 0, then the result bit is set to 0.

### AND
In bit manipulation, the AND operator is a bitwise operator that performs a logical AND operation on each pair of corresponding bits in two binary numbers. The result of the operation is a new binary number where each bit is set to 1 only if both corresponding bits in the input numbers are set to 1. If either or both of the corresponding bits are set to 0, then the result bit is set to 0.
