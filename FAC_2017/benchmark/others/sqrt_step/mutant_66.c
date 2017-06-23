/* Generated by Frama-C */
/*@ requires 0 <= n <= 10;
    ensures \result * \result <= \old(n) < (\result + 1) * (\result + 1);
    typically n < 5;
 */
int sqrt_step(int n)
{
  int r;
  int step;
  r = 0;
  step = n + 1;
  outer_loop:
    /*@ loop invariant
          r >= 0 && step >= 1 && r * r <= n < (r + step) * (r + step);
        loop assigns step, r;
        loop variant step;
    */
    while (step > 1) {
      step /= 2;
      inner_loop:
        /*@ loop invariant r >= 0 && r * r <= n;
            loop assigns r;
            loop variant -((n - r) - 1);
        */
        while (n >= (r + step) * (r + step)) r += step;
    }
  return r;
}


