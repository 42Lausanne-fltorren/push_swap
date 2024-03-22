n = 500;
A = []; while (A.length < n) { A.push(Math.floor(Math.random() * 100000 * 2) - 100000); A = [...new Set(A)];} console.log(A.join(" "));