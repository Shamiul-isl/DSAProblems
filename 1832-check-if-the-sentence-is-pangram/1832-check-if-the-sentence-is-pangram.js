/**
 * @param {string} sentence
 * @return {boolean}
 */
var checkIfPangram = function(sentence) {
    let alphabet = new Set("abcdefghijklmnopqrstuvwxyz");
    
    for (let i = 0; i < sentence.length; i++) {
        let cur = sentence[i].toLowerCase();
        if (alphabet.has(cur)) {
            alphabet.delete(cur);
        }
    }
    
    return alphabet.size === 0;
};