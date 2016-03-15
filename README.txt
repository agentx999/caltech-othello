CS 2 Othello README
Maya Josyula


When I submitted Part 1, my heuristic originally assigned different weights
to different parts of the board. All the corners had a weight of 2, the 
edge positions right next to the corners had a weight of -2, the other
edges had a weight of 3, and the positions diagonal to the corners had
a weight of -3. Using this, I could beat SimplePlayer pretty much 100% of the 
time, and could beat ConstantTimePlayer about half of the time.

When I started Part 2, I knew that ConstantTimePlayer didn't use a minimax
search algorithm so I figured I should be able to beat it simply by modifying
my heuristic a little. The first thing I tried was taking the number of pieces
heuristic that I used for testminimax (# your pieces - # opponent's pieces) and
combining it in a weighted average with the board weights matrix I already had.
I thought that since those were two valid heuristics, combining them in some
way might make them better. Surprisingly enough, this did end up working. I 
experimented with a lot of different weightings and found that 0.4 * the pieces
heuristic + 0.6 * the board heuristic was by far the best, netting me wins 
against ConstantTimePlayer 8/10 times. 

I then tried making my board heuristic more complex, since it only weighted
a small fraction of the total pieces on the board (along the edges, plus four
extra squares) and I thought a board matrix that took more positions into 
account might end up working better. While looking up Othello strategy, I 
found a more complicated board weight matrix online that I adapted here:
http://www.samsoft.org.uk/reversi/strategy.htm
Notably, it assigned negative weights to pieces that were next to edges,
as well as pieces that were next to corners. I replaced my original board
position matrix with this one instead, and if I used the same idea as I
described above I won against ConstantTimePlayer 18/20 times. 

I then figured I was good enough to move on to BetterPlayer. I was a bit wary
of moving on, because I knew BetterPlayer uses minimax and I hadn't 
implemented minimax as part of my competitive strategy yet. But when I tested
my AI against BetterPlayer for the first time, I discovered that as black,
I could TIE against it with my combination pieces-board-weights heuristic. (Of
course, as white, BetterPlayer annihilated me. But that comes later.) That was
when I first got the idea that instead of struggling to incorporate minimax
into my program and dealing with things slowing down and having to worry
about memory problems, all I had to do was come up with an intelligent enough
heuristic in order to outsmart BetterPlayer. 

I tried a lot of things that were kind of random in retrospect. I changed 
various entries on my board weight matrix first - I tried counting the edges 
as higher than the corners, I tried eliminating all the weights near the middle
and keeping all the middle positions the same value, I tried valuing the
corners less (which changed nothing, interestingly), and I tried swapping the 
values of the two entire middle columns. And, of course, with every change, I
tried calculating my pieces-board weighted average in different ways. 
None of these managed to beat BetterPlayer, and I actually started losing 
against ConstantTimePlayer as well after a while. 

After A LOT of failed heuristics, I decided to try something completely new,
and implemented the minimizing-frontiers idea that was discussed in the 
second Othello recitation. I needed to modify board.h to do this, and made
some of the private methods public in order to make my life a little easier
when I was calculating the number of adjacent occupied squares.

I then found something interesting: if I took out my number of pieces heuristic 
and substituted the frontiers one instead, I would consistently lose to 
BetterPlayer as black, but consistently win as white. If I changed the weighted 
average, I would consistently win as black, but consistently lose as white. 
This implies that as a black player, it is in one's best interests to make sure 
one is minimizing one's frontier score, and that minimizing the frontier is not 
as important in an optimal strategy as white as it is as black. This makes 
sense, because if black goes first, more of black's pieces would naturally be 
frontier pieces, so black would want to take special care to make sure they 
don't overextend themselves.

My final heuristic takes 0.7 * the board weights + 0.3 * the frontier score if
the player is white, and 0.6 * the board weights + 0.4 * the frontier score if
the player is black. It beats ConstantTimePlayer 19/20 times, and BetterPlayer
10/10 times - and it does not use minimax.

I think this strategy works partly due to the combination: my player tries
to play in an optimal location, but also tries to minimize the frontier. In
terms of gameplay, this tends to result in me hovering around the middle
for a while, and then suddenly expanding around the edges in late-middle or
early-endgame. The way my strategy changes depending on whether I go first
or second helps too, because the way my player works kind of mirrors how
an actual person would want to play. 

In terms of the tournament, I'm sure there are a lot of people out there that
did a bunch of crazy things to make their programs amazing, so I'm not expecting 
to do very well. But thinking up an algorithm that actually beats an AI that 
looks three turns into the future is pretty cool. I'm happy I managed to do it, 
and I'm really excited to see how my non-minimax AI fares against everyone 
else's. 

(I was solo, so I did everything.) 
