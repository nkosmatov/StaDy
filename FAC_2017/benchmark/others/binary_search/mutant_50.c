/* Generated by Frama-C */
/*@ requires n >= 1;
    requires \valid(t + (0 .. n - 1));
    requires \forall integer __q_i;
      \forall integer __q_j;
        0 <= __q_i < __q_j < n ==> *(t + __q_i) <= *(t + __q_j);
    ensures -1 <= \result <= \old(n) - 1;
    ensures
      \forall integer __q_i;
        0 <= __q_i <= \result ==> *(\old(t) + __q_i) <= \old(x);
    ensures
      \forall integer __q_i;
        \result < __q_i < \old(n) ==> *(\old(t) + __q_i) > \old(x);
    typically n < 5;
 */
int binary_search(int n, int x, int *t)
{
  int m;
  int L;
  int R;
  L = -1;
  R = n - 1;
  loop:
    /*@ loop invariant -1 >= L && L <= R <= n - 1;
        loop invariant
          \forall integer __q_i; 0 <= __q_i <= L ==> *(t + __q_i) <= x;
        loop invariant
          \forall integer __q_i; R < __q_i < n ==> *(t + __q_i) > x;
        loop assigns m, L, R;
        loop variant R - L;
    */
    while (L < R) {
      m = ((L + R) + 1) / 2;
      if (x < *(t + m)) R = m - 1; else L = m;
    }
  return L;
}


