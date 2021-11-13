||
|[ProgTest](https://progtest.fit.cvut.cz/index.php?X=Main)  ►  [BIE-PA1 (18/19 ZS)](https://progtest.fit.cvut.cz/index.php?X=Course&Cou=251)  ►  [Homework 03](https://progtest.fit.cvut.cz/index.php?X=TaskGrp&Cou=251&Tgr=1587)  ►  **Hyperloop II**|[Logout](https://progtest.fit.cvut.cz/index.php?X=Logout)|

||
|**Hyperloop II**|

**Submission deadline:**

**2018-11-25 23:59:59**

 

**Late submission with malus:**

**2019-01-06 23:59:59** (Late submission malus: 100.0000 %)

**Evaluation:**

**5.0000**

**Max. assessment:**

**5.0000** (Without bonus points)

**Submissions:**

4 / 20 Free retries + 10 Penalized retries (-10 % penalty each retry)

**Advices:**

1 / 2 Advices for free + 2 Advices with a penalty (-10 % penalty each advice)

The task is to implement a function (not a whole program, just a function) that plans hyperloop tracks. The function will be given the lengths of the available track segments and the length of the desired track. Based on these parameters, the function computes whether the track can be constructed, or not. This problem is an extension of the simple variant. Up to three segments are combined in this version.

The hyperloop track is composed of individual segments of certain lengths. We assume there are three manufacturers, each of them produces segments of one fixed length. Each pair of adjacent segments must be connected by exactly one bulkhead; the whole track must start and end with a bulkhead. All bulkheads have the same length. The segments and bulkheads must be used in their original length, i.e., they cannot be cut or extended. The function is given the lengths of the segments, bulkheads, and the length of the track. Based on the parameters, the function decides whether there is a valid combination of segments and bulkheads that gives the exact length of the desired track. If the track can be constructed, the function counts how many different variants are available.

Valid combinations of bulkheads and segments are:

    bulkhead
    bulkhead segment bulkhead
    bulkhead segment bulkhead segment bulkhead
    bulkhead segment bulkhead segment bulkhead segment bulkhead
    bulkhead segment bulkhead segment bulkhead segment bulkhead segment bulkhead
    ...

The required interface is:

    unsigned long long int  hyperloop                          ( unsigned long long int len, 
                                                                 unsigned int s1, 
                                                                 unsigned int s2, 
                                                                 unsigned int s3, 
                                                                 unsigned int bulkhead, 
                                                                 unsigned int * c1, 
                                                                 unsigned int * c2, 
                                                                 unsigned int * c3 );

**`len`**  
an input parameter - the length of the track being constructed,

**`s1, s2, s3`**  
input parameters - the lengths of the segments produced by the first/second/third manufacturer. The parameter may be zero, meaning the segments from the respective producer(s) are unavailable and cannot be used (i.e., only the segments from the other manufacturers),

**`bulkhead`**  
an input parameter - the length of the bulkhead. The parameter may be zero, meaning the bulkheads do not add to the overall length of the track,

**`c1, c2, c3`**  
output parameters - the required number of segments from the first/second/third manufacturer. If the function cannot find the solution, it shall not modify this parameter,

**return value**  
is either zero or the number of different solutions found. If the function does not succeed (i.e., no valid combination of segments and bulkheads results in the desired track length), the return value must be 0. Otherwise, if some solutions do exist, the function returns the number of different solutions that lead to the desired track length. The output parameters `c1`, `c2`, and `c3` must be set to some valid solution.

Two solutions are considered identical if the required number of segments is the same for each segment length. Conversely, two solutions are considered different if they differ in the number of segments in at least one length. In other words:

-   the order of segments in the track is irrelevant. For example:

              len = 27
              s1 = 3
              s2 = 9
              s3 = 1
              bulkhead = 5
             

    gives the following 5 combinations:

               [bulkhead] [segment 3] [bulkhead] [segment 3] [bulkhead] [segment 1] [bulkhead]
               [bulkhead] [segment 3] [bulkhead] [segment 1] [bulkhead] [segment 3] [bulkhead]
               [bulkhead] [segment 1] [bulkhead] [segment 3] [bulkhead] [segment 3] [bulkhead]
               
               [bulkhead] [segment 3] [bulkhead] [segment 9] [bulkhead]
               [bulkhead] [segment 9] [bulkhead] [segment 3] [bulkhead]
             

    Of the above combinations, the first three are equivalent (three segments of length 3, zero segments of length 9, and one segment of length 1) and the last two combinations are equivalent (one segment of length 3, one segment of length 9, and zero segments of length 1):

               2 * s1 + 0 * s2 + 1 * s3 + 4 * bulkhead = 27
               1 * s1 + 1 * s2 + 0 * s3 + 3 * bulkhead = 27

               hyperloop ( 27, 3, 9, 1, 5, &c1, &c2, &c3 ) == 2
             

-   if two (or all three) manufacturers produce segments of the same length, then the segments are indistinguishable. For example:

               len = 40
               s1 = 10
               s2 = 10
               s3 = 20
               bulkhead = 0
             

    There is a total of 9 possible combinations:

               4 * s1 + 0 * s2 + 0 * s3 + 5 * bulkhead = 40
               3 * s1 + 1 * s2 + 0 * s3 + 5 * bulkhead = 40
               2 * s1 + 2 * s2 + 0 * s3 + 5 * bulkhead = 40
               1 * s1 + 3 * s2 + 0 * s3 + 5 * bulkhead = 40
               0 * s1 + 4 * s2 + 0 * s3 + 5 * bulkhead = 40
               
               2 * s+ + 0 * s2 + 1 * s3 + 4 * bulkhead = 40
               1 * s+ + 1 * s2 + 1 * s3 + 4 * bulkhead = 40
               0 * s+ + 2 * s2 + 1 * s3 + 4 * bulkhead = 40
               
               0 * s+ + 0 * s2 + 2 * s3 + 3 * bulkhead = 40
             

    Of them, only three are considered different. The first solution requires four segments of length 10 and zero segments of length 20. The second solution requires two segments of length 10 and one segment of length 20. Finally, the third solution requires zero segments of length 10 and two segments of length 20:

              hyperloop ( 40, 10, 10, 20, 0, &c1, &c2, &c3 ) == 3
             

Submit a source file with the implementation of `hyperloop`. Further, the source file must include your auxiliary functions which are called from the required function. The `hyperloop` function will be called from the testing environment, thus, it is important to adhere to the required interface. Use the attached sample code as a basis for your development, complete the required function and add your required auxiliary functions. There is an example `main` with some test in the attached code. These values will be used in the basic test. Please note the header files as well as `main` is nested in a conditional compile block (`#ifdef/#endif`). Please keep these conditional compile block in place. They are present to simplify the development. When compiling on your computer, the headers and `main` will be present as usual. On the other hand, the header and `main` will "disappear" when compiled by Progtest. Thus, your testing `main` will not interfere with the testing environment's `main`.

Your function will be executed in a limited environment. There are limits on both time and memory. The exact limits are shown in the test log of the reference. A reasonable implementation of the naive algorithm shall pass both limits without any problems. There is a bonus test, the bonus test requires an efficient algorithm to pass the time limit.

**Advice:**

-   Download the attached sample code and use it as a base for your development.
-   The `main` function in your program may be modified (e.g. new tests may be included). The conditional compile block must remain, however.
-   There is `assert` macro used in the example `main` function. If the value passed to `assert` is nonzero (true), the macro does nothing. On the other hand, if the parameter is zero, the macro stops the execution and reports line, where the test did not match (and shall be fixed). Thus, the program ends silently when your implementation passes the tests correctly.
-   The total track length and the resulting number of different solutions may exceed the range of the `int` data type. Therefore, the interface uses `unsigned long long int` data type instead. Functions `printf` and `scanf` use `%llu` conversion to display/read values of this data type.
-   Do not try to generate all possible permutations and subsequently de-duplicate them. Generate only the unique solutions. Arrays are not required to solve the problem. Indeed, the array would add unnecessary complexity (it would have to be dynamically allocated) and the de-duplication would be too time expensive.
-   The `unsigned long long int` data type is an extension of the C90/C++03 standard; the data type is included in the newer standards. If the compiler uses the old standard, it displays warnings. Progtest compiler is configured to suppress this warning, the compilation includes `-Wno-long-long` flag.

**Sample data:**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskS&Cou=251&Tgr=1587&Tsk=1574)

 **Reference**

 

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 100.00 %, required: 25.00 %
        -   Total run time: 0.001 s (limit: 2.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test': success
        -   result: 100.00 %, required: 25.00 %
        -   Total run time: 0.005 s (limit: 1.999 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Bonus test (speed)': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.197 s (limit: 2.000 s)
        -   Bonus test - success, evaluation: 130.00 %
    -   Overall ratio: 130.00 % (= 1.00 \* 1.00 \* 1.00 \* 1.30)
-   Total percent: 130.00 %
-   Early submission bonus: 0.50
-   Total points: 1.30 \* ( 5.00 + 0.50 ) = 7.15

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**5**|--|--|--|
|Lines of code:|**149**|29.80 ± 7.19|41|`hyperloop3`|
|Cyclomatic complexity:|**32**|6.40 ± 2.42|9|`hyperloop3`|

**4**

**2018-11-25 22:57:22**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1587&Tsk=1574&Sub=1013317)

**Submission status:**

Evaluated

 

**Evaluation:**

5.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.040 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 100.00 %, required: 25.00 %
        -   Total run time: 0.087 s (limit: 2.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test': success
        -   result: 100.00 %, required: 25.00 %
        -   Total run time: 0.237 s (limit: 1.913 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Bonus test (speed)': Abnormal program termination (Time limit exceeded)
        -   Cumulative test time exceeded, killed after:: 2.003 s (limit: 2.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 100.00 % (= 1.00 \* 1.00 \* 1.00)
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 100.00 %
-   Total points: 1.00 \* 5.00 = 5.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**2**|--|--|--|
|Lines of code:|**265**|132.50 ± 98.50|231|`hyperloop`|
|Cyclomatic complexity:|**69**|34.50 ± 18.50|53|`hyperloop`|

**3**

**2018-11-25 22:46:04**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1587&Tsk=1574&Sub=1013283)

**Submission status:**

Evaluated

 

**Evaluation:**

4.3939

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.037 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 87.88 %, required: 25.00 %
        -   Total run time: 0.105 s (limit: 2.000 s)
        -   Optional test success, evaluation: 87.88 %
        -   Failed (invalid output) [[Unlock advice (65 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1574&Unl=L3017322'))
        -   Failed (invalid output) [[Unlock advice (65 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1574&Unl=L3017323'))
        -   Failed (invalid output) [[Unlock advice (65 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1574&Unl=L3017324'))
        -   Failed (invalid output) [[Unlock advice (67 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1574&Unl=L3017325'))
    -   Test 'Random test': success
        -   result: 100.00 %, required: 25.00 %
        -   Total run time: 0.552 s (limit: 1.895 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Bonus test (speed)': Abnormal program termination (Time limit exceeded)
        -   Cumulative test time exceeded, killed after:: 2.002 s (limit: 2.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 87.88 % (= 1.00 \* 0.88 \* 1.00)
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 87.88 %
-   Total points: 0.88 \* 5.00 = 4.39

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**2**|--|--|--|
|Lines of code:|**280**|140.00 ± 106.00|246|`hyperloop`|
|Cyclomatic complexity:|**72**|36.00 ± 20.00|56|`hyperloop`|

**2**

**2018-11-25 22:28:58**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1587&Tsk=1574&Sub=1013216)

**Submission status:**

Evaluated

 

**Evaluation:**

4.9500

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.028 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 100.00 %, required: 25.00 %
        -   Total run time: 0.157 s (limit: 2.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test': success
        -   result: 99.00 %, required: 25.00 %
        -   Total run time: 0.237 s (limit: 1.843 s)
        -   Optional test success, evaluation: 99.00 %
        -    Failed (invalid output)

                 hyperloop ( 88161, 41, 20, 41, 8, &c1, &c2, &c3 ) => r=0, s=0, c1=194, c2=182, c3=0, c1/c2/c3 modified

    -   Test 'Bonus test (speed)': Abnormal program termination (Time limit exceeded)
        -   Cumulative test time exceeded, killed after:: 2.002 s (limit: 2.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 99.00 % (= 1.00 \* 1.00 \* 0.99)
-   Total percent: 99.00 %
-   Total points: 0.99 \* 5.00 = 4.95

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**2**|--|--|--|
|Lines of code:|**265**|132.50 ± 98.50|231|`hyperloop`|
|Cyclomatic complexity:|**69**|34.50 ± 18.50|53|`hyperloop`|

**1**

**2018-11-25 21:40:32**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1587&Tsk=1574&Sub=1013076)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': failed
        -   result: 37.50 %, required: 100.00 %
        -   Total run time: 0.070 s (limit: 1.000 s)
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (59 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1574&Unl=L3016673'))
        -   Failed (invalid output) [[Unlock advice (69 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1574&Unl=L3016674'))
        -   Failed (invalid output) [[Unlock advice (59 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1574&Unl=L3016675'))
        -   Failed (invalid output) [[Unlock advice (60 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1574&Unl=L3016676'))
        -   Failed (invalid output) [[Unlock advice (61 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1574&Unl=L3016677'))
    -   Overall ratio: 0.00 %
-   Total percent: 0.00 %
-   Total points: 0.00 \* 5.00 = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**2**|--|--|--|
|Lines of code:|**225**|112.50 ± 78.50|191|`hyperloop`|
|Cyclomatic complexity:|**59**|29.50 ± 13.50|43|`hyperloop`|


