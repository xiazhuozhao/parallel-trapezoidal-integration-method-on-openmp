#parallel-trapezoidal-integration-method-on-openmp  
This is the daily pratice No.202001 of the team for supercomputer in Southwest Petroleum University（西南石油大学超算与并行计算团队）.  
Please install [GitHub with MathJax](https://chrome.google.com/webstore/detail/mathjax-plugin-for-github/ioemnmodlmafdkllaclgeombjnmnbima) to see the formula.
# The structure of folders
> ├── XiaZhuozhao  --my answer  
> │   ├── main.cpp  --main cpp file  
> │   └── trapezoid.h  --the cpp header file  
> └── original question  
>     ├── 性能优化过程记录表.xlsx --examinees are required to record their process of optimization  
>     ├── 优化要求.pdf --the main requirement PDF file of this problem  
>     ├── main.cpp --main cpp file  
>     └── trapezoid.h --the cpp header file  
# Problem
As we all known, the trapezoidal method can approximately solve the definite integral of a function. OpenMP is a basic tool of the parallel programming of the C language. Now, you are required to use OpenMP to realize the trapezoidal method of given definite integral for approximate solution optimization, the step length should not be more than $1*10^{-7}$. One percent error is allowed.  
$$\int_0^{10000}(x^2-5)dx$$
# Judge platform
* i7 10750H with 12 logical processors
* 32GB memory
* Linux64, GCC 8.3
# My solution
The conputing task was divided into 10000 parts, every parts are the minimum parallel conputing units. For every unit, the program will operation $1*10^7$ times, to satisfy the requirement of the minimun step length. Such operation is used to avoid the maximum limit of the integer (the integer is only permitted in the for loop in some versions of OpenMP as the incremental expression).  
What's more, i optimized the algorithm. The original algorithm:
$$\sum_{i=0}^{1*10^{11}}(f(i*10^{-18})+f((i+1)*10^{-18}))*0.5*10^{-7}$$
After algorithm optimizatiom, we could just calculate:  
$$10^{-7}*\sum_{i=0}^{1*10^{11}}f(i*10^{-18})$$
It significantly reduced the time comsume of each computing unit.  
# Result
* Original serial running time consuption: 323128ms
* My time consuption: 34121.3ms
* 10.06 times faster than before
