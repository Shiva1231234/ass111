Question =1
/*
#include <bits/stdc++.h>
using namespace std;
 
void solve(vector<vector<int> >& details, int N)
{
 
    // Vector to store the pairs with
    // common values
    vector<int> adj_a[N + 1], adj_b[N + 1];
 
    for (int i = 0; i < N; i++) {
 
        // Storing pairs with same first values
        adj_a[details[i][0]].push_back(details[i][1]);
 
        // Storing pairs with same second values
        adj_b[details[i][1]].push_back(details[i][0]);
    }
 
    // Total ways to choose a triplet from
    // n pairs is nc3
    int ans = (N * (N - 1) * (N - 2)) / 6;
 
    for (int i = 1; i < N + 1; i++) {
 
        // Size to keep record of the elements
        // with same first values
        int size = adj_a[i].size();
 
        for (auto& u : adj_a[i]) {
 
            // Count of pairs that forms
            // invalid triplets
            int same_cnt = adj_b[u].size() - 1;
 
            // Subtracting the invalid values
            ans -= (size - 1) * same_cnt;
        }
    }
    // Printing the answer
    cout << ans << endl;
}
 
// Driver's code
int main()
{
 
    // Given input
    int n = 5;
    vector<vector<int> > details{
        { 1, 4 }, { 2, 4 }, { 3, 3 }, { 4, 2 }, { 1, 2 }
    };
 
    // Function Call
    solve(details, n);
 
    return 0;
}
*\
Q=2
/*
// the above approach
#include <bits/stdc++.h>
using namespace std;
 
// Function to sort the vector elements
// ascending for first element
// and if first element equal
// then descending for second element
bool sortbyCond(const pair<int, int>& a,
                const pair<int, int>& b)
{
    if (a.first != b.first)
        return (a.first < b.first);
    else
       return (a.second > b.second);
}
 
// Driver code
int main()
{
    // Declaring vector of pairs
    vector<pair<int, int> > vect;
 
    // Initialising 1st and 2nd element
    // of pairs with array values
    int arr[] = { 10, 10, 5, 5, 15, 15 };
    int arr1[] = { 40, 60, 20, 50, 12, 24 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // Entering values in vector of pairs
    for (int i = 0; i < n; i++)
        vect.push_back(make_pair(arr[i],
                                 arr1[i]));
 
    // The original vector(before sort())
    cout << "The vector before sort operation is:\n";
    for (int i = 0; i < n; i++) {
        // "first" and "second" are used to
        // access 1st and 2nd element of pair
        // respectively
        cout << vect[i].first << " "
             << vect[i].second << endl;
    }
 
    // Using sort() function to sort by
    // 1st element of pair and if first
    // element equal then by descending
    // order of second element
    sort(vect.begin(), vect.end(), sortbyCond);
 
    // Printing the sorted vector(after
    // using sort())
    cout << "The vector after sort operation is:\n";
    for (int i = 0; i < n; i++) {
        // "first" and "second" are used to
        // access 1st and 2nd element of pair
        // respectively
        cout << vect[i].first << " "
             << vect[i].second << endl;
    }
    return 0;
}
*\
Q=3
/*
// of pairs
#include <bits/stdc++.h>
using namespace std;
  
// Function to print deque elements
void print(deque<pair<int, 
           bool> >& myContainer)
{
    for (auto currentpair : myContainer) 
    {
        // Each element of the deque is
        // a pair itself
        pair<int, bool> pr = currentpair;
  
        cout << "[ ";
  
        // Printing pair elements
        cout << pr.first << ' ' << 
                pr.second;
        cout << ']';
        cout << '\n';
    }
}
  
// Driver code
int main()
{
    // Declaring a deque of pairs
    // of type {int, bool}
    deque<pair<int, bool> >
          myContainer;
  
    // Declaring a pair
    pair<int, bool> pair1;
  
    // Initializing the
    // pair
    pair1 = make_pair(22, false);
  
    // Push the pair at the front
    // in the deque
    myContainer.push_front(pair1);
  
    // Declaring another pair
    pair<int, bool> pair2;
  
    // Initializing the
    // pair
    pair2 = make_pair(33, true);
  
    // Push the pair at the back
    // in the deque
    myContainer.push_back(pair2);
  
    // Declaring another pair
    pair<int, bool> pair3;
  
    // Initializing the pair
    pair3 = make_pair(11, false);
  
    // Push the pair at the front
    // in the deque
    myContainer.push_front(pair3);
  
    // Declaring another pair
    pair<int, bool> pair4;
  
    // Initializing the pair
    pair4 = make_pair(44, true);
  
    // Push the pair at the back
    // in the deque
    myContainer.push_back(pair4);
  
    // Calling print function
    print(myContainer);
    return 0;
}
*\
Q=4
/*
of LIS problem */
#include <iostream>
using namespace std;
 
/* To make use of recursive calls, this
function must return two things:
1) Length of LIS ending with element arr[n-1].
    We use max_ending_here for this purpose
2) Overall maximum as the LIS may end with
    an element before arr[n-1] max_ref is
    used this purpose.
The value of LIS of full array of size n
is stored in *max_ref which is our final result
*/
int _lis(int arr[], int n, int* max_ref)
{
    /* Base case */
    if (n == 1)
        return 1;
 
    // 'max_ending_here' is length of LIS
    // ending with arr[n-1]
    int res, max_ending_here = 1;
 
    /* Recursively get all LIS ending with arr[0],
    arr[1] ... arr[n-2]. If arr[i-1] is smaller
    than arr[n-1], and max ending with arr[n-1]
    needs to be updated, then update it */
    for (int i = 1; i < n; i++) {
        res = _lis(arr, i, max_ref);
        if (arr[i - 1] < arr[n - 1]
            && res + 1 > max_ending_here)
            max_ending_here = res + 1;
    }
 
    // Compare max_ending_here with the overall
    // max. And update the overall max if needed
    if (*max_ref < max_ending_here)
        *max_ref = max_ending_here;
 
    // Return length of LIS ending with arr[n-1]
    return max_ending_here;
}
 
// The wrapper function for _lis()
int lis(int arr[], int n)
{
    // The max variable holds the result
    int max = 1;
 
    // The function _lis() stores its result in max
    _lis(arr, n, &max);
 
    // returns max
    return max;
}
 
/* Driver program to test above function */
int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout <<"Length of lis is "<< lis(arr, n);
    return 0;
}
*\
Q=5
/*
of LIS problem */
#include <iostream>
using namespace std;
 
/* To make use of recursive calls, this
function must return two things:
1) Length of LIS ending with element arr[n-1].
    We use max_ending_here for this purpose
2) Overall maximum as the LIS may end with
    an element before arr[n-1] max_ref is
    used this purpose.
The value of LIS of full array of size n
is stored in *max_ref which is our final result
*/
int _lis(int arr[], int n, int* max_ref)
{
    /* Base case */
    if (n == 1)
        return 1;
 
    // 'max_ending_here' is length of LIS
    // ending with arr[n-1]
    int res, max_ending_here = 1;
 
    /* Recursively get all LIS ending with arr[0],
    arr[1] ... arr[n-2]. If arr[i-1] is smaller
    than arr[n-1], and max ending with arr[n-1]
    needs to be updated, then update it */
    for (int i = 1; i < n; i++) {
        res = _lis(arr, i, max_ref);
        if (arr[i - 1] < arr[n - 1]
            && res + 1 > max_ending_here)
            max_ending_here = res + 1;
    }
 
    // Compare max_ending_here with the overall
    // max. And update the overall max if needed
    if (*max_ref < max_ending_here)
        *max_ref = max_ending_here;
 
    // Return length of LIS ending with arr[n-1]
    return max_ending_here;
}
 
// The wrapper function for _lis()
int lis(int arr[], int n)
{
    // The max variable holds the result
    int max = 1;
 
    // The function _lis() stores its result in max
    _lis(arr, n, &max);
 
    // returns max
    return max;
}
 
/* Driver program to test above function */
int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout <<"Length of lis is "<< lis(arr, n);
    return 0;
}of LIS problem */
#include <iostream>
using namespace std;
 
/* To make use of recursive calls, this
function must return two things:
1) Length of LIS ending with element arr[n-1].
    We use max_ending_here for this purpose
2) Overall maximum as the LIS may end with
    an element before arr[n-1] max_ref is
    used this purpose.
The value of LIS of full array of size n
is stored in *max_ref which is our final result
*/
int _lis(int arr[], int n, int* max_ref)
{
    /* Base case */
    if (n == 1)
        return 1;
 
    // 'max_ending_here' is length of LIS
    // ending with arr[n-1]
    int res, max_ending_here = 1;
 
    /* Recursively get all LIS ending with arr[0],
    arr[1] ... arr[n-2]. If arr[i-1] is smaller
    than arr[n-1], and max ending with arr[n-1]
    needs to be updated, then update it */
    for (int i = 1; i < n; i++) {
        res = _lis(arr, i, max_ref);
        if (arr[i - 1] < arr[n - 1]
            && res + 1 > max_ending_here)
            max_ending_here = res + 1;
    }
 
    // Compare max_ending_here with the overall
    // max. And update the overall max if needed
    if (*max_ref < max_ending_here)
        *max_ref = max_ending_here;
 
    // Return length of LIS ending with arr[n-1]
    return max_ending_here;
}
 
// The wrapper function for _lis()
int lis(int arr[], int n)
{
    // The max variable holds the result
    int max = 1;
 
    // The function _lis() stores its result in max
    _lis(arr, n, &max);
 
    // returns max
    return max;
}
 
/* Driver program to test above function */
int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout <<"Length of lis is "<< lis(arr, n);
    return 0;
}*/
Q=5
/*
of LIS problem */
#include <iostream>
using namespace std;
 
/* To make use of recursive calls, this
function must return two things:
1) Length of LIS ending with element arr[n-1].
    We use max_ending_here for this purpose
2) Overall maximum as the LIS may end with
    an element before arr[n-1] max_ref is
    used this purpose.
The value of LIS of full array of size n
is stored in *max_ref which is our final result
*/
int _lis(int arr[], int n, int* max_ref)
{
    /* Base case */
    if (n == 1)
        return 1;
 
    // 'max_ending_here' is length of LIS
    // ending with arr[n-1]
    int res, max_ending_here = 1;
 
    /* Recursively get all LIS ending with arr[0],
    arr[1] ... arr[n-2]. If arr[i-1] is smaller
    than arr[n-1], and max ending with arr[n-1]
    needs to be updated, then update it */
    for (int i = 1; i < n; i++) {
        res = _lis(arr, i, max_ref);
        if (arr[i - 1] < arr[n - 1]
            && res + 1 > max_ending_here)
            max_ending_here = res + 1;
    }
 
    // Compare max_ending_here with the overall
    // max. And update the overall max if needed
    if (*max_ref < max_ending_here)
        *max_ref = max_ending_here;
 
    // Return length of LIS ending with arr[n-1]
    return max_ending_here;
}
 
// The wrapper function for _lis()
int lis(int arr[], int n)
{
    // The max variable holds the result
    int max = 1;
 
    // The function _lis() stores its result in max
    _lis(arr, n, &max);
 
    // returns max
    return max;
}
 
/* Driver program to test above function */
int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout <<"Length of lis is "<< lis(arr, n);
    return 0;
}*/
Q=6
/*
of LIS problem */
#include <iostream>
using namespace std;
 
/* To make use of recursive calls, this
function must return two things:
1) Length of LIS ending with element arr[n-1].
    We use max_ending_here for this purpose
2) Overall maximum as the LIS may end with
    an element before arr[n-1] max_ref is
    used this purpose.
The value of LIS of full array of size n
is stored in *max_ref which is our final result
*/
int _lis(int arr[], int n, int* max_ref)
{
    /* Base case */
    if (n == 1)
        return 1;
 
    // 'max_ending_here' is length of LIS
    // ending with arr[n-1]
    int res, max_ending_here = 1;
 
    /* Recursively get all LIS ending with arr[0],
    arr[1] ... arr[n-2]. If arr[i-1] is smaller
    than arr[n-1], and max ending with arr[n-1]
    needs to be updated, then update it */
    for (int i = 1; i < n; i++) {
        res = _lis(arr, i, max_ref);
        if (arr[i - 1] < arr[n - 1]
            && res + 1 > max_ending_here)
            max_ending_here = res + 1;
    }
 
    // Compare max_ending_here with the overall
    // max. And update the overall max if needed
    if (*max_ref < max_ending_here)
        *max_ref = max_ending_here;
 
    // Return length of LIS ending with arr[n-1]
    return max_ending_here;
}
 
// The wrapper function for _lis()
int lis(int arr[], int n)
{
    // The max variable holds the result
    int max = 1;
 
    // The function _lis() stores its result in max
    _lis(arr, n, &max);
 
    // returns max
    return max;
}
 
/* Driver program to test above function */
int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout <<"Length of lis is "<< lis(arr, n);
    return 0;
}*/