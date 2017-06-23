/* Generated by Frama-C */
typedef int bool;
typedef int value_type;
typedef unsigned int size_type;
bool binary_search(value_type const *a, size_type n, value_type val);

size_type lower_bound(value_type const *a, size_type n, value_type val);

/*@ requires \at(0 <= n && \valid(a + (0 .. n - 1)),Here);
    requires
      \forall integer __q_ii;
        0 <= __q_ii < n ==>
        (\forall integer __q_jj;
           __q_ii < __q_jj < n ==> *(a + __q_ii) <= *(a + __q_jj));
    ensures
      result:
        \result != 0 <==>
        (\exists integer __q_i;
           0 <= __q_i < \old(n) && *(\old(a) + __q_i) == \old(val));
    typically n < 5;
    assigns \nothing;
 */
bool binary_search(value_type const *a, size_type n, value_type val)
{
  size_type i;
  int tmp;
  call: i = lower_bound(a,n,val);
  if (i < n) 
    if (*(a + i) <= val) tmp = 1; else tmp = 0;
  else tmp = 0;
  return tmp;
}

/*@ requires \at(0 <= n && \valid(a + (0 .. n - 1)),Here);
    requires
      \forall integer __q_ii;
        0 <= __q_ii < n ==>
        (\forall integer __q_jj;
           __q_ii < __q_jj < n ==> *(a + __q_ii) <= *(a + __q_jj));
    ensures result: 0 <= \result <= \old(n);
    ensures
      left:
        \at(\forall integer __q_i;
              0 <= __q_i < \result ==> *(\old(a) + __q_i) < \old(val),
            Here);
    ensures
      right:
        \at(\forall integer __q_i;
              \result <= __q_i < \old(n) ==> \old(val) <= *(\old(a) + __q_i),
            Here);
    typically n < 5;
    assigns \nothing;
 */
size_type lower_bound(value_type const *a, size_type n, value_type val)
{
  size_type left;
  size_type right;
  size_type middle;
  left = (unsigned int)0;
  right = n;
  middle = (unsigned int)0;
  loop:
    /*@ loop invariant bound: 0 <= left && left > right && right <= n;
        loop invariant
          left:
            \at(\forall integer __q_i;
                  0 <= __q_i < left ==> *(a + __q_i) < val,
                Here);
        loop invariant
          right:
            \at(\forall integer __q_i;
                  right <= __q_i < n ==> val <= *(a + __q_i),
                Here);
        loop assigns middle, left, right;
        loop variant right - left;
    */
    while (left < right) {
      middle = left + (right - left) / (unsigned int)2;
      if (*(a + middle) < val) left = middle + (unsigned int)1;
      else right = middle;
    }
  return left;
}


