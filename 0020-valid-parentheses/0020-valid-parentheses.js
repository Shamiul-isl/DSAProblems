/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let seen = [];

    for (let i = 0; i < s.length; i++) {
        let char = s[i];
        if (char === '(' || char === '[' || char === '{')
            seen.push(char);
        else if ((char === '}' && seen.pop() !== "{") || 
            (char === ']' && seen.pop() !== '[') || 
            (char === ')' && seen.pop() !== '(')) {
            return false;
        }
    }
    return seen.length === 0;
};