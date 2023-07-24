# Rate of return

The rate of return *r* of a single financial asset over a period is the interest obtained at the end of period by investing on it. 

## Example 

If the rate of return over a single period is r = 0.05 and we invest a quantity S = 1000 euro at the beginning of the period, the final value of our portfolio is V = (1 + r) * S = 1050 euro at the end of the period. 

## Requirements

Let us assume that, at the beginning of the period, we invest a total sum S over *n* assets with rate of return *r~i~*, by allocating a fraction *w~i~* of *S* in the *i*-th asset.

Write a program which reads the data from a file of name **data.csv** of the following format:

```text
S;1000
n;8
w;r
0.05;0.1
0.2;0.01
0.12;0.05
0.18;0.02
0.15;0.02
0.15;0.05
0.1;0.01
0.05;0.03
```

and computes the rate of return and the final value of the whole portfolio. 

The read data and the result must be printed on the screen and on a file named "result.txt".

The export format is:

```text
S = 1000.00, n = 8
w = [ 0.05 0.2 0.12 0.18 0.15 0.15 0.1 0.05 ]
r = [ 0.1 0.01 0.05 0.02 0.02 0.05 0.01 0.03 ]
Rate of return of the portfolio: 0.0296
V: 1029.60
```

Remark: S and V must be printed in decimal notation with 2 digits of precision by keeping *trailing* zeros.
