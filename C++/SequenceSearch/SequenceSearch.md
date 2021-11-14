||
|[ProgTest](https://progtest.fit.cvut.cz/index.php?X=Main)  ►  [BIE-PA2 (19/20 LS)](https://progtest.fit.cvut.cz/index.php?X=Course&Cou=293)  ►  [Homework 07](https://progtest.fit.cvut.cz/index.php?X=TaskGrp&Cou=293&Tgr=1854)  ►  **Sequence search**|[Logout](https://progtest.fit.cvut.cz/index.php?X=Logout)|

||
|**Sequence search**|

**Submission deadline:**

**2020-05-03 23:59:59**

 

**Late submission with malus:**

**2020-06-30 23:59:59** (Late submission malus: 100.0000 %)

**Evaluation:**

**7.1500**

**Max. assessment:**

**7.1500** (Without bonus points)

**Submissions:**

1 / 20 Free retries + 20 Penalized retries (-2 % penalty each retry)

**Advices:**

0 / 2 Advices for free + 2 Advices with a penalty (-10 % penalty each advice)

The task is to develop class template `CSearch`. The class will implement sequence-in-sequence searching. A string may be considered an example sequence. Thus, the class will be able to search a string in another string. Moreover, the class will be able to search multiple sequences (strings) in the searched sequence (string).

To make the class very flexible, there will be two generic parameters:

-   `_Type` is the data type of the sequence. This may be either C++ `string` or a sequential STL container (e.g., `vector`, `deque`, `forward_list`, `list`, ...). Thus, the class may handle string-in-string searches (`_Type = string`), a sequence of integers inside another sequence of integers (`_Type = vector<int>` or `_Type =   list<int>`), sequences of strings (`_Type = vector<string>` or `_Type =   list<string>`), ... Please note that the `forward_list` only supports forward iterator.

    The elements in the containers may be of virtually any data type. The type of the element is implicitly defined by the generic parameter `_Type`. It may be `char` data type (for `string`), primitive data types (such as `int`), or any other compound data type. You may assume that the element data type supports copying (built-in or a custom copy constructor and operator =), destructor, and equal/not equal comparison operators (==, !=). No further interface is guaranteed. Caution, there does not have to be default constructor present in the element data type.

-   `_Comparator` is an optional generic parameter for the comparator. It is either a function object, a function, or the generic parameter is omitted (meaning to use the `std::equal_to` from the STL library).

The interface of the class:

-   Constructor (optionally with a comparator) creates an empty object instance.
-   Destructor (if needed)
-   Method `Add(id,needle)` adds another sequence `needle` into the list of sequences to search for. The sequence is identified by the integer `id`.
-   Method `Search(hayHeap)` searches the sequence `hayHeap` for all sequences previously added via `Add` method. The method returns set of integer identifiers (`id`), the set will list the sequences found in `hayHeap`.
-   Copy constructor and operator = are not tested in this homework, thus, there is no need to actually implement them. However, it is a good idea to disable them (see the attached source).

Submit a source file with your `CSearch` template implementation. Moreover, add any further class (or classes) your implementation requires. The class must follow the public interface below. If there is a mismatch in the interface, the compilation will fail. You may extend the interface and add you auxiliary methods and member variables (both public and private, although private are preferred). The submitted file must include both declarations as well as implementation of the class (the methods may be implemented inline but do not have to). The submitted file shall not contain anything unnecessary. In particular, if the file contains `main`, your tests, or any \#include definitions, please, keep them in a conditional compile block. Use the template below as a basis for your implementation. If the preprocessor definitions are preserved, the file maybe submitted to Progtest.

Use STL to develop the `CSearch` class.

There are mandatory and optional tests in this homework. There is many long sequences to search for in the bonus test. Naive algorithm is too slow to finish the search in time. To pass the bonus, implement some more efficient algorithm like Aho-Corasick.

The solution of this homework cannot be used for code review (the naive solution is quite straightforward and short). Some complexity comes with the language (templates).

* * * * *

**Advice:**

-   Sequential STL containers are: `vector`, `list`, `deque`, `forward_list`, `array`, and `string`. Only these types (their specializations) may be used in the place of generic parameter `_Type`.
-   The above listed STL containers provide useful public declarations, your implementation may want o use them. Read about `_Type::value_type`, `_Type::iterator`, and others.
-   The `CSearch` instance needs to store some pre-calculated data for the efficient searching algorithm (bonus test). It is clumsy to pre-calculate the data after each invocation of `Add` (there may follow another call to `Add`, thus the pre-calculation was useless). The other option is to pre-calculate the data in the `Search` method. `Search` is declared as `const`, thus it cannot modify any member variable. This situation may be solved if the member variables with the pre-calculated values are marked as `mutable`. A `mutable` member variable may be modified even in the body of a `const` method. A `mutable` member variable does not define the state of the object. Instead, such member variable stores some data derived from the non-mutable members, e.g. to speed up the computation.

**Sample data:**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskS&Cou=293&Tgr=1854&Tsk=929)

 **Reference**

 

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Zakladni test s parametry podle ukazky': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 3.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Test nahodnymi daty': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.028 s (limit: 3.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Efektivita - rychlost': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 2.083 s (limit: 8.000 s)
        -   Bonus test - success, evaluation: 120.00 %
    -   Overall ratio: 120.00 % (= 1.00 \* 1.00 \* 1.20)
-   Total percent: 120.00 %
-   Early submission bonus: 0.72
-   Total points: 1.20 \* ( 7.15 + 0.72 ) = 9.44

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**15**|--|--|--|
|Lines of code:|**174**|11.60 ± 10.43|38|`main`|
|Cyclomatic complexity:|**34**|2.27 ± 1.91|7|`CSearch::solveFail`|

**1**

**2020-05-02 01:01:00**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1854&Tsk=929&Sub=1165088)

**Submission status:**

Evaluated

 

**Evaluation:**

7.1500

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 3.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.112 s (limit: 3.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Efficiency - speed': Abnormal program termination (Time limit exceeded)
        -   Cumulative test time exceeded, killed after:: 8.015 s (limit: 8.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 100.00 % (= 1.00 \* 1.00)
-   Total percent: 100.00 %
-   Total points: 1.00 \* 7.15 = 7.15

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**9**|--|--|--|
|Lines of code:|**92**|10.22 ± 15.65|50|`main`|
|Cyclomatic complexity:|**16**|1.78 ± 1.31|5|`CSearch::check`|


