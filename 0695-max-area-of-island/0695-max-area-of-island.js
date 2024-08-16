/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxAreaOfIsland = function(matrix) {
    let biggestIslandArea = 0;
    // TODO: Write your code here

    for (let i = 0; i < matrix.length; i++) {
      for (let j = 0; j < matrix[0].length; j++) {
        if (matrix[i][j] == 1) {
          biggestIslandArea = Math.max(biggestIslandArea, bfs([i, j], matrix));
        }
      }
    }
    return biggestIslandArea;
};

function bfs(position, matrix) {
    let landCounter = 0;
    let queue = [];
    queue.push(position);

    while (queue.length > 0) {
      let cur = queue.shift();
      let row = cur[0];
      let col = cur[1];

      if (row < 0 || row >= matrix.length || col < 0 || col >= matrix[0].length)
        continue;
      
      if (matrix[row][col] == 0)
        continue;
      
      landCounter++;
      matrix[row][col] = 0;
      queue.push([row + 1, col]);
      queue.push([row - 1, col]);
      queue.push([row, col + 1]);
      queue.push([row, col - 1]);
    }

    return landCounter;
  }