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

int partition(double arr[], int low, int high)
{
    double pivot = arr[high];
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++)
    {
        comp++;
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

int partition_r(double arr[], int low, int high)
{
    srand(time(NULL));
    int random = low + rand() % (high - low);
 
    swap(arr[random], arr[high]);
 
    return partition(arr, low, high);
}

void quickSort(double arr[], int low, int high)
{
    // Added delay
    long long count = 1e5;
    while(count--)
    {}
    
    if (low < high) {
        int pi = partition_r(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// int main()
// {

// 	double arr[] = { 9, 3, 4, 2, 1, 8, 1, -1.5, -2 };
// 	int n = 9;

// 	quickSort(arr, 0, n - 1);

// 	for (int i = 0; i < n; i++) {
// 		cout << arr[i] << " ";
// 	}

// 	return 0;
// }


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
        cout << (comp*log(2))/(pow(2,i)*log(pow(2,i))) << " " << ans << " milliseconds" << "\n";
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
        cout << (comp*log(2))/(pow(2,i)*log(pow(2,i))) << " " << ans << " milliseconds" << "\n";
    }

	for(int i=0; i<15; i++)
	cout << times1[i] << ",";
	cout << "\n";
	for(int i=0; i<15; i++)
	cout << times2[i] << ",";
	cout << "\n";
    return 0;
}