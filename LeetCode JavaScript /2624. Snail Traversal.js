// 2624. Snail Traversal

// SC: O(rows * cols);
// TC: O(rows * cols);
Array.prototype.snail = function (rowsCount, colsCount) {
  if (this.length !== rowsCount * colsCount) return [];

  const res = new Array(rowsCount)
    .fill()
    .map(() => new Array(colsCount).fill(0));

  let revOrder = false,
    ind = 0;
  for (let j = 0; j < colsCount; ++j) {
    if (!revOrder) for (let i = 0; i < rowsCount; ++i) res[i][j] = this[ind++];
    else for (let i = rowsCount - 1; i >= 0; --i) res[i][j] = this[ind++];

    revOrder = !revOrder;
  }
  return res;
};
