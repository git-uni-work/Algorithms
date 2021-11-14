||
|[ProgTest](https://progtest.fit.cvut.cz/index.php?X=Main)  ►  [BIE-PA2 (19/20 LS)](https://progtest.fit.cvut.cz/index.php?X=Course&Cou=293)  ►  [Homework 02](https://progtest.fit.cvut.cz/index.php?X=TaskGrp&Cou=293&Tgr=1847)  ►  **Tax register**|[Logout](https://progtest.fit.cvut.cz/index.php?X=Logout)|

||
|**Tax register**|

**Submission deadline:**

**2020-03-29 23:59:59**

 

**Late submission with malus:**

**2020-06-30 23:59:59** (Late submission malus: 100.0000 %)

**Evaluation:**

**7.1500**

**Max. assessment:**

**7.1500** (Without bonus points)

**Submissions:**

7 / 20 Free retries + 20 Penalized retries (-2 % penalty each retry)

**Advices:**

1 / 2 Advices for free + 2 Advices with a penalty (-10 % penalty each advice)

Your task is to implement class `CTaxRegister`, which implements a simple tax revenue database.

The database is very simplified. We assume the database holds information about all citizens from the moment they born until they die. Each citizen is identified by his/her account. The accounts are strings and are unique in the database. Second, citizens may be positively identified by their names and addresses. We assume the pair (name, address) is unique in the database. That is, there may exist many citizens with the same name (e.g. "John Smith"), there may be many citizens registered with the same address (e.g. "Main Street 10"), however, there may be at most one "John Smith" registered on "Main Street 10".

The class shall implement the following public interface:

-   A constructor (without parameters). This constructor initializes a new empty database.
-   Destructor -- it shall free all resources used by the instance.
-   Method `Birth (Name, Addr, Acct )` which adds a new record to the database. The parameters are name, address and account id of the person being registered. The method returns `true` if it succeeds, or `false` if it fails (the pair `Name, Addr` is already present in the database, or the `Acct` is not unique in the database).
-   Method `Death (Name, Addr)` removes the corresponding record from the database, the record is identified by the name and address. The method returns `true` if it succeeds, or `false` if it fails (the corresponding record was not present).
-   Methods `Income` add `Amount` to the income of some account. There are two variants of the method: the account is either identified directly by account id, or the account is identified by the owner name and address. The methods return `true` if they succeed, or `false` if they fail (the corresponding person was not found).
-   Methods `Expense` add `Amount` to the expenses of some account. There are two variants of the method: the account is either identified directly by account id, or the account is identified by the owner name and address. The methods return `true` if they succeed, or `false` if they fail (the corresponding person was not found).
-   Method `Audit ( Name, Addr, Acct, SumIncome, SumExpense)` searches the database for the record identified by owner name and address. The method fills the `Acct`, `SumIncome`, and `SumExpense` output parameters accordingly. The method returns `true` if it succeeds, or `false` if it fails (the corresponding person was not found). Moreover, if the method fails, the output parameters shall be left unmodified.
-   Method `ListByName` creates and returns a new instance of class `CIterator`. The exact interface of the returned object is listed below, the object is used to access the records in the tax register. The records are visited in a sorted way, the order will be based on the person names (i.e., the person with the lexicographically smallest name is visited first). If the tax register contains two records with the same name, then the record with lexicographically smaller address goes first.

The public interface of `CIterator` class is the following:

-   Method `AtEnd` returns a boolean `true` if the end of the register was reached (the iterator does not refer to any valid record) or boolean `false` if the iterator did not reach the end of the register (it refers to a valid record).
-   Method `Next` which advances the iterator further.
-   Method `Name` to retrieve the name of a person at the current iterator position.
-   Method `Addr` to retrieve the address of a person at the current iterator position.
-   Method `Account` to retrieve the account id of a person at the current iterator position.
-   The testing environment does not perform any changes to the register when the iterator created for the register is used. In particular, methods `CTaxRegister::Birth` and `CTaxRegister::Death` are not called.

Submit a source file with your implementation of classes `CTaxRegister` and `CIterator`. The class must follow the required public interface. If there is a mismatch in the interface, the compilation will fail. You may extend the interface and add you auxiliary methods and member variables (both public and private, although private are preferred). The submitted file must include both declarations as well as implementation of the class (the methods may be implemented inline but do not have to). The submitted file shall not contain anything except the required classes. In particular, if the file contains `main`, your tests, or any \#include definitions, please, keep them in a conditional compile block. Use the attached template as a basis for your implementation. If the preprocessor definitions are preserved, the file may be submitted to Progtest.

The class is tested in a limited environment -- both memory and running time is limited. The available memory is big enough to store the records. The class does not have to implement a copy constructor or an overloaded operator =. This functionality is not tested in this homework.

Your implementation must be both time and space efficient. A simple linear-time solution will not succeed (it takes more than 5 minutes for the test data). You may assume `Birth` and `Death` calls are rare compared to the other methods. Thus, a binary searching in a sorted array with logarithmic time complexity is recommended. The add and delete operations may be implemented using binary searching (to find the index) and linear copying of the array elements.

Either STL container or a dynamic array allocation is required to implement the database. If implemented using the dynamically allocated array, set the initial size of the array to some reasonably small value (e.g. one hundred elements). When the array is full, do not increase the size by just one element. The overhead of the resizing would be enormous. Instead, increase the size by e.g. a thousand elements or use a quotient ranging from 1.5 to 2 (better solution).

If STL is used, your implementation does not have to care about the allocation. Caution: STL container `map` is disabled in this homework.

* * * * *

**Notes:**

-   There is a solution template in the attached archive. Use it as a basis of your implementation. Next, the attached archive contains a basic test set.
-   Do not submit solutions with test cases copied from your colleagues. Submissions with such copied test cases will be considered cribbed. (The test cases in the attached archive are permitted.)
-   This homework may be used for code review.

**Sample data:**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskS&Cou=293&Tgr=1847&Tsk=1056)

 **Reference**

 

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Zakladni test s parametry podle ukazky': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 8.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Test meznich hodnot': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.072 s (limit: 8.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Test nahodnymi vstupy (Add, Search)': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.004 s (limit: 7.928 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Test nahodnymi vstupy (Add, Del, Search)': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.004 s (limit: 7.924 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Test rychlosti (nahodne hodnoty)': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.378 s (limit: 7.920 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Test nahodnymi hodnotami + test prace s pameti': success
        -   result: 100.00 %, required: 25.00 %
        -   Total run time: 0.017 s (limit: 8.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Test rychlosti (nahodna jmena, fixni adresa)': success
        -   result: 100.00 %, required: 75.00 %
        -   Total run time: 0.529 s (limit: 10.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Test rychlosti (fixni jmena, nahodna adresa)': success
        -   result: 100.00 %, required: 75.00 %
        -   Total run time: 0.440 s (limit: 9.471 s)
        -   Optional test success, evaluation: 100.00 %
    -   Overall ratio: 100.00 % (= 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.00)
-   Total percent: 100.00 %
-   Early submission bonus: 0.72
-   Total points: 1.00 \* ( 7.15 + 0.72 ) = 7.87

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**18**|--|--|--|
|Lines of code:|**179**|9.94 ± 7.21|29|`CTaxRegister::Birth`|
|Cyclomatic complexity:|**49**|2.72 ± 2.26|8|`CTaxRegister::Birth`|

**7**

**2020-05-04 05:36:15**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1847&Tsk=1056&Sub=1165800)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 8.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.265 s (limit: 8.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (Add, Search)': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.021 s (limit: 7.735 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (Add, Del, Search)': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.019 s (limit: 7.714 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Speed test (nahodne hodnoty)': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 1.536 s (limit: 7.695 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random input test + correct memory usage test': success
        -   result: 100.00 %, required: 25.00 %
        -   Total run time: 0.099 s (limit: 8.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test (random names, fixed address)': success
        -   result: 100.00 %, required: 75.00 %
        -   Total run time: 1.653 s (limit: 10.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test (fixed names, random address)': success
        -   result: 100.00 %, required: 75.00 %
        -   Total run time: 1.401 s (limit: 8.347 s)
        -   Optional test success, evaluation: 100.00 %
    -   Overall ratio: 100.00 % (= 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.00)
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 100.00 %
-   Late submission malus: 7.15
-   Total points: 1.00 \* ( 7.15 - 7.15 ) = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**28**|--|--|--|
|Lines of code:|**247**|8.82 ± 14.07|75|`main`|
|Cyclomatic complexity:|**73**|2.61 ± 2.78|13|`main`|

**6**

**2020-03-29 00:46:37**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1847&Tsk=1056&Sub=1149432)

**Submission status:**

Evaluated

 

**Evaluation:**

7.1500

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 8.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.142 s (limit: 8.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (Add, Search)': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.019 s (limit: 7.858 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test (Add, Del, Search)': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.017 s (limit: 7.839 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Speed test (nahodne hodnoty)': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 1.357 s (limit: 7.822 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random input test + correct memory usage test': success
        -   result: 100.00 %, required: 25.00 %
        -   Total run time: 0.081 s (limit: 8.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test (random names, fixed address)': success
        -   result: 100.00 %, required: 75.00 %
        -   Total run time: 1.392 s (limit: 10.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test (fixed names, random address)': success
        -   result: 100.00 %, required: 75.00 %
        -   Total run time: 1.190 s (limit: 8.608 s)
        -   Optional test success, evaluation: 100.00 %
    -   Overall ratio: 100.00 % (= 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.00)
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 100.00 %
-   Total points: 1.00 \* 7.15 = 7.15

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**20**|--|--|--|
|Lines of code:|**236**|11.80 ± 15.70|75|`main`|
|Cyclomatic complexity:|**65**|3.25 ± 3.06|13|`main`|

**5**

**2020-03-29 00:39:00**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1847&Tsk=1056&Sub=1149425)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 8.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': failed
        -   result: 95.60 %, required: 100.00 %
        -   Total run time: 0.304 s (limit: 8.000 s)
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (190 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3534819'))
        -   Failed (invalid output) [[Unlock advice (192 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3534820'))
        -   Failed (invalid output) [[Unlock advice (192 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3534821'))
        -   Failed (invalid output) [[Unlock advice (192 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3534822'))
        -   Failed (invalid output) [[Unlock advice (175 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3534823'))
        -   Failed (invalid output) [[Unlock advice (172 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3534824'))
        -   Failed (invalid output) [[Unlock advice (172 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3534825'))
        -   Failed (invalid output) [[Unlock advice (172 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3534826'))
    -   Overall ratio: 0.00 % (= 1.00 \* 0.00)
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 0.00 %
-   Total points: 0.00 \* 7.15 = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**20**|--|--|--|
|Lines of code:|**238**|11.90 ± 15.66|75|`main`|
|Cyclomatic complexity:|**58**|2.90 ± 2.84|13|`main`|

**4**

**2020-03-29 00:29:48**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1847&Tsk=1056&Sub=1149422)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 8.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': failed
        -   result: 89.61 %, required: 100.00 %
        -   Total run time: 2.001 s (limit: 8.000 s)
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (192 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3534809'))
        -   Failed (invalid output) [[Unlock advice (192 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3534810'))
        -   Failed (invalid output) [[Unlock advice (192 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3534811'))
        -   Failed (invalid output) [[Unlock advice (192 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3534812'))
        -   Failed (invalid output) [[Unlock advice (39 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3534813'))
        -   Failed (invalid output) [[Unlock advice (39 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3534814'))
        -   Failed (invalid output) [[Unlock advice (38 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3534815'))
        -   Failed (invalid output) [[Unlock advice (39 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3534816'))
    -   Overall ratio: 0.00 % (= 1.00 \* 0.00)
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 0.00 %
-   Total points: 0.00 \* 7.15 = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**20**|--|--|--|
|Lines of code:|**241**|12.05 ± 15.64|75|`main`|
|Cyclomatic complexity:|**57**|2.85 ± 2.87|13|`main`|

**3**

**2020-03-29 00:02:01**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1847&Tsk=1056&Sub=1149405)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 8.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': failed
        -   result: 89.61 %, required: 100.00 %
        -   Total run time: 1.532 s (limit: 8.000 s)
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (190 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3534714'))
        -   Failed (invalid output) [[Unlock advice (192 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3534715'))
        -   Failed (invalid output) [[Unlock advice (192 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3534716'))
        -   Failed (invalid output) [[Unlock advice (192 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3534717'))
        -   Failed (invalid output) [[Unlock advice (39 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3534718'))
        -   Failed (invalid output) [[Unlock advice (39 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3534719'))
        -   Failed (invalid output) [[Unlock advice (38 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3534720'))
        -   Failed (invalid output) [[Unlock advice (39 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3534721'))
    -   Overall ratio: 0.00 % (= 1.00 \* 0.00)
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 0.00 %
-   Total points: 0.00 \* 7.15 = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**20**|--|--|--|
|Lines of code:|**235**|11.75 ± 15.75|75|`main`|
|Cyclomatic complexity:|**57**|2.85 ± 2.87|13|`main`|

**2**

**2020-03-28 05:27:13**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1847&Tsk=1056&Sub=1148919)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Compile in 'pedantic' mode failed (10 % penalty). [[Unlock advice (513 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=C1155839'))
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 8.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': failed
        -   result: 89.61 %, required: 100.00 %
        -   Total run time: 1.579 s (limit: 8.000 s)
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (190 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3533322'))
        -   Failed (invalid output) [[Unlock advice (192 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3533323'))
        -   Failed (invalid output) [[Unlock advice (192 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3533324'))
        -   Failed (invalid output) [[Unlock advice (192 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3533325'))
        -   Failed (invalid output) [[Unlock advice (39 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3533326'))
        -   Failed (invalid output) [[Unlock advice (39 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3533327'))
        -   Failed (invalid output) [[Unlock advice (38 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3533328'))
        -   Failed (invalid output) [[Unlock advice (39 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3533329'))
    -   Overall ratio: 0.00 % (= (1.00 \* 0.00) \* 0.9)
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 0.00 %
-   Total points: 0.00 \* 7.15 = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**21**|--|--|--|
|Lines of code:|**260**|12.38 ± 15.81|75|`main`|
|Cyclomatic complexity:|**59**|2.81 ± 2.81|13|`main`|

**1**

**2020-03-27 23:56:38**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1847&Tsk=1056&Sub=1148850)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 8.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline test': failed
        -   result: 95.61 %, required: 100.00 %
        -   Total run time: 0.856 s (limit: 8.000 s)
        -   Mandatory test failed, evaluation: 0.00 %
        -    Failed (invalid output)

                 Birth ( "KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK", "KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK", "Flpjqdjfcgfcca" ) => r=true, s=false

        -   Failed (invalid output) [[Unlock advice (190 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3533169'))
        -   Failed (invalid output) [[Unlock advice (192 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3533170'))
        -   Failed (invalid output) [[Unlock advice (192 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3533171'))
        -   Failed (invalid output) [[Unlock advice (39 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3533172'))
        -   Failed (invalid output) [[Unlock advice (39 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3533173'))
        -   Failed (invalid output) [[Unlock advice (38 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3533174'))
        -   Failed (invalid output) [[Unlock advice (39 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1847&Tsk=1056&Unl=L3533175'))

    -   Overall ratio: 0.00 % (= 1.00 \* 0.00)
-   Total percent: 0.00 %
-   Total points: 0.00 \* 7.15 = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**20**|--|--|--|
|Lines of code:|**233**|11.65 ± 15.78|75|`main`|
|Cyclomatic complexity:|**57**|2.85 ± 2.87|13|`main`|


