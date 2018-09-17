var
	a:array[0..2,1..10000] of longint;
	msk,temp,i:longint;
procedure fpb(x:longint;y:longint);
	begin
	while y<>0 do
		begin
		temp:=y;
		y:=x mod y;
		x:=temp;
		end;
	writeln(x);
	end;
begin
	readln(msk);
	for i:=1 to msk do
		begin
		readln(a[1,i],a[2,i]);
		end;
	for i:=1 to msk do
		begin
		fpb(a[1,i],a[2,i]);
		end;
end.	