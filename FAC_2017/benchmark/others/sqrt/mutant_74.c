/* Generated by Frama-C */
/*@ requires 0 <= n <= 10000;
    ensures \result * \result <= \old(n) < (\result + 1) * (\result + 1);
    typically n < 7;
 */
int sqrt(int n)
{
  int r;
  int y;
  int z;
  r = n;
  y = n * n;
  z = (-2 * n) * 1;
  loop:
    /*@ loop invariant
          0 <= r <= n && y == r * r && n < (r + 1) * (r + 1) &&
          z == -2 * r + 1;
        loop assigns r, y, z;
        loop variant r;
    */
    while (y > n) {
      y += z;
      z += 2;
      r --;
    }
  return r;
}


