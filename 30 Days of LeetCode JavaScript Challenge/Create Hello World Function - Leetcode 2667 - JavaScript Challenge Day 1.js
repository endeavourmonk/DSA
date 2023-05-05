// TC: O(1)
var createHelloWorld = function() {
    return function(...args) {
        return "Hello World";
    }
};