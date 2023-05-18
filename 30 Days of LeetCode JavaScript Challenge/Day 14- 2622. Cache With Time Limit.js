class TimeLimitedCache {
  constructor() {
    this.cache = new Map();
  }

  set(key, value, duration) {
    const keyExist = this.cache.get(key);
    if (keyExist)
      clearTimeout(keyExist.timer);
    const timer = setTimeout(() => this.cache.delete(key), duration);
    this.cache.set(key, { value, timer });
    return Boolean(keyExist);
  }

  get(key) {
    return this.cache.has(key) ? this.cache.get(key).value : -1;
  }

  count() {
    return this.cache.size;
  }
}

var obj = new TimeLimitedCache();
console.log(obj.set(1, 42, 1000)); // false
console.log(obj.get(1)); // 42
console.log(obj.count()); // 1
