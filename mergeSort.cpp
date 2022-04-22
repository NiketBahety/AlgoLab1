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
    uniform_real_distribution<double> distribution(1.0, 1000.0);

    for(int i = 0; i<32768; i++)
    normal_dist[i] = distribution(generator);
}

void merge(double arr[], int l, int mid, int r){
    int n1=mid-l+1;
    int n2=r-mid;

    double a[n1];
    double b[n2];

    for(int i=0; i<n1; i++)
    a[i] = arr[l+i];

    for(int i=0; i<n2; i++)
    b[i] = arr[mid + 1 + i];

    int i=0;
    int j=0;
    int k=l;

    // Added delay
    long long count = 1e5;
    while(count--)
    {}

    while(i<n1 && j<n2){
        if(a[i]<b[j]) {
            arr[k] = a[i];
            k++; i++; comp++;

        }
        else {
            arr[k] = b[j];
            k++; j++; comp++;
        }
    }

    while(i<n1){
        arr[k] = a[i];
            k++; i++; comp++;      
    }

    while(j<n2){
        arr[k] = b[j];
            k++; j++; comp++;
    }
}

void mergeSort(double arr[], int l, int r){

    if(l<r){
    int mid = (l+r)/2;
    mergeSort(arr, l , mid);
    mergeSort(arr, mid+1, r);

    merge(arr, l, mid, r);
    }
}

bool checkForCorrectness(double arr[], int n){
    for(int i=1; i<n; i++){
        if(arr[i] < arr[i-1])
        return false;
    }
    return true;
}

int main(){
    n_d();
    u_d();

    cout << "Normal Distribution\n";

    for(int i=1; i<=15; i++){
        comp = 0;
        int x = (int)pow(2,i);
        double arr[x];
        for(int j=0; j<x; j++){
            arr[j] = normal_dist[j];
        }
        cout << pow(2,i) << " ";
        clock_t time_req = clock();
        mergeSort(arr, 0, (int)pow(2,i)-1);
        time_req = clock()- time_req;
        cout << comp << " " << (float)time_req * 1000/CLOCKS_PER_SEC << " milliseconds" << "\n";
    }
    cout << "\n";
    cout << "Uniform Distribution\n";
    for(int i=1; i<=15; i++){
        comp = 0;
        int x = (int)pow(2,i);
        double arr[x];
        for(int j=0; j<x; j++){
            arr[j] = uniform_dist[j];
        }
        cout << pow(2,i) << " ";
        clock_t time_req = clock();
        mergeSort(arr, 0, (int)pow(2,i)-1);
        time_req = clock()- time_req;
        cout << comp << " " << (float)time_req * 1000/CLOCKS_PER_SEC << " milliseconds" << "\n";
    }
    return 0;
}