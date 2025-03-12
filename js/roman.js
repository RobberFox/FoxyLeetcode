var roman = 'MCMXCIV';

/* function romanToInt(s) {
	var table = {
		I: 1,
		V: 5,
		X: 10,
		L: 50,
		C: 100,
		D: 500,
		M: 1000,
	};
	var except = {
		IV: 4,
		IX: 9,
		XL: 40,
		XC: 90,
		CD: 400,
		CM: 900,
	};

	var num = 0;
	for (let key in except) {
		if (s.match(key) !== null) {
			s = s.split(key).join('');
			num += except[key];
		}
	}

	var array = s.split('');
	for (let key in table) {
		for (let char in array) {
			if (array[char] === key) {
				num += table[key]
			}
		}
	}

	return num;
} */

function romanToInt(s) {
	var table = {
		I: 1,
		V: 5,
		X: 10,
		L: 50,
		C: 100,
		D: 500,
		M: 1000,
	};

	var array = s.split('');
	var num = 0;
	for (let i = 0; i < array.length; i++) {
		let curr = table[array[i]];
		let next = table[array[i+1]];
	
		if (curr >= next || i == array.length-1) {
			num += curr;
		}
		else {
			num -= curr;
		}
	}

	return num;
}

console.log(romanToInt(roman));

