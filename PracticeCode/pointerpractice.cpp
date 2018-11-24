#include <iostream>
#include <cstring>
using namespace std;

void reverse(char* a) {
    char* first = a;
    char* last = a;
    while(*last) {
        last++;
    }
    last--;

    while(first < last) {
        char temp = *first;
        *first = *last;
        *last = temp;
        first++;
        last--;
    }
}

void descSort(int* nums, int len) {
    for(int* i = nums; i < (nums + len - 1); i++) {
        int* next = i + 1;
        int* posGreatest = i;
        int greatest = *i;
        while(next < nums + len) {
            if(greatest < *next) {
                greatest = *next;
                posGreatest = next;
            }
            next++;
        }
        int temp = *i;
        *i = *posGreatest;
        *posGreatest = temp;
    }
}

void minMax(int arr[], int n, int*& min, int*& max) {
    int minimum = arr[0];
    int maximum = arr[0];
    for(int i = 0; i < n; i++) {
        if(arr[i] > maximum) {
            maximum = arr[i];
            max = &arr[i];
        }
        if(arr[i] < minimum) {
            minimum = arr[i];
            min = &arr[i];
        }
    }
}

void mergeAndSort(int* nums1, int* nums2, int* merged, int len1, int len2) {
    int count = len1;
    switch(count/1) {
      case 0:
        while(nums2 < nums2 + len2) {
          *merged = *num2;
          merged++;
          nums2++;
        }
        break;
      default:
        while(nums1 < nums1 + len1) {
          *merged = *num1;
          merged++;
          nums1++;
          count--;
        }
    }
}

int main() {
    // char string[] = "kayak!";
    // reverse(string);
    // cout << string << endl;
    // char a[] = "racecar";
    // reverse(a);
    // cout << a << endl;
    // char b[] = "dennis";
    // reverse(b);
    // cout << b << endl;

    // int nums[] = {3,1,4,0,-1,2,3,4,1,2};
    // descSort(nums, 10);
    // for(int i = 0; i < 10; i++) {
    //     cout << nums[i] << ", ";
    // }

    int arr[5] = {0,5,7,-10,2};
    int* pmin;
    int* pmax;
    minMax(arr, 5, pmin, pmax);
    cout << *pmin << " " << *pmax << endl;
}
