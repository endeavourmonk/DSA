const myPromise = new Promise((resolve, reject) => {
  setTimeout(() => {
    // resolve("resolving my Promise");
    reject("I am error")
  }, 4000);
});

console.log("Before Promise");
myPromise
    .then(res => console.log(res))
    .catch(err => console.log(err));
console.log("Leetcode")