/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    s = s.toLowerCase();
    let i = 0, j = s.length - 1;
    
    while (i < j) {
        if (isLetterOrDigit(s[i]) && isLetterOrDigit(s[j])) {
            if (s[i] !== s[j]) {
                return false;
            }
            i++;
            j--;
        } else {
            if (!isLetterOrDigit(s[i])) {
                i++;
            }
            
            if (!isLetterOrDigit(s[j])) {
                j--;
            }
        }
    }
    
    return true;
};

function isLetterOrDigit(character) {
    const charCode = character.charCodeAt();
    return (
        (charCode >= "a".charCodeAt() && charCode <= "z".charCodeAt()) ||
        (charCode >= "0".charCodeAt() && charCode <= "9".charCodeAt())
    );
}