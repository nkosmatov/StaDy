/* Generated by Frama-C */
typedef int bool;
typedef int value_type;
typedef unsigned int size_type;
size_type mismatch(value_type const *a, size_type n, value_type const *b);

bool equal(value_type const *a, size_type n, value_type const *b);

/*@ requires \at(0 <= n && \valid(a+(0 .. n-1)),Here);
    requires \at(0 <= n && \valid(b+(0 .. n-1)),Here);
    ensures
      \result != 0 <==>
      (\forall integer __q_i;
         0 <= __q_i < \old(n) ==>
         \at(*(\old(a)+__q_i),Here) == \at(*(\old(b)+__q_i),Here));
    assigns \nothing;
 */
bool equal(value_type const *a, size_type n, value_type const *b)
{
  bool __retres;
  size_type tmp;
  tmp = mismatch(a,n,b);
  __retres = tmp == n;
  return __retres;
}

/*@ requires \at(0 <= n && \valid(a+(0 .. n-1)),Here);
    requires \at(0 <= n && \valid(b+(0 .. n-1)),Here);
    assigns \nothing;
    
    behavior all_equal:
      assumes
        \forall integer __q_i;
          0 <= __q_i < n ==> \at(*(a+__q_i),Here) != \at(*(b+__q_i),Here);
      ensures \result == \old(n);
    
    behavior some_not_equal:
      assumes
        !(\forall integer __q_i;
            0 <= __q_i < n ==> \at(*(a+__q_i),Here) == \at(*(b+__q_i),Here));
      ensures 0 <= \result < \old(n);
      ensures *(\old(a)+\result) != *(\old(b)+\result);
      ensures
        \forall integer __q_i;
          0 <= __q_i < \result ==>
          \at(*(\old(a)+__q_i),Here) == \at(*(\old(b)+__q_i),Here);
    
    complete behaviors some_not_equal, all_equal;
    disjoint behaviors some_not_equal, all_equal;
 */
size_type mismatch(value_type const *a, size_type n, value_type const *b)
{
  size_type __retres;
  {
    size_type i;
    i = (unsigned int)0;
    /*@ loop invariant 0 <= i <= n;
        loop invariant
          \forall integer __q_i;
            0 <= __q_i < i ==> \at(*(a+__q_i),Here) == \at(*(b+__q_i),Here);
        loop assigns i;
        loop variant n-i;
    */
    while (i < n) {
      if (*(a + i) != *(b + i)) {
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


