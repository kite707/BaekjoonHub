#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int n, p, l, m, tmp;
string op;


int problevel[100001];
set<pair<int, int>> st;//난이도, 문제 저장



int main() {
    cin >> n;
    while (n--) {
        cin >> p >> l;
        problevel[p] = l;
        st.insert({ l,p });
    }
    cin >> m;
    string s;
    while (m--) {
        cin >> s;
        if (s == "add") {
            cin >> p >> l;
            st.insert({ l,p });
            problevel[p] = l;
        }
        else if (s == "recommend") {
            cin >> tmp;
            if (tmp == 1) {
                auto iter = --st.end();
                cout << (iter->second) << "\n";
            }
            else {
                cout << st.begin()->second << "\n";
            }
        }
        else {
            cin >> p;
            int l = problevel[p];
            st.erase({ l,p });
        }
    }
}