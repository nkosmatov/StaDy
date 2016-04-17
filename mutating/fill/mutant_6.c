/* Generated by Frama-C */
typedef int value_type;
typedef unsigned int size_type;
void fill(value_type *a, size_type n, value_type val);

/*@ requires \at(0 <= n && \valid(a+(0 .. n-1)),Here);
    ensures
      constant:
        \at(\forall integer __q_i;
              0 <= __q_i < \old(n) ==> *(\old(a)+__q_i) == \old(val),
            Here);
    assigns *(a+(0 .. n-1));
 */
void fill(value_type *a, size_type n, value_type val)
{
  size_type i;
  i = (unsigned int)0;
  /*@ loop invariant bound: 0 <= i <= n+1;
      loop invariant
        constant:
          \at(\forall integer __q_i; 0 <= __q_i < i ==> *(a+__q_i) == val,
              Here);
      loop assigns i, *(a+(0 .. n-1));
      loop variant n-i;
  */
  while (i < n) {
    *(a + i) = val;
    i ++;
  }
  return;
}


