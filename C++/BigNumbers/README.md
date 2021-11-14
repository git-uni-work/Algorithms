# Big numbers


The task is to develop a C++ class `CBigInt` representing integers (both positive and negative) with virtually unlimited range.

Built-in integer data types like `int` and `long long int` have a fixed size, thus the range is fixed too. If the computation requires a bigger range, a custom data type must be used to represent the numbers. Our class representing big integers will use dynamically allocated memory to store the numbers. Thus the range will be unlimited (only the size of the available memory is the limit). Your task is to implement the class. To simplify the task, we adopted certain limitations:

-   Only integers are considered. The class will not have to care for decimal/fractional numbers.
-   The class will only support basic math operations: addition, multiplication, and comparison.

The class shall conform to the following interface:

default constructor

the constructor will prepare an object representing number 0.

constructor with an integer parameter

the constructor will initialize the object with the value given by the integer parameter.

constructor with string (ASCIIZ) parameter

the constructor will initialize the object with the number passed as the parameter. The number parameter is in the decimal notation. If the string does not represent a valid decimal number, the constructor must throw `invalid_argument` exception. This exception is declared in the standard library (header `stdexcept`). The constructor of `invalid_argument` takes one parameter - a textual description of the problem. The description string may be just anything in this homework.

copy constructor

the constructor will be implemented if your internal representation requires it.

destructor

destructor will be present if your internal representation requires it.

overloaded operator=

the operator will allow assignments from integer, ASCIIZ string and `CBigInt` instance (right-hand side) to a `CBigInt` instance (left-hand side).

operator \<\<

will output an instance of `CBigInt` to an output stream. The output will be in decimal, without unnecessary leading zeros.

operator \>\>

will read an instance of `CBigInt` from an input stream (the input will be in decimal).

operator +

this operator adds two instances of:

-   `CBigInt + CBigInt`,
-   `CBigInt + int`,
-   `CBigInt + ASCIIZ string`,
-   `int + CBigInt`, and
-   `ASCIIZ string + CBigInt`.

operator +=

this operator will add the right-hand operand to the left-hand operand. Valid right-hand operands are `CBigInt`, integer, and ASCIIZ string (representing a decimal number).

operator \*

this operator multiplies two integers, operands are the same as in the case of the addition operator,

operator \*=

this operator will multiply the left hand operand with the value of the right-hand operand. Valid right-hand operands are be `CBigInt`, integer, and ASCIIZ string (representing a decimal number).

relational operators (\< \<=, \> \>=, == and !=)

are designated to compare two integers, the types of operands are the same as in the case of the addition and multiplication.

Submit a source file with your implementation of `CBigInt` class. The submitted file shall not contain any \#include directives nor `main` function. If your `main` function or \#include remains in the file, please place them into a conditional compile block (use the attached example).

This task does not provide the required class interface. Instead, you are expected to develop the interface yourself. Use the description above and your knowledge of overloaded operators.

* * * * *

**Advice:**

-   The testing environment outputs your `CBigInt` objects to memory output stream to examine the value they hold. If your overloaded operator `<<` does not work properly, all tests will be negative.
-   Implement the output operator properly -- do not blindly sent the data to `cout`. Instead, send the data to the output stream passed as the parameter. Output only the digits representing the number. Avoid unnecessary leading zeros, do not add any whitespace/newline characters.
-   If your program does not compile (and especially if it compiles locally, however it does not compile in Progtest), there might be some problem in your interface design. Check your operator overloads, pay special attention to `const` qualifiers.
-   How to implement the class -- the simplest solution stores a string representing the number in a decimal notation. Store the absolute value and a separate flag distinguishing positive/negative numbers. Addition and multiplication may be implemented using algorithms we learned in the basic school. A correct implementation of this basic idea results in a simple solution which will pass all tests except the bonus tests (the solution is rather slow).
-   The first bonus test requires much faster implementation (thus a better representation). A binary representation is recommended. The test attempts to solve a factorial of a big number (e.g. 5000!).
-   The second bonus test requires even faster multiplication of big numbers. The test multiplies numbers ten-to-hundred thousand decimal digits long. Binary representation is a need, moreover, an advanced multiplication algorithm must be used (Karatsuba algorithm, multiplication based on FFT). Note that the implementation of the advanced multiplication algorithm significantly increases the length of the source code.
-   Stream input must correctly manipulate the stream status (fail bit). The behavior of `CBigInt` shall follow the behavior of the built-in `int`. The input stream shall be read while there are valid decimal digits in the input. The leading whitespace and leading unnecessary zeros shall be skipped over silently. The reading stops on the first character which is not a valid decimal digit. The reading succeeds if there were at least one decimal digit in the input. Otherwise, the input fails (i.e., it fails only if there were no decimal digits in the input). In the case of a failure, the value contained in the object shall remain unchanged (see value 999 in the sample run) and fail bit in the stream shall be set. Use `is . setstate (ios::failbit)` to modify the status. Your may find helpful method `is . peek()`. This method reads the next character in the stream like `is . get()` does, however, the `peek` method does not actually remove the character from the stream. Caution -- the behavior is a bit different from the string processing in the constructor.
-   Decimal values in string (the operands of operators +, +=, \*, \*=, ==, ...) are to be processed by the `CBigInt` constructor. Thus, the operation may throw `invalid_argument` exception if the string is not valid. We require that the entire string is a valid integer here, i.e., the processing of `CBigInt ( "12x" )` throws an exception (reading the same characters from an input stream would have succeeded, stopping at the character 'x').
-   The class requires 10 operators overloaded for many data types (`CBigInt`, integer, ASCIIZ strings). Use all C++ features to minimize the number of operators/methods you will actually implement (user conversion constructor, implicit parameters, ...).
-   STL classes `std::vector` and `std::string` are available.
-   `CBigInt` instances are often copied/moved in the arithmetic operations. If you decide to store the number data in a dynamically allocated structure and you decide to manage the structure by yourself, you have to implement copy constructor, operator =, and a destructor (an optionally the move variants). Such implementation is possible, but we discourage you from doing so. Use the STL containers, object composition, and the automatically generated constructors/operators=/destructor ([rule of zero](https://en.cppreference.com/w/cpp/language/rule_of_three)).
-   A working solution of this homework may be used for code review (your solution must pass the mandatory and optional tests with 100% result; the solution does not have to pass the bonus tests).

* * * * *

**Advice, updated**

-   `CBigInt` instances may be constructed from strings with leading zeros, e.g., `CBigInt ( "0012122" )`. Such string are considered valid **decimal** numbers.
-   Both input and output conversions do decimal conversions only (they do not have to handle manipulators like `hex`, `oct`, ...).
-   The second bonus test is rather difficult. You have to choose a reasonable representation of the number and implement a fast multiplication algorithm. You may have chosen a representation - array of integers (e.g., `vector<int>`), where the array elements may hold values between 0 to 1000000000 (modulus 10<sup>9</sup>, indeed, the number is expressed as a number in base 1 billion). Such representation is not efficient enough to pass the second bonus. The representation requires frequent divisions by 1 billion and modulus by 1 billion. These operations are rather slow, especially in the multiplication. Instead, consider the following idea:
    -   the values are stored in `vector<uint32_t>`,
    -   full `uint32_t` capacity is used,
    -   indeed, the numbers are represented as base 2<sup>32</sup> numbers,
    -   division/modulus by 10<sup>9</sup> is replaced with a division/modulus by 2<sup>32</sup>. The latter two operations are implemented by means of bit masks/bit shifts/done implicitly (e.g., an assignment from `uint64_t` to `uint32_t` discards the upper 32 bits, thus implicitly does modulus by 2<sup>32</sup>),
    -   such representation requires different addition and subtraction algorithms,
    -   next, the conversions from/to decimal are more complicated,
    -   however, the multiplication is faster. Combined with the Karatsuba algorithm, the implementation passes the second bonus,
    -   as previously stated, the second bonus is rather laborious. On the other hand, it is assessed by extra 50% points.
-   One more test case in the example tests.
