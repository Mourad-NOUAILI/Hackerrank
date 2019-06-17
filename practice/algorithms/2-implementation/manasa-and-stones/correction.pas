(*free pascal*)
uses math;

procedure saisie (msg : string ; var x : word);
begin
	repeat
		write (msg);
		read(x);
	until (x >= 1) and ( x <= 1000);
end;

procedure derniersNombres(n , a , b : word);
var
	aMin , bMax , i : word;
begin
	aMin := min(a,b);
	bMax := max(a,b);
	dec(n);
	for i:= 0 to n  do
		write( (n - i) * aMin + bMax * i : 5 );
	writeln;
end;

var
	n , a , b : word;
begin
	saisie('n = ' , n);
	saisie('a = ' , a);
	saisie('b = ' , b);
	derniersNombres(n,a,b);
end.

