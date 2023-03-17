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
