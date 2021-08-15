#include <stdio.h>   
const int mod = 100000;      
int N,M,C; char S[22][22];      
int D[2][3][1<<21],f;   
void sum(int& a, int b){a = (a + b) % mod;}      
int main()      
{      
    int i,j,k,c;   
    scanf ("%d %d",&N,&M); C = 1;      
    for (i=0;i<N;i++){      
        scanf ("%s",S[i]);      
        for (j=0;j<M;j++){      
            if (S[i][j] == '?') C = (C * 3) % mod;      
        }      
    }      
    D[1][0][0] = 1;      
    for (i=0;i<N;i++) for (j=0;j<M;j++){      
        for (k=0;k<(1<<M);k++) D[f][0][k] = D[f][1][k] = D[f][2][k] = 0;      
        for (k=0;k<(1<<M);k++){      
            c = (D[!f][0][k] + D[!f][1][k] + D[!f][2][k]) % mod;   
            if (S[i][j] == 'K' || S[i][j] == '?') sum(D[f][0][k>>1],c);      
            if ((S[i][j] == 'I' || S[i][j] == '?') && (k & 1) == 0) sum(D[f][2][k>>1],c);      
            if (j == 0){      
                if (S[i][j] == 'O' || S[i][j] == '?') sum(D[f][1][k>>1],c);      
            }      
            else{      
                if(S[i][j] == 'O' || S[i][j] == '?'){      
                    sum(D[f][1][k>>1],D[!f][1][k]+D[!f][2][k]);      
                    sum(D[f][1][(k>>1)+(1<<(M-2))],D[!f][0][k]);      
                }      
            }      
        }      
        f = !f;      
    }      
    c = 0;      
    for (k=0;k<(1<<M);k++){      
        c = (c + D[!f][0][k] + D[!f][1][k] + D[!f][2][k]) % mod;      
    }      
    printf ("%d",(C-c+mod)%mod);      
    return 0;      
}  