let A = [];
let B = [];
let count = 0;

function sa()
{
	// Swap first two el from A
	const tmp = A[0];
	A[0] = A[1];
	A[1] = tmp;
	count++;
}

function sb()
{
	// Swap first two el from B
	const tmp = B[0];
	B[0] = B[1];
	B[1] = tmp;
	count++;
}

function ss()
{
	sa();
	sb();
	count++;
}

function pa()
{
	const tmp = B[0];
	B.shift();
	A.unshift(tmp);
	count++;
}

function pb()
{
	const tmp = A[0];
	A.shift();
	B.unshift(tmp);
	count++;
}

function ra()
{
	const tmp = A[0];
	A.shift();
	A.push(tmp);
	count++;
}

function rb()
{
	const tmp = B[0];
	B.shift();
	B.push(tmp);
	count++;
}

function rr()
{
	ra();
	rb();
	count++;
}

function rra()
{
	const tmp = A[A.length - 1];
	A.pop();
	A.unshift(tmp);
	count++;
}

function rrb()
{
	const tmp = B[B.length - 1];
	B.pop();
	B.unshift(tmp);
	count++;
}

function rrr()
{
	rra();
	rrb();
	count++;
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
	console.log("Count: " + count);
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

function place(n)
{
	let rot = 0;
	while (B[rot] != n) rot++;
	let revRot = 0;
	while (B[(B.length - revRot) % B.length] != n) revRot++;
	if (rot < revRot)
		for (let i = 0; i < rot; i++)
			rb();
	else
		for (let i = 0; i < revRot; i++)
			rrb();
	// console.log(n, rot, revRot);
	pa();
	// print();
}

function solveForLots()
{
	const chunks = A.length <= 100 ? 5 : 11;
	const interval = Math.max(...A) - Math.min(...A);
	const chunkInterval = Math.ceil(interval / chunks);
	const start = Math.min(...A);

	for (let c = 0; c < chunks; c++)
	{
		const min = start + chunkInterval * c;
		const max = min + chunkInterval;
		// console.log(min, max);
		while (A.filter(n => n >= min && n <= max).length > 0)
		{
			let i = 0;
			while (A[i] < min || A[i] > max)
				i++;
			if (i == A.length)
				break;
			let rot = 0;
			while (A[rot] != A[i]) rot++;
			let revRot = 0;
			while (A[(A.length - revRot - 1) % A.length] != A[i]) revRot++;
			if (rot < revRot)
				for (let j = 0; j < rot; j++)
					ra();
			else
				for (let j = 0; j < revRot; j++)
					rra();
			pb();
		}
		// print();
	}
	while (B.length > 0)
	{
		place(Math.max(...B));
	}
	// print();
}

function tester()
{
	const tests = 1000;
	const n = 100;
	const results = [];
	const max = 10000;

	console.time("Tester");
	for (let t = 0; t < tests; t++)
	{
		A = [];
		B = [];
		count = 0;
		while (A.length < n)
		{
			A.push(Math.floor(Math.random() * max * 2) - max);
			// Remove duplicates
			A = [...new Set(A)];
		}
		console.log("Test " + (t + 1), A);
		solveForLots();
		if (!isSorted())
		{
			print();
			throw new Error("Error", t+1, A);
		}
		results.push(count);
	}
	console.timeEnd("Tester");
	console.log("Average: ", results.reduce((a, b) => a + b) / results.length);
	console.log("Min: ", Math.min(...results));
	console.log("Max: ", Math.max(...results));
}

tester();
