#include <bits/stdc++.h>
using namespace std;

long long comp=0;
double normal_dist[32768];
double uniform_dist[32768];

void n_d(){
    default_random_engine generator;
    std::normal_distribution<double> distribution(500.0, 200.0); // Mean=500 // SD=200
    
    for(int i = 0; i<32768; i++)
    normal_dist[i] = distribution(generator);
}

void u_d(){
    default_random_engine generator;
    uniform_real_distribution<double> distribution(1.0, 200.0);

    for(int i = 0; i<32768; i++)
    uniform_dist[i] = distribution(generator);
}

void insertion_sort(double arr[], int initial, int final)
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

int give_median(double arr[], int initial, int final)
{
    insertion_sort(arr, initial, final);
    int mid = (initial + final) / 2;
    return arr[mid];
}

int median_of_median(double arr[], int arr_size, int divide_size)
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

    double next_arr[next_arr_size];

    for (int i = 0; i < next_arr_size; i++)
    {
        if (i == next_arr_size-1)
            next_arr[i] = give_median(arr, divide_size * i, next_arr_size - 2);
        else
            next_arr[i] = give_median(arr, divide_size * i, divide_size * (i + 1) - 1);
    }

    return median_of_median(next_arr, next_arr_size, divide_size);
}

int partition(double arr[], int start, int end)
{

	double pivot = arr[median_of_median(arr, end, 5)];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}

	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);

	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i] <= pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

void quickSort(double arr[], int start, int end)
{

	if (start >= end)
		return;
	
	// Added delay
    long long count = 1e5;
    while(count--)
    {}

	int p = partition(arr, start, end);
    comp++;

	quickSort(arr, start, p - 1);
	quickSort(arr, p + 1, end);
}

int main(){
    n_d();
    u_d();

    cout << "Normal Distribution\n";
    vector<double> times1;

    for(int i=1; i<=15; i++){
        comp = 0;
        int x = (int)pow(2,i);
        double arr[x];
        for(int j=0; j<x; j++){
            arr[j] = normal_dist[j];
        }
        cout << pow(2,i) << " ";
        clock_t time_req = clock();
        quickSort(arr, 0, (int)pow(2,i)-1);
        time_req = clock()- time_req;
		double ans = ((float)time_req * log(2) * 1000/CLOCKS_PER_SEC)/(pow(2,i)*log(pow(2,i)));
		times1.push_back(ans);
        cout << comp/pow(2,i) << " " << ans << " milliseconds" << "\n";
    }
    cout << "\n";
    cout << "Uniform Distribution\n";
	vector<double> times2;
    for(int i=1; i<=15; i++){
        comp = 0;
        int x = (int)pow(2,i);
        double arr[x];
        for(int j=0; j<x; j++){
            arr[j] = uniform_dist[j];
        }
        cout << pow(2,i) << " ";
        clock_t time_req = clock();
        quickSort(arr, 0, (int)pow(2,i)-1);
        time_req = clock()- time_req;
		double ans = ((float)time_req * log(2) * 1000/CLOCKS_PER_SEC)/(pow(2,i)*log(pow(2,i)));
		times2.push_back(ans);
        cout << comp/pow(2,i) << " " << ans << " milliseconds" << "\n";
    }

	for(int i=0; i<15; i++)
	cout << times1[i] << ",";
	cout << "\n";
	for(int i=0; i<15; i++)
	cout << times2[i] << ",";
	cout << "\n";
    return 0;
}