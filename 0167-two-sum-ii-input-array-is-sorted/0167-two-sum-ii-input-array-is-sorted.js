/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(numbers, target) {
    let i = 0, j = numbers.length - 1;
    while (i < j) {
        let sum = numbers[i] + numbers[j];
        if (sum > target)
            j--;
        else if (sum < target)
            i++;
        else
            return [i + 1, j + 1];
    }
    return [0, 0];
};