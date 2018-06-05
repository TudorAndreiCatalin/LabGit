// C++ program for activity selection problem.
// The following implementation assumes that the activities
// are already sorted according to their finish time
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
// Prints a maximum set of activities that can be done by a single
// person, one at a time.
//  n   -->  Total number of activities
//  s[] -->  An array that contains start time of all activities
//  f[] -->  An array that contains finish time of all activities
void printMaxActivities(int s[], int f[], int n)
{
    int i, j;
    vector<int> myvector (f, f+sizeof(f)-1);
    sort(myvector.begin(),myvector.end());
    printf ("Following activities are selected n: ");

    // The first activity always gets selected
    i = 0;
    printf("%d ", i);

    // Consider rest of the activities
    for (j = 1; j < n; j++)
    {
      // If this activity has start time greater than or
      // equal to the finish time of previously selected
      // activity, then select it
      if (s[j] >= myvector[i])
      {
          printf ("%d ", j);
          i = j;
      }
    }
}

// driver program to test above function
int main()
{
    int startTime[] =  {1, 3, 0, 5, 8, 5};
    int finishTime[] =  {4, 2, 7, 6, 9, 9};
    int n = sizeof(startTime)/sizeof(startTime[0]);
    printMaxActivities(startTime,finishTime, n);
    return 0;
}

