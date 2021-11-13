||
|[ProgTest](https://progtest.fit.cvut.cz/index.php?X=Main)  ►  [BIE-PA1 (18/19 ZS)](https://progtest.fit.cvut.cz/index.php?X=Course&Cou=251)  ►  [Homework 04](https://progtest.fit.cvut.cz/index.php?X=TaskGrp&Cou=251&Tgr=1588)  ►  **Billboards I**|[Logout](https://progtest.fit.cvut.cz/index.php?X=Logout)|

||
|**Billboards I**|

**Submission deadline:**

**2018-12-02 23:59:59**

 

**Late submission with malus:**

**2019-01-06 23:59:59** (Late submission malus: 100.0000 %)

**Evaluation:**

**3.3000**

**Max. assessment:**

**3.0000** (Without bonus points)

**Submissions:**

18 / 20 Free retries + 10 Penalized retries (-10 % penalty each retry)

**Advices:**

2 / 2 Advices for free + 2 Advices with a penalty (-10 % penalty each advice)

The task is to develop a program that plans the positions of billboards along a highway.

Even though billboards positioned along highways impose some threat, they are still used as an efficient form of advertising. The efficiency of the billboards may be increased if the layout is well thought up. The task is to develop a program to solve the planning. We assume there is a highway of length `len`. There are certain places along the highway suitable to place the billboards (conversely, the billboards cannot be placed anywhere else). The suitable places are identified by their position from the beginning of the highway; the position is an integer in the range `[1;len-1]`. There is at most 1000000 such places.

We are about to use some of the places for our advertising. Our concern is to use as few billboards as possible. On the other hand, we require that the distance between two consecutive billboards is at most `dist`. The first billboard must be placed within `dist` from the beginning of the highway. Similarly, the last billboard must be placed within `dist` from the end of the highway. Based on these criteria, the program shall find the required number of billboards.

The input of the program is an integer - the length of the highway `len`. The length is followed by the list of suitable places. Each place is described by an integer; the integers are enclosed in curly braces and separated by commas. Following the places, there is a list of queries. Each query is formed by an integer - the distance `dist`. The queries are read from the input until the end-of-file is reached.

The output of the program is the required number of billboards for each input query. The billboards cannot be placed for certain combinations of positions and distances. A different output is printed out in these case. The exact output format is shown in the sample runs below.

The program must validate input data. If the input is invalid, the program must detect it, it shall output an error message (see below), and terminate. If displayed, the error message must be sent to the standard output (do not send it to the error output) and the error message must be terminated by a newline (\\n). The input is considered invalid, if:

-   the distances are not valid integers,
-   highway length is zero or negative,
-   suitable billboard positions do not fit the range `<1;len-1>`,
-   the list of suitable billboard positions is empty,
-   there is more than 1000000 billboard positions in the input,
-   the distance `dist` is negative or zero,
-   there are missing/redundant separators (curly brace, comma, colon).

**Sample program runs:**

* * * * *

    Suitable positions:
    1000: { 250, 500, 750 }
    Distances:
    800
    Billboards: 1
    500
    Billboards: 1
    300
    Billboards: 3
    250
    Billboards: 3
    200
    N/A

* * * * *

    Suitable positions:
    1000 : { 250 , 300 , 550 , 750 }
    Distances:
    371
    Billboards: 3
    507
    Billboards: 2
    273
    Billboards: 4
    561
    Billboards: 1

* * * * *

    Suitable positions:
    1000:{481,692,159,843,921,315}
    Distances:
    1000
    Billboards: 0
    999
    Billboards: 1
    519
    Billboards: 1
    518
    Billboards: 2
    377
    Billboards: 2
    376
    Billboards: 3
    315
    Billboards: 3
    314
    Billboards: 4
    308
    Billboards: 4
    307
    Billboards: 5
    211
    Billboards: 5
    210
    N/A

* * * * *

    Suitable positions:
    3:{1,2,1,2}
    Distances:
    1
    Billboards: 2
    10
    Billboards: 0

* * * * *

    Suitable positions:
    500:{250,830}
    Invalid input.

* * * * *

    Suitable positions:
    330:{15,240 310
    Invalid input.

* * * * *

**Advice:**

-   The sample runs above list both the output of your program (boldface font) and user input (regular font). The bold/regular formatting is included here, in the problem statement page, to increase readability of the listing. Your program must output the text without any additional markup.
-   Do not forget the newline (\\n) after the last output line.
-   The program is to store the suitable billboard positions. There is up to 1000000 such positions. Therefore, the positions may be stored in a statically allocated array. This task does not require dynamic memory allocation.
-   A reasonable implementation of the naive algorithm passes all tests except the bonus tests. The naive algorithm just passes the suitable positions an allocates them with respect to the maximal allowed distance.
-   Speed tests \#1 and \#2 are extra bonus tests. The tests input long highways with many suitable places for the billboards. Moreover, there is a lot of queries with various distances. The naive algorithm is too slow to finish in the given time limit. An efficient algorithm must be used, moreover, it may be advantageous to pre-process the input data.
-   The inputs are chosen such that the input values fit into the `int` data type.
-   Your program will be tested in a restricted environment. The testing environment limits running time and available memory. The exact time and memory limits are shown in the reference solution testing log. The memory limit is approx. 500MiB, i.e., more than enough to store the input data in a statically allocated array.
-   Textual description of valid input data structure is not 100% exact. Therefore we provide a formal specification of the input language in EBNF:

            input      ::= { whiteSpace } integer { whiteSpace } ':' { whiteSpace } '{' posList '}' 
                           queryList { whiteSpace }
            whiteSpace ::= ' ' | '\t' | '\n' | '\r'
            posList    ::= { { whiteSpace } integer { whiteSpace } ',' } { whiteSpace } integer { whiteSpace }
            queryList  ::= { { whiteSpace } integer }
            integer    ::= digit { digit }
            digit      ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
           

**Sample data:**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskS&Cou=251&Tgr=1588&Tsk=1575)

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
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.045 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Test ošetření nesprávných vstupů': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.007 s (limit: 1.000 s)
        -   Total run time: 0.143 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Test náhodnými daty': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.007 s (limit: 2.000 s)
        -   Total run time: 0.112 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Tet náhodnými daty + mem dbg': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.034 s (limit: 2.000 s)
        -   Total run time: 0.252 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Test rychlosti I': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.021 s (limit: 1.000 s)
        -   Total run time: 0.035 s
        -   Bonus test - success, evaluation: 110.00 %
    -   Test 'Test rychlosti II': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.244 s (limit: 1.000 s)
        -   Total run time: 0.244 s
        -   Bonus test - success, evaluation: 120.00 %
    -   Overall ratio: 132.00 % (= 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.10 \* 1.20)
-   Total percent: 132.00 %
-   Early submission bonus: 0.30
-   Total points: 1.32 \* ( 3.00 + 0.30 ) = 4.36

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**6**|--|--|--|
|Lines of code:|**125**|20.83 ± 9.70|35|`main`|
|Cyclomatic complexity:|**29**|4.83 ± 2.73|10|`readPlaces`|

**18**

**2018-12-02 03:26:16**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1588&Tsk=1575&Sub=1019155)

**Submission status:**

Evaluated

 

**Evaluation:**

3.3000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.031 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.039 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Invalid input test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.008 s (limit: 1.000 s)
        -   Total run time: 0.119 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.010 s (limit: 2.000 s)
        -   Total run time: 0.106 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test + mem dbg': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.032 s (limit: 2.000 s)
        -   Total run time: 0.270 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test \#1': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.828 s (limit: 1.000 s)
        -   Total run time: 1.480 s
        -   Bonus test - success, evaluation: 110.00 %
    -   Test 'Speed test \#2': Abnormal program termination (Time limit exceeded)
        -   Program was killed after: 1.000 s (limit: 1.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
        -   Time limit exceeded [[Unlock advice (8.00 KiB, incomplete data)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3039032'))
    -   Overall ratio: 110.00 % (= 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.10)
-   Advices used: 2
-   Penalty due to advices: None (2 \<= 2 limit)
-   Total percent: 110.00 %
-   Total points: 1.10 \* 3.00 = 3.30

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**2**|--|--|--|
|Lines of code:|**142**|71.00 ± 57.00|128|`main`|
|Cyclomatic complexity:|**30**|15.00 ± 12.00|27|`main`|

**17**

**2018-12-02 02:07:45**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1588&Tsk=1575&Sub=1019135)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': failed
        -   result: 83.33 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.032 s
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (472 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3038990'))
    -   Overall ratio: 0.00 %
-   Advices used: 2
-   Penalty due to advices: None (2 \<= 2 limit)
-   Total percent: 0.00 %
-   Total points: 0.00 \* 3.00 = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**2**|--|--|--|
|Lines of code:|**141**|70.50 ± 56.50|127|`main`|
|Cyclomatic complexity:|**30**|15.00 ± 12.00|27|`main`|

**16**

**2018-12-02 01:02:26**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1588&Tsk=1575&Sub=1019096)

**Submission status:**

Evaluated

 

**Evaluation:**

1.5000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.035 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.044 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Invalid input test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.111 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.013 s (limit: 2.000 s)
        -   Total run time: 0.124 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test + mem dbg': Abnormal program termination (Segmentation fault/Bus error/Memory limit exceeded/Stack limit exceeded)
        -   Max. run time: 0.027 s (limit: 2.000 s)
        -   Total run time: 0.046 s
        -   Optional test failed, evaluation: 50.00 %
        -    Seggmentation fault

             Input data [[262 B / 262 B]](https://progtest.fit.cvut.cz/index.php?X=Advice&UID=I3038869)

            ``` {#pre_I3038869 style="display: none"}
            121:{58,102,57,112,25,49,7,30,5,83,95,49,20,4,3,45,51,50,88,47,109,59,22,25,56,67,48,18,2,76,26,58,66,87}
            7
            2
            18
            19
            1
            23
            10
            6
            12
            10
            21
            21
            20
            16
            11
            9
            19
            15
            14
            13
            7
            5
            5
            21
            22
            13
            22
            13
            11
            23
            23
            19
            5
            3
            3
            9
            15
            16
            10
            17
            17
            1
            6
            10
            14
            7
            13
            17
            15
            3
            25
            11
            13
            9
            15
            24
            16
            3
            ```

    -   Test 'Speed test \#1': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Test 'Speed test \#2': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 50.00 % (= 1.00 \* 1.00 \* 1.00 \* 1.00 \* 0.50)
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 50.00 %
-   Total points: 0.50 \* 3.00 = 1.50

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**2**|--|--|--|
|Lines of code:|**144**|72.00 ± 58.00|130|`main`|
|Cyclomatic complexity:|**30**|15.00 ± 12.00|27|`main`|

**15**

**2018-12-02 00:57:28**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1588&Tsk=1575&Sub=1019090)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': failed
        -   result: 33.33 %, required: 100.00 %
        -   Max. run time: 0.007 s (limit: 1.000 s)
        -   Total run time: 0.032 s
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (266 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3038809'))
        -   Failed (invalid output) [[Unlock advice (255 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3038810'))
        -   Failed (invalid output) [[Unlock advice (555 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3038811'))
        -   Failed (invalid output) [[Unlock advice (148 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3038812'))
    -   Overall ratio: 0.00 %
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 0.00 %
-   Total points: 0.00 \* 3.00 = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**2**|--|--|--|
|Lines of code:|**145**|72.50 ± 58.50|131|`main`|
|Cyclomatic complexity:|**30**|15.00 ± 12.00|27|`main`|

**14**

**2018-12-02 00:56:36**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1588&Tsk=1575&Sub=1019088)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': failed
        -   result: 33.33 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.034 s
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (266 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3038802'))
        -   Failed (invalid output) [[Unlock advice (255 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3038803'))
        -   Failed (invalid output) [[Unlock advice (555 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3038804'))
        -   Failed (invalid output) [[Unlock advice (148 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3038805'))
    -   Overall ratio: 0.00 %
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 0.00 %
-   Total points: 0.00 \* 3.00 = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**2**|--|--|--|
|Lines of code:|**145**|72.50 ± 58.50|131|`main`|
|Cyclomatic complexity:|**30**|15.00 ± 12.00|27|`main`|

**13**

**2018-12-02 00:42:48**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1588&Tsk=1575&Sub=1019080)

**Submission status:**

Evaluated

 

**Evaluation:**

1.5000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.029 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.038 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Invalid input test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.102 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.031 s (limit: 2.000 s)
        -   Total run time: 0.116 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test + mem dbg': Abnormal program termination (Segmentation fault/Bus error/Memory limit exceeded/Stack limit exceeded)
        -   Max. run time: 0.018 s (limit: 2.000 s)
        -   Total run time: 0.018 s
        -   Optional test failed, evaluation: 50.00 %
        -   Seggmentation fault [[Unlock advice (374 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3038740'))
    -   Test 'Speed test \#1': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Test 'Speed test \#2': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 50.00 % (= 1.00 \* 1.00 \* 1.00 \* 1.00 \* 0.50)
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 50.00 %
-   Total points: 0.50 \* 3.00 = 1.50

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**2**|--|--|--|
|Lines of code:|**141**|70.50 ± 56.50|127|`main`|
|Cyclomatic complexity:|**30**|15.00 ± 12.00|27|`main`|

**12**

**2018-12-02 00:37:31**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1588&Tsk=1575&Sub=1019076)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': failed
        -   result: 83.33 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.034 s
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (135 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3038733'))
    -   Overall ratio: 0.00 %
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 0.00 %
-   Total points: 0.00 \* 3.00 = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**2**|--|--|--|
|Lines of code:|**140**|70.00 ± 56.00|126|`main`|
|Cyclomatic complexity:|**30**|15.00 ± 12.00|27|`main`|

**11**

**2018-12-02 00:35:41**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1588&Tsk=1575&Sub=1019074)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': failed
        -   result: 33.33 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.030 s
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (244 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3038728'))
        -   Failed (invalid output) [[Unlock advice (245 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3038729'))
        -   Failed (invalid output) [[Unlock advice (488 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3038730'))
        -   Failed (invalid output) [[Unlock advice (146 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3038731'))
    -   Overall ratio: 0.00 %
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 0.00 %
-   Total points: 0.00 \* 3.00 = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**2**|--|--|--|
|Lines of code:|**143**|71.50 ± 57.50|129|`main`|
|Cyclomatic complexity:|**31**|15.50 ± 12.50|28|`main`|

**10**

**2018-11-30 18:25:01**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1588&Tsk=1575&Sub=1017691)

**Submission status:**

Evaluated

 

**Evaluation:**

3.3000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.030 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.035 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Invalid input test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.111 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.014 s (limit: 2.000 s)
        -   Total run time: 0.116 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test + mem dbg': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.028 s (limit: 2.000 s)
        -   Total run time: 0.203 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test \#1': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.824 s (limit: 1.000 s)
        -   Total run time: 1.345 s
        -   Bonus test - success, evaluation: 110.00 %
    -   Test 'Speed test \#2': Abnormal program termination (Time limit exceeded)
        -   Program was killed after: 1.004 s (limit: 1.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
        -   Time limit exceeded [[Unlock advice (8.00 KiB, incomplete data)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3032580'))
    -   Overall ratio: 110.00 % (= 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.10)
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 110.00 %
-   Total points: 1.10 \* 3.00 = 3.30

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**1**|--|--|--|
|Lines of code:|**128**|128.00 ± 0.00|128|`main`|
|Cyclomatic complexity:|**26**|26.00 ± 0.00|26|`main`|

**9**

**2018-11-30 18:22:00**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1588&Tsk=1575&Sub=1017683)

**Submission status:**

Evaluated

 

**Evaluation:**

3.1625

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.028 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.036 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Invalid input test': success
        -   result: 95.83 %, required: 50.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.113 s
        -   Optional test success, evaluation: 95.83 %
        -    Failed (invalid output)

             Input data [[15 B / 15 B]](https://progtest.fit.cvut.cz/index.php?X=Advice&UID=I3032563)

            ``` {#pre_I3032563 style="display: none"}
            42:{6,7}
            pwwqd
            ```

             Output data [[46 B / 46 B]](https://progtest.fit.cvut.cz/index.php?X=Advice&UID=O3032563)

            ``` {#pre_O3032563 style="display: none"}
            Suitable positions:
            Distances:
            Invalid Input.
            ```

             Reference [[46 B / 46 B]](https://progtest.fit.cvut.cz/index.php?X=Advice&UID=R3032563)

            ``` {#pre_R3032563 style="display: none"}
            Suitable positions:
            Distances:
            Invalid input.
            ```

    -   Test 'Random test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.023 s (limit: 2.000 s)
        -   Total run time: 0.148 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test + mem dbg': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.026 s (limit: 2.000 s)
        -   Total run time: 0.213 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test \#1': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.892 s (limit: 1.000 s)
        -   Total run time: 1.361 s
        -   Bonus test - success, evaluation: 110.00 %
    -   Test 'Speed test \#2': Abnormal program termination (Time limit exceeded)
        -   Program was killed after: 1.002 s (limit: 1.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
        -   Time limit exceeded [[Unlock advice (8.00 KiB, incomplete data)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3032564'))
    -   Overall ratio: 105.41 % (= 1.00 \* 1.00 \* 0.96 \* 1.00 \* 1.00 \* 1.10)
-   Total percent: 105.41 %
-   Total points: 1.05 \* 3.00 = 3.16

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**1**|--|--|--|
|Lines of code:|**128**|128.00 ± 0.00|128|`main`|
|Cyclomatic complexity:|**26**|26.00 ± 0.00|26|`main`|

**8**

**2018-11-30 14:46:48**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1588&Tsk=1575&Sub=1017536)

**Submission status:**

Evaluated

 

**Evaluation:**

0.3750

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.031 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.036 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Invalid input test': Abnormal program termination (Time limit exceeded)
        -   Optional test failed, evaluation: 50.00 %
        -   Time limit exceeded [[Unlock advice (16 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031868'))
    -   Test 'Random test': Not tested
        -   Optional test failed, evaluation: 50.00 %
    -   Test 'Random test + mem dbg': Not tested
        -   Optional test failed, evaluation: 50.00 %
    -   Test 'Speed test \#1': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Test 'Speed test \#2': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 12.50 % (= 1.00 \* 1.00 \* 0.50 \* 0.50 \* 0.50)
-   Total percent: 12.50 %
-   Total points: 0.12 \* 3.00 = 0.38

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**1**|--|--|--|
|Lines of code:|**123**|123.00 ± 0.00|123|`main`|
|Cyclomatic complexity:|**25**|25.00 ± 0.00|25|`main`|

**7**

**2018-11-30 14:43:55**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1588&Tsk=1575&Sub=1017532)

**Submission status:**

Evaluated

 

**Evaluation:**

0.3750

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.033 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.041 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Invalid input test': Abnormal program termination (Time limit exceeded)
        -   Program was killed after: 1.002 s (limit: 1.000 s)
        -   Optional test failed, evaluation: 50.00 %
        -   Time limit exceeded [[Unlock advice (17 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031864'))
    -   Test 'Random test': Not tested
        -   Optional test failed, evaluation: 50.00 %
    -   Test 'Random test + mem dbg': Not tested
        -   Optional test failed, evaluation: 50.00 %
    -   Test 'Speed test \#1': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Test 'Speed test \#2': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 12.50 % (= 1.00 \* 1.00 \* 0.50 \* 0.50 \* 0.50)
-   Total percent: 12.50 %
-   Total points: 0.12 \* 3.00 = 0.38

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**1**|--|--|--|
|Lines of code:|**128**|128.00 ± 0.00|128|`main`|
|Cyclomatic complexity:|**26**|26.00 ± 0.00|26|`main`|

**6**

**2018-11-30 14:41:04**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1588&Tsk=1575&Sub=1017531)

**Submission status:**

Evaluated

 

**Evaluation:**

0.3750

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.031 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.038 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Invalid input test': Abnormal program termination (Time limit exceeded)
        -   Optional test failed, evaluation: 50.00 %
        -   Time limit exceeded [[Unlock advice (15 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031863'))
    -   Test 'Random test': Not tested
        -   Optional test failed, evaluation: 50.00 %
    -   Test 'Random test + mem dbg': Not tested
        -   Optional test failed, evaluation: 50.00 %
    -   Test 'Speed test \#1': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Test 'Speed test \#2': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 12.50 % (= 1.00 \* 1.00 \* 0.50 \* 0.50 \* 0.50)
-   Total percent: 12.50 %
-   Total points: 0.12 \* 3.00 = 0.38

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**1**|--|--|--|
|Lines of code:|**128**|128.00 ± 0.00|128|`main`|
|Cyclomatic complexity:|**26**|26.00 ± 0.00|26|`main`|

**5**

**2018-11-30 14:39:14**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1588&Tsk=1575&Sub=1017529)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': failed
        -   result: 83.33 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.031 s
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (80 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031861'))
    -   Overall ratio: 0.00 %
-   Total percent: 0.00 %
-   Total points: 0.00 \* 3.00 = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**1**|--|--|--|
|Lines of code:|**123**|123.00 ± 0.00|123|`main`|
|Cyclomatic complexity:|**26**|26.00 ± 0.00|26|`main`|

**4**

**2018-11-30 14:36:11**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1588&Tsk=1575&Sub=1017526)

**Submission status:**

Evaluated

 

**Evaluation:**

0.3750

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.029 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.045 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Invalid input test': Abnormal program termination (Time limit exceeded)
        -   Program was killed after: 1.002 s (limit: 1.000 s)
        -   Optional test failed, evaluation: 50.00 %
        -   Time limit exceeded [[Unlock advice (16 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031803'))
    -   Test 'Random test': Not tested
        -   Optional test failed, evaluation: 50.00 %
    -   Test 'Random test + mem dbg': Not tested
        -   Optional test failed, evaluation: 50.00 %
    -   Test 'Speed test \#1': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Test 'Speed test \#2': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 12.50 % (= 1.00 \* 1.00 \* 0.50 \* 0.50 \* 0.50)
-   Total percent: 12.50 %
-   Total points: 0.12 \* 3.00 = 0.38

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**1**|--|--|--|
|Lines of code:|**123**|123.00 ± 0.00|123|`main`|
|Cyclomatic complexity:|**25**|25.00 ± 0.00|25|`main`|

**3**

**2018-11-30 14:11:27**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1588&Tsk=1575&Sub=1017513)

**Submission status:**

Evaluated

 

**Evaluation:**

0.3953

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.032 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': failed
        -   result: 37.50 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.034 s
        -   Optional test failed, evaluation: 50.00 %
        -   Failed (invalid output) [[Unlock advice (276 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031760'))
        -   Failed (invalid output) [[Unlock advice (343 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031761'))
        -   Failed (invalid output) [[Unlock advice (471 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031762'))
        -   Failed (invalid output) [[Unlock advice (135 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031763'))
        -   Failed (invalid output) [[Unlock advice (116 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031764'))
    -   Test 'Invalid input test': success
        -   result: 95.83 %, required: 50.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.112 s
        -   Optional test success, evaluation: 95.83 %
        -   Failed (invalid output) [[Unlock advice (97 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031765'))
    -   Test 'Random test': failed
        -   result: 45.00 %, required: 50.00 %
        -   Max. run time: 0.024 s (limit: 2.000 s)
        -   Total run time: 0.115 s
        -   Optional test failed, evaluation: 50.00 %
        -   Failed (invalid output) [[Unlock advice (2.40 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031766'))
        -   Failed (invalid output) [[Unlock advice (1.40 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031767'))
        -   Failed (invalid output) [[Unlock advice (3.11 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031768'))
        -   Failed (invalid output) [[Unlock advice (1.62 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031769'))
        -   Failed (invalid output) [[Unlock advice (1.98 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031770'))
        -   Failed (invalid output) [[Unlock advice (3.51 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031771'))
        -   Failed (invalid output) [[Unlock advice (1.25 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031772'))
        -   Failed (invalid output) [[Unlock advice (1.16 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031773'))
        -   Failed (invalid output) [[Unlock advice (4.86 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031774'))
        -   Failed (invalid output) [[Unlock advice (2.56 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031775'))
        -   Failed (invalid output) [[Unlock advice (2.59 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031776'))
    -   Test 'Random test + mem dbg': failed
        -   result: 10.00 %, required: 50.00 %
        -   Max. run time: 0.026 s (limit: 2.000 s)
        -   Total run time: 0.179 s
        -   Optional test failed, evaluation: 50.00 %
        -   Failed (invalid output) [[Unlock advice (992 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031777'))
        -   Failed (invalid output) [[Unlock advice (1.26 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031778'))
        -   Failed (invalid output) [[Unlock advice (1.00 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031779'))
        -   Failed (invalid output) [[Unlock advice (810 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031780'))
        -   Failed (invalid output) [[Unlock advice (1.13 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031781'))
        -   Failed (invalid output) [[Unlock advice (1.61 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031782'))
        -   Failed (invalid output) [[Unlock advice (1.03 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031783'))
        -   Failed (invalid output) [[Unlock advice (1.49 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031784'))
        -   Failed (invalid output) [[Unlock advice (1.79 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031785'))
    -   Test 'Speed test \#1': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.848 s (limit: 1.000 s)
        -   Total run time: 1.341 s
        -   Bonus test - success, evaluation: 110.00 %
    -   Test 'Speed test \#2': Abnormal program termination (Time limit exceeded)
        -   Program was killed after: 1.002 s (limit: 1.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
        -   Time limit exceeded [[Unlock advice (8.00 KiB, incomplete data)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031786'))
    -   Overall ratio: 13.18 % (= 1.00 \* 0.50 \* 0.96 \* 0.50 \* 0.50 \* 1.10)
-   Total percent: 13.18 %
-   Total points: 0.13 \* 3.00 = 0.40

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**1**|--|--|--|
|Lines of code:|**129**|129.00 ± 0.00|129|`main`|
|Cyclomatic complexity:|**26**|26.00 ± 0.00|26|`main`|

**2**

**2018-11-30 14:09:07**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1588&Tsk=1575&Sub=1017512)

**Submission status:**

Evaluated

 

**Evaluation:**

0.6325

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.027 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': failed
        -   result: 37.50 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.035 s
        -   Optional test failed, evaluation: 50.00 %
        -   Failed (invalid output) [[Unlock advice (276 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031743'))
        -   Failed (invalid output) [[Unlock advice (343 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031744'))
        -   Failed (invalid output) [[Unlock advice (471 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031745'))
        -   Failed (invalid output) [[Unlock advice (135 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031746'))
        -   Failed (invalid output) [[Unlock advice (116 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031747'))
    -   Test 'Invalid input test': success
        -   result: 95.83 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.094 s
        -   Optional test success, evaluation: 95.83 %
        -   Failed (invalid output) [[Unlock advice (96 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031748'))
    -   Test 'Random test': success
        -   result: 80.00 %, required: 50.00 %
        -   Max. run time: 0.039 s (limit: 2.000 s)
        -   Total run time: 0.155 s
        -   Optional test success, evaluation: 80.00 %
        -   Failed (invalid output) [[Unlock advice (1.67 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031749'))
        -   Failed (invalid output) [[Unlock advice (1.53 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031750'))
        -   Failed (invalid output) [[Unlock advice (2.34 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031751'))
        -   Failed (invalid output) [[Unlock advice (9.87 KiB, incomplete data)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031752'))
    -   Test 'Random test + mem dbg': failed
        -   result: 40.00 %, required: 50.00 %
        -   Max. run time: 0.028 s (limit: 2.000 s)
        -   Total run time: 0.221 s
        -   Optional test failed, evaluation: 50.00 %
        -   Failed (invalid output) [[Unlock advice (1.46 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031753'))
        -   Failed (invalid output) [[Unlock advice (808 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031754'))
        -   Failed (invalid output) [[Unlock advice (1.18 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031755'))
        -   Failed (invalid output) [[Unlock advice (971 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031756'))
        -   Failed (invalid output) [[Unlock advice (1.51 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031757'))
        -   Failed (invalid output) [[Unlock advice (774 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031758'))
    -   Test 'Speed test \#1': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.786 s (limit: 1.000 s)
        -   Total run time: 1.289 s
        -   Bonus test - success, evaluation: 110.00 %
    -   Test 'Speed test \#2': Abnormal program termination (Time limit exceeded)
        -   Program was killed after: 1.004 s (limit: 1.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
        -   Time limit exceeded [[Unlock advice (8.00 KiB, incomplete data)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031759'))
    -   Overall ratio: 21.08 % (= 1.00 \* 0.50 \* 0.96 \* 0.80 \* 0.50 \* 1.10)
-   Total percent: 21.08 %
-   Total points: 0.21 \* 3.00 = 0.63

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**1**|--|--|--|
|Lines of code:|**124**|124.00 ± 0.00|124|`main`|
|Cyclomatic complexity:|**25**|25.00 ± 0.00|25|`main`|

**1**

**2018-11-30 14:07:32**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1588&Tsk=1575&Sub=1017507)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': failed
        -   result: 0.00 %, required: 100.00 %
        -   Max. run time: 0.007 s (limit: 1.000 s)
        -   Total run time: 0.037 s
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (206 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031682'))
        -   Failed (invalid output) [[Unlock advice (203 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031683'))
        -   Failed (invalid output) [[Unlock advice (438 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031684'))
        -   Failed (invalid output) [[Unlock advice (115 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031685'))
        -   Failed (invalid output) [[Unlock advice (64 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031686'))
        -   Failed (invalid output) [[Unlock advice (66 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1588&Tsk=1575&Unl=L3031687'))
    -   Overall ratio: 0.00 %
-   Total percent: 0.00 %
-   Total points: 0.00 \* 3.00 = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**1**|--|--|--|
|Lines of code:|**123**|123.00 ± 0.00|123|`main`|
|Cyclomatic complexity:|**25**|25.00 ± 0.00|25|`main`|


