||
|[ProgTest](https://progtest.fit.cvut.cz/index.php?X=Main)  ►  [BIE-PA1 (18/19 ZS)](https://progtest.fit.cvut.cz/index.php?X=Course&Cou=251)  ►  [Homework 08](https://progtest.fit.cvut.cz/index.php?X=TaskGrp&Cou=251&Tgr=1593)  ►  **Employee list II**|[Logout](https://progtest.fit.cvut.cz/index.php?X=Logout)|

||
|**Employee list II**|

**Submission deadline:**

**2018-12-30 23:59:59**

 

**Late submission with malus:**

**2019-01-06 23:59:59** (Late submission malus: 100.0000 %)

**Evaluation:**

**6.6000 (6.6000 - Cribbed copy)**

**Max. assessment:**

**5.0000** (Without bonus points)

**Submissions:**

3 / 20 Free retries + 10 Penalized retries (-10 % penalty each retry)

**Advices:**

0 / 2 Advices for free + 2 Advices with a penalty (-10 % penalty each advice)

The task is to implement a set of functions to handle linked lists. An office is implemented as a structure with two linked lists. The first linked list stores the employees, the second list represents the cars. Each employee is represented by name and a link to his/her assigned car. A car is represented by its model name. Given that structures, the functions are used to initialize a new office, add a new employee, add a new car, copy the office, and dispose the office.

`TEMPLOYEE`  
is a data structure defined in the testing environment. Your implementation must use the structure, however, it must not modify it in any way. The structure represents one employee. The employees are organized in a single linked list. The structure has the following fields:

-   `m_Next` - a link to the next employee in the list. The last employee in the list must set `m_Next` to the `NULL` value.
-   `m_Car` - is a link to the assigned car. The link is either `NULL` (meaning the employee does not have any car assigned), or it references some element in the car linked list.
-   `m_Name` - an ASCIIZ (zero terminated) employee name.

`TCAR`  
is a data structure defined in the testing environment. Your implementation must use the structure, however, it must not modify it in any way. The structure represents one car. The car are organized in a single linked list. The structure has the following fields:

-   `m_Next` - a link to the next car in the list. The last car in the list must set `m_Next` to the `NULL` value.
-   `m_Model` - an ASCIIZ (zero terminated) car model name.

`TOFFICE`  
is a data structure defined in the testing environment. Your implementation must use the structure, however, it must not modify it in any way. The structure represents one office, the structure contains two fields:

-   `m_Emp` - a pointer to the first employee in the linked list of employees,
-   `m_Car` - a pointer to the first car in the linked list of cars.

`initOffice ()`  
the function creates a new office. The structure is to be dynamically allocated and a pointer to that structure is to be returned. Both lists in the newly created office must be initialized as empty.

`addEmployee ( office, name )`  
the function creates a new employee and places the new employee at the first position of the employee list. The parameters are `name` - name of the new employee and `office` - the office to place the employee to. The function is responsible for the allocation of the employee structure, moreover it must initialize the fields. The newly listed employee does not have any car assigned, i.e. `m_Car` must be set to `NULL`.

`addCar ( office, model )`  
the function creates a new car and places the new car at the first position of the car list. The parameters are `model` - the model name of the car and `office` - the office to place the car to. The function is responsible for the allocation of the car structure, moreover it must initialize the fields.

`freeOffice ( office )`  
the function frees all resources allocated by the given office (i.e. both employee and car linked lists plus the structure that represents the office),

`cloneOffice ( office )`  
the function creates an independent copy of the given office. The newly created office must preserve the employees, the cars, the order of employees, the order of the cars, and the assigned cars. Caution: the newly created list must be independent, thus the links to the cars must be updated to refer to the corresponding elements in the newly created office. Return value is a pointer that points to the newly allocated (and filled) office structure.

Submit a source file with the implementation of the above functions. Further, the source file must include your auxiliary functions which are called from the required functions. Your functions will be called from the testing environment, thus, it is important to adhere to the required interface. Use the attached sample code as a basis for your development, complete the required functions and add your required auxiliary functions. There is an example `main` with some tests in the attached code. These test cases will be used in the basic test. Please note the header files as well as `main` is nested in a conditional compile block (`#ifdef/#endif`). Please keep these conditional compile block in place. They are present to simplify the development. When compiling on your computer, the headers and `main` will be present as usual. On the other hand, the header and `main` will "disappear" when compiled by Progtest. Thus, your testing `main` will not interfere with the testing environment's `main`.

Your function will be executed in a limited environment. There are limits on both time and memory. The exact limits are shown in the test log of the reference. A reasonable implementation of the naive algorithm shall pass both limits without any problems. There is a bonus test, the bonus test requires an efficient algorithm to copy the lists.

**Advice:**

-   Download the attached sample code and use it as a base for your development.
-   The `main` function in your program may be modified (e.g. a new test may be included). The conditional compile block must remain, however.
-   There is macro `assert` used in the example `main` function. If the value passed to `assert` is nonzero (true), the macro does nothing. On the other hand, if the parameter is zero, the macro stops the execution and reports the line, where the test did not match (and shall be fixed). Thus, the program ends silently when your implementation passes all the tests correctly.
-   There are not any known limitations on the employee names. In particular, employee names may be unique, but they do not have to be.

**Sample data:**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskS&Cou=251&Tgr=1593&Tsk=1583)

 **Reference**

 

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Zakladni test podle ukazky': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 2.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Test meznich hodnot': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.000 s (limit: 2.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Test nahodnymi daty': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.013 s (limit: 2.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Test nahodnymi daty + test prace s pameti': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.031 s (limit: 2.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Bonus - rychlost': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 2.441 s (limit: 5.000 s)
        -   Bonus test - success, evaluation: 120.00 %
    -   Overall ratio: 120.00 % (= 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.20)
-   Total percent: 120.00 %
-   Early submission bonus: 0.50
-   Total points: 1.20 \* ( 5.00 + 0.50 ) = 6.60

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**5**|--|--|--|
|Lines of code:|**78**|15.60 ± 10.33|34|`cloneOffice`|
|Cyclomatic complexity:|**11**|2.20 ± 1.60|5|`cloneOffice`|

**3**

**2018-12-23 22:33:59**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1593&Tsk=1583&Sub=1035151)

**Submission status:**

Evaluated

 

**Evaluation:**

6.6000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 2.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.000 s (limit: 2.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.017 s (limit: 2.000 s)
        -   CPU time: 0.020 s (limit: 2.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test + memory usage test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.023 s (limit: 2.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Bonus - speed': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 2.397 s (limit: 5.000 s)
        -   Bonus test - success, evaluation: 120.00 %
    -   Overall ratio: 120.00 % (= 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.20)
-   Total percent: 120.00 %
-   Early submission bonus: 0.50
-   Total points: 1.20 \* ( 5.00 + 0.50 ) = 6.60

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**6**|--|--|--|
|Lines of code:|**192**|32.00 ± 32.58|96|`main`|
|Cyclomatic complexity:|**54**|9.00 ± 13.35|38|`main`|

**2**

**2018-12-23 22:28:10**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1593&Tsk=1583&Sub=1035139)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 2.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': Abnormal program termination (Segmentation fault/Bus error/Memory limit exceeded/Stack limit exceeded)
        -   Total run time: 0.005 s (limit: 2.000 s)
        -   Mandatory test failed, evaluation: 0.00 %
    -   Overall ratio: 0.00 % (= 1.00 \* 0.00)
-   Total percent: 0.00 %
-   Early submission bonus: 0.50
-   Total points: 0.00 \* ( 5.00 + 0.50 ) = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**6**|--|--|--|
|Lines of code:|**198**|33.00 ± 33.27|96|`main`|
|Cyclomatic complexity:|**56**|9.33 ± 13.40|38|`main`|

**1**

**2018-12-23 22:22:35**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=251&Tgr=1593&Tsk=1583&Sub=1035126)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 2.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': Abnormal program termination (Segmentation fault/Bus error/Memory limit exceeded/Stack limit exceeded)
        -   Total run time: 0.006 s (limit: 2.000 s)
        -   Mandatory test failed, evaluation: 0.00 %
    -   Overall ratio: 0.00 % (= 1.00 \* 0.00)
-   Total percent: 0.00 %
-   Early submission bonus: 0.50
-   Total points: 0.00 \* ( 5.00 + 0.50 ) = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**6**|--|--|--|
|Lines of code:|**192**|32.00 ± 32.58|96|`main`|
|Cyclomatic complexity:|**54**|9.00 ± 13.35|38|`main`|


