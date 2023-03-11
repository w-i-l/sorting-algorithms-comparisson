#include <iostream>
#include <fstream>
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

void quicksort(int* arr, int* copy, int left, int right){
    
    if(left>=right) return;
    
    srand(time(NULL));
    int pivot = rand() % (right-left+1) + left;
    
    int index = left,last = right;
    
    
    for(int i=left;i<=right;i++){
        if(arr[i] < arr[pivot]){
            copy[index++] = arr[i];
        }
        else if(arr[i] > arr[pivot]){
            copy[last--] = arr[i];
            
        }
        else{
            if(arr[i] == arr[pivot] && i != pivot){
                copy[index++] = arr[i];
            }
        }
    }
    
    copy[index] = arr[pivot];
    
    for(int i=left;i<=right;i++){
        arr[i] = copy[i];
    }
    
    
    quicksort(arr, copy, left,index-1);
    quicksort(arr, copy, index+1,right);

}


int main()
{
    
    
    srand(time(NULL));

    int minim = 1, maxim = 200000000, nr_elem = 200000000;
    int* arr = new int[nr_elem];
    int* copy = new int[nr_elem];
    for(int i=0; i<nr_elem; i++){
        arr[i] = rand() % maxim;
        // cout << arr[i] << " ";
    }

      // Get starting timepoint
    auto start = high_resolution_clock::now();
 
    // Call the function, here sort()
    // sort(values.begin(), values.end());
    quicksort(arr, copy, 0, nr_elem-1);
    // Get ending timepoint
    auto stop = high_resolution_clock::now();
 
    // Get duration. Substart timepoints to
    // get duration. To cast it to proper unit
    // use duration cast method
    auto duration = duration_cast<milliseconds>(stop - start);
 
    cout << "Time taken by function: " << duration.count() << " milliseconds" << endl;

    cout << (sorted(arr, nr_elem) == 1 ? "elements were sorted" : "there was an error") << endl;
    
    // for(int i=0; i<nr_elem; i++)
    //     cout << arr[i] << ' ';
    // cout << endl;

    delete[] arr;


}