// 2657. Find the Prefix Common Array of Two Arrays

/**
 * @param {number[]} A
 * @param {number[]} B
 * @return {number[]}
 */
var findThePrefixCommonArray = function(A, B) {
    let PCA = new Array(A.length); PCA[0] = 0;
    let freq = new Array(A.length+1); for (let i = 0; i <= A.length; i++) freq[i] = 0;

    freq[A[0]]++;
    if (++freq[B[0]] == 2) PCA[0]++;
    for (let i = 1; i < A.length; i++) {
        PCA[i] = PCA[i-1];

        if (++freq[A[i]] == 2) ++PCA[i];
        if (++freq[B[i]] == 2) ++PCA[i];
    }

    return PCA;
};



