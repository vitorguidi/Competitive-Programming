#include <bits/stdc++.h>
 
 
using namespace std;
 
const int N = 10;
 
vector <int> ord, v;
 
map <vector <int>, int> mp_1, mp_2;
int cnt_1 = 0, cnt_2 = 0;
 
double val_1[5000], val_2[5000];
 
int n;
 
double ans_1(vector <int> a) {
    
    double sum = 0;
    int tot = n*n;
    int test = 1;
    for (int i = 0; i < n; ++i) {
        if(a[i] != ord[i]) {
            test = 0;
        }
    }
    if(test == 1) return 0.0;
    if(mp_1.find(a) == mp_1.end()) {
        mp_1[a] = cnt_1++; 
    } else {
        return val_1[mp_1[a]];
    }
    cout << "wtf" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            vector <int> b;
            for (int k = 0; k < n; ++k) {
                b.push_back(a[k]);
            }
            swap(b[i], b[j]);
            int ok = 1;
            for (int k = 0; k < n; ++k) {
                if(a[k] != b[k]) {
                    ok = 0;
                }
            }
            if (ok) {
                tot--;
            } else {
                sum += ans_1(b);
            }
        }
    }
    cout << "eee "<< tot << " " << sum << endl;
    return val_1[mp_1[a]] = (sum+1)/tot;
}
 
double ans_2(vector <int> a) {
    
    double sum = 0;
    int tot = n-1;
    int test = 1;
    for (int i = 0; i < n; ++i) {
        if(a[i] != ord[i]) {
            test = 0;
        }
    }
    if(test == 1) return 0.0;
    if(mp_2.find(a) == mp_2.end()) {
        mp_2[a] = cnt_2++; 
    } else {
        return val_2[mp_2[a]];
    }
    for (int i = 0; i < n-1; ++i) {
        int j = i+1;
        vector <int> b;
        for (int k = 0; k < n; ++k) {
            b.push_back(a[k]);
        }
        swap(b[i], b[j]);
        int ok = 1;
        for (int k = 0; k < n; ++k) {
            if(a[k] != b[k]) {
                ok = 0;
            }
        }
        if (ok) {
            tot--;
        } else {
            sum += ans_2(b);
        }
    }
    return val_2[mp_2[a]] = (sum+1)/tot;
}
 
int main() {
    int t;
    cin >> t;
    cout << setprecision(12) << fixed;
    
 
    for (int cas = 0; cas < t; ++cas) {
        cin >> n;
        ord.clear();
        v.clear();
        mp_1.clear(), mp_2.clear(); 
        cnt_1 = 0, cnt_2 = 0;
 
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            v.push_back(x);
            ord.push_back(x);
        }
        sort(ord.begin(), ord.end());
        cout << "Monty " << ans_1(v) << " Carlos " << ans_2(v) << endl;
    }
     
}


