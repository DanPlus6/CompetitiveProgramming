// CCC '13 S2 - Bridge Transport
function main() {
    const ipt = require('fs');

    const data = ipt.readFileSync(0, 'utf8').trim().split(/\s+/).map(Number);

    let i = 0;
    var W = data[i++];
    var N = data[i++];

    var C = [];
    for (let j = 0; j < N; j++) {
        C.push(data[i++]);
    }

    // still leanring js >.<
    // const readline = require('readline');

    // const rl = readline.createInterface({
    //     input: process.stdin,
    //     output: process.stdout
    // });

    // incorrect input parsing
    // the following reads a single line not all input
    // let W;
    // let N;
    // let C = [];

    // rl.on('line', (line) => {
    //     W = line;
    //     N = line;
    //     for (let i = 0; i < N; i++) C.push(line);
    //     rl.close();
    // });

    if (C[0] > W) {return 0;}

    let res = 0, weight = 0, l = 0, r = 4;
    for(let i = 0; i < ((N < 4) ? N : 4); i++) {
        weight += C[i];
        if (weight > W) return res;
        res++;
    }

    while (r < N) {
        weight += C[r];
        weight -= C[l]; l++;
        if (weight > W) return res;
        res++;
        r++;
    }

    return res;
}

console.log(main());

