// 2620. Counter
// Link: https://leetcode.com/problems/counter/description/?utm_campaign=PostD2&utm_medium=Post&utm_source=Post&gio_link_id=xogkVqBo

// TC: O(1)
// SC: O(1)
var createCounter = function (n) {
  let i = -1;
  return function () {
    ++i;
    return i + n;
  };
};

/**
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */
