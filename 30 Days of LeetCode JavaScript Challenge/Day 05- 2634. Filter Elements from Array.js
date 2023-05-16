// 2634. Filter Elements from Array
// https://leetcode.com/problems/filter-elements-from-array/description/
// https://leetcode.com/problems/filter-elements-from-array/solutions/3502707/easy-javascript-solution-in-o-n/

/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
// TC: O(N)
// SC: O(N)
var filter = function (arr, fn) {
  let res = [];
  for (i in arr) {
    if (fn(arr[i], Number(i))) res.push(arr[i]);
  }
  return res;
};
