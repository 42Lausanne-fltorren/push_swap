const util = require('util');
const exec = util.promisify(require('child_process').exec);

const ops = {
	"sa": (A, B) => {
		const tmp = A[0];
		A[0] = A[1];
		A[1] = tmp;
	},
	"sb": (A, B) => {
		const tmp = B[0];
		B[0] = B[1];
		B[1] = tmp;
	},
	"ss": (A, B) => {
		ops.sa(A, B);
		ops.sb(A, B);
	},
	"pa": (A, B) => {
		const tmp = B[0];
		B.shift();
		A.unshift(tmp);
	},
	"pb": (A, B) => {
		const tmp = A[0];
		A.shift();
		B.unshift(tmp);
	},
	"ra": (A, B) => {
		const tmp = A[0];
		A.shift();
		A.push(tmp);
	},
	"rb": (A, B) => {
		const tmp = B[0];
		B.shift();
		B.push(tmp);
	},
	"rr": (A, B) => {
		ops.ra(A, B);
		ops.rb(A, B);
	},
	"rra": (A, B) => {
		const tmp = A[A.length - 1];
		A.pop();
		A.unshift(tmp);
	},
	"rrb": (A, B) => {
		const tmp = B[B.length - 1];
		B.pop();
		B.unshift(tmp);
	},
	"rrr": (A, B) => {
		ops.rra(A, B);
		ops.rrb(A, B);
	}
}

function isSorted(A)
{
	for (let i = 0; i < A.length - 1; i++)
	{
		if (A[i] > A[i + 1])
			return false;
	}
	return true;
}

async function test(n, threshold) {
	let A = [];
	let B = [];
	const max = 100000;

	while (A.length < n)
	{
		A.push(Math.floor(Math.random() * max * 2) - max);
		// Remove duplicates
		A = [...new Set(A)];
	}
	const { stdout, stderr } = await exec(`./push_swap ${A.join(' ')}`);
	const operations = stdout.split('\n');
	operations.pop();
	for(let op of operations) {
		ops[op](A, B);
	}
	if (A.length != n) {
		console.log(n, "Error: A.length != n", A, B);
		return -1;
	} else if (B.length != 0) {
		console.log(n, "Error: B.length != 0", A, B);
		return -1;
	} else if (!isSorted(A)) {
		console.log(n, "Error: A is not sorted", A, B);
		return -1;
	} else if (operations.length > threshold) console.log(n, "Error: Too many operations", operations.length, ">", threshold, A, B);
	return operations.length;
}

async function test_n(tests, n, threshold) {
	let res = [];
	for (let i = 0; i < tests; i++) {
		const result = await test(n, threshold);
		if (result == -1)
			return;
		// if (i % (Math.floor(tests / 20)) == 0)
		// 	console.log(`${i} / ${tests} - ${Math.floor(i / tests * 100)}%`);
		res.push(result);
	}
	console.log("============================", n, "============================");
	console.log("Average: ", res.reduce((a, b) => a + b, 0) / res.length, " | Objective: ", threshold, " | Success: ", res.filter(x => x <= threshold).length / res.length * 100 + "%");
	console.log("Min: ", Math.min(...res));
	console.log("Max: ", Math.max(...res));
}

function generateInput(n)
{
	let A = [];
	const max = 100000;

	while (A.length < n)
	{
		A.push(Math.floor(Math.random() * max * 2) - max);
		// Remove duplicates
		A = [...new Set(A)];
	}
	console.log(A.join(' '));
}

/*test_n(1000, 2, 5);
test_n(1000, 3, 3);
test_n(1000, 4, 12);
test_n(1000, 5, 12);
test_n(1000, 100, 700);
test_n(100, 500, 5500);*/
generateInput(20);
