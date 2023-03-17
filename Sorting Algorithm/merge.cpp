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
