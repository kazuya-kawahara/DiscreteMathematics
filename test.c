#include <stdio.h>

#define N 1000

unsigned long long int st[N+1][N+1]
unsigned long long int od[N+1][N+1]

unsigned long long int strict(m: int){
    int i, k

    st[0][0] = 1;
    for(i = 1; i <= m; i++){
        st[0][i] = 0
    }

    for(k = 1; k <= m; k++){
        for(i = 0; i < k; i++){
            st[k][i] = st[i][i];
        }
        for(i = k; i <= m; i++){
            if(k%2){
                st[k][i] = st[k-1][i] + st[k][i-k];
            }
            else{
                
            }
        }
    }

    return st[m][m];
}

unsigned long long int odd(m: int){
    int i, k

    od[0][0] = 1;
    for(i = 1; i <= m; i++){
        od[0][i] = 0
    }

    for(k = 1; k <= m; k++){
        for(i = 0; i < k; i++){
            od[k][i] = od[i][i];
        }
    }

    return od[m][m];
}