var
	msk,n,x,lima:longint;
begin
	readln(msk);
	n:=0;
	lima:=5;
	while msk>=lima do
		begin
		x:=msk;
		while x>=lima do
			begin
			x:=(x-lima);
			n:=n+1;
			end;
		lima:=lima*5;
		end;
	writeln(n);
end.