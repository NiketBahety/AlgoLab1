#include <bits/stdc++.h>

using namespace std;

long long comp=0;
double normal_dist[32768];
double uniform_dist[32768];

void n_d(){
    default_random_engine generator;
    std::normal_distribution<double> distribution(0.5, 0.5); // Mean=500 // SD=200
    
    for(int i = 0; i<32768; i++)
    normal_dist[i] = distribution(generator);
}

void u_d(){
    default_random_engine generator;
    uniform_real_distribution<double> distribution(0.0, 1.0);

    for(int i = 0; i<32768; i++)
    normal_dist[i] = distribution(generator);
}

void bucketSort(double arr[], int n)
{
	vector<double> b[n];

	for (int i = 0; i < n; i++) {
		int bi = n * arr[i];
		b[bi].push_back(arr[i]);
          // Added delay
    long long count = 1e5;
    while(count--)
    {}
	}

	for (int i = 0; i < n; i++)
		sort(b[i].begin(), b[i].end());

	int index = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < b[i].size(); j++)
			arr[index++] = b[i][j];
}

int main(){
    n_d();
    u_d();

    cout << "Normal Distribution\n";
    vector<double> times1;

    for(int i=1; i<=15; i++){
        int x = (int)pow(2,i);
        double arr[x];
        for(int j=0; j<x; j++){
            arr[j] = normal_dist[j];
        }
        cout << pow(2,i) << " ";
        clock_t time_req = clock();
        bucketSort(arr, (int)pow(2,i)-1);
        time_req = clock()- time_req;
        double ans = ((float)time_req * log(2) * 1000/CLOCKS_PER_SEC)/(pow(2,i)*log(pow(2,i)));
		times1.push_back(ans);
        cout << " " << ans << " milliseconds" << "\n";
    }
    cout << "\n";
    cout << "Uniform Distribution\n";
    vector<double> times2;
    
    for(int i=1; i<=15; i++){
        int x = (int)pow(2,i);
        double arr[x];
        for(int j=0; j<x; j++){
            arr[j] = uniform_dist[j];
        }
        cout << pow(2,i) << " ";
        clock_t time_req = clock();
        bucketSort(arr, (int)pow(2,i)-1);
        time_req = clock()- time_req;
        double ans = ((float)time_req * log(2) * 1000/CLOCKS_PER_SEC)/(pow(2,i)*log(pow(2,i)));
		times2.push_back(ans);
        cout << " " << ans << " milliseconds" << "\n";
    }

    for(int i=0; i<15; i++)
	cout << times1[i] << ",";
	cout << "\n";
	for(int i=0; i<15; i++)
	cout << times2[i] << ",";
	cout << "\n";
    return 0;
}