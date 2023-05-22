// 2636. Promise Pool
// https://leetcode.com/problems/promise-pool/description/

/**
 * @param {Function[]} functions
 * @param {number} n
 * @return {Function}
 */
// TC: O(functions.length)
var promisePool = async function (functions, n) {
    return new Promise((resolve) => {
      let inProgress = 0, index = 0;
      function helper() {
        // base case
        if (index >= functions.length) {
          if (inProgress === 0) resolve();
          return;
        }
  
        while (inProgress < n && index < functions.length) {
          inProgress++;
          functions[index++]().then(() => {
            inProgress--;
            helper();
          });
        }
      }
      helper();
    });
  };
  
  /**
   * const sleep = (t) => new Promise(res => setTimeout(res, t));
   * promisePool([() => sleep(500), () => sleep(400)], 1)
   *   .then(console.log) // After 900ms
   */