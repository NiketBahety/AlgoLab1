#include <bits/stdc++.h>

using namespace std;

void insertion_sort(short arr[], int initial, int final)
{
    for (int i = initial; i <= final; i++)
    {
        int value = arr[i];
        int pos = i - 1;
        while (pos >= initial && arr[pos] > value)
        {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = value;
    }
}

int give_median(short arr[], int initial, int final)
{
    insertion_sort(arr, initial, final);
    int mid = (initial + final) / 2;
    return arr[mid];
}

int median_of_median(short arr[], int arr_size, int divide_size)
{
    if (arr_size < divide_size)
    {
        int median = give_median(arr, 0, arr_size - 1);
        return median;
    }

    int no_full_group = arr_size / divide_size;
    int elements_in_last = arr_size % divide_size;

    int next_arr_size;

    if (elements_in_last == 0)
        next_arr_size = no_full_group;
    else
        next_arr_size = no_full_group + 1;

    short next_arr[next_arr_size];

    for (int i = 0; i < next_arr_size; i++)
    {
        if (i == next_arr_size-1)
            next_arr[i] = give_median(arr, divide_size * i, next_arr_size - 2);
        else
            next_arr[i] = give_median(arr, divide_size * i, divide_size * (i + 1) - 1);
    }

    return median_of_median(next_arr, next_arr_size, divide_size);
}

int main()
{
    srand(time(0));
    vector<float> ans;
    vector<float> num;

    for(int i=10; i<10000; i++){
    num.push_back(i);

    int arr_size = i;

    short arr[arr_size];

    for (int i = 0; i < arr_size; i++)
        arr[i] = rand() % 100;

    short copy[arr_size];

    for (int i = 0; i < arr_size; i++)
        copy[i] = arr[i];

    int val = median_of_median(arr, arr_size, 5);
    vector<int> check;

    for(int i=0; i<arr_size; i++){
        if(arr[i] == val){
        check.push_back(i+1);
    }
    }

    ans.push_back(check[(check.size())/2]/(float)arr_size);
    }

    for(int i=0; i<ans.size(); i++)
    cout << num[i] << ",";
    return 0;
}