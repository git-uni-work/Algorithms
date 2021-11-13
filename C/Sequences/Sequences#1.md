||
|[ProgTest](https://progtest.fit.cvut.cz/index.php?X=Main)  ►  [BIE-PA1 (18/19 ZS)](https://progtest.fit.cvut.cz/index.php?X=Course&Cou=251)  ►  [Homework 02](https://progtest.fit.cvut.cz/index.php?X=TaskGrp&Cou=251&Tgr=1586)  ►  **Sequence \#1**|[Logout](https://progtest.fit.cvut.cz/index.php?X=Logout)|

||
|**Sequence \#1**|

**Submission deadline:**

**2018-11-18 23:59:59**

 

**Late submission with malus:**

**2019-01-06 23:59:59** (Late submission malus: 100.0000 %)

**Evaluation:**

**3.3000**

**Max. assessment:**

**3.0000** (Without bonus points)

**Submissions:**

3 / 20 Free retries + 10 Penalized retries (-10 % penalty each retry)

**Advices:**

0 / 2 Advices for free + 2 Advices with a penalty (-10 % penalty each advice)

The task is to develop a program that analyzes binary numbers from a given interval.

The input of the program consists of two integers. The integers define closed interval `[ lo ; hi ]`. Assume a string formed from all binary numbers from this interval, starting from the lower bound. The binary numbers form a sequence of zeros and ones. The program shall analyze the sequence and compute one of:

-   the overall length of the sequence (i.e., the total number of binary digits),
-   the number of zeros in the sequence,
-   the longest contiguous run of zeros in the sequence.

For example, input interval `[10;20]` defines binary sequence:

      1010 1011 1100 1101 1110 1111 10000 10001 10010 10011 10100

The sequence is 49 digits long, out of which, there is 22 zeros. The longest contiguous run of zeros is of length 4.

The input of the program is a pair of non-negative integers (i.e., positive or zero). The integers are enclosed in angle braces and delimited by a semicolon. The first integer defines the lower bound; the second is the upper bound. The lower bound must be less than or equal to the upper bound. Following the interval, there is one character. The character describes the computation required:

-   `l` to display the total length of the binary sequence (number of digits),
-   `z` to display the count of zeros in the sequence,
-   `s` to display the length of the longest contiguous run of zeros in the sequence.

The output of the program is the result of the desired computation. The exact output format is shown in the sample runs below.

The program must validate input data. If the input is invalid, the program must detect it, it shall output an error message (see below), and terminate. If displayed, the error message must be sent to the standard output (do not send it to the error output) and the error message must be terminated by a newline (\\n). The input is considered invalid, if:

-   the interval boundaries are invalid (are not valid integers),
-   the boundaries are negative, or
-   the lower bound is greater than the upper bound.
-   the required computation is not any of `l`, `z`, and `s`,
-   there are missing/redundant separators (angle brace, semicolon).

**Sample program runs:**

* * * * *

    Enter the interval:
    <0;11> l
    Digits: 34

* * * * *

    Enter the interval:
    <0;11> z
    Zeros: 14

* * * * *

    Enter the interval:
    <0;11> s
    Sequence: 3

* * * * *

    Enter the interval:
    <10;20> l
    Digits: 49

* * * * *

    Enter the interval:
     < 10 ; 20 > z
    Zeros: 22

* * * * *

    Enter the interval:
    <10;20>s
    Sequence: 4

* * * * *

    Enter the interval:
    <1492;2018> l
    Digits: 5797

* * * * *

    Enter the interval:
    <1123;2000> z
    Zeros: 4319

* * * * *

    Enter the interval:
    <1683;1999> s
    Sequence: 8

* * * * *

    Enter the interval:
    <4;4> l
    Digits: 3

* * * * *

    Enter the interval:
    <0;3> z
    Zeros: 2

* * * * *

    Enter the interval:
    <255;255> s
    Sequence: 0

* * * * *

    Enter the interval:
    <47;16> l
    Invalid input.

* * * * *

    Enter the interval:
    <23;asdf> z
    Invalid input.

* * * * *

**Advice:**

-   The sample runs above list both the output of your program (boldface font) and user input (regular font). The bold/regular formatting is included here, in the problem statement page, to increase readability of the listing. Your program must output the text without any additional markup.
-   Do not forget the newline (\\n) after the last output line.
-   The program can be developed without additional functions (i.e., in one big `main`). However, if divided into functions, the program is readable and easier to debug.
-   A reasonable implementation of the naive algorithm passes all tests except the bonus tests. The naive algorithm passes all numbers in the input interval and analyzes their binary representation. Loops, conditions, and a few integer variables are needed in the implementation. There is no need for arrays or strings. Do not construct the entire binary sequence in the program's memory. Such implementation is clumsy, error-prone, laborious, and slow.
-   Speed test \#1 is an extra bonus test. The test inputs long intervals, the total number of digits is to be computed. The number of digits must be computed using an efficient algorithm to pass the time limits. Such an algorithm does not scan all numbers in the input interval. Instead, it establishes the result based just on the interval boundaries. The other computations (count of zeros, the longest run of zeros) are not tested in speed test \#1, thus efficient algorithms are not needed to pass. If a program passes the bonus test, it is awarded some extra points (above the nominal 100%).
-   Speed test \#2 is similar to the speed test \#1. All three computations (total number of digits, count of zeros, the longest run of zeros) are tested, moreover, the input intervals are long. All computations must be done by efficient algorithms to pass the test. The implementation may need a few small arrays (up to 100 elements) to store some intermediate results.
-   The inputs are chosen such that the input values fit into the `int` data type. The same applies to the resulting values in the mandatory and optional tests. The intervals in the bonus tests are very long, the results may exceed the limits of `int` data type. It is recommended to use the `long long int` data type when developing a program that is supposed to pass the bonus tests.
-   Please strictly adhere to the format of the output. The output must exactly match the output of the reference program. The comparison is completed by a machine, meaning an exact match is required. If your program provides output different from the reference, the program is considered malfunctioning. Be very careful since the comparison is sensitive even to whitespace characters (spaces, newlines, tabulators). Please note that all output lines are followed by a newline character (\\n). The new line character must be present after the last line of the output and after the error messages. Download the enclosed archive. The archive contains a set of testing inputs and the expected outputs. Read Progtest FAQ to learn how to use input/output redirection and how to simplify testing of your programs.
-   Your program will be tested in a restricted environment. The testing environment limits running time and available memory. The exact time and memory limits are shown in the reference solution testing log. However, neither time nor memory limit could cause a problem in this simple program. Next, the testing environment prohibits the use of functions which are considered "dangerous" (functions to execute other processes, functions to access the network, ... ). If your program uses such functions, the testing environment refuses to execute the program. Your program may use something like the code below:

           int main ( int argc, char * argv [] )
           {
            
             ...
                
             system ( "pause" ); /* prevent program window from closing */
             return 0;
           }
           

    This will not work properly in the testing environment - it is prohibited to execute other programs. (Even if the function were allowed, this would not work properly. The program would infinitely wait for a key to be pressed, however, no one will press any key in the automated testing environment. Thus, the program would be terminated on exceeded time limit.) If you want to keep the pause for your debugging and you want the program to be accepted by the Progtest, use the following trick:

           int main ( int argc, char * argv [] )
           {
            
             ...
           
           #ifndef __PROGTEST__
             system ( "pause" ); /* this is ignored by Progtest */
           #endif /* __PROGTEST__ */
             return 0;
           } 
           

-   Textual description of valid input data structure is not 100% exact. Therefore we provide a formal specification of the input language in EBNF:

            input      ::= { whiteSpace } '<' { whiteSpace } integer { whiteSpace } ';' 
                           { whiteSpace } integer { whiteSpace } '>' { whiteSpace } computation { whiteSpace }
            whiteSpace ::= ' ' | '\t' | '\n' | '\r'
            computation::= 'l' | 'z' | 's'
            integer    ::= digit { digit }
            digit      ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
           

**Sample data:**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskS&Cou=251&Tgr=1586&Tsk=1569)

 **Reference**

 

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Základní test s parametry podle ukázky': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 0.500 s)
        -   Total run time: 0.071 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Test mezních hodnot': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 0.500 s)
        -   Total run time: 0.194 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Test ošetření nesprávných vstupů': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 0.500 s)
        -   Total run time: 0.071 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Test náhodnými daty': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.105 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Test rychlosti \#1': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.005 s (limit: 0.100 s)
        -   Total run time: 0.015 s
        -   Bonus test - success, evaluation: 120.00 %
    -   Test 'Test rychlosti \#2': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.005 s (limit: 0.100 s)
        -   Total run time: 0.023 s
        -   Bonus test - success, evaluation: 120.00 %
    -   Overall ratio: 144.00 % (= 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.20 \* 1.20)
-   Total percent: 144.00 %
-   Early submission bonus: 0.30
-   Total points: 1.44 \* ( 3.00 + 0.30 ) = 4.75

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**7**|--|--|--|
|Lines of code:|**130**|18.57 ± 9.29|32|`seqZeros`|
|Cyclomatic complexity:|**39**|5.57 ± 3.50|11|`seqZeros`|

**3**

**2018-11-09 00:47:43**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1586&Tsk=1569&Sub=987283)

**Submission status:**

Evaluated

 

**Evaluation:**

3.3000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 0.500 s)
        -   Total run time: 0.081 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.006 s (limit: 0.500 s)
        -   Total run time: 0.202 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Invalid input test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 0.500 s)
        -   Total run time: 0.067 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.130 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test \#1': Abnormal program termination (Time limit exceeded)
        -   Program was killed after: 0.103 s (limit: 0.100 s)
        -   Bonus test - failed, evaluation: No bonus awarded
        -   Time limit exceeded [[Unlock advice (22 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1569&Unl=L2894181'))
    -   Test 'Speed test \#2': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 100.00 % (= 1.00 \* 1.00 \* 1.00 \* 1.00)
-   Total percent: 100.00 %
-   Early submission bonus: 0.30
-   Total points: 1.00 \* ( 3.00 + 0.30 ) = 3.30

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**4**|--|--|--|
|Lines of code:|**94**|23.50 ± 7.76|35|`main`|
|Cyclomatic complexity:|**22**|5.50 ± 2.69|10|`main`|

**2**

**2018-11-09 00:38:45**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1586&Tsk=1569&Sub=987270)

**Submission status:**

Evaluated

 

**Evaluation:**

2.9621

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 0.500 s)
        -   Total run time: 0.071 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 92.86 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 0.500 s)
        -   Total run time: 0.169 s
        -   Optional test success, evaluation: 92.86 %
        -   Failed (invalid output) [[Unlock advice (78 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1569&Unl=L2894074'))
        -   Failed (invalid output) [[Unlock advice (78 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1569&Unl=L2894075'))
        -   Failed (invalid output) [[Unlock advice (78 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1569&Unl=L2894076'))
    -   Test 'Invalid input test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 0.500 s)
        -   Total run time: 0.072 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test': success
        -   result: 96.67 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.126 s
        -   Optional test success, evaluation: 96.67 %
        -   Failed (invalid output) [[Unlock advice (79 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1569&Unl=L2894077'))
    -   Test 'Speed test \#1': Abnormal program termination (Time limit exceeded)
        -   Program was killed after: 0.103 s (limit: 0.100 s)
        -   Bonus test - failed, evaluation: No bonus awarded
        -   Time limit exceeded [[Unlock advice (23 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1569&Unl=L2894078'))
    -   Test 'Speed test \#2': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 89.77 % (= 1.00 \* 0.93 \* 1.00 \* 0.97)
-   Total percent: 89.77 %
-   Early submission bonus: 0.30
-   Total points: 0.90 \* ( 3.00 + 0.30 ) = 2.96

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**4**|--|--|--|
|Lines of code:|**90**|22.50 ± 7.63|35|`main`|
|Cyclomatic complexity:|**22**|5.50 ± 2.69|10|`main`|

**1**

**2018-11-09 00:29:17**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1586&Tsk=1569&Sub=987257)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Compile in 'pedantic' mode failed (10 % penalty). [[Unlock advice (510 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1569&Unl=C996854'))
    -   Test 'Basic test with sample input data': failed
        -   result: 71.43 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 0.500 s)
        -   Total run time: 0.073 s
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (81 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1569&Unl=L2893989'))
        -   Failed (invalid output) [[Unlock advice (82 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1569&Unl=L2893990'))
        -   Failed (invalid output) [[Unlock advice (87 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1569&Unl=L2893991'))
        -   Failed (invalid output) [[Unlock advice (84 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1569&Unl=L2893992'))
    -   Overall ratio: 0.00 %
-   Total percent: 0.00 %
-   Early submission bonus: 0.30
-   Total points: 0.00 \* ( 3.00 + 0.30 ) = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**4**|--|--|--|
|Lines of code:|**89**|22.25 ± 7.66|35|`main`|
|Cyclomatic complexity:|**22**|5.50 ± 2.69|10|`main`|


