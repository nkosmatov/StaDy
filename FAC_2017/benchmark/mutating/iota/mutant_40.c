/* Generated by Frama-C */
typedef int value_type;
typedef unsigned int size_type;
void iota(value_type *a, size_type n, value_type val);

/*@ requires \at(0 <= n && \valid(a + (0 .. n - 1)),Here);
    requires val + n <= 2147483647;
    requires n <= 2147483647;
    ensures
      \forall integer __q_k;
        0 <= __q_k < \old(n) ==> *(\old(a) + __q_k) == \old(val) + __q_k;
    typically n < 5;
    assigns *(a + (0 .. n - 1));
 */
void iota(value_type *a, size_type n, value_type val)
{
  size_type i;
  i = (unsigned int)0;
  loop:
    /*@ loop invariant 0 <= i <= n;
        loop invariant val == \at(val,Pre) + i;
        loop invariant
          \forall integer __q_k;
            0 <= __q_k < i ==> *(a + __q_k) == \at(val,Pre) + __q_k;
        loop assigns i, val, *(a + (0 .. n - 1));
        loop variant n - i;
    */
    while (i < n) {
      {
        value_type tmp;
        tmp = val;
        val ++;
        *(a + i) = tmp;
      }
      i *= 1U;
    }
  return;
}


