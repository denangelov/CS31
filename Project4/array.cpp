#include <string>
#include <iostream>
#include <cassert>
using namespace std;

int appendToAll(string a[], int n, string value);
int lookup(const string a[], int n, string target);
int positionOfMax(const string a[], int n);
int rotateLeft(string a[], int n, int pos);
int countRuns(const string a[], int n);
int flip(string a[], int n);
int differ(const string a1[], int n1, const string a2[], int n2);
int subsequence(const string a1[], int n1, const string a2[], int n2);
int lookupAny(const string a1[], int n1, const string a2[], int n2);
int divide(string a[], int n, string divider);

int min(int n1, int n2) {
  return (n2 < n1) ? n2 : n1;
}

int main () {
  
}

int appendToAll(string a[], int n, string value) {
  if(n < 0) {
      return -1;
  }
  for(int i = 0; i < n; i++) {
      a[i] += value;
  }
  return n;
}

int lookup(const string a[], int n, string target) {
  if (n > 0) {
    for(int i = 0; i < n; i++) {
      if(a[i] == target) {
        return i;
      }
    }
  }
    return -1;
}

int positionOfMax(const string a[], int n) {
  if(n <= 0) {
    return -1;
  }

  int pos = 1;
  int greatest = 0;

  while(pos < n) {
    if(a[pos] > a[greatest]) {
      greatest = pos;
    }
    pos++;
  }
  return greatest;
}

int rotateLeft(string a[], int n, int pos) {
  if(n <= 0 || pos < 0 || pos >= n) {
    return -1;
  }

  string temp = a[pos];
  for(int i = pos; i < n - 1; i++) {
    a[i] = a[i + 1];
  }
  a[n-1] = temp;
  return pos;
}

int countRuns(const string a[], int n) {
  if(n < 0) {
    return -1;
  }

  int count = 0;
  for(int i = 0; i < n; i++) {
    count++;
    while(i < n - 1 && a[i] == a[i + 1]) {
      i++;
    }
  }
  return count;
}

int flip(string a[], int n) {
  if(n < 0) {
    return -1;
  }

  int start = 0;
  int end = n-1;
  string temp;
  while(end - start >= 1) {
    temp = a[start];
    a[start] = a[end];
    a[end] = temp;
    start++;
    end--;
  }
  return n;
}

int differ(const string a1[], int n1, const string a2[], int n2) {
  if (n1 < 0 || n2 < 0) {
    return -1;
  }
  for(int i = 0; i < min(n1, n2); i++) {
    if(a1[i] != a2[i]) {
      return i;
    }
  }
  return min(n1, n2);
}

int subsequence(const string a1[], int n1, const string a2[], int n2) {
  if(n1 > 0 && n2 > 0) {
    int k = 0;
    for(int i = 0; i < min(n1, n2); i++) {
      int pos = i;
      while(k < n2) {
        if(a1[pos] == a2[k]) {
          pos++;
          k++;
        }
        else {
          break;
        }
      }
      if(k == n2) {
        return i;
      }
      else {
        k = 0;
      }
    }
    return -1;
  }
  else if(n2 == 0) {
    return 0;
  }
  else {
    return -1;
  }
}

int lookupAny(const string a1[], int n1, const string a2[], int n2) {
  if(n1 < 0 || n2 < 0) {
    return -1;
  }
  int pos = n1;

  for(int j = 0; j < n2; j++) {
    for(int i = 0; i < n1; i++) {
      if(a1[i] == a2[j] && i < pos) {
        pos = i;
      }
    }
  }
  if(pos == n1) {
    return -1;
  }
  else {
    return pos;
  }
}

int divide(string a[], int n, string divider) {
  if(n < 0) {
    return -1;
  }

  string temp;
  int j = n - 1;

  for(int i = 0; i < j; i++) {
    if(a[i] == divider) {
      for(int k = i + 1; k < n; k++) {
        if(a[k] < divider) {
          a[i] = a[k];
          a[k] = divider;
          break;
        }
      }
    }
    if(a[i] > divider) {
      temp = a[i];
      while(j > i) {
        if(a[j] <= divider) {
          a[i] = a[j];
          a[j] = temp;
          i--;
          j--;
          break;
        }
        j--;
      }
    }
  }

  for(int i = 0; i < n; i++) {
    if(a[i] >= divider) {
      return i;
    }
  }

  return n;

}
