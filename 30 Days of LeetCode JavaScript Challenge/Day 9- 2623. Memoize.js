// 2623. Memoize
// https://leetcode.com/problems/memoize/?utm_campaign=PostD9&utm_medium=Post&utm_source=Post&gio_link_id=nRbADVd9

/**
 * @param {Function} fn
 */
// TC: O(1) accessing cached data
// SC: O(N)

// Approach: 1
function memoize(fn) {
  const memo = {};
  return function (...args) {
    const params = JSON.stringify(args);
    if (params in memo) return memo[params];
    const result = fn(...args);
    memo[params] = result;
    return result;
  };
}

// Approach: 2
var memoize =
  (fn, cache = {}) =>
  (...args) =>
    cache[args.join()] ?? (cache[args.join()] = fn(...args));

/**
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1
 */
