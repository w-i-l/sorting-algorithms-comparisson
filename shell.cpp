#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;


bool sorted(int arr[], int no){
    for(int i=0; i<no-1; i++){
        if(arr[i] > arr[i+1]){
            cout << "position: " << i << " " << arr[i] << " " << arr[i+1] << endl;
            return false;
        }
    }
    return true;
}

void shellSort(int array[], int no) {

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

int main(){
    

    srand(time(NULL));
    ////////////////////////////////////////////2147483647
    int minim = 1, maxim = 999999999, nr_elem = 99999999 , base = 1024;
    int* arr = new int[nr_elem];
    for(int i=0; i<nr_elem; i++){
        arr[i] = rand() % maxim;
        // cout << arr[i] << " ";
    }

      // Get starting timepoint
    auto start = high_resolution_clock::now();
 
    // Call the function, here sort()
    // sort(values.begin(), values.end());
    shellSort(arr, nr_elem);
    // Get ending timepoint
    auto stop = high_resolution_clock::now();
 
    // Get duration. Substart timepoints to
    // get duration. To cast it to proper unit
    // use duration cast method
    auto duration = duration_cast<seconds>(stop - start);
 
    cout << "Time taken by function: " << duration.count() << " seconds" << endl;

    cout << (sorted(arr, nr_elem) == 1 ? "elements were sorted" : "there was an error") << endl;
    
    // for(int i=0; i<nr_elem; i++)
    //     cout << arr[i] << ' ';
    // cout << endl;

    delete[] arr;

    return 0;
}