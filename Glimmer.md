# Part1-了解C语言配置文件

## 什么是`GCC`，什么是`MinGW`？它的作用是什么？
1. `GCC`是一个编译器，可以将C语言源代码编译为机器码
2. `MinGW`是一种将`GCC`适配到windows操作系统上的工具
3. VScode只是编辑器，需要`GCC`与`MinGW`配合才能将VScode上的源代码在windows上编译为机器码。[^problem1]  
[^problem1]:暑假时我下载过一个msys64。然后我使用的IDE一直是visual studio,但因微光该题中提到了三个配置文件加上老师也给出了vscode的环境配置教程，于是乎我决定再安装一个vscode体验环境配置的过程，而这个过程中因为我已存在的msys64导致配置文件经常导向原来的msys，所以我就只能手动改路径解决。

## `c_cpp_properties.json` `launch.json` `tasks.json`这三个文件分别有什么作用？
1. `c_cpp_properties.json`用于完善用户对编辑器的使用体验，可以支持自动补全与报错。
2. `launch.json`用于调试，调试`tasks.json`编译好的`.exe`程序，并且可以调用`gdb`来通过断点排查找到bug所在。
3. `tasks.json`用于调用`gcc`完成编译，完成`.exe`文件。

## 为什么要在编辑器内下载C语言的插件，插件的作用又是什么？
1. **Why**  
编辑器本身只提供编辑平台，没有识别c语言的能力。需要下载c语言插件辅助编辑和处理相关配置文件。
2. **What**  
   - 插件提供更好的编辑体验：可以在编辑过程中自动补全代码、提供语法高亮。
   - 添加插件后vscode才可以和`lauch.json`配合调用`gdb`完成调试。
   - 让VScode识别几个配置文件，辅助配置文件完成任务。

## `lauch.json`的配置
1. `"stopAtEntry": false`  //该项用于判断是否要在main函数让入口处停下：false代表“不”，即顺着main函数一直运行到第一个断点位置；true代表“是”，即在main函数开头停下，随后用户可以用F10一行行运行。
2. `"externalConsole": false`  //该项控制是否要打开外置控制台，false表示默认的集成终端。[^problem2]

[^problem2]:在我刚配置完环境时重新打开vscode时不知为何`.vscode`这个文件夹消失了，但在我的D盘还存在，于是我重新建了一遍配置文件把设置调整了一下（主要就是前面提到的路径导向另一个文件msys64的问题）
3. `"miDebuggerPath": "C:\\mingw64\\bin\\gdb.exe"`  //该项用于调用调试器，必须与自己的路径相同。

## `hello,world`运行结果截图
- 集成终端版![1](https://github.com/backway-Lai/GLIMMER-CS-EASY-01/raw/main/images/screen-shot1.png)
- 外置控制台版![1](https://github.com/backway-Lai/GLIMMER-CS-EASY-01/raw/main/images/screen-shot2.png)

# Part2-C语言基础

## 变量类型
- 变量类型为编译器提供了解释二进制的规则，同样的二进制会因不同的变量类型呗解析为不同结果。
- 存放年龄应该使用`int`，因为`int`代表整数，而`float`代表浮点数，年龄一般用整数表示，因此`int`足矣。
- `char`不可以用来直接存放"apple"，因为"apple"是一个字符串，而`char`只能存放一个字符。当我直接用`char`存放"apple"时，输出结果只有"e"。![1](https://github.com/backway-Lai/GLIMMER-CS-EASY-01/raw/main/images/screen-shot3.png)

## 数组的起始与边界
- 数组的第一个下标从0开始，实际上`arr[0]`与`arr`等价，都代表数组中首元素的地址。

- 数组越界
  1. C语言不会检验下标，因此可能带来数组越界。
  2. **读越界**：即读取不在数组内的内存，可能会随机读取垃圾信息导致乱码，也可能读到重要信息导致信息泄露。
  3. **写越界**：会覆盖其他变量，很可能带来程序崩溃，危害更大。

- 流程控制 - 循环结构
  1. `for`与`while`均代表一种循环结构，表示程序在达成某种条件前将会循环运行该结构中的代码，直到达成条件为止。
  2. `for`循环中的初始化代表第一次进入循环时为变量赋值；条件判断代表每次进入循环时检验是否满足这个条件，若满足则继续运行，若不满足则跳出循环；迭代部分则表示每次循环结束执行一次该程序。[^1]
  [^1]:因为小时候学过类似scratch的图形化编程，因此对循环的逻辑和结构比较熟悉。
  3. `while`的逻辑是如果满足条件，则进入循环内程序；而`do...while`的逻辑是执行程序直到不满足条件。可以理解为`while`会在运行前检验，因此有可能一次都不运行，而`do...while`必须运行至少一次才会进入检验。
  `while`的运算：![1](https://github.com/backway-Lai/GLIMMER-CS-EASY-01/raw/main/images/screen-shot4.png)
  `do...while`的运算：![1](https://github.com/backway-Lai/GLIMMER-CS-EASY-01/raw/main/images/screen-shot5.png)

- 流程控制 - 逻辑表达式
  1. **逻辑表达式**：运算的是关系数值，类似比较，结果是真或假（1或0）.
  2. **运算表达式**：运算的是纯数值，类似计算，结果也是纯数值。
  3. **运算逻辑符**：`&&`表达同时成立（与）；`||`表达存在一个成立（或）；`!`表达非，即取反，结果只有真或假（0或1）。[^2]
  [^2]:此处的`!`是有点与我认知不一样的，我以为会与!=含义类似，代表一种不等于，但实际上它代表着仅仅只有取反，类似于命题的非，运算结果的0/1有点感觉反直觉。

- ![part2小题代码地址](https://github.com/backway-Lai/GLIMMER-CS-EASY-01/edit/main/part2.c)实测截图：![1](https://github.com/backway-Lai/GLIMMER-CS-EASY-01/raw/main/images/screen-shot7.png)
- 逻辑其实很好理解，需要一个循环，循环内容是输出-输入-记录，而判断条件确实一个我原先不熟悉的：用户直接输入。因此我一开始就错了很多次，一开始是不清楚char的规范，在scanf中多余的使用了&，还有就是字符串内容相等要用string.h，一开始我把它写成了ans == "yes"的形式。)

## Part3-函数

因为我以前的图形化编程基础，因此函数上手也比较熟悉，[part3代码地址](https://github.com/backway-Lai/GLIMMER-CS-EASY-01/blob/main/part3.c)[^3]
***
[^3]:首先我一开始对第三个要求即封装排序非常疑惑，不知道怎么用函数化简这一步，之后问了一下AI发现似乎只能用三目运算符才能化简，但多层嵌套又可能带来复杂问题，因此我在代码中就只将排序单独拿出来以此来化简主函数。其次是我在中文乱码上遇上一个大难题，我分别在visual studio 和vscode上都重新试了一下，最后还是通过ai知道了可以改文件保存时的编译类型，加上简体中文的“高级保存设置”就可以实现了。
