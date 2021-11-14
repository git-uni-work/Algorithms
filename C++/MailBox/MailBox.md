||
|[ProgTest](https://progtest.fit.cvut.cz/index.php?X=Main)  ►  [BIE-PA2 (19/20 LS)](https://progtest.fit.cvut.cz/index.php?X=Course&Cou=293)  ►  [Homework 05](https://progtest.fit.cvut.cz/index.php?X=TaskGrp&Cou=293&Tgr=1851)  ►  **Mail box**|[Logout](https://progtest.fit.cvut.cz/index.php?X=Logout)|

||
|**Mail box**|

**Submission deadline:**

**2020-04-19 23:59:59**

 

**Late submission with malus:**

**2020-06-30 23:59:59** (Late submission malus: 100.0000 %)

**Evaluation:**

**7.8650**

**Max. assessment:**

**7.1500** (Without bonus points)

**Submissions:**

9 / 20 Free retries + 20 Penalized retries (-2 % penalty each retry)

**Advices:**

0 / 2 Advices for free + 2 Advices with a penalty (-10 % penalty each advice)

The task is to develop classes `CMailBox` and `CMail`, which simulate a mail box in a mail server.

There will be several classes in the final program. Your task is to develop some of them, the others are already finished in the testing environment. However, you will have to prepare lightweight replacements for the already existing classes to test your implementation. This technique is used in practice to simplify development and testing, it is named "mocking". The "mocked" classes will have the same interface, however, the implementation is simplified to the level needed by testing/development.

`CMailBox`  
This class represents one mail box. The mail box holds incoming mail (i.e. instances of `CMail`), the e-mails can be organized into folders. The `CMailBox` class is to be developed by you.

`CMail`  
This class represents one e-mail. The e-mail is represented by the date/time stamp, the address of the sender, the body of the mail, and an optional attachment. To represent these components, your implementation shall use classes `CTimeStamp`, `std::string`, `CMailBody`, and `CAttach`, respectively. The `CMail` class is to be developed by you.

`CTimeStamp`  
Is a simple container class that represent a time stamp (date and time). This class is implemented in the testing environment, you will have to implement its lightweight variant for your testing. Important: the declaration and the implementation of your "mocked" variant must be kept in the conditional compile block (as shown in the attached file).

`CMailBody`  
Is another container, the class represents mail body. Again, this class is implemented in the testing environment, you will have to implement its lightweight variant for your testing. Important: the declaration and the implementation of your "mocked" variant must be kept in the conditional compile block (as shown in the attached file).

`CAttach`  
This class represents mail attachment. The class is implemented in the testing environment, moreover, a lightweight implementation is present in the attached file. It is important to keep the implementation in the conditional compile block (as in the attached file).

CMailBox
--------

You will implement this class. The declaration and implementation must be OUTSIDE the conditional compile block. The required interface is:

constructor  
creates an empty mailbox (no mail). Moreover, the new mailbox will contain one folder `inbox`.

destructor, copy constructor, operator=  
will have to be implemented if the default is not usable,

`Delivery (mail)`  
The method will be called when a new e-mail is to be stored into the mailbox. The new mail will be copied into the `inbox` folder. The method returns `true` (success), or `false` (failure, however, delivery shall not fail).

`NewFolder (name)`  
The method creates a new folder named `name`. The newly created folder shall be empty. The method returns `true` (success), or `false` (failure, folder of the name already exists). We assume one-level hierarchy of folders, i.e. folders cannot be nested. There are no restrictions on folder names.

`MoveMail (fromFld, toFld)`  
The method moves all e-mails from folder `fromFld` into folder `toFld`. The e-mails are moved, i.e. `fromFld` will be empty after a successful completion. The method returns `true` (success), or `false` (failure, from/to folder does not exist).

`ListMail (fld, from, to)`  
The method returns a list of e-mails selected from folder `fld`, moreover, the e-mails will be returned if the e-mail time stamp fits the time interval (`from - to`, both inclusive). If the folder does not exist, the method returns an empty list.

`ListAddr (from, to)`  
The method returns a set of e-mail addresses. The addresses will be selected from the e-mail that fits into the interval (`from - to`, both inclusive). The method shall search all folders. If no mail fits the time interval, the returned set will be empty.

CMail
-----

You will implement this class. The declaration and implementation must be OUTSIDE the conditional compile block. The required interface is:

constructor  
creates an instance of e-mail based on the parameters. Parameter `attach` may be NULL indicating an e-mail without an attachment,

destructor, copy constructor, operator =, ...  
will be implement if the default are not usable,

access methods (getters)  
for individual fields (time stamp, sender, mail body, attachment),

output operator  
displays the time stamp, sender, mail body and (optionally) the attachment. The objects representing individual fields do support output operators, the fields are to be separated by a single space (with an exception for the attachment, see the exact format in the enclosed archive). Indeed, the operator is not tested in the testing environment, the purpose of the operator is to simplify testing.

CTimeStamp
----------

This class is implemented in the testing environment, you will implement is as a "mock" class. Your implementation MUST be hidden in the conditional compile block. The interface is:

constructor  
creates an instance of the object based on year/month/day/hour/minute/second parameters,

Compare (x)  
The method compares the instance and parameter `x`. Return value is a negative number (instance is smaller than `x`), zero (instances represent identical time stamps), or positive (the instance is bigger than `x`).

output operator  
displays the time stamp in format YYYY-MM-DD HH24:MI:SS.

other  
Your mock class will be used for your tests. Your implementation will not be used in the Progtest environment. You may add further methods to your "mock" implementation of `CTimeStamp`, however, the extra interface will not be present in Progtest. Therefore, we recommend you to keep this guaranteed interface without any modifications.

CMailBody
---------

This class is implemented in the testing environment, you will implement is as a "mock" class. Your implementation MUST be hidden in the conditional compile block. The interface is:

constructor  
creates an instance of the class, based on the length/content parameters,

destructor, copy constructor, operator =, ...  
the instances must correctly handle copying/moving,

output operator  
is provided in the attached file. The operator is intended for debugging only, it is not actually tested,

other  
Your mock class will be used for your tests. Your implementation will not be used in the Progtest environment. You may add further methods to your "mock" implementation of `CMailBody`, however, the extra interface will not be present in Progtest. Therefore, we recommend you to keep this guaranteed interface without any modifications. Moreover, the implementation in Progtest uses a hack which disables dynamically created instances of `CMailBody` (`new CMailBody` does not work, do not use it).

CAttach
-------

This class is implemented in the attached source file. The implementation is included in the conditional compile block. The class represents an e-mail attachment. Since e-mail attachments are quite long and are often sent to many addresses, the implementation is designed such that the attachment objects use counted references. The interface is:

constructor  
creates an instance based on the contents (simplified). Next, the constructor initializes `m_RefCnt`, this member counts the references. The instance will be deleted when the number of references drops to 0 (m\_RefCnt==0).

`AddRef`  
This method increases the number of references. When a reference to the object is created (such as when the constructor of `CMail` stores the pointer, or when getter `Attach` returns the reference), this method is to be called to increase the counter to match the number of actual references.

`Release`  
The method decreases the reference count. When the reference count drops to zero, the instance commits a suicide. The method will be when a reference to the instance is about to vanish, such as in the destructor of `CMail`. Similarly, `Release` needs to be called when a reference to attachment object (previously obtained via getter `Attach`) is to vanish.

destructor  
releases the resources allocated in the instance (simplified in the delivered implementation). Please note the destructor is private. The private destructor means two things. First, instances of `CAttach` cannot be allocated statically. Second, instances of `CAttach` cannot be deleted directly by `delete`. There is a good reason: an instance (possibly referenced from many other objects) cannot be deleted. Instead, the AddRef/Release mechanism must be used (thus the users of `CAttach` must follow the counted references).

copy constructor, operator =, ...  
these are private, thus cannot be used by other parts of the program.

output operator  
is delivered in the attached file, again, it is intended for debugging and testing.

mutable m\_RefCnt  
the mutable keyword allows modifications of `m_RefCnt` even from `const` methods.

other  
The delivered class is similar to the implementation actually used in the Progtest environment. You may add further methods to the implementation of `CAttach`, however, the extra interface will not be present in Progtest. Therefore, we recommend you to keep this delivered interface without any modifications.

Submit a source file with your implementation of the required classes (`CMailBox`, `CMail`). The classes must follow the public interface. If there is a mismatch in the interface, the compilation will fail. You may extend the interface and add you auxiliary methods and member variables (both public and private, although private are preferred). The submitted file must include both declarations as well as implementation of the class (the methods may be implemented inline but do not have to). The submitted file shall not contain anything unnecessary. In particular, if the file contains `main`, your tests, classes `CTimeStamp`, `CMailBody`, `CAttach`, or any \#include definitions, please, keep them in a conditional compile block. Use the attached source as a basis for your implementation. If the preprocessor definitions are preserved, the file may be submitted to Progtest.

Use STL to develop the required classes. Use appropriate STL containers in your implementation. Your implementation shall focus on the speed when accessing folders, accessing e-mail by date/time, and shall avoid unnecessary copying when moving e-mail among folders. There are mandatory, optional, and bonus tests in this homework. Correct naive solution passes the mandatory tests. To pass the optional tests, your implementation must handle many e-mails (minimize the number of date/time comparisons). To pass the bonus test, your implementation must allow fast moving of e-mail among the folders (C++11 move constructors/operators= are useful, moreover, `noexcept` must be used).

Solution of this homework cannot be used for code review (the interface is given, there is no program design and OOP style to assess).

**Sample data:**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskS&Cou=293&Tgr=1851&Tsk=1064)

 **Reference**

 

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Zakladni test s parametry podle ukazky': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 4.000 s)
        -   Peak mem usage: 12812 KiB (limit: 23126 KiB)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Test nahodnymi daty': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.280 s (limit: 4.000 s)
        -   Peak mem usage: 13860 KiB (limit: 23126 KiB)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Test rychlosti (mnoho e-mailu)': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 2.309 s (limit: 10.000 s)
        -   Peak mem usage: 19464 KiB (limit: 42657 KiB)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Test rychlosti (mnoho presunu)': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 4.633 s (limit: 15.000 s)
        -   Peak mem usage: 56112 KiB (limit: 111017 KiB)
        -   Bonus test - success, evaluation: 130.00 %
    -   Overall ratio: 130.00 % (= 1.00 \* 1.00 \* 1.00 \* 1.30)
-   Total percent: 130.00 %
-   Early submission bonus: 0.72
-   Total points: 1.30 \* ( 7.15 + 0.72 ) = 10.22

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**11**|--|--|--|
|Lines of code:|**68**|6.18 ± 2.82|11|`operator =(const CMail &)`|
|Cyclomatic complexity:|**19**|1.73 ± 1.35|5|`operator =(const CMail &)`|

**9**

**2020-04-12 02:16:55**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1851&Tsk=1064&Sub=1157465)

**Submission status:**

Evaluated

 

**Evaluation:**

7.8650

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 4.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.105 s (limit: 4.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Speed test (many e-mails)': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 2.745 s (limit: 6.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test (many moves)': Abnormal program termination (Time limit exceeded)
        -   Cumulative test time exceeded, killed after:: 15.022 s (limit: 15.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 100.00 % (= 1.00 \* 1.00 \* 1.00)
-   Total percent: 100.00 %
-   Early submission bonus: 0.72
-   Total points: 1.00 \* ( 7.15 + 0.72 ) = 7.87

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**31**|--|--|--|
|Lines of code:|**270**|8.71 ± 16.83|97|`main`|
|Cyclomatic complexity:|**46**|1.48 ± 0.91|4|`CMailBox::MoveMail`|

**8**

**2020-04-12 01:50:10**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1851&Tsk=1064&Sub=1157451)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Compile in 'basic' mode failed. [[Unlock advice (2070 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1851&Tsk=1064&Unl=C1164202'))
-   Total percent: 0.00 %
-   Early submission bonus: 0.72
-   Total points: 0.00 \* ( 7.15 + 0.72 ) = 0.00

**7**

**2020-04-12 01:30:39**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1851&Tsk=1064&Sub=1157439)

**Submission status:**

Evaluated

 

**Evaluation:**

7.8650

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 4.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.087 s (limit: 4.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Speed test (many e-mails)': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 2.667 s (limit: 6.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test (many moves)': Abnormal program termination (Time limit exceeded)
        -   Cumulative test time exceeded, killed after:: 15.011 s (limit: 15.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 100.00 % (= 1.00 \* 1.00 \* 1.00)
-   Total percent: 100.00 %
-   Early submission bonus: 0.72
-   Total points: 1.00 \* ( 7.15 + 0.72 ) = 7.87

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**31**|--|--|--|
|Lines of code:|**270**|8.71 ± 16.83|97|`main`|
|Cyclomatic complexity:|**46**|1.48 ± 0.91|4|`CMailBox::MoveMail`|

**6**

**2020-04-11 21:53:25**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1851&Tsk=1064&Sub=1157223)

**Submission status:**

Evaluated

 

**Evaluation:**

7.8650

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 4.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.081 s (limit: 4.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Speed test (many e-mails)': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 2.699 s (limit: 6.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Speed test (many moves)': Abnormal program termination (Time limit exceeded)
        -   Cumulative test time exceeded, killed after:: 15.016 s (limit: 15.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 100.00 % (= 1.00 \* 1.00 \* 1.00)
-   Total percent: 100.00 %
-   Early submission bonus: 0.72
-   Total points: 1.00 \* ( 7.15 + 0.72 ) = 7.87

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**31**|--|--|--|
|Lines of code:|**271**|8.74 ± 16.85|97|`main`|
|Cyclomatic complexity:|**46**|1.48 ± 0.91|4|`CMailBox::MoveMail`|

**5**

**2020-04-11 18:56:03**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1851&Tsk=1064&Sub=1157028)

**Submission status:**

Evaluated

 

**Evaluation:**

3.9325

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 4.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 1.727 s (limit: 4.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Speed test (many e-mails)': Abnormal program termination (Time limit exceeded)
        -   Cumulative test time exceeded, killed after:: 6.009 s (limit: 6.000 s)
        -   Optional test failed, evaluation: 50.00 %
    -   Test 'Speed test (many moves)': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 50.00 % (= 1.00 \* 1.00 \* 0.50)
-   Total percent: 50.00 %
-   Early submission bonus: 0.72
-   Total points: 0.50 \* ( 7.15 + 0.72 ) = 3.93

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**30**|--|--|--|
|Lines of code:|**261**|8.70 ± 17.14|97|`main`|
|Cyclomatic complexity:|**46**|1.53 ± 1.06|5|`CMailBox::MoveMail`|

**4**

**2020-04-11 04:15:11**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1851&Tsk=1064&Sub=1156569)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 4.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test': Abnormal program termination (Time limit exceeded)
        -   Cumulative test time exceeded, killed after:: 4.006 s (limit: 4.000 s)
        -   Mandatory test failed, evaluation: 0.00 %
    -   Overall ratio: 0.00 % (= 1.00 \* 0.00)
-   Total percent: 0.00 %
-   Early submission bonus: 0.72
-   Total points: 0.00 \* ( 7.15 + 0.72 ) = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**28**|--|--|--|
|Lines of code:|**255**|9.11 ± 17.85|97|`main`|
|Cyclomatic complexity:|**45**|1.61 ± 1.21|6|`CMailBox::MoveMail`|

**3**

**2020-04-10 21:53:14**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1851&Tsk=1064&Sub=1156384)

**Submission status:**

Evaluated

 

**Evaluation:**

3.9325

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 4.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.199 s (limit: 4.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Speed test (many e-mails)': Abnormal program termination (Time limit exceeded)
        -   Cumulative test time exceeded, killed after:: 6.007 s (limit: 6.000 s)
        -   Optional test failed, evaluation: 50.00 %
    -   Test 'Speed test (many moves)': Not tested
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 50.00 % (= 1.00 \* 1.00 \* 0.50)
-   Total percent: 50.00 %
-   Early submission bonus: 0.72
-   Total points: 0.50 \* ( 7.15 + 0.72 ) = 3.93

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**29**|--|--|--|
|Lines of code:|**254**|8.76 ± 17.41|97|`main`|
|Cyclomatic complexity:|**48**|1.66 ± 1.35|6|`CMailBox::MoveMail`|

**2**

**2020-04-10 02:53:43**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1851&Tsk=1064&Sub=1156005)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Compile in 'basic' mode failed. [[Unlock advice (1854 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1851&Tsk=1064&Unl=C1162770'))
-   Total percent: 0.00 %
-   Early submission bonus: 0.72
-   Total points: 0.00 \* ( 7.15 + 0.72 ) = 0.00

**1**

**2020-04-10 02:49:14**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=293&Tgr=1851&Tsk=1064&Sub=1156004)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Compile in 'basic' mode failed. [[Unlock advice (1856 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=293&Tgr=1851&Tsk=1064&Unl=C1162769'))
-   Total percent: 0.00 %
-   Early submission bonus: 0.72
-   Total points: 0.00 \* ( 7.15 + 0.72 ) = 0.00

