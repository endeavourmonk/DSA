// 2626. Array Reduce Transformation
// https://leetcode.com/problems/array-reduce-transformation/description/

/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */

// TC: O(N)
// SC: O(1)
var reduce = function (nums, fn, init) {
  let val = init;
  for (i in nums) val = fn(val, nums[i]);
  return val;
};
