var
	msk,i,j,n:longint;
begin
	readln(msk);
	for i:=1 to msk do
		begin
		for j:=1 to i do
		begin
		write(n);
		n:=n+1; n:=n mod 10;
		end;
		writeln;
		end;
end.