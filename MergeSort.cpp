#include <bits/stdc++.h>
using namespace std;


void merge(vector<int>&v, int f, int e) {
    int m = (f + e) >> 1;

    //copying.
    int l = f, l1 = m-f+1, l2 = e-m;
    vector<int> v1(l1), v2(l2);
    for(int i = 0; i < l1; ++i) v1[i] = v[l++];
    for(int i = 0; i < l2; ++i) v2[i] = v[l++];

    //merging.
    l = f;
    int i = 0, j = 0;
    while(i < l1 && j < l2)
       v[l++] = (v1[i] < v2[j]? v1[i++] : v2[j++]);

    while(i < l1) v[l++] = v1[i++];
    while(j < l2) v[l++] = v2[j++];
    for(auto it : v) cout << it << ' '; cout << '\n';
}
void mergesort(vector<int>&v, int f, int e) {
    if(f == e) return;
    int m = (f+e)>>1;
    mergesort(v, f, m), mergesort(v, m+1, e);
    merge(v, f, e);
}
void solve() {

    int n; cin >> n;
    vector<int> v(n);
    for(auto& it : v) cin >> it;

    mergesort(v, 0, n-1);
    for(auto it : v) cout << it << ' '; cout << '\n';
}
/*
     1 2 3 4 5 6 7 8

       1        5
     1   3    4   5


 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}