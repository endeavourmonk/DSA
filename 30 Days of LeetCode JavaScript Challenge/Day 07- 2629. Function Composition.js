// 2629. Function Composition
// https://leetcode.com/problems/function-composition/
/**
 * @param {Function[]} functions
 * @return {Function}
 */

// TC: O(N)
// SC: O(1)
// Approach: 1 Loops
var compose = function (functions) {
  return function (x) {
    for (let i = functions.length - 1; i >= 0; --i) {
      x = functions[i](x);
    }
    return x;
  };
};

// approach 2: reduceRight()
var compose = function (functions) {
  return function (x) {
    return functions.reduceRight((acc, currf) => currf(acc), x);
  };
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */
