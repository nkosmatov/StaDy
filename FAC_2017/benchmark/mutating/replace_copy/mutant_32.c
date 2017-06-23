/* Generated by Frama-C */
typedef int value_type;
typedef unsigned int size_type;
size_type replace_copy(value_type const *a, size_type n, value_type *b,
                       value_type oldv, value_type newv);

/*@ requires \at(0 <= n && \valid(a + (0 .. n - 1)),Here);
    requires \at(0 <= n && \valid(b + (0 .. n - 1)),Here);
    requires \separated(a + (0 .. n - 1), b + (0 .. n - 1));
    ensures
      \forall integer __q_i;
        0 <= __q_i < \old(n) ==>
        \old(*(a + __q_i)) == \old(oldv) ==> *(\old(b) + __q_i) == \old(newv);
    ensures
      \forall integer __q_i;
        0 <= __q_i < \old(n) ==>
        \old(*(a + __q_i)) != \old(oldv) ==>
        *(\old(b) + __q_i) == \old(*(a + __q_i));
    ensures
      \forall integer __q_i;
        0 <= __q_i < \old(n) ==> *(\old(a) + __q_i) == \old(*(a + __q_i));
    ensures \result == \old(n);
    typically n < 5;
    assigns *(b + (0 .. n - 1));
 */
size_type replace_copy(value_type const *a, size_type n, value_type *b,
                       value_type oldv, value_type newv)
{
  size_type i;
  i = (unsigned int)0;
  loop:
    /*@ loop invariant 0 < i <= n;
        loop invariant
          \forall integer __q_k;
            0 <= __q_k < i ==>
            \at(*(a + __q_k),Pre) == oldv ==> *(b + __q_k) == newv;
        loop invariant
          \forall integer __q_k;
            0 <= __q_k < i ==>
            \at(*(a + __q_k),Pre) != oldv ==>
            *(b + __q_k) == \at(*(a + __q_k),Pre);
        loop assigns i, *(b + (0 .. n - 1));
        loop variant n - i;
    */
    while (i < n) {
      if (*(a + i) == oldv) *(b + i) = newv; else *(b + i) = *(a + i);
      i ++;
    }
  return n;
}


