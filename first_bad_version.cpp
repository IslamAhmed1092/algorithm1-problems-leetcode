#include <iostream>
using namespace std;

int bad;

bool isBadVersion(int v) {
    if(v >= bad) {
        return true;
    }

    return false;
}

int firstBadVersion(int n) {
    int l = 0, r = n-1;
    int firstBad = 0;
    while(l <= r) {
        int m = l + (r-l)/2;
        if(isBadVersion(m+1)) {
            r = m-1;
        } else {
            l = m+1;
        }
    }

    return l+1;
}

int main() {
    int n;
    cin>>n>>bad;
    cout<<firstBadVersion(n);
    return 0;
}