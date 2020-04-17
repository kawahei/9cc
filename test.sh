#!/bin/bash
assert() {
	expected="$1"
	input="$2"
	
	./9cc "$input" > tmp.s
	cc -o tmp tmp.s
	./tmp
	actual="$?"

	if [ "$actual" = "$expected" ]; then
		echo "$input => $actual"
	else 
		echo "$input => $expected expected, but got $actual"
		exit 1
	fi
}

assert 6 6 
assert 1 1 
assert 4 1+6-3

echo OK
