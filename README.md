# RandomSelect

We have an array of n (not in order) elements, our goal is to pick out the i th 
smallest element form the array. One solution is to sort the array first, then
we coould use i as index to get the answer (O(nlgn)).
But there is a better way to do so. 
We know partition is an efficient algorithms to get the index of an element that 
is placed in an appropriate place (this element itself is sorted). So we don't
need to sort all array, just stop sorting as soon as we get the i th smallest 
element. So this algorithms should be faster than the previous one.
