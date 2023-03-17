#include <iostream>
#include <cmath>
#include <ctime>
#include <chrono>
#include <cstring>
#include <fstream>


#define time_unit milliseconds


using namespace std;
using namespace std::chrono;


// returns true if the array is sorted
bool sorted(int arr[], int no){
    for(int i=0; i<no-1; i++){
        if(arr[i] > arr[i+1]){
            cout << "position: " << i << " " << arr[i] << " " << arr[i+1] << endl;
            return false;
        }
    }
    return true;
}


void count_sort(int arr[], int no, int maxim){

    // the of all numbers from 0 to maxim
    int* indexes = new int[maxim];

    // reseting
    for(int i=0; i<maxim; i++)
        indexes[i] = 0;

    // indexing
    for(int i=0; i<no; i++)
        indexes[arr[i]] ++;

    // i - index for indexes array
    // k - index for arr array
    int i=0, k=0;

    // moving back to the original array
    while(i < maxim){

        if(indexes[i]){
            for(int j=0; j<indexes[i]; j++, ++k)
                arr[k] = i;
        }

        i++;
    }

    delete[] indexes;
}


void merge(int arr[], int l, int mid, int r){

    // indexes for arrays
    int i = 0 , j = 0 , k = l;

    // upper limits for arrays
    int n1 = mid - l + 1;
    int n2 = r - mid;

    // creates the two arrays
    int* arr1 = new int[n1];
    int* arr2 = new int[n2];

    // copy data to arrays
    for(int i=0; i<n1; i++)
        arr1[i] = arr[l + i];

    for(int i=0; i<n2; i++)
        arr2[i] = arr[mid + i + 1];

    // merging
    while(i < n1 && j < n2){
        if(arr1[i] <= arr2[j]){
            arr[k] = arr1[i];
            i++;
        }
        else{
            arr[k] = arr2[j];
            j++;
        }

        k++;
    }

    // if there are any elements left
    while(i < n1){
        arr[k++] = arr1[i++];
    }

    while(j < n2)
        arr[k++] = arr2[j++];

    delete[] arr1;
    delete[] arr2;
}


void merge_sort(int arr[], int l, int r){

    // stop condition
    if(l < r){
        int mid = (l + r - 1) / 2;

        merge_sort(arr, l, mid);
        merge_sort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}


void quicksort(int a[], int left, int right){

    // stop condition
    if(left < right){

        // poz - the random index
        int poz = rand() % (right-left+1) + left, pivot = a[poz];

        int i = left - 1;

        // in place swapping
        for(int j=left; j<=right; ++j){
            if(a[j] < pivot){
                i++;
                if(i == poz){
                    poz = j;
                }
                swap(a[i], a[j]);
            }
        }
        swap(a[++i], a[poz]);

        quicksort(a, left, i - 1);
        quicksort(a, i + 1, right);
    }
}


// arr - the array, no - number of elements
// base - the base of radix
// n - represents the index of current digit (ex. in 1234 2 has the n=2)
// aux - represents the array of digits
// copy - represents an array for copying elements
void pseudo_count_sort(int* arr, int no, int base, int n, int* aux, int* copy){
    
    // array with all elements from 0 to base-1
    // int* aux = new int[base];
    // int* copy = new int[no];
    int a = 1;
    
    // a = pow(base, n)
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
    
}


void radix_sort(int arr[], int no, int base){
    int max_digits = 0;

    int* aux = new int[base];
    int* copy = new int[no];

        // counting
        for(int i=0; i<no; i++){
            int digits = ceil(log(arr[i]) / log(base));
            if(digits > max_digits) max_digits = digits;
        }
        
        // sorting
        for(int i=0; i<max_digits; i++){
            pseudo_count_sort(arr, no, base, i, aux, copy);
        }
    
    delete[] aux;
    delete[] copy;
}


void shell_sort(int array[], int no) {

    // using the standard shell gap
    for (int space = no / 2; space > 0; space /= 2) {

        //
        for (int i = space; i <= no; i += 1) {

        int temp = array[i];
        int j;

        for (j = i; j >= space && array[j - space] > temp; j -= space) {
            array[j] = array[j - space];
        }

        array[j] = temp;
        }
    }
}

// copy array from src to dest
void copy_array(int* dest, int* src, int no){
    for(int i=0; i<no; i++)
        dest[i] = src[i];
}


// takes the input from main() and converts to run
// teh current program
void convert_input(int arg, char** args, int* maxim, int* nr_elem, int* base){

    *maxim = 0; *nr_elem = 0; *base = 0;

    if(args[1][0] != '-' || args[2][0] != '-' || args[3][0] != '-' ) exit(-1);

    for(int i=1; i<strlen(args[1]); i++) *maxim = *maxim * 10 + (args[1][i] - '0');
    for(int i=1; i<strlen(args[2]); i++) *nr_elem = *nr_elem * 10 + (args[2][i] - '0');
    for(int i=1; i<strlen(args[3]); i++) *base = *base * 10 + (args[3][i] - '0');

    if(*maxim > 100000000 || *nr_elem > 100000000 || *base > 100000000) exit(-1);

}


int main(int arg, char** args){

    srand(time(NULL));
    int minim = 1, maxim, nr_elem, base;

    convert_input(arg, args, &maxim, &nr_elem, &base);

    int* arr = new int[nr_elem+1];
    int* copy = new int[nr_elem+1];
    int* initial_array = new int[nr_elem+1];

    ofstream f("rezultate.txt", ios::app);

    for(int i=0; i<nr_elem; i++){
        arr[i] = rand() % maxim;
        initial_array[i] = arr[i];
    }

    f << maxim << " " << nr_elem << " " << base << " " ;

    ////////////////////////////////////////////////////////////////////////////////////////////////

    auto start = high_resolution_clock::now();

    count_sort(arr, nr_elem, maxim);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<time_unit>(stop - start);
 
    f << "Count " << duration.count() << " ";

    ////////////////////////////////////////////////////////////////////////////////////////////////

    copy_array(arr, initial_array, nr_elem);

    start = high_resolution_clock::now();

    quicksort(arr, 0, nr_elem-1);

    stop = high_resolution_clock::now();

    duration = duration_cast<time_unit>(stop - start);
 
    f << "Quick " << duration.count() << " ";

    ////////////////////////////////////////////////////////////////////////////////////////////////

    copy_array(arr, initial_array, nr_elem); 

    start = high_resolution_clock::now();

    radix_sort(arr, nr_elem, base);

    stop = high_resolution_clock::now();

    duration = duration_cast<time_unit>(stop - start);
 
    f << "Radix " << duration.count() << " ";
    
    ////////////////////////////////////////////////////////////////////////////////////////////////

    copy_array(arr, initial_array, nr_elem);

    start = high_resolution_clock::now();

    shell_sort(arr, nr_elem);

    stop = high_resolution_clock::now();

    duration = duration_cast<time_unit>(stop - start);
 
    f << "Shell " << duration.count() << " ";
    
    ////////////////////////////////////////////////////////////////////////////////////////////////

    copy_array(arr, initial_array, nr_elem);

    start = high_resolution_clock::now();

    merge_sort(arr, 0, nr_elem-1);

    stop = high_resolution_clock::now();

    duration = duration_cast<time_unit>(stop - start);
 
    f << "Merge " << duration.count() << " ";
    
    ////////////////////////////////////////////////////////////////////////////////////////////////
    
    f << endl;


    delete[] arr;
    delete[] copy;
    delete[] initial_array;
    
}
