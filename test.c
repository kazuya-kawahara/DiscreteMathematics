#include <stdio.h>

#define N 1000

unsigned long long int st[N+1][N+1];
unsigned long long int od[N+1][N+1];

unsigned long long int strict(int m){
    int i, k;

    st[0][0] = 1;
    for(i = 1; i <= m; i++){
        st[0][i] = 0;
    }

    for(k = 1; k <= m; k++){
        for(i = 0; i < k; i++){
            st[k][i] = st[i][i];
        }
        for(i = k; i <= m; i++){
            st[k][i] = st[k-1][i] + st[k-1][i-k];
        }
    }

    return st[m][m];
}

unsigned long long int odd(int m){
    int i, k;

    od[0][0] = 1;
    for(i = 1; i <= m; i++){
        od[0][i] = 0;
    }

    for(k = 1; k <= m; k++){
        for(i = 0; i < k; i++){
            od[k][i] = od[i][i];
        }
        for(i = k; i <= m; i++){
            if(k%2 == 0){
                od[k][i] = od[k-1][i];
            }
            else{
                od[k][i] = od[k-1][i] + od[k][i-k];
            }
        }
    }

    return od[m][m];
}


int main() {
    int n, i;

    printf("strict(i)=odd(i) or not (1<=i<=n)\nn=?\n");
    scanf("%d", &n);

    strict(n);
    odd(n);

    for(i = 1; i <= n; i++){
        if(st[i][i] == od[i][i]){
            printf("strict(%d) = %lu", i, st[i][i]);
            printf(", od(%d) = %lu\n", i, od[i][i]);
        }
        else{
            printf("strict(%d) = %lu", i, st[i][i]);
            printf(", od(%d) = %lu\n", i, od[i][i]);
            printf("Error!");
            break;
        }
    }

    return 0;

}