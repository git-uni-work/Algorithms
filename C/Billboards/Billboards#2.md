||
|[ProgTest](https://progtest.fit.cvut.cz/index.php?X=Main)  ►  [BIE-PA1 (18/19 ZS)](https://progtest.fit.cvut.cz/index.php?X=Course&Cou=251)  ►  [Homework 04](https://progtest.fit.cvut.cz/index.php?X=TaskGrp&Cou=251&Tgr=1588)  ►  **Billboards II**|[Logout](https://progtest.fit.cvut.cz/index.php?X=Logout)|

||
|**Billboards II**|

**Submission deadline:**

**2018-12-02 23:59:59**

 

**Late submission with malus:**

**2019-01-06 23:59:59** (Late submission malus: 100.0000 %)

**Evaluation:**

**5.0000**

**Max. assessment:**

**5.0000** (Without bonus points)

**Submissions:**

4 / 20 Free retries + 10 Penalized retries (-10 % penalty each retry)

**Advices:**

2 / 2 Advices for free + 2 Advices with a penalty (-10 % penalty each advice)

The task is to develop a program that plans the positions of billboards along a highway. This problem is an extension of the simpler task.

The task is to develop a program to solve the planning of billboards. There are certain places along the highway suitable to place the billboards (conversely, the billboards cannot be placed anywhere else). The suitable places are identified by their position from the beginning of the highway; the position is an integer. There is at most 1000000 such places.

We are about to use some of the places for our advertising. Our primary concern is to place exactly the given number of billboards. Secondly, the distance between a pair of adjacent billboards must be as high as possible. The program shall place the billboards and find the distance between the closest pair of billboards.

The input of the program is the list of suitable places. Each place is described by an integer; the integers are enclosed in curly braces and separated by commas. Following the places, there is a list of queries. Each query is formed by an integer - the required number of billboards `cnt`. The queries are read from the input until the end-of-file is reached.

The output of the program is the computed distance of the closest pair of billboards, the output is provided for each input query. There are some combinations of input data where the distance cannot be computed. Namely, the first special case is "infinite" and the second special case is "cannot accomplish". There is a special output in these case. The exact output format is shown in the sample runs below.

The program must validate input data. If the input is invalid, the program must detect it, it shall output an error message (see below), and terminate. If displayed, the error message must be sent to the standard output (do not send it to the error output) and the error message must be terminated by a newline (\\n). The input is considered invalid, if:

-   the suitable positions or the number of billboards are not valid integers,
-   suitable billboard positions are negative,
-   the list of suitable billboard positions is empty,
-   there is more than 1000000 billboard positions in the input,
-   the number of billboards `cnt` is negative,
-   there are missing/redundant separators (curly brace, comma).

**Sample program runs:**

* * * * *

    Suitable positions:
    { 250, 500, 750 }
    # of billboards:
    0
    Distance: inf
    3
    Distance: 250
    2
    Distance: 500
    1
    Distance: inf
    4
    N/A

* * * * *

    Suitable positions:
    { 250 , 300 , 550 , 750 }
    # of billboards:
    1
    Distance: inf
    5
    N/A
    4
    Distance: 50
    2
    Distance: 500
    3
    Distance: 200

* * * * *

    Suitable positions:
    {481,692,159,843,921,315}
    # of billboards:
    1
    Distance: inf
    5
    Distance: 156
    4
    Distance: 211
    6
    Distance: 78
    2
    Distance: 762
    3
    Distance: 322

* * * * *

    Suitable positions:
    {0,1,2,1,2}
    # of billboards:
    2
    Distance: 2
    4
    Distance: 0
    1
    Distance: inf
    3
    Distance: 1
    6
    N/A
    2
    Distance: 2
    5
    Distance: 0

* * * * *

    Suitable positions:
    {250,-3}
    Invalid input.

* * * * *

    Suitable positions:
    {15,240 310
    Invalid input.

* * * * *

**Advice:**

-   The sample runs above list both the output of your program (boldface font) and user input (regular font). The bold/regular formatting is included here, in the problem statement page, to increase readability of the listing. Your program must output the text without any additional markup.
-   Do not forget the newline (\\n) after the last output line.
-   The program is to store the suitable billboard positions. There is up to 1000000 such positions. Therefore, the positions may be stored in a statically allocated array. This task does not require dynamic memory allocation.
-   A reasonable implementation of the naive algorithm passes all tests except the bonus tests. The naive algorithm just sets up a minimum billboard distance and tries to place all billboards with that minimum distance. Based on the result, the distance is either increased or decreased until the minimum is found.
-   Speed tests \#1 and \#2 are extra bonus tests. The tests input long highways with many suitable places for the billboards. Moreover, there is a lot of queries with various distances. The naive algorithm is too slow to finish in the given time limit. An efficient algorithm must be used, moreover, it may be advantageous to pre-process the input data.
-   The inputs are chosen such that the input values fit into the `int` data type.
-   Your program will be tested in a restricted environment. The testing environment limits running time and available memory. The exact time and memory limits are shown in the reference solution testing log. The memory limit is approx. 500MiB, i.e., more than enough to store the input data in a statically allocated array.
-   Textual description of valid input data structure is not 100% exact. Therefore we provide a formal specification of the input language in EBNF:

            input      ::= { whiteSpace } '{' posList '}' queryList { whiteSpace }
            whiteSpace ::= ' ' | '\t' | '\n' | '\r'
            posList    ::= { { whiteSpace } integer { whiteSpace } ',' } { whiteSpace } integer { whiteSpace }
            queryList  ::= { { whiteSpace } integer }
            integer    ::= digit { digit }
            digit      ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
           

**Sample data:**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskS&Cou=251&Tgr=1588&Tsk=1576)

 **Reference**

 

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Základní test s parametry podle ukázky': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.032 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Test mezních hodnot': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.047 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Test ošetření nesprávných vstupů': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.066 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Test náhodnými daty': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.009 s (limit: 1.000 s)
        -   Total run time: 0.131 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Test náhodnými daty + mem dbg': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.025 s (limit: 1.000 s)
        -   Total run time: 0.208 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Test rychlosti I': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.101 s (limit: 1.000 s)
        -   Total run time: 0.101 s
        -   Bonus test - success, evaluation: 120.00 %
    -   Test 'Test rychlosti II': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.454 s (limit: 2.000 s)
        -   Total run time: 0.454 s
        -   Bonus test - success, evaluation: 120.00 %
    -   Overall ratio: 144.00 % (= 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.20 \* 1.20)
-   Total percent: 144.00 %
-   Early submission bonus: 0.50
-   Total points: 1.44 \* ( 5.00 + 0.50 ) = 7.92

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**7**|--|--|--|
|Lines of code:|**143**|20.43 ± 9.48|38|`main`|
|Cyclomatic complexity:|**33**|4.71 ± 2.37|8|`readPlaces`|

**4**

**2019-01-05 23:29:56**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1588&Tsk=1576&Sub=1047492)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.034 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.051 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Invalid input test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.066 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.156 s (limit: 1.000 s)
        -   Total run time: 1.376 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test + mem dbg': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.077 s (limit: 1.000 s)
        -   Total run time: 0.461 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test \#1': Abnormal program termination (Time limit exceeded)
        -   Program was killed after: 1.004 s (limit: 1.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
        -   Time limit exceeded [[Unlock advice (8.00 KiB, incomplete data)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1576&Unl=L3119671'))
    -   Test 'Speed test \#2': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 100.00 % (= 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.00)
-   Advices used: 2
-   Penalty due to advices: None (2 \<= 2 limit)
-   Total percent: 100.00 %
-   Late submission malus: 5.00
-   Total points: 1.00 \* ( 5.00 - 5.00 ) = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**3**|--|--|--|
|Lines of code:|**131**|43.67 ± 39.84|100|`main`|
|Cyclomatic complexity:|**27**|9.00 ± 7.79|20|`main`|

**3**

**2018-12-02 23:25:24**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1588&Tsk=1576&Sub=1020798)

**Submission status:**

Evaluated

 

**Evaluation:**

5.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.034 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.049 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Invalid input test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.068 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.163 s (limit: 1.000 s)
        -   Total run time: 1.481 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test + mem dbg': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.093 s (limit: 1.000 s)
        -   Total run time: 0.426 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test \#1': Abnormal program termination (Time limit exceeded)
        -   Program was killed after: 1.002 s (limit: 1.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
        -   Time limit exceeded [[Unlock advice (8.00 KiB, incomplete data)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1576&Unl=L3047362'))
    -   Test 'Speed test \#2': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 100.00 % (= 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.00)
-   Advices used: 2
-   Penalty due to advices: None (2 \<= 2 limit)
-   Total percent: 100.00 %
-   Total points: 1.00 \* 5.00 = 5.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**3**|--|--|--|
|Lines of code:|**131**|43.67 ± 39.84|100|`main`|
|Cyclomatic complexity:|**27**|9.00 ± 7.79|20|`main`|

**2**

**2018-12-02 22:54:05**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1588&Tsk=1576&Sub=1020677)

**Submission status:**

Evaluated

 

**Evaluation:**

4.1786

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.029 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 90.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.046 s
        -   Optional test success, evaluation: 90.00 %
        -    Failed (invalid output)

             Input data [[25 B / 25 B]](https://progtest.fit.cvut.cz/index.php?X=Advice&UID=I3046728)

            ``` {#pre_I3046728 style="display: none"}
            {272}
            0
            1
            2
            3
            4
            12345678
            ```

             Output data [[89 B / 89 B]](https://progtest.fit.cvut.cz/index.php?X=Advice&UID=O3046728)

            ``` {#pre_O3046728 style="display: none"}
            Suitable positions:
            # of billboards:
            Distance: inf
            Distance: inf
            Distance: 0
            N/A
            N/A
            N/A
            ```

             Reference [[81 B / 81 B]](https://progtest.fit.cvut.cz/index.php?X=Advice&UID=R3046728)

            ``` {#pre_R3046728 style="display: none"}
            Suitable positions:
            # of billboards:
            Distance: inf
            Distance: inf
            N/A
            N/A
            N/A
            N/A
            ```

    -   Test 'Invalid input test': success
        -   result: 92.86 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.060 s
        -   Optional test success, evaluation: 92.86 %
        -    Failed (invalid output)

             Input data [[10 B / 10 B]](https://progtest.fit.cvut.cz/index.php?X=Advice&UID=I3046729)

            ``` {#pre_I3046729 style="display: none"}
            {6,11}
            -7
            ```

             Output data [[49 B / 49 B]](https://progtest.fit.cvut.cz/index.php?X=Advice&UID=O3046729)

            ``` {#pre_O3046729 style="display: none"}
            Suitable positions:
            # of billboards:
            Distance: 0
            ```

             Reference [[52 B / 52 B]](https://progtest.fit.cvut.cz/index.php?X=Advice&UID=R3046729)

            ``` {#pre_R3046729 style="display: none"}
            Suitable positions:
            # of billboards:
            Invalid input.
            ```

    -   Test 'Random test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.184 s (limit: 1.000 s)
        -   Total run time: 1.279 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test + mem dbg': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.067 s (limit: 1.000 s)
        -   Total run time: 0.373 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test \#1': Abnormal program termination (Time limit exceeded)
        -   Program was killed after: 1.003 s (limit: 1.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
        -   Time limit exceeded [[Unlock advice (8.00 KiB, incomplete data)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1576&Unl=L3046730'))
    -   Test 'Speed test \#2': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 83.57 % (= 1.00 \* 0.90 \* 0.93 \* 1.00 \* 1.00)
-   Total percent: 83.57 %
-   Total points: 0.84 \* 5.00 = 4.18

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**3**|--|--|--|
|Lines of code:|**125**|41.67 ± 37.01|94|`main`|
|Cyclomatic complexity:|**24**|8.00 ± 6.38|17|`main`|

**1**

**2018-12-02 22:36:28**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1588&Tsk=1576&Sub=1020627)

**Submission status:**

Evaluated

 

**Evaluation:**

0.5625

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.008 s (limit: 1.000 s)
        -   Total run time: 0.040 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 90.00 %, required: 50.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.054 s
        -   Optional test success, evaluation: 90.00 %
        -   Failed (invalid output) [[Unlock advice (195 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1576&Unl=L3046475'))
    -   Test 'Invalid input test': Abnormal program termination (Time limit exceeded)
        -   Program was killed after: 1.002 s (limit: 1.000 s)
        -   Optional test failed, evaluation: 50.00 %
        -   Failed (invalid output) [[Unlock advice (111 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1576&Unl=L3046476'))
        -   Time limit exceeded [[Unlock advice (12 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1576&Unl=L3046477'))
    -   Test 'Random test': Not tested
        -   Optional test failed, evaluation: 50.00 %
    -   Test 'Random test + mem dbg': Not tested
        -   Optional test failed, evaluation: 50.00 %
    -   Test 'Speed test \#1': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Test 'Speed test \#2': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 11.25 % (= 1.00 \* 0.90 \* 0.50 \* 0.50 \* 0.50)
-   Total percent: 11.25 %
-   Total points: 0.11 \* 5.00 = 0.56

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**3**|--|--|--|
|Lines of code:|**115**|38.33 ± 32.29|84|`main`|
|Cyclomatic complexity:|**23**|7.67 ± 5.91|16|`main`|


