/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <cmath>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

bool sorted(int arr[], int no){
    for(int i=0; i<no-1; i++){
        if(arr[i] > arr[i+1])
            return false;
    }
    return true;
}


void count_sort_pow2(int* arr, int no, int base, int base_power_2, int n, int* aux, int* copy){


    // reseting
    for(int i=0; i<base; i++) aux[i] = 0;
    
    // indexing
    for(int i=0; i<no; i++){
        int digit = (arr[i] >> (n)) & (base-1);
        aux[digit]++;
    }
    
    // summing
    for(int i=1; i<base; i++)
        aux[i] += aux[i-1];
    
    // sorting
    for(int i=no-1; i>-1; i--){
        int digit = (arr[i] >> (n)) & (base-1);
        copy[--aux[digit]] = arr[i];
    }
    
    // moving
    for(int i=0; i<no; i++){
        arr[i] = copy[i];
    }
}


void count_sort(int* arr, int no, int base, int n, int* aux, int* copy){
    
    // array with all elements from 0 to base-1
    // int* aux = new int[base];
    // int* copy = new int[no];
    int a = 1;
    
    while(n){
        a*=base;
        n--;
    } 
    
    // reseting
    for(int i=0; i<base; i++) aux[i] = 0;
    
    // indexing
    for(int i=0; i<no; i++){
        int digit = (arr[i]/a) % base;
        aux[digit]++;
    }
    
    // summing
    for(int i=1; i<base; i++)
        aux[i] += aux[i-1];
    
    // sorting
    for(int i=no-1; i>-1; i--){
        int digit = (arr[i]/a) % base;
        copy[--aux[digit]] = arr[i];
    }
    
    // moving
    for(int i=0; i<no; i++){
        arr[i] = copy[i];
    }
    
    // delete[] aux;
    // delete[] copy;
}


void radix_sort(int arr[], int no, int base){
    int max_digits = 0;

    int* aux = new int[base];
    int* copy = new int[no];
    
    // if(log2(base) == (int)log2(base)){
        
    //     cout << "Sorting a 2 base" << endl;

    //     int base_power2 = log2(base);
    //     //cout << base_power2<< endl;

    //     // counting
    //     for(int i=0; i<no; i++){
    //         int digits = ceil(log2(arr[i]));
    //         if(digits > max_digits) max_digits = digits;
    //     }
        
    //     // sorting
    //     for(int i=0; i<max_digits; i++){
    //         count_sort_pow2(arr, no, base,base_power2, i, aux, copy);
    //     }
    // }
    // else{

    //     cout << "Sorting a non 2 base" << endl;

        // counting
        for(int i=0; i<no; i++){
            int digits = ceil(log(arr[i]) / log(base));
            if(digits > max_digits) max_digits = digits;
        }
        
        // sorting
        for(int i=0; i<max_digits; i++){
            count_sort(arr, no, base, i, aux, copy);
        }
    // }

    

    delete[] aux;
    delete[] copy;
}

int main()
{   
    srand(time(NULL));
    
    int minim = 1, maxim = 999999999, nr_elem = 100000000 , base = 1048576;
    int* arr = new int[nr_elem];
    for(int i=0; i<nr_elem; i++){
        arr[i] = rand() % maxim;
        // cout << arr[i] << " ";
    }

      // Get starting timepoint
    auto start = high_resolution_clock::now();
 
    // Call the function, here sort()
    // sort(values.begin(), values.end());
    radix_sort(arr, nr_elem , base);
    // Get ending timepoint
    auto stop = high_resolution_clock::now();
 
    // Get duration. Substart timepoints to
    // get duration. To cast it to proper unit
    // use duration cast method
    auto duration = duration_cast<milliseconds>(stop - start);
 
    cout << "Time taken by function: " << duration.count() << " milliseconds" << endl;

    // for(int i=0; i<nr_elem; i++)
    //     cout << arr[i] << ' ';
    // cout << endl;
    
    cout << (sorted(arr, nr_elem) == 1 ? "elements were sorted" : "there was an error") << endl;

    delete[] arr;
    return 0;
}
