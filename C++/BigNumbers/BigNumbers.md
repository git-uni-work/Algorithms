||
|[ProgTest](https://progtest.fit.cvut.cz/index.php?X=Main)  ►  [BIE-PA2 (19/20 LS)](https://progtest.fit.cvut.cz/index.php?X=Course&Cou=293)  ►  [Homework 03](https://progtest.fit.cvut.cz/index.php?X=TaskGrp&Cou=293&Tgr=1848)  ►  **Big numbers**|[Logout](https://progtest.fit.cvut.cz/index.php?X=Logout)|

||
|**Big numbers**|

**Submission deadline:**

**2020-04-05 23:59:59**

 

**Late submission with malus:**

**2020-06-30 23:59:59** (Late submission malus: 100.0000 %)

**Evaluation:**

**6.2510**

**Max. assessment:**

**7.1500** (Without bonus points)

**Submissions:**

23 / 25 Free retries + 20 Penalized retries (-2 % penalty each retry)

**Advices:**

2 / 2 Advices for free + 2 Advices with a penalty (-10 % penalty each advice)

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

**Advice, updated on 2020-03-23:**

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

**Sample data:**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskS&Cou=293&Tgr=1848&Tsk=1641)

 **Reference**

 

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Zakladni test s parametry podle ukazky': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.001 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Test nahodnymi vstupy (op=, op \<\<)': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.016 s (limit: 0.999 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Test nahodnymi vstupy (op=, op \<\<, op +)': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.021 s (limit: 2.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Test nahodnymi vstupy (op=, op \<\<, op +, op\*)': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.035 s (limit: 1.979 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Test nahodnymi vstupy (op=, op \<\<, op +, op\*, op \>': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.019 s (limit: 1.944 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Test relacnich operatoru (\<, \<=, ...)': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.094 s (limit: 1.925 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Test kopirujiciho konstruktoru': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.831 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Test operatoru=': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.830 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Test operatoru v meznich podminkach': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.829 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Test rychlosti (faktorial)': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 1.294 s (limit: 2.000 s)
        -   Bonus test - success, evaluation: 120.00 %
    -   Test 'Test rychlosti (nasobeni pro velka cisla)': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 5.479 s (limit: 8.000 s)
        -   Bonus test - success, evaluation: 150.00 %
    -   Overall ratio: 180.00 % (= 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.20 \* 1.50)
-   Total percent: 180.00 %
-   Early submission bonus: 0.72
-   Total points: 1.80 \* ( 7.15 + 0.72 ) = 14.16

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**31**|--|--|--|
|Lines of code:|**399**|12.87 ± 9.59|38|`CBigInt::mulRecurse`|
|Cyclomatic complexity:|**95**|3.06 ± 2.42|9|`CBigInt::cmp`|

**23**

**2020-04-05 23:58:32**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1848&Tsk=1641&Sub=1154410)

**Submission status:**

Evaluated

 

**Evaluation:**

5.6792

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op\<\< )': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.005 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op \<\<, op +)': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.006 s (limit: 2.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op \<\<, op +, op\*)': success
        -   result: 87.50 %, required: 50.00 %
        -   Total run time: 0.043 s (limit: 1.994 s)
        -   Optional test success, evaluation: 87.50 %
        -   Failed (invalid output) [[Unlock advice (507 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554491'))
        -   Failed (invalid output) [[Unlock advice (927 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554492'))
        -   Failed (invalid output) [[Unlock advice (1.43 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554493'))
        -   Failed (invalid output) [[Unlock advice (282 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554494'))
        -   Failed (invalid output) [[Unlock advice (2.10 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554495'))
        -   Failed (invalid output) [[Unlock advice (1.57 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554496'))
        -   Failed (invalid output) [[Unlock advice (1.65 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554497'))
        -   Failed (invalid output) [[Unlock advice (1.97 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554498'))
    -   Test 'Random test (op=, op \<\<, op +, op\*, op \>\>)': success
        -   result: 96.18 %, required: 50.00 %
        -   Total run time: 0.020 s (limit: 1.951 s)
        -   Optional test success, evaluation: 96.18 %
        -   Failed (invalid output) [[Unlock advice (449 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554499'))
        -   Failed (invalid output) [[Unlock advice (932 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554500'))
        -   Failed (invalid output) [[Unlock advice (691 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554501'))
        -   Failed (invalid output) [[Unlock advice (996 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554502'))
        -   Failed (invalid output) [[Unlock advice (1.33 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554503'))
        -   Failed (invalid output) [[Unlock advice (1.33 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554504'))
    -   Test 'Relational operators (\<, \<=, ... )': success
        -   result: 94.38 %, required: 50.00 %
        -   Total run time: 0.054 s (limit: 1.931 s)
        -   Optional test success, evaluation: 94.38 %
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554505'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554506'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554507'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554508'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554509'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554510'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554511'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554512'))
    -   Test 'Copy constructor test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.877 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Assignment operator test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.876 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Operator pitfalls test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.875 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test (factorial)': Abnormal program termination (Time limit exceeded)
        -   Cumulative test time exceeded, killed after:: 2.006 s (limit: 2.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Test 'Speed test (big number multiplication)': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 79.43 % (= 1.00 \* 1.00 \* 1.00 \* 0.88 \* 0.96 \* 0.94 \* 1.00 \* 1.00 \* 1.00)
-   Advices used: 2
-   Penalty due to advices: None (2 \<= 2 limit)
-   Total percent: 79.43 %
-   Total points: 0.79 \* 7.15 = 5.68

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**75**|--|--|--|
|Lines of code:|**905**|12.07 ± 13.59|93|`main`|
|Cyclomatic complexity:|**198**|2.64 ± 2.68|12|`multiply`|

**22**

**2020-04-05 23:54:16**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1848&Tsk=1641&Sub=1154382)

**Submission status:**

Evaluated

 

**Evaluation:**

5.6345

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op\<\< )': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.009 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op \<\<, op +)': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.010 s (limit: 2.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op \<\<, op +, op\*)': success
        -   result: 82.79 %, required: 50.00 %
        -   Total run time: 0.056 s (limit: 1.990 s)
        -   Optional test success, evaluation: 82.79 %
        -   Failed (invalid output) [[Unlock advice (854 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554182'))
        -   Failed (invalid output) [[Unlock advice (663 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554183'))
        -   Failed (invalid output) [[Unlock advice (794 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554184'))
        -   Failed (invalid output) [[Unlock advice (686 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554185'))
        -   Failed (invalid output) [[Unlock advice (1.91 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554186'))
        -   Failed (invalid output) [[Unlock advice (1.29 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554187'))
        -   Failed (invalid output) [[Unlock advice (1.38 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554188'))
        -   Failed (invalid output) [[Unlock advice (1.70 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554189'))
    -   Test 'Random test (op=, op \<\<, op +, op\*, op \>\>)': success
        -   result: 99.36 %, required: 50.00 %
        -   Total run time: 0.030 s (limit: 1.934 s)
        -   Optional test success, evaluation: 99.36 %
        -   Failed (invalid output) [[Unlock advice (720 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554190'))
    -   Test 'Relational operators (\<, \<=, ... )': success
        -   result: 95.80 %, required: 50.00 %
        -   Total run time: 0.052 s (limit: 1.904 s)
        -   Optional test success, evaluation: 95.80 %
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554191'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554192'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554193'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554194'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554195'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554196'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554197'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3554198'))
    -   Test 'Copy constructor test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.852 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Assignment operator test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.851 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Operator pitfalls test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.850 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test (factorial)': Abnormal program termination (Time limit exceeded)
        -   Cumulative test time exceeded, killed after:: 2.006 s (limit: 2.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Test 'Speed test (big number multiplication)': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 78.81 % (= 1.00 \* 1.00 \* 1.00 \* 0.83 \* 0.99 \* 0.96 \* 1.00 \* 1.00 \* 1.00)
-   Advices used: 2
-   Penalty due to advices: None (2 \<= 2 limit)
-   Total percent: 78.81 %
-   Total points: 0.79 \* 7.15 = 5.63

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**75**|--|--|--|
|Lines of code:|**905**|12.07 ± 13.59|93|`main`|
|Cyclomatic complexity:|**198**|2.64 ± 2.68|12|`multiply`|

**21**

**2020-04-05 23:50:19**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1848&Tsk=1641&Sub=1154363)

**Submission status:**

Evaluated

 

**Evaluation:**

5.6239

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op\<\< )': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.008 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op \<\<, op +)': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.012 s (limit: 2.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op \<\<, op +, op\*)': success
        -   result: 88.00 %, required: 50.00 %
        -   Total run time: 0.064 s (limit: 1.988 s)
        -   Optional test success, evaluation: 88.00 %
        -   Failed (invalid output) [[Unlock advice (530 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553920'))
        -   Failed (invalid output) [[Unlock advice (1.27 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553921'))
        -   Failed (invalid output) [[Unlock advice (1.03 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553922'))
        -   Failed (invalid output) [[Unlock advice (1.42 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553923'))
        -   Failed (invalid output) [[Unlock advice (1.35 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553924'))
        -   Failed (invalid output) [[Unlock advice (3.35 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553925'))
        -   Failed (invalid output) [[Unlock advice (4.00 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553926'))
        -   Failed (invalid output) [[Unlock advice (1.18 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553927'))
    -   Test 'Random test (op=, op \<\<, op +, op\*, op \>\>)': success
        -   result: 97.37 %, required: 50.00 %
        -   Total run time: 0.026 s (limit: 1.924 s)
        -   Optional test success, evaluation: 97.37 %
        -   Failed (invalid output) [[Unlock advice (968 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553928'))
        -   Failed (invalid output) [[Unlock advice (1.37 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553929'))
        -   Failed (invalid output) [[Unlock advice (1.95 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553930'))
        -   Failed (invalid output) [[Unlock advice (620 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553931'))
    -   Test 'Relational operators (\<, \<=, ... )': success
        -   result: 91.80 %, required: 50.00 %
        -   Total run time: 0.061 s (limit: 1.898 s)
        -   Optional test success, evaluation: 91.80 %
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553932'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553933'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553934'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553935'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553936'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553937'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553938'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553939'))
    -   Test 'Copy constructor test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.837 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Assignment operator test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.000 s (limit: 1.836 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Operator pitfalls test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.000 s (limit: 1.836 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test (factorial)': Abnormal program termination (Time limit exceeded)
        -   Cumulative test time exceeded, killed after:: 2.006 s (limit: 2.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Test 'Speed test (big number multiplication)': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 78.66 % (= 1.00 \* 1.00 \* 1.00 \* 0.88 \* 0.97 \* 0.92 \* 1.00 \* 1.00 \* 1.00)
-   Advices used: 2
-   Penalty due to advices: None (2 \<= 2 limit)
-   Total percent: 78.66 %
-   Total points: 0.79 \* 7.15 = 5.62

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**75**|--|--|--|
|Lines of code:|**905**|12.07 ± 13.59|93|`main`|
|Cyclomatic complexity:|**198**|2.64 ± 2.68|12|`multiply`|

**20**

**2020-04-05 23:47:18**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1848&Tsk=1641&Sub=1154345)

**Submission status:**

Evaluated

 

**Evaluation:**

4.6637

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op\<\< )': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.009 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op \<\<, op +)': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.010 s (limit: 2.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op \<\<, op +, op\*)': success
        -   result: 69.49 %, required: 50.00 %
        -   Total run time: 0.079 s (limit: 1.990 s)
        -   Optional test success, evaluation: 69.49 %
        -   Failed (invalid output) [[Unlock advice (1.20 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553866'))
        -   Failed (invalid output) [[Unlock advice (1.30 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553867'))
        -   Failed (invalid output) [[Unlock advice (1.58 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553868'))
        -   Failed (invalid output) [[Unlock advice (1.66 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553869'))
        -   Failed (invalid output) [[Unlock advice (1.81 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553870'))
        -   Failed (invalid output) [[Unlock advice (4.00 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553871'))
        -   Failed (invalid output) [[Unlock advice (4.00 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553872'))
        -   Failed (invalid output) [[Unlock advice (4.00 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553873'))
    -   Test 'Random test (op=, op \<\<, op +, op\*, op \>\>)': success
        -   result: 99.35 %, required: 50.00 %
        -   Total run time: 0.023 s (limit: 1.911 s)
        -   Optional test success, evaluation: 99.35 %
        -   Failed (invalid output) [[Unlock advice (711 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553874'))
    -   Test 'Relational operators (\<, \<=, ... )': success
        -   result: 94.48 %, required: 50.00 %
        -   Total run time: 0.050 s (limit: 1.888 s)
        -   Optional test success, evaluation: 94.48 %
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553875'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553876'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553877'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553878'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553879'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553880'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553881'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553882'))
    -   Test 'Copy constructor test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.838 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Assignment operator test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.837 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Operator pitfalls test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.000 s (limit: 1.836 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test (factorial)': Abnormal program termination (Time limit exceeded)
        -   Cumulative test time exceeded, killed after:: 2.006 s (limit: 2.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Test 'Speed test (big number multiplication)': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 65.23 % (= 1.00 \* 1.00 \* 1.00 \* 0.69 \* 0.99 \* 0.94 \* 1.00 \* 1.00 \* 1.00)
-   Advices used: 2
-   Penalty due to advices: None (2 \<= 2 limit)
-   Total percent: 65.23 %
-   Total points: 0.65 \* 7.15 = 4.66

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**75**|--|--|--|
|Lines of code:|**905**|12.07 ± 13.59|93|`main`|
|Cyclomatic complexity:|**198**|2.64 ± 2.68|12|`multiply`|

**19**

**2020-04-05 23:45:28**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1848&Tsk=1641&Sub=1154334)

**Submission status:**

Evaluated

 

**Evaluation:**

5.0449

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op\<\< )': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.005 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op \<\<, op +)': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.011 s (limit: 2.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op \<\<, op +, op\*)': success
        -   result: 77.87 %, required: 50.00 %
        -   Total run time: 0.054 s (limit: 1.989 s)
        -   Optional test success, evaluation: 77.87 %
        -   Failed (invalid output) [[Unlock advice (419 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553774'))
        -   Failed (invalid output) [[Unlock advice (686 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553775'))
        -   Failed (invalid output) [[Unlock advice (766 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553776'))
        -   Failed (invalid output) [[Unlock advice (1.70 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553777'))
        -   Failed (invalid output) [[Unlock advice (1.71 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553778'))
        -   Failed (invalid output) [[Unlock advice (1023 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553779'))
        -   Failed (invalid output) [[Unlock advice (1.41 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553780'))
        -   Failed (invalid output) [[Unlock advice (1.48 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553781'))
    -   Test 'Random test (op=, op \<\<, op +, op\*, op \>\>)': success
        -   result: 97.35 %, required: 50.00 %
        -   Total run time: 0.028 s (limit: 1.935 s)
        -   Optional test success, evaluation: 97.35 %
        -   Failed (invalid output) [[Unlock advice (732 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553782'))
        -   Failed (invalid output) [[Unlock advice (848 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553783'))
        -   Failed (invalid output) [[Unlock advice (274 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553784'))
        -   Failed (invalid output) [[Unlock advice (367 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553785'))
    -   Test 'Relational operators (\<, \<=, ... )': success
        -   result: 93.08 %, required: 50.00 %
        -   Total run time: 0.062 s (limit: 1.907 s)
        -   Optional test success, evaluation: 93.08 %
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553786'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553787'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553788'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553789'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553790'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553791'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553792'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553793'))
    -   Test 'Copy constructor test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.845 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Assignment operator test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.844 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Operator pitfalls test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.000 s (limit: 1.843 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test (factorial)': Abnormal program termination (Time limit exceeded)
        -   Cumulative test time exceeded, killed after:: 2.005 s (limit: 2.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Test 'Speed test (big number multiplication)': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 70.56 % (= 1.00 \* 1.00 \* 1.00 \* 0.78 \* 0.97 \* 0.93 \* 1.00 \* 1.00 \* 1.00)
-   Advices used: 2
-   Penalty due to advices: None (2 \<= 2 limit)
-   Total percent: 70.56 %
-   Total points: 0.71 \* 7.15 = 5.05

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**79**|--|--|--|
|Lines of code:|**933**|11.81 ± 13.29|93|`main`|
|Cyclomatic complexity:|**201**|2.54 ± 2.60|12|`multiply`|

**18**

**2020-04-05 23:42:25**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1848&Tsk=1641&Sub=1154319)

**Submission status:**

Evaluated

 

**Evaluation:**

5.4883

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op\<\< )': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.008 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op \<\<, op +)': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.011 s (limit: 2.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op \<\<, op +, op\*)': success
        -   result: 84.50 %, required: 50.00 %
        -   Total run time: 0.054 s (limit: 1.989 s)
        -   Optional test success, evaluation: 84.50 %
        -   Failed (invalid output) [[Unlock advice (498 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553680'))
        -   Failed (invalid output) [[Unlock advice (735 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553681'))
        -   Failed (invalid output) [[Unlock advice (541 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553682'))
        -   Failed (invalid output) [[Unlock advice (660 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553683'))
        -   Failed (invalid output) [[Unlock advice (1.28 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553684'))
        -   Failed (invalid output) [[Unlock advice (988 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553685'))
        -   Failed (invalid output) [[Unlock advice (1.04 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553686'))
        -   Failed (invalid output) [[Unlock advice (1.15 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553687'))
    -   Test 'Random test (op=, op \<\<, op +, op\*, op \>\>)': success
        -   result: 96.15 %, required: 50.00 %
        -   Total run time: 0.022 s (limit: 1.935 s)
        -   Optional test success, evaluation: 96.15 %
        -   Failed (invalid output) [[Unlock advice (956 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553688'))
        -   Failed (invalid output) [[Unlock advice (1.39 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553689'))
        -   Failed (invalid output) [[Unlock advice (1.71 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553690'))
        -   Failed (invalid output) [[Unlock advice (1.82 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553691'))
        -   Failed (invalid output) [[Unlock advice (854 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553692'))
        -   Failed (invalid output) [[Unlock advice (1.31 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553693'))
    -   Test 'Relational operators (\<, \<=, ... )': success
        -   result: 94.48 %, required: 50.00 %
        -   Total run time: 0.060 s (limit: 1.913 s)
        -   Optional test success, evaluation: 94.48 %
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553694'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553695'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553696'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553697'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553698'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553699'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553700'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553701'))
    -   Test 'Copy constructor test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.853 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Assignment operator test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.000 s (limit: 1.852 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Operator pitfalls test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.852 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test (factorial)': Abnormal program termination (Time limit exceeded)
        -   Cumulative test time exceeded, killed after:: 2.005 s (limit: 2.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Test 'Speed test (big number multiplication)': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 76.76 % (= 1.00 \* 1.00 \* 1.00 \* 0.84 \* 0.96 \* 0.94 \* 1.00 \* 1.00 \* 1.00)
-   Advices used: 2
-   Penalty due to advices: None (2 \<= 2 limit)
-   Total percent: 76.76 %
-   Total points: 0.77 \* 7.15 = 5.49

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**79**|--|--|--|
|Lines of code:|**947**|11.99 ± 14.01|93|`main`|
|Cyclomatic complexity:|**204**|2.58 ± 2.72|12|`multiply`|

**17**

**2020-04-05 23:40:26**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1848&Tsk=1641&Sub=1154308)

**Submission status:**

Evaluated

 

**Evaluation:**

5.8523

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op\<\< )': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.006 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op \<\<, op +)': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.011 s (limit: 2.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op \<\<, op +, op\*)': success
        -   result: 87.07 %, required: 50.00 %
        -   Total run time: 0.110 s (limit: 1.989 s)
        -   Optional test success, evaluation: 87.07 %
        -   Failed (invalid output) [[Unlock advice (693 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553643'))
        -   Failed (invalid output) [[Unlock advice (1.01 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553644'))
        -   Failed (invalid output) [[Unlock advice (1.32 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553645'))
        -   Failed (invalid output) [[Unlock advice (1.70 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553646'))
        -   Failed (invalid output) [[Unlock advice (4.00 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553647'))
        -   Failed (invalid output) [[Unlock advice (3.00 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553648'))
        -   Failed (invalid output) [[Unlock advice (3.74 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553649'))
        -   Failed (invalid output) [[Unlock advice (3.74 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553650'))
    -   Test 'Random test (op=, op \<\<, op +, op\*, op \>\>)': success
        -   result: 96.79 %, required: 50.00 %
        -   Total run time: 0.017 s (limit: 1.879 s)
        -   Optional test success, evaluation: 96.79 %
        -   Failed (invalid output) [[Unlock advice (859 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553651'))
        -   Failed (invalid output) [[Unlock advice (1.02 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553652'))
        -   Failed (invalid output) [[Unlock advice (1.44 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553653'))
        -   Failed (invalid output) [[Unlock advice (347 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553654'))
        -   Failed (invalid output) [[Unlock advice (720 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553655'))
    -   Test 'Relational operators (\<, \<=, ... )': success
        -   result: 97.12 %, required: 50.00 %
        -   Total run time: 0.052 s (limit: 1.862 s)
        -   Optional test success, evaluation: 97.12 %
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553656'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553657'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553658'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553659'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553660'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553661'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553662'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553663'))
    -   Test 'Copy constructor test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.810 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Assignment operator test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.809 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Operator pitfalls test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.808 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test (factorial)': Abnormal program termination (Time limit exceeded)
        -   Cumulative test time exceeded, killed after:: 2.004 s (limit: 2.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Test 'Speed test (big number multiplication)': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 81.85 % (= 1.00 \* 1.00 \* 1.00 \* 0.87 \* 0.97 \* 0.97 \* 1.00 \* 1.00 \* 1.00)
-   Advices used: 2
-   Penalty due to advices: None (2 \<= 2 limit)
-   Total percent: 81.85 %
-   Total points: 0.82 \* 7.15 = 5.85

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**79**|--|--|--|
|Lines of code:|**947**|11.99 ± 14.01|93|`main`|
|Cyclomatic complexity:|**204**|2.58 ± 2.72|12|`multiply`|

**16**

**2020-04-05 23:36:05**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1848&Tsk=1641&Sub=1154294)

**Submission status:**

Evaluated

 

**Evaluation:**

5.8124

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op\<\< )': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.009 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op \<\<, op +)': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.011 s (limit: 2.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op \<\<, op +, op\*)': success
        -   result: 89.06 %, required: 50.00 %
        -   Total run time: 0.056 s (limit: 1.989 s)
        -   Optional test success, evaluation: 89.06 %
        -   Failed (invalid output) [[Unlock advice (536 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553584'))
        -   Failed (invalid output) [[Unlock advice (850 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553585'))
        -   Failed (invalid output) [[Unlock advice (1.07 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553586'))
        -   Failed (invalid output) [[Unlock advice (1.70 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553587'))
        -   Failed (invalid output) [[Unlock advice (1.67 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553588'))
        -   Failed (invalid output) [[Unlock advice (1.88 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553589'))
        -   Failed (invalid output) [[Unlock advice (2.09 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553590'))
        -   Failed (invalid output) [[Unlock advice (1.36 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553591'))
    -   Test 'Random test (op=, op \<\<, op +, op\*, op \>\>)': success
        -   result: 98.06 %, required: 50.00 %
        -   Total run time: 0.020 s (limit: 1.933 s)
        -   Optional test success, evaluation: 98.06 %
        -   Failed (invalid output) [[Unlock advice (620 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553592'))
        -   Failed (invalid output) [[Unlock advice (812 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553593'))
        -   Failed (invalid output) [[Unlock advice (812 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553594'))
    -   Test 'Relational operators (\<, \<=, ... )': success
        -   result: 93.08 %, required: 50.00 %
        -   Total run time: 0.057 s (limit: 1.913 s)
        -   Optional test success, evaluation: 93.08 %
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553595'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553596'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553597'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553598'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553599'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553600'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553601'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3553602'))
    -   Test 'Copy constructor test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.856 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Assignment operator test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.855 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Operator pitfalls test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.000 s (limit: 1.854 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test (factorial)': Abnormal program termination (Time limit exceeded)
        -   Cumulative test time exceeded, killed after:: 2.004 s (limit: 2.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Test 'Speed test (big number multiplication)': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 81.29 % (= 1.00 \* 1.00 \* 1.00 \* 0.89 \* 0.98 \* 0.93 \* 1.00 \* 1.00 \* 1.00)
-   Advices used: 2
-   Penalty due to advices: None (2 \<= 2 limit)
-   Total percent: 81.29 %
-   Total points: 0.81 \* 7.15 = 5.81

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**79**|--|--|--|
|Lines of code:|**933**|11.81 ± 13.29|93|`main`|
|Cyclomatic complexity:|**202**|2.56 ± 2.64|12|`multiply`|

**15**

**2020-04-05 21:55:46**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1848&Tsk=1641&Sub=1154061)

**Submission status:**

Evaluated

 

**Evaluation:**

5.8569

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op\<\< )': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.008 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op \<\<, op +)': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.008 s (limit: 2.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op \<\<, op +, op\*)': success
        -   result: 85.48 %, required: 50.00 %
        -   Total run time: 0.048 s (limit: 1.992 s)
        -   Optional test success, evaluation: 85.48 %
        -   Failed (invalid output) [[Unlock advice (526 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552264'))
        -   Failed (invalid output) [[Unlock advice (880 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552265'))
        -   Failed (invalid output) [[Unlock advice (820 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552266'))
        -   Failed (invalid output) [[Unlock advice (1.20 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552267'))
        -   Failed (invalid output) [[Unlock advice (3.67 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552268'))
        -   Failed (invalid output) [[Unlock advice (2.68 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552269'))
        -   Failed (invalid output) [[Unlock advice (3.45 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552270'))
        -   Failed (invalid output) [[Unlock advice (3.67 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552271'))
    -   Test 'Random test (op=, op \<\<, op +, op\*, op \>\>)': success
        -   result: 98.67 %, required: 50.00 %
        -   Total run time: 0.020 s (limit: 1.944 s)
        -   Optional test success, evaluation: 98.67 %
        -   Failed (invalid output) [[Unlock advice (898 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552272'))
        -   Failed (invalid output) [[Unlock advice (416 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552273'))
    -   Test 'Relational operators (\<, \<=, ... )': success
        -   result: 97.12 %, required: 50.00 %
        -   Total run time: 0.055 s (limit: 1.924 s)
        -   Optional test success, evaluation: 97.12 %
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552274'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552275'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552276'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552277'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552278'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552279'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552280'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552281'))
    -   Test 'Copy constructor test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.869 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Assignment operator test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.868 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Operator pitfalls test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.000 s (limit: 1.867 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test (factorial)': Abnormal program termination (Time limit exceeded)
        -   Cumulative test time exceeded, killed after:: 2.006 s (limit: 2.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Test 'Speed test (big number multiplication)': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 81.91 % (= 1.00 \* 1.00 \* 1.00 \* 0.85 \* 0.99 \* 0.97 \* 1.00 \* 1.00 \* 1.00)
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 81.91 %
-   Total points: 0.82 \* 7.15 = 5.86

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**81**|--|--|--|
|Lines of code:|**947**|11.69 ± 13.15|93|`main`|
|Cyclomatic complexity:|**204**|2.52 ± 2.62|12|`multiply`|

**14**

**2020-04-05 21:41:08**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1848&Tsk=1641&Sub=1154041)

**Submission status:**

Evaluated

 

**Evaluation:**

6.2510

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op\<\< )': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.008 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op \<\<, op +)': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.011 s (limit: 2.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op \<\<, op +, op\*)': success
        -   result: 94.57 %, required: 50.00 %
        -   Total run time: 0.061 s (limit: 1.989 s)
        -   Optional test success, evaluation: 94.57 %
        -   Failed (invalid output) [[Unlock advice (1.17 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552050'))
        -   Failed (invalid output) [[Unlock advice (1.23 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552051'))
        -   Failed (invalid output) [[Unlock advice (1.68 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552052'))
        -   Failed (invalid output) [[Unlock advice (2.13 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552053'))
        -   Failed (invalid output) [[Unlock advice (2.58 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552054'))
        -   Failed (invalid output) [[Unlock advice (1.26 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552055'))
        -   Failed (invalid output) [[Unlock advice (662 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552056'))
    -   Test 'Random test (op=, op \<\<, op +, op\*, op \>\>)': success
        -   result: 95.17 %, required: 50.00 %
        -   Total run time: 0.022 s (limit: 1.928 s)
        -   Optional test success, evaluation: 95.17 %
        -   Failed (invalid output) [[Unlock advice (705 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552057'))
        -   Failed (invalid output) [[Unlock advice (993 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552058'))
        -   Failed (invalid output) [[Unlock advice (1.45 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552059'))
        -   Failed (invalid output) [[Unlock advice (653 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552060'))
        -   Failed (invalid output) [[Unlock advice (912 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552061'))
        -   Failed (invalid output) [[Unlock advice (1.13 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552062'))
        -   Failed (invalid output) [[Unlock advice (702 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552063'))
    -   Test 'Relational operators (\<, \<=, ... )': success
        -   result: 97.13 %, required: 50.00 %
        -   Total run time: 0.063 s (limit: 1.906 s)
        -   Optional test success, evaluation: 97.13 %
        -    Failed (invalid output)

                 op < mismatch r=true, s=false

        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552065'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552066'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552067'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552068'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552069'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552070'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3552071'))

    -   Test 'Copy constructor test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.843 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Assignment operator test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.842 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Operator pitfalls test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.000 s (limit: 1.841 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test (factorial)': Abnormal program termination (Time limit exceeded)
        -   Cumulative test time exceeded, killed after:: 2.005 s (limit: 2.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Test 'Speed test (big number multiplication)': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 87.42 % (= 1.00 \* 1.00 \* 1.00 \* 0.95 \* 0.95 \* 0.97 \* 1.00 \* 1.00 \* 1.00)
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 87.42 %
-   Total points: 0.87 \* 7.15 = 6.25

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**75**|--|--|--|
|Lines of code:|**905**|12.07 ± 13.59|93|`main`|
|Cyclomatic complexity:|**198**|2.64 ± 2.68|12|`multiply`|

**13**

**2020-04-05 21:26:44**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1848&Tsk=1641&Sub=1154014)

**Submission status:**

Evaluated

 

**Evaluation:**

5.9866

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op\<\< )': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.006 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op \<\<, op +)': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.011 s (limit: 2.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op \<\<, op +, op\*)': success
        -   result: 92.86 %, required: 50.00 %
        -   Total run time: 0.080 s (limit: 1.989 s)
        -   Optional test success, evaluation: 92.86 %
        -   Failed (invalid output) [[Unlock advice (661 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551770'))
        -   Failed (invalid output) [[Unlock advice (948 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551771'))
        -   Failed (invalid output) [[Unlock advice (1.53 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551772'))
        -   Failed (invalid output) [[Unlock advice (2.07 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551773'))
        -   Failed (invalid output) [[Unlock advice (668 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551774'))
        -   Failed (invalid output) [[Unlock advice (2.54 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551775'))
        -   Failed (invalid output) [[Unlock advice (2.54 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551776'))
        -   Failed (invalid output) [[Unlock advice (3.43 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551777'))
    -   Test 'Random test (op=, op \<\<, op +, op\*, op \>\>)': success
        -   result: 96.88 %, required: 50.00 %
        -   Total run time: 0.015 s (limit: 1.909 s)
        -   Optional test success, evaluation: 96.88 %
        -   Failed (invalid output) [[Unlock advice (902 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551778'))
        -   Failed (invalid output) [[Unlock advice (567 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551779'))
        -   Failed (invalid output) [[Unlock advice (941 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551780'))
        -   Failed (invalid output) [[Unlock advice (1.04 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551781'))
        -   Failed (invalid output) [[Unlock advice (1.13 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551782'))
    -   Test 'Relational operators (\<, \<=, ... )': success
        -   result: 93.08 %, required: 50.00 %
        -   Total run time: 0.062 s (limit: 1.894 s)
        -   Optional test success, evaluation: 93.08 %
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551783'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551784'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551785'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551786'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551787'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551788'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551789'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551790'))
    -   Test 'Copy constructor test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.832 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Assignment operator test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.831 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Operator pitfalls test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.000 s (limit: 1.830 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test (factorial)': Abnormal program termination (Time limit exceeded)
        -   Cumulative test time exceeded, killed after:: 2.006 s (limit: 2.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Test 'Speed test (big number multiplication)': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 83.74 % (= 1.00 \* 1.00 \* 1.00 \* 0.93 \* 0.97 \* 0.93 \* 1.00 \* 1.00 \* 1.00)
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 83.74 %
-   Total points: 0.84 \* 7.15 = 5.99

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**69**|--|--|--|
|Lines of code:|**869**|12.59 ± 14.05|93|`main`|
|Cyclomatic complexity:|**192**|2.78 ± 2.75|12|`multiply`|

**12**

**2020-04-05 21:07:29**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1848&Tsk=1641&Sub=1153987)

**Submission status:**

Evaluated

 

**Evaluation:**

5.3835

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op\<\< )': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.007 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op \<\<, op +)': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.006 s (limit: 2.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op \<\<, op +, op\*)': success
        -   result: 81.30 %, required: 50.00 %
        -   Total run time: 0.054 s (limit: 1.994 s)
        -   Optional test success, evaluation: 81.30 %
        -   Failed (invalid output) [[Unlock advice (303 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551684'))
        -   Failed (invalid output) [[Unlock advice (355 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551685'))
        -   Failed (invalid output) [[Unlock advice (970 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551686'))
        -   Failed (invalid output) [[Unlock advice (970 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551687'))
        -   Failed (invalid output) [[Unlock advice (1.75 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551688'))
        -   Failed (invalid output) [[Unlock advice (560 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551689'))
        -   Failed (invalid output) [[Unlock advice (992 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551690'))
        -   Failed (invalid output) [[Unlock advice (1.41 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551691'))
    -   Test 'Random test (op=, op \<\<, op +, op\*, op \>\>)': success
        -   result: 95.33 %, required: 50.00 %
        -   Total run time: 0.029 s (limit: 1.940 s)
        -   Optional test success, evaluation: 95.33 %
        -   Failed (invalid output) [[Unlock advice (790 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551692'))
        -   Failed (invalid output) [[Unlock advice (682 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551693'))
        -   Failed (invalid output) [[Unlock advice (783 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551694'))
        -   Failed (invalid output) [[Unlock advice (1.52 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551695'))
        -   Failed (invalid output) [[Unlock advice (1.52 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551696'))
        -   Failed (invalid output) [[Unlock advice (2.32 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551697'))
        -   Failed (invalid output) [[Unlock advice (3.04 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551698'))
    -   Test 'Relational operators (\<, \<=, ... )': success
        -   result: 97.14 %, required: 50.00 %
        -   Total run time: 0.050 s (limit: 1.911 s)
        -   Optional test success, evaluation: 97.14 %
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551699'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551700'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551701'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551702'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551703'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551704'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551705'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551706'))
    -   Test 'Copy constructor test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.861 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Assignment operator test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.860 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Operator pitfalls test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.000 s (limit: 1.859 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test (factorial)': Abnormal program termination (Time limit exceeded)
        -   Cumulative test time exceeded, killed after:: 2.005 s (limit: 2.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Test 'Speed test (big number multiplication)': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 75.29 % (= 1.00 \* 1.00 \* 1.00 \* 0.81 \* 0.95 \* 0.97 \* 1.00 \* 1.00 \* 1.00)
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 75.29 %
-   Total points: 0.75 \* 7.15 = 5.38

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**67**|--|--|--|
|Lines of code:|**857**|12.79 ± 14.21|93|`main`|
|Cyclomatic complexity:|**190**|2.84 ± 2.77|12|`multiply`|

**11**

**2020-04-05 20:38:15**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1848&Tsk=1641&Sub=1153954)

**Submission status:**

Evaluated

 

**Evaluation:**

3.6454

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op\<\< )': success
        -   result: 95.50 %, required: 50.00 %
        -   Total run time: 0.009 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 95.50 %
        -   Failed (invalid output) [[Unlock advice (426 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551570'))
        -   Failed (invalid output) [[Unlock advice (934 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551571'))
        -   Failed (invalid output) [[Unlock advice (844 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551572'))
        -   Failed (invalid output) [[Unlock advice (142 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551573'))
        -   Failed (invalid output) [[Unlock advice (152 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551574'))
        -   Failed (invalid output) [[Unlock advice (520 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551575'))
        -   Failed (invalid output) [[Unlock advice (346 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551576'))
        -   Failed (invalid output) [[Unlock advice (396 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551577'))
    -   Test 'Random test (op=, op \<\<, op +)': success
        -   result: 84.92 %, required: 50.00 %
        -   Total run time: 0.010 s (limit: 2.000 s)
        -   Optional test success, evaluation: 84.92 %
        -   Failed (invalid output) [[Unlock advice (226 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551578'))
        -   Failed (invalid output) [[Unlock advice (775 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551579'))
        -   Failed (invalid output) [[Unlock advice (905 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551580'))
        -   Failed (invalid output) [[Unlock advice (905 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551581'))
        -   Failed (invalid output) [[Unlock advice (741 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551582'))
        -   Failed (invalid output) [[Unlock advice (924 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551583'))
        -   Failed (invalid output) [[Unlock advice (604 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551584'))
        -   Failed (invalid output) [[Unlock advice (741 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551585'))
    -   Test 'Random test (op=, op \<\<, op +, op\*)': success
        -   result: 91.67 %, required: 50.00 %
        -   Total run time: 0.049 s (limit: 1.990 s)
        -   Optional test success, evaluation: 91.67 %
        -   Failed (invalid output) [[Unlock advice (947 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551586'))
        -   Failed (invalid output) [[Unlock advice (1.06 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551587'))
        -   Failed (invalid output) [[Unlock advice (1.06 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551588'))
        -   Failed (invalid output) [[Unlock advice (1.83 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551589'))
        -   Failed (invalid output) [[Unlock advice (1.84 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551590'))
        -   Failed (invalid output) [[Unlock advice (1.06 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551591'))
        -   Failed (invalid output) [[Unlock advice (1.25 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551592'))
        -   Failed (invalid output) [[Unlock advice (1.44 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551593'))
    -   Test 'Random test (op=, op \<\<, op +, op\*, op \>\>)': success
        -   result: 89.47 %, required: 50.00 %
        -   Total run time: 0.019 s (limit: 1.941 s)
        -   Optional test success, evaluation: 89.47 %
        -   Failed (invalid output) [[Unlock advice (724 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551594'))
        -   Failed (invalid output) [[Unlock advice (474 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551595'))
        -   Failed (invalid output) [[Unlock advice (900 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551596'))
        -   Failed (invalid output) [[Unlock advice (679 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551597'))
        -   Failed (invalid output) [[Unlock advice (1002 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551598'))
        -   Failed (invalid output) [[Unlock advice (712 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551599'))
        -   Failed (invalid output) [[Unlock advice (464 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551600'))
        -   Failed (invalid output) [[Unlock advice (903 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551601'))
    -   Test 'Relational operators (\<, \<=, ... )': success
        -   result: 95.81 %, required: 50.00 %
        -   Total run time: 0.058 s (limit: 1.922 s)
        -   Optional test success, evaluation: 95.81 %
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551602'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551603'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551604'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551605'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551606'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551607'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551608'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551609'))
    -   Test 'Copy constructor test': success
        -   result: 80.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.864 s)
        -   Optional test success, evaluation: 80.00 %
        -   Failed (invalid output) [[Unlock advice (555 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551610'))
        -   Failed (invalid output) [[Unlock advice (555 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551611'))
        -   Failed (invalid output) [[Unlock advice (555 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551612'))
        -   Failed (invalid output) [[Unlock advice (555 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551613'))
        -   Failed (invalid output) [[Unlock advice (555 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551614'))
    -   Test 'Assignment operator test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.863 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Operator pitfalls test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.000 s (limit: 1.862 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test (factorial)': Abnormal program termination (Time limit exceeded)
        -   Cumulative test time exceeded, killed after:: 2.004 s (limit: 2.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Test 'Speed test (big number multiplication)': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 50.98 % (= 1.00 \* 0.95 \* 0.85 \* 0.92 \* 0.89 \* 0.96 \* 0.80 \* 1.00 \* 1.00)
-   Total percent: 50.98 %
-   Total points: 0.51 \* 7.15 = 3.65

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**75**|--|--|--|
|Lines of code:|**902**|12.03 ± 13.58|93|`main`|
|Cyclomatic complexity:|**198**|2.64 ± 2.68|12|`multiply`|

**10**

**2020-04-05 20:33:57**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1848&Tsk=1641&Sub=1153950)

**Submission status:**

Evaluated

 

**Evaluation:**

2.3126

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op\<\< )': success
        -   result: 96.00 %, required: 50.00 %
        -   Total run time: 0.005 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 96.00 %
        -   Failed (invalid output) [[Unlock advice (464 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551520'))
        -   Failed (invalid output) [[Unlock advice (758 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551521'))
        -   Failed (invalid output) [[Unlock advice (416 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551522'))
        -   Failed (invalid output) [[Unlock advice (770 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551523'))
        -   Failed (invalid output) [[Unlock advice (746 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551524'))
        -   Failed (invalid output) [[Unlock advice (816 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551525'))
        -   Failed (invalid output) [[Unlock advice (211 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551526'))
        -   Failed (invalid output) [[Unlock advice (566 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551527'))
    -   Test 'Random test (op=, op \<\<, op +)': success
        -   result: 77.24 %, required: 50.00 %
        -   Total run time: 0.012 s (limit: 2.000 s)
        -   Optional test success, evaluation: 77.24 %
        -   Failed (invalid output) [[Unlock advice (923 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551528'))
        -   Failed (invalid output) [[Unlock advice (923 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551529'))
        -   Failed (invalid output) [[Unlock advice (923 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551530'))
        -   Failed (invalid output) [[Unlock advice (923 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551531'))
        -   Failed (invalid output) [[Unlock advice (614 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551532'))
        -   Failed (invalid output) [[Unlock advice (614 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551533'))
        -   Failed (invalid output) [[Unlock advice (614 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551534'))
        -   Failed (invalid output) [[Unlock advice (614 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551535'))
    -   Test 'Random test (op=, op \<\<, op +, op\*)': success
        -   result: 80.32 %, required: 50.00 %
        -   Total run time: 0.052 s (limit: 1.988 s)
        -   Optional test success, evaluation: 80.32 %
        -   Failed (invalid output) [[Unlock advice (470 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551536'))
        -   Failed (invalid output) [[Unlock advice (701 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551537'))
        -   Failed (invalid output) [[Unlock advice (561 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551538'))
        -   Failed (invalid output) [[Unlock advice (641 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551539'))
        -   Failed (invalid output) [[Unlock advice (3.08 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551540'))
        -   Failed (invalid output) [[Unlock advice (343 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551541'))
        -   Failed (invalid output) [[Unlock advice (1.32 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551542'))
        -   Failed (invalid output) [[Unlock advice (2.13 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551543'))
    -   Test 'Random test (op=, op \<\<, op +, op\*, op \>\>)': success
        -   result: 91.14 %, required: 50.00 %
        -   Total run time: 0.017 s (limit: 1.936 s)
        -   Optional test success, evaluation: 91.14 %
        -   Failed (invalid output) [[Unlock advice (63 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551544'))
        -   Failed (invalid output) [[Unlock advice (62 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551545'))
        -   Failed (invalid output) [[Unlock advice (51 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551546'))
        -   Failed (invalid output) [[Unlock advice (81 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551547'))
        -   Failed (invalid output) [[Unlock advice (958 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551548'))
        -   Failed (invalid output) [[Unlock advice (276 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551549'))
        -   Failed (invalid output) [[Unlock advice (450 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551550'))
        -   Failed (invalid output) [[Unlock advice (388 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551551'))
    -   Test 'Relational operators (\<, \<=, ... )': success
        -   result: 93.12 %, required: 50.00 %
        -   Total run time: 0.057 s (limit: 1.919 s)
        -   Optional test success, evaluation: 93.12 %
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551552'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551553'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551554'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551555'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551556'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551557'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551558'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551559'))
    -   Test 'Copy constructor test': success
        -   result: 80.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.862 s)
        -   Optional test success, evaluation: 80.00 %
        -   Failed (invalid output) [[Unlock advice (105 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551560'))
        -   Failed (invalid output) [[Unlock advice (105 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551561'))
        -   Failed (invalid output) [[Unlock advice (105 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551562'))
        -   Failed (invalid output) [[Unlock advice (105 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551563'))
        -   Failed (invalid output) [[Unlock advice (105 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551564'))
    -   Test 'Assignment operator test': success
        -   result: 80.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.861 s)
        -   Optional test success, evaluation: 80.00 %
        -   Failed (invalid output) [[Unlock advice (255 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551565'))
        -   Failed (invalid output) [[Unlock advice (255 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551566'))
        -   Failed (invalid output) [[Unlock advice (255 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551567'))
        -   Failed (invalid output) [[Unlock advice (255 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551568'))
        -   Failed (invalid output) [[Unlock advice (255 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551569'))
    -   Test 'Operator pitfalls test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.000 s (limit: 1.860 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test (factorial)': Abnormal program termination (Time limit exceeded)
        -   Cumulative test time exceeded, killed after:: 2.004 s (limit: 2.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Test 'Speed test (big number multiplication)': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 32.35 % (= 1.00 \* 0.96 \* 0.77 \* 0.80 \* 0.91 \* 0.93 \* 0.80 \* 0.80 \* 1.00)
-   Total percent: 32.35 %
-   Total points: 0.32 \* 7.15 = 2.31

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**78**|--|--|--|
|Lines of code:|**923**|11.83 ± 13.35|93|`main`|
|Cyclomatic complexity:|**201**|2.58 ± 2.65|12|`multiply`|

**9**

**2020-04-05 20:10:29**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1848&Tsk=1641&Sub=1153918)

**Submission status:**

Evaluated

 

**Evaluation:**

3.6701

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op\<\< )': success
        -   result: 94.50 %, required: 50.00 %
        -   Total run time: 0.008 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 94.50 %
        -   Failed (invalid output) [[Unlock advice (176 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551398'))
        -   Failed (invalid output) [[Unlock advice (436 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551399'))
        -   Failed (invalid output) [[Unlock advice (72 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551400'))
        -   Failed (invalid output) [[Unlock advice (892 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551401'))
        -   Failed (invalid output) [[Unlock advice (508 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551402'))
        -   Failed (invalid output) [[Unlock advice (282 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551403'))
        -   Failed (invalid output) [[Unlock advice (872 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551404'))
        -   Failed (invalid output) [[Unlock advice (416 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551405'))
    -   Test 'Random test (op=, op \<\<, op +)': success
        -   result: 96.85 %, required: 50.00 %
        -   Total run time: 0.008 s (limit: 2.000 s)
        -   Optional test success, evaluation: 96.85 %
        -   Failed (invalid output) [[Unlock advice (658 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551406'))
        -   Failed (invalid output) [[Unlock advice (851 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551407'))
        -   Failed (invalid output) [[Unlock advice (658 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551408'))
        -   Failed (invalid output) [[Unlock advice (659 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551409'))
    -   Test 'Random test (op=, op \<\<, op +, op\*)': success
        -   result: 81.82 %, required: 50.00 %
        -   Total run time: 0.076 s (limit: 1.992 s)
        -   Optional test success, evaluation: 81.82 %
        -   Failed (invalid output) [[Unlock advice (457 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551410'))
        -   Failed (invalid output) [[Unlock advice (756 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551411'))
        -   Failed (invalid output) [[Unlock advice (550 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551412'))
        -   Failed (invalid output) [[Unlock advice (786 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551413'))
        -   Failed (invalid output) [[Unlock advice (940 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551414'))
        -   Failed (invalid output) [[Unlock advice (1.22 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551415'))
        -   Failed (invalid output) [[Unlock advice (1.62 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551416'))
        -   Failed (invalid output) [[Unlock advice (2.34 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551417'))
    -   Test 'Random test (op=, op \<\<, op +, op\*, op \>\>)': success
        -   result: 93.42 %, required: 50.00 %
        -   Total run time: 0.020 s (limit: 1.916 s)
        -   Optional test success, evaluation: 93.42 %
        -   Failed (invalid output) [[Unlock advice (170 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551418'))
        -   Failed (invalid output) [[Unlock advice (451 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551419'))
        -   Failed (invalid output) [[Unlock advice (1.39 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551420'))
        -   Failed (invalid output) [[Unlock advice (1.50 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551421'))
        -   Failed (invalid output) [[Unlock advice (366 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551422'))
        -   Failed (invalid output) [[Unlock advice (308 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551423'))
        -   Failed (invalid output) [[Unlock advice (708 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551424'))
        -   Failed (invalid output) [[Unlock advice (1.11 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551425'))
    -   Test 'Relational operators (\<, \<=, ... )': success
        -   result: 91.72 %, required: 50.00 %
        -   Total run time: 0.063 s (limit: 1.896 s)
        -   Optional test success, evaluation: 91.72 %
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551426'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551427'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551428'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551429'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551430'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551431'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551432'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551433'))
    -   Test 'Copy constructor test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.000 s (limit: 1.833 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Assignment operator test': success
        -   result: 80.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.833 s)
        -   Optional test success, evaluation: 80.00 %
        -   Failed (invalid output) [[Unlock advice (355 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551434'))
        -   Failed (invalid output) [[Unlock advice (355 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551435'))
        -   Failed (invalid output) [[Unlock advice (355 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551436'))
        -   Failed (invalid output) [[Unlock advice (355 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551437'))
        -   Failed (invalid output) [[Unlock advice (355 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551438'))
    -   Test 'Operator pitfalls test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.832 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test (factorial)': Abnormal program termination (Time limit exceeded)
        -   Cumulative test time exceeded, killed after:: 2.005 s (limit: 2.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Test 'Speed test (big number multiplication)': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 51.33 % (= 1.00 \* 0.94 \* 0.97 \* 0.82 \* 0.93 \* 0.92 \* 1.00 \* 0.80 \* 1.00)
-   Total percent: 51.33 %
-   Total points: 0.51 \* 7.15 = 3.67

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**75**|--|--|--|
|Lines of code:|**902**|12.03 ± 13.58|93|`main`|
|Cyclomatic complexity:|**198**|2.64 ± 2.68|12|`multiply`|

**8**

**2020-04-05 20:01:33**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1848&Tsk=1641&Sub=1153907)

**Submission status:**

Evaluated

 

**Evaluation:**

4.8883

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op\<\< )': success
        -   result: 94.00 %, required: 50.00 %
        -   Total run time: 0.007 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 94.00 %
        -   Failed (invalid output) [[Unlock advice (264 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551318'))
        -   Failed (invalid output) [[Unlock advice (132 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551319'))
        -   Failed (invalid output) [[Unlock advice (873 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551320'))
        -   Failed (invalid output) [[Unlock advice (697 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551321'))
        -   Failed (invalid output) [[Unlock advice (778 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551322'))
        -   Failed (invalid output) [[Unlock advice (1015 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551323'))
        -   Failed (invalid output) [[Unlock advice (118 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551324'))
        -   Failed (invalid output) [[Unlock advice (444 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551325'))
    -   Test 'Random test (op=, op \<\<, op +)': success
        -   result: 89.52 %, required: 50.00 %
        -   Total run time: 0.011 s (limit: 2.000 s)
        -   Optional test success, evaluation: 89.52 %
        -   Failed (invalid output) [[Unlock advice (915 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551326'))
        -   Failed (invalid output) [[Unlock advice (915 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551327'))
        -   Failed (invalid output) [[Unlock advice (915 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551328'))
        -   Failed (invalid output) [[Unlock advice (915 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551329'))
        -   Failed (invalid output) [[Unlock advice (1021 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551330'))
        -   Failed (invalid output) [[Unlock advice (1021 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551331'))
        -   Failed (invalid output) [[Unlock advice (1021 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551332'))
        -   Failed (invalid output) [[Unlock advice (1021 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551333'))
    -   Test 'Random test (op=, op \<\<, op +, op\*)': success
        -   result: 96.09 %, required: 50.00 %
        -   Total run time: 0.051 s (limit: 1.989 s)
        -   Optional test success, evaluation: 96.09 %
        -   Failed (invalid output) [[Unlock advice (635 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551334'))
        -   Failed (invalid output) [[Unlock advice (1.03 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551335'))
        -   Failed (invalid output) [[Unlock advice (939 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551336'))
        -   Failed (invalid output) [[Unlock advice (974 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551337'))
        -   Failed (invalid output) [[Unlock advice (350 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551338'))
    -   Test 'Random test (op=, op \<\<, op +, op\*, op \>\>)': success
        -   result: 93.59 %, required: 50.00 %
        -   Total run time: 0.021 s (limit: 1.938 s)
        -   Optional test success, evaluation: 93.59 %
        -   Failed (invalid output) [[Unlock advice (610 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551339'))
        -   Failed (invalid output) [[Unlock advice (816 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551340'))
        -   Failed (invalid output) [[Unlock advice (652 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551341'))
        -   Failed (invalid output) [[Unlock advice (400 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551342'))
        -   Failed (invalid output) [[Unlock advice (72 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551343'))
        -   Failed (invalid output) [[Unlock advice (602 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551344'))
        -   Failed (invalid output) [[Unlock advice (646 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551345'))
        -   Failed (invalid output) [[Unlock advice (917 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551346'))
    -   Test 'Relational operators (\<, \<=, ... )': success
        -   result: 90.34 %, required: 50.00 %
        -   Total run time: 0.060 s (limit: 1.917 s)
        -   Optional test success, evaluation: 90.34 %
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551347'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551348'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551349'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551350'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551351'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551352'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551353'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551354'))
    -   Test 'Copy constructor test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.857 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Assignment operator test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.856 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Operator pitfalls test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.000 s (limit: 1.855 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test (factorial)': Abnormal program termination (Time limit exceeded)
        -   Cumulative test time exceeded, killed after:: 2.002 s (limit: 2.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Test 'Speed test (big number multiplication)': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 68.37 % (= 1.00 \* 0.94 \* 0.90 \* 0.96 \* 0.94 \* 0.90 \* 1.00 \* 1.00 \* 1.00)
-   Total percent: 68.37 %
-   Total points: 0.68 \* 7.15 = 4.89

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**73**|--|--|--|
|Lines of code:|**896**|12.27 ± 13.70|93|`main`|
|Cyclomatic complexity:|**196**|2.68 ± 2.70|12|`multiply`|

**7**

**2020-04-05 19:41:38**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1848&Tsk=1641&Sub=1153868)

**Submission status:**

Evaluated

 

**Evaluation:**

5.0523

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op\<\< )': success
        -   result: 93.50 %, required: 50.00 %
        -   Total run time: 0.009 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 93.50 %
        -   Failed (invalid output) [[Unlock advice (192 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551114'))
        -   Failed (invalid output) [[Unlock advice (544 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551115'))
        -   Failed (invalid output) [[Unlock advice (850 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551116'))
        -   Failed (invalid output) [[Unlock advice (940 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551117'))
        -   Failed (invalid output) [[Unlock advice (795 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551118'))
        -   Failed (invalid output) [[Unlock advice (706 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551119'))
        -   Failed (invalid output) [[Unlock advice (908 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551120'))
        -   Failed (invalid output) [[Unlock advice (770 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551121'))
    -   Test 'Random test (op=, op \<\<, op +)': success
        -   result: 92.00 %, required: 50.00 %
        -   Total run time: 0.011 s (limit: 2.000 s)
        -   Optional test success, evaluation: 92.00 %
        -   Failed (invalid output) [[Unlock advice (903 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551122'))
        -   Failed (invalid output) [[Unlock advice (238 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551123'))
        -   Failed (invalid output) [[Unlock advice (972 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551124'))
        -   Failed (invalid output) [[Unlock advice (972 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551125'))
        -   Failed (invalid output) [[Unlock advice (630 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551126'))
        -   Failed (invalid output) [[Unlock advice (507 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551127'))
        -   Failed (invalid output) [[Unlock advice (368 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551128'))
        -    Failed (invalid output)

                 op = mismatch r=544513092602794509666468920191145507906176446906973510312321536196886504159849436897828, s=0544513092602794509666468920191145507906176446906973510312321536196886504159849436897828

    -   Test 'Random test (op=, op \<\<, op +, op\*)': success
        -   result: 91.06 %, required: 50.00 %
        -   Total run time: 0.109 s (limit: 1.989 s)
        -   Optional test success, evaluation: 91.06 %
        -   Failed (invalid output) [[Unlock advice (952 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551130'))
        -   Failed (invalid output) [[Unlock advice (953 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551131'))
        -   Failed (invalid output) [[Unlock advice (710 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551132'))
        -   Failed (invalid output) [[Unlock advice (1.13 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551133'))
        -   Failed (invalid output) [[Unlock advice (971 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551134'))
        -   Failed (invalid output) [[Unlock advice (888 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551135'))
        -   Failed (invalid output) [[Unlock advice (946 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551136'))
        -   Failed (invalid output) [[Unlock advice (970 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551137'))
    -   Test 'Random test (op=, op \<\<, op +, op\*, op \>\>)': success
        -   result: 95.57 %, required: 50.00 %
        -   Total run time: 0.017 s (limit: 1.880 s)
        -   Optional test success, evaluation: 95.57 %
        -   Failed (invalid output) [[Unlock advice (930 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551138'))
        -   Failed (invalid output) [[Unlock advice (778 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551139'))
        -   Failed (invalid output) [[Unlock advice (478 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551140'))
        -   Failed (invalid output) [[Unlock advice (738 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551141'))
        -   Failed (invalid output) [[Unlock advice (170 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551142'))
        -   Failed (invalid output) [[Unlock advice (171 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551143'))
        -   Failed (invalid output) [[Unlock advice (386 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551144'))
    -   Test 'Relational operators (\<, \<=, ... )': success
        -   result: 94.40 %, required: 50.00 %
        -   Total run time: 0.055 s (limit: 1.863 s)
        -   Optional test success, evaluation: 94.40 %
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551145'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551146'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551147'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551148'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551149'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551150'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551151'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551152'))
    -   Test 'Copy constructor test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.808 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Assignment operator test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.807 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Operator pitfalls test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.806 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test (factorial)': Abnormal program termination (Time limit exceeded)
        -   Cumulative test time exceeded, killed after:: 2.006 s (limit: 2.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Test 'Speed test (big number multiplication)': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 70.67 % (= 1.00 \* 0.94 \* 0.92 \* 0.91 \* 0.96 \* 0.94 \* 1.00 \* 1.00 \* 1.00)
-   Total percent: 70.67 %
-   Total points: 0.71 \* 7.15 = 5.05

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**67**|--|--|--|
|Lines of code:|**854**|12.75 ± 14.20|93|`main`|
|Cyclomatic complexity:|**190**|2.84 ± 2.77|12|`multiply`|

**6**

**2020-04-05 19:40:43**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1848&Tsk=1641&Sub=1153867)

**Submission status:**

Evaluated

 

**Evaluation:**

3.2079

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op\<\< )': success
        -   result: 95.50 %, required: 50.00 %
        -   Total run time: 0.009 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 95.50 %
        -   Failed (invalid output) [[Unlock advice (254 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551072'))
        -   Failed (invalid output) [[Unlock advice (150 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551073'))
        -   Failed (invalid output) [[Unlock advice (384 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551074'))
        -   Failed (invalid output) [[Unlock advice (1010 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551075'))
        -   Failed (invalid output) [[Unlock advice (558 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551076'))
        -   Failed (invalid output) [[Unlock advice (1010 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551077'))
        -   Failed (invalid output) [[Unlock advice (966 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551078'))
        -   Failed (invalid output) [[Unlock advice (400 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551079'))
    -   Test 'Random test (op=, op \<\<, op +)': success
        -   result: 86.89 %, required: 50.00 %
        -   Total run time: 0.010 s (limit: 2.000 s)
        -   Optional test success, evaluation: 86.89 %
        -   Failed (invalid output) [[Unlock advice (323 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551080'))
        -   Failed (invalid output) [[Unlock advice (323 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551081'))
        -   Failed (invalid output) [[Unlock advice (162 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551082'))
        -   Failed (invalid output) [[Unlock advice (972 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551083'))
        -   Failed (invalid output) [[Unlock advice (769 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551084'))
        -   Failed (invalid output) [[Unlock advice (745 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551085'))
        -   Failed (invalid output) [[Unlock advice (746 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551086'))
        -   Failed (invalid output) [[Unlock advice (746 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551087'))
    -   Test 'Random test (op=, op \<\<, op +, op\*)': success
        -   result: 74.02 %, required: 50.00 %
        -   Total run time: 0.044 s (limit: 1.990 s)
        -   Optional test success, evaluation: 74.02 %
        -   Failed (invalid output) [[Unlock advice (367 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551088'))
        -   Failed (invalid output) [[Unlock advice (534 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551089'))
        -   Failed (invalid output) [[Unlock advice (850 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551090'))
        -   Failed (invalid output) [[Unlock advice (1.05 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551091'))
        -   Failed (invalid output) [[Unlock advice (1.16 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551092'))
        -   Failed (invalid output) [[Unlock advice (1.87 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551093'))
        -   Failed (invalid output) [[Unlock advice (400 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551094'))
        -   Failed (invalid output) [[Unlock advice (753 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551095'))
    -   Test 'Random test (op=, op \<\<, op +, op\*, op \>\>)': success
        -   result: 96.71 %, required: 50.00 %
        -   Total run time: 0.024 s (limit: 1.946 s)
        -   Optional test success, evaluation: 96.71 %
        -   Failed (invalid output) [[Unlock advice (412 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551096'))
        -   Failed (invalid output) [[Unlock advice (683 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551097'))
        -   Failed (invalid output) [[Unlock advice (1.11 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551098'))
        -   Failed (invalid output) [[Unlock advice (534 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551099'))
        -   Failed (invalid output) [[Unlock advice (819 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551100'))
    -   Test 'Relational operators (\<, \<=, ... )': success
        -   result: 94.42 %, required: 50.00 %
        -   Total run time: 0.063 s (limit: 1.922 s)
        -   Optional test success, evaluation: 94.42 %
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551101'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551102'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551103'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551104'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551105'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551106'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551107'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551108'))
    -   Test 'Copy constructor test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.859 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Assignment operator test': success
        -   result: 80.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.858 s)
        -   Optional test success, evaluation: 80.00 %
        -   Failed (invalid output) [[Unlock advice (145 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551109'))
        -   Failed (invalid output) [[Unlock advice (145 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551110'))
        -   Failed (invalid output) [[Unlock advice (145 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551111'))
        -   Failed (invalid output) [[Unlock advice (145 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551112'))
        -   Failed (invalid output) [[Unlock advice (145 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3551113'))
    -   Test 'Operator pitfalls test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.000 s (limit: 1.857 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test (factorial)': Abnormal program termination (Time limit exceeded)
        -   Cumulative test time exceeded, killed after:: 2.006 s (limit: 2.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Test 'Speed test (big number multiplication)': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 44.87 % (= 1.00 \* 0.95 \* 0.87 \* 0.74 \* 0.97 \* 0.94 \* 1.00 \* 0.80 \* 1.00)
-   Total percent: 44.87 %
-   Total points: 0.45 \* 7.15 = 3.21

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**67**|--|--|--|
|Lines of code:|**770**|11.49 ± 10.21|60|`addting`|
|Cyclomatic complexity:|**190**|2.84 ± 2.77|12|`multiply`|

**5**

**2020-04-05 19:07:05**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1848&Tsk=1641&Sub=1153812)

**Submission status:**

Evaluated

 

**Evaluation:**

4.3668

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op\<\< )': success
        -   result: 94.50 %, required: 50.00 %
        -   Total run time: 0.007 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 94.50 %
        -   Failed (invalid output) [[Unlock advice (640 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550878'))
        -   Failed (invalid output) [[Unlock advice (182 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550879'))
        -   Failed (invalid output) [[Unlock advice (465 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550880'))
        -   Failed (invalid output) [[Unlock advice (620 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550881'))
        -   Failed (invalid output) [[Unlock advice (852 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550882'))
        -   Failed (invalid output) [[Unlock advice (1.01 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550883'))
        -   Failed (invalid output) [[Unlock advice (852 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550884'))
        -   Failed (invalid output) [[Unlock advice (793 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550885'))
    -   Test 'Random test (op=, op \<\<, op +)': success
        -   result: 97.62 %, required: 50.00 %
        -   Total run time: 0.011 s (limit: 2.000 s)
        -   Optional test success, evaluation: 97.62 %
        -   Failed (invalid output) [[Unlock advice (801 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550886'))
        -   Failed (invalid output) [[Unlock advice (801 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550887'))
        -   Failed (invalid output) [[Unlock advice (362 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550888'))
    -   Test 'Random test (op=, op \<\<, op +, op\*)': success
        -   result: 78.15 %, required: 50.00 %
        -   Total run time: 0.071 s (limit: 1.989 s)
        -   Optional test success, evaluation: 78.15 %
        -   Failed (invalid output) [[Unlock advice (218 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550889'))
        -   Failed (invalid output) [[Unlock advice (316 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550890'))
        -   Failed (invalid output) [[Unlock advice (1.11 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550891'))
        -   Failed (invalid output) [[Unlock advice (407 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550892'))
        -   Failed (invalid output) [[Unlock advice (4.00 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550893'))
        -   Failed (invalid output) [[Unlock advice (3.94 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550894'))
        -   Failed (invalid output) [[Unlock advice (3.99 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550895'))
        -   Failed (invalid output) [[Unlock advice (4.00 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550896'))
    -   Test 'Random test (op=, op \<\<, op +, op\*, op \>\>)': success
        -   result: 90.91 %, required: 50.00 %
        -   Total run time: 0.021 s (limit: 1.918 s)
        -   Optional test success, evaluation: 90.91 %
        -   Failed (invalid output) [[Unlock advice (808 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550897'))
        -   Failed (invalid output) [[Unlock advice (573 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550898'))
        -   Failed (invalid output) [[Unlock advice (888 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550899'))
        -   Failed (invalid output) [[Unlock advice (1.12 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550900'))
        -   Failed (invalid output) [[Unlock advice (623 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550901'))
        -   Failed (invalid output) [[Unlock advice (747 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550902'))
        -   Failed (invalid output) [[Unlock advice (605 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550903'))
        -   Failed (invalid output) [[Unlock advice (980 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550904'))
    -   Test 'Relational operators (\<, \<=, ... )': success
        -   result: 93.19 %, required: 50.00 %
        -   Total run time: 0.058 s (limit: 1.897 s)
        -   Optional test success, evaluation: 93.19 %
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550905'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550906'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550907'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550908'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550909'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550910'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550911'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550912'))
    -   Test 'Copy constructor test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.839 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Assignment operator test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.838 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Operator pitfalls test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.000 s (limit: 1.837 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test (factorial)': Abnormal program termination (Time limit exceeded)
        -   Cumulative test time exceeded, killed after:: 2.006 s (limit: 2.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Test 'Speed test (big number multiplication)': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 61.08 % (= 1.00 \* 0.94 \* 0.98 \* 0.78 \* 0.91 \* 0.93 \* 1.00 \* 1.00 \* 1.00)
-   Total percent: 61.08 %
-   Total points: 0.61 \* 7.15 = 4.37

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**61**|--|--|--|
|Lines of code:|**790**|12.95 ± 14.83|93|`main`|
|Cyclomatic complexity:|**172**|2.82 ± 2.84|12|`multiply`|

**4**

**2020-04-05 18:14:51**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1848&Tsk=1641&Sub=1153714)

**Submission status:**

Evaluated

 

**Evaluation:**

3.1064

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op\<\< )': success
        -   result: 92.50 %, required: 50.00 %
        -   Total run time: 0.005 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 92.50 %
        -   Failed (invalid output) [[Unlock advice (473 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550398'))
        -   Failed (invalid output) [[Unlock advice (148 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550399'))
        -   Failed (invalid output) [[Unlock advice (694 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550400'))
        -   Failed (invalid output) [[Unlock advice (868 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550401'))
        -   Failed (invalid output) [[Unlock advice (1.01 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550402'))
        -   Failed (invalid output) [[Unlock advice (532 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550403'))
        -   Failed (invalid output) [[Unlock advice (70 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550404'))
        -   Failed (invalid output) [[Unlock advice (822 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550405'))
    -   Test 'Random test (op=, op \<\<, op +)': success
        -   result: 88.89 %, required: 50.00 %
        -   Total run time: 0.011 s (limit: 2.000 s)
        -   Optional test success, evaluation: 88.89 %
        -   Failed (invalid output) [[Unlock advice (686 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550406'))
        -   Failed (invalid output) [[Unlock advice (732 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550407'))
        -   Failed (invalid output) [[Unlock advice (654 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550408'))
        -   Failed (invalid output) [[Unlock advice (655 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550409'))
        -   Failed (invalid output) [[Unlock advice (1.00 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550410'))
        -   Failed (invalid output) [[Unlock advice (1.00 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550411'))
        -   Failed (invalid output) [[Unlock advice (1.00 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550412'))
        -   Failed (invalid output) [[Unlock advice (1.00 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550413'))
    -   Test 'Random test (op=, op \<\<, op +, op\*)': success
        -   result: 77.24 %, required: 50.00 %
        -   Total run time: 0.078 s (limit: 1.989 s)
        -   Optional test success, evaluation: 77.24 %
        -   Failed (invalid output) [[Unlock advice (506 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550414'))
        -   Failed (invalid output) [[Unlock advice (1.43 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550415'))
        -   Failed (invalid output) [[Unlock advice (1.87 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550416'))
        -   Failed (invalid output) [[Unlock advice (2.25 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550417'))
        -   Failed (invalid output) [[Unlock advice (961 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550418'))
        -   Failed (invalid output) [[Unlock advice (226 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550419'))
        -   Failed (invalid output) [[Unlock advice (490 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550420'))
        -   Failed (invalid output) [[Unlock advice (857 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550421'))
    -   Test 'Random test (op=, op \<\<, op +, op\*, op \>\>)': success
        -   result: 91.82 %, required: 50.00 %
        -   Total run time: 0.019 s (limit: 1.911 s)
        -   Optional test success, evaluation: 91.82 %
        -   Failed (invalid output) [[Unlock advice (479 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550422'))
        -   Failed (invalid output) [[Unlock advice (553 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550423'))
        -   Failed (invalid output) [[Unlock advice (517 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550424'))
        -   Failed (invalid output) [[Unlock advice (771 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550425'))
        -   Failed (invalid output) [[Unlock advice (828 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550426'))
        -   Failed (invalid output) [[Unlock advice (689 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550427'))
        -   Failed (invalid output) [[Unlock advice (474 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550428'))
        -   Failed (invalid output) [[Unlock advice (783 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550429'))
    -   Test 'Relational operators (\<, \<=, ... )': success
        -   result: 93.13 %, required: 50.00 %
        -   Total run time: 0.057 s (limit: 1.892 s)
        -   Optional test success, evaluation: 93.13 %
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550430'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550431'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550432'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550433'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550434'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550435'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550436'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550437'))
    -   Test 'Copy constructor test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.835 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Assignment operator test': success
        -   result: 80.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.834 s)
        -   Optional test success, evaluation: 80.00 %
        -   Failed (invalid output) [[Unlock advice (609 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550438'))
        -   Failed (invalid output) [[Unlock advice (609 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550439'))
        -   Failed (invalid output) [[Unlock advice (609 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550440'))
        -   Failed (invalid output) [[Unlock advice (609 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550441'))
        -   Failed (invalid output) [[Unlock advice (609 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3550442'))
    -   Test 'Operator pitfalls test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.000 s (limit: 1.833 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test (factorial)': Abnormal program termination (Time limit exceeded)
        -   Cumulative test time exceeded, killed after:: 2.004 s (limit: 2.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Test 'Speed test (big number multiplication)': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 43.45 % (= 1.00 \* 0.93 \* 0.89 \* 0.77 \* 0.92 \* 0.93 \* 1.00 \* 0.80 \* 1.00)
-   Total percent: 43.45 %
-   Total points: 0.43 \* 7.15 = 3.11

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**67**|--|--|--|
|Lines of code:|**850**|12.69 ± 14.20|93|`main`|
|Cyclomatic complexity:|**190**|2.84 ± 2.77|12|`multiply`|

**3**

**2020-04-05 07:43:56**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1848&Tsk=1641&Sub=1153094)

**Submission status:**

Evaluated

 

**Evaluation:**

3.7626

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (op=, op\<\< )': success
        -   result: 94.00 %, required: 50.00 %
        -   Total run time: 0.008 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 94.00 %
        -   Failed (invalid output) [[Unlock advice (372 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547448'))
        -   Failed (invalid output) [[Unlock advice (244 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547449'))
        -   Failed (invalid output) [[Unlock advice (168 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547450'))
        -   Failed (invalid output) [[Unlock advice (484 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547451'))
        -   Failed (invalid output) [[Unlock advice (508 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547452'))
        -   Failed (invalid output) [[Unlock advice (670 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547453'))
        -   Failed (invalid output) [[Unlock advice (768 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547454'))
        -   Failed (invalid output) [[Unlock advice (688 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547455'))
    -   Test 'Random test (op=, op \<\<, op +)': success
        -   result: 93.08 %, required: 50.00 %
        -   Total run time: 0.011 s (limit: 2.000 s)
        -   Optional test success, evaluation: 93.08 %
        -   Failed (invalid output) [[Unlock advice (230 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547456'))
        -   Failed (invalid output) [[Unlock advice (962 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547457'))
        -   Failed (invalid output) [[Unlock advice (963 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547458'))
        -   Failed (invalid output) [[Unlock advice (963 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547459'))
        -   Failed (invalid output) [[Unlock advice (720 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547460'))
        -   Failed (invalid output) [[Unlock advice (963 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547461'))
        -   Failed (invalid output) [[Unlock advice (988 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547462'))
        -   Failed (invalid output) [[Unlock advice (989 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547463'))
    -   Test 'Random test (op=, op \<\<, op +, op\*)': success
        -   result: 90.84 %, required: 50.00 %
        -   Total run time: 0.062 s (limit: 1.989 s)
        -   Optional test success, evaluation: 90.84 %
        -   Failed (invalid output) [[Unlock advice (116 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547464'))
        -   Failed (invalid output) [[Unlock advice (193 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547465'))
        -   Failed (invalid output) [[Unlock advice (379 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547466'))
        -   Failed (invalid output) [[Unlock advice (477 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547467'))
        -   Failed (invalid output) [[Unlock advice (548 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547468'))
        -   Failed (invalid output) [[Unlock advice (3.36 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547469'))
        -   Failed (invalid output) [[Unlock advice (148 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547470'))
        -   Failed (invalid output) [[Unlock advice (391 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547471'))
    -   Test 'Random test (op=, op \<\<, op +, op\*, op \>\>)': success
        -   result: 94.34 %, required: 50.00 %
        -   Total run time: 0.019 s (limit: 1.927 s)
        -   Optional test success, evaluation: 94.34 %
        -   Failed (invalid output) [[Unlock advice (623 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547472'))
        -   Failed (invalid output) [[Unlock advice (544 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547473'))
        -   Failed (invalid output) [[Unlock advice (515 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547474'))
        -   Failed (invalid output) [[Unlock advice (557 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547475'))
        -   Failed (invalid output) [[Unlock advice (741 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547476'))
        -   Failed (invalid output) [[Unlock advice (224 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547477'))
        -   Failed (invalid output) [[Unlock advice (908 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547478'))
        -   Failed (invalid output) [[Unlock advice (157 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547479'))
    -   Test 'Relational operators (\<, \<=, ... )': success
        -   result: 87.73 %, required: 50.00 %
        -   Total run time: 0.065 s (limit: 1.908 s)
        -   Optional test success, evaluation: 87.73 %
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547480'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547481'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547482'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547483'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547484'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547485'))
        -   Failed (invalid output) [[Unlock advice (31 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547486'))
        -   Failed (invalid output) [[Unlock advice (30 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547487'))
    -   Test 'Copy constructor test': success
        -   result: 80.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.843 s)
        -   Optional test success, evaluation: 80.00 %
        -   Failed (invalid output) [[Unlock advice (165 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547488'))
        -   Failed (invalid output) [[Unlock advice (165 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547489'))
        -   Failed (invalid output) [[Unlock advice (165 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547490'))
        -   Failed (invalid output) [[Unlock advice (165 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547491'))
        -   Failed (invalid output) [[Unlock advice (165 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547492'))
    -   Test 'Assignment operator test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 1.842 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Operator pitfalls test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.000 s (limit: 1.841 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test (factorial)': Abnormal program termination (Time limit exceeded)
        -   Cumulative test time exceeded, killed after:: 2.006 s (limit: 2.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Test 'Speed test (big number multiplication)': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 52.63 % (= 1.00 \* 0.94 \* 0.93 \* 0.91 \* 0.94 \* 0.88 \* 0.80 \* 1.00 \* 1.00)
-   Total percent: 52.63 %
-   Total points: 0.53 \* 7.15 = 3.76

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**61**|--|--|--|
|Lines of code:|**787**|12.90 ± 14.82|93|`main`|
|Cyclomatic complexity:|**172**|2.82 ± 2.84|12|`multiply`|

**2**

**2020-04-05 07:38:29**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1848&Tsk=1641&Sub=1153093)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': failed
        -   result: 96.77 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 1.000 s)
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547446'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547447'))
    -   Overall ratio: 0.00 %
-   Total percent: 0.00 %
-   Total points: 0.00 \* 7.15 = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**61**|--|--|--|
|Lines of code:|**786**|12.89 ± 14.82|93|`main`|
|Cyclomatic complexity:|**172**|2.82 ± 2.84|12|`multiply`|

**1**

**2020-04-05 07:26:26**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1848&Tsk=1641&Sub=1153092)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': failed
        -   result: 96.77 %, required: 100.00 %
        -   Total run time: 0.001 s (limit: 1.000 s)
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547444'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1848&Tsk=1641&Unl=L3547445'))
    -   Overall ratio: 0.00 %
-   Total percent: 0.00 %
-   Total points: 0.00 \* 7.15 = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**61**|--|--|--|
|Lines of code:|**784**|12.85 ± 14.84|93|`main`|
|Cyclomatic complexity:|**172**|2.82 ± 2.84|12|`multiply`|


