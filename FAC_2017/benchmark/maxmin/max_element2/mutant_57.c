/* Generated by Frama-C */
typedef int value_type;
typedef unsigned int size_type;
size_type max_element(value_type const *a, size_type n);

/*@ requires \at(0 <= n && \valid(a + (0 .. n - 1)),Here);
    typically n < 5;
    assigns \nothing;
    
    behavior empty:
      assumes n == 0;
      ensures result: \result == 0;
    
    behavior not_empty:
      assumes 0 < n;
      ensures result: 0 <= \result < \old(n);
      ensures
        maximum:
          0 <= \result < \old(n) &&
          \at(\forall integer __q_i;
                0 <= __q_i < \old(n) ==>
                *(\old(a) + __q_i) <= *(\old(a) + \result),
              Here);
      ensures
        first:
          \at(\forall integer __q_i;
                0 <= __q_i < \result ==>
                *(\old(a) + __q_i) < *(\old(a) + \result),
              Here);
    
    complete behaviors not_empty, empty;
    disjoint behaviors not_empty, empty;
 */
size_type max_element(value_type const *a, size_type n)
{
  size_type __retres;
  size_type max;
  size_type i;
  if (n == (unsigned int)0) {
    __retres = (unsigned int)0;
    goto return_label;
  }
  max = (unsigned int)0;
  i = (unsigned int)0;
  loop:
    /*@ loop invariant bound: 0 != i && i <= n;
        loop invariant min: 0 <= max < n;
        loop invariant
          lower:
            \at(\forall integer __q_i;
                  0 <= __q_i < i ==> *(a + __q_i) <= *(a + max),
                Here);
        loop invariant
          first:
            \at(\forall integer __q_i;
                  0 <= __q_i < max ==> *(a + __q_i) < *(a + max),
                Here);
        loop assigns max, i;
        loop variant n - i;
    */
    while (i < n) {
      if (*(a + max) < *(a + i)) max = i;
      i ++;
    }
  __retres = max;
  return_label: ;
  return __retres;
}


