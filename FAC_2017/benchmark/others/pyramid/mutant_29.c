/* Generated by Frama-C */
/*@ requires 0 <= n <= 10000;
    ensures \result == ((\old(n) + 1) * \old(n)) / 2;
    typically n < 5;
    assigns \nothing;
 */
int pyramid(int n)
{
  int i;
  int sum;
  int k;
  i = 1;
  sum = 0;
  loop_1:
    /*@ loop invariant i1: 1 <= i <= (n + 1) + 1;
        loop invariant i2: sum == ((i - 1) * i) / 2;
        loop assigns sum, i, k;
        loop variant n - i;
    */
    while (i <= n) {
      k = 1;
      loop_2:
        /*@ loop invariant i3: 1 <= k <= i + 1;
            loop invariant i4: sum == (((i - 1) * i) / 2 + k) - 1;
            loop assigns sum, k;
            loop variant i - k;
        */
        while (k <= i) {
          sum ++;
          k ++;
        }
      i ++;
    }
  return sum;
}


