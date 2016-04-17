/* Generated by Frama-C */
typedef int value_type;
typedef unsigned int size_type;
void reverse_copy(value_type const *a, size_type n, value_type *b);

/*@ requires \at(0 <= n && \valid(a+(0 .. n-1)),Here);
    requires \at(0 <= n && \valid(b+(0 .. n-1)),Here);
    requires \separated(a+(0 .. n-1), b+(0 .. n-1));
    ensures
      \forall integer __q_i;
        0 <= __q_i < \old(n) ==>
        *(\old(b)+__q_i) == *(\old(a)+((\old(n)-1)-__q_i));
    assigns *(b+(0 .. n-1));
 */
void reverse_copy(value_type const *a, size_type n, value_type *b)
{
  size_type i;
  i = (unsigned int)0;
  /*@ loop invariant 0 <= i <= n+1;
      loop invariant
        \forall integer __q_k;
          0 <= __q_k < i ==> *(b+__q_k) == *(a+((n-1)-__q_k));
      loop assigns i, *(b+(0 .. n-1));
      loop variant n-i;
  */
  while (i < n) {
    *(b + i) = *(a + ((n - (unsigned int)1) - i));
    i ++;
  }
  return;
}


