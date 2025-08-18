// Q1:
#include <iostream>
using namespace std;
int search(int nums[], int len, int val) {
    int l=0, r=len-1;
    while(l<=r) {
        int m=l+(r-l)/2;
        if(nums[m]==val) return m;
        else if(nums[m]<val) l=m+1;
        else r=m-1;
    }
    return -1;
}
int main() {
    int nums[]={5,10,15,20,25,30};
    int k=20;
    int idx=search(nums,6,k);
    if(idx>=0) cout << "Index " << idx;
    else cout << "Missing";
    return 0;
}

// Q2: 
#include <iostream>
using namespace std;
void sortArr(int v[], int m) {
    for(int x=0;x<m-1;x++) {
        for(int y=0;y<m-x-1;y++) {
            if(v[y]>v[y+1]) {
                int z=v[y];
                v[y]=v[y+1];
                v[y+1]=z;
            }
        }
    }
}
int main() {
    int d[]={64,34,25,12,22,11,90};
    sortArr(d,7);
    for(int i=0;i<7;i++) cout << d[i] << " ";
    return 0;
}

// Q3: 
#include <iostream>
using namespace std;
int missLinear(int a[], int len) {
    int s=0;
    for(int k=0;k<len-1;k++) s+=a[k];
    int full=len*(len+1)/2;
    return full-s;
}
int missBinary(int b[], int len) {
    int st=0,en=len-2;
    while(st<=en) {
        int md=(st+en)/2;
        if(b[md]==md+1) st=md+1;
        else en=md-1;
    }
    return st+1;
}
int main() {
    int arr[]={1,2,4,5,6};
    int len=6;
    cout << missLinear(arr,len) << endl;
    cout << missBinary(arr,len) << endl;
    return 0;
}

// Q4a: 
#include <iostream>
#include <string>
using namespace std;
int main() {
    string a="Good", b="Morning";
    cout << a+b;
    return 0;
}

// Q4b:
#include <iostream>
#include <string>
using namespace std;
int main() {
    string c="HELLO";
    for(int i=c.size()-1;i>=0;i--) cout << c[i];
    return 0;
}

// Q4c:
#include <iostream>
#include <string>
using namespace std;
int main() {
    string txt="COMPUTER", out="";
    string vowels="aeiouAEIOU";
    for(char ch: txt) if(vowels.find(ch)==string::npos) out+=ch;
    cout << out;
    return 0;
}

// Q4d: 
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    string list[4]={"zebra","lion","cat","dog"};
    sort(list,list+4);
    for(int i=0;i<4;i++) cout << list[i] << endl;
    return 0;
}

// Q4e: 
#include <iostream>
#include <cctype>
using namespace std;
int main() {
    char ch='K';
    cout << char(tolower(ch));
    return 0;
}

// Q5: 
#include <iostream>
using namespace std;
int main() {
    int diag[]={9,8,7,6};
    for(int i=0;i<4;i++) cout << diag[i] << " ";
    return 0;
}

// Q6:
#include <iostream>
using namespace std;
int main() {
    int mat[3][3]={{3,3,3},{0,1,2},{2,0,1}};
    int t[3][3];
    t[0][0]=mat[1][0];
    t[1][0]=mat[0][0];
    t[2][0]=mat[0][1];
    cout << "Transpose done";
    return 0;
}

// Q7: 
#include <iostream>
using namespace std;
int main() {
    int nums[]={5,3,2,1,4};
    int n=5, c=0;
    for(int a=0;a<n;a++) {
        for(int b=a+1;b<n;b++) {
            if(nums[a]>nums[b]) c++;
        }
    }
    cout << c;
    return 0;
}

// Q8: 
#include <iostream>
using namespace std;
int main() {
    int nums[]={7,7,2,3,3,4};
    int l=6, d=0;
    for(int i=0;i<l;i++) {
        bool seen=false;
        for(int j=0;j<i;j++) if(nums[i]==nums[j]) {seen=true; break;}
        if(!seen) d++;
    }
    cout << d;
    return 0;
}