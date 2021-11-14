||
|[ProgTest](https://progtest.fit.cvut.cz/index.php?X=Main)  ►  [BIE-PA2 (18/19 LS)](https://progtest.fit.cvut.cz/index.php?X=Course&Cou=264)  ►  [Homework 05](https://progtest.fit.cvut.cz/index.php?X=TaskGrp&Cou=264&Tgr=1698)  ►  **Mail log**|[Logout](https://progtest.fit.cvut.cz/index.php?X=Logout)|

||
|**Mail log**|

**Submission deadline:**

**2019-04-21 23:59:59**

 

**Late submission with malus:**

**2019-06-30 23:59:59** (Late submission malus: 100.0000 %)

**Evaluation:**

**5.0000**

**Max. assessment:**

**5.0000** (Without bonus points)

**Submissions:**

14 / 20 Free retries + 20 Penalized retries (-2 % penalty each retry)

**Advices:**

1 / 2 Advices for free + 2 Advices with a penalty (-10 % penalty each advice)

The task is to develop class `CMailLog` which is capable of processing mailer daemon logs.

When analyzing e-mail traffic, it is common to search for an email (who sent it, when it was delivered, ...). To achieve this, mail log must be parsed first. Class `CMailLog` will be able to parse the log and solve some searches.

The input to the parser is a mail log. The format is:

    month day year hour:minute:sec relay_name mailID: message

for instance:

    Mar 29 2013 14:55:31.456 relay.fit.cvut.cz KhdfEjkl247D: from=PR-department@fit.cvut.cz
    Mar 29 2013 14:50:23.233 relay.fit.cvut.cz ADFger72343D: mail undeliverable
    Mar 29 2013 14:58:32.563 relay.fit.cvut.cz KhdfEjkl247D: subject=Meeting this afternoon
    Mar 29 2013 15:04:18.345 relay.fit.cvut.cz KhdfEjkl247D: to=CEO@fit.cvut.cz

The fields are self-explanatory: month (English notation, 3 letter acronym, first in capital), day of month, year, hour, minute, second (with milliseconds), mail server DNS name, e-mail identifier (letters and digits) and a message. The mail server produces a message every time something important happens (e.g., an email is received from a client, an email is delivered to the mailbox, ...). It is common for one email to generate several log messages, however, the messages share the same mail identifier.

The aim is to match sender, subject, and receiver(s) for each e-mail delivered. Thus, we will only focus on messages starting with `from=`, `subject=`, or `to=`. We will ignore all other messages. If the log does not provide `subject=` for an e-mail, set the email subject to an empty string.

The sample above demonstrates that the log messages are nearly ordered, however there may be some lines that violate the ordering. The out-of-order messages are the messages with the `to=` message. The log first provides `from=`, then `subject=`, and finally one or more `to=`, this relative order is guaranteed for each e-mail. Next, the messages are interleaved for all e-mails being processed. Finally, there may be several `to=` messages for one e-mail. In this case, there will be several records, one for each addressee (possibly with different timestamps).

The `CMailLog` class will parse the above log. It must integrate into existing classes already present in the testing environment (classes `CTimeStamp` and `CMail`). Since the latter two classes are already implemented in the testing environment, they are presented in a conditional compile block. You do not have to implement the two classes to pass the test in Progtest, however, you will have to implement them at least partially to test your implementation ("mocking"). Please keep in mind these two classes must be kept in the conditional compile block, otherwise the program will not compile. On the other hand, you have to fully implement `CMailLog` class and keep this class outside the conditional compile block.

    class CTimeStamp
    {
      public:
        CTimeStamp ( int       year,
                     int       month,
                     int       day,
                     int       hour,
                     int       minute,
                     double    sec );
                                                                 
        int Compare ( const CTimeStamp & x ) const;
        friend ostream & operator << ( ostream     & os,
                                       const CTimeStamp & x );
      private:
        ...
    };

    class CMail
    {
      public:
        CMail  ( const CTimeStamp & timeStamp,
                 const string     & from,
                 const string     & to,
                 const string     & subject );
        int CompareByTime ( const CTimeStamp & x ) const 
        int CompareByTime ( const CMail      & x ) const 
        const string & From ( void ) const;
        const string & To   ( void ) const;
        const string & Subject ( void ) const;
        const CTimeStamp & TimeStamp ( void ) const;
        friend ostream & operator << ( ostream     & os,
                                       const CMail & x );
      private:
        ...
    };
    #endif /* __PROGTEST__ */   

    class CMailLog      
    {
      public: 
        // default constructor
        // destructor
        int            ParseLog          ( istream & in );
        list<CMail>    ListMail          ( const CTimeStamp & from,
                                           const CTimeStamp & to ) const;
        set<string>    ActiveUsers       ( const CTimeStamp & from,
                                           const CTimeStamp & to ) const;
      private:
        ...
    };

CTimeStamp
----------

This class implements a timestamp. The interface is:

-   constructor which fills-in the member variables,
-   overloaded output operator which displays the timestamp in ISO format (YYYY-MM-DD HH24:MI:SS.UUU). This operator is useful for testing and debugging only,
-   comparison method `Compare`. The result `a . Compare   (b)` is either a positive number for `a > b`, 0 for `a ==   b`, or a negative number for `a < b`.

CMail
-----

This class represents one e-mail record. The interface is:

-   constructor which fills-in member variables,
-   methods to retrieve the values (getters) - `From`, `Subject`, `To`, and `TimeStamp`,
-   methods to compare the timestamps, the result value corresponds to the result returned by `CTimeStamp::Compare`,
-   overloaded output operator (testing and debugging).

CMailLog
--------

This class is the mail log processor itself. The interface is:

-   default constructor which creates an empty instance,
-   destructor to free allocated resources (if any),
-   method `ParseLog`, which processes the log. The log is accessible via input stream. The method will read the stream and store the e-mail records (see above). If there is an invalid log entry (an invalid log line), the method skips the line and proceeds with the next log line. The return value is the total number of e-mail records reconstructed from the log (i.e., not the number of log lines processed),
-   method `ListMail` returns a list of e-mail records that were delivered in the time interval specified (both boundaries inclusive). The list returned must be sorted in an ascending order (order by delivery timestamp). If there are two e=mails with identical delivery timestamp, then the relative order from the log must be preserved,
-   method `ActiveUsers` considers the mail records that were delivered in the time interval specified (both boundaries inclusive). The return value is the set of all e-mail addresses that participated in these e-mails (both senders and receivers).

Submit a source file with your `CMailLog` implementation. The class must follow the public interface above. If there is a mismatch in the interface, the compilation will fail. You may extend the interface and add you auxiliary methods and member variables (both public and private, although private are preferred). The submitted file must include both declarations as well as implementation of the class (the methods may be implemented inline but do not have to). The submitted file shall not contain anything unnecessary. In particular, if the file contains `main`, your tests, or any \#include definitions, please, keep them in a conditional compile block. Use the template above as a basis for your implementation. If the preprocessor definitions are preserved, the file maybe submitted to Progtest.

Use STL to develop the `CMailLog` class. Think of a solution that processes the log and searches the e-mail records faster than `O(n)`.

Your code will be compiled in a separate namespace to avoid possible identifier conflicts. On the other hand, classes `CTimeStamp` and `CMail` are compiled in a parental namepace. This way, the classes are available for both your code (in your namespace) and reference code (in its namespace). The attached code includes directive `namespace MysteriousNamespace`, this simulates the compilation in the testing environment (however, the actual name of your namespace will be random). Your namespace must implement class `CMailLog` and its support classes and functions. On the other hand, code in your namespace is not supposed to extend the interface of the existing classes `CTimeStamp` and `CMail` (such code would be appropriate in the parental namespace). Do not try to extend the interface of classes `CTimeStamp` and `CMail` from yur namespace, just use the existing methods.

The solution of this homework cannot be used for code review.

**Sample data:**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskS&Cou=264&Tgr=1698&Tsk=1601)

 **Reference**

 

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Zakladni test s parametry podle ukazky': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 5.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Test nahodnymi daty': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.815 s (limit: 5.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Test rychlosti': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 1.759 s (limit: 5.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Overall ratio: 100.00 % (= 1.00 \* 1.00 \* 1.00)
-   Total percent: 100.00 %
-   Early submission bonus: 0.50
-   Total points: 1.00 \* ( 5.00 + 0.50 ) = 5.50

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**19**|--|--|--|
|Lines of code:|**225**|11.84 ± 9.64|43|`CMailLog::parseRow`|
|Cyclomatic complexity:|**51**|2.68 ± 3.01|12|`CMailLog::parseRow`|

**14**

**2019-04-21 05:33:20**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1698&Tsk=1601&Sub=1075106)

**Submission status:**

Evaluated

 

**Evaluation:**

5.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 5.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.814 s (limit: 5.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Speed test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 1.558 s (limit: 5.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Overall ratio: 100.00 % (= 1.00 \* 1.00 \* 1.00)
-   Total percent: 100.00 %
-   Total points: 1.00 \* 5.00 = 5.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**21**|--|--|--|
|Lines of code:|**241**|11.48 ± 17.36|72|`MysteriousNamespace::CMailLog::ParseLog`|
|Cyclomatic complexity:|**52**|2.48 ± 4.26|21|`MysteriousNamespace::CMailLog::ParseLog`|

**13**

**2019-04-21 01:19:58**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1698&Tsk=1601&Sub=1075072)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': failed
        -   result: 66.67 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 5.000 s)
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (34 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1698&Tsk=1601&Unl=L3260906'))
        -   Failed (invalid output) [[Unlock advice (34 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1698&Tsk=1601&Unl=L3260907'))
    -   Overall ratio: 0.00 %
-   Total percent: 0.00 %
-   Total points: 0.00 \* 5.00 = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**21**|--|--|--|
|Lines of code:|**245**|11.67 ± 18.04|76|`MysteriousNamespace::CMailLog::ParseLog`|
|Cyclomatic complexity:|**53**|2.52 ± 4.47|22|`MysteriousNamespace::CMailLog::ParseLog`|

**12**

**2019-04-21 00:58:29**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1698&Tsk=1601&Sub=1075058)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': failed
        -   result: 66.67 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 5.000 s)
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (34 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1698&Tsk=1601&Unl=L3260868'))
        -   Failed (invalid output) [[Unlock advice (34 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1698&Tsk=1601&Unl=L3260869'))
    -   Overall ratio: 0.00 %
-   Total percent: 0.00 %
-   Total points: 0.00 \* 5.00 = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**21**|--|--|--|
|Lines of code:|**244**|11.62 ± 17.87|75|`MysteriousNamespace::CMailLog::ParseLog`|
|Cyclomatic complexity:|**53**|2.52 ± 4.47|22|`MysteriousNamespace::CMailLog::ParseLog`|

**11**

**2019-04-21 00:39:50**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1698&Tsk=1601&Sub=1075045)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': failed
        -   result: 66.67 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 5.000 s)
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (34 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1698&Tsk=1601&Unl=L3260840'))
        -   Failed (invalid output) [[Unlock advice (34 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1698&Tsk=1601&Unl=L3260841'))
    -   Overall ratio: 0.00 %
-   Total percent: 0.00 %
-   Total points: 0.00 \* 5.00 = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**21**|--|--|--|
|Lines of code:|**242**|11.52 ± 17.53|73|`MysteriousNamespace::CMailLog::ParseLog`|
|Cyclomatic complexity:|**52**|2.48 ± 4.26|21|`MysteriousNamespace::CMailLog::ParseLog`|

**10**

**2019-04-20 21:53:49**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1698&Tsk=1601&Sub=1074958)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': failed
        -   result: 66.67 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 5.000 s)
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (34 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1698&Tsk=1601&Unl=L3260656'))
        -   Failed (invalid output) [[Unlock advice (34 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1698&Tsk=1601&Unl=L3260657'))
    -   Overall ratio: 0.00 %
-   Total percent: 0.00 %
-   Total points: 0.00 \* 5.00 = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**21**|--|--|--|
|Lines of code:|**322**|15.33 ± 23.76|101|`MysteriousNamespace::CMailLog::ParseLog`|
|Cyclomatic complexity:|**73**|3.48 ± 6.60|30|`MysteriousNamespace::CMailLog::ParseLog`|

**9**

**2019-04-20 21:04:44**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1698&Tsk=1601&Sub=1074936)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': failed
        -   result: 66.67 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 5.000 s)
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (34 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1698&Tsk=1601&Unl=L3260565'))
        -   Failed (invalid output) [[Unlock advice (34 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1698&Tsk=1601&Unl=L3260566'))
    -   Overall ratio: 0.00 %
-   Total percent: 0.00 %
-   Total points: 0.00 \* 5.00 = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**21**|--|--|--|
|Lines of code:|**251**|11.95 ± 16.71|67|`MysteriousNamespace::CMailLog::ParseLog`|
|Cyclomatic complexity:|**54**|2.57 ± 4.32|21|`MysteriousNamespace::CMailLog::ParseLog`|

**8**

**2019-04-20 21:02:17**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1698&Tsk=1601&Sub=1074934)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': failed
        -   result: 33.33 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 5.000 s)
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (34 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1698&Tsk=1601&Unl=L3260561'))
        -   Failed (invalid output) [[Unlock advice (34 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1698&Tsk=1601&Unl=L3260562'))
        -   Failed (invalid output) [[Unlock advice (37 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1698&Tsk=1601&Unl=L3260563'))
        -   Failed (invalid output) [[Unlock advice (37 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1698&Tsk=1601&Unl=L3260564'))
    -   Overall ratio: 0.00 %
-   Total percent: 0.00 %
-   Total points: 0.00 \* 5.00 = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**21**|--|--|--|
|Lines of code:|**251**|11.95 ± 16.71|67|`MysteriousNamespace::CMailLog::ParseLog`|
|Cyclomatic complexity:|**58**|2.76 ± 4.46|21|`MysteriousNamespace::CMailLog::ParseLog`|

**7**

**2019-04-20 20:45:40**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1698&Tsk=1601&Sub=1074922)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': failed
        -   result: 33.33 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 5.000 s)
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (34 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1698&Tsk=1601&Unl=L3260549'))
        -   Failed (invalid output) [[Unlock advice (34 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1698&Tsk=1601&Unl=L3260550'))
        -   Failed (invalid output) [[Unlock advice (37 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1698&Tsk=1601&Unl=L3260551'))
        -   Failed (invalid output) [[Unlock advice (37 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1698&Tsk=1601&Unl=L3260552'))
    -   Overall ratio: 0.00 %
-   Total percent: 0.00 %
-   Total points: 0.00 \* 5.00 = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**21**|--|--|--|
|Lines of code:|**322**|15.33 ± 23.76|101|`MysteriousNamespace::CMailLog::ParseLog`|
|Cyclomatic complexity:|**77**|3.67 ± 6.81|30|`MysteriousNamespace::CMailLog::ParseLog`|

**6**

**2019-04-19 02:47:15**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1698&Tsk=1601&Sub=1074348)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': failed
        -   result: 33.33 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 5.000 s)
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (34 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1698&Tsk=1601&Unl=L3258514'))
        -   Failed (invalid output) [[Unlock advice (34 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1698&Tsk=1601&Unl=L3258515'))
        -   Failed (invalid output) [[Unlock advice (37 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1698&Tsk=1601&Unl=L3258516'))
        -   Failed (invalid output) [[Unlock advice (37 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1698&Tsk=1601&Unl=L3258517'))
    -   Overall ratio: 0.00 %
-   Total percent: 0.00 %
-   Total points: 0.00 \* 5.00 = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**21**|--|--|--|
|Lines of code:|**325**|15.48 ± 23.70|101|`MysteriousNamespace::CMailLog::ParseLog`|
|Cyclomatic complexity:|**79**|3.76 ± 6.79|30|`MysteriousNamespace::CMailLog::ParseLog`|

**5**

**2019-04-19 01:03:27**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1698&Tsk=1601&Sub=1074343)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': failed
        -   result: 33.33 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 5.000 s)
        -   Mandatory test failed, evaluation: 0.00 %
        -   Failed (invalid output) [[Unlock advice (34 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1698&Tsk=1601&Unl=L3258507'))
        -   Failed (invalid output) [[Unlock advice (34 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1698&Tsk=1601&Unl=L3258508'))
        -   Failed (invalid output) [[Unlock advice (37 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1698&Tsk=1601&Unl=L3258509'))
        -   Failed (invalid output) [[Unlock advice (37 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1698&Tsk=1601&Unl=L3258510'))
    -   Overall ratio: 0.00 %
-   Total percent: 0.00 %
-   Total points: 0.00 \* 5.00 = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**21**|--|--|--|
|Lines of code:|**325**|15.48 ± 23.70|101|`MysteriousNamespace::CMailLog::ParseLog`|
|Cyclomatic complexity:|**79**|3.76 ± 6.79|30|`MysteriousNamespace::CMailLog::ParseLog`|

**4**

**2019-04-18 03:04:42**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1698&Tsk=1601&Sub=1074126)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -    Compile in 'basic' mode failed.

        ``` {#pre_C1082886 style="display: none"}
        In file included from testbed.cpp:343:0:
        tested: In member function ‘int student_f5e726bf6ac82e4e296e3d64c477e7d0::CMailLog::ParseLog(std::istream&)’:
        tested:234:66: error: no matching function for call to ‘CMail::CMail(CTimeStamp&, std::__cxx11::string&, std::__cxx11::string&, std::__cxx11::string&, std::__cxx11::string&)’
                         CMail email ( time , message , empty , empty , id);
                                                                          ^
        testbed.cpp:88:20: note: candidate: CMail::CMail(const CTimeStamp&, const string&, const string&, const string&)
                            CMail                                   ( const CTimeStamp & timeStamp,
                            ^~~~~
        testbed.cpp:88:20: note:   candidate expects 4 arguments, 5 provided
        testbed.cpp:84:7: note: candidate: CMail::CMail(const CMail&)
         class CMail
               ^~~~~
        testbed.cpp:84:7: note:   candidate expects 1 argument, 5 provided
        testbed.cpp:84:7: note: candidate: CMail::CMail(CMail&&)
        testbed.cpp:84:7: note:   candidate expec

        <skipping 16417 B>

        o member named ‘min’; did you mean ‘m_Min’?
                     time += ( e->TimeStamp().y  * 365 * 24 * 60 * 60 ) + ( e->TimeStamp().mon * 30 * 24 * 60 * 60 ) + ( e->TimeStamp().d * 24 * 60 * 60 ) + ( e->TimeStamp().h * 60 * 60 ) + ( e->TimeStamp().min * 60 ) + e->TimeStamp().s;
                                                                                                                                                                                                               ^~~
        tested:406:227: error: ‘const class CTimeStamp’ has no member named ‘s’
                     time += ( e->TimeStamp().y  * 365 * 24 * 60 * 60 ) + ( e->TimeStamp().mon * 30 * 24 * 60 * 60 ) + ( e->TimeStamp().d * 24 * 60 * 60 ) + ( e->TimeStamp().h * 60 * 60 ) + ( e->TimeStamp().min * 60 ) + e->TimeStamp().s;
                                                                                                                                                                                                                                           ^
        ```

-   Total percent: 0.00 %
-   Total points: 0.00 \* 5.00 = 0.00

**3**

**2019-04-18 03:02:20**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1698&Tsk=1601&Sub=1074125)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Compile in 'basic' mode failed. [[Unlock advice (2070 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1698&Tsk=1601&Unl=C1082885'))
-   Total percent: 0.00 %
-   Total points: 0.00 \* 5.00 = 0.00

**2**

**2019-04-18 03:01:01**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1698&Tsk=1601&Sub=1074124)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Compile in 'basic' mode failed. [[Unlock advice (2070 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1698&Tsk=1601&Unl=C1082884'))
-   Total percent: 0.00 %
-   Total points: 0.00 \* 5.00 = 0.00

**1**

**2019-04-18 02:56:26**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1698&Tsk=1601&Sub=1074122)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Compile in 'basic' mode failed. [[Unlock advice (2070 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1698&Tsk=1601&Unl=C1082882'))
-   Total percent: 0.00 %
-   Total points: 0.00 \* 5.00 = 0.00

