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
