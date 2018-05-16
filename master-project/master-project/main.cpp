
//freopen("/Users/mithoonkumar/Documents/personal-github-repo/ds-algo-code/ds-algo-code/master-project/master-project/input.txt","r",stdin);

#include <iostream>
#include <vector>
#include <string.h>
/*    .___.
 /     \
 | O _ O |
 /  \_/  \
 .' /     \ `.
 / _|       |_ \
 (_/ |       | \_)
 \       /
 __\_>-<_/__
 ~;/     \;~     */


#define float double
#define debug(x) (cerr << #x << ": " << (x) << endl)

#define int long long

typedef long long ll;

using namespace std;

int n, m;
vector<string> field;

int countBombs(int r, int c) {
    int result = 0;
    if (r > 0 && c > 0 && field[r-1][c-1] == '*') result++;
    if (r > 0 && field[r-1][c] == '*') result++;
    if (r > 0 && c < m-1 && field[r-1][c+1] == '*') result++;
    if (c > 0 && field[r][c-1] == '*') result++;
    if (c < m-1 && field[r][c+1] == '*') result++;
    if (r < n-1 && c > 0 && field[r+1][c-1] == '*') result++;
    if (r < n-1 && field[r+1][c] == '*') result++;
    if (r < n-1 && r < m-1 && field[r+1][c+1] == '*') result++;
    return result;
}

int32_t main() {
    freopen("/Users/mithoonkumar/Documents/personal-github-repo/ds-algo-code/ds-algo-code/master-project/master-project/input.txt","r",stdin);
    cin >> n >> m;
    string row;
    for (int i = 0; i < n; i++) {
        cin >> row;
        field.push_back(row);
    }
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (field[r][c] == '.') {
                if (countBombs(r, c) != 0) {
                    cout << "NO\n"; return 0;
                }
            } else if (field[r][c] == '*') {
                
            } else {
                if (countBombs(r, c) != field[r][c] - '0') {
                    cout << "NO\n"; return 0;
                }
            }
        }
    }
    cout << "YES\n";
}
