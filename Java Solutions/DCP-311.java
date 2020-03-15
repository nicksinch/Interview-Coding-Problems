/*
    This problem was asked by Sumo Logic.

    Given an unsorted array, in which all elements are distinct, find a "peak" element in O(log N) time.

    An element is considered a peak if it is greater than both its left and right neighbors.

    It is guaranteed that the first and last elements are lower than all others.

    The idea is to use Binary Search approach, obviously.
*/


public class AlgoClass {
    public static int findPeak(int[] arr, int length, int left, int right)
    {
        int mid = (left + right) / 2;
        if((mid == 0 || arr[mid]>= arr[mid-1]) && (mid == length - 1 || arr[mid] >= arr[mid+1]))
            return mid; // We have found the peak
        if(mid - 1 >= 0 && arr[mid-1] > arr[mid])
            return findPeak(arr,length, left, mid - 1);

        return findPeak(arr,length,mid + 1, right);
    }
    public static void main(String[] args){
        int testFuncArr[] = {8,9,10,12,15};
        int peakIndex = findPeak(testFuncArr, 5, 0, 4);
        System.out.println(peakIndex);
    }
}
