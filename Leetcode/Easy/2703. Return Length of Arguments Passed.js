'use strict';
/**
 * Author: DanPlus6 // David Fu
 * Problem Name: 2703. Return Length of Arguments Passed
 * Problem Code: return-length-of-arguments-passed
 * Problem URL:  https://leetcode.com/problems/return-length-of-arguments-passed/
 */

/**
 * @param {...(null|boolean|number|string|Array|Object)} args
 * @return {number}
 */
const argumentsLength = (...args) => args.length;
