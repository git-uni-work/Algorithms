||
|[ProgTest](https://progtest.fit.cvut.cz/index.php?X=Main)  ►  [BIE-PA2 (18/19 LS)](https://progtest.fit.cvut.cz/index.php?X=Course&Cou=264)  ►  [Homework 01](https://progtest.fit.cvut.cz/index.php?X=TaskGrp&Cou=264&Tgr=1694)  ►  **Image flipping**|[Logout](https://progtest.fit.cvut.cz/index.php?X=Logout)|

||
|**Image flipping**|

**Submission deadline:**

**2019-03-24 23:59:59**

 

**Late submission with malus:**

**2019-06-30 23:59:59** (Late submission malus: 100.0000 %)

**Evaluation:**

**3.6364**

**Max. assessment:**

**5.0000** (Without bonus points)

**Submissions:**

14 / 20 Free retries + 20 Penalized retries (-2 % penalty each retry)

**Advices:**

1 / 2 Advices for free + 2 Advices with a penalty (-10 % penalty each advice)

The task is to develop a function to handle an image file -- the function shall be able to read the image, flip it, and save the modified image.

We assume a simple uncompressed image files in this assignment. An image can be seen as a 2D array of pixels, the size of the image corresponds to the width and height of the array. The easiest way to save a 2D array into a file is to traverse the array in a row-major order, i.e., save the first row, then second row, ..., until the entire array is serialized into the target file. Pixels in the image do not need to be integers, instead, each pixel of the image may be formed from tuples (channels), e.g. 3 channels (RGB components), 4 channels (RGB and opacity component), or simple 1 channel (shades of gray). Next, each channel value is represented with some precision, the precision is given by the number of bits per channel value. We assume precision 1 bit, 8 bits, or 16 bits per channel, and we assume 1, 3, or 4 channels per pixel.

![](https://progtest.fit.cvut.cz/index.php?X=ImgT&UID=1595&N=1)

Image flipping is very simple image processing operation. The required function will be able to perform the flipping, based on the parameters. The flipping may be horizontal (by vertical axis), vertical (by horizontal axis), both vertical and horizontal, and none (i.e., plain copy). The required function interface is:

    bool flipImage ( const char * srcFileName, 
                     const char * dstFileName, 
                     bool         flipHorizontal,
                     bool         flipVertical );

`srcFileName`  
is an ASCIIZ string denoting the name of the source image file. The function is supposed to read the source image, however, it cannot modify it.

`dstFileName`  
is an ASCIIZ string denoting the name of the resulting image file. The function creates/overwrites the resulting file and stores the updated image into the file.

`flipHorizontal`  
true if the function shall do the horizontal flip (by vertical axis),

`flipVertical`  
true if the function shall do the vertical flip (by horizontal axis),

return value  
`true` to indicate success, `false` to report a failure. The following shall be considered a failure:

-   file or I/O related problems (cannot read/write, file does not exist, ...),
-   invalid input file format (invalid header, invalid pixel format, not enough image data, too many bytes in the file, ...).

The function creates the resulting file based on the source image and parameters:

-   resulting image size is determined by the source image size,
-   resulting image pixel format and endianity is identical to the source image pixel format and endianity,
-   image data in the image file are modified based on the flipHorizontal/flipVertical parameters.

The image file format is very simple. The file starts with a fixed size header that is followed by the image data. The header has the following structure:

    offset   size         description
    +0       2B           endianity (0x4949 little endian, 0x4d4d big endian)
    +2       2B           image width
    +4       2B           image height
    +6       2B           pixel format
    +8       ??           image data (pixels)

-   Little/big endian identifier is the first field in the header. The field describes the byte order of two byte values stored in the file. The actual values (0x4949 and 0x4d4d) are symmetric, thus the field can be correctly read by any platform. This field will be set to little endian in the mandatory tests (little endian is the platform your program runs on). However, the value may be either little endian or big endian in the optional tests. (Actually, there are few invalid inputs in the mandatory tests where the endianity is set to a random value. Obviously, such inputs must be rejected).
-   Width and height fields denote the dimensions of the image. The values must be non-zero.
-   Pixel format describes the coding of individual pixels. The value is composed from individual bits:

            bit  15            5  4 3 2  1 0
                 0 0    ...    0  B B B  C C
           

    Each pixel may consist of several channels. Bits 1 and 0 denote the number of channels per pixel:

            00 - 1 channel: black/white, or shades of gray
            01 - invalid combination
            10 - 3 channels = RGB
            11 - 4 channels = RGBA
           

    Each channel value is coded in the given number of bits:

            000 -  1 bit per channel
            001 -  invalid combination
            010 -  invalid combination
            011 -  8 bits per channel
            100 - 16 bits per channel
            101 \
            110  | invalid combination
            111 /
           

    Bits 5-15 are not used, they must be set to zero. A few examples:

           0x000c = 0b00001100 - 1 channel per pixel, 8 bits per channel
           0x000e = 0b00001110 - 3 channels per pixel, 8 bits per channel
           0x0013 = 0b00010011 - 4 channels per pixel, 16 bits per channel
              

**Notes:**

-   Pay special attention to the file I/O. The testing environment tests your implementation, it tries nonexistent files, unreadable files, files with invalid contents, ...
-   Do not assume anything about file names. There are no explicit restrictions on file names. The important thing is: can the file be opened/read/written.
-   You may use either C or C++ file interface, the choice is free.
-   There is a set of input and corresponding result images in the attached archive. Further, there is a source file with a sample test `main` that calls your implementation to convert the sample input files and compares the results with the reference. You may use the example source file as a basis of your implementation. There are parts of shared code, the code is placed in conditional compile blocks. If these conditional compile blocks are preserved, the source can be submitted to Progtest.
-   Use bit operation (&) and bit shifts (\<\< and \>\>) to handle pixel format field in the header.
-   Little/big endian applies to the fields in the header, moreover, it applies to the 16 bit values in the image data (if the actual pixel format is 16 bits per channel).
-   Do not develop one huge function. Instead, divide the problem into subproblems, use functions/classes to implement the subproblems. A reasonable solution reads the source into memory, decodes the pixels, modifies the pixels, and writes the contents back into the destination file. There is enough memory to load the entire image.
-   There are fixed width fields in the header (e.g. 2 byte integers). Do not use `int` type to handle these values, the width of `int` data type is not guaranteed. Instead, use fixed width data types declared in `cstdint` header, such as `int16_t` and `uint16_t`.
-   Mandatory tests use 8 bits / channel format, moreover, only little endian is used (i.e. it matches the processor architecture). Your implementation passes all mandatory tests if:
    -   it handles 8 bits / channel + little endian, and
    -   it reports an error for all other bits/channel and endian combinations.
-   The test "16 bit + endianity" is an optional test. If your implementation does not pass the test, there will be a certain malus to the overall result. The fact it is optional means that your implementation may be awarded non-zero points even if your implementation completely fails the optional test. (If it was a mandatory test, then a failure to pass the test would automatically result in 0 points.)
-   The last test is focused on 1 bit / channel. It is a bonus test, i.e., you will be awarded extra points over the nominal 100% if your program passes this test. The processing of 1 bit values means that the bytes read from the input file must be decomposed into individual bits. Similarly, the bits written to the output file must be combined into bytes. The bits in the bytes are to be stored in the LSB to MSB order (least significant bit to most significant bit). Each row of the image starts on a byte boundary. If the total number of bits in a row is not a multiple of 8, then the last byte in the row is padded with zero bits.
-   It is recommended to start with the basic variant (8 bits/channel + little endian). Once it works, extend the solution to work with the other bit depths. There is a hidden benefit of this continuous development - you have to design function/method interfaces to be extensible. You may need to re-design the function several times, however, the experience is invaluable.
-   A solution of this homework may be used in code review. However, the solution must pass all mandatory and optional tests to 100%.

**Sample data:**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskS&Cou=264&Tgr=1694&Tsk=1595)

 **Reference**

 

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Zakladni test se soubory dle ukazky': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.002 s (limit: 5.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Mezni hodnoty': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.034 s (limit: 4.998 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Nespravne vstupy': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 4.964 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Nahodny test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.086 s (limit: 4.963 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Test osetreni I/O chyb': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.028 s (limit: 4.877 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Nahodny test, 16bit, little/big endian': success
        -   result: 100.00 %, required: 80.00 %
        -   Total run time: 0.006 s (limit: 3.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Nahodny test, 1bit': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.007 s (limit: 2.000 s)
        -   Bonus test - success, evaluation: 120.00 %
    -   Overall ratio: 120.00 % (= 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.20)
-   Total percent: 120.00 %
-   Early submission bonus: 0.50
-   Total points: 1.20 \* ( 5.00 + 0.50 ) = 6.60

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**17**|--|--|--|
|Lines of code:|**191**|11.24 ± 6.73|29|`CImage::Read`|
|Cyclomatic complexity:|**57**|3.35 ± 3.01|14|`CImage::Read`|

**14**

**2019-05-05 23:41:33**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1694&Tsk=1595&Sub=1078709)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample files': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.002 s (limit: 5.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.074 s (limit: 4.998 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Invalid input': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 4.924 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.173 s (limit: 4.923 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Test I/O failures': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.160 s (limit: 4.750 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test, 16bit, little/big endian': success
        -   result: 100.00 %, required: 80.00 %
        -   Total run time: 0.006 s (limit: 3.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test, 1bit': failed
        -   result: 0.00 %, required: 100.00 %
        -   Total run time: 0.009 s (limit: 2.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
        -   Failed (invalid output) [[Unlock advice (380 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3269442'))
        -   Failed (invalid output) [[Unlock advice (292 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3269443'))
        -   Failed (invalid output) [[Unlock advice (275 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3269444'))
        -   Failed (invalid output) [[Unlock advice (1.28 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3269445'))
        -   Failed (invalid output) [[Unlock advice (231 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3269446'))
        -   Failed (invalid output) [[Unlock advice (135 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3269447'))
        -   Failed (invalid output) [[Unlock advice (335 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3269448'))
        -   Failed (invalid output) [[Unlock advice (730 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3269449'))
    -   Overall ratio: 100.00 % (= 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.00)
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 100.00 %
-   Late submission malus: 5.00
-   Total points: 1.00 \* ( 5.00 - 5.00 ) = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**12**|--|--|--|
|Lines of code:|**263**|21.92 ± 18.40|72|`Image::loadheader`|
|Cyclomatic complexity:|**70**|5.83 ± 5.54|22|`main`|

**13**

**2019-05-05 05:19:35**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1694&Tsk=1595&Sub=1078317)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample files': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.001 s (limit: 5.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.056 s (limit: 4.999 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Invalid input': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 4.943 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.156 s (limit: 4.942 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Test I/O failures': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.191 s (limit: 4.786 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test, 16bit, little/big endian': success
        -   result: 100.00 %, required: 80.00 %
        -   Total run time: 0.011 s (limit: 3.000 s)
        -   Optional test success, evaluation: 100.00 %
    -   Test 'Random test, 1bit': failed
        -   result: 0.00 %, required: 100.00 %
        -   Total run time: 0.008 s (limit: 2.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
        -   Failed (invalid output) [[Unlock advice (588 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3268731'))
        -   Failed (invalid output) [[Unlock advice (136 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3268732'))
        -   Failed (invalid output) [[Unlock advice (130 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3268733'))
        -   Failed (invalid output) [[Unlock advice (509 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3268734'))
        -   Failed (invalid output) [[Unlock advice (323 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3268735'))
        -   Failed (invalid output) [[Unlock advice (318 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3268736'))
        -   Failed (invalid output) [[Unlock advice (214 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3268737'))
        -   Failed (invalid output) [[Unlock advice (650 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3268738'))
    -   Overall ratio: 100.00 % (= 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.00)
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 100.00 %
-   Late submission malus: 5.00
-   Total points: 1.00 \* ( 5.00 - 5.00 ) = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**12**|--|--|--|
|Lines of code:|**261**|21.75 ± 17.95|70|`Image::loadheader`|
|Cyclomatic complexity:|**70**|5.83 ± 5.54|22|`main`|

**12**

**2019-04-22 02:13:52**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1694&Tsk=1595&Sub=1075752)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample files': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.002 s (limit: 5.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.073 s (limit: 4.998 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Invalid input': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 4.925 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.141 s (limit: 4.924 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Test I/O failures': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.118 s (limit: 4.783 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test, 16bit, little/big endian': failed
        -   result: 47.50 %, required: 80.00 %
        -   Total run time: 0.011 s (limit: 3.000 s)
        -   Optional test failed, evaluation: 80.00 %
        -   Failed (invalid output) [[Unlock advice (982 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3263284'))
        -   Failed (invalid output) [[Unlock advice (3.18 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3263285'))
        -   Failed (invalid output) [[Unlock advice (4.06 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3263286'))
        -   Failed (invalid output) [[Unlock advice (2.87 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3263287'))
        -   Failed (invalid output) [[Unlock advice (3.91 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3263288'))
        -   Failed (invalid output) [[Unlock advice (1.13 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3263289'))
        -   Failed (invalid output) [[Unlock advice (500 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3263290'))
        -   Failed (invalid output) [[Unlock advice (5.49 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3263291'))
    -   Test 'Random test, 1bit': Abnormal program termination (Time limit exceeded)
        -   Cumulative test time exceeded, killed after:: 2.023 s (limit: 2.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 80.00 % (= 1.00 \* 1.00 \* 1.00 \* 1.00 \* 1.00 \* 0.80)
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 80.00 %
-   Late submission malus: 5.00
-   Total points: 0.80 \* ( 5.00 - 5.00 ) = 0.00

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**12**|--|--|--|
|Lines of code:|**218**|18.17 ± 13.89|60|`Image::loadheader`|
|Cyclomatic complexity:|**57**|4.75 ± 3.22|12|`Image::loadheader`|

**11**

**2019-04-22 02:09:40**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1694&Tsk=1595&Sub=1075751)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Compile in 'basic' mode failed. [[Unlock advice (2070 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=C1084499'))
-   Advices used: 1
-   Penalty due to advices: None (1 \<= 2 limit)
-   Total percent: 0.00 %
-   Late submission malus: 5.00
-   Total points: 0.00 \* ( 5.00 - 5.00 ) = 0.00

**10**

**2019-03-25 00:00:39**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1694&Tsk=1595&Sub=1063198)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Compile in 'basic' mode failed. [[Unlock advice (2070 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=C1071959'))
-   Total percent: 0.00 %
-   Late submission malus: 5.00
-   Total points: 0.00 \* ( 5.00 - 5.00 ) = 0.00

**9**

**2019-03-22 01:56:20**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1694&Tsk=1595&Sub=1060907)

**Submission status:**

Evaluated

 

**Evaluation:**

3.6364

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample files': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.002 s (limit: 5.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.074 s (limit: 4.998 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Invalid input': success
        -   result: 90.91 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 4.924 s)
        -   Mandatory test success, evaluation: 90.91 %
        -    Failed (invalid output)

                 flipImage ( ..., true, false ) st=true, ref=false

            Input data [[58 B / 58 B]](https://progtest.fit.cvut.cz/index.php?X=Advice&UID=I3194607)

    -   Test 'Random test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.151 s (limit: 4.923 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Test I/O failures': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.155 s (limit: 4.772 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test, 16bit, little/big endian': failed
        -   result: 55.00 %, required: 80.00 %
        -   Total run time: 0.010 s (limit: 3.000 s)
        -   CPU time: 0.012 s (limit: 3.000 s)
        -   Optional test failed, evaluation: 80.00 %
        -   Failed (invalid output) [[Unlock advice (2.58 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3194608'))
        -   Failed (invalid output) [[Unlock advice (418 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3194609'))
        -   Failed (invalid output) [[Unlock advice (3.71 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3194610'))
        -   Failed (invalid output) [[Unlock advice (2.59 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3194611'))
        -   Failed (invalid output) [[Unlock advice (2.31 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3194612'))
        -   Failed (invalid output) [[Unlock advice (2.90 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3194613'))
        -   Failed (invalid output) [[Unlock advice (1.32 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3194614'))
        -   Failed (invalid output) [[Unlock advice (1.93 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3194615'))
    -   Test 'Random test, 1bit': failed
        -   result: 0.00 %, required: 100.00 %
        -   Total run time: 0.981 s (limit: 2.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
        -   Failed (invalid output) [[Unlock advice (172 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3194616'))
        -   Failed (invalid output) [[Unlock advice (145 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3194617'))
        -   Failed (invalid output) [[Unlock advice (986 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3194618'))
        -   Failed (invalid output) [[Unlock advice (795 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3194619'))
        -   Failed (invalid output) [[Unlock advice (112 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3194620'))
        -   Failed (invalid output) [[Unlock advice (212 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3194621'))
        -   Failed (invalid output) [[Unlock advice (729 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3194622'))
        -   Failed (invalid output) [[Unlock advice (275 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3194623'))
    -   Overall ratio: 72.73 % (= 1.00 \* 1.00 \* 0.91 \* 1.00 \* 1.00 \* 0.80)
-   Total percent: 72.73 %
-   Total points: 0.73 \* 5.00 = 3.64

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**12**|--|--|--|
|Lines of code:|**212**|17.67 ± 12.40|54|`Image::loadheader`|
|Cyclomatic complexity:|**56**|4.67 ± 3.04|11|`Image::loadheader`|

**8**

**2019-03-22 01:37:28**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1694&Tsk=1595&Sub=1060897)

**Submission status:**

Evaluated

 

**Evaluation:**

3.6364

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample files': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.002 s (limit: 5.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.079 s (limit: 4.998 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Invalid input': success
        -   result: 90.91 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 4.919 s)
        -   Mandatory test success, evaluation: 90.91 %
        -   Failed (invalid output) [[Unlock advice (108 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3194558'))
    -   Test 'Random test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.165 s (limit: 4.918 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Test I/O failures': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.132 s (limit: 4.753 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test, 16bit, little/big endian': failed
        -   result: 50.00 %, required: 80.00 %
        -   Total run time: 0.009 s (limit: 3.000 s)
        -   Optional test failed, evaluation: 80.00 %
        -   Failed (invalid output) [[Unlock advice (1.85 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3194559'))
        -   Failed (invalid output) [[Unlock advice (1.46 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3194560'))
        -   Failed (invalid output) [[Unlock advice (2.35 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3194561'))
        -   Failed (invalid output) [[Unlock advice (2.12 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3194562'))
        -   Failed (invalid output) [[Unlock advice (1.05 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3194563'))
        -   Failed (invalid output) [[Unlock advice (1.11 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3194564'))
        -   Failed (invalid output) [[Unlock advice (707 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3194565'))
        -   Failed (invalid output) [[Unlock advice (4.33 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3194566'))
    -   Test 'Random test, 1bit': failed
        -   result: 0.00 %, required: 100.00 %
        -   Total run time: 1.670 s (limit: 2.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
        -   Failed (invalid output) [[Unlock advice (477 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3194567'))
        -   Failed (invalid output) [[Unlock advice (143 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3194568'))
        -   Failed (invalid output) [[Unlock advice (234 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3194569'))
        -   Failed (invalid output) [[Unlock advice (604 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3194570'))
        -   Failed (invalid output) [[Unlock advice (177 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3194571'))
        -   Failed (invalid output) [[Unlock advice (121 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3194572'))
        -   Failed (invalid output) [[Unlock advice (1.22 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3194573'))
        -   Failed (invalid output) [[Unlock advice (1.03 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3194574'))
    -   Overall ratio: 72.73 % (= 1.00 \* 1.00 \* 0.91 \* 1.00 \* 1.00 \* 0.80)
-   Total percent: 72.73 %
-   Total points: 0.73 \* 5.00 = 3.64

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**12**|--|--|--|
|Lines of code:|**212**|17.67 ± 12.40|54|`Image::loadheader`|
|Cyclomatic complexity:|**54**|4.50 ± 2.72|10|`main`|

**7**

**2019-03-22 01:36:28**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1694&Tsk=1595&Sub=1060896)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Compile in 'basic' mode failed. [[Unlock advice (1021 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=C1069661'))
-   Total percent: 0.00 %
-   Total points: 0.00 \* 5.00 = 0.00

**6**

**2019-03-21 12:47:10**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1694&Tsk=1595&Sub=1060575)

**Submission status:**

Evaluated

 

**Evaluation:**

2.9091

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample files': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.001 s (limit: 5.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.058 s (limit: 4.999 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Invalid input': success
        -   result: 72.73 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 4.941 s)
        -   Mandatory test success, evaluation: 72.73 %
        -   Failed (invalid output) [[Unlock advice (108 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3192490'))
        -   Failed (invalid output) [[Unlock advice (58 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3192491'))
        -   Failed (invalid output) [[Unlock advice (57 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3192492'))
    -   Test 'Random test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.160 s (limit: 4.940 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Test I/O failures': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.148 s (limit: 4.780 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test, 16bit, little/big endian': failed
        -   result: 50.00 %, required: 80.00 %
        -   Total run time: 0.010 s (limit: 3.000 s)
        -   CPU time: 0.012 s (limit: 3.000 s)
        -   Optional test failed, evaluation: 80.00 %
        -   Failed (invalid output) [[Unlock advice (2.24 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3192493'))
        -   Failed (invalid output) [[Unlock advice (2.12 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3192494'))
        -   Failed (invalid output) [[Unlock advice (1.55 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3192495'))
        -   Failed (invalid output) [[Unlock advice (2.85 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3192496'))
        -   Failed (invalid output) [[Unlock advice (2.03 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3192497'))
        -   Failed (invalid output) [[Unlock advice (922 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3192498'))
        -   Failed (invalid output) [[Unlock advice (2.78 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3192499'))
        -   Failed (invalid output) [[Unlock advice (2.15 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3192500'))
    -   Test 'Random test, 1bit': Abnormal program termination (Time limit exceeded)
        -   Cumulative test time exceeded, killed after:: 2.026 s (limit: 2.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
    -   Overall ratio: 58.18 % (= 1.00 \* 1.00 \* 0.73 \* 1.00 \* 1.00 \* 0.80)
-   Total percent: 58.18 %
-   Total points: 0.58 \* 5.00 = 2.91

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**12**|--|--|--|
|Lines of code:|**214**|17.83 ± 12.39|54|`Image::loadheader`|
|Cyclomatic complexity:|**53**|4.42 ± 2.53|10|`main`|

**5**

**2019-03-21 12:42:19**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1694&Tsk=1595&Sub=1060572)

**Submission status:**

Evaluated

 

**Evaluation:**

2.9091

-   **Evaluator: computer**
    -   Program compiled
    -   Test 'Basic test with sample files': success
        -   result: 100.00 %, required: 100.00 %
        -   Total run time: 0.002 s (limit: 5.000 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Borderline': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.073 s (limit: 4.998 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Invalid input': success
        -   result: 72.73 %, required: 50.00 %
        -   Total run time: 0.001 s (limit: 4.925 s)
        -   Mandatory test success, evaluation: 72.73 %
        -   Failed (invalid output) [[Unlock advice (108 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3192455'))
        -   Failed (invalid output) [[Unlock advice (58 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3192456'))
        -   Failed (invalid output) [[Unlock advice (57 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3192457'))
    -   Test 'Random test': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.161 s (limit: 4.924 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Test I/O failures': success
        -   result: 100.00 %, required: 50.00 %
        -   Total run time: 0.143 s (limit: 4.763 s)
        -   Mandatory test success, evaluation: 100.00 %
    -   Test 'Random test, 16bit, little/big endian': failed
        -   result: 50.00 %, required: 80.00 %
        -   Total run time: 0.010 s (limit: 3.000 s)
        -   CPU time: 0.012 s (limit: 3.000 s)
        -   Optional test failed, evaluation: 80.00 %
        -   Failed (invalid output) [[Unlock advice (2.52 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3192458'))
        -   Failed (invalid output) [[Unlock advice (1.53 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3192459'))
        -   Failed (invalid output) [[Unlock advice (1.52 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3192460'))
        -   Failed (invalid output) [[Unlock advice (559 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3192461'))
        -   Failed (invalid output) [[Unlock advice (1.18 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3192462'))
        -   Failed (invalid output) [[Unlock advice (5.49 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3192463'))
        -   Failed (invalid output) [[Unlock advice (755 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3192464'))
        -   Failed (invalid output) [[Unlock advice (1.46 KiB)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3192465'))
    -   Test 'Random test, 1bit': failed
        -   result: 0.00 %, required: 100.00 %
        -   Total run time: 1.824 s (limit: 2.000 s)
        -   Bonus test - failed, evaluation: No bonus awarded
        -   Failed (invalid output) [[Unlock advice (290 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3192466'))
        -   Failed (invalid output) [[Unlock advice (248 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3192467'))
        -   Failed (invalid output) [[Unlock advice (169 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3192468'))
        -   Failed (invalid output) [[Unlock advice (818 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3192469'))
        -   Failed (invalid output) [[Unlock advice (382 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3192470'))
        -   Failed (invalid output) [[Unlock advice (699 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3192471'))
        -   Failed (invalid output) [[Unlock advice (717 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3192472'))
        -   Failed (invalid output) [[Unlock advice (105 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=L3192473'))
    -   Overall ratio: 58.18 % (= 1.00 \* 1.00 \* 0.73 \* 1.00 \* 1.00 \* 0.80)
-   Total percent: 58.18 %
-   Total points: 0.58 \* 5.00 = 2.91

**SW metrics:**

||
| |Total|Average|Maximum|Function name|
|Functions:|**12**|--|--|--|
|Lines of code:|**204**|17.00 ± 10.50|46|`Image::loadheader`|
|Cyclomatic complexity:|**48**|4.00 ± 2.38|10|`main`|

**4**

**2019-03-20 22:53:26**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1694&Tsk=1595&Sub=1060456)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Compile in 'basic' mode failed. [[Unlock advice (1021 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=C1069229'))
-   Total percent: 0.00 %
-   Total points: 0.00 \* 5.00 = 0.00

**3**

**2019-03-20 17:53:10**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1694&Tsk=1595&Sub=1060349)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Compile in 'basic' mode failed. [[Unlock advice (1021 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=C1069124'))
-   Total percent: 0.00 %
-   Total points: 0.00 \* 5.00 = 0.00

**2**

**2019-03-20 17:46:26**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1694&Tsk=1595&Sub=1060344)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Compile in 'basic' mode failed. [[Unlock advice (1021 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=C1069119'))
-   Total percent: 0.00 %
-   Total points: 0.00 \* 5.00 = 0.00

**1**

**2019-03-20 17:33:55**

[Download](https://progtest.fit.cvut.cz/index.php?X=TaskD&Cou=264&Tgr=1694&Tsk=1595&Sub=1060341)

**Submission status:**

Evaluated

 

**Evaluation:**

0.0000

-   **Evaluator: computer**
    -   Compile in 'basic' mode failed. [[Unlock advice (1021 B)]](javascript:%20unlockAdvice('?X=Unlock&Cou=264&Tgr=1694&Tsk=1595&Unl=C1069116'))
-   Total percent: 0.00 %
-   Total points: 0.00 \* 5.00 = 0.00

