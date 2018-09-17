#include <algorithm>
#include <cstdio>
#include <stack>
using namespace std;
long long height[1000000],n;
stack <long long> left,index;
long long largestRectangleArea() {  
   long long area = 0;  
   // stack to store the indices of left boundary  
   // left boundary is the last height that is not lower than the current one  
   long long cur = 0;  
   while (cur < n) {  
     if (cur == 0 || height[cur] > height[index.top()]) {  
       left.push(cur); 	 
       index.push(cur);  
     } else if (height[cur] < height[index.top()]) {  
       long long last;  
       do {  
         last = left.top();
		 left.pop(); 
         area = max(area, height[index.top()] * (cur - last));  
         index.pop();
       } while (!left.empty() && height[cur] < height[index.top()]);  
       left.push(last);  
       index.push(cur);  
     }  
     cur++;  
   }  
   // pop out values in index and left and calculate their areas  
   while (!index.empty() && !left.empty()) {  
     area = max(area, height[index.top()] * (n - left.top()));  
     index.pop();
     left.pop();
   }  
   
   return area;  
 }  
int main ()
{
	while (true)
	{
		scanf("%lld",&n);
		if (n==0)
		{
			return 0;
		}
		for (long long i=0;i<n;i++)
		{
			scanf("%lld",&height[i]);
		}
		printf("%lld\n",largestRectangleArea());
	}
	return 0;
}
