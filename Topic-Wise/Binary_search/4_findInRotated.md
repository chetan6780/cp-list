# Find Element in Rotated array

-   If we can find the index of minimum element, we can divide array in 2 sorted subarray.
-   then we can binary search in those both subarray separately, one of them return -1 while other return index of element.
-   return the max(left subarray, right subarray)

### Code

```cpp
int findInRotated(vector<int>& a)
{
    int n = a.size();
    int minElemIndex = numberOfTimesRotated(a);
    // binarySearch(array, StartIndex, EndIndex);
    return max(binarySearch(a, 0, minElemIndex), binarySearch(a, minElemIndex, n - 1));
}
```
