%HW6
%Author: Brett Yeager
%CS 451
%This program is a 4x4 tic tac toe game. You win by getting 4 in a row

%All possible wins
ordered_line(1, 2, 3, 4). ordered_line(5, 6, 7, 8). ordered_line(9, 10, 11, 12). ordered_line(13, 14, 15, 16).
ordered_line(1, 5, 9, 13). ordered_line(2, 6, 10, 14). ordered_line(3, 7, 11, 15). ordered_line(4, 8, 12, 16).
ordered_line(1, 6, 11, 16). ordered_line(4, 7, 10, 13).

%Horizontal detection --any two in a row
halfthere(1,2). halfthere(1,3). halfthere(1,4). halfthere(2,3). halfthere(2,4). halfthere(3,4).
halfthere(5,6). halfthere(5,7). halfthere(5,8). halfthere(6,7). halfthere(6,8). halfthere(7,8).
halfthere(9,10). halfthere(9,11). halfthere(9,12). halfthere(10,11). halfthere(10,12). halfthere(11,12).
halfthere(13,14). halfthere(13,15). halfthere(13,16). halfthere(14,15). halfthere(14,15). halfthere(15,16).

%vertical detection --any two in a row
halftherev1(1,5). halftherev1(1,9). halftherev1(1,13). halftherev1(5,9). halftherev1(5,13). halftherev1(9,13).
halftherev2(2,6). halftherev2(2,10). halftherev2(2,14). halftherev2(6,10). halftherev2(6,14). halftherev2(10,14).
halftherev3(3,7). halftherev3(3,11). halftherev3(3,15). halftherev3(7,11). halftherev3(7,15). halftherev3(11,15).
halftherev4(4,8). halftherev4(4,12). halftherev4(4,16). halftherev4(8,12). halftherev4(8,16). halftherev4(12,16).

halfthered1(1,6). halfthered1(1,11). halfthered1(1,16). halfthered1(6,11). halfthered1(6,16). halfthered1(11,16).
halfthered2(4,7). halfthered2(4,10). halfthered2(4,13). halfthered2(7,10). halfthered2(7,13). halfthered2(10,13).

%I am not sure what these lines are doing. They seem pointless
%line(A, B, C) :- ordered_line(A, B, C). line(A, B, C) :- ordered_line(A, C, B).
%line(A, B, C) :- ordered_line(B, A, C). line(A, B, C) :- ordered_line(B, C, A).
%line(A, B, C) :- ordered_line(C, A, B). line(A, B, C) :- ordered_line(C, B, A).

row-one(X) :- empty(1), !, assert(x(1)). row-one(X) :- empty(2), !, assert(x(2)). row-one(X) :- empty(3), !, assert(x(3)). row-one(X) :- empty(4), !, assert(x(4)).
row-two(X) :- empty(5), !, assert(x(5)). row-two(X) :- empty(6), !, assert(x(6)). row-two(X) :- empty(7), !, assert(x(7)). row-two(X) :- empty(8), !, assert(x(8)).
row-three(X) :- empty(9), !, assert(x(9)). row-three(X) :- empty(10), !, assert(x(10)). row-three(X) :- empty(11), !, assert(x(11)). row-three(X) :- empty(12), !, assert(x(12)).
row-four(X) :- empty(13), !, assert(x(13)). row-four(X) :- empty(14), !, assert(x(14)). row-four(X) :- empty(15), !, assert(x(15)). row-four(X) :- empty(16), !, assert(x(16)).
col-one(X) :- empty(1), !, assert(x(1)). col-one(x) :- empty(5), !, assert(x(5)). col-one(x) :- empty(9), !, assert(x(9)). col-one(x) :- empty(13), !, assert(x(13)). 
col-two(X) :- empty(2), !, assert(x(2)). col-two(x) :- empty(6), !, assert(x(6)). col-two(x) :- empty(10), !, assert(x(10)). col-two(x) :- empty(14), !, assert(x(14)). 
col-three(X) :- empty(3), !, assert(x(3)). col-three(x) :- empty(7), !, assert(x(7)). col-three(x) :- empty(11), !, assert(x(11)). col-three(x) :- empty(15), !, assert(x(15)). 
col-four(X) :- empty(4), !, assert(x(4)). col-four(x) :- empty(8), !, assert(x(8)). col-four(x) :- empty(12), !, assert(x(12)). col-four(x) :- empty(16), !, assert(x(16)). 
di-one(X) :- empty(1), !, assert(x(1)). di-one(X) :- empty(6), !, assert(x(6)). di-one(X) :- empty(11), !, assert(x(11)). di-one(X) :- empty(16), !, assert(x(16)).
di-two(X) :- empty(4), !, assert(x(4)). di-two(X) :- empty(7), !, assert(x(7)). di-two(X) :- empty(10), !, assert(x(10)). di-two(X) :- empty(13), !, assert(x(13)).
play_row_two :- row-two(X).
play_row_three :- row-three(X).
play_row_four :- row-four(X).
play_col_one :- col-one(X).
play_col_two :- col-two(X).
play_col_three :- col-three(X).
play_col_four :- col-four(X).
play_di_one :- di-one(X).
play_di_two :- di-two(X).
%AI checking for best move
stop_move :- halfthere(A,B), o(A), o(B), A < 5, B < 5, play_row_one, !.
stop_move :- halfthere(A,B), o(A), o(B), A > 5, A < 9, B > 5, B < 9, play_row_two, !.
stop_move :- halfthere(A,B), o(A), o(B), A > 9, A < 13, B > 9, B < 13, play_row_three, !.
stop_move :- halfthere(A,B), o(A), o(B), A > 13, B > 13, play_row_four, !.
stop_move :- halftherev1(A,B), o(A), o(B), play_col_one, !.
stop_move :- halftherev2(A,B), o(A), o(B), play_col_two, !.
stop_move :- halftherev3(A,B), o(A), o(B), play_col_three, !.
stop_move :- halftherev4(A,B), o(A), o(B), play_col_four, !.
stop_move :- halfthered1(A,B), o(A), o(B), play_di_one, !.
stop_move :- halfthered1(A,B), o(A), o(B), play_di_two, !.

stop_move :- makemove.

%checoing if a spot is taken
full(A) :- x(A). full(A) :- o(A). 

%checking if a spot is empty
empty(A) :- \+(full(A)).
same(A, A). different(A, B) :- \+(same(A, B)).
move(A) :- good(A), empty(A), !.
good(13). good(16). good(1). good(4). good(10). good(11). good(6). good(7). good(2). good(3). good(5). good(8). good(9). good(12). good(14). good(15).
all_full :- full(1), full(2), full(3), full(4), full(5),
full(6), full(7), full(8), full(9), full(10), full(11), full(12), full(14), full(15), full(16).
done :- ordered_line(A, B, C, D), x(A), x(B), x(C), x(D), write('I won.'), nl, ask_new_game.
done :- all_full, write('Draw.'), nl, ask_new_game.
getmove :- repeat, write('Please enter a move: '), read(X), empty(X), assert(o(X)).
makemove :- move(X), !, assert(x(X)).
makemove :- all_full.
printsquare(N) :- o(N), write(' o ').
printsquare(N) :- x(N), write(' x ').
printsquare(N) :- empty(N), write(' ').
printboard :- printsquare(1), printsquare(2), printsquare(3), printsquare(4), nl,
printsquare(5), printsquare(6), printsquare(7), printsquare(8), nl,
printsquare(9), printsquare(10), printsquare(11), printsquare(12), nl,
printsquare(13), printsquare(14), printsquare(15), printsquare(16), nl.
clear :- retractall(x(_)), retractall(o(_)).
% main
play :- clear, repeat, getmove, respond.
respond :- ordered_line(A, B, C, D), o(A), o(B), o(C), o(D),
printboard, write('You won.'), nl, ask_new_game. 
respond :- stop_move, printboard, done.

ask_new_game :- write('Do you want a new game? 1 = Yes, 2= NO'), read(X), new_game(X).
new_game(1) :- play.
new_game(2) :- write('Goodbye').