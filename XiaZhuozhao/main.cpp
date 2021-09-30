#include "omp.h"
#include "trapezoid.h"
#include "iostream"
using namespace std;


double parallel_fun()
{
    //You should return a double type result to the main function
    //write your code here
    double result = 0;
    int k;
    #pragma omp parallel for num_threads(THREADS_NUM) reduction(+:result)
	for(k = LOW_LIMIT; k < UPPER_LIMIT; k ++) {
        double branch_result = 0;
		for(double i = k; i < k+1; i += STEP)
        {
            branch_result += i*i+5;
        }
        result += branch_result;
	}
    result = result * 0.0000001;
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