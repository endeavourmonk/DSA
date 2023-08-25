// 2721. Execute Asynchronous Functions in Parallel

/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */

// TC: O(N)
// SC: O(N)

// Approach: 1
var promiseAll = async function (functions) {
  return new Promise((res, rej) => {
    let len = functions.length,
      ct = 0;
    const ans = new Array(len);
    for (let ind = 0; ind < len; ++ind) {
      functions[ind]()
        .then((val) => {
          ans[ind] = val;
          ct++;
          if (ct === len) res(ans);
        })
        .catch((err) => rej(err));
    }
  });
};

// Approach: 2
var promiseAll = async function (functions) {
  return new Promise(async (res, rej) => {
    let len = functions.length,
      ct = 0;
    const ans = new Array(len);
    functions.forEach(async (func, ind) => {
      try {
        let val = await func();
        ans[ind] = val;
        ct++;
        if (ct === len) res(ans);
      } catch (err) {
        rej(err);
      }
    });
  });
};

// var promiseAll = async function (functions) {
//   return new Promise(async (res, rej) => {
//     let len = functions.length,
//       ct = 0;
//     const ans = new Array(len);
//     for (let ind = 0; ind < len; ++ind) {
//       try {
//         let val = await functions[ind]();
//         ans[ind] = val;
//         ct++;
//         if (ct === len) res(ans);
//       } catch (err) {
//         rej(err);
//       }
//     }
//   });
// };

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */

// Note:
// In code 3, we are using a traditional for loop to iterate through the functions array. Inside the loop, you are using await to wait for each promise to resolve before moving on to the next iteration. This means that the promises are executed sequentially, one after the other. This leads to a longer total execution time since each promise takes some time to resolve and you are waiting for each one before moving to the next.

// In code 2, we are using the forEach method to iterate through the functions array. Inside the forEach callback, you are using await again to wait for each promise to resolve. However, the key difference here is that the forEach loop itself doesn't wait for the promises. It starts executing all the promises concurrently and then the await inside the loop makes sure to pause the execution until each individual promise is resolved. This approach leads to parallel execution of promises and a shorter total execution time since they overlap in execution.
