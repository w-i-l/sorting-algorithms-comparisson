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
