#include <stdio.h>
#include <algorithm>

using namespace std;

int n, arr[110000];

int main(){
	scanf("%d",&n);
	for (int i=0; i<n; i++)
		scanf("%d",&arr[i]);
	sort(arr,arr+n);
	for (int i=0,j=n-1,k=0; k<n; k++){
		if (k%2==0) printf("%d\n",arr[i++]);
		else printf("%d\n",arr[j--]);
	}
}
