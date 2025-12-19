#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

// Sorting Algorithm 1 : Bubble Sort (Time Complexity : O(N^2))
void bubble_sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        // 'i' elements are largest at the last
        for (int j = 1; j <= (n - 1 - i); j++)
        {
            // if left element is greater, then swap the elements
            if (arr[j - 1] > arr[j])
            {
                int temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return;
}

// Sorting Algorithm 2 : Selection Sort (Time Complexity : O(N^2))
void selection_sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        // 'i' elements in start are in sorted order in start
        int minn = INT_MAX;
        int idx = -1;
        // finding the minimum element from i-th position
        for (int j = i; j < n; j++)
        {
            if (arr[j] < minn)
            {
                minn = arr[j];
                idx = j;
            }
        }
        // swap the element to increase 'sorted' 'start'array length by '1'
        int temp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = temp;
    }
}

// Sorting Algorithm 3 : Insertion Sort (Time Complexity : O(N^2))
void insertion_sort(int *arr, int n)
{
    // consider that the first element is sorted
    for (int i = 1; i < n; i++)
    {
        int j = i;
        int ele = arr[i];
        while (1)
        {
            // if ele is smallest among the sorted array, keep at first
            if (j == 0)
            {
                arr[j] = ele;
                break;
            }
            // assume that arr[j] > ele and move the element to right
            arr[j] = arr[j - 1];
            // assumption is wrong, put the element in that position and break
            if (arr[j] <= ele)
            {
                arr[j] = ele;
                break;
            }
            // assumption is true, continue by checking more small elements
            else
                j--;
        }
    }
}

// Sorting Algorithm 4 : Merge Sort (Time Complexity : O(N * (log(N))))
void merge_sort(int *arr, int *temp, int l, int r)
{
    // base case : only one element
    if (l == r)
        return;
    int mid = (l + (r - l) / 2);
    merge_sort(arr, temp, l, mid);
    merge_sort(arr, temp, mid + 1, r);
    // after applying merge sorts on both, both arrays are sorted
    // code for merging two sorted arrays using 'two' pointer approach
    int pt1 = l;
    int pt2 = mid + 1;
    int i = l;
    // looping through both arrays
    while (pt1 <= mid && pt2 <= r)
    {
        if (arr[pt1] >= arr[pt2])
        {
            temp[i] = arr[pt2];
            pt2++;
        }
        else
        {
            temp[i] = arr[pt1];
            pt1++;
        }
        i++;
    }
    while (pt1 <= mid)
    {
        temp[i] = arr[pt1];
        i++;
        pt1++;
    }
    while (pt2 <= r)
    {
        temp[i] = arr[pt2];
        i++;
        pt2++;
    }
    for (int i = l; i <= r; i++)
    {
        arr[i] = temp[i];
    }
}

// Sorting Algorithm 5 : Quick Sort (Time Complexity : O(N*log(N)) [Average Case] & O(N^2) [Worst Case])
void quick_sort(int *arr, int l, int r)
{
    // base case: 0 or 1 element
    if (l >= r)
        return;

    // pick a random index between l and r (inclusive)
    int randidx = l + rand() % (r - l + 1);
    // swap the random element with the last element
    int tempidx = arr[randidx];
    arr[randidx] = arr[r];
    arr[r] = tempidx;

    // last element as pivot
    int pivot = arr[r];
    // pidx represents the partition index
    int pidx = l;
    for (int i = l; i < r; i++)
    {
        // if element is smaller than pivot, then replace the element with ele at pidx
        if (arr[i] < pivot)
        {
            int temp = arr[i];
            arr[i] = arr[pidx];
            arr[pidx] = temp;
            pidx++;
        }
    }

    // after the loop, all elements from idx 0 to pidx-1 are less than pivot
    // after swapping ele at pidx with pivot, all elements after the pivot are greater
    // and before it are less
    int temp = arr[pidx];
    arr[pidx] = arr[r];
    arr[r] = temp;
    quick_sort(arr, l, pidx - 1);
    quick_sort(arr, pidx + 1, r);
}

int main()
{
    srand(time(NULL));
    int choice;
    scanf("%d", &choice);

    int T;
    scanf("%d", &T);

    while (T--)
    {
        int N;
        scanf("%d", &N);
        int *arr = (int *)malloc(N * sizeof(int));
        if (arr == NULL)
        {
            return 1;
        }

        for (int i = 0; i < N; i++)
        {
            scanf("%d", &arr[i]);
        }

        switch (choice)
        {
        case 1:
            bubble_sort(arr, N);
            break;
        case 2:
            selection_sort(arr, N);
            break;
        case 3:
        {
            int *temp = (int *)malloc(N * sizeof(int));
            if (temp == NULL)
            {
                free(arr);
                return 1;
            }
            merge_sort(arr, temp, 0, N - 1);
            free(temp);
            break;
        }
        case 4:
            insertion_sort(arr, N);
            break;
        case 5:
            quick_sort(arr, 0, N - 1);
            break;
        }

        for (int i = 0; i < N; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");

        free(arr);
    }
}
