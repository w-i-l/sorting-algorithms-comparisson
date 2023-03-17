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
