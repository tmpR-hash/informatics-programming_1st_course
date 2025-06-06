#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for( int i = 1; i < n; i++){
        for( int j = i * 2; j; j -= 2 )
            cout << j << ' ';
        cout << endl;
        for( int j = 0; j < i; j++ )
            cout << ( i - 1 ) * 3 << ' ';
        cout << endl;
    }
    return 0;
}
