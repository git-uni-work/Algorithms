||
|[ProgTest](https://progtest.fit.cvut.cz/index.php?X=Main)  ►  [BIE-PA2 (18/19 LS)](https://progtest.fit.cvut.cz/index.php?X=Course&Cou=264)  ►  [Homework 07](https://progtest.fit.cvut.cz/index.php?X=TaskGrp&Cou=264&Tgr=1702)  ►  **Routing**|[Logout](https://progtest.fit.cvut.cz/index.php?X=Logout)|

||
|**Routing**|

**Submission deadline:**

**2019-05-05 23:59:59**

 

**Late submission with malus:**

**2019-06-30 23:59:59** (Late submission malus: 100.0000 %)

**Evaluation:**

**5.0000**

**Max. assessment:**

**5.0000** (Without bonus points)

**Submissions:**

16 / 20 Free retries + 20 Penalized retries (-2 % penalty each retry)

**Advices:**

2 / 2 Advices for free + 2 Advices with a penalty (-10 % penalty each advice)

The task is to develop a generic class `CRoute` that can find a path connecting two given places.

We assume a map with nodes (e.g. cities, computers, ...) and edges that connect node pairs (e.g. roads, railroads, network links, ...). Class `CRoute` stores the map. Since the map is general, the data types describing nodes and edges will be implemented as generic parameters.

The class will provide a method to insert edges and a method to search a path. The exact interface is:

default constructor  
prepares an empty `CRoute` instance.

method Add (u1, u2, e)  
this method adds a new edge connecting nodes `u1` and `u2`. The third parameter `e` is the description of the edge, e.g. the speed of the line, type of road, ... The edge is assume two-way edge.

method Find (u1, u2, [,f] )  
this method will search the map to find a path from `u1` to `u2`. The result is a list (`std::list`) with the nodes along the path from `u1` to `u2`. The first node in the list shall be `u1`, the last `u2`.

It may be the case that there is no path connecting `u1` to `u2`. In that case the method throws `NoRouteException`. Moreover, there may exist many different ways to get from `u1` to `u2`. In that case, the method returns the shortest path (the path with the lowest number of intermediate nodes). Finally, if there are several options of the path with the lowest number of intermediate nodes, the result may be any of them.

The method shall be provided in two variants: with and without the third optional parameter `f`. If present, the third parameter acts as a filter that enables/disables individual edges. The filter is provided in the form of a function/functor/lambda expression. It shall be applied to the edges. If the filter returns `false`, the edge must not be included in the resulting path. Thus, the filter may be used to remove certain edges from the search, i.e. we may consider only edges with some properties (speed, quality, ...).

Generic parameter `_T` is the data type that represents nodes. Your implementation may use the following operations with \_T:

-   copy constructor,
-   operator =,
-   relational operators (==, !=, \<, \<=, \> \>=),
-   destructor,
-   output operator \<\<.
-   Further operations may exist, however, they are not guaranteed.

Generic parameter `_T` is the data type that represents edges. Your implementation may use the following operations with \_E:

-   copy constructor,
-   operator =,
-   destructor.
-   Further operations may exist, however, they are not guaranteed.

* * * * *

Submit a source file with the implementation of the `CRoute` class template and `NoRouteException` exception class. Use the attached source code as a basis for your implementation. Please preserve the conditional compile directives - if present, the source may be locally tested and submitted to Progtest without manual modifications.

The assessment is divided into mandatory and optional tests. The mandatory tests use only small maps with small number of nodes. The optional test tests maps with high number of nodes, thus the implementation requires some efficient data structures to finish in the time limit. A significant penalty will apply if the optional test is not passed.

Use BFS (breadth first search) algorithm to search the map. Further inspiration: PA1, proseminar \#11, labyrinth problem.

The example source code may be found in the attached archive.

The solution of this homework cannot be used for code review.

**Sample data:**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskS&Cou=264&Tgr=1702&Tsk=1208)

 **Reference**

 

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Zakladni test s parametry podle ukazky': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 5.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Test nahodnymi daty': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.090 s (limit: 5.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Test rychlosti': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 2.590 s (limit: 8.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Overall ratio: 100.00 % (= 1.00 \* 1.00 \* 1.00)
-   Total percent: 100.00 %
-   Early submission bonus: 0.50
-   Total points: 1.00 \* ( 5.00 + 0.50 ) = 5.50

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**13**|--|--|--|
|Lines of code:|**155**|11.92 ± 15.52|51|`main`|
|Cyclomatic complexity:|**25**|1.92 ± 1.86|8|`CRoute::Find`|

**16**

**2019-05-05 22:11:48**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1702&Tsk=1208&Sub=1078643)

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
        -   Total run time: 0.075 s (limit: 5.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Speed test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 2.516 s (limit: 8.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Overall ratio: 100.00 % (= 1.00 \* 1.00 \* 1.00)
-   Advices used: 2
-   Penalty due to advices: None (2 \<= 2 limit)
-   Total percent: 100.00 %
-   Total points: 1.00 \* 5.00 = 5.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**13**|--|--|--|
|Lines of code:|**154**|11.85 ± 20.27|62|`CRoute::Find`|
|Cyclomatic complexity:|**32**|2.46 ± 3.67|15|`CRoute::Find`|

**15**

**2019-05-05 22:09:57**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1702&Tsk=1208&Sub=1078640)

**Submission status:**

Evaluated

 

**Evaluation:**

4.1225

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 5.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test': success
        -   result: 97.00 %, required: 50.00 %
        -   Total run time: 0.085 s (limit: 5.000 s)
        -   Mandatory test success, evaluation: 97.00 %
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269284'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269285'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269286'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269287'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269288'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269289'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269290'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269291'))
    -   Test 'Speed test': success
        -   result: 85.00 %, required: 50.00 %
        -   Total run time: 2.549 s (limit: 8.000 s)
        -   Optional test success, evaluation: 85.00 %
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269292'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269293'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269294'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269295'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269296'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269297'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269298'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269299'))
    -   Overall ratio: 82.45 % (= 1.00 \* 0.97 \* 0.85)
-   Advices used: 2
-   Penalty due to advices: None (2 \<= 2 limit)
-   Total percent: 82.45 %
-   Total points: 0.82 \* 5.00 = 4.12

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**13**|--|--|--|
|Lines of code:|**154**|11.85 ± 20.27|62|`CRoute::Find`|
|Cyclomatic complexity:|**31**|2.38 ± 3.41|14|`CRoute::Find`|

**14**

**2019-05-05 22:05:42**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1702&Tsk=1208&Sub=1078637)

**Submission status:**

Evaluated

 

**Evaluation:**

4.1275

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 5.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test': success
        -   result: 98.27 %, required: 50.00 %
        -   Total run time: 0.082 s (limit: 5.000 s)
        -   Mandatory test success, evaluation: 98.27 %
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269252'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269253'))
        -    Failed (invalid output)

                 Invalid exception thrown

        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269255'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269256'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269257'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269258'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269259'))

    -   Test 'Speed test': success
        -   result: 84.00 %, required: 50.00 %
        -   Total run time: 2.254 s (limit: 8.000 s)
        -   Optional test success, evaluation: 84.00 %
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269260'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269261'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269262'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269263'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269264'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269265'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269266'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269267'))
    -   Overall ratio: 82.55 % (= 1.00 \* 0.98 \* 0.84)
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 82.55 %
-   Total points: 0.83 \* 5.00 = 4.13

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**13**|--|--|--|
|Lines of code:|**155**|11.92 ± 20.46|63|`CRoute::Find`|
|Cyclomatic complexity:|**31**|2.38 ± 3.41|14|`CRoute::Find`|

**13**

**2019-05-05 22:03:58**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1702&Tsk=1208&Sub=1078635)

**Submission status:**

Evaluated

 

**Evaluation:**

3.8340

-   **Evaluator: computer**
    -   Compile in 'pedantic' mode failed (10 % penalty). [[Unlock advice (2069 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=C1087238'))
    -   Test 'Basic test with sample input data': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.000 s (limit: 5.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test': success
        -   result: 96.82 %, required: 50.00 %
        -   Total run time: 0.082 s (limit: 5.000 s)
        -   Mandatory test success, evaluation: 96.82 %
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269236'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269237'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269238'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269239'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269240'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269241'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269242'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269243'))
    -   Test 'Speed test': success
        -   result: 88.00 %, required: 50.00 %
        -   Total run time: 2.535 s (limit: 8.000 s)
        -   Optional test success, evaluation: 88.00 %
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269244'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269245'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269246'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269247'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269248'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269249'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269250'))
        -   Failed (invalid output) [[Unlock advice (25 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=L3269251'))
    -   Overall ratio: 76.68 % (= (1.00 \* 0.97 \* 0.88) \* 0.9)
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 76.68 %
-   Total points: 0.77 \* 5.00 = 3.83

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**13**|--|--|--|
|Lines of code:|**152**|11.69 ± 19.89|60|`CRoute::Find`|
|Cyclomatic complexity:|**30**|2.31 ± 3.15|13|`CRoute::Find`|

**12**

**2019-05-05 21:46:48**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1702&Tsk=1208&Sub=1078616)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Compile in 'basic' mode failed. [[Unlock advice (2069 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=C1087223'))
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 0.00 %
-   Total points: 0.00 \* 5.00 = 0.00

**11**

**2019-05-05 21:40:08**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1702&Tsk=1208&Sub=1078610)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Compile in 'basic' mode failed. [[Unlock advice (2069 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=C1087217'))
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 0.00 %
-   Total points: 0.00 \* 5.00 = 0.00

**10**

**2019-05-05 21:35:14**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1702&Tsk=1208&Sub=1078608)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Compile in 'basic' mode failed. [[Unlock advice (2069 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=C1087215'))
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 0.00 %
-   Total points: 0.00 \* 5.00 = 0.00

**9**

**2019-05-05 21:16:41**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1702&Tsk=1208&Sub=1078600)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -    Compile in 'basic' mode failed.

        ``` {#pre_C1087207 style="display: none"}
        In file included from testbed.cpp:185:0:
        tested: In instantiation of ‘const std::__cxx11::list<_T> student_47331de53834d8c61f9780b7e671f255::CRoute<_T, _E>::Find(const _T&, const _T&, const _F&) const [with _F = CMinFilter; _T = CMinType; _E = CMinEdge]’:
        testbed.cpp:491:53:   required from ‘void validateRoute(int&, int&, teacher_71a7b55aba468bf90f13e55d2c9350b3::CRoute<_T, _E>&, student_47331de53834d8c61f9780b7e671f255::CRoute<_T, _E>&, const _T&, const _T&, const _F&) [with _T = CMinType; _E = CMinEdge; _F = CMinFilter]’
        testbed.cpp:603:125:   required from here
        tested:167:9: error: no matching function for call to ‘std::map<int, std::__cxx11::basic_string<char> >::insert(<brace-enclosed initializer list>)’
                 tmp.insert( {0 , start} );
                 ^~~
        In file included from /usr/include/c++/6/map:61:0,
                         from testbed.cpp:12:
        /usr/include/c++/6/bits/stl_map.h:731:7: note: candidate: std::pair<typename std::_Rb_tree<_Key, std::pair<const _Key, _Tp>, std::_Select1st<std::pair<cons

        <skipping 64495 B>

        ,
                         from testbed.cpp:11:
        /usr/include/c++/6/bits/stl_list.h:1097:7: note: candidate: void std::__cxx11::list<_Tp, _Alloc>::push_back(const value_type&) [with _Tp = int; _Alloc = std::allocator<int>; std::__cxx11::list<_Tp, _Alloc>::value_type = int]
               push_back(const value_type& __x)
               ^~~~~~~~~
        /usr/include/c++/6/bits/stl_list.h:1097:7: note:   no known conversion for argument 1 from ‘const std::__cxx11::basic_string<char>’ to ‘const value_type& {aka const int&}’
        /usr/include/c++/6/bits/stl_list.h:1102:7: note: candidate: void std::__cxx11::list<_Tp, _Alloc>::push_back(std::__cxx11::list<_Tp, _Alloc>::value_type&&) [with _Tp = int; _Alloc = std::allocator<int>; std::__cxx11::list<_Tp, _Alloc>::value_type = int]
               push_back(value_type&& __x)
               ^~~~~~~~~
        /usr/include/c++/6/bits/stl_list.h:1102:7: note:   no known conversion for argument 1 from ‘const std::__cxx11::basic_string<char>’ to ‘std::__cxx11::list<int, std::allocator<int> >::value_type&& {aka int&&}’
        ```

-   Total percent: 0.00 %
-   Total points: 0.00 \* 5.00 = 0.00

**8**

**2019-05-05 19:15:21**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1702&Tsk=1208&Sub=1078530)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Compile in 'basic' mode failed. [[Unlock advice (2070 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=C1087137'))
-   Total percent: 0.00 %
-   Total points: 0.00 \* 5.00 = 0.00

**7**

**2019-05-05 15:02:12**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1702&Tsk=1208&Sub=1078406)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Compile in 'basic' mode failed. [[Unlock advice (2070 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=C1087015'))
-   Total percent: 0.00 %
-   Total points: 0.00 \* 5.00 = 0.00

**6**

**2019-05-05 14:20:55**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1702&Tsk=1208&Sub=1078398)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Compile in 'basic' mode failed. [[Unlock advice (2070 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=C1087007'))
-   Total percent: 0.00 %
-   Total points: 0.00 \* 5.00 = 0.00

**5**

**2019-05-05 05:38:45**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1702&Tsk=1208&Sub=1078319)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Compile in 'basic' mode failed. [[Unlock advice (2070 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=C1086928'))
-   Total percent: 0.00 %
-   Total points: 0.00 \* 5.00 = 0.00

**4**

**2019-05-05 05:32:21**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1702&Tsk=1208&Sub=1078318)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Compile in 'basic' mode failed. [[Unlock advice (2070 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=C1086927'))
-   Total percent: 0.00 %
-   Total points: 0.00 \* 5.00 = 0.00

**3**

**2019-05-05 01:58:43**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1702&Tsk=1208&Sub=1078296)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Compile in 'basic' mode failed. [[Unlock advice (2070 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=C1086905'))
-   Total percent: 0.00 %
-   Total points: 0.00 \* 5.00 = 0.00

**2**

**2019-05-05 00:38:38**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1702&Tsk=1208&Sub=1078281)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Compile in 'basic' mode failed. [[Unlock advice (2070 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=C1086890'))
-   Total percent: 0.00 %
-   Total points: 0.00 \* 5.00 = 0.00

**1**

**2019-05-04 23:08:04**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1702&Tsk=1208&Sub=1078262)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Compile in 'basic' mode failed. [[Unlock advice (2070 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1702&Tsk=1208&Unl=C1086871'))
-   Total percent: 0.00 %
-   Total points: 0.00 \* 5.00 = 0.00

