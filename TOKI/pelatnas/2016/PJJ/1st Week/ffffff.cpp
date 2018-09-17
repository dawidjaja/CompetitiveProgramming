#include <algorithm>
#include <cstdio>
#include <stack>
using namespace std;
int main ()
{
	while (true)
	{
		int numBars,barHeights[100005];
		scanf("%d",&numBars);
		if (numBars==0)
		{
			return 0;
		}
		for (int i=0;i<numBars;i++)
		{
			scanf("%d",&barHeights[i]);
		}
	    if (numBars <= 0)
	        return 0;
	 
	    int maxArea = 0;
		stack <int> stk;
	    stk.push (0);
	    
	    for (int i=1; i < numBars; i++)
	    {
	        int currEle = barHeights[i];
	 
	        while (stk.empty() == false)
	        {
	            int stackTop = stk.top(); // peep gets stack top without removing
	 
	            if ( currEle > barHeights[stackTop] )
	            {
	                stk.push (i);
	                break;
	            }
	            
	            stackTop = stk.top();
				stk.pop(); // pop gets stack top with removal
	 
	            // Since stack only stores elements in increasing order, any element
	            // just below an element must give the leftmost boundary of the rectangle
	            // containing current element
	 
	            // if stack is empty, then the popped element is minimum so far            
	            int leftBoundary = stk.empty() ? 0 : stk.top(); 
	            int rightBoundary = (barHeights[stackTop] == currEle) ? i : i-1;
	 
	            int area = (rightBoundary - leftBoundary) * barHeights[stackTop];
	            if (area > maxArea)
	            {
	           		printf("- %d -\n",stackTop);
	                maxArea = area;
				}
	        }
	        
	        if (stk.empty())
	            stk.push (i);
	    }
	 
	    // empty the remaining stack
	    int rightBoundary = numBars;
	    while (stk.empty() == false)
	    {
	        int stackTop = stk.top();
	        stk.pop();
	        int leftBoundary = stk.empty() ? 0 : stk.top();
	        int area = (rightBoundary - leftBoundary) * barHeights[stackTop];
	        if (area > maxArea)
	        {
	            maxArea = area;
	            printf("- %d -\n",stackTop);
			}
	    }
		printf("%d\n",maxArea);
	}
}
