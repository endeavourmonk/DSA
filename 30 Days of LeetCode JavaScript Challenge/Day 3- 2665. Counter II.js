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
