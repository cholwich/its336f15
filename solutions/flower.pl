/* Let us use a nested predicate flowers to store the solution
flowers(f(Woman1,Flower1,Color1,Place1,Day1),
        f(Woman2,Flower2,Color2,Place2,Day2),
        f(Woman3,Flower3,Color3,Place3,Day3),
        f(Woman4,Flower4,Color4,Place4,Day4),
        f(Woman5,Flower5,Color5,Place5,Day5)). */

has(X, F) :- F=flowers(X,_,_,_,_).
has(X, F) :- F=flowers(_,X,_,_,_).
has(X, F) :- F=flowers(_,_,X,_,_).
has(X, F) :- F=flowers(_,_,_,X,_).
has(X, F) :- F=flowers(_,_,_,_,X).
before(X, Y, F) :- F=flowers(X,Y,_,_,_).
before(X, Y, F) :- F=flowers(X,_,Y,_,_).
before(X, Y, F) :- F=flowers(X,_,_,Y,_).
before(X, Y, F) :- F=flowers(X,_,_,_,Y).
before(X, Y, F) :- F=flowers(_,X,Y,_,_).
before(X, Y, F) :- F=flowers(_,X,_,Y,_).
before(X, Y, F) :- F=flowers(_,X,_,_,Y).
before(X, Y, F) :- F=flowers(_,_,X,Y,_).
before(X, Y, F) :- F=flowers(_,_,X,_,Y).
before(X, Y, F) :- F=flowers(_,_,_,X,Y).
after(X, Y, F) :- before(Y, X, F).

solve(F) :-
  F = flowers(A,B,C,D,E),
  
  /* Clue (a) */
  A = f(_,tulips,yellow,_,monday),
  B = f(_,_,_,office,tuesday),
  C = f(_,_,purple,_,wednesday),
  D = f(_,roses,_,park,thursday),
  E = f(julia,_,white,_,friday),

  /* Clue (b) */

  (has(f(bethany,_,_,backyard,_), F); has(f(bethany,_,_,park,_), F)),

  /* Clue (c) */
  ((has(f(_,_,_,wedding,wednesday), F), has(f(_,_,_,birthday,friday), F));
   (has(f(_,_,_,wedding,friday), F), has(f(_,_,_,birthday,wednesday), F))),

  /* Clue (d) */
  after(f(amy,_,_,_,_), f(rachel,_,_,_,_), F),
  before(f(amy,_,_,_,_), f(kristen,_,_,_,_), F),

  /* Clue (e) */
  has(f(rachel,_,peach,office,_), F),

  /* Clue (f) */
  has(f(_,daisies,purple,_,wednesday), F),

  /* Clue (g) */
  after(f(_,_,pink,_,_), f(_,carnations,_,_,_), F),
  before(f(_,_,pink,_,_), f(_,lilies,_,_,_), F),


  /* Clue (h) */
  after(f(_,_,_,birthday,_), f(_,_,_,office,_), F),
  before(f(_,_,_,birthday,_), f(_,_,_,wedding,_), F).
