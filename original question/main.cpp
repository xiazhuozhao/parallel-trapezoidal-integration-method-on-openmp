#include "omp.h"
#include "trapezoid.h"
#include "iostream"
using namespace std;

double parallel_fun()
{
    //You should return a double type result to the main function
    //write your code here
    double result = 0, a, b;
    omp_set_num_threads(THREADS_NUM);
    for(double i=LOW_LIMIT; i<=UPPER_LIMIT;)
    {
        a = i*i+5;
        i += STEP;
        b = i*i+5;
        result += (a+b)*HALF_STEP;
    }
    return result;
}

int main(){
    //DO NOT CHANGE THE MAIN FUNCTION
    double start = omp_get_wtime();
    cout << "Program Started" << endl;
    double result = parallel_fun();
    double end = 1000*(omp_get_wtime() - start);
    cout << "Time consumption is " << end << "ms" << endl;
    cout << "Your result is " << result << endl;
    return 0;
}