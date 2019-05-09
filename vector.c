#include "vector.h"

typedef char* string;

typedef struct {
    int x, y;
} Tuple;

int main(void)
{
    printf("Output for String:\n");
    qvec(string) *sv = qvec_new(string, "Who", "are", "you?");
    qvec_print(sv);
    qvec_at(sv, 2) = "we?";
    qvec_print(sv);
    qvec_free(sv);

    printf("Output for int:\n");
    qvec(int) *iv = qvec_new(int, 1, 2, 3, 4);
    qvec_print(iv);
    printf("%d\n", qvec_pop(iv));
    qvec_free(iv);

    printf("Output for Double:\n");
    qvec(double) *dv = qvec_new(double, 1, 2, 3, 4);
    qvec_print(dv);
    printf("%lf\n", qvec_pop(dv));
    qvec_free(dv);

    printf("Output for Tuple:\n");
    qvec(Tuple) *tv = qvec_new(Tuple, { .x = 0, .y = 1 }, { 4, 2 }, { 5, 4 });
    printf("%d\n", qvec_at(tv, 1).x);
    printf("%d\n", qvec_at(tv, 2).x);
    qvec_free(tv);
}