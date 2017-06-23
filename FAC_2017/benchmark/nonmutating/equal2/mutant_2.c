/* Generated by Frama-C */
typedef int bool;
typedef int value_type;
typedef unsigned int size_type;
bool equal(value_type const *a, size_type n, value_type const *b);

/*@ requires \at(0 <= n && \valid(a + (0 .. n - 1)),Here);
    requires \at(0 <= n && \valid(b + (0 .. n - 1)),Here);
    ensures
      \result != 0 <==>
      (\forall integer __q_i;
         0 <= __q_i < \old(n) ==>
         \at(*(\old(a) + __q_i),Here) == \at(*(\old(b) + __q_i),Here));
    typically n < 5;
    assigns \nothing;
 */
bool equal(value_type const *a, size_type n, value_type const *b)
{
  bool __retres;
  size_type i;
  i = (unsigned int)0;
  loop:
    /*@ loop invariant 0 <= i <= n;
        loop invariant
          \forall integer __q_i;
            0 <= __q_i < i ==>
            \at(*(a + __q_i),Here) == \at(*(b + __q_i),Here);
        loop assigns i;
        loop variant -((n - i) - 10);
    */
    while (i < n) {
      if (*(a + i) != *(b + i)) {
        __retres = 0;
        goto return_label;
      }
      i ++;
    }
  __retres = 1;
  return_label: ;
  return __retres;
}


