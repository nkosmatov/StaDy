/* Generated by Frama-C */
typedef int value_type;
typedef unsigned int size_type;
size_type adjacent_find(value_type const *a, size_type n);

/*@ requires \at(0 <= n && \valid(a+(0 .. n-1)),Here);
    assigns \nothing;
    
    behavior some:
      assumes
        \exists integer __q_i;
          0 <= __q_i < n-1 && *(a+__q_i) == *(a+(__q_i+1));
      ensures 0 <= \result < \old(n)-1;
      ensures *(\old(a)+\result) == *(\old(a)+(\result+1));
      ensures
        !(\exists integer __q_i;
            0 <= __q_i < \result-1 &&
            *(\old(a)+__q_i) == *(\old(a)+(__q_i+1)));
    
    behavior none:
      assumes
        !(\exists integer __q_i;
            0 <= __q_i < n-1 && *(a+__q_i) == *(a+(__q_i+1)));
      ensures \result == \old(n);
    
    complete behaviors none, some;
    disjoint behaviors none, some;
 */
size_type adjacent_find(value_type const *a, size_type n)
{
  size_type __retres;
  if ((unsigned int)0 == n) {
    __retres = n;
    goto return_label;
  }
  {
    size_type i;
    i = (unsigned int)0;
    /*@ loop invariant 0 <= i <= n;
        loop invariant
          !(\exists integer __q_i;
              0 <= __q_i < (i+1)-1 && *(a+__q_i) == *(a+(__q_i+1)));
        loop assigns i;
        loop variant n-i;
    */
    while (i < n - (unsigned int)1) {
      if (*(a + i) == *(a + (i + (unsigned int)1))) {
        __retres = i;
        goto return_label;
      }
      i ++;
    }
  }
  __retres = n;
  return_label: ;
  return __retres;
}


