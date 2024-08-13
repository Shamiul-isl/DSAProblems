/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    let seen = new Map();
    
    for (let i = 0; i < s.length; i++) {
        seen.set(s[i], (seen.get(s[i]) ? seen.get(s[i]): 0) + 1);
    }
    
        
        
    for (let i = 0; i < t.length; i++) {
        if (seen.has(t[i])) {
            let curCount = seen.get(t[i]);
            if (curCount === 1)
                seen.delete(t[i]);
            else
                seen.set(t[i], curCount - 1);
        } else
            return false;
    }
    
    
    return seen.size === 0;
};