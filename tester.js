let A = [];
let B = [];
let operations = [];

function sa()
{
	// Swap first two el from A
	const tmp = A[0];
	A[0] = A[1];
	A[1] = tmp;
	operations.push("sa");
}

function sb()
{
	// Swap first two el from B
	const tmp = B[0];
	B[0] = B[1];
	B[1] = tmp;
	operations.push("sb");
}

function ss()
{
	sa();
	sb();
	operations.push("ss");
}

function pa()
{
	const tmp = B[0];
	B.shift();
	A.unshift(tmp);
	operations.push("pa");
}

function pb()
{
	const tmp = A[0];
	A.shift();
	B.unshift(tmp);
	operations.push("pb");
}

function ra()
{
	const tmp = A[0];
	A.shift();
	A.push(tmp);
	operations.push("ra");
}

function rb()
{
	const tmp = B[0];
	B.shift();
	B.push(tmp);
	operations.push("rb");
}

function rr()
{
	ra();
	rb();
	operations.pop();
	operations.pop();
	operations.push("rr");
}

function rra()
{
	const tmp = A[A.length - 1];
	A.pop();
	A.unshift(tmp);
	operations.push("rra");
}

function rrb()
{
	const tmp = B[B.length - 1];
	B.pop();
	B.unshift(tmp);
	operations.push("rrb");
}

function rrr()
{
	rra();
	rrb();
	// remove last operation
	operations.pop();
	operations.pop();
	operations.push("rrr");
}

function isSorted()
{
	for (let i = 0; i < A.length - 1; i++)
		if (A[i] > A[i + 1])
			return false;
	return true;
}

function print()
{
	console.log("A: " + A);
	console.log("B: " + B);
	console.log("Sorted: " + isSorted());
	console.log("Count: " + operations.length);
}

function solveFor3()
{
	// Sort in ascending order
	if (A[0] > A[1] && A[1] < A[2] && A[0] < A[2]) // b a c
		sa();
	else if (A[0] < A[1] && A[2] < A[1] && A[0] > A[2]) // b c a
		rra();
	else if (A[0] < A[1] && A[1] > A[2]) // a c b
	{
		rra();
		sa();
	} else if (A[0] > A[1] && A[0] > A[2] && A[1] < A[2]) // c a b
		ra();
	else if (A[0] > A[1] && A[1] > A[2]) // c b a
	{
		sa();
		rra();
	}
}

function findNeighbours(n)
{
	let nU = Math.min(...A);
	let nD = Math.max(...A);

	if (n > nD || n < nU)
		return [nU, nD];
	for (let i = 0; i < A.length; i++)
	{
		if (A[i] > n && A[i] < nD)
			nD = A[i];
		if (A[i] < n && A[i] > nU)
			nU = A[i];
	}
	return [nU, nD];
}

function solveFor5()
{
	// We first push the 2 firsts el from A to B
	pb(); pb();
	// Then we sort the 3 remaining el from A
	solveFor3();
	// Then we push back the 2 firsts el from B to A in the correct positions
	// Count the number of rotations needed to put the first el into A
	for (let j = 0; j < 2; j++)
	{
		//print();
		let neighboors = findNeighbours(B[0]);
		//console.log(neighboors);
		let rot = 0;
		while (!neighboors.includes(A[(rot - 1) % A.length]) || !neighboors.includes(A[rot % A.length])) rot++;
		let revRot = 0;
		while (!neighboors.includes(A[(A.length - revRot) % A.length]) || !neighboors.includes(A[(A.length - revRot - 1) % A.length])) revRot++;
		//console.log(rot, revRot);
		if (rot < revRot)
			for (let i = 0; i < rot; i++)
				ra();
		else
			for (let i = 0; i < revRot; i++)
				rra();
		pa();
	}
	// Then we rotate A to put the smallest el at the top
	//print();
	let rotations = 0;
	while (A[rotations] != Math.min(...A)) rotations++;
	let reverseRotations = 0;
	while (A[(A.length - reverseRotations) % A.length] != Math.min(...A)) reverseRotations++;
	//console.log(rotations, reverseRotations);
	if (rotations < reverseRotations)
		for (let i = 0; i < rotations; i++)
			ra();
	else
		for (let i = 0; i < reverseRotations; i++)
			rra()
}

function countMoves(n)
{
	let target = Math.max(...B);
	if (n > Math.min(...B) && n < Math.max(...B)) {
		target = Math.min(...B);
		for (let i = 0; i < B.length; i++)
		{
			if (B[i] < n && B[i] > target)
				target = B[i];
		}
	}

	let rotB = 0;
	while (B[rotB] != target) rotB++;
	let revRotB = 0;
	while (B[Math.abs((B.length - revRotB) % B.length)] != target) revRotB++;

	let rotA = 0;
	while (A[rotA] != n) rotA++;
	let revRotA = 0;
	while (A[Math.abs((A.length - revRotA) % A.length)] != n) revRotA++;

	//console.log("n: ", n, "rotB: ", rotB, "revRotB: ", revRotB, "rotA: ", rotA, "revRotA: ", revRotA, target);
	let res = Math.min((rotB + revRotA), (revRotB + rotA), Math.max(rotB, rotA), Math.max(revRotB, revRotA));
	if (res == rotB + revRotA)
		return {rb: rotB, rra: revRotA, ra: 0, rrb: 0, rr: 0, rrr: 0};
	else if (res == revRotB + rotA)
		return {rrb: revRotB, ra: rotA, rb: 0, rra: 0, rr: 0, rrr: 0};
	else if (res == Math.max(rotB, rotA))
	{
		let min = Math.min(rotB, rotA);
		if (rotB < rotA)
			return {rb: 0, ra: rotA - min, rra: 0, rrb: 0, rr: min, rrr: 0};
		else
			return {rb: rotB - min, ra: 0, rra: 0, rrb: 0, rr: min, rrr: 0};
	}
	else if (res == Math.max(revRotB, revRotA))
	{
		let min = Math.min(revRotB, revRotA);
		if (revRotB < revRotA)
			return {rrb: 0, rra: revRotA - min, rb: 0, ra: 0, rr: 0, rrr: min};
		else
			return {rrb: revRotB - min, rra: 0, rb: 0, ra: 0, rr: 0, rrr: min};
	}
	else
		return null;
}

function solveForLots()
{
	// First we push the 2 firsts el from A to B
	pb(); pb();

	while (A.length > 0)
	{
		let moves = {};
		for (let i = 0; i < A.length; i++)
			moves[A[i]] = countMoves(A[i]);
		//console.log(moves);
		let min = Infinity;
		let key;
		for (let i = 0; i < A.length; i++)
		{
			let m = moves[A[i]];
			let sum = m.rb + m.ra + m.rr + m.rra + m.rrb + m.rrr;
			if (sum < min)
			{
				min = sum;
				key = A[i];
			}
		}
		//console.log("Key: ", key);
		let m = moves[key];
		for (let i = 0; i < m.rb; i++)
			rb();
		for (let i = 0; i < m.ra; i++)
			ra();
		for (let i = 0; i < m.rr; i++)
			rr();
		for (let i = 0; i < m.rra; i++)
			rra();
		for (let i = 0; i < m.rrb; i++)
			rrb();
		for (let i = 0; i < m.rrr; i++)
			rrr();
		pb();
		//print();
	}
	while (B.length > 0)
		pa();
	//print();
	let rotations = 0;
	while (A[rotations] != Math.min(...A)) rotations++;
	let reverseRotations = 0;
	while (A[(A.length - reverseRotations) % A.length] != Math.min(...A)) reverseRotations++;
	//console.log(rotations, reverseRotations);
	if (rotations < reverseRotations)
		for (let i = 0; i < rotations; i++)
			ra();
	else
		for (let i = 0; i < reverseRotations; i++)
			rra()
	//print();
}

function tester(n, tests)
{
	const results = [];
	const max = 100000;

	for (let t = 0; t < tests; t++)
	{
		A = [];
		B = [];
		operations = [];
		while (A.length < n)
		{
			A.push(Math.floor(Math.random() * max * 2) - max);
			// Remove duplicates
			A = [...new Set(A)];
		}
		if (n == 3)
			solveFor3();
		else if (n == 5)
			solveFor5();
		else
			solveForLots();
		//print();
		if (!isSorted())
		{
			console.log( t+1, A, operations);
			throw new Error("Error");
		}
		results.push(operations.length);

		if (t%10 == 0) console.log(n, "Test " + (t) + " / " + tests, "Min: ", Math.min(...results), "Max: ", Math.max(...results), "Avg: ", results.reduce((a, b) => a + b) / results.length);
	}
	return results;
}

let three = tester(3, 1000);
let five = tester(5, 1000);
let hundred = tester(100, 1000);
let five_hundred = tester(500, 500);

console.log("===== 3 (min: " + Math.min(...three) + ", max: " + Math.max(...three) + ", avg: " + three.reduce((a, b) => a + b) / three.length + ", objective: " + three.filter(t => t <= 5).length + ")=====");
console.log("===== 5 (min: " + Math.min(...five) + ", max: " + Math.max(...five) + ", avg: " + five.reduce((a, b) => a + b) / five.length + ", objective: " + five.filter(t => t <= 12).length + ")=====");
console.log("===== 100 (min: " + Math.min(...hundred) + ", max: " + Math.max(...hundred) + ", avg: " + hundred.reduce((a, b) => a + b) / hundred.length + ", objective: " + hundred.filter(t => t <= 700).length + ")=====");
console.log("===== 500 (min: " + Math.min(...five_hundred) + ", max: " + Math.max(...five_hundred) + ", avg: " + five_hundred.reduce((a, b) => a + b) / five_hundred.length + ", objective: " + five_hundred.filter(t => t <= 5500).length + ")=====");
