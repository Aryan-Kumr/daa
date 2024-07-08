//horspool
#include <iostream>
#include<vector>
using namespace std;
string text = "JIM_SAW_ME_IN_BARBER_SHOP";
string pattern = "BARBER";
int m = pattern.size();
int n = text.size();
vector<int> table(128, m);

void badMatchTable() {
    for(int i = 0; i < m-1; i++) {
        table[pattern[i]] = m - i - 1;
    }
}

int horspool() {
    int i = m-1;
    while(i < n) {
        int k = 0;  // to keep rocord of no. of matched characters
        while(k < m && pattern[m - k - 1] == text[i - k]) {
            k++;
        }
        if(k == m) {
            return i - m + 1;
        }
        else {
            i = i + table[text[i]];
        }
    }
    return -1;
}

int main() {
    badMatchTable();
    int res = horspool();
    if (res == -1) {
        cout << "\nPattern not found\n";
    } else {
        cout << "\nPattern found at pos = " << res << endl;
    }
    return 0;
}