// Q1.
#include <iostream>
#include <vector>

using namespace std;

int searchInArray(const vector<int>& data, int value) {
    int start = 0;
    int end = data.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (data[mid] == value) {
            return mid;
        }
        if (data[mid] < value) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> numbers = {3, 7, 11, 15, 19, 23, 27, 31, 35, 39};
    int target = 23;
    int index = searchInArray(numbers, target);

    if (index != -1) {
        cout << "Element " << target << " found at index " << index << "." << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}

// Q2.
#include <iostream>
#include <vector>

using namespace std;

void sortNumbers(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temporary = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temporary;
            }
        }
    }
}

void printVector(const vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> numbers = {64, 34, 25, 12, 22, 11, 90};

    cout << "Original array: ";
    printVector(numbers);

    sortNumbers(numbers);

    cout << "Sorted array: ";
    printVector(numbers);

    return 0;
}
// Q3.
// a.
#include <iostream>
#include <vector>

using namespace std;

int findMissingLinear(const vector<int>& arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }
    return n;
}

int main() {
    vector<int> myVector = {1, 2, 3, 5, 6, 7};
    int totalCount = 7;
    int missingNum = findMissingLinear(myVector, totalCount);
    cout << "The missing number is " << missingNum << "." << endl;

    return 0;
}
// b.
#include <iostream>
#include <vector>

using namespace std;

int findMissingBinary(const vector<int>& nums, int limit) {
    int start = 0;
    int end = nums.size() - 1;
    int missingValue = limit;

    while (start <= end) {
        int midIndex = start + (end - start) / 2;
        if (nums[midIndex] == midIndex + 1) {
            start = midIndex + 1;
        } else {
            missingValue = midIndex + 1;
            end = midIndex - 1;
        }
    }

    return missingValue;
}

int main() {
    vector<int> sortedNums = {1, 2, 4, 5, 6, 7};
    int nValue = 7;
    int result = findMissingBinary(sortedNums, nValue);
    cout << "The missing number is " << result << "." << endl;

    return 0;
}
// Q4.
#include <iostream>
#include <string>

using namespace std;

void swapChars(char& a, char& b);
string combineStrings(string firstStr, string secondStr);
string flipString(string inputStr);
string removeVowels(string inputStr);
string organizeString(string inputStr);
string convertToUpper(string inputStr);

int main() {
  string initialStr = "Hello";
  string combined = combineStrings(initialStr, " World");
  cout << "Combined: " << combined << endl;
  string flipped = flipString(initialStr);
  cout << "Flipped: " << flipped << endl;
  string noVowels = removeVowels(initialStr);
  cout << "Without vowels: " << noVowels << endl;
  string arranged = organizeString(initialStr);
  cout << "Sorted: " << arranged << endl;
  string allCaps = convertToUpper(initialStr);
  cout << "Uppercase: " << allCaps << endl;
}

void swapChars(char& a, char& b) {
  char tempChar = a;
  a = b;
  b = tempChar;
}

string combineStrings(string firstStr, string secondStr) {
  return firstStr + secondStr;
}

string flipString(string inputStr) {
  string resultRev = inputStr;
  int strLength = inputStr.length();
  for (int i = 0; i < strLength; i++) {
    resultRev[i] = inputStr[strLength - i - 1];
  }
  return resultRev;
}

string removeVowels(string inputStr) {
  string outputNoVowels;
  for (char c : inputStr) {
    if (tolower(c) != 'a' && tolower(c) != 'e' && tolower(c) != 'i' && tolower(c) != 'o' && tolower(c) != 'u') {
      outputNoVowels.push_back(c);
    }
  }
  return outputNoVowels;
}

string organizeString(string inputStr) {
  string resultSorted = inputStr;
  bool noSwap;
  int strLength = inputStr.length();
  for (int i = 0; i < strLength - 1; i++) {
    noSwap = true;
    for (int j = 0; j < strLength - i - 1; j++) {
      if (tolower(resultSorted[j]) > tolower(resultSorted[j + 1])) {
        noSwap = false;
        swapChars(resultSorted[j], resultSorted[j + 1]);
      }
    }
    if (noSwap) {
      break;
    }
  }
  return resultSorted;
}

string convertToUpper(string inputStr) {
  string resultCaps = inputStr;
  for (int i = 0; i < inputStr.length(); i++) {
    if (resultCaps[i] >= 'a' && resultCaps[i] <= 'z') {
      resultCaps[i] -= 32;
    }
  }
  return resultCaps;
}
// Q5.
#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter number of elements (n): ";
    cin >> n;

    int arr[50];
    for (int i = 0; i < n ; i++) {
        cout << "Enter element of diagonal matrix " << ": ";
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                cout << arr[i] << " "; 
            } else {
                cout << "0 "; 
            }
        }
        cout << endl; 
    }
    
    
}
#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter number of elements n: ";
    cin >> n;

    int arr[50],k=0;
    
    for(int i = 0; i < (3*n)-2; i++) {
        cout << "Enter " << i+1 << " element of tri-diagonal matrix " << ": ";
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
           if(i-j == 0 || i-j == 1 || j-i == 1) {
                cout << arr[k] << " "; 
                k++;
            } else {
                cout << "0 "; 
            }
        }
        cout << endl;
  
}
return 0;
}
#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter order of  matrix "<<"\n";
    cin >> n;

    int arr[50],k=0,z=(n*(n+1))/2;
    cout << "Enter " << z << " elements of lower triangular matrix: ";
    
    for(int i = 0; i < z; i++) {
        cout << "Enter " << i+1 << "st element of lower triangular matrix " << ": ";
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
           if(i >= j) {
                cout << arr[k] << " "; 
                k++;
            } else {
                cout << "0 "; 
            }
        }
        cout << endl;
  
}
return 0;
}
#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter order of  matrix "<<"\n";
    cin >> n;

    int arr[50],k=0,z=(n*(n+1))/2;
    cout << "Enter " << z << " elements of lower triangular matrix: ";
    
    for(int i = 0; i < z; i++) {
        cout << "Enter " << i+1 << " element of lower triangular matrix " << ": ";
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
           if(i <= j) {
                cout << arr[k] << " "; 
                k++;
            } else {
                cout << "0 "; 
            }
        }
        cout << endl;
  
}
return 0;
}
#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter order of  matrix "<<"\n";
    cin >> n;

    int arr[50],k=0,z=(n*(n+1))/2;
    cout << "Enter " << z << " elements of symmetric matrix: ";
    
    for(int i = 0; i < z; i++) {
        cout << "Enter " << i+1 << " element of symmetric matrix " << ": ";
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
           if(i <= j) {
                cout << arr[k] << " "; 
                k++;
            } else {
                cout << "0 "; 
            }
        }
        cout << endl;
  
}
return 0;
}
// Q6.
#include <iostream>
using namespace std;

void inputMatrix(int rows[], int cols[], int values[], int nonZeros) {
    cout << "Enter " << nonZeros << " non-zero elements (row col value):\n";
    for (int i = 0; i < nonZeros; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> rows[i] >> cols[i] >> values[i];
    }
}

void displayMatrix(int rows[], int cols[], int values[], int nonZeros, int matrixRows, int matrixCols) {
    cout << "Matrix representation:\n";
    for (int i = 0; i < matrixRows; i++) {
        for (int j = 0; j < matrixCols; j++) {
            int value = 0;
            for (int k = 0; k < nonZeros; k++) {
                if (rows[k] == i && cols[k] == j) {
                    value = values[k];
                    break;
                }
            }
            cout << value << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

void displayTriplets(int rows[], int cols[], int values[], int nonZeros) {
    cout << "Row\tCol\tValue\n";
    cout << "---\t---\t-----\n";
    for (int i = 0; i < nonZeros; i++) {
        cout << rows[i] << "\t" << cols[i] << "\t" << values[i] << "\n";
    }
    cout << "\n";
}

void sortedTranspose(int rows[], int cols[], int values[], int nonZeros,
                     int transRows[], int transCols[], int transValues[]) {
    for (int i = 0; i < nonZeros; i++) {
        transRows[i] = cols[i];
        transCols[i] = rows[i];
        transValues[i] = values[i];
    }
    
    for (int i = 0; i < nonZeros - 1; i++) {
        for (int j = 0; j < nonZeros - i - 1; j++) {
            if (transRows[j] > transRows[j + 1] ||
                (transRows[j] == transRows[j + 1] && transCols[j] > transCols[j + 1])) {
                
                int tempRow = transRows[j];
                int tempCol = transCols[j];
                int tempVal = transValues[j];
                
                transRows[j] = transRows[j + 1];
                transCols[j] = transCols[j + 1];
                transValues[j] = transValues[j + 1];
                
                transRows[j + 1] = tempRow;
                transCols[j + 1] = tempCol;
                transValues[j + 1] = tempVal;
            }
        }
    }
}

int main() {
    cout << "SPARSE MATRIX TRANSPOSE\n";
    
    int matrixRows, matrixCols, nonZeros;
    cout << "Enter matrix dimensions (rows cols): ";
    cin >> matrixRows >> matrixCols;
    cout << "Enter number of non-zero elements: ";
    cin >> nonZeros;
    
    int rows[100], cols[100], values[100];
    inputMatrix(rows, cols, values, nonZeros);
    
    cout << "\nOriginal Matrix:\n";
    displayTriplets(rows, cols, values, nonZeros);
    displayMatrix(rows, cols, values, nonZeros, matrixRows, matrixCols);
    
    int transRows[100], transCols[100], transValues[100];
    sortedTranspose(rows, cols, values, nonZeros, transRows, transCols, transValues);
    
    cout << "Transposed Matrix:\n";
    displayTriplets(transRows, transCols, transValues, nonZeros);
    displayMatrix(transRows, transCols, transValues, nonZeros, matrixCols, matrixRows);
    
    return 0;
}


#include <iostream>
using namespace std;

void inputMatrix(int rows[], int cols[], int values[], int nonZeros) {
    cout << "Enter " << nonZeros << " non-zero elements (row col value):\n";
    for (int i = 0; i < nonZeros; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> rows[i] >> cols[i] >> values[i];
    }
}

void displayMatrix(int rows[], int cols[], int values[], int nonZeros, int matrixRows, int matrixCols) {
    cout << "Matrix representation:\n";
    for (int i = 0; i < matrixRows; i++) {
        for (int j = 0; j < matrixCols; j++) {
            int value = 0;
            for (int k = 0; k < nonZeros; k++) {
                if (rows[k] == i && cols[k] == j) {
                    value = values[k];
                    break;
                }
            }
            cout << value << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

int addMatrices(int rows1[], int cols1[], int values1[], int nz1,
                int rows2[], int cols2[], int values2[], int nz2,
                int resultRows[], int resultCols[], int resultValues[]) {
    
    int resultCount = 0;
    
    for (int i = 0; i < nz1; i++) {
        resultRows[resultCount] = rows1[i];
        resultCols[resultCount] = cols1[i];
        resultValues[resultCount] = values1[i];
        resultCount++;
    }
    
    for (int i = 0; i < nz2; i++) {
        int currentRow = rows2[i];
        int currentCol = cols2[i];
        int currentValue = values2[i];
        
        bool found = false;
        for (int j = 0; j < resultCount; j++) {
            if (resultRows[j] == currentRow && resultCols[j] == currentCol) {
                resultValues[j] += currentValue;
                
                if (resultValues[j] == 0) {
                    for (int k = j; k < resultCount - 1; k++) {
                        resultRows[k] = resultRows[k + 1];
                        resultCols[k] = resultCols[k + 1];
                        resultValues[k] = resultValues[k + 1];
                    }
                    resultCount--;
                }
                found = true;
                break;
            }
        }
        
        if (!found) {
            resultRows[resultCount] = currentRow;
            resultCols[resultCount] = currentCol;
            resultValues[resultCount] = currentValue;
            resultCount++;
        }
    }
    
    return resultCount;
}

int main() {
    cout << "SPARSE MATRIX ADDITION\n";
    
    int matrixRows, matrixCols, nz1, nz2;
    cout << "Enter matrix dimensions (rows cols): ";
    cin >> matrixRows >> matrixCols;
    
    cout << "Enter number of non-zero elements in first matrix: ";
    cin >> nz1;
    int rows1[100], cols1[100], values1[100];
    cout << "First Matrix:\n";
    inputMatrix(rows1, cols1, values1, nz1);
    
    cout << "Enter number of non-zero elements in second matrix: ";
    cin >> nz2;
    int rows2[100], cols2[100], values2[100];
    cout << "Second Matrix:\n";
    inputMatrix(rows2, cols2, values2, nz2);
    
    cout << "\nFirst Matrix:\n";
    displayMatrix(rows1, cols1, values1, nz1, matrixRows, matrixCols);
    
    cout << "Second Matrix:\n";
    displayMatrix(rows2, cols2, values2, nz2, matrixRows, matrixCols);
    
    int resultRows[200], resultCols[200], resultValues[200];
    int resultNonZeros = addMatrices(rows1, cols1, values1, nz1,
                                    rows2, cols2, values2, nz2,
                                    resultRows, resultCols, resultValues);
    
    cout << "Sum Matrix:\n";
    displayMatrix(resultRows, resultCols, resultValues, resultNonZeros, matrixRows, matrixCols);
    
    return 0;
}


#include <iostream>
using namespace std;

void inputMatrix(int rows[], int cols[], int values[], int nonZeros) {
    cout << "Enter " << nonZeros << " non-zero elements (row col value):\n";
    for (int i = 0; i < nonZeros; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> rows[i] >> cols[i] >> values[i];
    }
}

void displayMatrix(int rows[], int cols[], int values[], int nonZeros, int matrixRows, int matrixCols) {
    cout << "Matrix representation:\n";
    for (int i = 0; i < matrixRows; i++) {
        for (int j = 0; j < matrixCols; j++) {
            int value = 0;
            for (int k = 0; k < nonZeros; k++) {
                if (rows[k] == i && cols[k] == j) {
                    value = values[k];
                    break;
                }
            }
            cout << value << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

void sortedTranspose(int rows[], int cols[], int values[], int nonZeros,
                     int transRows[], int transCols[], int transValues[]) {
    for (int i = 0; i < nonZeros; i++) {
        transRows[i] = cols[i];
        transCols[i] = rows[i];
        transValues[i] = values[i];
    }
    
    for (int i = 0; i < nonZeros - 1; i++) {
        for (int j = 0; j < nonZeros - i - 1; j++) {
            if (transRows[j] > transRows[j + 1] ||
                (transRows[j] == transRows[j + 1] && transCols[j] > transCols[j + 1])) {
                
                int tempRow = transRows[j];
                int tempCol = transCols[j];
                int tempVal = transValues[j];
                
                transRows[j] = transRows[j + 1];
                transCols[j] = transCols[j + 1];
                transValues[j] = transValues[j + 1];
                
                transRows[j + 1] = tempRow;
                transCols[j + 1] = tempCol;
                transValues[j + 1] = tempVal;
            }
        }
    }
}

int multiplyMatrices(int rows1[], int cols1[], int values1[], int nz1, int matrixRows1, int matrixCols1,
                     int rows2[], int cols2[], int values2[], int nz2, int matrixRows2, int matrixCols2,
                     int resultRows[], int resultCols[], int resultValues[]) {
    
    if (matrixCols1 != matrixRows2) {
        cout << "Matrix dimensions don't match for multiplication!\n";
        return 0;
    }
    
    int transRows[200], transCols[200], transValues[200];
    sortedTranspose(rows2, cols2, values2, nz2, transRows, transCols, transValues);
    
    int tempRows[1000], tempCols[1000], tempValues[1000];
    int tempCount = 0;
    
    for (int i = 0; i < nz1; i++) {
        int row1 = rows1[i];
        int col1 = cols1[i];
        int val1 = values1[i];
        
        for (int j = 0; j < nz2; j++) {
            int row2 = transRows[j];
            int col2 = transCols[j];
            int val2 = transValues[j];
            
            if (col1 == col2) {
                int product = val1 * val2;
                tempRows[tempCount] = row1;
                tempCols[tempCount] = row2;
                tempValues[tempCount] = product;
                tempCount++;
            }
        }
    }
    
    int resultCount = 0;
    
    for (int i = 0; i < tempCount; i++) {
        int currentRow = tempRows[i];
        int currentCol = tempCols[i];
        int currentValue = tempValues[i];
        
        bool found = false;
        for (int j = 0; j < resultCount; j++) {
            if (resultRows[j] == currentRow && resultCols[j] == currentCol) {
                resultValues[j] += currentValue;
                found = true;
                break;
            }
        }
        
        if (!found) {
            resultRows[resultCount] = currentRow;
            resultCols[resultCount] = currentCol;
            resultValues[resultCount] = currentValue;
            resultCount++;
        }
    }
    
    return resultCount;
}

int main() {
    cout << "SPARSE MATRIX MULTIPLICATION\n";
    
    int r1, c1, r2, c2, nz1, nz2;
    cout << "Enter first matrix dimensions (rows cols): ";
    cin >> r1 >> c1;
    cout << "Enter second matrix dimensions (rows cols): ";
    cin >> r2 >> c2;
    
    if (c1 != r2) {
        cout << "Invalid dimensions for multiplication!\n";
        return 1;
    }
    
    cout << "Enter number of non-zero elements in first matrix: ";
    cin >> nz1;
    int rows1[100], cols1[100], values1[100];
    cout << "First Matrix:\n";
    inputMatrix(rows1, cols1, values1, nz1);
    
    cout << "Enter number of non-zero elements in second matrix: ";
    cin >> nz2;
    int rows2[100], cols2[100], values2[100];
    cout << "Second Matrix:\n";
    inputMatrix(rows2, cols2, values2, nz2);
    
    cout << "\nFirst Matrix:\n";
    displayMatrix(rows1, cols1, values1, nz1, r1, c1);
    
    cout << "Second Matrix:\n";
    displayMatrix(rows2, cols2, values2, nz2, r2, c2);
    
    int resultRows[500], resultCols[500], resultValues[500];
    int resultNonZeros = multiplyMatrices(rows1, cols1, values1, nz1, r1, c1,
                                         rows2, cols2, values2, nz2, r2, c2,
                                         resultRows, resultCols, resultValues);
    
    if (resultNonZeros > 0) {
        cout << "Product Matrix:\n";
        displayMatrix(resultRows, resultCols, resultValues, resultNonZeros, r1, c2);
    }
    
    return 0;
}
// Q7.
#include <iostream>

using namespace std;

int main() {
    int arraySize;
    cout << "Enter the size of the array: ";
    cin >> arraySize;

    int sequence[100]; 
    cout << "Enter " << arraySize << " elements for the sequence:\n";
    for (int idx = 0; idx < arraySize; idx++) {
        cin >> sequence[idx];
    }

    int totalInversions = 0;

    for (int outer = 0; outer < arraySize; outer++) {
        for (int inner = outer + 1; inner < arraySize; inner++) {
            if (sequence[outer] > sequence[inner]) {
                totalInversions++;
            }
        }
    }

    cout << "Number of inversions found: " << totalInversions << endl;
    return 0;
}
// Q8.
#include <iostream>

using namespace std;

int main() {
    int myArray[50];
    int size, distinctCount = 0;

    cout << "Enter the size of the array: ";
    cin >> size;

    for(int outerIndex = 0; outerIndex < size; outerIndex++) {
        cout << "Enter element " << outerIndex + 1 << ": ";
        cin >> myArray[outerIndex];
    }

    for(int outerIndex = 0; outerIndex < size; outerIndex++) {
        bool isAlreadyFound = false;
        for(int innerIndex = 0; innerIndex < outerIndex; innerIndex++) {
            if(myArray[outerIndex] == myArray[innerIndex]) {
                isAlreadyFound = true;
                break;
            }
        }
        if(!isAlreadyFound) {
            distinctCount++;
        }
    }

    cout << "Total unique elements: " << distinctCount << endl;
    return 0;
}