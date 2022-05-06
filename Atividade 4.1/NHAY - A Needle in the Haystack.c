# include <stdio.h>
# include <string.h>

# define max(x, y) (x) > (y) ? (x) : (y)
# define MAXN 1000010
# define min(x, y) (x) < (y) ? (x) : (y)

char haystack[MAXN], needle[MAXN];
int length;

void next_maximal_suffix (char *x, int m, int *ip, int *jp, int *k, int *p) {
    char a, b;

    while (*jp + *k < m) {
        a = x[*ip + *k];
        b = x[*jp + *k];

        if (a == b) {
            if (*k == *p) {
                (*jp) += *p;
                *k = 1;
            }

            else {
                (*k)++;
            }
        }

        else {
            if (a > b) {
                (*jp) += *k;
                *k = 1;
                *p = *jp - *ip;
            }

            else {
                *ip = *jp;
                (*jp)++;
                *k = *p = 1;
            }
        }
    }
}

void SMOA (char *x, int m, char *y, int n) {
    int i, ip, j, jp, k, p;

    ip = -1;
    i = j = jp = 0;
    k = p = 1;

    while (j <= n - m) {
        while (i + j < n && i < m && x[i] == y[i + j]) {
            i++;
        }

        if (i == 0) {
            j++;
            ip = -1;
            jp = 0;
            k = p = 1;
        }

        else {
            if (i >= m) {
                printf("%d\n", j);
            }

            next_maximal_suffix(y + j, i + 1, &ip, &jp, &k, &p);

            if (ip < 0 || (ip < p && memcmp(y + j, y + j + p, ip + 1) == 0)) {
                j += p;
                i -= p;

                if (i < 0) {
                    i = 0;
                }

                if (jp - ip > p) {
                    jp -= p;
                }

                else {
                    ip = -1;
                    jp = 0;
                    k = p = 1;
                }
            }

            else {
                j += max(ip + 1, min(i - ip - 1, jp + 1)) + 1;
                i = jp = 0;
                ip = -1;
                k = p = 1;
            }
        }
    }
}

int main () {
    while (scanf("%d", &length) != EOF) {
        scanf("%s %s", needle, haystack);
        SMOA(needle, length, haystack, strlen(haystack));
        printf("\n");
    }
    
    return 0;
}