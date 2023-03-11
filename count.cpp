#include <iostream>
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

void count_sort(int arr[], int no, int maxim){

    int* indexes = new int[maxim];

    for(int i=0; i<maxim; i++)
        indexes[i] = 0;

    for(int i=0; i<no; i++)
        indexes[arr[i]] ++;

    int i=0, k=0;
    while(i < maxim){
        if(indexes[i]){
            for(int j=0; j<indexes[i]; j++, ++k)
                arr[k] = i;
        }

        i++;
    }

    delete[] indexes;
}


int main(){

    srand(time(NULL));

    int minim = 1, maxim = 200000000, nr_elem = 200000000;
    int* arr = new int[nr_elem];
    for(int i=0; i<nr_elem; i++){
        arr[i] = rand() % maxim;
        // cout << arr[i] << " ";
    }

      // Get starting timepoint
    auto start = high_resolution_clock::now();
 
    // Call the function, here sort()
    // sort(values.begin(), values.end());
    count_sort(arr, nr_elem, maxim);
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

    return 0;
}