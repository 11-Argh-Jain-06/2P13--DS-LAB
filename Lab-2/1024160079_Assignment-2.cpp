// Q1.
#include <iostream>
#include <vector>

using namespace std;

int findInArray(const vector<int>& arr, int key, int low, int high) {
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;
    if (arr[mid] == key) {
        return mid;
    }
    if (arr[mid] < key) {
        return findInArray(arr, key, mid + 1, high);
    } else {
        return findInArray(arr, key, low, mid - 1);
    }
}

int main() {
    vector<int> collection = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int desiredValue = 56;
    int position = findInArray(collection, desiredValue, 0, collection.size() - 1);

    if (position != -1) {
        cout << "The value " << desiredValue << " is at position " << position << "." << endl;
    } else {
        cout << "The value " << desiredValue << " was not found." << endl;
    }

    return 0;
}
// Q2.
#include <iostream>
#include <vector>

using namespace std;

void processArray(vector<int>& list) {
    int len = list.size();
    bool didSwap;
    for (int p = 0; p < len - 1; p++) {
        didSwap = false;
        for (int q = 0; q < len - p - 1; q++) {
            if (list[q] > list[q + 1]) {
                int current = list[q];
                list[q] = list[q + 1];
                list[q + 1] = current;
                didSwap = true;
            }
        }
        if (didSwap == false) {
            break;
        }
    }
}

void displayList(const vector<int>& list) {
    for (int element : list) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    vector<int> data = {64, 34, 25, 12, 22, 11, 90};

    cout << "Initial list: ";
    displayList(data);

    processArray(data);

    cout << "Final sorted list: ";
    displayList(data);

    return 0;
}
// Q3.
// a.
#include <iostream>
#include <vector>

using namespace std;

int findMissingNumber(const vector<int>& sequence, int sizeN) {
    for (int i = 0; i < sequence.size(); i++) {
        if (sequence[i] != i + 1) {
            return i + 1;
        }
    }
    return sizeN;
}

int main() {
    vector<int> numbers = {1, 2, 3, 4, 6, 7, 8, 9};
    int limit = 9;
    int missingVal = findMissingNumber(numbers, limit);
    cout << "The absent value is " << missingVal << "." << endl;

    return 0;
}
// b.
#include <iostream>
#include <vector>

using namespace std;

int locateMissing(const vector<int>& dataset) {
    int lower = 0;
    int upper = dataset.size() - 1;
    int foundVal = dataset.size() + 1;

    while (lower <= upper) {
        int midPoint = lower + (upper - lower) / 2;
        if (dataset[midPoint] == midPoint + 1) {
            lower = midPoint + 1;
        } else {
            foundVal = midPoint + 1;
            upper = midPoint - 1;
        }
    }

    return foundVal;
}

int main() {
    vector<int> dataset = {1, 2, 3, 5, 6, 7, 8, 9};
    int missingResult = locateMissing(dataset);
    cout << "The missing integer is " << missingResult << "." << endl;

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

string combine(string s1, string s2);
string manualReverse(string s);
string filter(string s);
string bubbleSort(string s);
string toUpperCase(string s);
void swap_chars(char& x, char& y);

int main() {
  string word = "Hello";
  string combined = combine(word, " World");
  cout << "Concatenated: " << combined << endl;
  string reversed_str = manualReverse(word);
  cout << "Reversed: " << reversed_str << endl;
  string filtered_str = filter(word);
  cout << "Filtered: " << filtered_str << endl;
  string sorted_str = bubbleSort(word);
  cout << "Sorted: " << sorted_str << endl;
  string upper_str = toUpperCase(word);
  cout << "Uppercase: " << upper_str << endl;
}

string combine(string s1, string s2) {
  string combined_string = s1;
  int n1 = s1.length();
  int n2 = s2.length();
  combined_string.resize(n1 + n2);
  for (int i = 0; i < n2; i++) {
    combined_string[n1 + i] = s2[i];
  }
  return combined_string;
}

string manualReverse(string s) {
  int start = 0;
  int end = s.length() - 1;
  while (start < end) {
    swap_chars(s[start], s[end]);
    start++;
    end--;
  }
  return s;
}

string filter(string s) {
  string result = "";
  for (char c : s) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
      continue;
    }
    result += c;
  }
  return result;
}

void swap_chars(char& x, char& y) {
  char temp = x;
  x = y;
  y = temp;
}

string bubbleSort(string s) {
  int n = s.length();
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (s[j] > s[j + 1]) {
        swap_chars(s[j], s[j + 1]);
      }
    }
  }
  return s;
}

string toUpperCase(string s) {
  for (int i = 0; i < s.length(); i++) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      s[i] = s[i] - 'a' + 'A';
    }
  }
  return s;
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

void acceptMatrix(int matrix_rows[], int matrix_cols[], int matrix_values[], int element_count) {
    cout << "Enter " << element_count << " non-zero elements (row col value):\n";
    for (int r = 0; r < element_count; r++) {
        cout << "Element " << r + 1 << ": ";
        cin >> matrix_rows[r] >> matrix_cols[r] >> matrix_values[r];
    }
}

void printMatrix(int matrix_rows[], int matrix_cols[], int matrix_values[], int element_count, int num_rows, int num_cols) {
    cout << "Matrix representation:\n";
    for (int r = 0; r < num_rows; r++) {
        for (int c = 0; c < num_cols; c++) {
            int cell_value = 0;
            for (int k = 0; k < element_count; k++) {
                if (matrix_rows[k] == r && matrix_cols[k] == c) {
                    cell_value = matrix_values[k];
                    break;
                }
            }
            cout << cell_value << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

void printTriplets(int matrix_rows[], int matrix_cols[], int matrix_values[], int element_count) {
    cout << "Row\tCol\tValue\n";
    cout << "---\t---\t-----\n";
    for (int r = 0; r < element_count; r++) {
        cout << matrix_rows[r] << "\t" << matrix_cols[r] << "\t" << matrix_values[r] << "\n";
    }
    cout << "\n";
}

void applyTranspose(int matrix_rows[], int matrix_cols[], int matrix_values[], int element_count,
                     int transposed_rows[], int transposed_cols[], int transposed_values[]) {
    for (int r = 0; r < element_count; r++) {
        transposed_rows[r] = matrix_cols[r];
        transposed_cols[r] = matrix_rows[r];
        transposed_values[r] = matrix_values[r];
    }
    
    for (int r = 0; r < element_count - 1; r++) {
        for (int c = 0; c < element_count - r - 1; c++) {
            if (transposed_rows[c] > transposed_rows[c + 1] ||
                (transposed_rows[c] == transposed_rows[c + 1] && transposed_cols[c] > transposed_cols[c + 1])) {
                
                int temp_r = transposed_rows[c];
                int temp_c = transposed_cols[c];
                int temp_v = transposed_values[c];
                
                transposed_rows[c] = transposed_rows[c + 1];
                transposed_cols[c] = transposed_cols[c + 1];
                transposed_values[c] = transposed_values[c + 1];
                
                transposed_rows[c + 1] = temp_r;
                transposed_cols[c + 1] = temp_c;
                transposed_values[c + 1] = temp_v;
            }
        }
    }
}

int main() {
    cout << "SPARSE MATRIX TRANSPOSE \n";
    
    int num_rows, num_cols, element_count;
    cout << "Enter matrix dimensions (rows cols): ";
    cin >> num_rows >> num_cols;
    cout << "Enter number of non-zero elements: ";
    cin >> element_count;
    
    int row_indices[100], col_indices[100], cell_values[100];
    acceptMatrix(row_indices, col_indices, cell_values, element_count);
    
    cout << "\nOriginal Matrix:\n";
    printTriplets(row_indices, col_indices, cell_values, element_count);
    printMatrix(row_indices, col_indices, cell_values, element_count, num_rows, num_cols);
    
    int transposed_rows[100], transposed_cols[100], transposed_values[100];
    applyTranspose(row_indices, col_indices, cell_values, element_count, transposed_rows, transposed_cols, transposed_values);
    
    cout << "Transposed Matrix:\n";
    printTriplets(transposed_rows, transposed_cols, transposed_values, element_count);
    printMatrix(transposed_rows, transposed_cols, transposed_values, element_count, num_cols, num_rows);
    
    return 0;
}
#include <iostream>
using namespace std;

void acceptMatrix(int matrix_rows[], int matrix_cols[], int matrix_values[], int element_count) {
    cout << "Enter " << element_count << " non-zero elements (row col value):\n";
    for (int r = 0; r < element_count; r++) {
        cout << "Element " << r + 1 << ": ";
        cin >> matrix_rows[r] >> matrix_cols[r] >> matrix_values[r];
    }
}

void printMatrix(int matrix_rows[], int matrix_cols[], int matrix_values[], int element_count, int num_rows, int num_cols) {
    cout << "Matrix representation:\n";
    for (int r = 0; r < num_rows; r++) {
        for (int c = 0; c < num_cols; c++) {
            int cell_value = 0;
            for (int k = 0; k < element_count; k++) {
                if (matrix_rows[k] == r && matrix_cols[k] == c) {
                    cell_value = matrix_values[k];
                    break;
                }
            }
            cout << cell_value << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

int performAddition(int rows_one[], int cols_one[], int values_one[], int count_one,
                    int rows_two[], int cols_two[], int values_two[], int count_two,
                    int sum_rows[], int sum_cols[], int sum_values[]) {
    
    int sum_count = 0;
    
    for (int r = 0; r < count_one; r++) {
        sum_rows[sum_count] = rows_one[r];
        sum_cols[sum_count] = cols_one[r];
        sum_values[sum_count] = values_one[r];
        sum_count++;
    }
    
    for (int r = 0; r < count_two; r++) {
        int current_r = rows_two[r];
        int current_c = cols_two[r];
        int current_v = values_two[r];
        
        bool item_found = false;
        for (int c = 0; c < sum_count; c++) {
            if (sum_rows[c] == current_r && sum_cols[c] == current_c) {
                sum_values[c] += current_v;
                
                if (sum_values[c] == 0) {
                    for (int k = c; k < sum_count - 1; k++) {
                        sum_rows[k] = sum_rows[k + 1];
                        sum_cols[k] = sum_cols[k + 1];
                        sum_values[k] = sum_values[k + 1];
                    }
                    sum_count--;
                }
                item_found = true;
                break;
            }
        }
        
        if (!item_found) {
            sum_rows[sum_count] = current_r;
            sum_cols[sum_count] = current_c;
            sum_values[sum_count] = current_v;
            sum_count++;
        }
    }
    
    return sum_count;
}

int main() {
    cout << "SPARSE MATRIX ADDITION\n";
    
    int num_rows, num_cols, count_one, count_two;
    cout << "Enter matrix dimensions (rows cols): ";
    cin >> num_rows >> num_cols;
    
    cout << "Enter number of non-zero elements in first matrix: ";
    cin >> count_one;
    int rows_one[100], cols_one[100], values_one[100];
    cout << "First Matrix:\n";
    acceptMatrix(rows_one, cols_one, values_one, count_one);
    
    cout << "Enter number of non-zero elements in second matrix: ";
    cin >> count_two;
    int rows_two[100], cols_two[100], values_two[100];
    cout << "Second Matrix:\n";
    acceptMatrix(rows_two, cols_two, values_two, count_two);
    
    cout << "\nFirst Matrix:\n";
    printMatrix(rows_one, cols_one, values_one, count_one, num_rows, num_cols);
    
    cout << "Second Matrix:\n";
    printMatrix(rows_two, cols_two, values_two, count_two, num_rows, num_cols);
    
    int sum_rows[200], sum_cols[200], sum_values[200];
    int sum_count = performAddition(rows_one, cols_one, values_one, count_one,
                                    rows_two, cols_two, values_two, count_two,
                                    sum_rows, sum_cols, sum_values);
    
    cout << "Sum Matrix:\n";
    printMatrix(sum_rows, sum_cols, sum_values, sum_count, num_rows, num_cols);
    
    return 0;
}
#include <iostream>
using namespace std;

void acceptMatrix(int matrix_rows[], int matrix_cols[], int matrix_values[], int element_count) {
    cout << "Enter " << element_count << " non-zero elements (row col value):\n";
    for (int r = 0; r < element_count; r++) {
        cout << "Element " << r + 1 << ": ";
        cin >> matrix_rows[r] >> matrix_cols[r] >> matrix_values[r];
    }
}

void printMatrix(int matrix_rows[], int matrix_cols[], int matrix_values[], int element_count, int num_rows, int num_cols) {
    cout << "Matrix representation:\n";
    for (int r = 0; r < num_rows; r++) {
        for (int c = 0; c < num_cols; c++) {
            int cell_value = 0;
            for (int k = 0; k < element_count; k++) {
                if (matrix_rows[k] == r && matrix_cols[k] == c) {
                    cell_value = matrix_values[k];
                    break;
                }
            }
            cout << cell_value << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

void sortedTranspose(int matrix_rows[], int matrix_cols[], int matrix_values[], int element_count,
                     int transposed_rows[], int transposed_cols[], int transposed_values[]) {
    for (int r = 0; r < element_count; r++) {
        transposed_rows[r] = matrix_cols[r];
        transposed_cols[r] = matrix_rows[r];
        transposed_values[r] = matrix_values[r];
    }
    
    for (int r = 0; r < element_count - 1; r++) {
        for (int c = 0; c < element_count - r - 1; c++) {
            if (transposed_rows[c] > transposed_rows[c + 1] ||
                (transposed_rows[c] == transposed_rows[c + 1] && transposed_cols[c] > transposed_cols[c + 1])) {
                
                int temp_r = transposed_rows[c];
                int temp_c = transposed_cols[c];
                int temp_v = transposed_values[c];
                
                transposed_rows[c] = transposed_rows[c + 1];
                transposed_cols[c] = transposed_cols[c + 1];
                transposed_values[c] = transposed_values[c + 1];
                
                transposed_rows[c + 1] = temp_r;
                transposed_cols[c + 1] = temp_c;
                transposed_values[c + 1] = temp_v;
            }
        }
    }
}

int computeProduct(int rows_one[], int cols_one[], int values_one[], int count_one, int num_rows_one, int num_cols_one,
                     int rows_two[], int cols_two[], int values_two[], int count_two, int num_rows_two, int num_cols_two,
                     int result_rows[], int result_cols[], int result_values[]) {
    
    if (num_cols_one != num_rows_two) {
        cout << "Matrix dimensions don't match for multiplication!\n";
        return 0;
    }
    
    int transposed_rows[200], transposed_cols[200], transposed_values[200];
    sortedTranspose(rows_two, cols_two, values_two, count_two, transposed_rows, transposed_cols, transposed_values);
    
    int temp_rows[1000], temp_cols[1000], temp_values[1000];
    int temp_count = 0;
    
    for (int r = 0; r < count_one; r++) {
        int r1 = rows_one[r];
        int c1 = cols_one[r];
        int v1 = values_one[r];
        
        for (int c = 0; c < count_two; c++) {
            int r2 = transposed_rows[c];
            int c2 = transposed_cols[c];
            int v2 = transposed_values[c];
            
            if (c1 == c2) {
                int product_val = v1 * v2;
                temp_rows[temp_count] = r1;
                temp_cols[temp_count] = r2;
                temp_values[temp_count] = product_val;
                temp_count++;
            }
        }
    }
    
    int result_count = 0;
    
    for (int r = 0; r < temp_count; r++) {
        int current_r = temp_rows[r];
        int current_c = temp_cols[r];
        int current_v = temp_values[r];
        
        bool was_found = false;
        for (int c = 0; c < result_count; c++) {
            if (result_rows[c] == current_r && result_cols[c] == current_c) {
                result_values[c] += current_v;
                was_found = true;
                break;
            }
        }
        
        if (!was_found) {
            result_rows[result_count] = current_r;
            result_cols[result_count] = current_c;
            result_values[result_count] = current_v;
            result_count++;
        }
    }
    
    return result_count;
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
    int rows_one[100], cols_one[100], values_one[100];
    cout << "First Matrix:\n";
    acceptMatrix(rows_one, cols_one, values_one, nz1);
    
    cout << "Enter number of non-zero elements in second matrix: ";
    cin >> nz2;
    int rows_two[100], cols_two[100], values_two[100];
    cout << "Second Matrix:\n";
    acceptMatrix(rows_two, cols_two, values_two, nz2);
    
    cout << "\nFirst Matrix:\n";
    printMatrix(rows_one, cols_one, values_one, nz1, r1, c1);
    
    cout << "Second Matrix:\n";
    printMatrix(rows_two, cols_two, values_two, nz2, r2, c2);
    
    int result_rows[500], result_cols[500], result_values[500];
    int result_non_zeros = computeProduct(rows_one, cols_one, values_one, nz1, r1, c1,
                                         rows_two, cols_two, values_two, nz2, r2, c2,
                                         result_rows, result_cols, result_values);
    
    if (result_non_zeros > 0) {
        cout << "Product Matrix:\n";
        printMatrix(result_rows, result_cols, result_values, result_non_zeros, r1, c2);
    }
    
    return 0;
}
// Q7.
#include <iostream>

using namespace std;

int main() {
    int numElements;
    cout << "Enter number of elements: ";
    cin >> numElements;

    int dataArray[100]; 
    cout << "Enter " << numElements << " elements:\n";
    for (int i = 0; i < numElements; i++) {
        cin >> dataArray[i];
    }

    int count = 0;

    for (int i = 0; i < numElements; i++) {
        for (int j = i + 1; j < numElements; j++) {
            if (dataArray[i] > dataArray[j]) {
                count++;
            }
        }
    }

    cout << "Total number of inversions: " << count << endl;
    return 0;
}
// Q8.
#include <iostream>

using namespace std;

int main() {
    int dataList[50];
    int numItems, uniqueElements = 0;

    cout << "Input the number of elements: ";
    cin >> numItems;

    for(int i = 0; i < numItems; i++) {
        cout << "Input item " << i + 1 << ": ";
        cin >> dataList[i];
    }

    for(int i = 0; i < numItems; i++) {
        bool duplicateFlag = false;
        for(int j = 0; j < i; j++) {
            if(dataList[i] == dataList[j]) {
                duplicateFlag = true;
                break;
            }
        }
        if(!duplicateFlag) {
            uniqueElements++;
        }
    }

    cout << "Number of distinct elements: " << uniqueElements << endl;
    return 0;
}