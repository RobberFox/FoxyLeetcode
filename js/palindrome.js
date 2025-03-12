var num = 121
/* function isPalindrome(x) {
	var str = String(x);
	var reverse = str.split('').reverse().join('');
	return (str === reverse);
} */

function isPalindrome(x) {
	if (x<0) 
		return false
	var rev = 0;

	var temp = x;
	var digit;

	while (temp > 0) {
		digit = temp % 10;
		rev = rev*10 + digit;
		temp = Math.floor(temp/10);
	}
	return (x === rev);
}

console.log(isPalindrome(num));
