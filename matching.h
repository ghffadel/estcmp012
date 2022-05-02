# include <stdbool.h>
# include <stdio.h>
# include <string.h>

# define max(x, y) (x) > (y) ? (x) : (y)
# define min(x, y) (x) < (y) ? (x) : (y)

/*
Galil-Seiferas Algorithm

- Complexidade de espaço extra constante
- Preprocessamento em O(m) e complexidade de espaço constante
- Pesquisa realizada em O(n)
- Realiza 5n comparações no pior caso
*/

void new_p1 (char *x, int *m, char *y, int *n, int *k, int *p, int *p1, int *p2, int *q, int *q1, int *q2, int *s);

void search (char *x, int *m, char *y, int *n, int *k, int *p, int *p1, int *p2, int *q, int *q1, int *q2, int *s) {
    while (*p <= *n - *m) {
        while (*p + *s + *q < *n && x[*s + *q] == y[*p + *s + *q]) {
            (*q)++;
        }

        if (*q == *m - *s && memcmp(x, y + *p, *s + 1) == 0) {
            printf("Pattern found at %d\n", *p);
        }

        if (*q == *p1 + *q1) {
            (*p) += *p1;
            (*q) -= *p1;
        }

        else {
            (*p) += (*q / *k + 1);
            *q = 0;
        }
    }
}

void parse (char *x, int *m, char *y, int *n, int *k, int *p, int *p1, int *p2, int *q, int *q1, int *q2, int *s) {
    while (true) {
        while (x[*s + *q1] == x[*s + *p1 + *q1]) {
            (*q1)++;
        }

        while (*p1 + *q1 >= *k * *p1) {
            (*s) += *p1;
            (*q1) -= *p1;
        }

        (*p1) += (*q1 / *k + 1);
        *q1 = 0;

        if (*p1 >= *p2) {
            break;
        }
    }

    new_p1(x, m, y, n, k, p, p1, p2, q, q1, q2, s);
}

void new_p2 (char *x, int *m, char *y, int *n, int *k, int *p, int *p1, int *p2, int *q, int *q1, int *q2, int *s) {
    while (x[*s + *q2] == x[*s + *p2 + *q2] && *p2 + *q2 < *k * *p2) {
        (*q2)++;
    }

    if (*p2 + *q2 == *k * *p2) {
        parse(x, m, y, n, k, p, p1, p2, q, q1, q2, s);
    }

    else {
        if (*s + *p2 + *q2 == *m) {
            search(x, m, y, n, k, p, p1, p2, q, q1, q2, s);
        }

        else {
            if (*q2 == *p1 + *q1) {
                (*p2) += *p1;
                (*q2) -= *p1;
            }

            else {
                (*p2) += (*q2 / *k + 1);
                *q2 = 0;
            }

            new_p2(x, m, y, n, k, p, p1, p2, q, q1, q2, s);
        }
    }
}

void new_p1 (char *x, int *m, char *y, int *n, int *k, int *p, int *p1, int *p2, int *q, int *q1, int *q2, int *s) {
    while (x[*s + *q1] == x[*s + *p1 + *q1]) {
        (*q1)++;
    }

    if (*p1 + *q1 >= *k * *p1) {
        *p2 = *q1;
        *q2 = 0;
        new_p2(x, m, y, n, k, p, p1, p2, q, q1, q2, s);
    }

    else {
        if (*s + *p1 + *q1 == *m) {
            search(x, m, y, n, k, p, p1, p2, q, q1, q2, s);
        }

        (*p1) += (*q1 / *k + 1);
        *q1 = 0;
        new_p1(x, m, y, n, k, p, p1, p2, q, q1, q2, s);
    }
}

void GS (char *x, int m, char *y, int n) {
    int k, p, p1, p2, q, q1, q2, s;

    k = 4;
    p = p2 = q = q1 = q2 = s = 0;
    p1 = 1;

    new_p1(x, &m, y, &n, &k, &p, &p1, &p2, &q, &q1, &q2, &s);
}

/*
Two Way Algorithm

- O alfabeto precisa estar ordenado
- Preprocessamento em O(m) e complexidade de espaço constante
- Pesquisa realizada em O(n)
- Realiza 2n - m comparações no pior caso
*/

int maximal_suffix (char *x, int m, int *p) {
    char a, b;
    int j, k, ms;

    ms = -1;
    j = 0;
    k = *p = 1;

    while (j + k < m) {
        a = x[j + k];
        b = x[ms + k];

        if (a < b) {
            j += k;
            k = 1;
            *p = j - ms;
        }

        else {
            if (a == b) {
                if (k != *p) {
                    k++;
                }

                else {
                    j += *p;
                    k = 1;
                }
            }

            else {
                ms = j;
                j = ms + 1;
                k = *p = 1;
            }
        }
    }

    return ms;
}

int maximal_suffix_reverse (char *x, int m, int *p) {
    char a, b;
    int j, k, ms;

    ms = -1;
    j = 0;
    k = *p = 1;

    while (j + k < m) {
        a = x[j + k];
        b = x[ms + k];

        if (a > b) {
            j += k;
            k = 1;
            *p = j - ms;
        }

        else {
            if (a == b) {
                if (k != *p) {
                    k++;
                }

                else {
                    j += *p;
                    k = 1;
                }
            }

            else {
                ms = j;
                j = ms + 1;
                k = *p = 1;
            }
        }
    }

    return ms;
}

void TW (char *x, int m, char *y, int n) {
    int ell, i, j, mem, p, per, q;

    i = maximal_suffix(x, m, &p);
    j = maximal_suffix_reverse(x, m, &q);

    if (i > j) {
        ell = i;
        per = p;
    }

    else {
        ell = j;
        per = q;
    }

    if (memcmp(x, x + per, ell + 1) == 0) {
        j = 0;
        mem = -1;

        while (j <= n - m) {
            i = max(ell, mem) + 1;

            while (i < m && x[i] == y[i + j]) {
                i++;
            }

            if (i >= m) {
                i = ell;

                while (i > mem && x[i] == y[i + j]) {
                    i--;
                }

                if (i <= mem) {
                    printf("Pattern found at %d\n", j);
                }

                j += per;
                mem = m - per - 1;
            }

            else {
                j += i - ell;
                mem = -1;
            }
        }
    }

    else {
        per = max(ell + 1, m - ell - 1) + 1;
        j = 0;

        while (j <= n - m) {
            i = ell + 1;

            while (i < m && x[i] == y[i + j]) {
                i++;
            }

            if (i >= m) {
                i = ell;

                while (i >= 0 && x[i] == y[i + j]) {
                    i--;
                }

                if (i < 0) {
                    printf("Pattern found at %d\n", j);
                }

                j += per;
            }

            else {
                j += (i - ell);
            }
        }
    }
}

/*
String Matching on Ordered Alphabets

- Não possui preprocessamento
- O alfabeto precisa estar ordenado
- Complexidade de espaço extra constante
- Pesquisa realizada em O(n)
- Realiza 6n + 5 comparações no pior caso
*/

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
                printf("Pattern found at %d\n", j);
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