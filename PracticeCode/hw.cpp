#include <iostream>
using namespace std;

//1a
void printArray() {
  int arr[3] = {5, 10, 15};
  int* ptr = arr;

  *ptr = 30;
  *(ptr + 1) = 20;
  ptr += 2;
  *ptr = 10;

  int* i = arr;
  while(i <= ptr) {
    cout << *i << endl;
    i++;
  }
}
//1b
void findMax(int arr[], int n, int*& pToMax) {
    if(n <= 0)
      return;

    pToMax = arr;

    for(int i = 1; i < n; i++) {
      if(arr[i] > *pToMax)
        // pToMax += i;
        pToMax = arr + i;
    }
}
//1c
void computeCube(int n, int* ncubed) {
  *ncubed = n * n * n;
}
//1d
bool strequal(const char str1[], const char str2[]) {
  while(*str1 != 0 && *str2 != 0) {
    if(*str1 != *str2) {
      return false;
    }
    str1++;
    str2++;
  }
  return *str1 == *str2;
}
//1e
int* nochange(int* p) {
  return p;
}

int* getPtrToArray(int& m) {
  int anArray[100];
  for(int j = 0; j < 100; j++) {
    anArray[j] = 100-j;
  }
  m = 100;
  return nochange(anArray);
}

double mean(const double* scores, int numScores) {
  double total = 0;
  for(int i = 0; i < numScores; i++) {
    total += *(scores + i);
  }
  return total/numScores;
}

const char* findTheChar(const char str[], char chr) {
  for(int k = 0; *(str + k) != 0; k++) {
    // cout << (str + k) << endl;
    if(*(str + k) == chr) {
      return (str + k);
    }
  }
  return nullptr;
}

int main() {
  // printArray();

  // int nums[4] = {5, 3, 15, 6};
  // int* ptr;
  //
  // findMax(nums, 4, ptr);
  // cout << "The max is at address " << ptr << endl;
  // cout << "It's at position " << ptr - nums << endl;
  // cout << "Its value is " << *ptr << endl;

  // int num = 5;
  // int* ptr = &num;
  // computeCube(num, ptr);
  // cout << "Five cubed is " << *ptr << endl;

  // char a[15] = "Zhou";
  // char b[15] = "Zhou";
  //
  // if(strequal(a,b)) {
  //   cout << "They're the same person!\n";
  // }

  // int n;
  // int* ptr = getPtrToArray(n);
  //
  // for(int i = 0; i < 3; i++) {
  //   cout << ptr[i] << ' ';
  // }
  // for(int i = (n - 3); i < n; i++) {
  //   cout << ptr[i] << ' ';
  // }
  // cout << endl;

  // double da[5] = {3,6,1,9,21};
  // cout << mean(da, 5) << endl;

  char string[10] = "Ghost";
  const char* ptr = findTheChar(string, 'o');

  cout << &ptr << endl;
}
