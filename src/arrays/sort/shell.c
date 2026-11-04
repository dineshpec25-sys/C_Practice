// it is optimization of insertion sort as in insertion sort if the smallest is at the last it has to move many times to reach it's correct place
//
// to avoid that  shell sort is there 
// in this the numbers move a huge distance initially so that number of swap reduces
//
// Steps used in the algorithm are,
// 1. Choose a gap sequence (n/4, n/2 ,...)
// 2. Sort elements at each gap using insertion sort
// 3. Reduce the gap and do it until it is 1
//
//
