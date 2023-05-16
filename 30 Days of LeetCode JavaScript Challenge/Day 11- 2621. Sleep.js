// 2621. Sleep
// https://leetcode.com/problems/sleep/

/**
 * @param {number} millis
 */

// TC: O(1)
// SC: O(1)
async function sleep(millis) {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      resolve(millis);
    }, millis);
  });
}

/**
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */
