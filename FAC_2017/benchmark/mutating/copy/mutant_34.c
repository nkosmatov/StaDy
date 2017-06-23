/* Generated by Frama-C */
typedef int value_type;
typedef unsigned int size_type;
void copy(value_type const *a, size_type const n, value_type *b);

/*@ requires \at(0 <= n && \valid(a + (0 .. n - 1)),Here);
    requires \at(0 <= n && \valid(b + (0 .. n - 1)),Here);
    requires \separated(a + (0 .. n - 1), b + (0 .. n - 1));
    ensures
      \forall integer __q_i;
        0 <= __q_i < \old(n) ==>
        \at(*(\old(a) + __q_i),Here) == \old(*(\old(a) + __q_i));
    ensures
      \forall integer __q_i;
        0 <= __q_i < \old(n) ==>
        \at(*(\old(a) + __q_i),Here) == \at(*(\old(b) + __q_i),Here);
    typically n < 5;
    assigns *(b + (0 .. n - 1));
 */
void copy(value_type const *a, size_type const n, value_type *b)
{
  size_type i;
  i = (unsigned int)0;
  loop:
    /*@ loop invariant i <= n;
        loop invariant
          \forall integer __q_i;
            0 <= __q_i < i ==>
            \at(*(a + __q_i),Here) == \at(*(b + __q_i),Here);
        loop assigns i, *(b + (0 .. n - 1));
        loop variant n - i;
    */
    while (i < n) {
      *(b + i) = *(a + i);
      i ++;
    }
  return;
}


