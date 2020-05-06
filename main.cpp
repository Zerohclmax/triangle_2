//数字三角形II:
// 有一个由正整数组成的三角形，第一行只有一个数，除了最下行之外每个数的左下方和右下方各有一个数，如下图所示。

// 1
// 3 2
// 4 10 1
// 4 3 2 20
// 从第一行的数开始，除了某一次可以走到下一行的任意位置外，每次都只能左下或右下走一格，直到走到最下行，把沿途经过的数全部加起来。如何走，使得这个和尽量大？

//###########################################################################
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int maxx[n+1];
        int a[n+1][n+1];
        int d[n+1][n+1][2];
        for (int i = 0; i <= n; i++){
            for(int j = 1;j<=i;j++){
                cin>>a[i][j];
            }
        }
        memset (maxx,0,sizeof(maxx));
        for(int j=1;j<=n;j++){
            d[n][j][1] = d[n][j][0] = a[n][j];
            if(a[n][j]>maxx[n]){
                maxx[n] = a[n][j];
            }
        }
        for(int i=n-1;i>=1;i--){
            for(int j=1;j<=i;j++){
                d[i][j][0] = a[i][j] + max(d[i+1][j][0],d[i+1][j+1][0]);
                if(d[i][j][0] > maxx[i])
                    maxx[i] = d[i][j][0];
                d[i][j][1] = a[i][j] + max(max(d[i + 1][j][1], d[i + 1][j + 1][1]), maxx[i + 1]);
            }
        }
        cout<<max(d[1][1][0],d[1][1][1])<<endl;
    }
    return 0;
}