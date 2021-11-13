||
|[ProgTest](https://progtest.fit.cvut.cz/index.php?X=Main)  ►  [BIE-PA1 (18/19 ZS)](https://progtest.fit.cvut.cz/index.php?X=Course&Cou=251)  ►  [Homework 03](https://progtest.fit.cvut.cz/index.php?X=TaskGrp&Cou=251&Tgr=1587)  ►  **Hyperloop I**|[Logout](https://progtest.fit.cvut.cz/index.php?X=Logout)|

||
|**Hyperloop I**|

**Submission deadline:**

**2018-11-25 23:59:59**

 

**Late submission with malus:**

**2019-01-06 23:59:59** (Late submission malus: 100.0000 %)

**Evaluation:**

**3.0000**

**Max. assessment:**

**3.0000** (Without bonus points)

**Submissions:**

11 / 20 Free retries + 10 Penalized retries (-10 % penalty each retry)

**Advices:**

0 / 2 Advices for free + 2 Advices with a penalty (-10 % penalty each advice)

The task is to implement a function (not a whole program, just a function) that plans hyperloop tracks. The function will be given the lengths of the available track segments and the length of the desired track. Based on these parameters, the function computes whether the track can be constructed, or not.

The hyperloop track is composed of individual segments of certain lengths. We assume there are two manufacturers, each of them produces segments of one fixed length. Each pair of adjacent segments must be connected by exactly one bulkhead; the whole track must start and end with a bulkhead. All bulkheads have the same length. The segments and bulkheads must be used in their original length, i.e., they cannot be cut or extended. The function is given the lengths of the segments, bulkheads, and the length of the track. Based on the parameters, the function decides whether there is a valid combination of segments and bulkheads that gives the exact length of the desired track. If the track can be constructed, the function counts how many different variants there exists.

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
                                                                 unsigned int bulkhead, 
                                                                 unsigned int * c1, 
                                                                 unsigned int * c2 );

`len`  
an input parameter - the length of the track being constructed,

**`s1, s2`**  
input parameters - the lengths of the segments produced by the first/second manufacturer. Either one or both parameter may be zero, meaning the segments from the respective manufacturer are unavailable and cannot be used (i.e., only the segments from the other manufacturer may be used),

**`bulkhead`**  
an input parameter - the length of the bulkhead. The parameter may be zero, meaning the bulkheads do not add to the overall length of the track,

**`c1, c2`**  
output parameters - the required number of segments from the first/second manufacturer. The function sets the parameters to any valid combination of segments that forms a valid solution. If the function cannot find any solution, it must not modify the parameters,

**return value**  
is either zero or the number of different solutions found. If the function does not succeed (i.e., no valid combination of segments and bulkheads results in the desired track length), the return value must be 0. Otherwise, if some solutions do exist, the function returns the number of different solutions that lead to the desired track length. The output parameters `c1` and `c2` must be set to some valid solution.

Two solutions are considered identical if the required number of segments is the same for each segment length. Conversely, two solutions are considered different if they differ in the number of segments in at least one length. In other words:

-   the order of segments in the track is irrelevant. For example:

               len = 20
               s1 = 5
               s2 = 10
               bulkhead = 0
             

    provides combinations:

               [bulkhead] [segment 5] [bulkhead] [segment 5] [bulkhead] [segment 5] [bulkhead] [segment 5] [bulkhead]
               
               [bulkhead] [segment 5] [bulkhead] [segment 5] [bulkhead] [segment 10] [bulkhead]
               [bulkhead] [segment 5] [bulkhead] [segment 10] [bulkhead] [segment 5] [bulkhead]
               [bulkhead] [segment 10] [bulkhead] [segment 5] [bulkhead] [segment 5] [bulkhead]
               
               [bulkhead] [segment 10] [bulkhead] [segment 10] [bulkhead]
             

    Of those, the middle three combinations are equivalent, all three require two segments of length 5 and one segment of length 10. Thus, the return value is 3 for this input:

               4 * s1 + 0 * s2 + 5 * bulkhead = 20
               2 * s1 + 1 * s2 + 4 * bulkhead = 20
               0 * s1 + 2 * s2 + 3 * bulkhead = 20
               
               hyperloop ( 20, 5, 10, 0, &c1, &c2 ) == 3
             

-   if both manufacturers produce segments of the same length, then the segments are indistinguishable. For example:

               len = 40
               s1 = 10
               s2 = 10
               bulkhead = 0
             

    may result in five combinations:

               4 * s1 + 0 * s2 + 5 * bulkhead = 40
               3 * s1 + 1 * s2 + 5 * bulkhead = 40
               2 * s1 + 2 * s2 + 5 * bulkhead = 40
               1 * s1 + 3 * s2 + 5 * bulkhead = 40
               0 * s1 + 4 * s2 + 5 * bulkhead = 40
             

    However, these 5 combinations are considered equivalent, all of them require 4 segments of length 10:

               hyperloop ( 40, 10, 10, 0, &c1, &c2 ) == 1
             

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

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskS&Cou=251&Tgr=1587&Tsk=1573)

 **Reference**

 

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 100.00 %, required: 25.00 %
        -   Total run time: 0.000 s (limit: 2.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test': success
        -   result: 100.00 %, required: 25.00 %
        -   Total run time: 0.001 s (limit: 2.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Bonus test (speed)': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.001 s (limit: 2.000 s)
        -   Bonus test - success, evaluation: 125.00 %
    -   Overall ratio: 125.00 % (= 1.00 \* 1.00 \* 1.00 \* 1.25)
-   Total percent: 125.00 %
-   Early submission bonus: 0.30
-   Total points: 1.25 \* ( 3.00 + 0.30 ) = 4.12

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**3**|--|--|--|
|Lines of code:|**80**|26.67 ± 7.41|35|`hyperloop`|
|Cyclomatic complexity:|**16**|5.33 ± 2.62|9|`hyperloop`|

**11**

**2018-11-24 21:18:10**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1587&Tsk=1573&Sub=1011613)

**Submission status:**

Evaluated

 

**Evaluation:**

3.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 100.00 %, required: 25.00 %
        -   Total run time: 0.012 s (limit: 2.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test': success
        -   result: 100.00 %, required: 25.00 %
        -   Total run time: 0.007 s (limit: 1.988 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Bonus test (speed)': Abnormal program termination (Time limit exceeded)
        -   Cumulative test time exceeded, killed after:: 2.003 s (limit: 2.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 100.00 % (= 1.00 \* 1.00 \* 1.00)
-   Total percent: 100.00 %
-   Total points: 1.00 \* 3.00 = 3.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**2**|--|--|--|
|Lines of code:|**88**|44.00 ± 21.00|65|`hyperloop`|
|Cyclomatic complexity:|**31**|15.50 ± 4.50|20|`hyperloop`|

**10**

**2018-11-24 20:51:52**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1587&Tsk=1573&Sub=1011584)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': failed
        -   result: 87.50 %, required: 100.00 %
        -   Total run time: 0.001 s (limit: 1.000 s)
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (51 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1573&Unl=L3009915'))
    -   Overall ratio: 0.00 %
-   Total percent: 0.00 %
-   Total points: 0.00 \* 3.00 = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**2**|--|--|--|
|Lines of code:|**88**|44.00 ± 21.00|65|`hyperloop`|
|Cyclomatic complexity:|**31**|15.50 ± 4.50|20|`hyperloop`|

**9**

**2018-11-24 20:30:19**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1587&Tsk=1573&Sub=1011560)

**Submission status:**

Evaluated

 

**Evaluation:**

0.1875

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.001 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': Abnormal program termination (Segmentation fault/Bus error/Memory limit exceeded/Stack limit exceeded)
        -   Total run time: 0.005 s (limit: 2.000 s)
        -   Optional test failed, evaluation: 25.00 %
    -   Test 'Random test': Not tested
        -   Optional test failed, evaluation: 25.00 %
    -   Test 'Bonus test (speed)': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 6.25 % (= 1.00 \* 0.25 \* 0.25)
-   Total percent: 6.25 %
-   Total points: 0.06 \* 3.00 = 0.19

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**2**|--|--|--|
|Lines of code:|**88**|44.00 ± 21.00|65|`hyperloop`|
|Cyclomatic complexity:|**32**|16.00 ± 5.00|21|`hyperloop`|

**8**

**2018-11-24 20:10:32**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1587&Tsk=1573&Sub=1011547)

**Submission status:**

Evaluated

 

**Evaluation:**

0.1875

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 1.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': Abnormal program termination (Segmentation fault/Bus error/Memory limit exceeded/Stack limit exceeded)
        -   Total run time: 0.005 s (limit: 2.000 s)
        -   Optional test failed, evaluation: 25.00 %
    -   Test 'Random test': Not tested
        -   Optional test failed, evaluation: 25.00 %
    -   Test 'Bonus test (speed)': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 6.25 % (= 1.00 \* 0.25 \* 0.25)
-   Total percent: 6.25 %
-   Total points: 0.06 \* 3.00 = 0.19

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**2**|--|--|--|
|Lines of code:|**88**|44.00 ± 21.00|65|`hyperloop`|
|Cyclomatic complexity:|**30**|15.00 ± 4.00|19|`hyperloop`|

**7**

**2018-11-24 19:50:44**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1587&Tsk=1573&Sub=1011525)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': failed
        -   result: 62.50 %, required: 100.00 %
        -   Total run time: 0.001 s (limit: 1.000 s)
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (50 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1573&Unl=L3009666'))
        -   Failed (invalid output) [[Unlock advice (59 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1573&Unl=L3009667'))
        -   Failed (invalid output) [[Unlock advice (50 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1573&Unl=L3009668'))
    -   Overall ratio: 0.00 %
-   Total percent: 0.00 %
-   Total points: 0.00 \* 3.00 = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**2**|--|--|--|
|Lines of code:|**82**|41.00 ± 18.00|59|`hyperloop`|
|Cyclomatic complexity:|**29**|14.50 ± 3.50|18|`hyperloop`|

**6**

**2018-11-21 23:40:19**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1587&Tsk=1573&Sub=1004884)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Compile in 'basic' mode failed. [[Unlock advice (1797 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1573&Unl=C1014470'))
-   Total percent: 0.00 %
-   Total points: 0.00 \* 3.00 = 0.00

**5**

**2018-11-21 22:24:23**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1587&Tsk=1573&Sub=1004847)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Compile in 'pedantic' mode failed (10 % penalty). [[Unlock advice (459 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1573&Unl=C1014433'))
    -   Test 'Basic test with sample input data': failed
        -   result: 25.00 %, required: 100.00 %
        -   Total run time: 0.002 s (limit: 1.000 s)
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (49 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1573&Unl=L2998540'))
        -   Failed (invalid output) [[Unlock advice (55 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1573&Unl=L2998541'))
        -   Failed (invalid output) [[Unlock advice (64 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1573&Unl=L2998542'))
        -   Failed (invalid output) [[Unlock advice (52 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1573&Unl=L2998543'))
        -   Failed (invalid output) [[Unlock advice (51 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1573&Unl=L2998544'))
        -   Failed (invalid output) [[Unlock advice (51 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1573&Unl=L2998545'))
    -   Overall ratio: 0.00 %
-   Total percent: 0.00 %
-   Total points: 0.00 \* 3.00 = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**2**|--|--|--|
|Lines of code:|**108**|54.00 ± 31.00|85|`hyperloop`|
|Cyclomatic complexity:|**34**|17.00 ± 6.00|23|`hyperloop`|

**4**

**2018-11-21 22:05:49**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1587&Tsk=1573&Sub=1004836)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Compile in 'basic' mode failed. [[Unlock advice (783 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1573&Unl=C1014422'))
-   Total percent: 0.00 %
-   Total points: 0.00 \* 3.00 = 0.00

**3**

**2018-11-21 20:04:19**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1587&Tsk=1573&Sub=1004722)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Compile in 'pedantic' mode failed (10 % penalty). [[Unlock advice (459 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1573&Unl=C1014308'))
    -   Test 'Basic test with sample input data': failed
        -   result: 37.50 %, required: 100.00 %
        -   Total run time: 0.001 s (limit: 1.000 s)
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (49 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1573&Unl=L2998173'))
        -   Failed (invalid output) [[Unlock advice (102 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1573&Unl=L2998174'))
        -   Failed (invalid output) [[Unlock advice (50 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1573&Unl=L2998175'))
        -   Failed (invalid output) [[Unlock advice (51 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1573&Unl=L2998176'))
        -   Failed (invalid output) [[Unlock advice (51 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1573&Unl=L2998177'))
    -   Overall ratio: 0.00 %
-   Total percent: 0.00 %
-   Total points: 0.00 \* 3.00 = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**2**|--|--|--|
|Lines of code:|**94**|47.00 ± 24.00|71|`hyperloop`|
|Cyclomatic complexity:|**32**|16.00 ± 5.00|21|`hyperloop`|

**2**

**2018-11-21 19:51:00**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1587&Tsk=1573&Sub=1004707)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Compile in 'pedantic' mode failed (10 % penalty). [[Unlock advice (459 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1573&Unl=C1014293'))
    -   Test 'Basic test with sample input data': failed
        -   result: 37.50 %, required: 100.00 %
        -   Total run time: 0.002 s (limit: 1.000 s)
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (49 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1573&Unl=L2998120'))
        -   Failed (invalid output) [[Unlock advice (55 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1573&Unl=L2998121'))
        -   Failed (invalid output) [[Unlock advice (50 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1573&Unl=L2998122'))
        -   Failed (invalid output) [[Unlock advice (51 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1573&Unl=L2998123'))
        -   Failed (invalid output) [[Unlock advice (51 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1573&Unl=L2998124'))
    -   Overall ratio: 0.00 %
-   Total percent: 0.00 %
-   Total points: 0.00 \* 3.00 = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**2**|--|--|--|
|Lines of code:|**94**|47.00 ± 24.00|71|`hyperloop`|
|Cyclomatic complexity:|**32**|16.00 ± 5.00|21|`hyperloop`|

**1**

**2018-11-21 19:28:05**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1587&Tsk=1573&Sub=1004688)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Compile in 'pedantic' mode failed (10 % penalty). [[Unlock advice (459 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1573&Unl=C1014274'))
    -   Test 'Basic test with sample input data': failed
        -   result: 37.50 %, required: 100.00 %
        -   Total run time: 0.001 s (limit: 1.000 s)
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (49 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1573&Unl=L2998074'))
        -   Failed (invalid output) [[Unlock advice (102 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1573&Unl=L2998075'))
        -   Failed (invalid output) [[Unlock advice (50 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1573&Unl=L2998076'))
        -   Failed (invalid output) [[Unlock advice (51 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1573&Unl=L2998077'))
        -   Failed (invalid output) [[Unlock advice (51 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1587&Tsk=1573&Unl=L2998078'))
    -   Overall ratio: 0.00 %
-   Total percent: 0.00 %
-   Total points: 0.00 \* 3.00 = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**2**|--|--|--|
|Lines of code:|**94**|47.00 ± 24.00|71|`hyperloop`|
|Cyclomatic complexity:|**32**|16.00 ± 5.00|21|`hyperloop`|


