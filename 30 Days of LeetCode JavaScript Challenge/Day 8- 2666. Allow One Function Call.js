// 2666. Allow One Function Call
// https://leetcode.com/problems/allow-one-function-call/?utm_campaign=PostD8&utm_medium=Post&utm_source=Post&gio_link_id=a9By01Oo

/**
 * @param {Function} fn
 * @return {Function}
 */

// TC: O(1)
// SC: O(1)
var once = function (fn) {
  let firstCall = true;
  return function (...args) {
    if (firstCall) {
      firstCall = false;
      return fn(...args);
    }
  };
};

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */
