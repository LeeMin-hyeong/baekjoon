#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int *a, int start, int end, int find){
    while(start<=end){
        int mid=(start+end)/2;
        if(a[mid]==find) return 1;
        else if(find<a[mid]) end=mid-1;
        else start=mid+1;
    }
    return 0;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n=0, m=0;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a, a+n);

    cin>>m;
    int b[m];
    for(int i=0; i<m; i++)
        cin>>b[i];
    for(int i=0; i<m; i++)
        cout<<binarySearch(a, 0, n-1, b[i])<<"\n";
}

