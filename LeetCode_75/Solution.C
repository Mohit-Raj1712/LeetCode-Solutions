void swap(int* a, int * b);

void sortColors(int* nums, const int N) {
    
    if (N == 1)
        return;

    int left_index = 0, right_index = N - 1, index = 0;

    while (index <= right_index && left_index < right_index)
    {
        if (nums[index] == 2)
        {
            swap(&nums[right_index], &nums[index]);

            right_index --;
        }
        else if (nums[index] == 0)
        {
            swap(&nums[left_index], &nums[index]);

            left_index ++;
            index ++;
        }
        else {

            index ++;
        }
    }

    return;
}

void swap(int* a, int* b) {

    int temp = *a;
    *a = *b;
    *b = temp;

    return;
}