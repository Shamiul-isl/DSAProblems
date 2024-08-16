/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function(matrix) {
    let totalIslands = 0;
    // TODO: Write your code here
    for (let i = 0; i < matrix.length; i++) {
      for (let j = 0; j < matrix[0].length; j++) {
        if (matrix[i][j] === '1') {
          totalIslands++;
          bfs([i, j], matrix);
        }
      }
    }
    return totalIslands;
};

function bfs(position, matrix) {
    let queue = [];
    queue.push(position);
    while (queue.length > 0) {
      let cur = queue.shift();
      let i = cur[0];
      let j = cur[1];
      if (i >= matrix.length || i < 0 || j >= matrix[0].length || j < 0) {
        continue;
      }

      if (matrix[i][j] !== '0') {
          matrix[i][j] = '0';
          queue.push([i + 1, j]);
          queue.push([i - 1, j]);
          queue.push([i, j + 1]);
          queue.push([i, j - 1]);
      }
    }
  }