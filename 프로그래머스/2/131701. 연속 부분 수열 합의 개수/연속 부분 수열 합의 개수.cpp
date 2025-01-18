#include <string>
#include <vector>
#include <set>


using namespace std;
int arr[1001];

int solution(vector<int> elements) {
    int N = elements.size();
    set<int> s;
    for(int i=0;i<N;i++){
        for(int j = 0; j<N;j++){
            arr[j]+=elements[(i+j)%N];
            s.insert(arr[j]);
        }
    }
    return s.size();
}