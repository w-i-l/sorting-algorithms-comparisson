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

    if(l < r){
        int mid = (l + r - 1) / 2;

        merge_sort(arr, l, mid);
        merge_sort(arr, mid+1, r);

        merge(arr, l, mid, r);
    }
}


int main(){


    srand(time(NULL));
    ////////////////////////////////////////////2147483647
    ////////////////////////////////////////////100000000
    int minim = 1, maxim = 999999999, nr_elem = 100000000;
    int* arr = new int[nr_elem];
    for(int i=0; i<nr_elem; i++){
        arr[i] = rand() % maxim;
        // cout << arr[i] << " ";
    }

      // Get starting timepoint
    auto start = high_resolution_clock::now();
 
    // Call the function, here sort()
    // sort(values.begin(), values.end());
    merge_sort(arr, 0, nr_elem-1);
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