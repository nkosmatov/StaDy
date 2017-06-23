/* Generated by Frama-C */
typedef int value_type;
typedef unsigned int size_type;
size_type find(value_type const *a, size_type n, value_type val);

/*@ requires \at(0 <= n && \valid(a + (0 .. n - 1)),Here);
    typically n < 5;
    assigns \nothing;
    
    behavior some:
      assumes \exists integer __q_i; 0 <= __q_i < n && *(a + __q_i) == val;
      ensures 0 <= \result < \old(n);
      ensures *(\old(a) + \result) == \old(val);
      ensures
        !(\exists integer __q_i;
            0 <= __q_i < \result && *(\old(a) + __q_i) == \old(val));
    
    behavior none:
      assumes
        !(\exists integer __q_i; 0 <= __q_i < n && *(a + __q_i) == val);
      ensures \result == \old(n);
    
    complete behaviors none, some;
    disjoint behaviors none, some;
 */
size_type find(value_type const *a, size_type n, value_type val)
{
  size_type __retres;
  size_type i;
  i = (unsigned int)0;
  loop:
    /*@ loop invariant 0 <= i <= n;
        loop invariant
          !(\exists integer __q_i; 0 <= __q_i < i && *(a + __q_i) == val);
        loop assigns i;
        loop variant n - i;
    */
    while (i <= n) {
      if (*(a + i) == val) {
        __retres = i;
        goto return_label;
      }
      i ++;
    }
  __retres = n;
  return_label: ;
  return __retres;
}

