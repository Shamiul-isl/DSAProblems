/**
 * @param {number[][]} image
 * @param {number} sr
 * @param {number} sc
 * @param {number} color
 * @return {number[][]}
 */
var floodFill = function(matrix, x, y, newColor) {
    // TODO: Write your code here
    let start = matrix[x][y];
    let queue = [];
    queue.push([x, y]);
    let directions = [[1, 0], [-1, 0], [0, 1], [0,-1]];

    while (queue.length > 0) {
      let cur = queue.shift();
      let row = cur[0], col = cur[1];
      if (matrix[row][col] === start && start !== newColor) {
        matrix[row][col] = newColor;
      } else
        continue;

      for (let direction of directions) {
        let newRow = row + direction[0];
        let newCol = col + direction[1];

        if (newRow >= 0 && newRow < matrix.length && newCol >= 0 && newCol < matrix[0].length && matrix[newRow][newCol] === start) {
          queue.push([newRow, newCol]);
        }
      } 
    }
    return matrix;
  };