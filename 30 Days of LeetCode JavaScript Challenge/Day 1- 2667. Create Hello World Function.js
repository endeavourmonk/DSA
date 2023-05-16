// 2667. Create Hello World Function
// https://leetcode.com/problems/create-hello-world-function/?utm_campaign=PostD1&utm_medium=Post&utm_source=Post&gio_link_id=QPDw0kJR

// TC: O(1)
// SC: O(1)
var createHelloWorld = function () {
  return function (...args) {
    return "Hello World";
  };
};
