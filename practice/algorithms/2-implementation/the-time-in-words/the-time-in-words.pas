const t : array[0..30] of string = (' o'' clock',
									'one',
									'two',
									'three',
									'four',
									'five',
									'six',
									'seven',
									'eight',
									'nine',
									'ten',
									'eleven',
									'twleve',
									'thirteen',
									'fourteen',
									'quarter',
									'sixteen',
									'seventeen',
									'eighteen',
									'nineteen',
									'twenty',
									'twenty one',
									'twenty two',
									'twenty three',
									'twenty four',
									'twenty five',
									'twenty six',
									'twenty seven',
									'twenty eight',
									'twenty nine',
									'half' );
var
	h,m : byte;

begin
	read(h);read(m);
	case m of
		0 :					writeln(t[h],t[m]);
		1 : 				writeln(t[m],' minute past ',t[h]);
		2..14 , 16..29 : 	writeln(t[m],' minutes past ',t[h]);
		15,30 : 			writeln(t[m],' past ',t[h]);
		31..59 :			if (60-m = 15) then writeln(t[60-m],' to ',t[h+1])
							else writeln(t[60-m],' minutes to ',t[h+1]);
	end;
end.
