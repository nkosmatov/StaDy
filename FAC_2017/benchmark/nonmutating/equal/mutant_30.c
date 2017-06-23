/* Generated by Frama-C */
typedef int bool;
typedef int value_type;
typedef unsigned int size_type;
bool equal(value_type const *a, size_type n, value_type const *b);

/*@ requires \at(0 <= n && \valid(a + (0 .. n - 1)),Here);
    requires \at(0 <= n && \valid(b + (0 .. n - 1)),Here);
    typically n < 5;
    assigns \nothing;
    
    behavior all_equal:
      assumes
        \forall integer __q_i;
          0 <= __q_i < n ==> *(a + __q_i) == *(b + __q_i);
      ensures \result != 0;
    
    behavior some_not_equal:
      assumes
        \exists integer __q_i; 0 <= __q_i < n && *(a + __q_i) != *(b + __q_i);
      ensures \result == 0;
    
    complete behaviors some_not_equal, all_equal;
    disjoint behaviors some_not_equal, all_equal;
 */
bool equal(value_type const *a, size_type n, value_type const *b)
{
  bool __retres;
  size_type i;
  i = (unsigned int)0;
  loop:
    /*@ loop invariant 0 >= i && i <= n;
        loop invariant
          \forall integer __q_k;
            0 <= __q_k < i ==> *(a + __q_k) == *(b + __q_k);
        loop assigns i;
        loop variant n - i;
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


