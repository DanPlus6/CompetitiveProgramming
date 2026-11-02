/**
 * Author: DanPlus6 // David Fu
 * Problem Name: 2733. Add Two Promises
 * Problem Code: add-two-promises
 * Problem URL:  https://leetcode.com/problems/add-two-promises/description/
 */
'use strict';

/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
const addTwoPromises = async function(promise1, promise2) {
    return (await promise1 + await promise2);
};
