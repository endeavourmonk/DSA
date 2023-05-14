// function f(a) {
//   return function (b) {
//     return function (c) {
//       console.log(a, b, c);
//     };
//   };
// }

// // f(1)(2)(3);
// const res1 = f(1);
// console.log("res1 = " + res1);
// const res2 = res1(2);
// console.log("res2 = " + res2)
// res2(3)

// TC: O(N)
// SC: O(N)
var curry = function (fn) {
  return function curried(...args) {
    if (args.length >= fn.length) return fn(...args);
    return function (...nextArgs) {
      return curried(...args, ...nextArgs);
    };
  };
};

function sum(a, b, c) {
  return a + b + c;
}
const csum = curry(sum);

// console.log(csum(1, 2, 3));
console.log(csum(1)(2)(3));
