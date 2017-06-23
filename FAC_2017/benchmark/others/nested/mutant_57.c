/* Generated by Frama-C */
void nested(int n, int m)
{
  int p;
  int q;
  p = 2;
  q = 2;
  loop_1:
    /*@ loop invariant i1: p >= 2 && q >= 2;
        loop assigns p, n, q, m;
        loop variant n;
    */
    while (n > 0) {
      loop_2:
        /*@ loop invariant q <= 2;
            loop assigns q, m;
            loop variant m; */
        while (m > 0) {
          q = 2;
          m = 0;
        }
      p = 2;
      n = 0;
    }
  /*@ assert p + q >= 4; */ ;
  return;
}


