||
|[ProgTest](https://progtest.fit.cvut.cz/index.php?X=Main)  ►  [BIE-PA1 (18/19 ZS)](https://progtest.fit.cvut.cz/index.php?X=Course&Cou=251)  ►  [Homework 01](https://progtest.fit.cvut.cz/index.php?X=TaskGrp&Cou=251&Tgr=1585)  ►  **Triangles \#1**|[Logout](https://progtest.fit.cvut.cz/index.php?X=Logout)|

||
|**Triangles \#1**|

**Submission deadline:**

**2018-11-11 23:59:59**

 

**Late submission with malus:**

**2019-01-06 23:59:59** (Late submission malus: 100.0000 %)

**Evaluation:**

**3.3000**

**Max. assessment:**

**3.0000** (Without bonus points)

**Submissions:**

19 / 20 Free retries + 10 Penalized retries (-10 % penalty each retry)

**Advices:**

1 / 2 Advices for free + 2 Advices with a penalty (-10 % penalty each advice)

The task is to develop a program that compares two given triangles in a 2D plane.

There are given two triangles in a 2D plane. Each triangle is defined by three vertices (i.e., there is a total of 6 vertices in the input). The vertices are described by their coordinates (pairs of decimal numbers). Your program reads the coordinates from the standard input. Next, the program decides one of the 4 cases:

-   the input vertices do not form a triangle (the three vertices defining the triangle are on a common line),
-   the triangles are identical,
-   the triangles are not identical while their circumference is the same, or
-   the triangles are entirely different.

The program must validate input data. If the input is invalid, the program must detect it, it shall output an error message (see below), and terminate. If displayed, the error message must be sent to the standard output (do not send it to the error output) and the error message must be terminated by a newline (\\n). The input is considered invalid, if:

-   the coordinates are invalid (are not valid decimals),
-   some coordinate(s) are missing.

**Sample program runs:**

* * * * *

    Triangle #1:
    Vertex A:
    0 0
    Vertex B:
    5 0
    Vertex C:
    2.5 3
    Triangle #2:
    Vertex A:
    4 -1
    Vertex B:
    7 1.5
    Vertex C:
    4 4
    The triangles are identical.

* * * * *

    Triangle #1:
    Vertex A:
    0


       15
    Vertex B:
    112 0 112 15
    Vertex C:
    Triangle #2:
    Vertex A:
    0 0
    Vertex B:
    96 0
    Vertex C:
    0 40
    The triangles are not identical, however, they have the same circumference.

* * * * *

    Triangle #1:
    Vertex A:
    0 0
    Vertex B:
    10 0
    Vertex C:
    0 10
    Triangle #2:
    Vertex A:
    -5 3
    Vertex B:
    12 8
    Vertex C:
    37 15
    Triangle #2 has a longer circumference.

* * * * *

    Triangle #1:
    Vertex A:
    0 14.04
    Vertex B:
    11.2 0
    Vertex C:
    0 0
    Triangle #2:
    Vertex A:
    20.16 0
    Vertex B:
    0 2.7
    Vertex C:
    20.16 2.7
    The triangles are not identical, however, they have the same circumference.

* * * * *

    Triangle #1:
    Vertex A:
    0 0
    Vertex B:
    10 0
    Vertex C:
    0 10
    Triangle #2:
    Vertex A:
    0 0
    Vertex B:
    10 10
    Vertex C:
    15 15
    The points do not form a triangle.

* * * * *

    Triangle #1:
    Vertex A:
    10 0
    Vertex B:
    20 1
    Vertex C:
    25 1.5
    The points do not form a triangle.

* * * * *

    Triangle #1:
    Vertex A:
    0 0
    Vertex B:
    999.990 204.330
    Vertex C:
    899.991 183.897
    The points do not form a triangle.

* * * * *

    Triangle #1:
    Vertex A:
    1 2
    Vertex B:
    3 abcd
    Invalid input.

* * * * *

**Advice:**

-   The sample runs above list both the output of your program (boldface font) and user input (regular font). The bold/regular formatting is included here, in the problem statement page, to increase readability of the listing. Your program must output the text without any additional markup.
-   Do not forget the newline (\\n) after the last output line.
-   Use `double` data type to represent the values. Do not use `float`, the precision of `float` is not always sufficient.
-   The program can be developed without additional functions (i.e., in one big `main`). However, if divided into functions, the program is readable and easier to debug.
-   All numeric values in the input fit into the range of `double` data type. The reference uses `double` and `int` data types to represent numbers.
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

            input      ::= { whiteSpace } coord { whiteSpace } coord { whiteSpace } coord { whiteSpace } 
                              coord { whiteSpace } coord { whiteSpace } coord { whiteSpace } 
            whiteSpace ::= ' ' | '\t' | '\n' | '\r'
            coord      ::= decimal { whiteSpace } decimal 
            decimal    ::= [ '+' | '-' ] integer [ '.' integer [ ( 'e' | 'E' ) [ '+' | '-' ] integer ] ]  |
                           [ '+' | '-'  ] '.' integer [ ( 'e' | 'E' ) [ '+' | '-' ] integer ]
            integer    ::= digit { digit }
            digit      ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
           

**Sample data:**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskS&Cou=251&Tgr=1585&Tsk=1566)

 **Reference**

 

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Základní test s parametry podle ukázky': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.039 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Test mezních hodnot': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.117 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Test ošetření nesprávných vstupů': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.105 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Test náhodnými daty': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.042 s
        -   Optional test success, evaluation: 100.00 %
    -   Overall ratio: 100.00 % (= 1.00 \* 1.00 \* 1.00 \* 1.00)
-   Total percent: 100.00 %
-   Early submission bonus: 0.30
-   Total points: 1.00 \* ( 3.00 + 0.30 ) = 3.30

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**7**|--|--|--|
|Lines of code:|**114**|16.29 ± 14.69|48|`readShape`|
|Cyclomatic complexity:|**26**|3.71 ± 3.49|9|`readShape`|

**19**

**2018-11-02 13:57:46**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1585&Tsk=1566&Sub=976155)

**Submission status:**

Evaluated

 

**Evaluation:**

3.3000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.041 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.109 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Invalid input test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.008 s (limit: 1.000 s)
        -   Total run time: 0.139 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.054 s
        -   Optional test success, evaluation: 100.00 %
    -   Overall ratio: 100.00 % (= 1.00 \* 1.00 \* 1.00 \* 1.00)
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 100.00 %
-   Early submission bonus: 0.30
-   Total points: 1.00 \* ( 3.00 + 0.30 ) = 3.30

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**2**|--|--|--|
|Lines of code:|**144**|72.00 ± 66.00|138|`main`|
|Cyclomatic complexity:|**27**|13.50 ± 11.50|25|`main`|

**18**

**2018-11-02 01:24:47**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1585&Tsk=1566&Sub=975776)

**Submission status:**

Evaluated

 

**Evaluation:**

1.3062

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.036 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 79.17 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.090 s
        -   Optional test success, evaluation: 79.17 %
        -   Failed (invalid output) [[Unlock advice (340 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816767'))
        -   Failed (invalid output) [[Unlock advice (436 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816768'))
        -   Failed (invalid output) [[Unlock advice (436 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816769'))
        -   Failed (invalid output) [[Unlock advice (437 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816770'))
        -   Failed (invalid output) [[Unlock advice (432 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816771'))
    -   Test 'Invalid input test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.103 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test': failed
        -   result: 10.00 %, required: 50.00 %
        -   Max. run time: 0.004 s (limit: 1.000 s)
        -   Total run time: 0.036 s
        -   Optional test failed, evaluation: 50.00 %
        -   Failed (invalid output) [[Unlock advice (387 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816772'))
        -   Failed (invalid output) [[Unlock advice (387 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816773'))
        -   Failed (invalid output) [[Unlock advice (386 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816774'))
        -   Failed (invalid output) [[Unlock advice (384 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816775'))
        -   Failed (invalid output) [[Unlock advice (390 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816776'))
        -   Failed (invalid output) [[Unlock advice (389 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816777'))
        -   Failed (invalid output) [[Unlock advice (387 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816778'))
        -   Failed (invalid output) [[Unlock advice (387 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816779'))
        -   Failed (invalid output) [[Unlock advice (391 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816780'))
    -   Overall ratio: 39.59 % (= 1.00 \* 0.79 \* 1.00 \* 0.50)
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 39.59 %
-   Early submission bonus: 0.30
-   Total points: 0.40 \* ( 3.00 + 0.30 ) = 1.31

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**1**|--|--|--|
|Lines of code:|**153**|153.00 ± 0.00|153|`main`|
|Cyclomatic complexity:|**37**|37.00 ± 0.00|37|`main`|

**17**

**2018-11-02 00:53:18**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1585&Tsk=1566&Sub=975757)

**Submission status:**

Evaluated

 

**Evaluation:**

1.4438

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.043 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 87.50 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.110 s
        -   Optional test success, evaluation: 87.50 %
        -   Failed (invalid output) [[Unlock advice (434 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816632'))
        -   Failed (invalid output) [[Unlock advice (434 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816633'))
        -   Failed (invalid output) [[Unlock advice (433 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816634'))
    -   Test 'Invalid input test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.106 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test': failed
        -   result: 20.00 %, required: 50.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.049 s
        -   Optional test failed, evaluation: 50.00 %
        -   Failed (invalid output) [[Unlock advice (382 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816635'))
        -   Failed (invalid output) [[Unlock advice (393 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816636'))
        -   Failed (invalid output) [[Unlock advice (385 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816637'))
        -   Failed (invalid output) [[Unlock advice (388 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816638'))
        -   Failed (invalid output) [[Unlock advice (387 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816639'))
        -   Failed (invalid output) [[Unlock advice (384 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816640'))
        -   Failed (invalid output) [[Unlock advice (388 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816641'))
        -   Failed (invalid output) [[Unlock advice (387 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816642'))
    -   Overall ratio: 43.75 % (= 1.00 \* 0.88 \* 1.00 \* 0.50)
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 43.75 %
-   Early submission bonus: 0.30
-   Total points: 0.44 \* ( 3.00 + 0.30 ) = 1.44

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**1**|--|--|--|
|Lines of code:|**171**|171.00 ± 0.00|171|`main`|
|Cyclomatic complexity:|**45**|45.00 ± 0.00|45|`main`|

**16**

**2018-11-01 23:34:08**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1585&Tsk=1566&Sub=975656)

**Submission status:**

Evaluated

 

**Evaluation:**

1.3750

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.041 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 83.33 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.109 s
        -   Optional test success, evaluation: 83.33 %
        -   Failed (invalid output) [[Unlock advice (435 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816015'))
        -   Failed (invalid output) [[Unlock advice (437 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816016'))
        -   Failed (invalid output) [[Unlock advice (437 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816017'))
        -   Failed (invalid output) [[Unlock advice (436 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816018'))
    -   Test 'Invalid input test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.117 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test': failed
        -   result: 30.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.045 s
        -   Optional test failed, evaluation: 50.00 %
        -   Failed (invalid output) [[Unlock advice (388 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816019'))
        -   Failed (invalid output) [[Unlock advice (387 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816020'))
        -   Failed (invalid output) [[Unlock advice (386 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816021'))
        -   Failed (invalid output) [[Unlock advice (387 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816022'))
        -   Failed (invalid output) [[Unlock advice (391 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816023'))
        -   Failed (invalid output) [[Unlock advice (386 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816024'))
        -   Failed (invalid output) [[Unlock advice (390 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2816025'))
    -   Overall ratio: 41.66 % (= 1.00 \* 0.83 \* 1.00 \* 0.50)
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 41.66 %
-   Early submission bonus: 0.30
-   Total points: 0.42 \* ( 3.00 + 0.30 ) = 1.37

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**1**|--|--|--|
|Lines of code:|**142**|142.00 ± 0.00|142|`main`|
|Cyclomatic complexity:|**46**|46.00 ± 0.00|46|`main`|

**15**

**2018-11-01 23:25:30**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1585&Tsk=1566&Sub=975640)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': failed
        -   result: 37.50 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.043 s
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (222 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2815949'))
        -   Failed (invalid output) [[Unlock advice (277 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2815950'))
        -   Failed (invalid output) [[Unlock advice (234 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2815951'))
        -   Failed (invalid output) [[Unlock advice (283 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2815952'))
        -   Failed (invalid output) [[Unlock advice (229 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2815953'))
    -   Overall ratio: 0.00 %
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 0.00 %
-   Early submission bonus: 0.30
-   Total points: 0.00 \* ( 3.00 + 0.30 ) = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**1**|--|--|--|
|Lines of code:|**142**|142.00 ± 0.00|142|`main`|
|Cyclomatic complexity:|**46**|46.00 ± 0.00|46|`main`|

**14**

**2018-11-01 23:09:46**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1585&Tsk=1566&Sub=975631)

**Submission status:**

Evaluated

 

**Evaluation:**

1.3750

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.038 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 83.33 %, required: 50.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.118 s
        -   Optional test success, evaluation: 83.33 %
        -   Failed (invalid output) [[Unlock advice (434 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2815902'))
        -   Failed (invalid output) [[Unlock advice (433 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2815903'))
        -   Failed (invalid output) [[Unlock advice (434 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2815904'))
        -   Failed (invalid output) [[Unlock advice (439 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2815905'))
    -   Test 'Invalid input test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.111 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test': failed
        -   result: 10.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.044 s
        -   Optional test failed, evaluation: 50.00 %
        -   Failed (invalid output) [[Unlock advice (389 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2815906'))
        -   Failed (invalid output) [[Unlock advice (381 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2815907'))
        -   Failed (invalid output) [[Unlock advice (387 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2815908'))
        -   Failed (invalid output) [[Unlock advice (388 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2815909'))
        -   Failed (invalid output) [[Unlock advice (387 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2815910'))
        -   Failed (invalid output) [[Unlock advice (390 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2815911'))
        -   Failed (invalid output) [[Unlock advice (385 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2815912'))
        -   Failed (invalid output) [[Unlock advice (390 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2815913'))
        -   Failed (invalid output) [[Unlock advice (387 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2815914'))
    -   Overall ratio: 41.66 % (= 1.00 \* 0.83 \* 1.00 \* 0.50)
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 41.66 %
-   Early submission bonus: 0.30
-   Total points: 0.42 \* ( 3.00 + 0.30 ) = 1.37

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**1**|--|--|--|
|Lines of code:|**142**|142.00 ± 0.00|142|`main`|
|Cyclomatic complexity:|**46**|46.00 ± 0.00|46|`main`|

**13**

**2018-11-01 03:05:33**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1585&Tsk=1566&Sub=974549)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Compile in 'pedantic' mode failed (10 % penalty). [[Unlock advice (686 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=C984191'))
    -   Test 'Basic test with sample input data': failed
        -   result: 87.50 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.037 s
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (383 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2811155'))
    -   Overall ratio: 0.00 %
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 0.00 %
-   Early submission bonus: 0.30
-   Total points: 0.00 \* ( 3.00 + 0.30 ) = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**1**|--|--|--|
|Lines of code:|**142**|142.00 ± 0.00|142|`main`|
|Cyclomatic complexity:|**46**|46.00 ± 0.00|46|`main`|

**12**

**2018-11-01 02:38:55**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1585&Tsk=1566&Sub=974543)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': failed
        -   result: 87.50 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.037 s
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (347 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2811123'))
    -   Overall ratio: 0.00 %
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 0.00 %
-   Early submission bonus: 0.30
-   Total points: 0.00 \* ( 3.00 + 0.30 ) = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**2**|--|--|--|
|Lines of code:|**178**|89.00 ± 83.00|172|`main`|
|Cyclomatic complexity:|**54**|27.00 ± 25.00|52|`main`|

**11**

**2018-11-01 02:35:10**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1585&Tsk=1566&Sub=974542)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': failed
        -   result: 62.50 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.044 s
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (347 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2811120'))
        -   Failed (invalid output) [[Unlock advice (246 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2811121'))
        -   Failed (invalid output) [[Unlock advice (230 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2811122'))
    -   Overall ratio: 0.00 %
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 0.00 %
-   Early submission bonus: 0.30
-   Total points: 0.00 \* ( 3.00 + 0.30 ) = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**2**|--|--|--|
|Lines of code:|**176**|88.00 ± 82.00|170|`main`|
|Cyclomatic complexity:|**54**|27.00 ± 25.00|52|`main`|

**10**

**2018-11-01 02:12:44**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1585&Tsk=1566&Sub=974537)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': failed
        -   result: 50.00 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.042 s
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (319 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2810945'))
        -   Failed (invalid output) [[Unlock advice (423 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2810946'))
        -   Failed (invalid output) [[Unlock advice (342 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2810947'))
        -   Failed (invalid output) [[Unlock advice (427 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2810948'))
    -   Overall ratio: 0.00 %
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 0.00 %
-   Early submission bonus: 0.30
-   Total points: 0.00 \* ( 3.00 + 0.30 ) = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**2**|--|--|--|
|Lines of code:|**185**|92.50 ± 86.50|179|`main`|
|Cyclomatic complexity:|**54**|27.00 ± 25.00|52|`main`|

**9**

**2018-11-01 02:08:00**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1585&Tsk=1566&Sub=974534)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': failed
        -   result: 50.00 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.042 s
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (319 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2810938'))
        -   Failed (invalid output) [[Unlock advice (423 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2810939'))
        -   Failed (invalid output) [[Unlock advice (342 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2810940'))
        -   Failed (invalid output) [[Unlock advice (427 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2810941'))
    -   Overall ratio: 0.00 %
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 0.00 %
-   Early submission bonus: 0.30
-   Total points: 0.00 \* ( 3.00 + 0.30 ) = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**2**|--|--|--|
|Lines of code:|**185**|92.50 ± 86.50|179|`main`|
|Cyclomatic complexity:|**54**|27.00 ± 25.00|52|`main`|

**8**

**2018-11-01 01:51:28**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1585&Tsk=1566&Sub=974533)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': failed
        -   result: 87.50 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.045 s
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (270 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2810937'))
    -   Overall ratio: 0.00 %
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 0.00 %
-   Early submission bonus: 0.30
-   Total points: 0.00 \* ( 3.00 + 0.30 ) = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**2**|--|--|--|
|Lines of code:|**189**|94.50 ± 88.50|183|`main`|
|Cyclomatic complexity:|**54**|27.00 ± 25.00|52|`main`|

**7**

**2018-10-31 00:44:33**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1585&Tsk=1566&Sub=972915)

**Submission status:**

Evaluated

 

**Evaluation:**

2.6125

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.041 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 79.17 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.104 s
        -   Optional test success, evaluation: 79.17 %
        -   Failed (invalid output) [[Unlock advice (351 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2802652'))
        -   Failed (invalid output) [[Unlock advice (351 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2802653'))
        -   Failed (invalid output) [[Unlock advice (347 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2802654'))
        -   Failed (invalid output) [[Unlock advice (352 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2802655'))
        -   Failed (invalid output) [[Unlock advice (350 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2802656'))
    -   Test 'Invalid input test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.100 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.042 s
        -   Optional test success, evaluation: 100.00 %
    -   Overall ratio: 79.17 % (= 1.00 \* 0.79 \* 1.00 \* 1.00)
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 79.17 %
-   Early submission bonus: 0.30
-   Total points: 0.79 \* ( 3.00 + 0.30 ) = 2.61

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**1**|--|--|--|
|Lines of code:|**149**|149.00 ± 0.00|149|`main`|
|Cyclomatic complexity:|**46**|46.00 ± 0.00|46|`main`|

**6**

**2018-10-31 00:26:48**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1585&Tsk=1566&Sub=972900)

**Submission status:**

Evaluated

 

**Evaluation:**

2.6125

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.041 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 79.17 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.108 s
        -   Optional test success, evaluation: 79.17 %
        -   Failed (invalid output) [[Unlock advice (348 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2802475'))
        -   Failed (invalid output) [[Unlock advice (384 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2802476'))
        -   Failed (invalid output) [[Unlock advice (391 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2802477'))
        -   Failed (invalid output) [[Unlock advice (395 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2802478'))
        -   Failed (invalid output) [[Unlock advice (390 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2802479'))
    -   Test 'Invalid input test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.004 s (limit: 1.000 s)
        -   Total run time: 0.099 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.046 s
        -   Optional test success, evaluation: 100.00 %
    -   Overall ratio: 79.17 % (= 1.00 \* 0.79 \* 1.00 \* 1.00)
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 79.17 %
-   Early submission bonus: 0.30
-   Total points: 0.79 \* ( 3.00 + 0.30 ) = 2.61

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**1**|--|--|--|
|Lines of code:|**149**|149.00 ± 0.00|149|`main`|
|Cyclomatic complexity:|**46**|46.00 ± 0.00|46|`main`|

**5**

**2018-10-30 23:03:26**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1585&Tsk=1566&Sub=972792)

**Submission status:**

Evaluated

 

**Evaluation:**

2.4750

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.039 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 75.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.105 s
        -   Optional test success, evaluation: 75.00 %
        -   Failed (invalid output) [[Unlock advice (354 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2801557'))
        -   Failed (invalid output) [[Unlock advice (354 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2801558'))
        -   Failed (invalid output) [[Unlock advice (388 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2801559'))
        -   Failed (invalid output) [[Unlock advice (385 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2801560'))
        -   Failed (invalid output) [[Unlock advice (387 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2801561'))
        -   Failed (invalid output) [[Unlock advice (388 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2801562'))
    -   Test 'Invalid input test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.087 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.004 s (limit: 1.000 s)
        -   Total run time: 0.037 s
        -   Optional test success, evaluation: 100.00 %
    -   Overall ratio: 75.00 % (= 1.00 \* 0.75 \* 1.00 \* 1.00)
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 75.00 %
-   Early submission bonus: 0.30
-   Total points: 0.75 \* ( 3.00 + 0.30 ) = 2.48

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**1**|--|--|--|
|Lines of code:|**149**|149.00 ± 0.00|149|`main`|
|Cyclomatic complexity:|**46**|46.00 ± 0.00|46|`main`|

**4**

**2018-10-30 00:08:45**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1585&Tsk=1566&Sub=971690)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': failed
        -   result: 87.50 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.038 s
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (270 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2795581'))
    -   Overall ratio: 0.00 %
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 0.00 %
-   Early submission bonus: 0.30
-   Total points: 0.00 \* ( 3.00 + 0.30 ) = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**1**|--|--|--|
|Lines of code:|**142**|142.00 ± 0.00|142|`main`|
|Cyclomatic complexity:|**46**|46.00 ± 0.00|46|`main`|

**3**

**2018-10-30 00:02:11**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1585&Tsk=1566&Sub=971681)

**Submission status:**

Evaluated

 

**Evaluation:**

2.3375

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.042 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 70.83 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.101 s
        -   Optional test success, evaluation: 70.83 %
        -   Failed (invalid output) [[Unlock advice (352 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2795510'))
        -   Failed (invalid output) [[Unlock advice (355 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2795511'))
        -   Failed (invalid output) [[Unlock advice (354 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2795512'))
        -   Failed (invalid output) [[Unlock advice (354 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2795513'))
        -   Failed (invalid output) [[Unlock advice (351 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2795514'))
        -   Failed (invalid output) [[Unlock advice (353 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2795515'))
        -   Failed (invalid output) [[Unlock advice (350 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2795516'))
    -   Test 'Invalid input test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.008 s (limit: 1.000 s)
        -   Total run time: 0.122 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.043 s
        -   Optional test success, evaluation: 100.00 %
    -   Overall ratio: 70.83 % (= 1.00 \* 0.71 \* 1.00 \* 1.00)
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 70.83 %
-   Early submission bonus: 0.30
-   Total points: 0.71 \* ( 3.00 + 0.30 ) = 2.34

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**1**|--|--|--|
|Lines of code:|**142**|142.00 ± 0.00|142|`main`|
|Cyclomatic complexity:|**46**|46.00 ± 0.00|46|`main`|

**2**

**2018-10-29 23:02:16**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1585&Tsk=1566&Sub=971612)

**Submission status:**

Evaluated

 

**Evaluation:**

1.9250

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Max. run time: 0.007 s (limit: 1.000 s)
        -   Total run time: 0.049 s
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 58.33 %, required: 50.00 %
        -   Max. run time: 0.007 s (limit: 1.000 s)
        -   Total run time: 0.122 s
        -   Optional test success, evaluation: 58.33 %
        -   Failed (invalid output) [[Unlock advice (300 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2795199'))
        -   Failed (invalid output) [[Unlock advice (301 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2795200'))
        -   Failed (invalid output) [[Unlock advice (304 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2795201'))
        -   Failed (invalid output) [[Unlock advice (342 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2795202'))
        -    Failed (invalid output)

             Input data [[96 B / 96 B]](https://progtest.fit.cvut.cz/index.php?X=Advice&UID=I2795203)

            ``` {#pre_I2795203 style="display: none"}
            -248.035 42.695
            -234.974 356.259
            -159.787 411.510
            5.951 110.612
            57.730 -109.852
            57.730 -109.852
            ```

             Output data [[126 B / 126 B]](https://progtest.fit.cvut.cz/index.php?X=Advice&UID=O2795203)

            ``` {#pre_O2795203 style="display: none"}
            Triangle #1:
            Vertex A:
            Vertex B:
            Vertex C:
            Triangle #2:
            Vertex A:
            Vertex B:
            Vertex C:
            Triangle #1 has a longer circumference.
            ```

             Reference [[121 B / 121 B]](https://progtest.fit.cvut.cz/index.php?X=Advice&UID=R2795203)

            ``` {#pre_R2795203 style="display: none"}
            Triangle #1:
            Vertex A:
            Vertex B:
            Vertex C:
            Triangle #2:
            Vertex A:
            Vertex B:
            Vertex C:
            The points do not form a triangle.
            ```

        -   Failed (invalid output) [[Unlock advice (346 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2795204'))
        -   Failed (invalid output) [[Unlock advice (388 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2795205'))
        -   Failed (invalid output) [[Unlock advice (388 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2795206'))
        -   Failed (invalid output) [[Unlock advice (387 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2795207'))
        -   Failed (invalid output) [[Unlock advice (390 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2795208'))

    -   Test 'Invalid input test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.005 s (limit: 1.000 s)
        -   Total run time: 0.112 s
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test': success
        -   result: 100.00 %, required: 50.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.051 s
        -   Optional test success, evaluation: 100.00 %
    -   Overall ratio: 58.33 % (= 1.00 \* 0.58 \* 1.00 \* 1.00)
-   Total percent: 58.33 %
-   Early submission bonus: 0.30
-   Total points: 0.58 \* ( 3.00 + 0.30 ) = 1.92

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**1**|--|--|--|
|Lines of code:|**132**|132.00 ± 0.00|132|`main`|
|Cyclomatic complexity:|**40**|40.00 ± 0.00|40|`main`|

**1**

**2018-10-29 22:56:59**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1585&Tsk=1566&Sub=971601)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': failed
        -   result: 87.50 %, required: 100.00 %
        -   Max. run time: 0.006 s (limit: 1.000 s)
        -   Total run time: 0.042 s
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (270 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=251&Tgr=1585&Tsk=1566&Unl=L2795131'))
    -   Overall ratio: 0.00 %
-   Total percent: 0.00 %
-   Early submission bonus: 0.30
-   Total points: 0.00 \* ( 3.00 + 0.30 ) = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**1**|--|--|--|
|Lines of code:|**132**|132.00 ± 0.00|132|`main`|
|Cyclomatic complexity:|**40**|40.00 ± 0.00|40|`main`|


