/**
 * @param {string} sentence
 * @return {boolean}
 */
var checkIfPangram = function(sentence) {
    let alphabet = new Set(sentence);
    return alphabet.size === 26;
};