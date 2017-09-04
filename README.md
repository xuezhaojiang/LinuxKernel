# Linux内核分析
薛兆江 + 原创作品转载请注明出处 + [《Linux内核分析》MOOC课程](http://mooc.study.163.com/course/USTC-1000029000)
http://mooc.study.163.com/course/USTC-1000029000     
#### 打开链接的时候，按住ctrl在点击左键，将会在新窗口打开    
## 实验报告列表
### 1.[分析一个简单C程序的汇编代码，理解计算机如何工作](https://xuezhaojiang.github.io/LinuxKernel/lab1/lab1.html)     
&emsp;&emsp;汇编语言基础知识、C语言函数调用过程中的堆栈变化和参数传递过程。     
### 2.[完成一个简单的时间片轮转多道程序内核代码](https://xuezhaojiang.github.io/LinuxKernel/lab2/lab2.html)    
&emsp;&emsp;模拟存储程序计算机工作模型，时钟中断和进程切换。关键代码是模拟的switch_to。值得注意的是仅仅模拟了主动调度。      
### 3.[跟踪分析Linux内核的启动过程](https://xuezhaojiang.github.io/LinuxKernel/lab3/lab3.html)     
&emsp;&emsp;源代码主要结构、内核启动及调试方法和start_kernel的解读。还有就是三个特殊进程idle,init,kthreadd的演化和作用，对于理解linux进程还是很有帮助的。       
### 4.[使用库函数API和C代码中嵌入汇编代码两种方式使用同一个系统调用](https://xuezhaojiang.github.io/LinuxKernel/lab4/lab4.html)     
&emsp;&emsp;对系统调用与用户态、内核态的理解、通过编写汇编代码和库函数调用了解系统调用机制。       
### 5.[分析system_call中断处理过程](https://xuezhaojiang.github.io/LinuxKernel/lab5/lab5.html)     
&emsp;&emsp;添加一个自己编写的系统调用，加深对系统调用在内核代码中的处理过程的理解。eip,esp,eflags的保存和恢复，参数的传递。      
### 6.[分析Linux内核创建一个新进程的过程](https://xuezhaojiang.github.io/LinuxKernel/lab6/lab6.html)     
&emsp;&emsp;关于进程的描述和创建。主要包括PCB的组织形式、进程的数据结构进程描述符、fork系统调用的关键执行过程。      
### 7.[Linux内核如何装载和启动一个可执行程序](https://xuezhaojiang.github.io/LinuxKernel/lab7/lab7.html)     
&emsp;&emsp;ELF文件格式，静态链接、动态链接（加载时链接、运行时链接）；exec库函数加载可执行文件。   
### 8.[进程调度与进程切换的过程](https://xuezhaojiang.github.io/LinuxKernel/lab8/lab8.html)     
&emsp;&emsp;进程调度与进程切换，switch_to代码分析。      
     
#### Linux内核,主要学习了系统启动过程、中断过程和系统调用、进程调度。可以说，这些都是linux内核中的核心功能。    
&emsp;&emsp;操作系统三个法宝：存储程序计算机、函数调用堆栈、中断机制。操作系统两把宝剑：中断上下文、进程上下文的切换。    
&emsp;&emsp;整个linux系统的所有进程是一个树形结构。树根是系统自动构造的，即在内核态下执行的0号进程，它是所有进程的祖先，完成加载系统后，演变为进程调度、交换。由0号进程创建1号进程（内核态），1号负责执行内核的部分初始化工作及进行系统配置，并创建若干个用于高速缓存和虚拟主存管理的内核线程。随后，1号进程调用execve()运行可执行程序init，并演变成用户态1号进程，即init进程。kthreadd进程是2号进程，由idle通过kernel_thread创建，并始终运行在内核空间，负责所有内核线程的调度和管理，它的任务就是管理和调度其他内核线程kernel_thread，会循环执行一个kthread的函数，该函数的作用就是运行kthread_create_list全局链表中维护的kthread，当我们调用kernel_thread创建的内核线程会被加入到此链表中，因此所有的内核线程都是直接或者间接的以kthreadd为父进程。    
&emsp;&emsp;**中断过程**，中断可以说是系统中最重要的功能之一，如果没有中断，那么一个操作系统就将退化成一个单道处理系统。中断大概过程就是主动或者被动发起一个中断，一断系统允许中断，那么首先就会保存eip,esp,eflags这些都由硬件来自动保存，接着进入到内核态。然后保存现场，即是保存通用寄存器，堆栈等等。然后，根据中断号来调用相应的中断处理程序，处理完成以后，恢复现场，中断返回。    
&emsp;&emsp;**系统调用**，系统调用就是特殊的中断过程，它一般由程序主动调用。当一个程序调用int 0x80时，便会是一个系统调用，首先，通过中断进入内核态，然后根据向量号（保存在eax中）进行相应的分发。它的相应参数都保存在寄存器中（%ebx，%ecx，%edx，%esi，%edi和%ebp），最后，处理完成以后，也会恢复现场，中断返回。     
&emsp;&emsp;**进程调度**，关于进程调度，最重要的便是要理解进程是如何从一个进程切换到另一个进程的，包括堆栈切换和逻辑控制流切换。从第一次实验，我们便写了一个模仿进程切换到的例子，它通过堆栈保存ebp，通过PCB保存当前进程的eip，esp，然后切换到下一个进程的esp、eip和ebp，这中间要保证能切换回来。最后一次实验也是分析进程切换的，真实的源码内容多，对比实验一中的简洁版，理解得更清楚。    
&emsp;&emsp;最大的遗憾可能就是课程中没有详细地讲讲内存管理、文件系统、设备驱动。     
    
#### 自己简单补充一些吧，留个基本的概念，也算让整个linux学习完善一些。    
### 中断  
[中断](https://github.com/xuezhaojiang/LinuxKernel/blob/master/interrupt/interrupt.md)  
### linux文件系统    
[文件系统](https://github.com/xuezhaojiang/LinuxKernel/blob/master/VirtualFilesystem/VirtualFilesystem.md)  
    
### linux内存管理    
[内存管理](https://github.com/xuezhaojiang/LinuxKernel/blob/master/ProcessAddressSpace/ProcessAddressSpace.md)  
    
    
    
    
### 学习建议
&emsp;&emsp;首先建议阅读现代操作系统这本书，对操作系统有个宏观的认识。  
&emsp;&emsp;接下来建议阅读Linux内核设计与实现。这种书籍应该阅读至少两遍。这本书翻译的不是很好，有的句子翻译的不对，词汇的单复数（在我阅读中，发现thread部分，单复数不区分，十分费解），多义连词的翻译，后置定语的翻译，如果阅读中文过程中遇到晦涩难懂甚至违反你过去的认知和逻辑的地方建议对照英文原文。有的比较核心的数据结构没有列出，阅读的时候注意自己翻看源码中的定义。内核服务与进程的内核栈之间的关系没有讲清楚。设备模型那里讲得不行，device、device_driver、bus_type、class这些都没讲，kobject、attribute、relationship如何与用户空间的显示对应也没说，还有就是cdev，我研究了好久没看懂。瑕不掩瑜，比看零碎的博客还是要强的多的。  
&emsp;&emsp;接下来应该时深入理解Linux内核了，按照李老师教学是直接用的这本书，这本书不适合对linux系统没有理解的学生看，或者说仅仅上过本文中提到的线上课程的学生阅读。这本书过于细节，全是结构和代码的讲解，容易理不清思路，陷入混乱。而且有的函数调用过程主线不清晰。现在只是先大概翻了翻，以后再评。  
  
最后给是个复习提纲，在主文件夹下的linux复习。愿诸君好好学习。  