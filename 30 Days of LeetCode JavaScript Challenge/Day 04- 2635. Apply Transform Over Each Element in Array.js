// 2635. Apply Transform Over Each Element in Array
// Link: https://leetcode.com/problems/apply-transform-over-each-element-in-array/description/

/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */

// TC: O(N)
// SC: O(1)
var map = function (arr, fn) {
  for (i in arr) 
    arr[i] = fn(arr[i], Number(i));
  return arr;
};
