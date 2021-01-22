# woshitaincai
we will happy to see our allocation rule is monotone and implementable.

# myerson's lemma
Three parts
1. an allocation rule is implementable -> checking it is monotone or not.
2. In the case, you have the monotone/implement, how can we find the payment rule to get the DSI property. if you bid 0, then you payment is 0.(due to the upperbound and the lowerbound of the payment).
3. payment is given by an explicity forumula (TBD)

---

#new content
## collary
There is an awsonme auction for sponsor search

## proof
consdier an allocation rule x. If (x,p)what does p have to look like? We just need to narrow down the search space and then find the optimal price rule. Fistly we need to  fix the auction price from others, and see the relationship between x(i) and p(i)
For sponsor's search, the x(i) will jump several times \alpha_i.

then 0<z<y;
1. case1 when true value is z, and the bid y.  
   if we bid z, then z * x(z) - p(z) > z *  x(y)  - p(z)(The inequality is based on the telling truthfulling is a DSIC strategy)
2. case2 when true value is y, and the bid z.  
   then we can get a different inequality.

In conclusion, 
?<p(y) - p(z) <? (*)
The above two cases, is just the extension of DSIC regardless of the bids

### exercise
* implicate thta x is not monotone (nondecreasing)  is not implementable
rest of the proof, assume x is monotone. for simplicity, assume x is piecewise constant.
In *, fixing z and take the limit y down to z to derrive ?
The resuld depend on the location of z.
also indicate the relationship from p and x
if x is jump, then p has to jump by z\times jump(x)
else p keeps constant as x keeps unchanged. (for piecceswise assumption)

subject to the DISC property, extension it, then the only possible payment rule p will depend on the x. we show that this payment rule is the only possible work strategy. 

### then we need to verify that p actually works when x is monotone.

proof by pic, see telling truthfully, overbid and lowerbid will bring us what

and remember the surplus formula
v \times x(b) - p(b)
By three rectangle, the utility will be the best if the monotone and truthfully strategy will be the DISC strategy 

