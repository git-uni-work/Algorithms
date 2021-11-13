||
|[ProgTest](https://progtest.fit.cvut.cz/index.php?X=Main)  ►  [BIE-PA1 (18/19 ZS)](https://progtest.fit.cvut.cz/index.php?X=Course&Cou=251)  ►  [Homework 02](https://progtest.fit.cvut.cz/index.php?X=TaskGrp&Cou=251&Tgr=1586)  ►  **Sequence \#2**|[Logout](https://progtest.fit.cvut.cz/index.php?X=Logout)|

||
|**Sequence \#2**|

**Submission deadline:**

**2018-11-18 23:59:59**

 

**Late submission with malus:**

**2019-01-06 23:59:59** (Late submission malus: 100.0000 %)

**Evaluation:**

**5.5000**

**Max. assessment:**

**5.0000** (Without bonus points)

**Submissions:**

4 / 20 Free retries + 10 Penalized retries (-10 % penalty each retry)

**Advices:**

1 / 2 Advices for free + 2 Advices with a penalty (-10 % penalty each advice)

The task is to develop a program that analyzes numbers from a given interval. The problem is an extension of the simpler variant. The analyzed numbers will not always be binary. Instead, the program shall analyze the sequences of numbers written in different bases.

An instance of the problem is defined by the radix `R`, a lower boundary `LO`, and an upper boundary `HI`. Assume all integers from the interval `[LO;HI]` written as radix-`R` numbers. The numbers form a sequence of digits. The program shall:

-   compute the overall length of the sequence (i.e., the total number of digits),
-   compute the number of zeros in the sequence, or
-   compute the longest contiguous run of zeros in the sequence.

For example, input problem instance `r4:[10;20]` defines sequence of numbers from 10 to 20 written as base-4 numbers. The sequence is:

      22 23 30 31 32 33 100 101 102 103 110 

The sequence is 27 digits long, out of which, there are 7 zeros. The longest contiguous run of zeros is of length 2. Similarly, input input problem instance `r13:[10;20]` defines a sequence of numbers from 10 to 20 written as base-13 numbers. The sequence is:

      A B C 10 11 12 13 14 15 16 17 

The sequence is 19 digits long, out of which, there is 1 zero, and the longest zero sequence is just 1.

The input of the program is a list of problem instances to solve. In general, the problem list may be of any length. Each problem instance is defined as a radix, a closed interval of numbers, and a code of the desired computation. The input may have two forms:

    rR: <LO;HI> OP
    <LO;HI> OP

where `R` is a decimal integer that defines the radix. If the radix is omitted (the second short form), we assume radix `R=10`. Values `LO` and `HI` are decimal integers that define a closed interval of numbers to analyze. Finally, `OP` is the code of the desired computation. It is a single character:

-   `l` to compute the overall length of the sequence,
-   `z` to compute the number of zeros in the sequence, or
-   `s` to compute the longest run of zeros in the sequence.

There is a list of problem instances in the program's input. The program shall read the individual problems instances, process them, and display the desired result. The processing of the input ends when the program reaches the end of file (EOF).

The output of the program is the result of the desired computation; the result is shown for each input problem instance. The exact output format is shown in the sample runs below.

The program must validate input data. If the input is invalid, the program must detect it, it shall output an error message (see below), and terminate. If displayed, the error message must be sent to the standard output (do not send it to the error output) and the error message must be terminated by a newline (\\n). The input is considered invalid, if:

-   the radix or the interval boundaries are invalid (are not valid decimal integers),
-   the boundaries are negative,
-   the lower bound is greater than the upper bound,
-   the radix is not in the range 2 to 36,
-   the desired computation is not any of `l`, `z`, and `s`, or
-   there are missing/redundant separators (angle brace, semicolon).

**Sample program runs:**

* * * * *

    Enter the intervals:
    <0;100> l
    Digits: 193
    <0;100> z
    Zeros: 12
    <0;100> s
    Sequence: 2
    r2:<11;21> l
    Digits: 50
    r2:<11;21> z
    Zeros: 22
    r2:<11;21> s
    Sequence: 4
    r4:<10;20> l
    Digits: 27
    r4:<10;20> z
    Zeros: 7
    r4:<10;20> s
    Sequence: 2
    r 3 : < 70 ; 112 > l
    Digits: 204
    r 3 : < 70 ; 112 > z
    Zeros: 70
    r 3 : < 70 ; 112 > s
    Sequence: 4
    r10: <6; 100> l
    Digits: 187
    r10: <6; 100> z
    Zeros: 11
    r10: <6; 100> s
    Sequence: 2
    r36 :<44;144> l
    Digits: 202
    r36 :<44;144> z
    Zeros: 3
    r36 :<44;144> s
    Sequence: 1

* * * * *

    Enter the intervals:
    <10;10> l
    Digits: 2
    <10;10> z
    Zeros: 1
    <10;10> s
    Sequence: 1
    r19:<61;61> l
    Digits: 2
    r19:<61;61> z
    Zeros: 0
    r19:<61;61> s
    Sequence: 0
    r44:<3,16> l
    Invalid input.

* * * * *

    Enter the intervals:
    <31;27> l
    Invalid input.

* * * * *

    Enter the intervals:
    33;41 z
    Invalid input.

* * * * *

    Enter the intervals:
    <33;asdf> s
    Invalid input.

* * * * *

**Advice:**

-   The sample runs above list both the output of your program (boldface font) and user input (regular font). The bold/regular formatting is included here, in the problem statement page, to increase readability of the listing. Your program must output the text without any additional markup.
-   Do not forget the newline (\\n) after the last output line.
-   The program can be developed without additional functions (i.e., in one big `main`). However, if divided into functions, the program is readable and easier to debug.
-   A reasonable implementation of the naive algorithm passes all tests except the bonus tests. The naive algorithm passes all numbers in the input interval and analyzes their binary representation. Loops, conditions, and a few integer variables are needed in the implementation. There is no need for arrays or strings. Do not construct the entire binary sequence in the program's memory. Such implementation is clumsy, error-prone, laborious, and slow.
-   Speed test \#1 is a bonus test. The test inputs long intervals, the total number of digits is to be computed. The number of digits must be computed using an efficient algorithm to pass the time limits. Such an algorithm does not scan all numbers in the input interval. Instead, it establishes the result based just on the interval boundaries. The other computations (count of zeros, the longest run of zeros) are not tested in speed test \#1, thus efficient algorithms are not needed to pass. If a program passes the bonus test, it is awarded some extra points (above the nominal 100%).
-   Speed test \#2 is similar to the speed test \#1. All three computations (total number of digits, count of zeros, the longest run of zeros) are tested, moreover, the input intervals are long. All computations must be done by efficient algorithms to pass the test. The implementation may need a few small arrays (up to 100 elements) to store some intermediate results.
-   The inputs are chosen such that the input values fit into the `int` data type. The same applies to the resulting values in the mandatory and optional tests. The intervals in the bonus tests are very long, thus the results may exceed the limits of `int` data type. It is recommended to use the `long long int` data type when developing a program that is supposed to pass the bonus tests.
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

            input      ::= full | short 
            full       ::= { whiteSpace } 'r' { whiteSpace } integer { whiteSpace } ':' short
            short      ::= { whiteSpace } '<' { whiteSpace } integer { whiteSpace } ';' 
                           { whiteSpace } integer { whiteSpace } '>' { whiteSpace } computation { whiteSpace }
            whiteSpace ::= ' ' | '\t' | '\n' | '\r'
            computation::= 'l' | 'z' | 's'
            integer    ::= digit { digit }
            digit      ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
           

**Sample data:**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskS&Cou=251&Tgr=1586&Tsk=1570)

 **Reference**

 

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Základní test s parametry podle ukázky': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 0.500 s)
        -   Total run time: 0.025 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Test mezních hodnot': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 0.500 s)
        -   Total run time: 0.024 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Test ošetření nesprávných vstupů': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.006 s (limit: 0.100 s)
        -   Total run time: 0.167 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Test náhodnými daty': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.092 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Test rychlosti \#1': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.005 s (limit: 0.100 s)
        -   Total run time: 0.017 s
        -   Bonus test - success, evaluation: 120.00 %
    -   Test 'Test rychlosti \#2': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.005 s (limit: 0.100 s)
        -   Total run time: 0.028 s
        -   Bonus test - success, evaluation: 120.00 %
    -   Overall ratio: 144.00 % (= 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.20 \* 1.20)
-   Total percent: 144.00 %
-   Early submission bonus: 0.50
-   Total points: 1.44 \* ( 5.00 + 0.50 ) = 7.92

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**9**|--|--|--|
|Lines of code:|**160**|17.78 ± 8.95|33|`seqZeros`|
|Cyclomatic complexity:|**48**|5.33 ± 4.27|15|`readInterval`|

**4**

**2018-11-10 22:38:33**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1586&Tsk=1570&Sub=989630)

**Submission status:**

Evaluated

 

**Evaluation:**

5.5000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.005 s (limit: 0.500 s)
        -   Total run time: 0.023 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 0.500 s)
        -   Total run time: 0.021 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Invalid input test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.004 s (limit: 0.100 s)
        -   Total run time: 0.134 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.088 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test \#1': Abnormal program termination (Time limit exceeded)
        -   Program was killed after: 0.102 s (limit: 0.100 s)
        -   Bonus test - failed, evaluation: No bonus awarded
        -   Time limit exceeded [[Unlock advice (180 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2916908'))
    -   Test 'Speed test \#2': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 100.00 % (= 1.00 \* 1.00 \* 1.00 \* 1.00)
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 100.00 %
-   Early submission bonus: 0.50
-   Total points: 1.00 \* ( 5.00 + 0.50 ) = 5.50

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**4**|--|--|--|
|Lines of code:|**129**|32.25 ± 22.16|70|`main`|
|Cyclomatic complexity:|**36**|9.00 ± 8.69|24|`main`|

**3**

**2018-11-10 22:25:40**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1586&Tsk=1570&Sub=989605)

**Submission status:**

Evaluated

 

**Evaluation:**

5.3472

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.007 s (limit: 0.500 s)
        -   Total run time: 0.027 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 0.500 s)
        -   Total run time: 0.023 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Invalid input test': success
        -   result: 97.22 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 0.100 s)
        -   Total run time: 0.167 s
        -   Optional test success, evaluation: 97.22 %
        -    Failed (invalid output)

             Input data [[9 B / 9 B]](https://progtest.fit.cvut.cz/index.php?X=Advice&UID=I2916806)

            ``` {#pre_I2916806 style="display: none"}
            *5;10> l
            ```

             Output data [[31 B / 31 B]](https://progtest.fit.cvut.cz/index.php?X=Advice&UID=O2916806)

            ``` {#pre_O2916806 style="display: none"}
            Enter the intervals:
            Digits: 7
            ```

             Reference [[36 B / 36 B]](https://progtest.fit.cvut.cz/index.php?X=Advice&UID=R2916806)

            ``` {#pre_R2916806 style="display: none"}
            Enter the intervals:
            Invalid input.
            ```

    -   Test 'Random test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.094 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test \#1': Abnormal program termination (Time limit exceeded)
        -   Program was killed after: 0.103 s (limit: 0.100 s)
        -   Bonus test - failed, evaluation: No bonus awarded
        -   Time limit exceeded [[Unlock advice (128 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2916807'))
    -   Test 'Speed test \#2': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 97.22 % (= 1.00 \* 1.00 \* 0.97 \* 1.00)
-   Total percent: 97.22 %
-   Early submission bonus: 0.50
-   Total points: 0.97 \* ( 5.00 + 0.50 ) = 5.35

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**4**|--|--|--|
|Lines of code:|**129**|32.25 ± 22.16|70|`main`|
|Cyclomatic complexity:|**35**|8.75 ± 8.26|23|`main`|

**2**

**2018-11-10 18:38:41**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1586&Tsk=1570&Sub=989168)

**Submission status:**

Evaluated

 

**Evaluation:**

2.5972

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 0.500 s)
        -   Total run time: 0.028 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.006 s (limit: 0.500 s)
        -   Total run time: 0.026 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Invalid input test': success
        -   result: 94.44 %, required: 50.00 %
        -   Max. run time: 0.006 s (limit: 0.100 s)
        -   Total run time: 0.168 s
        -   Optional test success, evaluation: 94.44 %
        -   Failed (invalid output) [[Unlock advice (77 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911975'))
        -   Failed (invalid output) [[Unlock advice (78 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911976'))
    -   Test 'Random test': failed
        -   result: 30.00 %, required: 50.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.099 s
        -   Optional test failed, evaluation: 50.00 %
        -   Failed (invalid output) [[Unlock advice (601 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911977'))
        -   Failed (invalid output) [[Unlock advice (436 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911978'))
        -   Failed (invalid output) [[Unlock advice (488 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911979'))
        -   Failed (invalid output) [[Unlock advice (560 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911980'))
        -   Failed (invalid output) [[Unlock advice (565 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911981'))
        -   Failed (invalid output) [[Unlock advice (610 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911982'))
        -   Failed (invalid output) [[Unlock advice (527 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911983'))
        -   Failed (invalid output) [[Unlock advice (526 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911984'))
        -   Failed (invalid output) [[Unlock advice (447 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911985'))
        -   Failed (invalid output) [[Unlock advice (562 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911986'))
        -   Failed (invalid output) [[Unlock advice (563 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911987'))
        -   Failed (invalid output) [[Unlock advice (549 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911988'))
        -   Failed (invalid output) [[Unlock advice (583 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911989'))
        -   Failed (invalid output) [[Unlock advice (437 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911990'))
    -   Test 'Speed test \#1': Abnormal program termination (Time limit exceeded)
        -   Program was killed after: 0.102 s (limit: 0.100 s)
        -   Bonus test - failed, evaluation: No bonus awarded
        -   Time limit exceeded [[Unlock advice (92 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911991'))
    -   Test 'Speed test \#2': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 47.22 % (= 1.00 \* 1.00 \* 0.94 \* 0.50)
-   Total percent: 47.22 %
-   Early submission bonus: 0.50
-   Total points: 0.47 \* ( 5.00 + 0.50 ) = 2.60

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**4**|--|--|--|
|Lines of code:|**129**|32.25 ± 22.16|70|`main`|
|Cyclomatic complexity:|**35**|8.75 ± 8.26|23|`main`|

**1**

**2018-11-10 18:19:18**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1586&Tsk=1570&Sub=989141)

**Submission status:**

Evaluated

 

**Evaluation:**

2.5972

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 0.500 s)
        -   Total run time: 0.027 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.007 s (limit: 0.500 s)
        -   Total run time: 0.032 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Invalid input test': success
        -   result: 94.44 %, required: 50.00 %
        -   Max. run time: 0.007 s (limit: 0.100 s)
        -   Total run time: 0.204 s
        -   Optional test success, evaluation: 94.44 %
        -   Failed (invalid output) [[Unlock advice (77 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911865'))
        -   Failed (invalid output) [[Unlock advice (78 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911866'))
    -   Test 'Random test': failed
        -   result: 25.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.095 s
        -   Optional test failed, evaluation: 50.00 %
        -   Failed (invalid output) [[Unlock advice (612 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911867'))
        -   Failed (invalid output) [[Unlock advice (598 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911868'))
        -   Failed (invalid output) [[Unlock advice (599 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911869'))
        -   Failed (invalid output) [[Unlock advice (601 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911870'))
        -   Failed (invalid output) [[Unlock advice (473 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911871'))
        -   Failed (invalid output) [[Unlock advice (607 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911872'))
        -   Failed (invalid output) [[Unlock advice (526 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911873'))
        -   Failed (invalid output) [[Unlock advice (519 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911874'))
        -   Failed (invalid output) [[Unlock advice (492 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911875'))
        -   Failed (invalid output) [[Unlock advice (447 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911876'))
        -   Failed (invalid output) [[Unlock advice (570 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911877'))
        -   Failed (invalid output) [[Unlock advice (511 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911878'))
        -   Failed (invalid output) [[Unlock advice (439 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911879'))
        -   Failed (invalid output) [[Unlock advice (454 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911880'))
        -   Failed (invalid output) [[Unlock advice (603 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911881'))
    -   Test 'Speed test \#1': Abnormal program termination (Time limit exceeded)
        -   Program was killed after: 0.103 s (limit: 0.100 s)
        -   Bonus test - failed, evaluation: No bonus awarded
        -   Time limit exceeded [[Unlock advice (150 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1586&Tsk=1570&Unl=L2911882'))
    -   Test 'Speed test \#2': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 47.22 % (= 1.00 \* 1.00 \* 0.94 \* 0.50)
-   Total percent: 47.22 %
-   Early submission bonus: 0.50
-   Total points: 0.47 \* ( 5.00 + 0.50 ) = 2.60

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**4**|--|--|--|
|Lines of code:|**129**|32.25 ± 22.16|70|`main`|
|Cyclomatic complexity:|**35**|8.75 ± 8.26|23|`main`|


