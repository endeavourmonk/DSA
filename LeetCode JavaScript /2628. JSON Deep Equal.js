/*
2628. JSON Deep Equal

Given two objects 01 and 02, check if they are deeply equal.

For two objects to be deeply equal, they must contain the same keys, and the associated values must also be deeply equal.
Two objects are also considered deeply equal if they pass the === equality check.
You may assume both objects are the output of JSON.parse. In other words, they are valid JSON.

Please solve it without using lodash's _.isEqual() function.

Example 1:
Input: 01 = {"x":1,"y":2}, o2 = {"x":1,"y":2}
Output: true
Explanation: The keys and values match exactly.

Example 2:
Input: 01 = {"y":2,"x":1}, o2 = {"x":1,"y":2}
Output: true
Explanation: Although the keys are in a different order, they still match exactly.

Example 3:
Input: 01 = {"x":null,"L":[1,2,3]), 02 = {"x":null,"L": ["1","2","3"]}
Output: false
Explanation: The array of numbers is different from the array of strings.

Example 4:
Input: o1 = true, 02 = false Explanation: true !== false
Output: false

Constraints:
1 <= JSON.stringify(o1).length <= 10^5
1 <= JSON.stringify(o2).length <= 10^5
maxNestingDepth = 1000
*/

/**
 * @param {any} o1
 * @param {any} o2
 * @return {boolean}
 */
/**
 * @param {any} o1
 * @param {any} o2
 * @return {boolean}
 */
function helper(key, value) {
  if (value && typeof value === "object" && !Array.isArray(value))
    return Object.fromEntries(Object.entries(value).sort());
  else return value;
}

var areDeeplyEqual = function (o1, o2) {
  const stringifiedO1 = JSON.stringify(o1, helper);
  const stringifiedO2 = JSON.stringify(o2, helper);

  return stringifiedO1 === stringifiedO2;
};
