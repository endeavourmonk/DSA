// 2665. Counter II
// Link: https://leetcode.com/problems/counter-ii/?utm_campaign=PostD3&utm_medium=Post&utm_source=Post&gio_link_id=xRxVYOXo

// TC: O(1)
// SC: O(1)
var createCounter = function (init) {
  let num = init;
  return {
    increment: () => ++num,
    decrement: () => --num,
    reset: () => (num = init),
  };
};

const counter = createCounter(5);
console.log(counter);
let ans = [];
ans.push(counter.increment()); // 6
ans.push(counter.reset()); // 5
ans.push(counter.decrement()); // 4
console.log(ans);
