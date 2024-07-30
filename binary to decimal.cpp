#include <iostream>
#include<vector>
using namespace std;
void decToBin(int n) {   
    vector<int> ans;
    int rem;
    int quo = n;
    while(quo != 0) {
        rem = quo % 2;
        quo = quo / 2;
        ans.push_back(rem);
    }
    for(int i = ans.size()-1; i >= 0; i--) {
        cout<<ans[i]<<" ";
    }
}
int main()
{
    decToBin(16);

    return 0;
}
