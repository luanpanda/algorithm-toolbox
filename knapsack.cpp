#include <bits/stdc++.h>
using namespace std;
int res[10001][301];
int solve(int w, int golds[], int n){
  for (int i = 0; i <= w; i++){
    res[i][0] = 0;
  }
  for (int i = 0; i <= n; i++)
    res[0][i] = 0;
  for (int i = 1; i <= n; i++){
    for (int subw = 1; subw <= w; subw ++){
      res[subw][i] = res[subw][i-1];
      if (golds[i] <= subw){
        res[subw][i] = max(golds[i] + res[subw - golds[i]][i-1], res[subw][i-1]);
      }
    }
}
  // for (int i = 0; i <= n; i ++){
  //   for (int j = 0; j <= w; j++)
  //     cout << res[j][i] << " ";
  //   cout << "\n";
  // }
    return res[w][n];
}
int main(){
  int w, n;
  cin >> w >> n;
  int golds[n+1];
  golds[0] = 0;
  for (int i = 1; i <= n; i++)
    cin >> golds[i];
  cout << solve(w, golds, n);
}