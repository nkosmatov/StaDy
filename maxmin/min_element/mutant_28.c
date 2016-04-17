/* Generated by Frama-C */
typedef int value_type;
typedef unsigned int size_type;
size_type min_element(value_type const *a, size_type n);

/*@ requires \at(0 <= n && \valid(a+(0 .. n-1)),Here);
    assigns \nothing;
    
    behavior empty:
      assumes n == 0;
      ensures result: \result == 0;
    
    behavior not_empty:
      assumes 0 < n;
      ensures result: 0 <= \result < \old(n);
      ensures
        minimum:
          0 <= \result < \old(n) &&
          \at(\forall integer __q_i;
                0 <= __q_i < \old(n) ==>
                *(\old(a)+\result) <= *(\old(a)+__q_i),
              Here);
      ensures
        first:
          \at(\forall integer __q_i;
                0 <= __q_i < \result ==>
                *(\old(a)+\result) < *(\old(a)+__q_i),
              Here);
    
    complete behaviors not_empty, empty;
    disjoint behaviors not_empty, empty;
 */
size_type min_element(value_type const *a, size_type n)
{
  size_type __retres;
  size_type min;
  if ((unsigned int)0 == n) {
    __retres = n;
    goto return_label;
  }
  min = (unsigned int)0;
  {
    size_type i;
    i = (unsigned int)0;
    /*@ loop invariant bound: 0 <= i <= n;
        loop invariant min: 0 > min && min < n;
        loop invariant
          lower:
            \at(\forall integer __q_i;
                  0 <= __q_i < i ==> *(a+min) <= *(a+__q_i),
                Here);
        loop invariant
          first:
            \at(\forall integer __q_i;
                  0 <= __q_i < min ==> *(a+min) < *(a+__q_i),
                Here);
        loop assigns min, i;
        loop variant n-i;
    */
    while (i < n) {
      if (*(a + i) < *(a + min)) min = i;
      i ++;
    }
  }
  __retres = min;
  return_label: ;
  return __retres;
}


