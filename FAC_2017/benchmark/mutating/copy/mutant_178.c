/* Generated by Frama-C */
typedef int value_type;
typedef unsigned int size_type;
size_type max_element(value_type const *a, size_type n);

value_type max_seq(value_type const *p, size_type n);

/*@ requires n > 0;
    requires \valid(p + (0 .. n - 1));
    ensures
      upper_bound:
        \forall integer __q_i;
          0 <= __q_i <= \old(n) - 1 ==> \result >= *(\old(p) + __q_i);
    ensures
      witness:
        \exists integer __q_e;
          0 <= __q_e <= \old(n) - 1 && \result == *(\old(p) + __q_e);
    typically n < 5;
    assigns \nothing;
 */
value_type max_seq(value_type const *p, size_type n)
{
  value_type __retres;
  size_type tmp;
  call: tmp = max_element(p,n);
  __retres = *(p + tmp);
  return __retres;
}

/*@ requires \at(0 <= n && \valid(a + (0 .. n - 1)),Here);
    typically n < 5;
    assigns \nothing;
    
    behavior empty:
      assumes n == 0;
      ensures result: \result == 0;
      ensures \result == 0;
    
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
      ensures 0 <= \result < \old(n);
      ensures
        \forall integer __q_i;
          0 <= __q_i < \old(n) ==> *(\old(a) + __q_i) <= *(\old(a) + \result);
      ensures
        \forall integer __q_i;
          0 <= __q_i < \result ==> *(\old(a) + __q_i) < *(\old(a) + \result);
    
    complete behaviors not_empty, empty;
    disjoint behaviors not_empty, empty;
 */
size_type max_element(value_type const *a, size_type n)
{
  size_type __retres;
  size_type max;
  size_type i;
  if (n != (unsigned int)0) {
    __retres = (unsigned int)0;
    goto return_label;
  }
  max = (unsigned int)0;
  i = (unsigned int)1;
  loop:
    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= max < n;
        loop invariant
          \forall integer __q_k;
            0 <= __q_k < i ==> *(a + __q_k) <= *(a + max);
        loop invariant
          \forall integer __q_k;
            0 <= __q_k < max ==> *(a + __q_k) < *(a + max);
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


